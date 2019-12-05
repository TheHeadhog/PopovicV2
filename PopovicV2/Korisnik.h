#pragma once

#include<iomanip>
#include<iostream>

using namespace std;

class Obavestenje;
class Lista;

class Korisnik {
public:
	
	Korisnik(string ime);
	Korisnik(const Korisnik&) = delete;
	Korisnik(Korisnik&& k);
	string getIme();
	void send(Obavestenje* o,Korisnik* reciever) {
		reciever->recieve(o);
	}
	void recieve(Obavestenje* O);
private:
	string korisnicko_ime="A";
	Lista* mojaOb;
};