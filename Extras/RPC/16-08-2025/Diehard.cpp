#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define sz(x) ((int) x.size())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
#define MILF
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int tests;

int main()
{
    // #ifdef MILF
    //     freopen("../input.txt", "r", stdin);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int d1[6]; forn(i,6) cin >> d1[i];
    int d2[6]; forn(i,6) cin >> d2[i];
    int d3[6]; forn(i,6) cin >> d3[i];
    sort(d1,d1 + 6);sort(d2,d2 + 6);sort(d3,d3 + 6);

    int res = -1;
    double val1 = 0.0, val2 = 0.0, emp1 = 0.0, emp2 = 0.0;
    double j = 0.0;
    forn(i,6)
    {
        while (j<6 && d1[(int)j] <= d2[i])
        {
            int k = i;
                while(k<6 && d1[(int)j] == d2[k])
                {
                    emp1++;
                    k++;
                }
            j++;
        }
        val1 += (6-j);
    }
    j = 0.0;
    forn(i,6)
    {
        while (j<6 && d1[(int)j] <= d3[i])
        {
            int k = i;
            while(k<6 && d1[(int)j] == d3[k])
            {
                emp2++;
                k++;
            }
            j++;
        }
        val2 += (6-j);
    }
    val1/=36;val2/=36;emp1/=36;emp2/=36;
    val1 >= (1.0-emp1-val1) && val2 >= (1.0-emp2-val2) && emp1 != 1.0 && emp2 != 1.0 ? res = 1 : res = res;

    if(res == -1) {
        val1 = 0.0; val2 = 0.0; emp1 = 0.0; emp2 = 0.0; j = 0.0;
        forn(i,6)
        {
            while (j<6 && d2[(int)j] <= d1[i])
            {
                int k = i;
                while(k<6 && d2[(int)j] == d1[k])
                {
                    emp1++;
                    k++;
                }
                j++;
            }
            val1 += (6-j);
        }
        j = 0.0;
        forn(i,6)
        {
            while (j<6 && d2[(int)j] <= d3[i])
            {
                int k = i;
                while(k<6 && d2[(int)j] == d3[k])
                {
                    emp2++;
                    k++;
                }
                j++;
            }
            val2 += (6-j);
        }
        val1/=36;val2/=36;emp1/=36;emp2/=36;
        val1 >= (1.0-emp1-val1) && val2 >= (1.0-emp2-val2) && emp1 != 1.0 && emp2 != 1.0 ? res = 2 : res = res;
    }

    if(res == -1){
        val1 = 0.0; val2 = 0.0; emp1 = 0.0; emp2 = 0.0; j = 0.0;
        forn(i,6)
        {
            while (j<6 && d3[(int)j] <= d1[i])
            {
                int k = i;
                while(k<6 && d3[(int)j] == d1[k])
                {
                    emp1++;
                    k++;
                }
                j++;
            }
            val1 += (6-j);
        }
        j = 0.0;
        forn(i,6)
        {
            while (j<6 && d3[(int)j] <= d2[i])
            {
                int k = i;
                while(k<6 && d3[(int)j] == d2[k])
                {
                    emp2++;
                    k++;
                }
                j++;
            }
            val2 += (6-j);
        }
        val1/=36;val2/=36;emp1/=36;emp2/=36;
        val1 >= (1.0-emp1-val1) && val2 >= (1.0-emp2-val2) && emp1 != 1.0 && emp2 != 1.0 ? res = 3 : res = res;
    }

    if (res == -1)
    {
        cout << "No dice";
    }
    else
    {
        cout << res;
    }
    cout << nl;
    
    return 0;
}