# Çalıştırmak için

```make``` ile derleyip

>  Pardus ve linux tabanlı sistmeler için `./sonuc.pars` diyerek çalıştırabilirsiniz

> windows için `sonuc.pars` çalıştırabilirsiniz


# Bizden istenenler

	Bu projede bize verilen fonksiyon imzalarına göre doldurulup bir matriks kütüphanesi oluşturmamız istendi. Bu doğrultuda matriks kütüphanesini oluşturup bunun header dosyası ile birlikte gerekli fonksiyon açıklamalarını yorum satırı olarak dosyaya eklendi.

      
# Projeden bazı kesitler
* Projede bize verilen imzalar haricinde ek olarak bazı imzalar da eklendi. Örneğin matriks ve vektör döndürmek için olan fonksiyona ek rast gele sayılarla dolduran fonksiyonlar da eklendi.

* Projede olabildiğince hafızayı gereksiz kullanmaktan kaçınılmaya çalışıldı. Gerekmedikçe yeni matriks oluşturulmadan eski matriks üzerinden işlemler yapılmaya devam edildi .Gerektiği yerde free ve freeMatrix fonksiyonları çağrılıp hafızadaki gereksiz bölümler işletim sistemine iade edildi. Ek olarak matriks silinirken güvenlik açığı olmasın diye tüm değerleri sıfırlanıp sisteme öyle geri verildi.

* Anlaması zor karışık fonksiyonlarda olabildiğince yorum satırı ekleyerek anlamayı kolaylaştırılmaya çalışıldı. Ek olarak her fonksiyonun header dosyasında kısa açıklamalarıyla birlikte dokümantasyonu eklendi.

* Dereleme işlemi ve çalıştırma işlemi her seferinde teker teker yazmaktansa bir make dosyası oluşturulup bütün işler otomatik hale getirilip test aşaması kolaylaştırılmıştır.

* Test dosyası çıktısı ayraçlarla ayrılıp okunması hem kolaylaştırılıp hem de daha anlamlı olması sağlanmıştır. Ek olarak değerler her çalıştırmada farklı çıksın diye dosya başına srand ile her seferinde farklı değerler çıkması sağlanmıştır.



# Test yapmak için
[kovaryans matrix](https://solvemymath.com/online_math_calculator/statistics/descriptive/covariance.php)

[kovaryans](https://www.ecalculator.co/calc/covariance-calculator#how-to-use-covariance-calculator)

[korelasyon](https://www.mathsisfun.com/data/correlation-calculator.html)

[matrix çarpımı](https://www.wolframalpha.com/input/?i=matrix+multiplication+calculator)

[determinant hesabı](https://www.wolframalpha.com/calculators/determinant-calculator)