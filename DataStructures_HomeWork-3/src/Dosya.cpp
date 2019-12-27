/****************************************************************************
* @file Dosya.cpp
* @description Dosya sinifinin metod govdelerinin bulundugu cpp dosyasi
* @course 2. ogretim A grubu
* @assignment 3. odev
* @date 15/12/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yilmaz arif.yilmaz3@ogr.sakarya.edu.tr
*****************************************************************************/

#include "Dosya.hpp"


	void Dosya::DosyaAc(string dosyaYolu)	// Parametre olarak alınan dosya yoluyla dosya açma işlemi yapılır.
	{
								
		dosya.open(dosyaYolu.c_str());		
	}
	
	void Dosya::AgacaYolla(IkiliAramaAgaci *Agac)	// Dosyadan okunan sayilari agaca ekleme islemi yapan fonksiyon.
	{
		if (dosya.is_open()) 			// Dosyanın acilip acilmadigi kontrol edilir.
		{
			while (dosya >> sayi) 		// Dosyadaki her sayi sirasiyla "sayi" degiskenine atanir.
			{
				Agac->Ekle(sayi);		// sayi degiskenine atanan her sayi sirasiyla Agac'a bir dugum olarak eklenir.
			}
		}
		dosya.close(); 					// Dosya kapatilir.
	}


