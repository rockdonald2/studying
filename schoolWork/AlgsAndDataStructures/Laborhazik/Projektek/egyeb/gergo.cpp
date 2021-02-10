#include <iostream>

void csere(int* a, int* b);
void kiiras(int n, int tomb[]);
void bouble_sort(int n, int tomb[]);
void minimumkivalasztasos_rendezes(int n, int tomb[]);
void beszuro_rendezes(int n, int tomb[]);
void leszamolo_rendezes(int n, int tomb[]);

int main()
{
    int n;
    std::cout << "Hany elem legyen?" << std::endl;
    std::cin >> n;
    int* tomb = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> tomb[i];
    }
    leszamolo_rendezes(n, tomb);
    kiiras(n, tomb);
}

void csere(int* a, int* b)
{
    int seged = *a;
    *a = *b;
    *b = seged;
}

void kiiras(int n, int tomb[]) {
    for (int i = 0; i < n; i++) {
        std::cout << tomb[i];
    }
}

void leszamolo_rendezes(int n, int tomb[]) {
    int k=tomb[0];
    for (int i = 1; i < n; i++) {
        if (tomb[i] > k) k = tomb[i];
    }
    int* seged = new int[k+1];
    for (int i = 1; i <= k; i++) {
        seged[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        std::cout << tomb[i] << ' ';
        seged[tomb[i]]++;
    }
    int q = -1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < seged[i]; j++) {
            q++;
            tomb[q] = i;
        }
    }
}