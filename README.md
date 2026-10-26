# Veri Yapıları Simülasyonu

Üniversitede Veri Yapıları dersi kapsamında C++ ile geliştirdiğim bir simülasyon projesi. Projede farklı veri yapılarını bir arada kullanarak sayıları düzenleme ve simülasyon boyunca bu yapılar arasında aktarma işlemleri üzerinde çalıştım.

## Proje Hakkında

Program, dosyadan okunan sayıları ikili arama ağaçlarına yerleştirir. Bu ağaçlar, en fazla 6 ağaç tutabilen kuyruklarda gruplandırılır. Kuyruklar ise çift yönlü dairesel bağlı liste içerisinde tutulur.

Kullanıcıdan alınan tur sayısına göre simülasyon çalışır. Her turda belirlenen kurallara göre bir kuyruk seçilir, ağaçları silinir ve içindeki sayılar diğer kuyruklara yeni ağaçlar oluşturacak şekilde dağıtılır.

## Özellikler

- Dosyadan sayıları okuma ve ikili arama ağaçları oluşturma
- İkili arama ağacı, kuyruk ve çift yönlü dairesel bağlı liste kullanma
- Her kuyrukta en fazla 6 ağaç tutma
- Ağaçların yüksekliği, düğüm sayısı ve kök değerleri üzerinde hesaplamalar yapma
- Ağaçları postorder sırasıyla dolaşma
- Belirlenen kurallara göre kuyrukları seçme ve ağaçları diğer kuyruklara dağıtma
- Simülasyonun turlar boyunca güncellenen durumunu ekranda gösterme
- Dinamik bellek yönetimi ve bellek temizliği üzerinde çalışma

## Kullanılan Teknolojiler ve Konular

- C++
- İkili Arama Ağacı (Binary Search Tree)
- Kuyruk (Queue)
- Çift Yönlü Dairesel Bağlı Liste
- Nesne yönelimli programlama
- Dosya okuma ve yazma
- Dinamik bellek yönetimi
- Pointer kullanımı ve ağaç dolaşma algoritmaları
