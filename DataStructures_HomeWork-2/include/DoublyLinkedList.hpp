/**
* @file DoublyLinkedList.hpp
* @description DoublyLinkedList sinifinin header dosyasi
* @course 2. ogretim A grubu
* @assignment 2. odev
* @date 25/11/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
*/
#ifndef DoublyLinkedList_HPP
#define DoublyLinkedList_HPP

#include "Iterator.hpp"
#include "Dugum.hpp"

class DoublyLinkedList{
	private:
		Dugum *basDugum;
		int size;
		int kazanc;
		
	public:
	
		DoublyLinkedList();
		
		void kazancEkle(int);
		int getKazanc() const;
		
		Dugum* getBasDugum() const;
		void setBasDugum(Dugum*);
		
		void BoyutArttir();
		void BoyutAzalt();
		
		bool isEmpty() const;
		
		int Count() const;
		
		void add(const string);
		
		friend ostream& operator<<(ostream&, DoublyLinkedList&);
		
		void clear();
		
		~DoublyLinkedList();
		
};
#endif