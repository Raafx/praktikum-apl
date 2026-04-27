#ifndef CRUD_H
#define CRUD_H
#include <iostream>
#include "inputHandler.h"
#include "struct.h"
#include <iomanip>

using namespace std;

void createData(int &jumlahData, Freelance *dataPesanan)
{

    cout << "\n===========================================" << endl
         << "Silahkan Buat Data Pesaan Freelance Baru (ADMIN): \n"
         << endl;

    inputNamaKlien(&dataPesanan[jumlahData]);
    inputJenisJasa(&dataPesanan[jumlahData]);
    inputDeadline(&dataPesanan[jumlahData]);
    inputBudget(&dataPesanan[jumlahData]);
    dataPesanan[jumlahData].statusProject = false;
    cin.ignore();

    jumlahData += 1;
    cout << "\n========== Data Pesanan Berhasil Dibuat! ==========\n"
         << endl;
    bool lanjut = isLanjut("Apakah nda ingin membuat data pesanan lain? (Y/N): ");

    if (lanjut)
    {
        createData(jumlahData, dataPesanan);
    }
}

void createData(int &jumlahDataGlobal, int jumlahDataUser, Freelance *dataPesananUser)
{
    cout << "\n===========================================" << endl
         << "Silahkan Buat Data Pesaan Freelance Baru (USER): \n"
         << endl;

    inputNamaKlien(&dataPesananUser[jumlahDataUser]);
    inputJenisJasa(&dataPesananUser[jumlahDataUser]);
    inputDeadline(&dataPesananUser[jumlahDataUser]);
    inputBudget(&dataPesananUser[jumlahDataUser]);
    dataPesananUser[jumlahDataUser].statusProject = false;
    cin.ignore();
    dataPesananFreelance[jumlahDataGlobal] = dataPesananUser[jumlahDataUser];

    jumlahDataUser += 1;
    jumlahDataGlobal += 1;

    cout << "\n========== Data Pesanan Berhasil Dibuat! ==========\n"
         << endl;
    bool lanjut = isLanjut("Apakah nda ingin membuat data pesanan lain? (Y/N): ");

    if (lanjut)
    {
        createData(jumlahDataGlobal, jumlahDataUser, dataPesananUser);
    }
}

void readData(int &jumlahData, Freelance *dataPesanan)
{
    cout << "\n============================================================================================================" << endl;
    cout << left
         << setw(5) << "No"
         << setw(20) << "Nama Klien"
         << setw(20) << "Jenis Jasa"
         << setw(15) << "Deadline"
         << setw(15) << "Budget"
         << setw(20) << "Status Pesanan"
         << endl;
    cout << "------------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < jumlahData; i++)
    {
        string statusPesanan = (dataPesanan + i)->statusProject
                                   ? "Sudah Selesai"
                                   : "Belum Selesai";
        string deadline =
            to_string((dataPesanan + i)->deadline.day) + "-" +
            to_string((dataPesanan + i)->deadline.month) + "-" +
            to_string((dataPesanan + i)->deadline.year);
        cout << left
             << setw(5) << i + 1
             << setw(20) << (dataPesanan + i)->namaKlien
             << setw(20) << (dataPesanan + i)->jenisJasa
             << setw(15) << deadline
             << setw(15) << (dataPesanan + i)->budget
             << setw(20) << statusPesanan
             << endl;
    }

    cout << "============================================================================================================\n"
         << endl;
}

void updateData(int &jumlahData, Freelance *dataPesanan)
{
    isValid = false;
    int dataDipilih;
    readData(jumlahData, dataPesanan);

    do
    {
        cout << "Pilih Data pesanan yang akan diubah: ";
        cin >> dataDipilih;
        cin.ignore();
        if (dataDipilih < 1 || dataDipilih > jumlahData)
        {
            isValid = false;
            cout << "Data Tidak ditemukan!" << endl;
        }
        else
        {
            isValid = true;
        }
    } while (!isValid);

    int jenisDataDipilih;

    cout
        << "1. Nama klien" << endl
        << "2. Jenis jasa" << endl
        << "3. Deadline" << endl
        << "4. Budget" << endl
        << "5. Status project" << endl
        << "Pilih jenis data yang ingin diubah: " << endl;
    cin >> jenisDataDipilih;
    cin.ignore();

    switch (jenisDataDipilih)
    {

    case 1:
        inputNamaKlien(&dataPesanan[dataDipilih - 1]);
        break;
    case 2:
        inputJenisJasa(&dataPesanan[dataDipilih - 1]);
        break;
    case 3:
        inputDeadline(&dataPesanan[dataDipilih - 1]);
        break;
    case 4:
        inputBudget(&dataPesanan[dataDipilih - 1]);
        break;

    case 5:
        char status;
        cout << "Ubah Status Pesanan menjadi Selesai? [Y/N]: ";
        cin >> status;
        switch (status)
        {
        case 'y':
            dataPesanan[dataDipilih - 1].statusProject = true;
            break;
        case 'Y':
            dataPesanan[dataDipilih - 1].statusProject = true;
            break;
        default:
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }
        break;

    default:
        cin.clear();
        cin.ignore(1000, '\n');
        break;
    }

    bool lanjut = isLanjut("Apakah nda ingin mengubah data pesanan lain? (Y/N): ");

    if (lanjut)
    {
        updateData(jumlahData, dataPesanan);
    }
}

void deleteData(int &jumlahData, Freelance *dataPesanan)
{
    isValid = false;
    int dataDipilih;
    readData(jumlahData, dataPesanan);
    do
    {
        cout << "Pilih Data Pesanan yang ingin dihapus: ";
        cin >> dataDipilih;
        cin.clear();
        cin.ignore(1000, '\n');
        if (dataDipilih < 1 || dataDipilih > jumlahData)
        {
            isValid = false;
            cout << "Data Tidak ditemukan!" << endl;
        }
        else
        {
            for (int i = dataDipilih - 1; i < jumlahData - 1; i++)
            {
                *(dataPesanan + i) = *(dataPesanan + (i + 1));
            }

            jumlahData -= 1;
            isValid = true;

            cout << "\n=========| Data Berhasil Dihapus! |=========\n"
                 << endl;
        }

    } while (!isValid);

    bool lanjut = isLanjut("Apakah nda ingin menghapus data pesanan lain? (Y/N): ");

    if (lanjut)
    {
        deleteData(jumlahData, dataPesanan);
    }
}

#endif