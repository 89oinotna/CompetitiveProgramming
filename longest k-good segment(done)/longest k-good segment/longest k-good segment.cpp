// longest k-good segment.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;


int main()
{
    unsigned int n = 0, k = 0;
    cin >> n>>k;
    vector<int> vect(n);
    map<int, int> distinct;
    for (int i = 0; i < n; i++) {
        scanf("%d", &vect[i]);
    }
    unsigned int l = 0, r = 0, max_segment_len = 0, maxl=0, maxr=0;
    while (r<vect.size()) {
        auto find = distinct.find(vect[r]);
  
        if (find!=distinct.end()) { //se presente aumento il contatore
            find->second++;
        }
        else { //altrimenti se non presente
            if (distinct.size()<k) { //se ho meno di k numeri diversi allora posso aggiungerlo
                distinct.insert(pair<int, int>(vect[r], 1));
            }
            else { //altrimenti devo spostare l finché distinct size<k
                while (distinct.size() == k) {
                    auto f = distinct.find(vect[l]);
                    if (f->second > 1) f->second--;
                    else distinct.erase(f);
                    l++;
                }
                distinct.insert(pair<int, int>(vect[r], 1));
            }
        }

        if (r - l > max_segment_len) {
            max_segment_len = r - l;
            maxr = r;
            maxl = l;
        }
        r++;

    }
    cout << maxl+1 << " " << maxr+1;

}

// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug

// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln
