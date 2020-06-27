# -*- coding: utf-8 -*-

from functools import reduce
from random import randint
from math import sqrt

def feladat1():
    fajl = open('szamok.txt', 'r')       
    szamok = [int(elem) for sor in fajl for elem in sor.split()]
    osszeg = reduce(lambda a, b : a + b, szamok)
    
    print("A fajlban talalhato szamok {}, amelyek atlaga {}.".format(szamok, osszeg / len(szamok)))
    
    fajl.close()

def feladat2():
    inp = open('in.txt', 'r')
    out = open('out.txt', 'w')
    
    for elem in inp:
        for alelem in elem.split():
            out.write('*' * len(alelem))
            out.write(' ')
        out.write('\n')
            
    inp.close()
    out.close()

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

def feladat3():
    prim = open('prim.txt', 'w')
    
    szamok = [randint(1, 100000) for _ in range(2048)]
    
    primek = list(filter(primszam, szamok))
    
    [prim.write(str(primek[szam]) + '\n') for szam in range(0, 15)]
    
    prim.close()

def feladat4():
    inp = open('temp.txt', 'r')
    flag = False
        
    for elem in inp:
        for alelem in elem.split():
            if alelem == 'autó':
                flag = True
                
            if flag:
                break
                
        if flag:
            break
    
    if flag:
        print('Igen')
    else:
        print('Nem')
        
    inp.close()

def feladat5():
    diakok = list()
    
    n = int(input("Add meg hany diakkal dolgoznal: "))
    
    for i in range(n):
        vizsgak = int(input("Add meg az {}. diak vizsgainak szamat: ".format(i + 1)))
        diakok.append({
                       'vizsgak_szama': vizsgak,
                       'jegyek': [int(input("Add meg az {}. diak {}. vizsgajanak jegyet: ".format(i + 1, j + 1))) for j in range(vizsgak)]
                    })

    for d in diakok:
        print('A {}. diak vegso jegye: {}'.format(diakok.index(d) + 1, reduce(lambda a, b : a + b, d['jegyek']) / d['vizsgak_szama']))

def feladat6():
    haromszogek = list()
    n = int(input("Add meg hany haromszoggel dolgozol: "))
    
    for i in range(n):
        haromszogek.append({
                            'befogo': int(input("Add meg az {}. haromszog befogojat: ".format(i + 1))),
                            'atfogo': int(input("Add meg az {}. haromszog atfogojat: ".format(i + 1)))
                           })
        
    for hsz in haromszogek:
        print("Az {}. haromszog terulete = {} es kerulete = {}.".format(
                            haromszogek.index(hsz) + 1, 
                            (hsz['befogo'] * (sqrt(hsz['atfogo']**2 - hsz['befogo']**2))) / 2,
                            (hsz['befogo'] + hsz['atfogo'] + (sqrt(hsz['atfogo']**2 - hsz['befogo']**2)))
        ))

def feladat7():
    sztring = input("Adj meg egy mondatot: ").split()
    
    print('A mondat forditott sorrendben: {}'.format(' '.join(sztring[::-1])))

def main():
	print("1. feladat")
	feladat1()
	print("2. feladat")
	feladat2()
	print("3. feladat")
	feladat3()
	print("4. feladat")
	feladat4()
	print("5. feladat")
	feladat5()
	print("6. feladat")
	feladat6()
	print("7. feladat")
	feladat7()


if __name__ == "__main__":
	main()