/**
* @file Dugum.hpp
* @description Dugum sinifinin header dosyasi
* @course 2. ogretim A grubu
* @assignment 2. odev
* @date 25/11/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>

using namespace std;

class Dugum
{
	private:
		string eleman;
		int tekrarEdenKonumu;
		bool tekrarliDegerMi;
		Dugum *ileri;
		Dugum *geri;
		
	public:	
	
		Dugum();
		
		Dugum* getIleri();
		void setIleri(Dugum*);
		
		Dugum* getGeri();
		void setGeri(Dugum*);
		
		string getEleman();
		void setEleman(string);
		
		int getTekrarEdenKonum();
		void setTekrarEdenKonum(int);
		
		bool getTekrarliDegerMi();
		void setTekrarliDegerMi(bool);
};
#endif