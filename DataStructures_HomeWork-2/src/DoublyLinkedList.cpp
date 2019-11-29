/**
* @file DoublyLinkedList.cpp
* @description DoublyLinkedList sinifinin metod govdelerinin bulundugu cpp dosyasi
* @course 2. ogretim A grubu
* @assignment 2. odev
* @date 25/11/2019
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr // Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
*/
#include "DoublyLinkedList.hpp"

		DoublyLinkedList::DoublyLinkedList()
		{
			// Bas dugumu olusturur
			setBasDugum(new Dugum());
			size=0;
			kazanc = 0;
		}
		
		Dugum* DoublyLinkedList::getBasDugum() const
		{
			// Bas dugumu dondurur
			return basDugum;
		}
		void DoublyLinkedList::setBasDugum(Dugum* yeniBasDugum)
		{
			// Bas dugume atama yapar
			basDugum = yeniBasDugum;
		}
		
		void DoublyLinkedList::kazancEkle(int eklenecekKazanc)
		{
			// Her tekrar edilen degerden sonra kazanilan byte'i ekler
			kazanc += eklenecekKazanc;
		}
		
		int DoublyLinkedList::getKazanc() const
		{
			// Kazanilan byte degerini dondurur
			return kazanc;
		}
		
		void DoublyLinkedList::BoyutArttir()
		{
			// Boyutu arttirir
			size++;
		}
		
		void DoublyLinkedList::BoyutAzalt()
		{
			// Boyutu azaltir
			size--;
		}
		
		bool DoublyLinkedList::isEmpty() const
		{
			// Listenin bos olup olmadigini dondurur
			return getBasDugum()->getIleri() == NULL;
		}
		
		int DoublyLinkedList::Count() const
		{
			// Listenin boyutunu dondurur
			return size;
		}
		
		void DoublyLinkedList::add(const string yeni)// Listenin sonuna ekleme yapar, tekrar eden deger varsa kontrol eder
		{
			int index=0;
			Iterator *iterator = new Iterator(basDugum); // current'i BasDugumu gösteren bir iterator olusturulur
			Dugum *yeniDugum = new Dugum(); // Eklenecek dugum heapte olusturulur
			
			while(Count() != index++)
			{
				if(yeni == iterator->getCurrentEleman()) 
				{// Yeni dugumun elemani ile iteratorun o an gosterdigi dugumdeki elemanin ayni olup olmadigi kontrol edilir
					yeniDugum->setTekrarliDegerMi(true);
					kazancEkle(yeni.length()-1);
				}
				if(yeniDugum->getTekrarliDegerMi() == true) // Yeni eklenecek dugumun elemani daha onceden varsa buraya girer
				{
					yeniDugum->setTekrarEdenKonum(yeniDugum->getTekrarEdenKonum()+1);
				}
				iterator->next(); // Her iterasyonda iteratorun ilerlemesi saglanir
			}
			
			iterator->getCurrent()->setIleri(yeniDugum); // Yeni dugum en son dugumun ilerisine eklenir
			
			// Ilk dugum eklenirken eklenen dugumun gerisinin NULL olarak kalması saglanir
			if(!Count() == 0) iterator->getCurrent()->getIleri()->setGeri(iterator->getCurrent());
			
			// Eklenen dugumun elemani tekrarli bir elemansa bos deger atanip tekrar eden degerin konumu belirtilir
			if(yeniDugum->getTekrarliDegerMi())
			{
				yeniDugum->setEleman("");
				yeniDugum->setTekrarEdenKonum(yeniDugum->getTekrarEdenKonum()+1);
			}
			else // Tekrarli bir eleman degilse girilen eleman dugumun elemanina atanir
			{
				yeniDugum->setEleman(yeni);
			}
			BoyutArttir(); // Bir eleman eklendiginden boyut bir arttirilir
			delete iterator;
		}
		
		ostream& operator << (ostream& screen, DoublyLinkedList &right)
		{
			if(right.isEmpty()) screen<<"Liste bos"; // Liste bos ise ekrana yazilir
			
			else
			{ // Liste bos degilse her dugum ekrana bir tasarim icinde basilir
				if(right.getBasDugum()->getIleri()->getGeri() == NULL) screen << "NULL<-";
				for(Iterator iterator = right.getBasDugum()->getIleri(); !iterator.canMove(); iterator.next())
				{
					screen << "|" << iterator.getCurrentEleman()<<" - " << iterator.getCurrent()->getTekrarEdenKonum() << "|";
					if(iterator.getCurrent()->getIleri() != NULL) screen << "<->";
					else screen << "->NULL";
				}
				screen << endl;
				screen << "Toplam Kazanc: " << right.getKazanc() << endl;
			}
			return screen;
		}
		
		void DoublyLinkedList::clear() // Listedeki butun elemanlari temizler
		{
			Iterator *onceki = new Iterator(getBasDugum()); // Bas dugumu gosteren bir iterator olusturulur
			
			while(onceki->getCurrent()->getIleri() != NULL) // BasDugumun ilerisi NULL olana kadar calisir
			{
				Dugum *eskiDugum = onceki->getCurrent()->getIleri(); // Silinecek dugum eskiDugum'e atanir
				onceki->getCurrent()->setIleri(onceki->getCurrent()->getIleri()->getIleri()); //basDugum'un ilerisi iki ilerisini gosterir
				delete eskiDugum; // eskiDugum bellege geri verilir
				BoyutAzalt(); // Boyut bir azaltilir
			}
			delete onceki;
		}
		
		DoublyLinkedList::~DoublyLinkedList()
		{ // Heapte olusan butun nesneler iade edilir
			clear();
			delete basDugum;
		}