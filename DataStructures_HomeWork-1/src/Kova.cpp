#include "Kova.hpp"
#include "Top.hpp"
#include <windows.h>

HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
	Kova::Kova()
    {
        static int KovaSayac = 0; // Kova sayisini tutmak icin static bir int sayac olusturulup 0'dan baslatilir
        setTop(NULL); // Baslangicta toplar olmadigi icin NULL olarak atanir
		KovaSayac++; // Her kova olusturuldugunda sayac bir artar
		setKovaninSirasi(KovaSayac); // Her kova, olusturuldugu anda sayacin sirasina gore sira degerini alir
        setRenkKodu(getKovaninSirasi()); // Kovanin sirasi degisebilir ancak her kovanin rengi kendine has oldugundan renk kodu ayri olarak saklanir
        
	}
	// Get metodlari tanimlanir
    int Kova::getKovaninSirasi()const{return kovaninSirasi;}
    char Kova::getTopDurumu()const{return TopDurumu;}
    int Kova::getRenkKodu()const{return renkKodu;}
    Top* Kova::getTop()const{return TopAdres;}
	
	// Set metodlari tanimlanir
    void Kova::setKovaninSirasi(int yeniSira){kovaninSirasi = yeniSira;}
    void Kova::setTopDurumu(char durum){TopDurumu = durum;}
	void Kova::setRenkKodu(int kod){renkKodu = kod;}
    void Kova::setTop(Top* adres){TopAdres = adres;}

	// Kova sinifi icin "<<" operatoru overload edilir
	ostream& operator<<(ostream& ekran, Kova& sag)
	{
		// Kovada top yoksa top durumu "-" olarak yazilir, varsa top durumu olarak topun adi yazilir
		sag.getTop() == NULL ? sag.setTopDurumu('-') : sag.setTopDurumu(sag.getTop()->getIsim());
		
        // Genel kova goruntusu yazdirilir
		ekran << sag.getKovaninSirasi() << ". Kova" << endl;
		SetConsoleTextAttribute(h,sag.getRenkKodu()); // Her kovanin kendi rengi ile yazilmasi saglanir
		ekran << "  .|.  " << endl;
		ekran << " .   . " << endl;
		ekran << ".     ." << endl;
		ekran << "#     #" << endl;
		ekran << "#  " << sag.getTopDurumu() << "  #" << endl; // Top durumu alinarak kovanin ortasina yazilir
		ekran << "#     #" << endl;
		ekran << "#######" << endl;
		ekran << "Kova'nin Adresi: " << &sag << endl; // Kovanin adresi alinir
		ekran << "Top'un Adresi: ";
		// Top yok ise NULL yazar, varsa adresini yazar
		sag.getTop()==NULL ? ekran << "NULL" << endl : ekran << sag.getTop() << endl;
        
		return ekran;
	}