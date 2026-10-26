/*
* @file             Agac.hpp
* @description      İkili arama ağacı, kuyruk ve dairesel bağlı liste yapılarını kullanarak dosya okuma yöntemiyle hazırlanan bir simülasyon.
* @course           1-C
* @assignment       2. Ödev
* @date             14.12.2025
* @author           Zeynep Uludağ - zeynep.uludag2@ogr.sakarya.edu.tr
*/

// ikili arama ağacı, BST, veriyi tutan yer
// dosyadan okunan satırlar sırayla bu ağaçlara yerleşiyor(postorder okumasıyla)
// bir ağaç, bir satırdaki sayıları tutuyor

#ifndef AGAC_HPP
#define AGAC_HPP

#include "Dugum.hpp"

class Agac {
private:
    Dugum* kok;
    
    void Ekle(Dugum*& aktif, int veri);
    void Sil(Dugum*& aktif);
    int Yukseklik(Dugum* aktif);

    void PostorderDizi(Dugum* aktif, int* dizi, int& index);
    int DugumSayisi(Dugum* aktif);

public:
    Agac();
    ~Agac();
    
    void Ekle(int veri);
    int Yukseklik();
    int GetKokVerisi();
    int DugumSayisi();

    int* PostorderVerileriAl(); // ağacın verilerini postorder biçimde okuyacak, verileri dizi şeklinde dönecek
};

#endif