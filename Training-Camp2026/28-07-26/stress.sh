#!/bin/bash
g++ -O2 -o gen gen.cpp
g++ -O2 -o brute brute.cpp
g++ -O2 -o sol L.cpp

for i in $(seq 1 5000)
do
    ./gen $i > input.txt
    echo "1" > full_input.txt
    cat input.txt >> full_input.txt
    ./sol < full_input.txt > out1.txt
    ./brute < input.txt > out2.txt
    if ! diff -q out1.txt out2.txt > /dev/null
    then
        echo "DIFERENCIA en seed $i"
        cat input.txt
        echo "tu solucion:"; cat out1.txt
        echo "fuerza bruta:"; cat out2.txt
        break
    fi
done