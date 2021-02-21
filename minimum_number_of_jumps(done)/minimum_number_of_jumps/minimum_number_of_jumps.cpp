// minimum_number_of_jumps.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
using namespace std;
/*
    Think as a graph and take the next max O(n)

    We jump to the next position in jump range that lets us jump farther:
    - done by simply sweeping on the range segment recording the max farther we can go
        which is the max position + the jump value in the subarray
    
*/
int minJumps(int arr[], int n) {
    
    int i = 0;
    int jumps = 0;
    while(i<n-1) {
        int max = 0;
        int max_j = 0;
        if (arr[i] == 0) return -1; 
        for (int j = 1; j <= arr[i]; j++) {
            if (i + j >= n-1) {
                max = INT_MAX, max_j = i + j;
                break;
            }
            else if (i+j + arr[i+j] > max) max = i+j + arr[i+j], max_j=i+j;
        }
        jumps++;
        i = max_j;
    }
    return jumps;
}

int main()
{
    int n;
    cin >> n;
    int* arr=new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<minJumps(arr, n);
}

