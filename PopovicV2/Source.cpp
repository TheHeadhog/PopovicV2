#include "Obavestenje.h"
#include "Korisnik.h"
#include "List.h"
int Obavestenje::lastID = 0;
int main() {
	Lista list;
	Korisnik* pera = new Korisnik("Pera");
	Korisnik* zika = new Korisnik("Zika");
	Obavestenje* ob = new Obavestenje(pera);
	system("PAUSE");
	pera->send(ob, zika);
	cout << zika->mojaOb;
	system("PAUSE");
}	