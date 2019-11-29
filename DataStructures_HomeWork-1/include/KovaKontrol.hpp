#ifndef KOVAKONTROL_HPP
#define KOVAKONTROL_HPP
#include "Kova.hpp"
#include "Top.hpp"

class KovaKontrol
{
    private:
        Kova **kovalar;
        int kovaSayisi;
    public:
		void KovaSayisiGir();
		void KovalariOlustur();
		void KovalariEkranaYazdir();
		void ToplariYerlestir();
		void ToplariYokEt();
		void KovaDegistir();
		void IkiKovayiDegistir(int,int);
		void KovalariTerstenYerlestir();
		void TopDegistir();
		void IkiTopuDegistir(int,int);
		void ToplariTerstenYerlestir();
		void HepsiniYokEt();
};
#endif