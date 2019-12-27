/****************************************************************************
* @file Dugum.hpp
* @description Dugum sinifi header dosyasi
* @course 2. ogretim A grubu
* @assignment 3. odev
* @date 15/12/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yilmaz arif.yilmaz3@ogr.sakarya.edu.tr
*****************************************************************************/
#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>

using namespace std;

struct Dugum{
	
	int deger;
	Dugum *sol;
	Dugum *sag;
	int soy_sayisi;
	
	Dugum(const int&,Dugum *,Dugum *);
	
};
#endif