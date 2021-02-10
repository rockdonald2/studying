#include <iostream>
#include <vector>
#include <algorithm>

void leszamlalos_rendezes(std::vector<int> &arr, const int &exp);
void radix_rendezes(std::vector<int> &arr);

int main() {
    std::vector<int> arr {329, 457, 657, 839, 436, 720, 355};

    radix_rendezes(arr);

    for (const auto &e : arr) {
        std::cout << e << ' ';
    }

    return 0;
}

void radix_rendezes(std::vector<int> &arr) {
    // a radix sort alapvetően úgy működik, hogy számjegyenként végzünk leszámlálós rendezést, amely stabil
    // a stabil fontos, megkell őrizzük az elemek közötti pozícionális összefűggést

    // tudnunk kell a max elemet a tömbből
    // mert annyiszor kell majd számjegyek szerinti leszámláló rendezést végrehajtani, ahány
    // számjegye van a legnagyobb számnak+-+
    // azért kell dereferencelni, mert a függvény egy iterátort fog visszatéríteni, amely a legnagyobb elemre mutat
    int max = *(std::max_element(arr.begin(), arr.end()));

    // amíg van számjegy, amely szerint tudunk rendezni (a legnagyobb szám szerint)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        leszamlalos_rendezes(arr, exp);
    }
}

void leszamlalos_rendezes(std::vector<int> &arr, const int &exp) {
    // max 10 értéknek számolhatunk gyakoriságot, mindegyiket 0-val inicializáljuk
    std::vector<int> szamlalo(10, 0);
    // ez lesz a kimeneti tömbünk, amelyet átírunk a bemeneti tömbbe
    // ez = a rendezett bemeneti tömbbel a végén
    std::vector<int> kimenet(arr.size());

    // megszámoljuk a gyakoriságokat
    for (const auto &i : arr) {
        szamlalo[(i / exp) % 10]++;
    }

    // kumuláljuk a gyakoriságokat
    for (size_t j = 1; j < szamlalo.size(); ++j) {
        szamlalo[j] += szamlalo[j - 1];
    }

    // itt történik a tényleges rendezés
    // a kumulált érték azt mutatja meg, hogy hová kell helyezni az adott arr[j] érték utolsó előfordulását
    // miután ezt behelyeztük, csökkentjük a kumulált értéket
    // a szamlalo mindig azt az indexet fogja tárolni, ahová az arr[j] elemet helyezni kell a rendezett sorban
    for (int j = arr.size() - 1; j >= 0; --j) {
        kimenet[szamlalo[(arr[j] / exp) % 10] - 1] = arr[j];
        szamlalo[(arr[j] / exp) % 10]--;
    }

    // majd átírjuk a kimeneti tömböt a bemenetibe, hogy helyben dolgozzunk
    for (size_t j = 0; j < kimenet.size(); ++j) {
        arr[j] = kimenet[j];
    }
}