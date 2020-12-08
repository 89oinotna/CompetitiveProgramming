// monkey and bamboo.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
using namespace std;

//k Strength factor (max jump height) 
//if I jump exactly k feet in a jump, k is decremented by 1.

int tryFactor(vector<int>&ladder, int k) {
    int last = 0;
    for (int i=0; i < (int)ladder.size(); i++) {
        if (ladder[i] - last > k) {
            return -1;
        }
        else if (ladder[i] - last == k) {
            k--;
        }
        last = ladder[i];
    }
    return 1;
}

int main()
{
    int T = 0; //#test cases
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n = 0; //#rungs
        cin>> n;
        vector<int> ladder(n); //rungs distance from ground
        for (int j = 0; j < n; j++) {
            cin >> ladder[j];
        }
        auto ladderit = ladder.begin();
        for (int x : ladder) {}
        int res = 0;
        int L = 1, R = 10000000;
        int k = 0;
        while (k != ((L + R) + 1) / 2) {
            k = ((L + R) + 1) / 2;
            res = tryFactor(ladder, k);
            if (res > 0) { //posso diminuire
                R = k;
            }
            else if (res < 0) { //devo aumentare
                L = k;
            }

        }

        cout << k<<endl;
    }
    
}


