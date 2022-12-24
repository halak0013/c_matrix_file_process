/**
 * @file matrixLib.c
 * @description Matriks işlelmerini yapan kütüphane
 * @assignment ilk ödev
 * @date 29/11/2022
 * @author Muhammet Halak muhammet.halak@stu.fsm.edu.tr
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrixLib.h"
#include <math.h>
/*
? matrix çarpımında parametre olarak alınan matriksler
? işlem bitince sisteme geri veriliyor mu
*/

float *returnVector(int size)
{
    return (float *)calloc(size, sizeof(float));
}
float *vectorRandom(int size)
{
    float *vector = returnVector(size);
    for (int i = 0; i < size; i++)
    {
        vector[i] = ((float)rand() / (float)(RAND_MAX)) * 10;
        //vector[i] = ((float)(rand() % 10)); 
        //test aşamasında kolay hesaplama için
    }
    return vector;
}
float **returnMatrix(int row, int col)
{
    float **matrix = calloc(row, sizeof(float *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = returnVector(col);
    }
    return matrix;
}

float **matrixRandom(int row, int col)
{
    float **matrix = calloc(row, sizeof(float *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = vectorRandom(col);
    }
    return matrix;
}

void freeMatrix(float **mat, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizeof(mat) / sizeof(mat[i]); j++)
        {
            mat[i][j] = 0;
            /*
            ? güvenlik için çöp kalmasın diye
            ? eski değerleri sıfırlıyoruz
            */
        }
        free(mat[i]); //? tüm satırdaki işarteçiler dolaşıp siler
    }
    free(mat);
    //printf("matrix silinmiştir\n");
}

float mean(float *vec, int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += vec[i];
    }
    return sum / size;
}

float **matrixMultiplication(float **mat1, float **mat2, int row1, int col1, int row2, int col2)
{
    if (col1 != row2)
        return NULL;
    float **result = returnMatrix(row1, col2);
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < col1; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
                /*
                ? öncelikle birinci matriksteki satırların her bir değerini
                ? ikinci matriksteki sutünların herbiri ile çarıpıp
                ? tüm değerleri toplar
                ? bunu satır ve sütunlar bitene kadar devam ettirir
                */
            }
        }
    }
    return result;
}

float **matrixTranspose(float **mat, int row, int col)
{
    float **trasnpoze = returnMatrix(col, row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            trasnpoze[j][i] = mat[i][j];
            /*
            ? satırlar ile sütünların yerini değiştirir
            */
        }
    }
    return trasnpoze;
}

float *rowMeans(float **mat, int row, int col)
{
    //? sağdan sola olanı hesaplar
    float toplama = 0;
    float *result = returnVector(col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            toplama += mat[i][j];
        }
        result[i] = toplama / col;
        toplama = 0;
    }
    return result;
}

float *columnMeans(float **mat, int row, int col)
{
    //? yukardan aşağı olanı hesaplar
    float toplama = 0;
    float *result = returnVector(col);
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            toplama += mat[j][i];
        }
        result[i] = toplama / row;
        toplama = 0;
    }
    return result;
}

float determinant(float **mat, int row)
{
    float det = 0;
    for (int i = 0; i < row; i++)
    {
        mat[i] = (float *)realloc(mat[i], row + 2);
        //? marise 2 tane sütun eklenir
    }

    for (int n = 0; n < row; n++)
    {
        for (int p = 0; p < row - 1; p++)
        {
            mat[n][p + 3] = mat[n][p];
            //? sondaki sütunalara değerleri konulur
        }
    }
    float toplam = 1.0; //? 1 verlime sebebi çarma işlemleri için
    /*
    ? toplama için genel bir örüntü çıkıyor
    ? 11 22 33 - 12 23 34 ...(ilk indis 1 olarak gösterilmiştir yazılmda 0 dır)
    ? görüldüğü gibi i i+j şeklinde gidiyor
    */
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            toplam *= mat[j][i + j];
        }
        det += toplam;
        toplam = 1;
    }
    toplam = 1;
    /*
    ? çıkarma işlemi için genel bir örüntü çıkıyor
    ? 31 22 13 - 32 23 14
    ? görüldüğü gibi satır-m-1 k+m şeklinde gidiyor
    */
    for (int k = 0; k < row; k++)
    {
        for (int m = 0; m < row; m++)
        {
            toplam *= mat[row - m - 1][k + m];
        }
        det -= toplam;
        toplam = 1;
    }
    return det;
}

float correlation(float *vec, float *vec2, int size)
{
    return covariance(vec, vec2, size) /( sqrt(covariance(vec, vec, size)) * sqrt(covariance(vec2, vec2, size)) );
}

float covariance(float *vec1, float *vec2, int size)
{
    if (sizeof(vec1) / sizeof(float) != sizeof(vec2) / sizeof(float))
    {
        printf("vektör uzunlukları aynı olmalı");
        return -1;
    }
    float mean1 = mean(vec1, size);
    float mean2 = mean(vec2, size);
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += ((vec1[i] - mean1) * (vec2[i] - mean2));
    }
    return (sum / (size-1));
}

float **covarianceMatrix(float **mat, int row, int col)
{
    float *colM = columnMeans(mat, row, col);
    //? her elemandan sütün ortalaması çıktılıyor
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            mat[j][i] -= colM[i];
        }
    }
    float **matTra = matrixTranspose(mat, row, col);
    mat = matrixMultiplication(matTra, mat, col, row, row, col);
    //? her değeri satır uzunluğuna bölüyoruz
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            mat[i][j] *= (1.0 / row);
        }
    }
    free(colM);
    freeMatrix(matTra,col);
    return mat;
}

void printVector(float *vec, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%f ", vec[i]);
    }
    printf("\n");
}

void printMatrix(float **mat, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }
}
