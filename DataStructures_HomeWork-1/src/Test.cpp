/**
* @file G171210009_VeriYapilari_Odev1
* @description Kullanicidan aldigi sayi kadar kova olusturup bu kovalarla top ekleme, 
top silme, kova veya top degistirme, kovalari veya toplari tersten yerlestirme islemlerinin yapildigi program
* @course 2.ogretim A grubu
* @assignment 1
* @date 25.10.2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "KovaKontrol.hpp"
using namespace std;

int main(){
    KovaKontrol islem; // Islemlerin yapilabilmesi icin bir islem nesnesi uretilir
	islem.KovaSayisiGir(); // Kullanicidan kova sayisi alinir
	islem.KovalariOlustur(); // Kovalar olusturulur
    int secim;
    do
    {
        system("CLS"); // Her islemden once ekran temizlenir
        islem.KovalariEkranaYazdir(); // Her secimden sonra kovalar ekrana yazdirilir
		
        cout << "[1] Toplari Yerlestir" << endl;
        cout << "[2] Toplari Yoket" << endl;
        cout << "[3] Kova Degistir" << endl;
        cout << "[4] Top Degistir" << endl;
        cout << "[5] Kovalari Tersten Yerlestir" << endl;
        cout << "[6] Toplari Tersten Yerlestir" << endl;
        cout << "[7] Cikis" << endl;
        cout << ">>";
        cin >> secim; // Kullanicidan secimi alinir
        switch (secim) // Yapilan secime gore islem yapilir
        {
            case 1:
            islem.ToplariYerlestir();
            break;
            case 2:
            islem.ToplariYokEt();
            break;
            case 3:
            islem.KovaDegistir();
            break;
            case 4:
            islem.TopDegistir();
            break;
            case 5:
            islem.KovalariTerstenYerlestir();
            break;
            case 6:
            islem.ToplariTerstenYerlestir();
            break;
            case 7:
            islem.HepsiniYokEt();
            break;
            default:
            cout << "Lutfen gecerli bir secim yapiniz..." << endl;
			system("pause");
            break;
        }
    } while (secim!=7);
	return 0; 
}