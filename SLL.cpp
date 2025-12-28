#include <iostream>
#include "SLL.h"
using namespace std;

void createList(list &L){
    L.first = nullptr;
}
address createNewElm(infotype x){
    address P = new elmlist;
    P->info = x;
    P->next = nullptr;
    return P;
}
void tambahData(list &L, infotype x){
   address p;
   p = createNewElm(x);
   if(L.first == nullptr){
        L.first = p;
    } else {
        p->next = L.first;
        L.first = p;
    }
}
address panenTerbanyak(list L){
    address p;
    address maxAdr;
    if (L.first == nullptr){
        return nullptr;
    }else{
        maxAdr = L.first;
        p = L.first->next;

        while(p != nullptr){
            if(p->info.jumlah > maxAdr->info.jumlah){
                maxAdr = p;
            }
            p = p->next;
        }
        return maxAdr;
    }
}
void panenBulanan(list L, infotype x){
     address p;
     p = L.first;
    while(p != nullptr) {
        if(p->info.bulan == x.bulan){
            cout << p->info.tanaman << " ";
        }
        p = p->next;
    }
    cout << endl;
}
