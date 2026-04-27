#ifndef SORT_H
#define SORT_H

#include <iostream>
#include "struct.h"
using namespace std;

void bubbleSort(Freelance dataPesanan[], int n)
{
    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (dataPesanan[j].namaKlien < dataPesanan[j + 1].namaKlien)
            {

                swap(dataPesanan[j], dataPesanan[j + 1]);
                swapped = true;
            }
        }

        if (swapped = false)
            break;
    }
}

void quickSort(Freelance dataPesanan[], int low, int high)
{
    // Base case: jika pointer low melewati high, berhenti
    if (low >= high)
        return;
    // Menentukan data tengah sebagai pivot (Strategi yang lebih stabil)
    int mid = low + (high - low) / 2;
    int pivot = dataPesanan[mid].budget;
    int i = low, j = high;
    // Proses Partisi
    while (i <= j)
    {
        // Cari elemen di kiri yang seharusnya di kanan pivot
        while (dataPesanan[i].budget < pivot)
        {
            i++;
        }
        // Cari elemen di kanan yang seharusnya di kiri pivot
        while (dataPesanan[j].budget > pivot)
        {
            j--;
        }
        // Tukar elemen jika ditemukan posisi yang salah
        if (i <= j)
        {
            swap(dataPesanan[i], dataPesanan[j]);
            i++;
            j--;
        }
    }

    // Rekursi untuk sub-dataPesananay bagian kiri (dari low sampai j)
    if (low < j)
    {

        quickSort(dataPesanan, low, j);
    }
    // Rekursi untuk sub-dataPesananay bagian kanan (dari i sampai high)
    if (i < high)
    {
        quickSort(dataPesanan, i, high);
    }
}

void selectionSort(Freelance arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        int indeksMin = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].deadline.year < arr[indeksMin].deadline.year)
            {
                indeksMin = j;
            }
            else if (arr[j].deadline.year == arr[indeksMin].deadline.year)
            {
                if (arr[j].deadline.month < arr[indeksMin].deadline.month)
                {
                    indeksMin = j;
                }
                else if (arr[j].deadline.month == arr[indeksMin].deadline.month)
                {
                    if (arr[j].deadline.day < arr[indeksMin].deadline.day)
                    {
                        indeksMin = j;
                    }
                }
            }
        }

        if (indeksMin != i)
        {
            swap(arr[i], arr[indeksMin]);
        }
    }
}

#endif