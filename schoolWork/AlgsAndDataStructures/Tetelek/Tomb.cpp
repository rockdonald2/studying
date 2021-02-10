#include <iostream>

using namespace std;

struct IntArray {
    int size;
    int *elements;
};

IntArray* Create(int);
void Destroy(IntArray*);
int Put(IntArray*, int, int);
int Get(IntArray*, int);
int Length(IntArray*);
void Print(IntArray*);

int main() {
    auto* arr = Create(5);
    cout << Length(arr) << '\n';

    Put(arr, 0, 1);
    Put(arr, 3, 3);

    Print(arr);
    Destroy(arr);
    return 0;
}

IntArray* Create(int size) {
    auto* arr = new IntArray;
    arr->size = size;
    arr->elements = new int[size];

    for (int i = 0; i < size; ++i) {
        arr->elements[i] = 0;
    }

    return arr;
}

void Destroy(IntArray* arr) {
    delete[] arr->elements;
    delete arr;
}

int Length(IntArray* arr) {
    return arr->size;
}

void Print(IntArray* arr) {
    for (int i = 0; i < arr->size; ++i) {
        cout << arr->elements[i] << ' ';
    }

    cout << '\n';
}

int Put(IntArray* arr, int index, int elem) {
    if (index >= arr->size) {
        cerr << "Invalid index\n";
        return -1;
    }

    arr->elements[index] = elem;
    return index;
}

int Get(IntArray* arr, int index) {
    if (index >= arr->size) {
        cerr << "Invalid index\n";
        return -1;
    }

    return arr->elements[index];
}