#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};
struct Freelance
{
    string namaKlien;
    string jenisJasa;
    Date deadline;
    int budget;
    bool statusProject;
};

struct User
{
    string username;
    string password;
    int JumlahPesananUser;
    Freelance dataPesanan[10];
};

string jenisJasa[3] = {"Desain", "Website", "Edit Video"};
Freelance dataPesananFreelance[10];
User dataUser[10];
int kapasitasData = sizeof(dataPesananFreelance) / sizeof(dataPesananFreelance[0]);

bool isValid;

bool isLanjut(string message)
{
    isValid = false;
    char lanjut;
    do
    {
        cout << message;
        cin >> lanjut;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            isValid = false;
        }
        else if (lanjut == 'Y' || lanjut == 'y')
        {
            cin.ignore();
            return true;
        }
        else
        {
            cin.ignore();
            return false;
        }

    } while (!isValid);
}

void isNumber(int &inputTarget, string messages)
{
    isValid = false;
    do
    {
        cout << messages;
        cin >> inputTarget;
        if (cin.fail() || inputTarget < 0)
        {
            cout << "Format input tidak dikenali!" << endl;
            isValid = false;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
        {
            isValid = true;
        }
    } while (!isValid);
}

void inputNamaKlien(Freelance *dataPesanan)
{
    cout << "Input Nama Klien: ";
    getline(cin, dataPesanan->namaKlien);
}

void inputJenisJasa(Freelance *dataPesanan)
{
    isValid = false;

    for (int i = 0; i < sizeof(jenisJasa) / sizeof(jenisJasa[0]); i++)
    {
        cout << i + 1 << ". " << jenisJasa[i] << endl;
    }
    int jenisJasaDipilih;
    do
    {
        isNumber(jenisJasaDipilih, "Pilih Jenis Jasa: ");
        if (jenisJasaDipilih < 1 || jenisJasaDipilih > sizeof(jenisJasa) / sizeof(jenisJasa[0]))
        {
            isValid = false;
        }
        else
        {
            dataPesanan->jenisJasa = jenisJasa[jenisJasaDipilih - 1];
            isValid = true;
        }
    } while (!isValid);
}

void inputDeadline(Freelance *dataPesanan)
{
    isValid = false;
    cout << "Deadline:"
         << endl;
    do
    {
        isNumber(dataPesanan->deadline.day, "Tanggal (1-31): ");
        if (dataPesanan->deadline.day < 1 || dataPesanan->deadline.day > 31)
        {
            cout << "Tanggal Tidak Sesuai!" << endl;
            isValid = false;
        }
        else
        {
            isValid = true;
        }
    } while (!isValid);

    do
    {
        isNumber(dataPesanan->deadline.month, "Bulan (1-12): ");
        if (dataPesanan->deadline.month < 1 || dataPesanan->deadline.month > 12)
        {
            cout << "Bulan Tidak Sesuai!" << endl;
            isValid = false;
        }
        else
        {
            isValid = true;
        }
    } while (!isValid);

    do
    {
        isNumber(dataPesanan->deadline.year, "Tahun ( >> 2025): ");
        if (dataPesanan->deadline.year < 2026)
        {
            cout << "Tahun tidak sesuai!" << endl;
            isValid = false;
        }
        else
        {
            isValid = true;
        }
    } while (!isValid);
}

void inputBudget(Freelance *dataPesanan)
{
    isNumber(dataPesanan->budget, "Budget: ");
}

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
                *(dataPesanan+ i) = *(dataPesanan + (i + 1));
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
        deleteData(jumlahData,dataPesanan);
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
                readData(jumlahData, dataPesananFreelance);
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

                updateData(jumlahData,dataPesananFreelance);
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

                deleteData(jumlahData,dataPesananFreelance);
            }
            break;
        case 5:
            return;

        default:
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }
    }
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
                readData(dataUser[indexUser].JumlahPesananUser,
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