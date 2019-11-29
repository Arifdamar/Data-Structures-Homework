/**
* @file Dugum.cpp
* @description Dugum sinifinin metod govdelerinin bulundugu cpp dosyasi
* @course 2. ogretim A grubu
* @assignment 2. odev
* @date 25/11/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

		
		Dugum::Dugum()
		{
			// Dugumun baslangic degerleri atanir
			setEleman(string());
			setIleri(NULL);
			setGeri(NULL);
			setTekrarEdenKonum(0);
			setTekrarliDegerMi(false);
		}
		
		Dugum* Dugum::getIleri()
		{
			return ileri;
		}
		
		void Dugum::setIleri(Dugum* yeniIleri)
		{
			ileri = yeniIleri;
		}
		
		Dugum* Dugum::getGeri()
		{
			return geri;
		}
		
		void Dugum::setGeri(Dugum* yeniGeri)
		{
			geri = yeniGeri;
		}
		
		int Dugum::getTekrarEdenKonum()
		{
			return tekrarEdenKonumu;
		}
		
		void Dugum::setTekrarEdenKonum(int yenitekrarEdenKonumu)
		{
			tekrarEdenKonumu = yenitekrarEdenKonumu;
		}
		
		string Dugum::getEleman()
		{
			return eleman;
		}
		
		void Dugum::setEleman(string yeniEleman)
		{
			eleman = yeniEleman;
		}
		
		bool Dugum::getTekrarliDegerMi()
		{
			return tekrarliDegerMi;
		}
		
		void Dugum::setTekrarliDegerMi(bool yenitekrarliDegerMi)
		{
			tekrarliDegerMi = yenitekrarliDegerMi;
		}
		
		