#!/bin/bash
g++ -O2 -o gen gen.cpp
g++ -O2 -o brute brute.cpp
g++ -O2 -o sol P.cpp

for i in $(seq 1 1000)   # <-- subir de 1000 a 20000 o más
do
    ./gen $i > input.txt
    ./sol < input.txt > out1.txt
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
echo "Terminado sin diferencias (o encontro una arriba)"