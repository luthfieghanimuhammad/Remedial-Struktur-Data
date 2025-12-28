#include <iostream>
#include "SLL.h"
using namespace std;

int main()
{
    list L;
    infotype data;
    address hasil;
    int jumlahData;

    createList(L);

    cout << "============================================" << endl;
    cout << "     PROGRAM MANAJEMEN DATA PANEN          " << endl;
    cout << "============================================" << endl << endl;

    cout << "Masukkan jumlah data panen : ";
    while(!(cin >> jumlahData)){
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input tidak valid! Masukkan angka: ";
    }
    cin.ignore();
    cout << endl;
    for(int i = 1; i <= jumlahData; i++){
        cout << "Data Panen ke-" << i << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Nama Tanaman      : ";
        getline(cin, data.tanaman);
        bool bulanValid = false;
        while(!bulanValid){
            cout << "Bulan Panen       : ";
            getline(cin, data.bulan);
            if(data.bulan == "Januari" || data.bulan == "Februari" || data.bulan == "Maret" ||
               data.bulan == "April" || data.bulan == "Mei" || data.bulan == "Juni" ||
               data.bulan == "Juli" || data.bulan == "Agustus" || data.bulan == "September" ||
               data.bulan == "Oktober" || data.bulan == "November" || data.bulan == "Desember"){
                bulanValid = true;
            } else {
                cout << "Bulan tidak valid! Masukkan bulan dari Januari-Desember" << endl;
            }
        }
        cout << "Jumlah Panen (kg) : ";
        while(!(cin >> data.jumlah)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Input tidak valid! Masukkan angka: ";
        }
        cin.ignore();
        tambahData(L, data);
        cout << endl;
    }

    cout << "============================================" << endl;
    cout << "          DAFTAR SEMUA DATA PANEN          " << endl;
    cout << "============================================" << endl;
    address p = L.first;
    int no = 1;
    while(p != nullptr){
        cout << no << ". " << p->info.tanaman
             << " | " << p->info.bulan
             << " | " << p->info.jumlah << " kg" << endl;
        p = p->next;
        no++;
    }

    cout << endl;
    cout << "============================================" << endl;
    cout << "             PANEN TERBANYAK               " << endl;
    cout << "============================================" << endl;
    hasil = panenTerbanyak(L);
    if(hasil != nullptr){
        cout << "Tanaman           : " << hasil->info.tanaman << endl;
        cout << "Bulan             : " << hasil->info.bulan << endl;
        cout << "Jumlah Panen      : " << hasil->info.jumlah << " kg" << endl;
    }
    cout << endl;
    cout << "============================================" << endl;
    cout << "        CARI PANEN BERDASARKAN BULAN       " << endl;
    cout << "============================================" << endl;

    bool bulanCariValid = false;
    while(!bulanCariValid){
        cout << "Masukkan Bulan    : ";
        getline(cin, data.bulan);
        if(data.bulan == "Januari" || data.bulan == "Februari" || data.bulan == "Maret" ||
           data.bulan == "April" || data.bulan == "Mei" || data.bulan == "Juni" ||
           data.bulan == "Juli" || data.bulan == "Agustus" || data.bulan == "September" ||
           data.bulan == "Oktober" || data.bulan == "November" || data.bulan == "Desember"){
            bulanCariValid = true;
        }else{
            cout << "Bulan tidak valid! Masukkan bulan dari Januari-Desember" << endl;
        }
    }
    cout << "Tanaman Dipanen   : ";
    panenBulanan(L, data);
    cout << endl;
    cout << "============================================" << endl;
    return 0;
}

