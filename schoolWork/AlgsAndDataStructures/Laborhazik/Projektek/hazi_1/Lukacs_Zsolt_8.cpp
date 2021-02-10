#include <array>
#include <iostream>
#include <string>
#include <vector>

/* 
Hallgató neve: Lukács Zsolt
Csoport: 1. csoport
Feladat sorszáma: 8.
*/
int szokoevek_szama(const int &kezdes, const int &vegzes) {
    int szamlalo = 0;
    int iterator = 1;

    // alapvető logika az algoritmus során, hogy megkeressük a kezdő dátum utáni első szőkőévet,
    // utána már csak 4-esével kell haladnunk

    int idg = kezdes;

    while (idg <= vegzes) {
        if ((!(idg % 4) && (idg % 100)) || !(idg % 400)) {
            szamlalo += 1;
            iterator == 1 ? iterator = 4 : NULL;
        }

        idg += iterator;
    }

    return szamlalo;
}

std::vector<int> elvalaszt_datum(std::string datum, const std::string &elvalaszto) {
    std::vector<int> elemek;

    // felbontja az adott datumot az elvalaszto szerinti megfelelo tagolassal
    size_t poz = 0;
    // amig az elvalaszto megtalalhato a datumban, futtassa le a kodreszletet
    while ((poz = datum.find(elvalaszto)) != std::string::npos) {
        // a datum eleje es az elvalaszto kozott reszt szamkent, adja hozza a tombhoz
        elemek.push_back(std::stoi(datum.substr(0, poz)));
        // torolje ki a hozzaadott reszt, az elvalasztoval egyutt
        datum.erase(0, poz + elvalaszto.length());
    }
    // az utolso resz nem kerult hozzaadasra, most adjuk hozza
    elemek.push_back(std::stoi(datum));

    return elemek;
}

int elt_napok(const std::string &szuletesi_datum, const std::string &mai_datum) {
    // kesobbi hasznalatra tudnunk kell hany nap van egy adott honapban, februar mindig 28 lesz, szokoevekkel kesobb foglalkozunk
    const std::array<int, 12> honap_napjai{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    std::string elvalaszto = ".";
    auto szuletesi_datum_elemek = elvalaszt_datum(szuletesi_datum, elvalaszto);
    auto mai_datum_elemek = elvalaszt_datum(mai_datum, elvalaszto);

    // ha a dátum nem megfelelő formátumban volt
    if (szuletesi_datum_elemek.size() != 3 || mai_datum_elemek.size() != 3) {
        std::cout << "A datum nem megfelelo formatumban volt megadva\n";
        return -1;
    }

    // lementjuk szamkent a datum egyes elemeit
    std::array<int, 2> evek{mai_datum_elemek[0], szuletesi_datum_elemek[0]};
    std::array<int, 2> honapok{mai_datum_elemek[1], szuletesi_datum_elemek[1]};
    std::array<int, 2> napok{mai_datum_elemek[2], szuletesi_datum_elemek[2]};

    // ha a felhasznalo korabbi datumot adott meg maikent, mint a szuletesi datum, az hiba
    if (evek[0] < evek[1]) {
        std::cout << "Mai datum nem lehet kisebb a szuletesi datumnal\n";
        return -1;
    }

    // kiszamoljuk az evkulonbseget
    int ev_kulonbseg = evek[0] - evek[1];

    // kiszámoljuk a leélt szökőnapokat
    int elt_szoko_napok = szokoevek_szama(evek[1], evek[0]);

    // amennyiben szökőév a születési év, de nem élt a szökőnapokra, ezt leírjuk
    if (honapok[1] > 2 && szokoevek_szama(evek[1], evek[1])) {
        elt_szoko_napok -= 1;
    }

    // amennyiben szökőév a mai dátum éve, de még nem volt a szökőnap, vagy a mai dátum pont szökőnap, akkor ezt levonjuk
    if ((honapok[0] <= 2 && szokoevek_szama(evek[0], evek[0]))) {
        elt_szoko_napok -= 1;
    }

    int honap_kulonbseg;
    if (honapok[0] == honapok[1] && napok[0] > napok[1]) {
        // kivételes eset az, amikor a hónapok megegyeznek, azonban a születési nap, kisebb, mint a mai dátum
        // ebben az esetben a programunk korai véget ér
        // tehát, leéltünk egy fix évet, ami a két év különbsége, plusz a pár napot az adott hónapban,
        // beleszámolva a születési és elhalálozási napot is,
        // plusz a szökőnapok a két év között
        int elt_napok = ev_kulonbseg * 365 + (napok[0] - napok[1]) + 1 + elt_szoko_napok;

        return elt_napok;
    }
        // ha a születési dátum hónapja, nagyobb, mint a mai dátum hónapja
        // azért kell a -1, mert a születési hónap ebbe a különbség nem számolódik bele, csakis az élt teljes hónapok
    else if (honapok[1] >= honapok[0]) {
        ev_kulonbseg -= 1;
        honap_kulonbseg = 12 - (honapok[1] - honapok[0]) - 1;
    } else {
        honap_kulonbseg = honapok[0] - honapok[1] - 1;
    }

    // azon napok, amelyeket az első honapban élt le, +1 azért kell, mert másképp a születési nap nem számolódna bele
    int le_elt_elso_napok = honap_napjai[honapok[1] - 1] - napok[1] + 1;

    // átalakítjuk a hónapkülönbséget napokká,
    // kezdve a születési hónap utáni hónappal,
    // végezve a mai hónap előttivel
    int honap_nappa = 0;
    if (honap_kulonbseg > 0) {
        for (unsigned int i = 0; i < honap_kulonbseg; i++) {
            honap_nappa += honap_napjai[(honapok[1] + i) % honap_napjai.size()];
        }
    }

    // a leélt napok száma megegyezik a teljesen leélt évek napjainak számával,
    // az első hónapban leélt napokkal, a teljes hónapok napjainak számával,
    // az élt szökőnapok számával,
    // az utolsó hónapban leélt napok számával
    int elt_napok = ev_kulonbseg * 365 + le_elt_elso_napok + honap_nappa + elt_szoko_napok + napok[0];

    return elt_napok;
}

void hany_napot_eltunk() {
    /*
     * A tényleges függvény, amely kiszámolja az élt napok számát, az 'elt_napok' függvény.
     * Azért volt szükség a szétválasztásra, mert ilyen formában működik a teszt függvény.
     * Alapvető logika az élt napok kiszámolásához,
     * az, hogy:
     *  Elsőként évkülönbséget számolunk.
     *  Majd, kiszámoljuk az élt szökőnapokat a két dátum között.
     *  Amennyiben valaki szökőévben született, de nem élt a szökőnapkor, ezt levonjuk.
     *  Amennyiben szökőév van, de még nem volt a szökőnap, ezt is levonjuk.
     *  Kiszámoljuk a hónapkülönbséget.
     *      Ebben az esetben megjelenik egy kivétel. Amennyiben a két dátum között egy fix évkülönbség, plusz néhány
     *      napnyi különbség van (pl. 1992.10.05 és 2020.10.10), akkor az élt napok egy (2020-1992) * 365 + (10 - 05 + 1) + szökőnapok.
     *      A +1 a születési nap beleszámolásához szükséges.
     *  Amennyiben, az évkülönbség nem megfelelő, mert a folyó évben a születési dátum még nem járt le, abban az esetben,
     *      csökkentjük azt, ebben az esetben a hónapkülönbség az a maradék hónap lesz, ami az év teljesítéséhez kellett volna.
     *  Kiszámoljuk azon napokat, amelyek az egyén életének első havában leélt.
     *  Átalakítjuk a hónapkülönbséget napokká.
     *  Majd kiszámoljuk a ténylegesen élt napokat:
     *      teljes évek * 365 + leélt első napok, az első hónapban + átalakított hónapkülönbség + szökőnapok + a folyó év utolsó havában leélt napok.
     * */

    std::string szuletesi_datum;
    std::cout << "elso = ";
    std::cin >> szuletesi_datum;

    std::string mai_datum;
    std::cout << "masodik = ";
    std::cin >> mai_datum;

    std::cout << elt_napok(szuletesi_datum, mai_datum) << " nap\n";
}

void teszt() {
    int start_datum = 1890;
    int start_napszam = 47720;
    std::array<int, 12> honap_napjai{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const std::string mai_datum = "2020.08.26";

    while (start_datum < 2020) {
        if (szokoevek_szama(start_datum, start_datum)) {
            honap_napjai[1] = 29;
        } else {
            honap_napjai[1] = 28;
        }

        for (unsigned int i = 0; i < 12; i++) {
            const unsigned int max_nap = honap_napjai[i];

            for (unsigned int j = 1; j <= max_nap; j++) {
                std::string datum = std::to_string(start_datum) + "." + std::to_string(i + 1) + "." + std::to_string(j);

                int napok = elt_napok(datum, mai_datum);
                if (start_napszam != napok) {
                    std::cout << "hiba: " << datum << " " << napok << "\n";
                    return;
                }

                start_napszam--;
            }
        }

        start_datum++;
    }
}

int main() {
    hany_napot_eltunk();
    //teszt();

    return 0;
}