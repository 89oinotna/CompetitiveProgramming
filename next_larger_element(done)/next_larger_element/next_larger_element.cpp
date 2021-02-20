// next_larger_element.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
/*
use a deque to track the seen elements in an ordered way
1) while current greater than the ones in deque remove and assign curr as next greater 
2) insert it in the front
- if greater i have removed all -> deque ordered on inser cause is the only one
- if there is some greater inserting it in the front ensures ordering 

at the end all element in the deque are the ones without the next grater elem
*/
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
     long long int* maxs = ( long long int*)malloc(sizeof(long long int) * n);
    
    deque<item> dq;

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && arr[i] > dq.front().value) {
            item it = dq.front();
            maxs[it.index] = arr[i];
            dq.pop_front();
        }
        
        item it = { i, arr[i] };
        dq.push_back(it);
        
        
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