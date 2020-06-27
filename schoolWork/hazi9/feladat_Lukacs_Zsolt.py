# -*- coding: utf-8 -*-

from random import randint, randrange
from functools import reduce

def feladat1():
    tomb = list()
    paros_elemek = list()
    
    for _ in range(randint(16, 32)):
        tomb.append(randrange(-1, 2, 2) * randint(1, 768))
        
    print("A tomb elemei: {}\n".format(tomb), sep=' ')
    
    for elem in tomb:
        if not elem % 2:
            paros_elemek.append((elem, tomb.index(elem)))
            
    print("A tomb paros elemei es ezek indexei: {}".format(paros_elemek))

def feladat2():
    hossz = int(input("Add meg hany elembol alljon a tomb: "))
    tomb = list()
    
    for it in range(7, hossz * 7 + 7, 7):
        tomb.append(it)
        
    print("A felepitett tomb: {}".format(tomb), sep=' ')

def feladat3():
    hossz = int(input("Add meg hany elemet tartalmazzon a tomb: "))
    a = int(input("Add meg melyik szammal valo oszthatosagot vizsgaljuk: "))
    tomb = list()
    
    for _ in range(hossz):
        tomb.append(randint(1, 1024))
        
    osszeg = reduce(lambda x, y: x + y, list(filter(lambda z : z % a == 0, tomb)))
    
    print("A tomb elemei: {}".format(tomb))
    print("A tomb azon elemeinek az osszege, amelyek oszthatok {}-al = {}".format(a, osszeg))

def feladat4():
    n = int(input("Add meg a matrix sorainak szamat: "))
    m = int(input("Add meg a matrix oszlopainak szamat: "))
    matrix = [[randint(1, 1024) for x in range(m)] for y in range(n)]
            
    print(matrix)

def feladat5():
    matrix = [[randint(1, 16) for x in range(2)] for y in range(2)]
    print("A matrix {}".format(matrix))
    
    determinans = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
    
    if determinans == 0:
        print("Determinans 0")
        return None
            
    adjungalt = [[(-1)**(x + y) * matrix[(x + 1) % 2][(y + 1) % 2] for y in range(2)] for x in range(2)]       
            
    transzponalt = [[adjungalt[y][x] for y in range(2)] for x in range(2)]
    
    inverz = [[(1 / determinans) * transzponalt[x][y] for y in range(2)] for x in range(2)]
    
    print("A matrix inverze {}".format(inverz))

def feladat6():
    matrix1 = [[randint(1, 16) for x in range(2)] for y in range(2)]
    matrix2 = [[randint(1, 16) for x in range(2)] for y in range(2)]
    szorzat = [[0 for _ in range(2)] for __ in range(2)]
    
    print("A ket matrix:\n{}\n{}\n".format(matrix1, matrix2))
            
    for x in range(2):
        for y in range(2):
            for k in range(2):
                szorzat[x][y] += matrix1[x][k] * matrix2[k][y]
                
    print("A ket matrix szorzata: {}".format(szorzat))

def eljaras(szo):
    for _ in range(len(szo)):
        print('*', end='')

def feladat7():
    szoveg = input("Adj meg egy szot: ")
    eljaras(szoveg)

def main():
    print("Feladat 1.")
    feladat1()
    print("Feladat 2.")
    feladat2()
    print("Feladat 3.")
    feladat3()
    print("Feladat 4.")
    feladat4()
    print("Feladat 5.")
    feladat5()
    print("Feladat 6.")
    feladat6()
    print("Feladat 7.")
    feladat7()
    

if __name__ == "__main__":
    main()