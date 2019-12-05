#pragma once
#include"Obavestenje.h"
#include<iostream>
#include<iomanip>

class Node {
public:
	Obavestenje* curr;
	Node* next;
};

class Lista {
public:
	Node* glava;
	Lista() {
		glava = NULL;
	}
	Lista(const Lista&) = delete;
	Lista(Lista&& l) {
		glava = l.glava;
		l.glava = nullptr;
	}
	void operator+=(Obavestenje* n);
	void operator()();
	int operator+();
	void operator!();
	void operator~();
	Obavestenje* operator[](int i);
	friend ostream& operator<<(ostream& os, Lista* list);
private:
	
};