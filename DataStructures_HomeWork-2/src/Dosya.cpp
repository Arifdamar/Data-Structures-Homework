/**
* @file Dosya.cpp
* @description Dosya sinifinin metod govdelerinin bulundugu cpp dosyasi
* @course 2. ogretim A grubu
* @assignment 2. odev
* @date 25/11/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
*/
#include "Dosya.hpp"


	void Dosya::DosyaAc(string dosyaYolu)
	{
		// Gonderilen dosya yolu acilir
		file.open(dosyaYolu.c_str());
	}
	
	void Dosya::ListeyeAktar(DoublyLinkedList* Liste)
	{
		if (file.is_open()) // Dosyanin acilip acilmadigi kontrol edilir
		{
			while (file >> word) // Dosyadaki her kelime sirayla word degiskenine atanir
			{
				Liste->add(word); // Her kelime listeye bir dugum icerisinde eklenir
			}
		}
		file.close(); // Dosya kapatilir
	}