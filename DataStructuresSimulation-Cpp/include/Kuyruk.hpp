/*
* @file             Kuyruk.hpp
* @description      İkili arama ağacı, kuyruk ve dairesel bağlı liste yapılarını kullanarak dosya okuma yöntemiyle hazırlanan bir simülasyon.
* @course           1-C
* @assignment       2. Ödev
* @date             14.12.2025
* @author           Zeynep Uludağ - zeynep.uludag2@ogr.sakarya.edu.tr
*/


// her bir altıgen, bir kuyruk, ağaçları tutan yer
// bir kuyruk en fazla 6 adet ağaç tutabilir

#ifndef KUYRUK_HPP
#define KUYRUK_HPP

#include "Agac.hpp"

class Kuyruk {
private:
    Agac** veriler;
    int kapasite;
    int bas;
    int son;
    int elemanSayisi;

public:
    Kuyruk();
    ~Kuyruk();
    
    bool BosMu();
    bool DoluMu();
    void Ekle(Agac* veri);
    Agac* Cikar();
    Agac* OncelikliCikar(); // yüksekliğe göre ağaçtan çıkarılacak
    
    Agac* Getir(int sira); // ekleme yapmak için indekse göre ağaç getirecek
    int ElemanSayisi();
    
    int ZirveDegeriGetir(); // kök/en büyük kök işlemini yapacak fonksiyon bu
    
};

#endif