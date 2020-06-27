# coding: utf-8

from random import randint
from math import floor, sqrt

def check_fibo(szam):
    if szam < 0:
        return False
    
    ideiglenes = sqrt(5 * szam**2 + 4)
    if ideiglenes - floor(ideiglenes) == 0:
        return True
    
    ideiglenes = sqrt(5 * szam**2 - 4)
    if ideiglenes - floor(ideiglenes) == 0:
        return True
    
    return False

def beolvasFibo():
    while True:
        szam = int(input("Adj meg egy szamot: "))
        
        if check_fibo(szam):
            break

def atlag():
    szam = int(input("Adj meg egy szamot: "))
    
    osszeg, szamlalo = 0, 0
    
    while szam > 0:
        osszeg += szam % 10
        szamlalo += 1
        szam //= 10
        
    print("A megadott szam szamjegyeinek osszege {}, {} szamjegybol all, szamjegyeinek atlaga pedig {}.".format(osszeg, szamlalo, float(osszeg) / szamlalo))

def ketto_hatvanya():
    szam = int(input("Adj meg egy szamot: "))
    
    if szam <= 0:
        print("{} nem ketto hatvanya.".format(szam))
    elif szam & szam - 1 == 0:
        print("{} ketto hatvanya.".format(szam))
    else:
        print("{} nem ketto hatvanya.".format(szam))

def mertani_atlag():
    szorzat, szamlalo = 1.0, 0
    
    while True:
        szam = int(input("Adj meg egy szamot: "))
        
        if szam % 2:
            szorzat *= szam
            szamlalo += 1
            
        if szam == 0:
            break
            
    print("A beolvasott paratlan szamok mertani atlaga {}.".format(szorzat**(1 / szamlalo)))

def legnagyobb(a, b, c):
    if a > b:
        if a > c:
            return a
        else:
            return c
    else:
        if b > c:
            return b
        else:
            return c
        
def feladat():
    elso, masodik, harmadik = [int(x) for x in input("Adj meg harom szamot szokozzel elvalasztva: ").split()]
    
    print("A harom szam kozul a legnagyobb a {}.".format(legnagyobb(elso, masodik, harmadik)))

def general_jelszo():
    jelszo = list()
    elfogadhato_spc = ['!', '?', '+', '-', '%', '#', '&', '@']
    
    # hozzaadja a kis-nagy karaktereket, szamokat es egyeb specialis karaktereket
    jelszo.append(chr(randint(ord('A'), ord('Z'))))
    for __ in range(3):
        jelszo.append(chr(randint(ord('0'), ord('9'))))
    for ___ in range(2):
        jelszo.append(elfogadhato_spc[randint(1, 1024) % 8])
    for _____ in range(2):
        jelszo.append(chr(randint(ord('a'), ord('z'))))
        
    # majd osszekeveri
    for i in range(8):
        rand_tmp = (i + randint(1, 1024)) % 8
        rand_tmp_chr = jelszo[i]
        jelszo[i] = jelszo[rand_tmp]
        jelszo[rand_tmp] = rand_tmp_chr
        
    jelszo = ''.join(jelszo)
    print("A generalt jelszo {}".format(jelszo))

def torol5():
    a = [1 , 1 , 2 , 3 , 5 , 8 , 13 , 21 , 34 , 55 , 89]
    
    print("A tomb elemei: {}".format(a))
    
    a = list(filter(lambda elem : elem >= 5, a))
    print("A tomb elemei, a torlesek utan: {}".format(a))



def main():
    print("Első feladat, Olvassunk be számokat egészen addig amig a beolvasott szám nem lesz egy Fibonacci szám.")
    beolvasFibo()
    print("\nMásodik feladat, Írjunk programot, amely egy tetszőleges beolvasot  n​számnak kiszámitja a számjegyeinek az átlagát.")
    atlag()
    print("\nHarmadik feladat, Egy beolvasott ​​n​ számról döntsük el, hogy 2 hatványa-e!")
    ketto_hatvanya()
    print("\nNegyedik feladat, Olvassunk be egész számokat 0 végjelig! Határozzuk meg a beolvasott páratlan számok mérteni középarányosát!")
    mertani_atlag()
    print("\nÖtödik feladat, Hozzál létre egy metódust (függvényt) amely három paramétert vár el és vissza téríti a három paraméter közül a legnagyobbat.")
    feladat()
    print("\nHatodik feladat, Generálj véletlenszerűen egy jelszót amely 8 karaktert tartalmaz és van benne egy nagybetű, két speciális karakter és három szám.")
    general_jelszo()
    print("\nHetedik feladat, Adott a következő tömb a ​=​ [​1​, ​1​, ​2​, ​3​, ​5​, ​8​, ​13​, ​21​, ​34​, ​55​, ​89​] vedd ki belőle az összes számot amely kisebb mint 5.")
    torol5()

if __name__ == "__main__":
    main()