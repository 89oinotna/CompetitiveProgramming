// inversion count.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int merge(vector<int> &v, int l, int r, int mid) {
	int inv = 0;
	int ll = l, rr = mid+1, k=0;
	vector<int> tmp(r - l + 1);
	while (ll <= mid && rr <= r) {
		if (v[ll] > v[rr]) {
			inv += mid - ll + 1;
			tmp[k] = v[rr];
			rr++;
		}
		else {
			tmp[k] = v[ll];
			ll++;
		}
		k++;
	}
	while (ll <= mid) {
		tmp[k] = v[ll];
		ll++;
		k++;
	}
	while (rr <= r) {
		tmp[k] = v[rr];
		rr++;
		k++;
	}
	for (int i = l; i <= r; i++) {
		v[i] = tmp[i-l];
	}
	return inv;
}

int mergeSort(vector<int> &v, int l, int r) {
	int inv = 0;
	if (r > l) {
		int mid = ((r + l) / 2);
		inv += mergeSort(v, l, mid);
		inv += mergeSort(v, mid + 1, r);
		inv += merge(v, l, r, mid);
	}
	return inv;
}

int countInversions(vector<int> &v, int l, int r) {
	return mergeSort(v, l, r);
}

int main()
{
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		int result=countInversions(v, 0, n-1);
		cout << result << endl;
	}
}

