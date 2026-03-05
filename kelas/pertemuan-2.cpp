#include <iostream>
using namespace std;

int main()
{
    int bilangan[5];
    string nama[4];
    float nilai[10];
    string buah[] = {"Jeruk", "Mangga", "Nanas", "Apel"};

    int angka[3];
    angka[0] = 10;
    angka[1] = 19;
    angka[2] = 30;

    // Penyisipan
    buah[4] = "Rambutan";
    for (int i = 0; i < 5; i++)
    {
        cout << buah[i] << endl;
    }

    // Pengaksesan
    cout << buah[0] << endl;
    cout << angka[2] << endl;
    // For each perulangan
    for (string x : buah)
    {
        cout << x << endl;
    }

    // Menghitung oanjang array
    int panjang = sizeof(angka) / sizeof(angka[0]);
    cout << "Panjang array: " << panjang << endl;

    // Array 2 dimensi

    int matriks[3][3] = {

        {1, 2, 3}, // Baris ke-0
        {4, 5, 6}, // Baris ke-1
        {7, 8, 9}  // Baris ke-2

    };
    // Mengakses elemen
    cout << matriks[0][1] << endl;
    cout << matriks[2][0] << endl;
    // Menampilkan seluruh matriks dengan nested loop
    for (int i = 0; i < 3; i++)
    {
        // Loop baris
        for (int j = 0; j < 3; j++)
        {
            // Loop kolom
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
    for (auto &baris : matriks)
    {
        // Iterasi setiap baris(array 1D)
        for (auto &elemen : baris)
        {
            // Iterasi setiap elemen dalam baris
            cout << elemen << " ";
        }
        cout << endl;
    }

    return 0;
}