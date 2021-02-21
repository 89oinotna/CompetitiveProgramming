// towers.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <unordered_map>
using namespace std;
/*
use an unordered map to store the pieces by their length
the key is the len and the value is the number of pieces
while populating the map also keep track of the maximum 
*/
int main()
{
    int n = 0;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> m;
    int max = INT_MIN;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (m.find(arr[i]) == m.end())
            m[arr[i]] = 1;
        else
            m[arr[i]]++;
        if (m[arr[i]] > max) max = m[arr[i]];
    }
   
    cout << max << " " << m.size() << endl;
}

