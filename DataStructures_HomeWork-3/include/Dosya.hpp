/****************************************************************************
* @file Dosya.hpp
* @description Dosya sinifi header dosyasi
* @course 2. ogretim A grubu
* @assignment 3. odev
* @date 15/12/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yilmaz arif.yilmaz3@ogr.sakarya.edu.tr
*****************************************************************************/
#ifndef DOSYA_HPP
#define DOSYA_HPP

#include <fstream>

#include "IkiliAramaAgaci.hpp"

class Dosya
{
	public:
	ifstream dosya;
	int sayi;
	
	void DosyaAc(string);
	void AgacaYolla(IkiliAramaAgaci *);
	
};
#endif