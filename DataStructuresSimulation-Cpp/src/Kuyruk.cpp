/*
* @file             Kuyruk.cpp
* @description      İkili arama ağacı, kuyruk ve dairesel bağlı liste yapılarını kullanarak dosya okuma yöntemiyle hazırlanan bir simülasyon.
* @course           1-C
* @assignment       2. Ödev
* @date             14.12.2025
* @author           Zeynep Uludağ - zeynep.uludag2@ogr.sakarya.edu.tr
*/

#include "Kuyruk.hpp"
#include <iostream>

Kuyruk::Kuyruk() { // kurucu fonksiyon
    kapasite = 6;
    bas = 0;
    son = 0;
    elemanSayisi = 0;
    veriler = new Agac*[kapasite];
}

Kuyruk::~Kuyruk() { // yıkıcı fonksiyon
    for(int i=0; i < elemanSayisi; i++) { // kuyruk silinirken içindeki ağaçları da silmek için for döngüsü
        int index = (bas + i) % kapasite;
        delete veriler[index];
    }

    delete[] veriler;
}

bool Kuyruk::BosMu() { // silmeden önce ( Cikar() fonksiyonunu çağırmadan önce) boş mu, eleman kaldı mı diye kontrol. Cikar fonksiyonunun başında: if(BosMu()) return 0; yazıcam.BosmU true ise dönecek.
    return elemanSayisi == 0;
}

bool Kuyruk::DoluMu() { // max 6 alıyor, max kapasiteye oluştu mu diye knontrol. Ekle fonksiyonu çağırmadan önce yazıcam. Eğer DoluMu true dönerse yeni bi kuyruk yani yeni bi altıgen oluşacak.
    return elemanSayisi == kapasite;
}

void Kuyruk::Ekle(Agac* veri) {
    if (DoluMu()) // kuyruk kapasitesi (6) dolduysa işlem yapılmaz, çıkış
        return;
    
    veriler[son] = veri;
    son = (son + 1) % kapasite; // indeksi 0,1,2,3,4, 5 olarak kullanarak dairesel sonsuz dizi mantığı
    elemanSayisi++;
}

// Normal Çıkarma (Tek Turlar)
Agac* Kuyruk::Cikar() {
    if (BosMu())
        return 0; // kuyrukta hiç eleman yoksa çıkarma işlemi yapmaya gereksiz, çıkış
    
    Agac* deger = veriler[bas]; // kuyruğun en önündeki elemanının adresini tutuyorum(deger), geçici olarrak
    bas = (bas + 1) % kapasite; // kuyruğun başını bir sağaa kaydırdım, başlangıç noktası değişti
    elemanSayisi--; 

    return deger;
}

// Öncelikli Çıkarma (Çift Turlar) - Yüksekliği en büyük olan
Agac* Kuyruk::OncelikliCikar() {
    if (BosMu())
        return 0;
    
    int maxIndex = bas;
    int maxYukseklik = veriler[bas]->Yukseklik();
    
    for (int i = 0; i < elemanSayisi; i++) { // diziyi dolaşıp yüksekliği en büyük olan elemanı buluyor sonra bunun dizideki indeksini alıyor.
        int index = (bas + i) % kapasite;
        int h = veriler[index]->Yukseklik();
        
        if (h > maxYukseklik) {
            maxYukseklik = h;
            maxIndex = index;
        }
    }
    
    Agac* silinecek = veriler[maxIndex]; // adresin kaybolmaması lazım. silmeden önce adresini yedekliyorum geçici pointerla.
    
    int anlik = maxIndex;
    int donguSayisi = (elemanSayisi - 1) - ((maxIndex - bas + kapasite) % kapasite); // kalan eleman sayısı
    
    for(int i=0; i<donguSayisi; i++) { // silinen elemanın arkasındaki tüm elemanları bi öne kaydıran fonksiiyon
        int sonraki = (anlik + 1) % kapasite;
        veriler[anlik] = veriler[sonraki];
        anlik = sonraki;
    }
    son = (son - 1 + kapasite) % kapasite; 
    elemanSayisi--;
    
    return silinecek;
}

Agac* Kuyruk::Getir(int sira) { // belirli o sıradaki elemanı indeksi yardımıyla buluyorum
    int index = (bas + sira) % kapasite;
    return veriler[index]; 
}

int Kuyruk::ElemanSayisi() {
    return elemanSayisi;
}

int Kuyruk::ZirveDegeriGetir() { // ekranda altıgenler yerine yazacak sayıyı buluyor.formül = (Kuyruğun en başındaki ağacın) kökü / (Kuyruktaki tüm ağaçlar arasından yüksekliği en fazla olan ağacın) kökü

    if (BosMu()) // kuyruk boşsa işlem yapılmaz kontrolü
        return 0;
    
    int cikacakKok = veriler[bas]->GetKokVerisi(); // baştaki verinin kök değeri.b ölünen pay kısmı bu
    
    int maxYukseklik = -1; // aşağıda yüksekliği en fazla olan ağacın kök değeri bulunacak
    int maxKok = 1; // 0a bölünme hatası olmasın diye default 1 yaptım kontrol
    
    for (int i = 0; i < elemanSayisi; i++) { //yüksekliği en fazla olan ağacın kök değerini bulmaca
        int index = (bas + i) % kapasite;
        int h = veriler[index]->Yukseklik();
        
        if (h > maxYukseklik) {
            maxYukseklik = h;
            maxKok = veriler[index]->GetKokVerisi(); // payda bölen bu
        }
    }
    
    return cikacakKok / maxKok; // ekranda bu işlemşn sonucu olan sayı yazacak o altıgen yerine.
}