/*
* @file             Hucre.hpp
* @description      İkili arama ağacı, kuyruk ve dairesel bağlı liste yapılarını kullanarak dosya okuma yöntemiyle hazırlanan bir simülasyon.
* @course           1-C
* @assignment       2. Ödev
* @date             14.12.2025
* @author           Zeynep Uludağ - zeynep.uludag2@ogr.sakarya.edu.tr
*/


// altıgenleri(kuyrukları) bağlamak için

#ifndef HUCRE_HPP
#define HUCRE_HPP

#include "Kuyruk.hpp"

class Hucre {
public:
    Kuyruk* kuyruk;
    Hucre* sonraki;
    Hucre* onceki;

    Hucre(Kuyruk* kuyruk);
    ~Hucre();
};

#endif