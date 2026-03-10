#include <iostream>
#include <iomanip>
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
    float budget;
    bool statusProject;
};

struct User
{
    string username;
    string password;
    int JumlahPesananUser;
    Freelance dataPesanan;
};

string jenisJasa[3] = {"Desain", "Website", "Edit Video"};
Freelance dataPesananFreelance[10];
User dataUser[10];

int main()
{

    int kapasitasData = sizeof(dataPesananFreelance) / sizeof(dataPesananFreelance[0]);
    int JumlahData = 0;
    int jumlahUser = 0;

    string namaAdmin = "Rafi";
    string nimAdmin = "034";

    string usernameAdmin;
    string passwordAdmin;

    string usernameUser;
    string passwordUser;

    int role = 0;
    bool programStatus = true;
    bool loginStatus = false;
    int menu;
    int percobaan;

    bool isValid;

    while (programStatus)
    {
        percobaan = 3;
        cout
            << "\n==========| SELAMAT DATANG PADA PROGRAM MANAJEMEN BOOKING FREELANCE |==========" << endl;

        cout << "\nSilhakan Pilih Role Anda: \n"
             << endl;

        cout << "1. Admin" << endl
             << "2. User" << endl
             << "3. Keluar" << endl
             << "Input Pilihan (1-3): ";
        cin >> role;
        cin.ignore();

        switch (role)
        {
        case 1:

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
                    while (loginStatus == true)
                    {
                        cout << "\n================| MENU ADMIN BOOKING JASA FREELANCE |================\n"
                             << endl;

                        menu = 0;
                        while (menu != 5)
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

                                if (JumlahData < kapasitasData)
                                {

                                    cout << "\n===========================================" << endl
                                         << "Silahkan Buat Data Pesaan Freelance Baru: \n"
                                         << endl;

                                    cout << "Input Nama Klien: ";
                                    getline(cin, dataPesananFreelance[JumlahData].namaKlien);

                                    for (int i = 0; i < sizeof(jenisJasa) / sizeof(jenisJasa[0]); i++)
                                    {
                                        cout << i + 1 << ". " << jenisJasa[i] << endl;
                                    }

                                    int jenisJasaDipilih;

                                    do
                                    {
                                        cout << "Pilih Jenis Jasa: ";
                                        cin >> jenisJasaDipilih;
                                        if (cin.fail())
                                        {
                                            cout << "Format input tidak dikenali!" << endl;
                                            isValid = false;
                                            cin.clear();
                                            cin.ignore(1000, '\n');
                                        }

                                        else if (jenisJasaDipilih < 1 || jenisJasaDipilih > sizeof(jenisJasa) / sizeof(jenisJasa[0]))
                                        {
                                            isValid = false;
                                        }
                                        else
                                        {
                                            isValid = true;
                                        }
                                    } while (!isValid);
                                    dataPesananFreelance[JumlahData].jenisJasa = jenisJasa[jenisJasaDipilih - 1];

                                    cout << "Deadline:"
                                         << endl;

                                    do
                                    {
                                        cout << "Tanggal (1-31): ";
                                        cin >> dataPesananFreelance[JumlahData].deadline.day;
                                        if (cin.fail())
                                        {
                                            cout << "Format input tidak dikenali!" << endl;
                                            isValid = false;
                                            cin.clear();
                                            cin.ignore(1000, '\n');
                                        }
                                        else if (dataPesananFreelance[JumlahData].deadline.day < 1 || dataPesananFreelance[JumlahData].deadline.day > 31)
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
                                        cout << "Bulan (1-12): ";
                                        cin >> dataPesananFreelance[JumlahData].deadline.month;
                                        if (cin.fail())
                                        {
                                            cout << "Format input tidak dikenali!" << endl;
                                            isValid = false;
                                            cin.clear();
                                            cin.ignore(1000, '\n');
                                        }
                                        else if (dataPesananFreelance[JumlahData].deadline.month < 1 || dataPesananFreelance[JumlahData].deadline.month > 12)
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
                                        cout << "Tahun (> 2026): ";
                                        cin >> dataPesananFreelance[JumlahData].deadline.year;
                                        if (cin.fail())
                                        {
                                            cout << "Format input tidak dikenali!" << endl;
                                            isValid = false;
                                            cin.clear();
                                            cin.ignore(1000, '\n');
                                        }
                                        else if (dataPesananFreelance[JumlahData].deadline.year < 2026)
                                        {
                                            cout << "Tahun tidak sesuai!" << endl;
                                            isValid = false;
                                        }
                                        else
                                        {
                                            isValid = true;
                                        }
                                    } while (!isValid);

                                    do
                                    {
                                        cout << "Budget: ";
                                        cin >> dataPesananFreelance[JumlahData].budget;
                                        if (cin.fail())
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

                                    dataPesananFreelance[JumlahData].statusProject = false;
                                    cin.ignore();

                                    JumlahData += 1;

                                    cout << "\n========== Data Pesanan Berhasil Dibuat! ==========\n"
                                         << endl;
                                }
                                else
                                {
                                    cout << "Jumlah Pesanan sudah terlalu banyak!" << endl;
                                }

                                break;
                            case 2:

                                if (JumlahData == 0)
                                {
                                    cout << "\nBELUM ADA DATA PESANAN YANG BISA DITAMPILKAN!\n"
                                         << endl;
                                }
                                else
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

                                    for (int i = 0; i < JumlahData; i++)
                                    {
                                        string statusPesanan = dataPesananFreelance[i].statusProject
                                                                   ? "Sudah Selesai"
                                                                   : "Belum Selesai";

                                        string deadline =
                                            to_string(dataPesananFreelance[i].deadline.day) + "-" +
                                            to_string(dataPesananFreelance[i].deadline.month) + "-" +
                                            to_string(dataPesananFreelance[i].deadline.year);

                                        cout << left
                                             << setw(5) << i + 1
                                             << setw(20) << dataPesananFreelance[i].namaKlien
                                             << setw(20) << dataPesananFreelance[i].jenisJasa
                                             << setw(15) << deadline
                                             << setw(15) << dataPesananFreelance[i].budget
                                             << setw(20) << statusPesanan
                                             << endl;
                                    }

                                    cout << "============================================================================================================\n"
                                         << endl;
                                }

                                break;
                            case 3:

                                if (JumlahData == 0)
                                {
                                    cout << "\nBELUM ADA DATA PESANAN YANG BISA DIUBAH!\n"
                                         << endl;
                                }
                                else
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

                                    for (int i = 0; i < JumlahData; i++)
                                    {
                                        string statusPesanan = dataPesananFreelance[i].statusProject
                                                                   ? "Sudah Selesai"
                                                                   : "Belum Selesai";

                                        string deadline =
                                            to_string(dataPesananFreelance[i].deadline.day) + "-" +
                                            to_string(dataPesananFreelance[i].deadline.month) + "-" +
                                            to_string(dataPesananFreelance[i].deadline.year);

                                        cout << left
                                             << setw(5) << i + 1
                                             << setw(20) << dataPesananFreelance[i].namaKlien
                                             << setw(20) << dataPesananFreelance[i].jenisJasa
                                             << setw(15) << deadline
                                             << setw(15) << dataPesananFreelance[i].budget
                                             << setw(20) << statusPesanan
                                             << endl;
                                    }

                                    cout << "============================================================================================================\n"
                                         << endl;

                                    int dataDipilih;

                                    do
                                    {
                                        cout << "Pilih Data pesanan yang akan diubah: ";
                                        cin >> dataDipilih;
                                        cin.ignore();
                                        if (dataDipilih < 1 || dataDipilih > JumlahData)
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
                                        cout << "Input Nama Klien Baru: ";
                                        getline(cin, dataPesananFreelance[dataDipilih - 1].namaKlien);

                                        break;

                                    case 2:
                                        for (int i = 0; i < sizeof(jenisJasa) / sizeof(jenisJasa[0]); i++)
                                        {
                                            cout << i + 1 << ". " << jenisJasa[i] << endl;
                                        }

                                        int jenisJasaDipilih;

                                        do
                                        {
                                            cout << "Pilih Jenis Jasa Baru: ";
                                            cin >> jenisJasaDipilih;
                                            if (cin.fail())
                                            {
                                                cout << "Format input tidak dikenali!" << endl;
                                                isValid = false;
                                                cin.clear();
                                                cin.ignore(1000, '\n');
                                            }
                                        } while (!isValid);

                                        dataPesananFreelance[dataDipilih - 1].jenisJasa = jenisJasa[jenisJasaDipilih - 1];
                                        break;

                                    case 3:
                                        cout << "Deadline:"
                                             << endl;

                                        do
                                        {
                                            cout << "Tanggal (1-31): ";
                                            cin >> dataPesananFreelance[dataDipilih - 1].deadline.day;
                                            if (cin.fail())
                                            {
                                                cout << "Format input tidak dikenali!" << endl;
                                                isValid = false;
                                                cin.clear();
                                                cin.ignore(1000, '\n');
                                            }
                                            else if (dataPesananFreelance[dataDipilih - 1].deadline.day < 1 || dataPesananFreelance[dataDipilih - 1].deadline.day > 31)
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
                                            cout << "Bulan (1-12): ";
                                            cin >> dataPesananFreelance[dataDipilih - 1].deadline.month;
                                            if (cin.fail())
                                            {
                                                cout << "Format input tidak dikenali!" << endl;
                                                isValid = false;
                                                cin.clear();
                                                cin.ignore(1000, '\n');
                                            }
                                            else if (dataPesananFreelance[dataDipilih - 1].deadline.month < 1 || dataPesananFreelance[dataDipilih - 1].deadline.month > 12)
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
                                            cout << "Tahun (> 2026): ";
                                            cin >> dataPesananFreelance[dataDipilih - 1].deadline.year;
                                            if (cin.fail())
                                            {
                                                cout << "Format input tidak dikenali!" << endl;
                                                isValid = false;
                                                cin.clear();
                                                cin.ignore(1000, '\n');
                                            }
                                            else if (dataPesananFreelance[dataDipilih - 1].deadline.year < 2026)
                                            {
                                                cout << "Tahun tidak sesuai!" << endl;
                                                isValid = false;
                                            }
                                            else
                                            {
                                                isValid = true;
                                            }
                                        } while (!isValid);
                                        break;

                                    case 4:

                                        do
                                        {
                                            cout << "Input Budget Baru: ";
                                            cin >> dataPesananFreelance[dataDipilih - 1].budget;
                                            if (cin.fail())
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
                                        break;

                                    case 5:
                                        char status;
                                        cout << "Ubah Status Pesanan menjadi Selesai? [Y/N]: ";
                                        cin >> status;

                                        switch (status)
                                        {
                                        case 'y':
                                            dataPesananFreelance[dataDipilih - 1].statusProject = true;
                                            break;
                                        case 'Y':
                                            dataPesananFreelance[dataDipilih - 1].statusProject = true;
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
                                }

                                break;
                            case 4:
                                if (JumlahData == 0)
                                {
                                    cout << "\nBELUM ADA DATA PESANAN YANG BISA DIHAPUS!\n"
                                         << endl;
                                }
                                else
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

                                    for (int i = 0; i < JumlahData; i++)
                                    {
                                        string statusPesanan = dataPesananFreelance[i].statusProject
                                                                   ? "Sudah Selesai"
                                                                   : "Belum Selesai";

                                        string deadline =
                                            to_string(dataPesananFreelance[i].deadline.day) + "-" +
                                            to_string(dataPesananFreelance[i].deadline.month) + "-" +
                                            to_string(dataPesananFreelance[i].deadline.year);

                                        cout << left
                                             << setw(5) << i + 1
                                             << setw(20) << dataPesananFreelance[i].namaKlien
                                             << setw(20) << dataPesananFreelance[i].jenisJasa
                                             << setw(15) << deadline
                                             << setw(15) << dataPesananFreelance[i].budget
                                             << setw(20) << statusPesanan
                                             << endl;
                                    }

                                    cout << "============================================================================================================\n"
                                         << endl;

                                    int dataDipilih;

                                    do
                                    {
                                        cout << "Pilih Data Pesanan yang ingin dihapus: ";
                                        cin >> dataDipilih;
                                        cin.clear();
                                        cin.ignore(1000, '\n');
                                        if (dataDipilih < 1 || dataDipilih > JumlahData)
                                        {
                                            isValid = false;
                                            cout << "Data Tidak ditemukan!" << endl;
                                        }
                                        else
                                        {
                                            for (int i = dataDipilih - 1; i < JumlahData - 1; i++)
                                            {
                                                dataPesananFreelance[i] = dataPesananFreelance[i + 1];
                                            }

                                            JumlahData -= 1;
                                            isValid = true;

                                            cout << "\n=========| Data Berhasil Dihapus! |=========\n"
                                                 << endl;
                                        }

                                    } while (!isValid);
                                }
                                break;
                            case 5:

                                loginStatus = false;
                                percobaan = 0;
                                break;

                            default:
                                cin.clear();
                                cin.ignore(1000, '\n');
                                break;
                            }
                        }
                    }
                }
                else
                {
                    percobaan -= 1;
                    cout << "Username dan Password salah, silahkan ulangi proses Input (Sisa percobaan: " << percobaan << ")" << endl;

                    if (percobaan == 0)
                    {
                        cout << "Anda Terlalu banyak mencoba, program akan berhenti secara otomatis..." << endl;
                        programStatus = false;
                    }
                }
            }
            break;
        case 2:
        {

            percobaan = 3;
            int multiUser;

            while (percobaan != 0)
            {

                cout << "\n===================================" << endl
                     << "1. Buat akun baru" << endl
                     << "2. Login dengan akun yang sudah ada" << endl
                     << "3. Keluar" << endl
                     << "Input Pilihan (1-3): ";
                cin >> multiUser;
                cin.ignore();

                switch (multiUser)
                {
                case 1:

                    cout << "Buat username baru: ";
                    getline(cin, dataUser[jumlahUser].username);
                    cout << "Buat Password Baru: ";
                    getline(cin, dataUser[jumlahUser].password);

                    cout << "\n=====| Akun anda berhasil dibuat, Silahkan Login dengan akun anda! |=====\n"
                         << endl;

                    jumlahUser += 1;
                    dataUser[jumlahUser].JumlahPesananUser = 0;
                    break;

                case 2:

                    if (jumlahUser == 0)
                    {
                        cout << "BELUM ADA DATA USER YANG DIBUAT!" << endl
                             << "Silahkan Buat akun terlebih dahulu" << endl;
                    }
                    else
                    {

                        loginStatus = false;
                        cout << "Input Username Anda: ";
                        getline(cin, usernameUser);
                        cout << "Input Password Anda: ";
                        getline(cin, passwordUser);

                        for (int indexUser = 0; indexUser < jumlahUser; indexUser++)
                        {

                            if (dataUser[indexUser].username == usernameUser && dataUser[indexUser].password == passwordUser)
                            {
                                loginStatus = true;
                                bool isLogin = true;
                                int menu = 0;
                                cout << "\n================| MENU BOOKING JASA FREELANCE |================\n"
                                     << endl;
                                while (isLogin)
                                {
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
                                        if (JumlahData < kapasitasData)
                                        {

                                            cout << "\n===========================================" << endl
                                                 << "Silahkan Buat Data Pesaan Freelance Baru: \n"
                                                 << endl;

                                            cout << "Input Nama Klien: ";
                                            getline(cin, dataUser[indexUser].dataPesanan.namaKlien);

                                            for (int i = 0; i < sizeof(jenisJasa) / sizeof(jenisJasa[0]); i++)
                                            {
                                                cout << i + 1 << ". " << jenisJasa[i] << endl;
                                            }

                                            int jenisJasaDipilih;

                                            do
                                            {
                                                cout << "Pilih Jenis Jasa: ";
                                                cin >> jenisJasaDipilih;
                                                if (cin.fail())
                                                {
                                                    cout << "Format input tidak dikenali!" << endl;
                                                    isValid = false;
                                                    cin.clear();
                                                    cin.ignore(1000, '\n');
                                                }

                                                else if (jenisJasaDipilih < 1 || jenisJasaDipilih > sizeof(jenisJasa) / sizeof(jenisJasa[0]))
                                                {
                                                    isValid = false;
                                                }
                                                else
                                                {
                                                    isValid = true;
                                                }
                                            } while (!isValid);
                                            dataUser[indexUser].dataPesanan.jenisJasa = jenisJasa[jenisJasaDipilih - 1];

                                            cout << "Deadline:"
                                                 << endl;

                                            do
                                            {
                                                cout << "Tanggal (1-31): ";
                                                cin >> dataUser[indexUser].dataPesanan.deadline.day;
                                                if (cin.fail())
                                                {
                                                    cout << "Format input tidak dikenali!" << endl;
                                                    isValid = false;
                                                    cin.clear();
                                                    cin.ignore(1000, '\n');
                                                }
                                                else if (dataUser[indexUser].dataPesanan.deadline.day < 1 || dataUser[indexUser].dataPesanan.deadline.day > 31)
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
                                                cout << "Bulan (1-12): ";
                                                cin >> dataUser[indexUser].dataPesanan.deadline.month;
                                                if (cin.fail())
                                                {
                                                    cout << "Format input tidak dikenali!" << endl;
                                                    isValid = false;
                                                    cin.clear();
                                                    cin.ignore(1000, '\n');
                                                }
                                                else if (dataUser[indexUser].dataPesanan.deadline.month < 1 || dataUser[indexUser].dataPesanan.deadline.month > 12)
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
                                                cout << "Tahun (> 2026): ";
                                                cin >> dataUser[indexUser].dataPesanan.deadline.year;
                                                if (cin.fail())
                                                {
                                                    cout << "Format input tidak dikenali!" << endl;
                                                    isValid = false;
                                                    cin.clear();
                                                    cin.ignore(1000, '\n');
                                                }
                                                else if (dataUser[indexUser].dataPesanan.deadline.year < 2026)
                                                {
                                                    cout << "Tahun tidak sesuai!" << endl;
                                                    isValid = false;
                                                }
                                                else
                                                {
                                                    isValid = true;
                                                }
                                            } while (!isValid);

                                            do
                                            {
                                                cout << "Budget: ";
                                                cin >> dataUser[indexUser].dataPesanan.budget;
                                                if (cin.fail())
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

                                            dataUser[indexUser].dataPesanan.statusProject = false;
                                            cin.ignore();

                                            cout << "\n========== Data Pesanan Berhasil Dibuat! ==========\n"
                                                 << endl;

                                            dataPesananFreelance[JumlahData] = dataUser[indexUser].dataPesanan;
                                            dataUser[indexUser].JumlahPesananUser += 1;
                                            JumlahData += 1;

                                            cout
                                                << "\n========== Data Pesanan Berhasil Dibuat! ==========\n"
                                                << endl;
                                        }
                                        else
                                        {
                                            cout << "Jumlah Pesanan sudah terlalu banyak!" << endl;
                                        }

                                        break;
                                    case 2:

                                        if (JumlahData == 0 || dataUser[indexUser].JumlahPesananUser == 0)
                                        {
                                            cout << "\nBELUM ADA DATA PESANAN YANG BISA DITAMPILKAN!\n"
                                                 << endl;
                                        }
                                        else
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

                                            string statusPesanan = dataUser[indexUser].dataPesanan.statusProject
                                                                       ? "Sudah Selesai"
                                                                       : "Belum Selesai";

                                            string deadline =
                                                to_string(dataUser[indexUser].dataPesanan.deadline.day) + "-" +
                                                to_string(dataUser[indexUser].dataPesanan.deadline.month) + "-" +
                                                to_string(dataUser[indexUser].dataPesanan.deadline.year);

                                            cout << left
                                                 << setw(5) << "1. "
                                                 << setw(20) << dataUser[indexUser].dataPesanan.namaKlien
                                                 << setw(20) << dataUser[indexUser].dataPesanan.jenisJasa
                                                 << setw(15) << deadline
                                                 << setw(15) << dataUser[indexUser].dataPesanan.budget
                                                 << setw(20) << statusPesanan
                                                 << endl;
                                        }

                                        cout << "============================================================================================================\n"
                                             << endl;

                                        break;

                                    case 3:
                                        isLogin = false;
                                        break;

                                    default:
                                        cin.clear();
                                        cin.ignore(1000, '\n');
                                        break;
                                    }
                                }
                            }
                        }
                        if (loginStatus == false)
                        {
                            percobaan -= 1;
                            cout << "Username dan Password salah, silahkan ulangi proses Input (Sisa percobaan: " << percobaan << ")" << endl;
                        }
                    }

                    break;

                case 3:
                    percobaan = 0;
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