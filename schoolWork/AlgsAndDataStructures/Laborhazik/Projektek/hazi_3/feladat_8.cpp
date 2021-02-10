//
// 8. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 8.
*/

#include <iostream>
#include <string>
#include <fstream>

using ll = long long;

ll hexa_dec_alakitas(const std::string &szam, const int &hat_szamlalo = 0);
int hexa_dec_megfelelo(const char &jegy);

int main() {
    /* ALGORITMUS LEÍRÁSA
     * Be szam - a vizsgált bemeneti szám beolvasása
     * Lehív hexa_dec_atalakitas(szam), ahol:
     *      - felhasználjuk a következő képletet az átalakításhoz:
     *          x1 * 16^k + x2 * 16^(k - 1) + ... + xn * 16^0 = ...
     *          ha kiemelünk 16-ot:
     *          16 * (x1 * 16^(k - 1) + x2 * 16^(k - 2) + ... + xn-1) + xn = ...
     *          végső soron eljutunk egy olyan sorozathoz, ahol:
     *          16 * (16 * (16 * (... * (x1)) + x2) + x3) + xn-1) + xn = ...
     *          megkapva a lenti rekurzív képletet, amely elvezet a megoldáshoz
     *          ! amit megkell jegyezni, MINDEN EGYES ÚJABB KIEMELÉS EGY ÚJABB ÁLLANDÓT SZABADÍT FEL A 16*-OS SZORZÁS ALÓL
     *          ! ezért vagyok képes ezeket simán hozzáadni
     *      - a rekurzív függvényt addig ismételjük, amíg van számjegyünk, ezt a hat_szamlalo paraméter fogja nyilvántartani,
     *          amely azt fogja nyilvántartani, hogy épp melyik 16^k-s hatványnál járunk, indulva 0-tól,
     *          akkor állva meg, ha már nincs következő hatványnak megfelelő állandónk
     *      - a függvény a 16-os számrendszerbeli jegy átalakításához a hexa_dec_megfelelő függvényt használja, amely
     *          string-et alkalmazva téríti vissza a 10-es számrendszerbeli értékét
     * Kiír 10-es számrendszerben
     * */

    std::ifstream bemeneti_all("be_8.txt");

    std::string szam;
    if (bemeneti_all.is_open()) {
        bemeneti_all >> szam;
    } else {
        std::cout << "Nem sikerult a bemeneti allomany megnyitasa. \nEllenorizd le a bemeneti allomany eleresi utvonalat.\n";
    }

    bemeneti_all.close();

    std::ofstream kimeneti_all("ki_8.txt");

    if (kimeneti_all.is_open()) {
        kimeneti_all << hexa_dec_alakitas(szam);
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    kimeneti_all.close();

    return 0;
}

ll hexa_dec_alakitas(const std::string &szam, const int &hat_szamlalo) {
    // addig folytatjuk a függvényt, amíg van az aktuális hatványnak megfelelő számjegyünk
    if (hat_szamlalo < szam.length()) {
        // alkalmazzuk a fent levezetett képletet
        return 16 * hexa_dec_alakitas(szam, hat_szamlalo + 1) + hexa_dec_megfelelo(szam[szam.length() - hat_szamlalo - 1]);
    } else {
        return 0;
    }
}

// ez a függvény azt a célt szolgálja, hogy gyorsan áttudjuk alakítani az aktuális 16-os számrendszerben
// levő számjegyet 10-es számrendszerbe,
// a string-en belüli indexpozíciója a számjegynek jelenti a 10-es számrendszerbeli értékét
int hexa_dec_megfelelo(const char &jegy) {
    // azért statikus változó, mert nem akarom minden lehíváskor újrafoglalni a változónak a memóriahelyet
    static const std::string hexa_jegyek = "0123456789ABCDEF";

    return hexa_jegyek.find(toupper(jegy));
}