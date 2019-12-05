#include "Korisnik.h"
#include "List.h"

Korisnik::Korisnik(string ime) {
	korisnicko_ime = ime;
	mojaOb = new Lista();
}

Korisnik::Korisnik(Korisnik&& k)
{
	korisnicko_ime = k.getIme();
	mojaOb = k.mojaOb;
	k.mojaOb = NULL;
}

string Korisnik::getIme()
{
	return korisnicko_ime;
}

void Korisnik::recieve(Obavestenje* O)
{

	*mojaOb += O;
}

