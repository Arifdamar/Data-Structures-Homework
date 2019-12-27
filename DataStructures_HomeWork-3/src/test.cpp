/****************************************************************************
* @file test.cpp
* @description Programın testinin yapıldığı dosya
* @course 2. ogretim A grubu
* @assignment 3. odev
* @date 15/12/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yilmaz arif.yilmaz3@ogr.sakarya.edu.tr
*****************************************************************************/
#include "Dosya.hpp"

int main(){
	
	int benimSkor=0;		// Benim Agacin aldigi skorlari tutar.
	int rakipSkor=0;		// Rakip Agacin aldigi skorlari tutar.
	int Round=0;			// Oynanan Tur sayisini tutar.
	
	IkiliAramaAgaci *benimAgac = new IkiliAramaAgaci();		// benim Agac nesne pointerı olusturulur.
	IkiliAramaAgaci *rakipAgac = new IkiliAramaAgaci();		// rakip Agac nesne pointerı olusturulur.
	
	// Dosya pointer nesneleri olusturulur
	Dosya *benimDosya = new Dosya();
	Dosya *rakipDosya = new Dosya();
	
	// Dosya yolu tanımlamaları yapılır
	string benimdosyaYolu = ".\\doc\\benimDosya.txt";
	string rakipdosyaYolu = ".\\doc\\rakipDosya.txt";
	
	// Dosyalar acilip degerler agaclara eklenir
	benimDosya->DosyaAc(benimdosyaYolu);
	benimDosya->AgacaYolla(benimAgac);
	
	rakipDosya->DosyaAc(rakipdosyaYolu);
	rakipDosya->AgacaYolla(rakipAgac);
	
		
		if(benimAgac->getKokSoy() == rakipAgac->getKokSoy()) // İki dosyada da esit sayi olup olmadigini kontrol eder.
		{
		
	
			while(true){	// Oyun bitene kadar programı devam ettirir.
						benimAgac->SifirlaToplamSoy();
						rakipAgac->SifirlaToplamSoy();
						cout<<"Benim Agac Postorder : "  <<endl;
						benimAgac->Postorder();
						cout<<"\n>> Benim Agac Toplam Soy Sayisi : "<<benimAgac->getToplamSoy()<<"\n----------------------\n"<<endl;
						cout<<"rakip Agac Postorder"  <<endl;
						rakipAgac->Postorder();
						cout<<"\n>> Rakip Agac Toplam Soy Sayisi : "<<rakipAgac->getToplamSoy()<<"\n----------------------"<<endl;
						
				if(benimAgac->getToplamSoy() < rakipAgac->getToplamSoy())	// Toplam soy sayisi az olan Turu kazanir, istenilen algoritmaya göre devam edilir.
				{
					Round++;
					benimSkor++;
					cout << "\n-- TEBRIKLER TURU KAZANDINIZ-- \n"<<"Skor"<<endl;		
					cout << "Benim : "<<benimSkor<<endl;
					cout << "Rakip : "<<rakipSkor<<endl;
					cout << "Tur Sayisi : " << Round <<endl<<endl;
					benimAgac->Ekle(rakipAgac->getEnbuyuk());
					rakipAgac->Sil(rakipAgac->getEnbuyuk());
					rakipAgac->Ekle(benimAgac->getKok());
					benimAgac->Sil(benimAgac->getKok());
				}
				else if(benimAgac->getToplamSoy() > rakipAgac->getToplamSoy()) // Toplam soy sayisi az olan Turu kazanir, istenilen algoritmaya göre devam edilir.
				{
					Round++;
					rakipSkor++;
					
					cout << "\n-- UZGUNUM TURU KAYBETTINIZ-- \n"<<"Skor"<<endl;		
					cout << "Benim : "<<benimSkor<<endl;
					cout << "Rakip : "<<rakipSkor<<endl;
					cout << "Tur Sayisi : " << Round <<endl<<endl;
					
					rakipAgac->Ekle(benimAgac->getEnbuyuk());
					benimAgac->Sil(benimAgac->getEnbuyuk());
					benimAgac->Ekle(rakipAgac->getKok());
					rakipAgac->Sil(rakipAgac->getKok());
				}
				else {		//	Beraberlik durumunda kokler karsilikli olarak birbirlerine verilir, kendilerinden silinir.
					Round++;
					
					cout << "\n-- BERABERE-- \n"<<"Skor"<<endl;		
					cout << "Benim : "<<benimSkor<<endl;
					cout << "Rakip : "<<rakipSkor<<endl;
					cout << "Tur Sayisi : " << Round <<endl<<endl;
					
					rakipAgac->Ekle(benimAgac->getKok());
					benimAgac->Ekle(rakipAgac->getKok());
					rakipAgac->Sil (rakipAgac->getKok());
					benimAgac->Sil (benimAgac->getKok());
				}
				
				if(benimSkor == 5) 	// Kazanılan tur sayisi 5 olan agac oyunu kazanır.
				{		
					cout <<"\n ---- OYUNU Benim Agac KAZANDI ------\n";
					break;
				}
				else if(rakipSkor == 5)
				{
					cout <<"\n ---- OYUNU Rakip Agac KAZANDI ------\n";
					break;
				}
				else if(Round == 20)	// 20 Tur'un sonunda kazanilan tur sayisi çok olan oyunu kazanir, eşitlik durumunda oyun berabere biter.
				{
					if(benimSkor > rakipSkor) cout <<"\n ---- OYUNU Benim Agac KAZANDI ------\n";
					else if(benimSkor < rakipSkor) cout <<"\n ---- OYUNU Rakip Agac KAZANDI ------\n";
					else cout <<"\n ---- OYUN BERABERE ------\n";
					break;
				}
				cout<< "ILERLEMEK ICIN HERHANGI BIR TUSA BASINIZ.";
				system("pause");
			}		
		}
		else
		{
			cout << "\n	   IKI DOSYADA DA ESIT SAYI BULUNMALIDIR..\n";
		}
			
	// Programin sonunda cöp olusmamasi icin olusturulan nesneler silinir.
	delete benimDosya;
	delete benimAgac;
	delete rakipDosya;
	delete rakipAgac;
	
	return 0;
}