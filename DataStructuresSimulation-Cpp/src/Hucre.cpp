/*
* @file             Hucre.cpp
* @description      İkili arama ağacı, kuyruk ve dairesel bağlı liste yapılarını kullanarak dosya okuma yöntemiyle hazırlanan bir simülasyon.
* @course           1-C
* @assignment       2. Ödev
* @date             14.12.2025
* @author           Zeynep Uludağ - zeynep.uludag2@ogr.sakarya.edu.tr
*/

#include "Hucre.hpp"

Hucre::Hucre(Kuyruk* kuyruk) {
    this->kuyruk = kuyruk;
    this->sonraki = 0;
    this->onceki = 0;
}

Hucre::~Hucre() {
    if (kuyruk != 0)
        delete kuyruk; // hücre silinince içindeki kuyruk da silinir
}