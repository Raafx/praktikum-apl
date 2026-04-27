#ifndef AUTH_H
#define AUTH_H
#include <iostream>
#include "struct.h"
#include "menu.h"

using namespace std;

bool adminLogin()
{
    int percobaan = 3;
    string namaAdmin = "Rafi";
    string nimAdmin = "034";
    string usernameAdmin;
    string passwordAdmin;
    bool loginStatus = false;

    while (percobaan != 0)
    {
        cout << "username Admin: ";
        getline(cin, usernameAdmin);
        cout << "password Admin: ";
        getline(cin, passwordAdmin);

        if (usernameAdmin == namaAdmin && passwordAdmin == nimAdmin)
        {
            cout << "Login Berhasil!, Selamat datang Admin " << namaAdmin << endl;
            loginStatus = true;
            return loginStatus;
        }
        else
        {
            percobaan -= 1;
            cout << "Username dan Password salah, silahkan ulangi proses Input (Sisa percobaan: " << percobaan << ")" << endl;
        }
    }
    return loginStatus;
}

int autentikasiUser()
{
    int multiUser;
    cout
        << "\n===================================" << endl
        << "1. Buat akun baru" << endl
        << "2. Login dengan akun yang sudah ada" << endl
        << "3. Keluar" << endl
        << "Input Pilihan (1-3): ";
    cin >> multiUser;
    cin.ignore();

    return multiUser;
}

void userRegist(int &jumlahUser)
{
    cout << "Buat username baru: ";
    getline(cin, dataUser[jumlahUser].username);
    cout << "Buat Password Baru: ";
    getline(cin, dataUser[jumlahUser].password);

    cout << "\n=====| Akun anda berhasil dibuat, Silahkan Login dengan akun anda! |=====\n"
         << endl;

    dataUser[jumlahUser].JumlahPesananUser = 0;
    jumlahUser += 1;
}

void userLogin(int &jumlahUser, int &jumlahData)
{
    string usernameUser;
    string passwordUser;
    bool userDitemukan;
    int percobaan = 3;
    if (jumlahUser == 0)
    {
        cout << "BELUM ADA DATA USER YANG DIBUAT!" << endl
             << "Silahkan Buat akun terlebih dahulu" << endl;
    }
    else
    {
        while (percobaan != 0)
        {
            userDitemukan = false;
            cout << "Input Username Anda: ";
            getline(cin, usernameUser);
            cout << "Input Password Anda: ";
            getline(cin, passwordUser);
            for (int indexUser = 0; indexUser < jumlahUser; indexUser++)
            {

                if (dataUser[indexUser].username == usernameUser && dataUser[indexUser].password == passwordUser)
                {
                    userDitemukan = true;
                    menuUser(jumlahData, indexUser);
                    return;
                }
            }
            if (userDitemukan == false)
            {
                percobaan -= 1;
                cout << "Username dan Password salah, silahkan ulangi proses Input (Sisa percobaan: " << percobaan << ")" << endl;
            }
        }
    }
}

#endif