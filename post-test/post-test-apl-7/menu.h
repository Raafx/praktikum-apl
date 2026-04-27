#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "struct.h"
#include "sort.h"
#include "search.h"
#include "crud.h"
using namespace std;

void cariBerdasarkanBudget(Freelance *dataPesanan, int &jumlahData)
{
    int target;
    isNumber(target, "Input Budget Pesanan yang ingin Anda Cari: ");
    quickSort(dataPesanan, 0, jumlahData - 1);
    int indexData = binarySearch(dataPesanan, jumlahData, target);

    if (indexData == -1)
    {
        cout << "Data dengan budget tersebut tidak ditemukan!\n";
    }
    else
    {
        int jumlahDataDitampilin = 1;
        readData(jumlahDataDitampilin, &dataPesanan[indexData]);
    }
}

void cariBerdasarkanNama(Freelance *dataPesanan, int &jumlahData)
{
    string target;
    cout << "Input Nama Klien yang ingin Anda Cari: ";
    getline(cin, target);
    bubbleSort(dataPesanan, jumlahData);
    int indexData = jumpSearch(dataPesanan, target, jumlahData);

    if (indexData == -1)
    {
        cout << "Data dengan Nama Klien tersebut tidak ditemukan!\n";
    }
    else
    {
        int jumlahDataDitampilin = 1;
        readData(jumlahDataDitampilin, &dataPesanan[indexData]);
    }
}

void menuReadData(int &jumlahData, Freelance *dataPesanan)
{
    int menuTampilan = 0;
    cout << "1. Tampilkan Data Berdasarkan Nama (Menurun)" << endl
         << "2. Tampilkan Data Berdasarkan Budget (Menaik)" << endl
         << "3. Tampilkan Data Berdasarkan Deadline (Menaik)" << endl
         << "4. Cari Data Berdasarkan Budget" << endl
         << "5. Cari Data Berdasarkan Nama Klien" << endl
         << "Pilih Metode Tampilan (1-3): ";

    cin >> menuTampilan;
    cin.ignore();

    switch (menuTampilan)
    {
    case 1:
        bubbleSort(dataPesanan, jumlahData);
        readData(jumlahData, dataPesanan);
        break;
    case 2:
        quickSort(dataPesanan, 0, jumlahData - 1);
        readData(jumlahData, dataPesanan);
        break;
    case 3:
        inputDeadline(dataPesananFreelance);
        readData(jumlahData, dataPesanan);
        break;
    case 4:
        cariBerdasarkanBudget(dataPesanan, jumlahData);
        break;
    case 5:
        cariBerdasarkanNama(dataPesanan, jumlahData);
        break;

    default:
        cout << "\nInput Tidak dikenali, silahkan ulangi proses input!\n"
             << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        break;
    }
}

int menuRole()
{
    int role;
    cout
        << "\nSilhakan Pilih Role Anda: \n"
        << endl;

    cout << "1. Admin" << endl
         << "2. User" << endl
         << "3. Keluar" << endl
         << "Input Pilihan (1-3): ";
    cin >> role;
    cin.ignore();

    return role;
}

void menuAdmin(int &jumlahData)
{
    cout << "\n================| MENU ADMIN BOOKING JASA FREELANCE |================\n"
         << endl;
    int menu = 0;
    while (true)
    {
        cout << "========================================" << endl
             << "|No| Menu                              |" << endl
             << "|--|-----------------------------------|" << endl
             << "|1.| Buat Pesanan Freelance            |" << endl
             << "|2.| Lihat Daftar Pesanan Freelance    |" << endl
             << "|3.| Update Data Pesanan Freelance     |" << endl
             << "|4.| Hapus Data Pesanan Freelance      |" << endl
             << "|5.| Logout                            |" << endl
             << "========================================" << endl
             << "Input Pilihan (1-5): ";
        cin >> menu;
        cin.ignore();
        switch (menu)
        {
        case 1:

            if (jumlahData < kapasitasData)
            {
                createData(jumlahData, dataPesananFreelance);
            }
            else
            {
                cout << "Jumlah Pesanan sudah terlalu banyak!" << endl;
            }

            break;
        case 2:

            if (jumlahData == 0)
            {
                cout << "\nBELUM ADA DATA PESANAN YANG BISA DITAMPILKAN!\n"
                     << endl;
            }
            else
            {
                menuReadData(jumlahData, dataPesananFreelance);
            }

            break;
        case 3:

            if (jumlahData == 0)
            {
                cout << "\nBELUM ADA DATA PESANAN YANG BISA DIUBAH!\n"
                     << endl;
            }
            else
            {

                updateData(jumlahData, dataPesananFreelance);
            }

            break;
        case 4:
            if (jumlahData == 0)
            {
                cout << "\nBELUM ADA DATA PESANAN YANG BISA DIHAPUS!\n"
                     << endl;
            }
            else
            {

                deleteData(jumlahData, dataPesananFreelance);
            }
            break;
        case 5:
            return;

        default:
            cout << "\nInput Tidak dikenali, silahkan ulangi proses input!\n"
                 << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }
    }
}

void menuUser(int &jumlahData, int &indexUser)
{
    int menu;
    while (true)
    {
        /* code */
        cout << "\n================| MENU BOOKING JASA FREELANCE |================\n"
             << endl;
        cout << "========================================" << endl
             << "|No| Menu                              |" << endl
             << "|--|-----------------------------------|" << endl
             << "|1.| Buat Pesanan Freelance            |" << endl
             << "|2.| Lihat Daftar Pesanan Freelance    |" << endl
             << "|3.| Keluar                            |" << endl
             << "========================================" << endl
             << "Input Pilihan (1-3): ";
        cin >> menu;
        cin.ignore();

        switch (menu)
        {
        case 1:
            createData(
                jumlahData,
                dataUser[indexUser].JumlahPesananUser,
                dataUser[indexUser].dataPesanan);

            break;
        case 2:

            if (jumlahData == 0 || dataUser[indexUser].JumlahPesananUser == 0)
            {
                cout << "\nBELUM ADA DATA PESANAN YANG BISA DITAMPILKAN!\n"
                     << endl;
            }
            else
            {
                menuReadData(dataUser[indexUser].JumlahPesananUser,
                             dataUser[indexUser].dataPesanan);
            }

            break;

        case 3:
            return;

        default:
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }
    }
}

#endif