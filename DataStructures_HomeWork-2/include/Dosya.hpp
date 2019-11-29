/**
* @file Dosya.hpp
* @description Dosya sinifi header dosyasi
* @course 2. ogretim A grubu
* @assignment 2. odev
* @date 25/11/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
*/
#ifndef DOSYA_HPP
#define DOSYA_HPP

#include <fstream>
#include "DoublyLinkedList.hpp"

class Dosya
{
	public:
	ifstream file;
	string word;
	
	void DosyaAc(string);
	void ListeyeAktar(DoublyLinkedList*);
};
#endif