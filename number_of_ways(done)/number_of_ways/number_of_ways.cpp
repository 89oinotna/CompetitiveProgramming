// number_of_ways.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    int result = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    if (sum % 3 != 0) {
        cout << result;
        return 0;
    }
    int i = v.size() - 1;
    vector<int> b(n, 0);
    vector<int> c(n, 0);
    int right_sum = 0;
    while (right_sum <= (sum / 3) && i>=0) {
        right_sum += v[i];
        if (right_sum == sum / 3) {
            b[i] = 1;
        }
        i--;
    }
    
    int last_sum = 0;
    for (int j = b.size() - 1; j >= 0; j--) {
        if (b[j] == 1) {
            c[j] = last_sum++;
        }
        else {
            c[j] = last_sum;
        }
    }
    i = 0;
    int left_sum = 0;
    while (left_sum <= (sum / 3) && i<v.size()) {
        left_sum += v[i];
        if (left_sum == sum / 3) {
            result += c[i + 1];
        }
        i++;
    }
    cout << result;
}

