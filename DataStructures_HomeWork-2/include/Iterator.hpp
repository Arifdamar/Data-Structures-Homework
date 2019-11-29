/**
* @file Iterator.hpp
* @description Iterator sinifinin header dosyasi
* @course 2. ogretim A grubu
* @assignment 2. odev
* @date 25/11/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
*/
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Dugum.hpp"

class Iterator
{
	private:
		Dugum *current; // Listede o anki bulunan konumu ifade eder
		
	public:
		
		Iterator(Dugum*);
		
		Dugum* getCurrent();
		
		const string getCurrentEleman();
		
		void setCurrent(Dugum*);
		
		bool canMove();
		
		void next();
		
};
#endif
