# coding: utf-8

def abc():
    for betu in range(ord('b'), ord('z') + 1, 2):
        print(chr(betu), end=" ")
        

def oszthato7():
    szamlalo = 0
    
    while True:
        szam = int(input('Adj meg egy szamot: '))
        
        if szam == 0:
            break
        elif szam % 7 == 0:
            szamlalo += 1
            
    print('A beolvasott szamok kozul {} volt oszthato 7-el.'.format(szamlalo))
    
def atlag():
    regiszter = {
        "osszeg": 0,
        "szamlalo": 0
    }
    
    while True:
        szam = int(input('Adj meg egy szamot: '))
        
        if szam == 0:
            break
            
        regiszter["osszeg"] += szam
        regiszter["szamlalo"] += 1
        
    print('A beolvasott szamok atlaga {}.'.format(float(regiszter["osszeg"]) / regiszter["szamlalo"]))


def primszam(n):
    if n <= 3:
        return n > 1
    elif n % 2 == 0 or n % 3 == 0:
        return False
    
    i = 5
    
    while i**2 <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i = i + 6
        
    return True

def kiir_primszam():
    for i in range(100):
        if primszam(i):
            print(i, end=' ')

def recur_fibonacci(n):
    if n <= 1:
        return n
    
    return (recur_fibonacci(n - 1) + recur_fibonacci(n - 2))

def fibo():
    ismetlesek = 35
    
    for i in range(ismetlesek):
        print(recur_fibonacci(i), end=' ')

def beolvas():
    n = 0
    while True:
        n = int(input('Add meg hany szamot szeretnel beolvasni: '))

        if n > 0:
            break

        print("Negativ szam.")

    szamlalok = {
        "oszthato8": 0,
        "oszthato9": 0,
        "oszthato11": 0
    }
    
    while n > 0:
        szam = 0

        while True:
            szam = int(input('Add meg egy szamot: '))
            
            if szam > 0:
                break       

            print("Negativ szam.")
        
        if not szam % 8:
            szamlalok["oszthato8"] += 1
        elif not szam % 9:
            szamlalok["oszthato9"] += 1
        elif not szam % 11:
            szamlalok["oszthato11"] += 1
        
        n -= 1
        
    print('A beolvasott szamok kozul {} volt oszthato 8-al, {} volt oszthato 9-el, {} volt oszthato 11-el.'.format(szamlalok["oszthato8"], szamlalok["oszthato9"], szamlalok["oszthato11"]))

def szamtani_kozep(elso, masodik):
    return float(elso + masodik) / 2

def mertani_kozep(elso, masodik):
    return float(elso * masodik)**0.5

def feladat():
    while True:
        elso, masodik = [int(x) for x in input("Adj meg ket szamot: ").split()]
        
        if elso > 0 and masodik > 0:
            break
    
    print('A ket beolvasott termeszetes szam az {} es {} voltak, amelyek szamtani atlaga {} es mertani atlaga {}.'.format(elso, masodik, szamtani_kozep(elso, masodik), mertani_kozep(elso, masodik)))

def main():
    print("Első feladat, Írjuk ki az abc minden második betűit.")
    abc()
    print('\n\nMásodik feladat, Kérjen be 0 végjelig számokat. Írassa ki hány darab számot osztható 7-tel a beolvasott számok között.')
    oszthato7()
    print('\nHarmadik feladat, Kérjen be 0 végjelig számokat. Írassa ki a bekért számok átlagát.')
    atlag()
    print('\nNegyedik feladat, Írjunk programot, amely kiírja 1-től 100-ig a prímszámokat.')
    kiir_primszam()
    print('\n\nÖtödik feladat, Írjunk programot amely kiírja az első 35 fibonacci számot.')
    fibo()
    print('\n\nHatodik feladat, Számoljuk meg, hogy n beolvasott természetes szám közül hány osztható 8-al, hányosztható 9-el, illetve hány osztható 11-el!')
    beolvas()
    print('\nHetedik feladat, Számoljuk meg, két nemnegatív szám mértani és számtani közepét.')
    feladat()


if __name__ == "__main__":
    main()