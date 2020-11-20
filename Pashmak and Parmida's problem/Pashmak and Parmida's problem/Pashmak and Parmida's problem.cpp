// Pashmak and Parmida's problem.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

/*There is a sequence a that consists of n integers a1, a2, ..., an. 
Let's denote f(l, r, x) the number of indices k such that: l ≤ k ≤ r and ak = x. 
His task is to calculate the number 
of pairs of indicies i, j (1 ≤ i < j ≤ n) such that f(1, i, ai) > f(j, n, aj).*/
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int*> tmp(v.size());
	for (int i = 0; i < n; i++) {
		tmp[i] = &(v[i]);
	}
	sort(tmp.begin(), tmp.end(), [](const int* a, const int* b) {
		return *a < *b;
		});
	int j = 0; //last index in remap
	int x = *(tmp[0]); //last number seen
	for (int i = 0; i < n; i++) {
		if(x == *(tmp[i]))
			v[i] = j;
		else {
			v[i] = ++j;
			x= *(tmp[i]);
		}
	}

	vector<int> num_counter(n, 0);
	vector<int> j_found(n, 0);
	for (int i = n - 1; i >= 0; i--) {
		num_counter[v[i]]++;
		j_found[i] = num_counter[i];
	}

	vector<int> i_found(n, 0);
	for (int i = 0; i <n; i++) {
		num_counter[v[i]]++;
		i_found[i] = num_counter[i];
	}

	cout << "ciao";
}
