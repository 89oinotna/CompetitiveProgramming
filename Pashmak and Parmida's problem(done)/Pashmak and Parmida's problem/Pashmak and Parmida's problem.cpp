// Pashmak and Parmida's problem.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

void add(vector<int>& v, int index, int x) {
	while (index < v.size()) {
		v[index] += x;
		index += index & -index;
	}
}

int sum(vector<int>& v, int i) {
	int s = 0;
	while (i > 0) {
		s += v[i];
		i -= i & -i;
	}
	return s;
}

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



/*There is a sequence a that consists of n integers a1, a2, ..., an. 
Let's denote f(l, r, x) the number of indices k such that: l ≤ k ≤ r and ak = x. 
His task is to calculate the number 
of pairs of indicies i, j (1 ≤ i < j ≤ n) such that f(1, i, ai) > f(j, n, aj).*/

/*
	use fw

	loop from right:
	-mantain a counter to count each value occurrence
	-store the count of vi for each i f(i,n,v[i])
	- add to fw 1 to keep track of how many counters we have for each value

	loop from left:
	- using the count of a vi remove its contribution in fw
	- use an array to count occurrencies of each value  f(0,i,v[i])
	- meanwhile use fw sum to check how many f(1, i, ai) > f(j, n, aj) fixed i
*/
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	remap<int>(v);
	vector<int> count_j(n, 0);
	vector<int> counter(n, 0);
	vector<int> ft(n, 0);
	for (int i = n - 1; i >= 0; --i) {
		counter[v[i]]++; //conto le occorrenze di v[i]
		count_j[i] = counter[v[i]];		//mantengo qual era il counter sull'indice i (cosi poi posso eliminare il suo contributo)	
								//k=counter[v[i]] occorrenze di v[i] in [i,n]
										//cioè il valore della f(i,n,v[i])
		add(ft, counter[v[i]], 1); //conto f(i,n,v[i]) ho per un indice j=counter[v[i]]
		//quanti hanno j occorrenze (mi serve dopo per >)
	}
	uint64_t res = 0;
	fill(counter.begin(), counter.end(), 0);
	for (int i = 0; i < n; i++) {
		add(ft, count_j[i], -1); //tolgo una occorrenza f(i,n,v[i]) (elimino il suo contributo)
		counter[v[i]]++; //conto le occorrenze f(0,i,v[i])
		res += sum(ft, counter[v[i]] - 1); //vedo quante occorrenze ho f(j,n,v[j]) minori di counter[v[i]] cioè f(0,i,v[i]) fissato i
	}

	cout << res;
}
