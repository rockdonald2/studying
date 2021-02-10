from random import randint
from functools import reduce
# coding: utf-8

def elso():
    string = "Alma"
    print(string)

def masodik():
    elsoSzam = int(input("Adj meg egy szamot: "))
    masodikSzam = int(input("Adj meg meg egy szamot: "))
    print("A ket szam osszege, {} + {} = {}".format(elsoSzam, masodikSzam, elsoSzam + masodikSzam))

def harmadik():
    print(list(range(1, 100)))

def negyedik():
    print("Az elso 255 szam osszege: {}".format(reduce(lambda a, b: a + b, range(1, 256))))

def otodik():
    tomb = []

    for _ in range(64):
        tomb.append(randint(1, 1024))

    print("A tomb elemei: {}".format(tomb))

    print("A szamok, amelyek oszthatok 4-el: {}".format(list(filter(lambda a : a % 4 == 0, tomb))))

def hatodik():
    try:
        elsoSzoveg = raw_input("Adj meg egy szovegreszt: ")
        masodikSzoveg = raw_input("Adj meg meg egy szovegreszt: ")
        print('A ket szovegresz osszefuzve: ' + elsoSzoveg + masodikSzoveg)
    except NameError:
        elsoSzoveg = input("Adj meg egy szovegreszt: ")
        masodikSzoveg = input("Adj meg meg egy szovegreszt: ")
        print('A ket szovegresz osszefuzve: {}'.format(elsoSzoveg + masodikSzoveg))

    # python3-al valo futatas eseten
    # python3-ban a raw_input deprecated es nem ajanlott
    # python((2?))-ben pedig, ha nem raw_input-ot hasznalok a beolvasott stringeket function objectnek nezi es nem engedi osszefuzni oket
    # python feladat_Lukacs_Zsolt.py
    # python3 feladat_Lukacs_Zsolt.py - python3-ban a raw_input() nincs definialva, a try-except exception blokkal ezt javitom ki,
    # igy mindegy melyikkel akarom futtatni, a kod lefut

def hetedik():
    tomb = [45,32,54,12,534,'a','b',56,12,'e',53,'gf']

    print("A tomb {} darab szamot tartalmazott.".format(len(list(filter(lambda a : isinstance(a, int), tomb)))))


#elso()
#masodik()
#harmadik()
#negyedik()
#otodik()
#hatodik()
#hetedik()

def main():
    elso()
    masodik()
    harmadik()
    negyedik()
    otodik()
    hatodik()
    hetedik()

if __name__ == "__main__":
    main()
