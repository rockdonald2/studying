//
// 1. Feladat forráskódja
//

/*
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 1.
*/

#include <iostream>
#include <vector>
#include <fstream>

void kiralyno(std::vector<int> &megoldas, const int &n, const int &i, std::vector<bool> &oszlop_all, std::vector<bool>
        &foatlo_all, std::vector<bool> &mellekatlo_all, std::ofstream &ki);
static inline bool nem_tamad(const int &n, const int &sor, const int &oszlop, std::vector<bool> &oszlop_all, std::vector<bool>
&foatlo_all, std::vector<bool> &mellekatlo_all);
void kiir(const std::vector<int> &megoldas, const int &n, std::ofstream &ki);

int main() {
    /*
     * ALGORITMUS LEÍRÁSA
     * Be n - beolvassuk a királynők számát
     * Létrehozzuk a megoldást tartalmazó tömböt, ez fogja nyilvántartani, hogy az adott sorszámú királynőt melyik
     * oszlopba helyeztük
     * Létrehozzuk a logikai tömbök, amelyek azt fogják nyilvántartani, hogy helyeztünk-e már el királynők az adott
     * oszlopba, mellékátlón, és főátlon;
     * Lehív kiralyno eljárás, ahol:
     *      - sorban haladva helyezzük el egy adott oszlopba a királynőket;
     *      - amennyiben egy adott oszlopban elhelyezünk egy királynőt, ellenőrízzük a megfelel függvénnyel, hogy nem
     *      támad-e egy már korábbi sorban elhelyezett másik királynőt; az által, hogy megnézi a három logikai tömb
     *      közül valamelyiknek, vagy akár több, a logikai értéke igaz-e. Ha igaz, akkor az adott
     *      oszlopban/mellékátlón/főátlón már van királynő elhelyezve, és ekkor egy másik oszlopot ajánl az adott
     *      sorszámű királynőnek. Amennyiben valamennyi oszlopot ajánlotta már, és egyik sem volt megfelelő (minden
     *      esetben támadott egy már korábban elhelyezett királynőt), visszalépünk, az azt megelőző királynőre, és
     *      annak javasolunk új oszlopot. Minden esetben visszatéréskor "felállítjuk" a királynőt, felszabadítva az
     *      adott oszlopot/mellékátlót/főátlót a logikai tömbök hamis-ra állításával.
     *      - minden esetben a valid megoldásokat kiírjuk egy állományba
     *      - paraméterek:
     *              - vector<int> &megoldás - a megoldást tartalmazó tömb, amelynek sorszáma a királynőt, értéke az
     *              oszlopát jelöli;
     *              - const int &n - hány királynőt kell elhelyeznünk, a folytatási feltétel tesztelésekor szükséges;
     *              - const int &i - éppen hányadik királynőt helyezzük el a sakktáblára;
     *              - vector<bool> ... - a logikai tömbök
     * */

    int n;
    std::cout << "n = ";
    std::cin >> n;

    std::vector<int> megoldas_tomb(n + 1, 0);
    std::vector<bool> oszlop_all(n + 1, false);

    // a lenti logikai tömbök úgy kerülnek ábrázolásra, hogy mellékátló esetében az adott mellékátló a cella
    // sorindexének és oszlopindexének összege;
    //  a főátló esetében a pedig a sorindex - oszlopindex + királnyők száma
    // (+ 1 az index miatt minden esetben)
    std::vector<bool> foatlo_all(2 * n + 1, false);
    std::vector<bool> mellekatlo_all(2 * n + 1, false);

    std::ofstream kimeneti_all("ki_1.txt");

    if (kimeneti_all.is_open()) {
        kiralyno(megoldas_tomb, n, 1, oszlop_all, foatlo_all, mellekatlo_all, kimeneti_all);
    } else {
        std::cout << "Nem sikerult a kimeneti allomany megnyitasa. \nEllenorizd le a kimeneti allomany eleresi utvonalat.\n";
    }

    kimeneti_all.close();

    return 0;
}

void kiralyno(std::vector<int> &megoldas, const int &n, const int &i, std::vector<bool> &oszlop_all, std::vector<bool>
&foatlo_all, std::vector<bool> &mellekatlo_all, std::ofstream &ki) {
    for (int j = 1; j <= n; ++j) {
        // teszteljük, hogy az i. királynő a j. oszlopba helyezhető-e
        if (nem_tamad(n, i, j, oszlop_all, foatlo_all, mellekatlo_all)) {
            // javasoljuk az i. királynőnek a j. oszlopot
            megoldas[i] = j;
            // lefoglaljuk az adott oszlopot, főátlót és mellékátlót
            oszlop_all[j] = true;
            foatlo_all[i - j + n + 1] = true;
            mellekatlo_all[i + j] = true;

            // teszteljük a folytatási feltételt, vagy kiírjuk a végeredményt
            if (i < n) {
                kiralyno(megoldas, n, i + 1, oszlop_all, foatlo_all, mellekatlo_all, ki);
            } else {
                kiir(megoldas, n, ki);
            }

            // kiírás után visszatérünk és felállítjuk az i. királynőt a j. oszlopból,
            // újat javasolva, amennyiben van rendelkezésre álló szabad hátralevő oszlop
            megoldas[i] = 0;
            oszlop_all[j] = false;
            foatlo_all[i - j + n + 1] = false;
            mellekatlo_all[i + j] = false;
        }
    }
}

static inline bool nem_tamad(const int &n, const int &sor, const int &oszlop, std::vector<bool> &oszlop_all,
                             std::vector<bool> &foatlo_all, std::vector<bool> &mellekatlo_all) {
    // igazat térít, amennyiben minden logikai tömb értéke hamis,
    // ami azt jelenti, hogy mind az adott oszlop, főátló és mellékátló is szabad
    return !(oszlop_all[oszlop] || foatlo_all[sor - oszlop + n + 1] || mellekatlo_all[sor + oszlop]);
}

void kiir(const std::vector<int> &megoldas, const int &n, std::ofstream &ki) {
    for (int j = 1; j <= n; ++j) {
        int id = megoldas[j];

        for (int z = 1; z < id; ++z) {
            ki << "0 ";
        }

        ki << "Q ";

        for (int z = id + 1; z <= n; ++z) {
            ki << "0 ";
        }

        ki << '\n';
    }

    ki << '\n';
}