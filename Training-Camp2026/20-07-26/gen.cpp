#include <bits/stdc++.h>
using namespace std;

int genStamina(int maxStamina)
{
    int bias = rand() % 3;
    if (bias == 0) 
        return rand() % maxStamina + 1;               // uniforme en [1, maxStamina]
    else 
        return rand() % (maxStamina/2 + 1) + 1;        // sesgado a valores bajos [1, maxStamina/2+1]
}

int main(int argc, char** argv)
{
    srand(atoi(argv[1])); // semilla distinta cada corrida

    int n = rand() % 3 + 1;
    int m = rand() % 3 + 1;
    int total = n*m;
    int k = rand() % (total+1);
    int l = total - k;
    int maxStamina = n+m;

    cout << n << " " << m << "\n";
    cout << k;
    for (int i = 0; i < k; i++) cout << " " << genStamina(maxStamina);
    cout << "\n";
    cout << l;
    for (int i = 0; i < l; i++) cout << " " << genStamina(maxStamina);
    cout << "\n";

    return 0;
}