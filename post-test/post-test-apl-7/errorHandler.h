#ifndef ERROR_HANDLER
#define ERROR_HANDLER

#include <iostream>
using namespace std;

void isNumber(int &inputTarget, string messages)
{
    bool isValid = false;
    while (!isValid)
    {
        try
        {
            cout << messages;
            cin >> inputTarget;
            if (cin.fail())
            {
                throw invalid_argument("Input harus berupa angka!");
            }
            else
            {
                isValid = true;
            }
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

bool isLanjut(string message)
{
    bool isValid = false;
    char lanjut;
    while (!isValid)
    {
        try
        {
            cout << message;
            cin >> lanjut;
            if (lanjut == 'Y' || lanjut == 'y')
            {
                cin.ignore();
                return true;
            }
            else if (lanjut == 'N' || lanjut == 'n')
            {
                cin.ignore();
                return false;
            }
            else
            {
                throw invalid_argument("Input Tidak dikenali, mohon input Y jika setuju dan N jika tidak");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << '\n';
        }

        if (lanjut == 'Y' || lanjut == 'y')
        {
            cin.ignore();
            return true;
        }
    }
}

#endif