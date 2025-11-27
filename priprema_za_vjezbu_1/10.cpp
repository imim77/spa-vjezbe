#include <iostream>
#include <ctime>
//#include "listd.h"
//#include "kursor.h"
#include "listapok.h"
using namespace std;

int main() {
	srand(time(0));
	list<int> L;
	int n;
	list<int>::element iter, iterpom;
	
	cout << "broj elemenata: "; cin >> n;
	for(int i=0; i<n; i++){
		if (i) L.Insert(L.End(), rand() % 20);
		else L.Insert(L.First(), rand() % 20);
	}
	
	cout << "Lista: ";
	for(iter=L.First(); iter!=L.End(); iter=L.Next(iter)){
		cout << L.Retrieve(iter) << " ";
	}
	
	int brojac, max = 1;
	for(iter=L.First(); iter!=L.End(); iter=L.Next(iter)){
		brojac = 1;
		for(iterpom=L.Next(iter); iterpom!=L.End(); iterpom=L.Next(iterpom)){
			if (L.Retrieve(iter) == L.Retrieve(iterpom)) brojac++;
		}
		if (brojac > max) max = brojac;
	}
	
	cout << "\nMax ponavljanja: " << max;
	cout << "\nIspis: ";
	for(iter=L.First(); iter!=L.End(); iter=L.Next(iter)){
		brojac = 1;
		for(iterpom=L.Next(iter); iterpom!=L.End(); iterpom=L.Next(iterpom)){
			if (L.Retrieve(iter) == L.Retrieve(iterpom)) brojac++;
		}
		if (brojac == max) cout << L.Retrieve(iter) << " ";
	}
	
	cout << "\n";
	return 0;
}

