/****************************************************************************
* @file IkiliAramaAgaci.hpp
* @description IkiliAramaAgaci sinifi header dosyasi
* @course 2. ogretim A grubu
* @assignment 3. odev
* @date 15/12/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yilmaz arif.yilmaz3@ogr.sakarya.edu.tr
*****************************************************************************/
#ifndef IKILIARAMAAGACI_HPP
#define IKILIARAMAAGACI_HPP

#include <cmath>
#include  "Dugum.hpp"

class IkiliAramaAgaci{
	private:
			Dugum *kok;	
			int ToplamSoy;	
			int enbuyuk;
			void AraveEkle(Dugum *&, const int &);	
			bool AraveSil(Dugum *&,const int &);
			bool DugumSil(Dugum *&);
			void Postorder(Dugum *); 
			int BuyukBul(Dugum *);
			int BulKokSoy(Dugum *);
	public:
			IkiliAramaAgaci();
			bool Bosmu() const;
			void Ekle(const int &);
			void Sil(const int &); 
			void Postorder() ;
			void Temizle();
			int getKokSoy();	
			int getToplamSoy();
			void SifirlaToplamSoy();
			int getKok();	  
			int getEnbuyuk(); 
			~IkiliAramaAgaci();		
};
#endif