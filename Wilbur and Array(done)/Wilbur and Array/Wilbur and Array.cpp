// Wilbur and Array.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long > base(n, 0);
    vector<long long > goal(n);
    for (int i = 0; i < n; i++) {
        cin>>goal[i];
    }
    long long int to_sum = 0;
    long long int counter = 0;
    for (int i = 0; i < n; i++) {
        base[i] += to_sum;
        if (base[i] != goal[i]) {
            long long int diff = goal[i] - base[i];
            to_sum +=  diff;
            counter+=abs(diff);
        }
        
    }
    cout << counter;
}

