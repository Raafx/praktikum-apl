#include <iostream>
using namespace std;

int main()
{
    string nama = "Rafi";
    string nim = "034";

    string username;
    string password;

    int percobaan = 3;

    cout << "==========| SELAMAT DATANG PADA PROGRAM KONVERSI PANJANG |==========" << endl;

    cout << "\nSilhakan Login terlebih dahulu menggunakna nama dan 3 digit NIM terakhir anda\n"
         << endl;

    while (percobaan != 0)
    {
        cout << "username: ";
        getline(cin, username);
        cout << "password: ";
        getline(cin, password);

        percobaan -= 1;

        if (username == nama && password == nim)
        {
            char menuDipilih[1] = {'0'};
            cout << "\n================| LOGIN BERHASIL! |================"
                 << endl;
            while (menuDipilih[0] != '4')
            {

                cout << "\nSilahkan Pilih Menu dibawah ini: " << endl
                     << "1. Konversi Meter -> Kilometer dan Centimeter" << endl
                     << "2. Konversi Kilometer -> Meter dan Centimeter" << endl
                     << "3. Konversi Centimeter -> Meter dan Kilometer" << endl
                     << "4. Keluar" << endl;

                cout << "Pilih Menu (1-4): ";
                cin >> menuDipilih;

                float panjang;
                float meter;
                float kilometer;
                float centimeter;
                char isLanjut;

                switch (menuDipilih[0])
                {
                case '1':

                    cin.ignore();
                    cout << "Input Jarak dalam Meter: ";
                    cin >> panjang;

                    kilometer = panjang / 1000;
                    centimeter = panjang * 100;

                    cout << "\n==========================" << endl
                         << "Hasil Konversi: \n"
                         << endl
                         << "Kilometer: " << kilometer << endl
                         << "Centimeter: " << centimeter << endl
                         << "==========================\n"
                         << endl;

                    cout << "Ingin melakukan Konversi lagi? (Y/N): ";
                    cin >> isLanjut;

                    if (isLanjut == 'Y' || isLanjut == 'y')
                    {
                        break;
                    }
                    else
                    {
                        menuDipilih[0] = 4;
                        percobaan = 0;
                        break;
                    }

                case '2':
                    cin.ignore();
                    cout << "Input Jarak dalam Kilometer: ";
                    cin >> panjang;

                    meter = panjang * 1000;
                    centimeter = panjang * 100000;

                    cout << "\n==========================" << endl
                         << "Hasil Konversi: \n"
                         << endl
                         << "Meter: " << meter << endl
                         << "Centimeter: " << centimeter << endl
                         << "==========================\n"
                         << endl;

                    cout << "Ingin melakukan Konversi lagi? (Y/N): ";
                    cin >> isLanjut;

                    if (isLanjut == 'Y' || isLanjut == 'y')
                    {
                        break;
                    }
                    else
                    {
                        menuDipilih[0] = 4;
                        percobaan = 0;
                        break;
                    }

                case '3':
                    cin.ignore();
                    cout << "Input Jarak dalam Centimeter: ";
                    cin >> panjang;

                    meter = panjang / 100;
                    kilometer = panjang / 100000;

                    cout << "\n==========================" << endl
                         << "Hasil Konversi: \n"
                         << endl
                         << "Meter: " << meter << endl
                         << "Kilometer: " << kilometer << endl
                         << "==========================\n"
                         << endl;

                    cout << "Ingin melakukan Konversi lagi? (Y/N): ";
                    cin >> isLanjut;

                    if (isLanjut == 'Y' || isLanjut == 'y')
                    {
                        break;
                    }
                    else
                    {
                        menuDipilih[0] = 4;
                        percobaan = 0;
                        break;
                    }

                case '4':
                    cin.ignore();
                    percobaan = 0;
                    break;

                default:
                    cout << "Pilihan tidak dikenali, silahkan input ulang!" << endl;
                    break;
                }
            }
        }

        else
        {
            cout << "username dan password salah, silahkan coba lagi! (sisa Percobaan: " << percobaan << ")" << endl;
            if (percobaan == 0)
            {
                cout << "\nSisa percobaan Habis, anda akan dibawa ke akhir program" << endl;
            }
        }
    }

    cout << "\n================| Program Berakhir |================" << endl;

    return 0;
}