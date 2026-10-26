/*
* @file             Agac.cpp
* @description      İkili arama ağacı, kuyruk ve dairesel bağlı liste yapılarını kullanarak dosya okuma yöntemiyle hazırlanan bir simülasyon.
* @course           1-C
* @assignment       2. Ödev
* @date             14.12.2025
* @author           Zeynep Uludağ - zeynep.uludag2@ogr.sakarya.edu.tr
*/

#include "Agac.hpp"
#include <iostream>
#include <algorithm>

Agac::Agac() {
    kok = 0;
}

Agac::~Agac() {
    Sil(kok);
}

void Agac::Sil(Dugum*& aktif) { // hafızadan düğümleri silme fonksiyonu
    if (aktif) { // eğer aktif düğüm varsa, solunu sil, sağını sil, kendisini sil. aktif düğüm yoksa if(0) yani hiçbir şey yapma.
        Sil(aktif->sol);
        Sil(aktif->sag);

        delete aktif;
        aktif = 0;
    }
}

void Agac::Ekle(Dugum*& aktif, int veri) {
    if (aktif == 0) { // düğüm yoksa ağaçta yeni düğüm oluşturur
        aktif = new Dugum(veri);
    }
    else if (veri <= aktif->veri) { // aranan veri küçükse veya değerler eşitse ağacın soluna eklenecek
        Ekle(aktif->sol, veri);
    }
    else {
        Ekle(aktif->sag, veri); // aranan veri büyükse ağacın sağına eklenecek
    }
}

void Agac::Ekle(int veri) { // kullanıcı sayı girdiğinde çağırılacak ekleme fonksiyonu.
    Ekle(kok, veri);
}

int Agac::Yukseklik(Dugum* aktif) { // yükseklik hesaplama fonksiyonu
    if (aktif) {
        int solYuk = Yukseklik(aktif->sol);
        int sagYuk = Yukseklik(aktif->sag);
        return 1 + (solYuk > sagYuk ? solYuk : sagYuk); // max yükseklik değerini bulmak için
    }
    return 0; // düğüm yoksa yükseklik 0 zaten
}

int Agac::Yukseklik() {
    return Yukseklik(kok);
}

int Agac::GetKokVerisi() { // ağacın kökünü bulan fonksiyon
    if (kok) // eğer ağaç varsa kökünü bulur, yoksa 0 döndürür
        return kok->veri;
    return 0;
}

int Agac::DugumSayisi(Dugum* aktif) { // dizi oluşturmak için düğüm sayısını buluyor bu fonksiyon da
    if (aktif == 0) // düğüm varsa sol+sağ+1den düğüm sayısını hesaplar,, yoksa çıkış
        return 0;
    return 1 + DugumSayisi(aktif->sol) + DugumSayisi(aktif->sag);
}

int Agac::DugumSayisi() {
    return DugumSayisi(kok);
}

// ağaçtan düğümleri çıkarıp diğer kuyruğa ekleme işlemi yapıcam aşağıda

void Agac::PostorderDizi(Dugum* aktif, int* dizi, int& index) { // postorder şekilde sol-sağ-kök diye ağaçlardaki
    if (aktif) {
        PostorderDizi(aktif->sol, dizi, index);
        PostorderDizi(aktif->sag, dizi, index);
        dizi[index++] = aktif->veri;
    }
}

int* Agac::PostorderVerileriAl() {
    int sayi = DugumSayisi();
    int* dizi = new int[sayi]; // düğüm sayısı kadar elemanı olan bir dizi oluşturdum. sonra bu düğümleri bu diziye ekledim.
    int index = 0;
    PostorderDizi(kok, dizi, index); // sayıların postorder sıralanmış halini içeren bir dizi (pointer) oluştu.
    return dizi;
}