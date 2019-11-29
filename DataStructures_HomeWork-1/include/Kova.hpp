#ifndef KOVA_HPP
#define KOVA_HPP
#include <iostream>
#include "Top.hpp"
using namespace std;

class Kova{
	private:
		int kovaninSirasi;
        int renkKodu;
		char TopDurumu;
		Top *TopAdres;
	public:
		Kova();
		
        int getKovaninSirasi()const;
        char getTopDurumu()const;
        int getRenkKodu()const;
        Top* getTop()const;
		
        void setKovaninSirasi(int);
        void setTopDurumu(char);
		void setRenkKodu(int);
        void setTop(Top*);

		friend ostream& operator<<(ostream&,Kova&);
};
#endif