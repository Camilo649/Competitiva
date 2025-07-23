// ========================================================================
// =========== CONTESTANT: READ THIS BEFORE USING THIS TEMPLATE ===========
// ========================================================================
//
// If you choose to use this template, keep in mind that:
//
// - you may add your own member variables
// - you may add your own member functions
// - you can use the provided member variables (and will probably need to)
// - you can modify the provided member functions (and will probably need to)
// - remember to read the documentation comments on each member variable/function
// - change #include "../strategy.h" to #include "strategy.h" below
//

#include "../strategy.h"

#include <functional>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace flow;
using namespace std::literals::chrono_literals;
using namespace std::placeholders;


namespace
{
    std::string formatTimestampNs(TimestampNs timestamp)
    {
        using namespace std::chrono;

        // Convert nanoseconds to seconds
        auto seconds = duration_cast<std::chrono::seconds>(timestamp);
        auto nanoseconds = timestamp.count() % 1000000000;
        auto milliseconds = nanoseconds / 1000000;

        // Convert seconds to time_t for std::gmtime
        std::time_t time = seconds.count();

        // Format the timestamp
        std::tm tm = *std::gmtime(&time);
        std::ostringstream oss;
        oss << std::put_time(&tm, "[%Y-%m-%d %H:%M:%S") << '.' << std::setfill('0') << std::setw(3) << milliseconds << ']';

        return oss.str();
    }
}

class Skeleton : public Strategy, public OrderStateObserver
{
public:
    Skeleton(EventDispatcher &eventDispatcher, Gateway &gateway, Risk &risk)
        : m_eventDispatcher{eventDispatcher}, m_gateway{gateway}, m_risk{risk}
    {
        onMinute();
    }

    /// OrderStateObserver interface
    /**
     * \brief Notification handler for order acknowledgments.
     * \param symbol The trading symbol
     * \param orderId The order ID
     * \param side The side of the order (Buy/Sell)
     * \param price The price at which the order was placed
     * \param qty The quantity of the order
     * \param tif The time-in-force of the order
     */
    void onAck(const Symbol &symbol, OrderId orderId, Side side, Price price, Quantity qty, TIF) override
    {
        /// TODO - add logic
    }

    /**
     * \brief Notification handler for order fills.
     * \param symbol The trading symbol
     * \param orderId The order ID
     * \param dealt The quantity dealt in the fill
     * \param contra The quantity dealt by the contra party
     */
    void onFill(const Symbol &, OrderId, Quantity dealt, Quantity contra) override
    {
        /// TODO - add logic
    }

    /**
     * \brief Notification handler for order terminations.
     * \param symbol The trading symbol
     * \param orderId The order ID
     * \param status The done status of the order
     */
    void onTerminated(const Symbol &, OrderId, DoneStatus status) override
    {
        --m_openOrders;

        /// TODO - add logic
    }

private:
    /**
     * \brief Handles updates to the top of the book.
     * \param symbol The trading symbol
     * \param book The top of the book data
     */
    void onTopOfBook(std::string_view, const md::TopOfBook &book)
    {
        /// TODO - add logic
    }

private:
    /**
     * \brief Runs every one minute
     */
    void onMinute()
    {
        m_eventDispatcher.postEvent(60s, [this]()
                                    { onMinute(); });

        // TODO - add logic
    }

// ========================================================================
// ==== CONTESTANT: YOU DO NOT NEED TO MODIFY ANY CODE BELOW THIS LINE ====
// ==== CONTESTANT: YOU **ARE** ALLOWED TO MODIFY CODE BELOW THIS LINE ====
// ========================================================================

    void sendOrder(const Symbol &symbol, Side side, Price price, Quantity qty)
    {
        m_gateway.getOrderSender(symbol, *this).sendOrder(side, price, qty, TIF::IOC);
        ++m_openOrders;
    }


public: // md::TopOfBook Subscriber interface

    /**
     * \brief Notification handler for top of book updates.
     *
     * This callback is called when there is a new symbol available to be published. The client can keep a reference to the record or subscribe to receive callbacks every time the record changes.
     *
     * \param consumer The consumer of the top of book updates
     * \param symbol The trading symbol
     * \param book The top of the book data
     */
    void notify(pub::Consumer<md::TopOfBook> &consumer, std::string_view symbol, const md::TopOfBook &book) override
    {
        if (m_bookSnapshots.insert_or_assign(std::string(symbol), &book).second)
        {
            consumer.subscribe(symbol, std::bind(&Skeleton::onTopOfBook, this, _1, _2));
        }
    }

    /**
     * \brief End of batch handler for top of book updates.
     *
     * This method is called after a batch of concurrent updates. For example, after a trade, the positions of the deal and contra currencies change, and after those two changes are propagated, the endOfBatch method is called.
     *
     * \param consumer The consumer of the top of book updates
     */
    void endOfBatch(pub::Consumer<md::TopOfBook> &) override {}

public: // Position Subscriber interface

    /**
     * \brief Notification handler for position updates.
     *
     * This callback is called when there is a new symbol available to be published. The client can keep a reference to the record or subscribe to receive callbacks every time the record changes.
     *
     * \param positionsConsumer The consumer of the position updates
     * \param asset The trading asset
     * \param position The position data
     */
    void notify(pub::Consumer<Position> &positionsConsumer, std::string_view asset, const Position &position) override
    {
        auto onPosition = [this](std::string_view asset, const Position &position)
        {
            m_positions[Asset(asset)] = position;
        };

        onPosition(asset, position);
        positionsConsumer.subscribe(asset, onPosition);
    }

    /**
     * \brief End of batch handler for position updates.
     *
     * This method is called after a batch of concurrent updates. For example, after a trade, the positions of the deal and contra currencies change, and after those two changes are propagated, the endOfBatch method is called.
     *
     * \param consumer The consumer of the position updates
     */
    void endOfBatch(pub::Consumer<Position> &) override
    {
    }

private:
    EventDispatcher &m_eventDispatcher;                                ///< Reference to the event dispatcher
    Gateway &m_gateway;                                                ///< Reference to the gateway for sending orders
    Risk &m_risk;                                                      ///< Reference to the risk management object
    std::unordered_map<Asset, Position> m_positions;                   ///< Map of asset positions
    std::unordered_map<Symbol, const md::TopOfBook *> m_bookSnapshots; ///< Map of top of book snapshots
    int m_openOrders = 0;                                              ///< Counter for open orders
};

/**
 * \brief Factory function to create a new Skeleton strategy.
 * \param eventDispatcher The event dispatcher for scheduling tasks and getting the current time
 * \param gateway The gateway for sending orders
 * \param risk The risk management object
 * \return A unique pointer to the created strategy
 */
std::unique_ptr<Strategy> createStrategy(EventDispatcher &eventDispatcher, Gateway &gateway, Risk &risk)
{
    return std::make_unique<Skeleton>(eventDispatcher, gateway, risk);
}
