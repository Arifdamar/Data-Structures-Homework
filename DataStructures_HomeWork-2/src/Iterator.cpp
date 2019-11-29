/**
* @file Iterator.cpp
* @description Iterator sinifinin metod govdelerinin bulundugu cpp dosyasi
* @course 2. ogretim A grubu
* @assignment 2. odev
* @date 25/11/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
*/
#include "Iterator.hpp"
		
		Iterator::Iterator(Dugum *dugum)
		{
			// Verilen dugumu current ile gosterir
			setCurrent(dugum);
		}
		
		Dugum* Iterator::getCurrent()
		{
			// iteratorun o an bulundugu dugumu dondurur
			return current;
		}
		
		void Iterator::setCurrent(Dugum *newCurrent)
		{
			// current set metodu
			current = newCurrent;
		}
		
		bool Iterator::canMove()
		{
			// Iteratorun hareket edip edemeyecegini dondurur
			return getCurrent() == NULL;
		}
		
		void Iterator::next()
		{
			// Iteratoru bir sonraki dugume goturur
			setCurrent(getCurrent()->getIleri());
		}
		
		const string Iterator::getCurrentEleman()
		{
			// Iteratorun o an gosterdigi dugumun elemanini dondurur
			return getCurrent()->getEleman();
		}