//
// 2. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 2.
*/

#include <iostream>
#include <vector>
#include <fstream>

using ll = long long;

const static std::vector<char> lehetseges_muveletek {'+', '-', '*', '/'};
ll elvegez_muvelet(const ll &a, const ll &b, const char &muvelet);

void osszegek(const std::vector<ll> &szamok, const int &i, const ll &k, std::vector<char>
        &muveletek, std::ofstream &ki, int &megoldasok_szama);
void kiir(const std::vector<ll> &szamok, const std::vector<char> &muveletek, const ll &k, std::ofstream &ki);

bool ellenoriz(const std::vector<ll> &szamok, const std::vector<char> &muveletek, const ll &k);

int main() {
    /*
     * ALGORITMUS LEÍRÁSA
     * Be n, szamok(n), K - beolvassuk, hogy hány számmal dolgozunk, beolvassuk az egész számokat, és beolvassuk az
     * összeget, amit vizsgálunk,
     * Létrehozzuk az n - 1 műveletet tartalmazó segédtömböt,
     * Létrehozzuk a megoldasok számát tároló segédváltozót, ez abban az esetben lesz szükséges, amikor az algoritmus
     * végrehajtása során nem találunk valid megoldást,
     * Lehív osszegek eljárás, ahol:
     *     - sorban haladva helyezzük el a műveletek a számok közé,
     *     - addig helyezünk el egy újabb műveletet, amíg van szabad helyünk,
     *     - miután a teljes kifejezésben elhelyezésre kerültek a műveleti jelek, leellenőrízzük az összeg teljesülését,
     *          amely akkor nem teljesül, ha nem egyezik meg az összeg K-val, vagy ha valamelyik lépésben a kifejezés
     *          nem egész szám.
     *     - amennyiben nem teljesül az i. műveleti jel helyére egy újabb műveleti jelet javasolunk, amennyiben van,
     *     ha nincs akkor visszalépünk az i-1. jelre és annak javasolunk újat, egész addig amíg nem marad szabad
     *     helyünk, és rendelkezésre álló műveleti jelünk.
     *     - amennyiben teljesül kiírjuk a megoldást és növeljük a megoldás számlálót
     *     - amennyiben visszatérés után észrevesszük, hogy egyetlen megoldást sem talált az algoritmus, kiírjuk a
     *     megfelelő üzenetet
     *     - paraméterek:
     *              - const vector<ll> &szamok - az egész számokat tartalmazó tömb, amelyek közé műveleteket kell
     *              elhelyeznünk,
     *              - const int &i - melyik sorszámű műveletet helyezzük el,
     *              - const ll &k - a végső eredmény, melynek teljesülését vizsgáljuk,
     *              - vector<char> &muveletek - a műveleteket tároló segédtömb,
     *              - int &megoldasok_szama - a segédváltozó, amely nyilvántartja a megoldások darabszámát
     * */

    int n;
    std::cout << "n = ";
    std::cin >> n;

    std::vector<ll> szamok(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> szamok[i];
    }

    ll osszeg;
    std::cout << "K = ";
    std::cin >> osszeg;

    std::vector<char> muveletek(n - 1, ' ');

    std::ofstream kimeneti_all("ki_2.txt");

    int megoldasok_szama = 0;

    if (kimeneti_all.is_open()) {
        osszegek(szamok, 0, osszeg, muveletek, kimeneti_all, megoldasok_szama);
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    if (!megoldasok_szama) {
        kimeneti_all << "Nincs megoldas\n";
    }

    kimeneti_all.close();

    return 0;
}

ll elvegez_muvelet(const ll &a, const ll &b, const char &muvelet) {
    // ez a függvény elvégzi, majd visszatéríti a karakterként tárolt műveletet a két egész szám között
    switch (muvelet) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;

        default:
            return 0;
    }
}

void osszegek(const std::vector<ll> &szamok, const int &i, const ll &k, std::vector<char>
&muveletek, std::ofstream &ki, int &megoldasok_szama) {
    for (const auto &m : lehetseges_muveletek) {
        // javasoljuk az m műveletet az i. helyre
        muveletek[i] = m;

        // amennyiben van még szabad hely előtte, javasolunk oda is, így lesz teljes a kifejezés kiértékelés előtt
        if (i < (muveletek.size() - 1)) {
            osszegek(szamok, i + 1, k, muveletek, ki, megoldasok_szama);
        } else {
            // kiértékeljük a kifejezést, melyet csak akkor fogadunk el, ha a kifejezés kiértékelése megegyezik K-val,
            // és minden lépésben a kifejezés értéke egész szám volt
            if (ellenoriz(szamok, muveletek, k)) {
                megoldasok_szama++;
                kiir(szamok, muveletek, k, ki);
            }
        }
    }
}

void kiir(const std::vector<ll> &szamok, const std::vector<char> &muveletek, const ll &k, std::ofstream &ki) {
    ki << k << " = ";

    for (int i = 0; i < (szamok.size() - 1); ++i) {
        ki << szamok[i] << " " << muveletek[i] << " ";
    }

    ki << szamok[szamok.size() - 1] << '\n';
}

bool ellenoriz(const std::vector<ll> &szamok, const std::vector<char> &muveletek, const ll &k) {
    // az első helytől kezdve elvégzi a kijelölt műveleteket az azt megelőző kiértékelt érték és j + 1 sorszámú számok között

    int osszeg = szamok[0];

    for (int j = 0; j < muveletek.size(); ++j) {
        // ha az adott kifejezés értéke az adott lépésben nem lenne egész érték, a kifejezés nem megfelelő
        if (muveletek[j] == '/' && osszeg % szamok[j + 1]) {
            return false;
        }

        // elvégezzük a kijelölt műveletet az azt megelőző kiértékelt érték és j + 1 számok között
        osszeg = elvegez_muvelet(osszeg, szamok[j + 1], muveletek[j]);
    }

    // ha az összeg megfelelő térítjük az igaz-at, különben hamis-at
    return osszeg == k;
}