/*
* @file             Yonetici.hpp
* @description      İkili arama ağacı, kuyruk ve dairesel bağlı liste yapılarını kullanarak dosya okuma yöntemiyle hazırlanan bir simülasyon.
* @course           1-C
* @assignment       2. Ödev
* @date             14.12.2025
* @author           Zeynep Uludağ - zeynep.uludag2@ogr.sakarya.edu.tr
*/

#ifndef YONETICI_HPP
#define YONETICI_HPP

#include "Hucre.hpp"


class Yonetici {
private:
    Hucre* bas; // dairesel bağlı listenin en başındaki düğüm
    
    void KuyrukEkle(Kuyruk* k);
    void EkraniCiz(int tur);

public:
    Yonetici(); // yonetici kurucu fonksiyon
    ~Yonetici(); // yonetici yıkıcı fonksiyon
    
    void DosyaOku(const char* dosyaYolu); // karakterlerden oluşan bir dizi. dosyaYolu'nun hafızadaki adresini verir.
    
    void Baslat(); // programı başlatan fonksiyon. ilk çalıştırıldığında kullanıcıdan tur sayısını ister.
};

#endif