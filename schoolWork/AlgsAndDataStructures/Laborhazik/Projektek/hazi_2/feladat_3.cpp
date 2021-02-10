//
// 3. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 3.
*/

#include <iostream>
#include <string>

static inline bool MAGANHANGZO_E(const char &k) {
    return k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u' || k == 'A' || k == 'E' || k == 'I' || k == 'O' || k == 'U';
}

int maganhangzok_szama(const std::string &str);

int main() {
    /*
     * ALGORITMUS LEÍRÁSA
     *
     * Be str - beolvassuk a karakterláncot, amelyet ellenőríznünk kell
     * Lehív maganhangzok_szama(str) - amely megszámolja a szövegben található magánhangzók számát,
     *      ahol:
     *          - végigmegy a karakterlánc összes karakterjén,
     *              és összeveti a fenti inline bool függvénnyel, amely igazat térít, ha az adott karakter magánhangzó,
     *              növeljük a számlálót, ha igazat térít
     *          - visszatérítjük a számlálót
     * Kiír magánhangzók száma
     * */

    // Be str
    std::string str;
    getline(std::cin, str);

    // Lehív maganhangzok_szama(str)
    // Visszatérés után -> Kiír magánhangzók száma
    std::cout << maganhangzok_szama(str) << std::endl;

    // C++17 MEGOLDÁS
    // std::cout << std::count_if(str.begin(), str.end(), MAGANHANGZO_E) << '\n';

    return 0;
}

int maganhangzok_szama(const std::string &str) {
    int szamlalo = 0;

    for (const auto &it : str) {
        if (MAGANHANGZO_E(it)) szamlalo++;
    }

    return szamlalo;
}