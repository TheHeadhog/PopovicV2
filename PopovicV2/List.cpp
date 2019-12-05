#include "List.h"

void Lista::operator()()
{
	Node* tek = glava;
	while (tek != NULL) {
		if (tek->curr->chkRead() == false) cout << *(tek->curr) << endl;
		tek = tek->next;
	}
}

int Lista::operator+()
{
	int cnt = 0;
	Node* tek = glava;
	while (tek != NULL) {
		if (tek->curr->chkRead() == false) cnt++;
		tek = tek->next;
	}
	return cnt;
}

void Lista::operator!()
{
	Node* tek = glava;
	while (tek != NULL) {
		if (tek->curr->chkRead() == false) tek->curr->read();
		tek = tek->next;
	}
}

void Lista::operator~()
{
	while (glava != NULL && glava->curr->chkRead() == true)
	{
		glava = glava->next;
	}
	Node* tek = glava;
	while (tek != NULL && tek->next != NULL) {
		if (tek->next->curr->chkRead() == true)
		{
			Node* Pom = tek->next;
			tek->next = tek->next->next;
			delete(Pom);
		}
		tek = tek->next;
	}
}

Obavestenje* Lista::operator[](int i)
{
	Node* tek = glava;
	for (int a = 0; a < i; a++) tek = tek->next;
	return tek->curr;
}

void Lista::operator+=(Obavestenje* n)
{
	Node* temp = new Node();
	temp->curr = n;
	if (glava != NULL)
	{
		temp->next = glava;
		glava = temp;
	}
	else glava = temp;
}

ostream& operator<<(ostream& os, Lista* list)
{
	Node* tek = list->glava;
	while (tek != NULL) {
		tek->curr->pisi(os);
		tek = tek->next;
	}
	return os;
}
