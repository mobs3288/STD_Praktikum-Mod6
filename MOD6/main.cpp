#include "DLL.h"

int main()
{
    List L;
    infotype data;
    bool kondisi;
    int jumlahData;

    createList(L);

    /*insertAsc(L, 25);
    printList(L);

    insertAsc(L, 10);
    printList(L);

    insertAsc(L, 32);
    printList(L);

    insertAsc(L, 3);
    printList(L);

    deleteElement(L, 32);
    printList(L);

    deleteElement(L, 3);
    printList(L);

    deleteElement(L, 10);
    printList(L);

    deleteElement(L, 25);
    printList(L); */

    insertAsc(L, 25);
    printList(L);

    insertAsc(L, 10);
    printList(L);

    insertAsc(L, 10);
    printList(L);

    insertAsc(L, 25);
    printList(L);

    insertAsc(L, 25);
    printList(L);

    kondisi = findElement(L, 10);

    cout << "----" << endl;
    if (kondisi) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    cout << "----" << endl;

    jumlahData = frequencyElement(L, 10);
    cout << "Jumlah data 10 : " << jumlahData << endl;

    jumlahData = frequencyElement(L, 25);
    cout << "Jumlah data 25 : " << jumlahData << endl;

    jumlahData = frequencyElement(L, 2);
    cout << "Jumlah data 2  : " << jumlahData << endl;

    return 0;
}
