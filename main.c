/**
 * @file main.c
 * @description Matriks işlelmerini yapan kütüphane
 * @assignment ilk ödev
 * @date 29/11/2022
 * @author Muhammet Halak muhammet.halak@stu.fsm.edu.tr
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "matrixLib.h"
#include <ctype.h>

#define N 5
typedef enum
{
    Iris_setosa = 1,
    Iris_versicolor,
    Iris_virginica
} species;

typedef struct
{
    float SepalLengthCm;
    float SepalWidthCm;
    float PetalLengthCm;
    float PetalWidthCm;
    species specie;
} IrisDataType;

void denemeOku(IrisDataType *ir, char *s)
{
    printf("*%f -", ir->SepalLengthCm);
    printf("%f -", ir->SepalWidthCm);
    printf("%f -", ir->PetalLengthCm);
    printf("%f -", ir->PetalWidthCm);
    printf("%s \n", s);
}
float **dataInclude(IrisDataType *datas, int row, int col)
{
    float **dataMatrix = matrixRandom(row, col);
    perror("dene");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            dataMatrix[i][j] = *((float *)datas + i * (col + 1) + j);
        }
    }
    return dataMatrix;
}

float *convertToVector(float **matris, int sellectedCol,int row,int col)
{
    printf("satir %d sutun %d",row,col);
    float *result=returnVector(row);
    for (int i = 0; i < row; i++)
    {
        result[i]=matris[i][sellectedCol];
    }
    return result;
}

int main(int argc, char *argv[])
{
    {
        if (argc == 2)
        {
            srand(atoi(argv[1]));
        }
        else
            srand(time(NULL)); //? her çalıştırmada farklı değerler vermesi için
        printf("-----------------\n");
        float **mat1 = matrixRandom(5, 2);
        float **mat2 = matrixRandom(2, 7);
        printf("--------mat1---------\n");
        printMatrix(mat1, 5, 2);
        printf("--------mat2---------\n");
        printMatrix(mat2, 2, 7);
        printf("--------matrix Multiplication---------\n");
        printMatrix(matrixMultiplication(mat1, mat2, 5, 2, 2, 7), 5, 7);
        printf("--------matrix Transpose---------\n");
        printMatrix(matrixTranspose(mat2, 2, 7), 7, 2);
        float **mat3 = matrixRandom(3, 3);
        printf("--------mat3---------\n");
        printMatrix(mat3, 3, 3);
        printf("--------row mean---------\n");
        printVector(rowMeans(mat3, 3, 3), 3);
        printf("--------column mean---------\n");
        printVector(columnMeans(mat3, 3, 3), 3);
        printf("--------deta---------\n");
        printf("%f\n", determinant(mat3, 3));
        freeMatrix(mat3, 3);
        printf("--------mat3 silinmiş---------\n");
        printMatrix(mat3, 3, 3);

        float *vec2 = vectorRandom(N);
        float *vec3 = vectorRandom(N);
        printf("--------vec1---------\n");
        printVector(vec2, N);
        printf("--------vec2---------\n");
        printVector(vec3, N);
        printf("--------mean1---------\n");
        printf("%f\n", mean(vec2, N));
        printf("--------mean2---------\n");
        printf("%f\n", mean(vec3, N));
        printf("--------cov---------\n");
        printf("%.18f\n", covariance(vec2, vec3, N));
        printf("--------cor---------\n");
        printf("%.18f\n", correlation(vec2, vec3, N));
        float **mat4 = matrixRandom(N, N);
        printf("--------mat4---------\n");
        printMatrix(mat4, N, N);
        printf("--------cov mat---------\n");
        printMatrix(covarianceMatrix(mat4, N, N), N, N);
    }

    // rb ile yapmayı dene
    FILE *file = fopen("Iris.csv", "rb");
    if (file == NULL)
    {
        perror("dosya bulunamadı");
        exit(1);
    }
    int length;
    fscanf(file, "%d", &length);

    char *line = (char *)malloc(sizeof(char) * 10);
    IrisDataType *datas = (IrisDataType *)malloc(sizeof(IrisDataType) * length);
    char temp_c;
    int temp_i;
    char *temp_s=(char *)malloc(sizeof(char) * 20);;

    fgets(line, __INT_MAX__, file);
    fgets(line, __INT_MAX__, file);
    for (int i = 0; i < length; i++)
    {
        fscanf(file, "%d,%f,%f,%f,%f,%[^\n]", &temp_i,
               &datas[i].SepalLengthCm, 
               &datas[i].SepalWidthCm,
               &datas[i].PetalLengthCm,
               &datas[i].PetalWidthCm,
               temp_s);
        denemeOku(&datas[i],temp_s);
        fgets(line, __INT_MAX__, file);
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            irisMatris[i][j] = *((float *)datas + i * (5) + j);
        }
    }
    printMatrix(irisMatris, length, 4);
    float *SepalLengthCm=convertToVector(irisMatris,0,length,4);
    float *SepalWidthCm=convertToVector(irisMatris,1,length,4);
    float *PetalLengthCm=convertToVector(irisMatris,2,length,4);
    float *PetalWidthCm=convertToVector(irisMatris,3,length,4);

    float slMean=mean(SepalLengthCm,length);
    float swMean=mean(SepalWidthCm,length);
    float plMean=mean(PetalLengthCm,length);
    float pwMean=mean(PetalWidthCm,length);

    float slVaryans=VARY(SepalLengthCm,length);
    float swVaryans=VARY(SepalWidthCm,length);
    float plVaryans=VARY(PetalLengthCm,length);
    float pwVaryans=VARY(PetalWidthCm,length);

    float sl_sw_corel=correlation(SepalLengthCm,SepalWidthCm,length);
    float pl_pw_corel=correlation(PetalLengthCm,PetalWidthCm,length);
    float sl_pl_corel=correlation(SepalLengthCm,PetalLengthCm,length);

    dataCorelMat=covarianceMatrix(irisMatris,length,4);
    fclose(file);

    fprintf(outPut,"Değerlerin Ortalaması\n");
    fprintf(outPut,"Sepal Length Cm Ortalaması: %f\n",slMean);
    fprintf(outPut,"Sepal Width Cm Ortalaması: %f\n",swMean);
    fprintf(outPut,"Petal Length Cm Ortalaması: %f\n",plMean);
    fprintf(outPut,"Petal Width Cm Ortalaması: %f\n",pwMean);

    fprintf(outPut,"\n\nDeğerlerin Varyansı\n");
    fprintf(outPut,"Sepal Length Cm Varyansı: %f\n",slVaryans);
    fprintf(outPut,"Sepal Width Cm Varyansı: %f\n",swVaryans);
    fprintf(outPut,"Petal Length Cm Varyansı: %f\n",plVaryans);
    fprintf(outPut,"Petal Width Cm Varyansı: %f\n",pwVaryans);


    return 0;
}
