#include "pch.h"
#include <iostream>

/*

hogyan is m�k�dik egy funkci� template?
	- a funkci� templateket a compiler direkt m�don nem ford�tja le, hanem
		minden egyes leh�v�s eset�ben replik�lja az adott funkci� a leh�vott t�pussal, majd ezt ford�tja le.
		! ezt a funkci�t amit val�di adatt�pusokkal hozz l�tre function template instance-nek h�vjuk.

*/

/*

Operators, function calls, and function templates,
	template funcki�k b�rmely be�p�tett adatt�pussal, illetve classal m�k�dik, egy ellentmond�ssal.
	- amikor a compiler leford�tja a template instance-t, �gy csin�lja ahogy egy norm�l funkci�t.
	- minden norm�l funkci�ban, b�rmely oper�tor vagy funkci� h�v�s amit a t�pusaiddal haszn�lsz megkell legyen hat�rozva,
		ha nincs compiler error
	- hasonl�an, b�rmely oper�tor vagy funkci� h�v�s a template funkci�dban is musz�j meghat�rozva legyen b�rmely t�pusra
		amelyre a template p�ld�zva lehet

		l�sd pl.-t a classal, ahol musz�j a > oper�tort overloadolni ahhoz, hogy m�k�dj�n.

*/