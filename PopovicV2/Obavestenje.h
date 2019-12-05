#pragma once

#include "Korisnik.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

class Korisnik;

class Obavestenje{
public:
	static void initID() {
		lastID = 0;
	}
	Obavestenje(Korisnik* c);
	int& getID();
	Obavestenje() = default;
	Korisnik* getOwner();
	bool chkRead();
	void read(){
		isRead = true;
	}
	friend ostream& operator<<(std::ostream& os,Obavestenje& o);
	virtual void pisi(ostream& os);
protected:
	int ID = lastID++;
	static int lastID;
	time_t vreme;
	bool isRead = false;
	Korisnik* owner;
};

class Objava :public Obavestenje {
public:
	Objava(Korisnik * c);
	void pisi(ostream& o);
private:
	string tekst_objave;
};
