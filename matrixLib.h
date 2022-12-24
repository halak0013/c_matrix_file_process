/**
* @file matrixLib.h
* @description Matriks işlelmerini yapan kütüphane
* @assignment ilk ödev
* @date 29/11/2022
* @author Muhammet Halak muhammet.halak@stu.fsm.edu.tr
*/
#ifndef tanimliMi
#define tanimliMi
/* istenilen boyutta tüm değerleri 0 olan bir vektör döndürür  */
float *returnVector(int size);

/*istenilen boyutta değerleri rastgele olan bir vektör döndürür*/
float *vectorRandom(int size);

/* istenilen boyutta tüm değerleri 0 olan bir matriks döndürür  */
float **returnMatrix(int row, int col);

/* istenilen boyutta değreleri rastgele olan bir matriks döndürür  */
float **matrixRandom(int row, int col);

/*
seçilen matiriksi sisteme geri verir 
teker teker tüm pontırları sisteme verip
değerleri de güvenlik nedeniyle sıfırlar
*/
void freeMatrix(float **mat, int row);
/* vektörün ortalamasını alır */
float mean(float *vec, int size);

/* seçilen satırın ortalamasını verir */
float *rowMeans(float **mat, int row, int col);

/* seçelen sutünun ortalamasını verir */
float *columnMeans(float **mat, int row, int col);

/* 
seçilen matriksleri biribiriyle çarpar 
    öncelikle birinci matriksteki satırların her bir değerini
    ikinci matriksteki sutünların herbiri ile çarıpıp
    tüm değerleri toplar
    bunu satır ve sütunlar bitene kadar devam ettirir
*/
float **matrixMultiplication(float **mat1, float **mat2, int row1, int col1, int row2, int col2);

/* seçilen matriksin tersini(traspozesini) alır */
float **matrixTranspose(float **mat, int row, int col);

/* 
seçilen matriksin determinantını alır

Öncelikle marise 2 tane sütun eklenir
Sondaki sütunalara değerleri konulur

    toplama için genel bir örüntü çıkıyor
    11 22 33 - 12 23 34 ...(ilk indis 1 olarak gösterilmiştir yazılmda 0 dır)
    görüldüğü gibi i i+j şeklinde gidiyor

    çıkarma işlemi için genel bir örüntü çıkıyor
    31 22 13 - 32 23 14
    görüldüğü gibi satır-m-1 k+m şeklinde gidiyor

*/
float determinant(float **mat, int row);

/* seçilen vektörBİLGİSAYARlerin korelasyonunu alır */
float correlation(float *vec, float *vec2, int size);

/* 
vektör uzunlukları aynı ise seçilen vektörlerin kovaryansını alır
S=(1/satır sayısı)*(traspoze X)*X
X: matirisin her satırından matris ortalaması çıkartılır
*/
float covariance(float *vec1, float *vec2, int size);

/* 
seçilen matriksin kovaryans matriksini döndürür 
*/
float **covarianceMatrix(float **mat, int row, int col);

/* seçilen vektörü yazdırı */
void printVector(float *vec, int N);

/* seçilen matriksi yazdırı */
void printMatrix(float **mat, int row, int col);
#endif