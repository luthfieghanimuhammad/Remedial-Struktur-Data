#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED
using namespace std;

struct tPanen {
    string tanaman;
    string bulan;
    int jumlah;
};

typedef struct tPanen infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct list {
    address first;
};

void createList(list &L);
address createNewElm(infotype x);
void tambahData(list &L, infotype x);
address panenTerbanyak(list L);
void panenBulanan(list L, infotype x);
#endif // SLL_H_INCLUDED
