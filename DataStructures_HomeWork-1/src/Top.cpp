#include "Top.hpp"

	int Top::topSayac = 0;
	Top::Top(char isim)
    {
		this->isim = isim; // Verilen isim topun ismine atanir
        topSayac++; // Top sayaci bir arttirilir
	}
    char Top::getIsim()const{return isim;}