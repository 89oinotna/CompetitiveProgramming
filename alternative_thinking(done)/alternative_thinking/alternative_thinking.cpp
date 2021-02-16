// alternative_thinking.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;
/*
    a flix can only increase the score by 2
    beginning - end of the sequence
    so we can have a max score og n -> string len
    or we can have m + 2 where m is the longest alternating subsequence
    min(n, m+2)
*/
int main()
{
    int n;
    cin >> n;
    string str;
    char* s;
    cin>>str;
    s = &str[0];
    int pre = s[0] - '0';
    int res = 1;
    for (int i = 1; i < n; i++) {
        if (pre != (s[i] - '0')) { //alternating
            res++;
            pre = s[i] - '0';
        }
    }
    cout << min(n, res+2);
}

