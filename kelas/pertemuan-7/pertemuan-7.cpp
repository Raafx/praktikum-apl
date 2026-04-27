#include <iostream>
#include "file.h"
using namespace std;

int main()
{
    try
    {
        int a = 10;
        int b = 0;
        if (b == 0)
        {
            throw runtime_error("Error pembagian dengan 0");
        }
        int c = a / b;
        cout << "Hasil: " << c << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Error ditangkap: " << e.what() << endl;
    }

    try
    {
        cout << "Masukkan bilangan positif: ";
        int angka;
        cin >> angka;
        if (cin.fail())
        {
            throw invalid_argument("Input harus berupa angka!");
        }
        if (angka < 0)
        {
            throw runtime_error("Bilangan harus bernilai positif!");
        }

        int hasilTambah = tambah(angka, angka);
        int hasilKali = kali(angka, angka);

        cout << "Hasil Tambah: " << hasilTambah << endl;
        cout << "Hasil Kali: " << hasilKali << endl;
    }
    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    cout << "Program selesai." << endl;

    return 0;
}
