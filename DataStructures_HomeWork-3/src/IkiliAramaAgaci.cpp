/****************************************************************************
* @file IkiliAramaAgaci.cpp
* @description IkiliAramaAgaci sinifinin metod govdelerinin bulundugu cpp dosyasi
* @course 2. ogretim A grubu
* @assignment 3. odev
* @date 15/12/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yilmaz arif.yilmaz3@ogr.sakarya.edu.tr
*****************************************************************************/
#include "IkiliAramaAgaci.hpp"


		void IkiliAramaAgaci::AraveEkle(Dugum *&alt_Dugum, const int &yeni) // eklenecek eleman icin bos dugum arar, konum belirler, elemani ekler. 
		{				  												
			if(alt_Dugum == NULL) 
			{
				alt_Dugum = new Dugum(yeni,NULL,NULL);
			}  
						
			else if(yeni <= alt_Dugum->deger) // eklenecek eleman bir onceki dugumdeki veriden kucukse veya esitse sola yerlesir, soy sayisina 1 eklenir.
			{	
					AraveEkle(alt_Dugum->sol,yeni); 
					alt_Dugum->soy_sayisi++;
			}
			else if(yeni > alt_Dugum->deger)	// eklenecek eleman bir onceki dugumdeki veriden buyukse saga yerlesir, soy sayisina 1 eklenir.
			{
				AraveEkle(alt_Dugum->sag,yeni);
				alt_Dugum->soy_sayisi++;
			}
			else return;
			
		}		
		bool IkiliAramaAgaci::AraveSil(Dugum *&alt_Dugum,const int &yeni)	
		{		
			if(alt_Dugum == NULL) return false; 
			if(alt_Dugum->deger == yeni)		// silinmek istenen deger ile dugumdeki veri uyuşuyorsa DugumSil fonksiyonu ile dugum silinir.
			{
				return DugumSil(alt_Dugum);
			}
			else if(yeni < alt_Dugum->deger)	// silinmek istenen deger dugumdeki veriden küçük ise sol dügüme gidilerek aynı işlem tekrar yapılır.
			{
					alt_Dugum->soy_sayisi--;	// soy sayisi 1 azaltilarak silinecek olan veri, bulundugumuz düğümün soyundan cikarilmis olur.
				return AraveSil(alt_Dugum->sol,yeni);
			}
			else		// silinmek istenen deger dugumdeki veriden buyuk ise sag dügüme gidilerek aynı işlem tekrar yapılır.
			{
					alt_Dugum->soy_sayisi--;	// soy sayisi 1 azaltilarak silinecek olan veri, bulundugumuz düğümün soyundan cikarilmis olur.
				return AraveSil(alt_Dugum->sag,yeni);
			}
		}
		
		bool IkiliAramaAgaci::DugumSil(Dugum *&alt_Dugum)	// Dugum silme islemi.
		{			
			Dugum *silinecekDugum = alt_Dugum;	
			
			if(alt_Dugum->sag == NULL) alt_Dugum = alt_Dugum->sol;	// Sag cocuk yoktur. Islemler sol cocuk uzerinden devam eder.
			
			else if(alt_Dugum->sol == NULL)alt_Dugum = alt_Dugum->sag;	// Sol cocuk yoktur. Islemler sag cocuk uzerinden devam eder.
			
			else		// Ikı cocuklu olma durumu ve sol cocugun en sagina gidilip dugumun silinmesi.
			{	
				silinecekDugum = alt_Dugum->sol;
				Dugum *ebeveynDugum = alt_Dugum;
				while(silinecekDugum->sag != NULL){		// En sag tarafa gidilir, ebeveyn dugum ve silinecek olan dugum yeni 
					ebeveynDugum=silinecekDugum;		
					silinecekDugum=silinecekDugum->sag;
					ebeveynDugum->soy_sayisi--;				// Ebeveyn dugumun soyundan 1 eksilir. 
				}
				alt_Dugum->deger = silinecekDugum->deger;		// silinecek dugumun verisi islemin basladigi kok'e verilir.
				alt_Dugum->soy_sayisi--;						// Dugum soyundan 1 eksilir.
				if(ebeveynDugum == alt_Dugum) alt_Dugum->sol = silinecekDugum->sol;		// dugumleri baglama islemleri.
				else ebeveynDugum->sag = silinecekDugum->sol;
			}
			delete silinecekDugum;			// yukarıdaki kosullara gore silinmesi gereken dugum silinmis olur.
			return true;
		}
		void IkiliAramaAgaci::Postorder(Dugum *alt_Dugum) {	// Postorder arama isleminin yapilmasi.
			
			if(alt_Dugum != NULL)	// Agacta eleman varsa arama yapilir.
			{
				Postorder(alt_Dugum->sol);		//Once sol cocuk sonra sag cocuk ardindan dugumun kendisi icin ayni fonksiyon özyineli olarak calisir.
				Postorder(alt_Dugum->sag);	
				cout<<"<";				
				cout<<alt_Dugum->deger<<","<<alt_Dugum->soy_sayisi<<"> ";		// Veri ve Soy sayisi yazdirilir.
				ToplamSoy += alt_Dugum->soy_sayisi;		// her bir dugumdeki soy sayisi Toplam sonucu tutan degiskene verilir.
			}
			
		}
		
		int IkiliAramaAgaci::BulKokSoy(Dugum *alt_Dugum)		// Kok verisinin soy sayisini dondurur.
		{
			return alt_Dugum->soy_sayisi;
		}
		int IkiliAramaAgaci::BuyukBul(Dugum *alt_Dugum)	// Agactaki en buyuk deger dondurulur.
		{
			while(alt_Dugum != NULL)	// Surekli sag cocuga gidilerek en buyuk deger bulunur.
			{
				enbuyuk = alt_Dugum->deger; 
				alt_Dugum = alt_Dugum->sag;
			}
		
			return enbuyuk;
		}
		
			IkiliAramaAgaci::IkiliAramaAgaci()	// Kurucu fonksiyon olusturulur. Barindirdigi degiskenlere ilk degerler atanir.
			{	
				ToplamSoy=0;
				enbuyuk=0;
				kok = NULL;
			}
			bool IkiliAramaAgaci::Bosmu() const{  
				return kok == NULL;
			}
			void IkiliAramaAgaci::Ekle(const int &yeni)
			{
				AraveEkle(kok,yeni);
				
			}	
			void IkiliAramaAgaci::Sil(const int &veri)
			{
				if(AraveSil(kok,veri) == false) cout << "Eleman BulunamadI.";
				
			}
			
			void IkiliAramaAgaci::Postorder() 
			{
				Postorder(kok);
			}
		
			void IkiliAramaAgaci::Temizle(){		
				while(!Bosmu()) DugumSil(kok);
			}
		
			int IkiliAramaAgaci::getKokSoy(){			// Agacin kökünün soy sayisini dondurur.
				return BulKokSoy(kok);
			}
			int IkiliAramaAgaci::getToplamSoy(){		// Toplam Soy Sayısını döndürür.
				return ToplamSoy;
			}
			void IkiliAramaAgaci::SifirlaToplamSoy(){	//Toplam Soy sayısının her aramada yeniden sayilmasi icin sıfıra eşitler.
				 ToplamSoy = 0;
			}
			int IkiliAramaAgaci::getKok(){				// Agaç kökünü döndürür.
				return kok->deger;
			}
			int IkiliAramaAgaci::getEnbuyuk(){			// Agacın en büyük degerini döndürür.
				return BuyukBul(kok);
			}
			
			IkiliAramaAgaci::~IkiliAramaAgaci(){		// Yıkıcı metotta temizle fonksiyonu kullanılarak her bir düğüm silinir.
				Temizle();
			}		
