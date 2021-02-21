// subset_sum_problem.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
/*
    compute total sum and divide by 2 to get the half
    now use knapsack to resolve:
    - row objects
    - column [0..half]


*/
int equalPartition(int N, int arr[])
{
    int half = 0;
    for (int i = 0; i < N; i++) {
        half += arr[i];
    }
    if (half % 2 != 0) return 0;
    half /= 2;
    vector<vector<int>> m(N + 1);
    for (int i = 0; i < N + 1; i++) {
        m[i].resize(half+1);
        for (int j = 0; j < half + 1; j++) {
            if (i == 0 || j == 0) m[i][j] = 0;
            else if (arr[i - 1] > j) m[i][j] = m[i - 1][j];
            else {
                m[i][j] = max(arr[i - 1] + m[i - 1][j - arr[i - 1]], m[i - 1][j]);
            } 
        }
    }
    return m[N][half] == half ? 1 : 0;

}
int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout << equalPartition(n, arr);
}

