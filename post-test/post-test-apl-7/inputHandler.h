#ifndef INPUT_HANDLER
#define INPUT_HANDLER
#include <iostream>
#include "struct.h"
#include "errorHandler.h"
using namespace std;

bool isValid;
string jenisJasa[3] = {"Desain", "Website", "Edit Video"};

void inputNamaKlien(Freelance *dataPesanan)
{
    cout << "Input Nama Klien: ";
    getline(cin, dataPesanan->namaKlien);
}

void inputJenisJasa(Freelance *dataPesanan)
{
    isValid = false;

    int jenisJasaDipilih;

    for (int i = 0; i < sizeof(jenisJasa) / sizeof(jenisJasa[0]); i++)
    {
        cout << i + 1 << ". " << jenisJasa[i] << endl;
    }
    while (!isValid)
    {
        try
        {

            isNumber(jenisJasaDipilih, "Pilih Jenis Jasa: ");

            if (jenisJasaDipilih < 1 || jenisJasaDipilih > sizeof(jenisJasa) / sizeof(jenisJasa[0]))
            {
                throw invalid_argument("Input Tidak Dikenali, Silahkan input antara 1-3");
            }
            else
            {
                dataPesanan->jenisJasa = jenisJasa[jenisJasaDipilih - 1];
                isValid = true;
            }
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << '\n';
        }
    }
}

void inputDeadline(Freelance *dataPesanan)
{
    isValid = false;
    cout << "Deadline:" << endl;

    do
    {
        try
        {
            isNumber(dataPesanan->deadline.day, "Tanggal (1-31): ");
            if (dataPesanan->deadline.day < 1 || dataPesanan->deadline.day > 31)
            {
                throw invalid_argument("Tanggal Tidak Sesuai!");
            }
            else
            {
                isValid = true;
            }
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << '\n';
            isValid = false;
        }
    } while (!isValid);

    do
    {
        try
        {
            isNumber(dataPesanan->deadline.month, "Bulan (1-12): ");
            if (dataPesanan->deadline.month < 1 || dataPesanan->deadline.month > 12)
            {
                throw invalid_argument("Bulan Tidak Sesuai!");
            }
            else
            {
                isValid = true;
            }
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << '\n';
            isValid = false;
        }

    } while (!isValid);

    do
    {
        try
        {
            isNumber(dataPesanan->deadline.year, "Tahun ( >> 2025): ");
            if (dataPesanan->deadline.year < 2026)
            {
                throw invalid_argument("Tahun tidak sesuai!");
            }
            else
            {
                isValid = true;
            }
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << '\n';
            isValid = false;
        }
    } while (!isValid);
}

void inputBudget(Freelance *dataPesanan)
{
    isNumber(dataPesanan->budget, "Budget: ");
}

#endif