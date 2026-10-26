/*
* @file             Dugum.cpp
* @description      İkili arama ağacı, kuyruk ve dairesel bağlı liste yapılarını kullanarak dosya okuma yöntemiyle hazırlanan bir simülasyon.
* @course           1-C
* @assignment       2. Ödev
* @date             14.12.2025
* @author           Zeynep Uludağ - zeynep.uludag2@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"

Dugum::Dugum(int veri) {
    this->veri = veri;
    this->sol = 0;
    this->sag = 0;
}

Dugum::~Dugum() {
}