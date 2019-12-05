#include "Obavestenje.h"

Obavestenje::Obavestenje(Korisnik* c)
{
	vreme = time(NULL);
	owner = c;
}

int& Obavestenje::getID()
{
	return ID;
}

Korisnik* Obavestenje::getOwner()
{
	return owner;
}

bool Obavestenje::chkRead()
{
	return isRead;
}

void Obavestenje::pisi(ostream& os)
{
	struct tm* t = localtime(&vreme);
	os << ID << "|" << owner->getIme() << "_" << t->tm_hour << ":" << t->tm_min << ":" << t->tm_sec << endl;
}

ostream& operator<<(std::ostream& os, Obavestenje& o)
{
	o.pisi(os);
	return os;
}

Objava::Objava(Korisnik * c):Obavestenje(c)
{
	cin >> tekst_objave;
}

void Objava::pisi(ostream& o)
{
	struct tm* t = localtime(&vreme);
	o << ID << "|" << owner->getIme() << "_" << t->tm_hour << ":" << t->tm_min << ":" << t->tm_sec << endl << tekst_objave << endl;
}
