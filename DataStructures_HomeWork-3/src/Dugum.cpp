/****************************************************************************
* @file Dugum.cpp
* @description Dugum sinifinin metod govdelerinin bulundugu cpp dosyasi
* @course 2. ogretim A grubu
* @assignment 3. odev
* @date 15/12/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yilmaz arif.yilmaz3@ogr.sakarya.edu.tr
*****************************************************************************/
#include "Dugum.hpp"


	Dugum::Dugum(const int& dgr,Dugum *sl=NULL,Dugum *sg=NULL) // Dugumun baslangic degerleri atanir.
	{
		deger=dgr;
		sol=sl;
		sag=sg;
		soy_sayisi=0;
	}