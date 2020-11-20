// kadanes algorithm.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    for (int i=0; i < T; i++) {
        int n = 0;
        cin >> n;
        int totalMax=0;
        int subSum = 0;
        int c = 0;
        int max=INT_MIN;
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c > max)max = c;
            if (subSum + c <= 0) subSum = 0;
            else
                subSum += c;
            if (subSum > totalMax) totalMax = subSum;
        }
        if(totalMax>0)
            cout << totalMax << endl;
        else
            cout << max << endl;
    }
}

