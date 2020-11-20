// Missing number.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n=0;
        cin >> n;
        int sum=0;
        int c = 0;
        for (int j = 0; j < n-1; j++) {
            cin >> c;
            sum += c;
        }
        int missing = (n * (n + 1)) / 2 - sum;
        cout << missing << endl;
    }
}
