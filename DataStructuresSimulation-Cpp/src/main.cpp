/*
* @file             main.cpp
* @description      İkili arama ağacı, kuyruk ve dairesel bağlı liste yapılarını kullanarak dosya okuma yöntemiyle hazırlanan bir simülasyon.
* @course           1-C
* @assignment       2. Ödev
* @date             14.12.2025
* @author           Zeynep Uludağ - zeynep.uludag2@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "Yonetici.hpp"

using namespace std;

int main() {
    Yonetici* oyun = new Yonetici();
    
    oyun->DosyaOku("data.txt");
    oyun->Baslat();

    delete oyun;
    return 0;
}