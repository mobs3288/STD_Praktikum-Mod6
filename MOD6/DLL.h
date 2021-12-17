#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include <iostream>

using namespace std;

#define info(P)     (P) -> info
#define next(P)     (P) -> next
#define prev(P)     (P) -> prev
#define first(L)    ((L).first)
#define last(L)     ((L).last)
#define alokasi(P)  (P) -> alokasi
#define nil NULL

typedef int infotype;
typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
address newElement(infotype dataBaru);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address Prec);
void printList(List L);
address deleteFirst(List &L);
address deleteLast(List &L);
address deleteAfter(address prec);
void insertAsc(List &L, infotype databaru);
void deleteElement(List &L, infotype dataHapus);
bool findElement(List L, infotype data);
int frequencyElement(List L, infotype data);

#endif // DLL_H_INCLUDED
