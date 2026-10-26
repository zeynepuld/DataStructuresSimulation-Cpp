// // /*
// // * @file             Yonetici.cpp
// // * @description      İkili arama ağacı, kuyruk ve dairesel bağlı liste yapılarını kullanarak dosya okuma yöntemiyle hazırlanan bir simülasyon.
// // * @course           1-C
// // * @assignment       2. Ödev
// // * @date             14.12.2025
// // * @author           Zeynep Uludağ - zeynep.uludag2@ogr.sakarya.edu.tr
// // */

#include "Yonetici.hpp"
#include "Agac.hpp"
#include "Kuyruk.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

Yonetici::Yonetici() { // kurucu fonks
    bas = 0;
}

Yonetici::~Yonetici() { // yıkıcı fonks
    if (bas) {
        Hucre* gecici = bas;
        do {
            Hucre* silinecek = gecici;
            gecici = gecici->sonraki;
            delete silinecek;  // yıkıcı fonks hucre, kuyruğu da siler
        } while (gecici != bas);
    }
}

void Yonetici::DosyaOku(const char* dosyaYolu) {
    ifstream dosya(dosyaYolu);
    
    if (!dosya.is_open()) {
        cout << "HATA!!!! " << dosyaYolu << " dosyasi acilamadi!!!!!!!" << endl; // data.txt dosya açılamamsı kontrolü
        return;
    }

    char karakter;         // dosyadan okunan her bir harf/rakamı karakter diye tanımladım
    int sayi = 0;
    bool sayiOkunuyor = false; // şu an dosyadan bir satır okunuyor mu kontrolü

    Kuyruk* aktifKuyruk = new Kuyruk();
    Agac* aktifAgac = new Agac();

    while (dosya.get(karakter)) {
        
        if (karakter >= '0' && karakter <= '9') { // dosyadan okunan karakter bir rakam ise karakteri inte çeviirp basamak ekleniyor
            sayi = (sayi * 10) + (karakter - '0'); 
            sayiOkunuyor = true;
        }
        else if (karakter == '\n') { // okunan karakter yeni satır ise bu ağacın bittiğini ifade eder.
            if (sayiOkunuyor) { // eğer satır sonunda yarım kalan bir sayı avrsa önce onu ekleyecek
                aktifAgac->Ekle(sayi);
                sayi = 0;
                sayiOkunuyor = false;
            }

            if (aktifAgac->DugumSayisi() > 0) { // eğer ağaç boş değilse ağaç kuyruğa eklenecek.
                if (aktifKuyruk->DoluMu()) {
                    KuyrukEkle(aktifKuyruk);
                    aktifKuyruk = new Kuyruk();
                }
                aktifKuyruk->Ekle(aktifAgac);
                
                aktifAgac = new Agac(); // yeni bir agac oluşturuyor
            }
        }
        else { 
            if (sayiOkunuyor) { // okunan karakter boşluksa mesela, sayı bitmiş demektir. ağaça ekle ve sıfırla
                aktifAgac->Ekle(sayi);
                sayi = 0;
                sayiOkunuyor = false;
            }
        }
    }

    if (sayiOkunuyor) { 
        aktifAgac->Ekle(sayi);
    }

    if (aktifAgac->DugumSayisi() > 0) {
        if (aktifKuyruk->DoluMu()) {
            KuyrukEkle(aktifKuyruk);
            aktifKuyruk = new Kuyruk();
        }
        aktifKuyruk->Ekle(aktifAgac);
    } else {
        delete aktifAgac; 
    }

    if (!aktifKuyruk->BosMu()) { 
        KuyrukEkle(aktifKuyruk);
    } else {
        delete aktifKuyruk;
    }

    dosya.close(); 
}

void Yonetici::KuyrukEkle(Kuyruk* k) { 
    Hucre* yeni = new Hucre(k);
    
    if (bas == 0) {
        bas = yeni;
        bas->sonraki = bas;
        bas->onceki = bas;
    }
    else {
        Hucre* son = bas->onceki; 
        
        son->sonraki = yeni; 
        yeni->onceki = son;
        yeni->sonraki = bas;
        bas->onceki = yeni;
    }
}

void Yonetici::EkraniCiz(int tur) {

    cout << "Tur: " << tur << endl; // her tur başlangıcında kaçıncı turda olduğu gözükecek

    if (bas == 0) {
        cout << "Sistemde hic kuyruk kalmadi ki!!!!!!1." << endl; // eğer kuyruk kalmamışsa ortada, aşağıdaki mesajı döndürecek sistemin çökmemesi için önlem
        return;
    }

    Hucre* gecici = bas; // dairesel bağlı listenin sonsuza kadar dönmesi için döngü aşağıda
// çalışma şekli: bas düğümünden başlar. O düğümdeki kuyruğun (altıgenin) içine girer. ZirveDegeriGetir() fonksiyonunu çağırarak o kuyruğun değerini ekranda çıakrır. Bir sonraki düğüme geçer ve tekrardan bas düğümüne gelene kadar döner.

    
    do { // altıgenlerin sayısal karşılıkları yan yana yazılıyor. setw(5) ile her sayıya 5 karakterlik yer ayırdım.
        cout << setw(5) << gecici->kuyruk->ZirveDegeriGetir(); 
        gecici = gecici->sonraki;
    } while (gecici != bas);

    cout << endl << endl; // tur bitince bir satır boşluk bırakılacak
}

void Yonetici::Baslat() { // program başlatıldığında bu fonksiyon çalışacak mainde bu var
    
    int turSayisi;
    cout << "Kac tur oynatilsin: ";  // program ilk başltığında kullanıcıdan kaç tur döneceği isteniyor
    cin >> turSayisi;

    system("cls");

    EkraniCiz(0);

    for (int i = 1; i <= turSayisi; i++) {
        
        if (bas == bas->sonraki) break; 

        Hucre* gecici = bas;
        Hucre* enKucukHucre = bas;
        int minZirve = bas->kuyruk->ZirveDegeriGetir(); 

        do { // altıgenlerin yerine hangi sayılar yazılacak onu hespalıyor zirvedegerigetir fonksiyonu..
            int anlikZirve = gecici->kuyruk->ZirveDegeriGetir();
            if (anlikZirve < minZirve) {
                minZirve = anlikZirve;
                enKucukHucre = gecici;
            }
            gecici = gecici->sonraki;
        } while (gecici != bas); // çıkarılacak kuyruk belirlendiğinde bu kuyruktaki tüm ağaçlar boşaltılıp içindeki sayılar sonraki kuyruğa eklenecek.

        Hucre* hedef = enKucukHucre->sonraki; // verilerin aktarılacağı ağaç da bu
        
        while (!enKucukHucre->kuyruk->BosMu()) { // kuyruk boşlanaa kadar içindeki ağaçları çıkarma kısmı burada
            Agac* aktifAgac = enKucukHucre->kuyruk->Cikar(); 
            int* sayilar = aktifAgac->PostorderVerileriAl(); 
            int dugumSayisi = aktifAgac->DugumSayisi();
            
            for (int j = 0; j < dugumSayisi; j++) { //bu sayılaı tek tek yeni ağaçlar oluşturulup sonraki kuyruklara dağılıtıyor
                Agac* yeniAgac = new Agac();
                yeniAgac->Ekle(sayilar[j]);
                hedef->kuyruk->Ekle(yeniAgac);
                
                hedef = hedef->sonraki; 
                if (hedef == enKucukHucre) {
                    hedef = hedef->sonraki;
                }
            }
            delete[] sayilar;  // dizi siliniyor
            delete aktifAgac; // eski ağaç siliniyor
        }

        if (enKucukHucre == bas) bas = enKucukHucre->sonraki; // boşalan hücre de bellekten siliniyor
        
        enKucukHucre->onceki->sonraki = enKucukHucre->sonraki;
        enKucukHucre->sonraki->onceki = enKucukHucre->onceki;
        
        delete enKucukHucre; 

        EkraniCiz(i);
        
    }
    
    cout << "Simulasyon tamamlandi. Cikis yapabilirsiniz..." << endl;
    
    cin.ignore(); 
    cin.get();
}