/*
* @file             Dugum.hpp
* @description      İkili arama ağacı, kuyruk ve dairesel bağlı liste yapılarını kullanarak dosya okuma yöntemiyle hazırlanan bir simülasyon.
* @course           1-C
* @assignment       2. Ödev
* @date             14.12.2025
* @author           Zeynep Uludağ - zeynep.uludag2@ogr.sakarya.edu.tr
*/

#ifndef DUGUM_HPP
#define DUGUM_HPP

class Dugum {
public:
    int veri;
    Dugum* sol;
    Dugum* sag;

    Dugum(int veri);
    ~Dugum();
};

#endif