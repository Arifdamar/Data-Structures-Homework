#include <windows.h>
#include <ctime>
#include "KovaKontrol.hpp"
using namespace std;

HANDLE hh = GetStdHandle( STD_OUTPUT_HANDLE );

	void KovaKontrol::KovaSayisiGir()
	{
		// Programin baslangicinda kullanicidan kova sayisi alinir
		cout << "Kova Sayisi: ";
		cin >> kovaSayisi;
	}
	
	void KovaKontrol::KovalariOlustur()
	{
		// Kullanicinin istedigi kova sayisi kadar bellekte arka arkaya dizili bir bolge ayrilir
		// ve kovalar bu bolgenin basini gosterir
		kovalar = (Kova**)malloc(sizeof(Kova)*kovaSayisi); 
		
		for(int i=0; i<kovaSayisi ; i++)
		{
			// Kovalar heap bellek bolgesinde olusturulup, kovalar dizisinin pointerlari tarafindan gosterilmesi saglanir
			kovalar[i] = new Kova();
		}
	}
	
	void KovaKontrol::KovalariEkranaYazdir()
	{
		for(int i = 0; i < kovaSayisi ; i++) // Kovalar ekrana basilir
        { 	
			SetConsoleTextAttribute(hh,15); // Konsolun yazi rengi beyaza ayarlanir
	        cout << *kovalar[i] <<endl;
        }
		SetConsoleTextAttribute(hh,15); // Konsolun yazi rengi beyaza ayarlanir
	}
    
    void KovaKontrol::ToplariYerlestir()
    {
        for (int i = 0; i < kovaSayisi; i++)
        {
            if (kovalar[i]->getTop() != NULL) { return; } // Kovalarda zaten top varsa fonksiyon doner ve islem yapilmasini engeller
            kovalar[i]->setTop(new Top(65 + Top::topSayac));// Toplar heap bellek bolgesinde olusturulup kovalara baglanir
        }
    }

    void KovaKontrol::ToplariYokEt()
    {
        for (int i = 0; i < kovaSayisi; i++)
        {
            if(kovalar[i]->getTop() == NULL) { return; } // Kovalarda top yoksa fonksiyon doner ve islem yapilmasini engeller

            delete kovalar[i]->getTop(); // Top nesneleri bellege iade edilir
            kovalar[i]->setTop(NULL);
        }
    }

    void KovaKontrol::KovaDegistir()
    {
        int ilkKova, ikinciKova;
		// Kullanicidan kovalar alinir
        cout << "Hangi Kova: ";
        cin >> ilkKova;
        cout << "Hangi Kova ile: ";
        cin >> ikinciKova;
		
		if(ilkKova > kovaSayisi || ikinciKova > kovaSayisi)
        {
			// Gecerli kovalardan girilmedigi durumda uyari mesaji verilir ve fonksiyon islem yapmadan doner
            cout << "Lutfen gecerli kovalardan giriniz..." << endl;
            system("pause");
            return;
        }
		
		// Programin devaminda diziler ile islem yapilacagindan alinan degerler bir azaltilir
        ilkKova--;
        ikinciKova--;

        IkiKovayiDegistir(ilkKova,ikinciKova); // Verilen iki kova degistirilir
    }

    void KovaKontrol::IkiKovayiDegistir(int birinci, int ikinci)
    {
        Kova* temp;
		
		// Kovalarin siralari birbiri ile degistirilir
        kovalar[birinci]->setKovaninSirasi(ikinci+1);
        kovalar[ikinci]->setKovaninSirasi(birinci+1);
		
		// Kova nesneleri bir temp yardimiyla yer degistirir
		temp = kovalar[birinci];
		kovalar[birinci] = kovalar[ikinci];
		kovalar[ikinci] = temp;
    }

    void KovaKontrol::KovalariTerstenYerlestir()
    {
        int ust = 0;
        int alt = kovaSayisi - 1;
		
        while(ust<alt)// Birer birer ilerleyerek ustteki kova ile alttaki kovayi degistirir
	    {
		    // Ilk Adim     Ikinci Adim ...
		    //    a-┐		  z
		    //    b |         b-┐
		    //	  ...	=>	  ...  =>...
		    //    y |         y-┘
		    //    z-┘         a
            IkiKovayiDegistir(ust,alt);
		    ust++;
		    alt--;
	    }
    }

    void KovaKontrol::TopDegistir()
    {
        if(kovalar[0]->getTop() == NULL) { return; } // Kovalarda top yoksa islem yapilmasini engeller
        int ilkTop, ikinciTop;
        cout << "Hangi Top: ";
        cin >> ilkTop;
        cout << "Hangi Top ile: ";
        cin >> ikinciTop;
		
		if(ilkTop > kovaSayisi || ikinciTop > kovaSayisi)
        {
            cout << "Lutfen gecerli toplardan giriniz..." << endl;
            system("pause");
            return;
        }
		
		// Programin devaminda diziler ile islem yapilacagindan alinan degerler bir azaltilir
        ilkTop--;
        ikinciTop--;

        IkiTopuDegistir(ilkTop, ikinciTop);
    }
    
    void KovaKontrol::IkiTopuDegistir(int birinci, int ikinci)
    {
		// Top nesneleri bir temp yardimiyla yer degistirir
        Top* temp;
        temp = kovalar[birinci]->getTop();
        kovalar[birinci]->setTop(kovalar[ikinci]->getTop());
        kovalar[ikinci]->setTop(temp);
    }

    void KovaKontrol::ToplariTerstenYerlestir()
    {
        if(kovalar[0]->getTop() == NULL) { return; } // Kovalarda top yoksa islem yapilmasini engeller
        int ust = 0;
        int alt = kovaSayisi - 1;

        while(ust<alt)// Birer birer ilerleyerek ustteki top ile alttaki topu degistirir
	    {
            IkiTopuDegistir(ust,alt);
		    ust++;
		    alt--;
	    }
    }

    void KovaKontrol::HepsiniYokEt()
    {
        ToplariYokEt(); // Top nesneleri bellege geri iade edilir
        
	    for(int i = 0; i < kovaSayisi; i++)
        {
		    delete kovalar[i]; // Kova nesneleri bellege geri iade edilir
	    }
		
		delete [] kovalar; // Kovalar pointer dizisi bellege geri iade edilir
    }