// magic_numbers.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int reduce(int i, const char* line, int val) {
    i++;
    if (val == 1) {
        if (line[i] - '0' == 4) { 
            int v=reduce(i, line, 4); 
            if (v == -1) return i;
            return v;
        }
        else return -1;
    }
    else {
        if (line[i] - '0' == 4) return i;
        else return -1;
    }
}
int main()
{
    string line;
    cin >> line;
    const char* l = line.c_str();
    
    int i = 0;
    while (i < line.length() ) {
        if (l[i] - '0' !=1) {
            cout << "NO";
            return 0;
        }
        else {
            int v = reduce(i, l, 1);
            if (v != -1) i = v;
           
        }
        i++;
    }
    cout << "YES";
    return 0;
}

