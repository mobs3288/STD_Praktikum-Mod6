#include "DLL.h"

// Fungsi untuk membuat list kosong
void createList(List &L) {
    first(L) = nil;
    last(L) = nil;
}

// Fungsi untuk membuat elemen baru
address newElement(infotype dataBaru) {
    address P = new elmList;

    info(P) = dataBaru;
    next(P) = nil;
    prev(P) = nil;

    return P;
}

// Fungsi untuk memasukkan element ke pertama atau paling krii list
void insertFirst(List &L, address P) {
    if (first(L) != nil && last(L) != nil) {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    } else {
        first(L) = P;
        last(L) = P;
    }
}

// Fungsi untuk memasukkan element ke terakhir atau paling kanan list
void insertLast(List &L, address P) {
    if (first(L) == nil) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

// Fungsi untuk memasukkan elemen ke tengah atau setelah address yg dituju
void insertAfter(address Prec){
    address P;

    next(P) = next(Prec);
    prev(next(Prec)) = P;
    next(Prec) = P;
    prev(P) = Prec;
}

// Menghapus element pertama pada list
address deleteFirst(List &L) {
    address P;

    P = first(L);
    if (next(first(L)) == nil) {
        first(L) = nil;
        last(L) = nil;
    } else {
        first(L) = next(first(L));
        prev(first(L)) = nil;
        next(P) = nil;
    }

    return P;
}

// menghapus elemen terakhir pada list
address deleteLast(List &L) {
    address P;

    P = last(L);

    if (prev(last(L)) != nil) {
        last(L) = prev(last(L));
        prev(P) = nil;
        next(last(L)) = nil;
    } else {
        first(L) = nil;
        last(L) = nil;
    }

}

// menhapus element tertentu setelah address tertentu
address deleteAfter(address prec) {
    address P;

    P = next(prec);
    next(prec) = next(P);
    prev(next(P)) = prec;
    prev(P) = nil;
    next(P) = nil;

    return P;
}

// Fungsi untuk memasukkan data diurutkan langsung secara manik
void insertAsc(List &L, infotype databaru) {
    address P;
    address Q;
    address prec;

    Q = newElement(databaru);
    P = first(L);

    if (P == nil){
        insertFirst(L, Q);
    } else if(first(L) != nil && last(L) != nil){
        if (info(P) >= databaru) {
            insertFirst(L, Q);
        } else if(info(P) <= databaru){
            insertLast(L, Q);
        }
    } else if (last(L) == nil) {
        prec = first(L);
        while(info(prec) > databaru){
            insertAfter(prec);
        }
    }
}

// Fungsi untuk menghapus element yang diminta dengan nim tertentu
void deleteElement(List &L, infotype data){
    address P;
    address Q;
    address prec;

    P = nil;
    Q = first(L);
    while (Q != nil){
        if (info(Q) == data){
            P = Q;
        }
        Q = next(Q);
    }
    if (P != nil){
        if (P == first(L)){
            deleteFirst(L);
        } else if (next(P) == nil){
            deleteLast(L);
        } else {
            prec = first(L);
            while (next(prec) != P){
                prec = next(prec);
            }
            deleteAfter(prec);
        }
    } else {
        cout << "Data tidak ditemukan" << endl;
        cout << endl;
    }
}

// fungsi yang mengembalikkan nilai true atau 1 apabila data yg dicari ada
bool findElement(List L, infotype data) {
    address P;
    bool check;

    check = false;

    P = first(L);
    while (P != nil) {
        if (info(P) == data) {
            check = true;
            return check;
        }
        P = next(P);
    }
    return check;
}

// fungsi untuk menghitung jumlah masing masing angka yang ada pada list
int frequencyElement(List L, infotype data) {
    address P;
    int i = 0;

    P = first(L);
    while (P != nil) {
        if (findElement(L, data) && info(P) == data) {
            i = i + 1;
        }
        P = next(P);
    }
    return i;
}

// Fyungsi untuk menampilkan seluruh data
void printList(List L) {
    address P;

    P = first(L);

    while (P != nil) {
        cout << info(P) << " ";
        P = next(P);
    }

    if (first(L) == nil) {
        cout << "List Kosong" << endl;
    } else {
        cout << endl;
    }
}
