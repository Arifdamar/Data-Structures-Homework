/**
* @file test.cpp
* @description Programin testinin yapildigi dosya
* @course 2. ogretim A grubu
* @assignment 2. odev
* @date 25/11/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
*/
#include "Dosya.hpp"

int main()
{
	DoublyLinkedList *metin = new DoublyLinkedList(); // Yeni bir liste olusturulur
	Dosya *DosyaIslem = new Dosya();
	
	string dosyaYolu = ".\\doc\\text.txt";
	
	DosyaIslem->DosyaAc(dosyaYolu);
	
	DosyaIslem->ListeyeAktar(metin);
	
	cout << *metin << endl;
	
	delete DosyaIslem;
	delete metin;
	system("pause");
	return 0;
}