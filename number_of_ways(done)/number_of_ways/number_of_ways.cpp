// number_of_ways.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

/*
 Count the number of ways to split all the elements of the array 
 into three contiguous parts so that the sum of elements in each part is the same

 mantain a variable sum as the total sum
 now we know that aech part mush have sum=(sum/3)

 the middle part is constrained by left and right part


 create array b to mark if in a position we can split having sum/3 starting from right
 suffix
 store in array c the suffix sum using b

 prefix
 now add in c the prefix sum starting from left

 the result is the sum of all c elements
*/


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

