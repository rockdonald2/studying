#include <iostream>
#include "Tomb.h"

using namespace std;

int main() {
    /*IntArray* arr1 = Create(3);
    IntArray* arr2 = Create(3);

    Put(arr1, 0, 1);
    Put(arr1, 1, 2);
    Put(arr1, 2, 3);

    Put(arr2, 0, 4);
    Put(arr2, 1, 5);
    Put(arr2, 2, 6);

    IntArray* tmp = Fesul(arr1, arr2);

    Print(tmp);*/

    IntArray* arr = Create(8);
    Put(arr, 0, 4);
    Put(arr, 1, 6);
    Put(arr, 2, 3);
    Put(arr, 3, 8);
    Put(arr, 4, 1);
    Put(arr, 5, 5);
    Put(arr, 6, 2);
    Put(arr, 7, 7);
    Rendez(arr);

    Print(arr);

    return 0;
}