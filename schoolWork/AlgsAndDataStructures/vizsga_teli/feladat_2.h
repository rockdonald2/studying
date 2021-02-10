#ifndef VIZSGA_TELI_FELADAT_2_H
#define VIZSGA_TELI_FELADAT_2_H

#include <iostream>
#include <vector>

struct Halmaz {
    const int MAX_HOSSZ = 256; // max hossz, hogy ne tudjunk többet behelyezni
    std::vector<int> elemek; // vektorban tárolt halmaz
    int db = 0; // vektor aktuális hossza
};

//Letrehozas
Halmaz* Create();  /// Ures halmazt hoz letre
void Destroy(Halmaz*);  /// Felszabaditja a halmaz helyet

//Elemek hozzaadasa es kivetele
void AddElement(Halmaz*, int);
void RemoveElement(Halmaz*, int);

//Ellenorzesek, visszaretitesi ertek 0 (hamis) vagy 1 (igaz)
int IsElement(Halmaz*, int);   /// Eleme-e a szam a halmaznak
int IsSubset(Halmaz*, Halmaz*);  /// Reszhalmaza-e a masodik halmaz az elsonek
int IsEmpty(Halmaz*);

//Halmazmuveletek - az eredmeny egy halmaz
Halmaz* Egyesit(Halmaz*, Halmaz*);
Halmaz* Metsz(Halmaz*, Halmaz*);
Halmaz* Kivon(Halmaz*, Halmaz*);

//Kiirja a halmaz elemeit
void PrintH(Halmaz*);

Halmaz* Create() {
    auto *p = new Halmaz;
    // létrehozza az új halmaz mutatót, amit térít, ezzel érjük el a halmazunk mezőit
    return p;
}

void Destroy(Halmaz* h) {
    delete h;
    // törli a halmaz mezőit
}

int IsEmpty(Halmaz *h) {
    return h->db == 0;
    // igazat térít, ha üres, tehát a hossza 0
}

int IsElement(Halmaz* h, int elem) {
    if (!IsEmpty(h)) {
        for (const auto &e : h->elemek) {
            if (e == elem) {
                return 1;
                // ha az elem bejáráskor megtalált, akkor igazat térít
            }
        }

        // ide akkor érünk el, ha a keresett elem nem volt megtalálható a halmazunkban
        return 0;
    } else {
        std::cerr << "A halmaz ures\n";
        return 0;
    }
}

int IsSubset(Halmaz *h1, Halmaz *h2) {
    // megkeresi a h2 első elemének indexét, s utána sorra növeli a j számlálót 1-el, amennyiben egyezik a két halmaz
    // bármely lépésben, ha az aktuális j és i elem nem egyezik, a j-t nullázza

    int i = 0;
    int j = 0;

    while (i < h1->db && j < h2->db) {
        if (h1->elemek[i] == h2->elemek[j]) {
            ++j;
        } else {
            j = 0;
        }

        ++i;
    }

    // akkor került megtalálásra a teljes h2 halmaz a h1-ben, ha a j számláló a h2 hosszával egyezik meg
    // tehát, minden elemet egy folytonos tömbszakaszban megtaláltunk
    return j == h2->db;
}

void AddElement(Halmaz *h, int elem) {
    if (h->db < h->MAX_HOSSZ) {
        // hozzáad egy új elemet és növeli a hosszát
       if (!IsElement(h, elem)) {
           h->elemek.push_back(elem);
           h->db++;
       } else {
           std::cerr << "Mar megtalalhato a " << elem << " a halmazban\n";
       }
    } else {
        std::cerr << "A halmaz megtelt\n";
    }
}

void RemoveElement(Halmaz *h, int elem) {
    if (!IsEmpty(h)) {
        if (IsElement(h, elem)) {
            int k = 0;

            // kiválogatás helyben, a hely megőrzésével, stabilan
            for (int i = 0; i < h->db; ++i) {
                if (h->elemek[i] != elem) {
                    h->elemek[k] = h->elemek[i];
                    ++k;
                }
            }

            // töröljük az utolsó elemet, s csökkentjük a hosszát a halmazunknak
            h->elemek.pop_back();
            h->db--;
        } else {
            std::cerr << "Nem talalhato meg a halmazban\n";
        }
    } else {
        std::cerr << "A halmaz ures\n";
    }
}

void PrintH(Halmaz *h) {
    if (!IsEmpty(h)) {
        for (const auto &e : h->elemek) {
            std::cout << e << ' ';
        }

        std::cout << '\n';
    } else {
        std::cerr << "A halmaz ures\n";
    }
}

Halmaz* Egyesit(Halmaz* h1, Halmaz* h2) {
    // egyesítés prog. tétel

    // belemásoljuk az első halmazt az eredménybe, majd a h2 elemeit, amely a h1-ben nem volt megtalálható az
    // eredménybe rakjuk
    auto *eredmeny = Create();

    eredmeny->elemek = h1->elemek;
    eredmeny->db = h1->db;

    for (const auto &e : h2->elemek) {
        if (!IsElement(h1, e)) {
            AddElement(eredmeny, e);
        }
    }

    return eredmeny;
}

Halmaz* Metsz(Halmaz* h1, Halmaz* h2) {
    auto *eredmeny = Create();

    // a közös elemeket helyezi az eredményhalmazba

    for (int i = 0; i < h1->db; ++i) {
        if (IsElement(h2, h1->elemek[i])) {
            AddElement(eredmeny, h1->elemek[i]);
        }
    }

    return eredmeny;
}

Halmaz* Kivon(Halmaz* h1, Halmaz* h2) {
    auto *eredmeny = Create();

    // a különböző elemeket helyezi az eredményhalmazba

    for (int i = 0; i < h1->db; ++i) {
        if (!IsElement(h2, h1->elemek[i])) {
            AddElement(eredmeny, h1->elemek[i]);
        }
    }

    return eredmeny;
}

#endif //VIZSGA_TELI_FELADAT_2_H
