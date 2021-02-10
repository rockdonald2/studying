#ifndef TETELEK_TOMB_H
#define TETELEK_TOMB_H

#include <iostream>

using namespace std;

struct IntArray {
    int size = 0;
    int *elements = nullptr;
};

IntArray* Create(int size) {
    auto* p = new IntArray;
    p->size = size;
    p->elements = new int[size];

    for (int i = 0; i < size; ++i) {
        p->elements[i] = 0;
    }

    return p;
}

void Destroy(IntArray* arr) {
    delete[] arr->elements;
    delete arr;
}

int Length(IntArray* arr) {
    return arr->size;
}

int Put(IntArray* arr, int index, int elem) {
    if (index >= Length(arr)) {
        cerr << "Helytelen index\n";
        return INT8_MIN;
    }

    arr->elements[index] = elem;
    return elem;
}

int Get(IntArray* arr, int index) {
    if (index >= Length(arr)) {
        cerr << "Helytelen index\n";
        return INT8_MIN;
    }

    return arr->elements[index];
}

void Print(IntArray* arr) {
    if (Length(arr) > 0) {
        for (int i = 0; i < arr->size; ++i) {
            cout << arr->elements[i] << ' ';
        }

        cout << '\n';
    }
}

IntArray* Fesul(IntArray* arr1, IntArray* arr2) {
    IntArray* osszefesult = Create(Length(arr1) + Length(arr2));

    int i = 0;
    int j = 0;
    int k = 0;
    while (i < Length(arr1) && j < Length(arr2)) {
        if (Get(arr1, i) < Get(arr2, j)) {
            Put(osszefesult, k, Get(arr1, i));
            ++i;
        } else {
            Put(osszefesult, k, Get(arr2, j));
            ++j;
        }

        ++k;
    }

    while (i < Length(arr1)) {
        Put(osszefesult, k, Get(arr1, i));
        ++i;
        ++k;
    }

    while (j < Length(arr2)) {
        Put(osszefesult, k, Get(arr2, j));
        ++j;
        ++k;
    }

    return osszefesult;
}

void Maximum_Kupacol(IntArray *arr, const int &kupac_meret, const int &i) {
    int bal = 2 * i + 1;
    int jobb = 2 * i + 2;

    int max;
    if (bal < kupac_meret && Get(arr, bal) > Get(arr, i)) {
        max = bal;
    } else {
        max = i;
    }

    if (jobb < kupac_meret && Get(arr, jobb) > Get(arr, max)) {
        max = jobb;
    }

    if (max != i) {
        int tmp = Get(arr, i);
        Put(arr, i, Get(arr, max));
        Put(arr, max, tmp);
        Maximum_Kupacol(arr, kupac_meret, max);
    }
}

void Maximum_Kupac_Epit(IntArray *arr) {
    for (int i = Length(arr) / 2 - 1; i >= 0; --i) {
        Maximum_Kupacol(arr, Length(arr), i);
    }
}

IntArray* Rendez(IntArray* arr) {
    Maximum_Kupac_Epit(arr);
    int tmp_size = Length(arr);

    for (int i = Length(arr) - 1; i >= 1; --i) {
        int tmp = Get(arr, 0);
        Put(arr, 0, Get(arr, i));
        Put(arr, i, tmp);
        tmp_size--;
        Maximum_Kupacol(arr, tmp_size, 0);
    }

    return arr;
}

#endif //TETELEK_TOMB_H
