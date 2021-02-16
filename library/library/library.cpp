// library.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;

template<typename T>
void remap(vector<T>& a) {
	vector<T> tmp(a.size());
	copy(a.begin(), a.end(), tmp.begin());
	sort(tmp.begin(), tmp.end());
	size_t sz = distance(tmp.begin(), unique(tmp.begin(), tmp.end()));
	tmp.resize(sz);

	for (auto& x : a)
		x = distance(tmp.begin(), lower_bound(tmp.begin(), tmp.end(), x));
}

int main()
{
    std::cout << "Hello World!\n";
}

