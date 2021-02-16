// n_meetings.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int maxMeetings(vector<int> start, vector<int> end, int n) {
    vector<tuple<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = {start[i], end[i] };
    }
    sort(v.begin(), v.end(), [](tuple<int, int> const& a, tuple<int, int> const&b) {
        return get<1>(a) < get<1>(b);
        });
    int counter = 0;
    int last_end = 0;
    for (int i = 0; i < n; i++) {
        if (last_end < get<0>(v[i])) {
            last_end = get<1>(v[i]);
            counter++;
        }
    }
    return counter;
}

int main()
{
    int n;
    cin >> n;
    vector<int> start(n);
    vector<int> end(n);
    for (int i = 0; i < n; i++) {
        cin >> start[i] >> end[i];
    }
    maxMeetings(start, end, n);
}

