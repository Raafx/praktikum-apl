#ifndef STRUCT_H
#define STRUCT_H
#include <iostream>
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

Freelance dataPesananFreelance[10];
User dataUser[10];
int kapasitasData = sizeof(dataPesananFreelance) / sizeof(dataPesananFreelance[0]);

#endif