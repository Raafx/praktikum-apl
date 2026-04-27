#include <iostream>
#include <vector>
#include "menu.h"
#include "autentication.h"

using namespace std;

int main()
{
    int JumlahData = 0;
    int jumlahUser = 0;

    bool programStatus = true;
    bool loginStatus;

    while (programStatus == true)
    {

        cout
            << "\n==========| SELAMAT DATANG PADA PROGRAM MANAJEMEN BOOKING FREELANCE |==========" << endl;

        int role = menuRole();
        switch (role)
        {
        case 1:

            loginStatus = adminLogin();
            if (loginStatus == true)
            {
                menuAdmin(JumlahData);
            }
            else
            {
                cout << "Anda Terlalu banyak mencoba, program akan berhenti secara otomatis..." << endl;
                programStatus = false;
            }

            break;
        case 2:
        {

            int multiUser = 0;

            while (multiUser != 3)
            {
                multiUser = autentikasiUser();
                switch (multiUser)
                {
                case 1:
                    userRegist(jumlahUser);
                    break;
                case 2:
                    userLogin(jumlahUser, JumlahData);
                    multiUser = 3;
                    break;
                case 3:
                    break;
                default:
                    cin.clear();
                    cin.ignore(1000, '\n');
                    break;
                }
            }
        }
        break;

        case 3:
            programStatus = false;
            break;
        default:
            cin.clear();
            cin.ignore(10000, '\n');
            cout
                << "Input tidak dikenali, silahkan ulangi proses input!" << endl;
            role = 0;

            break;
        }
    }

    cout << "\n================| Program Berakhir |================" << endl;

    return 0;
}