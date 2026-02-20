# TinyML Tensor ve Dinamik Nicemleme (Quantization) Projesi

Bu proje, kısıtlı belleğe sahip gömülü sistemler (Arduino, ESP32 vb.) için tasarlanmış dinamik bir **Tensor** yapısını ve %75 bellek tasarrufu sağlayan bir **Nicemleme (Quantization)** algoritmasını içerir.

## 🚀 Proje Özellikleri

* **Dinamik Bellek Yönetimi**: Matris boyutları çalışma zamanında (runtime) `malloc` ile belirlenir ve işlem sonunda `free` ile bellek sisteme iade edilir.
* **Union Tabanlı Mimari**: Bellek verimliliği için aynı adresi paylaşan float ve int8 pointerları kullanılarak RAM tasarrufu sağlanmıştır.
* **8-Bit Quantization**: 32-bit float veriler, 8-bit tam sayılara sıkıştırılarak düşük kapasiteli cihazlarda yüksek performans hedeflenmiştir.

## 🛠 Teknik Detaylar

* **Uygulanan Formül**: Veriler şu matematiksel model ile nicemlenmiştir:  
  $$Q = \text{int8}(V_{float} \times 127.0)$$
* **Geliştirme Yaklaşımı**: Bu proje, **Agentic Coding** prensipleriyle (Yapay Zeka asistanı Gemini ile interaktif mühendislik süreci) geliştirilmiştir.
* **Hata Ayıklama**: Geliştirme sürecinde Debugger kullanılarak matrislerin bellekteki durumları anlık olarak doğrulanmıştır.

## 💻 Çalıştırma

Proje GCC derleyicisi ile derlenip terminal üzerinden çıktıları gözlemlenebilir:

1. `gcc main.c -o main`
2. `./main`
