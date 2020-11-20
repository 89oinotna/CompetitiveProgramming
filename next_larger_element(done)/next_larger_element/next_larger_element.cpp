// next_larger_element.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

long long int* initialize(long long int n) {
    long long int* arr=(long long int*)malloc(sizeof(unsigned long long int)*n);
    for (long long int i = 0; i < n; i++) {
        long long int c;
        cin >> c;
        arr[i] = c;
    }
    return arr;
}

struct item {
   long long int index;
    long long int value;
};

 long long int* getMaxs( long long int* arr, unsigned long long int n) {
     long long int* maxs = ( long long int*)malloc(sizeof(unsigned long long int) * n);
    
    deque<item> dq;

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && arr[i] > dq.front().value) {
            item it = dq.front();
            maxs[it.index] = arr[i];
            dq.pop_front();
        }
        if (dq.empty() || arr[i] < dq.front().value){
            item it = { i, arr[i] };
            dq.push_front(it);
        }
        else {
            item it = { i, arr[i] };
            dq.push_back(it);
        }
        
    }
    while (!dq.empty()) {
        item it = dq.front();
        maxs[it.index] = -1;
        dq.pop_front();
    }
    return maxs;
}

int main()
{
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        long long int n = 0;
        cin >> n;
        long long int* v = initialize(n);
        long long int* maxs = getMaxs(v, n);
        for (long long int i = 0; i < n; i++) {
            cout << maxs[i] << " ";
        }
        free(v);
        free(maxs);
        cout << endl;
    }
}