#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <cmath>
#include "struct.h"
using namespace std;

int binarySearch(Freelance *dataPesanan, int &jumlahData, int target)
{
    int low = 0;
    int high = jumlahData - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if ((dataPesanan + mid)->budget == target)
        {
            return mid;
        }
        else if ((dataPesanan + mid)->budget < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int jumpSearch(Freelance *dataPesanan, string target, int n)
{

    int step = sqrt(n - 1);
    int prev = 0;

    while ((dataPesanan + (min(step, n) - 1))->namaKlien > target)
    {
        prev = step;
        step += sqrt(n);
        if (prev == n)
            return -1;
    }

    while ((dataPesanan + prev)->namaKlien > target)
    {
        prev++;

        if (prev == min(step, n))
            return -1;
    }

    if ((dataPesanan + prev)->namaKlien == target)
        return prev;
    return -1;
}

#endif