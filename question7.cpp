
#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 255
#define OK 1
#define TRUE 1
#define ERROR -1
#define FALSE -1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct {
    int i, j; ElemType e;
}Triplet;//结点定义
typedef struct {
    int mu, nu, tu;
    Triplet data[MAX_SIZE + 1
    ];
}TSMatrix;
Status DestroyMatrix(TSMatrix* t);
void Display(TSMatrix t);
Status Transpose(TSMatrix m, TSMatrix* t);
void FatsTransMatrix(TSMatrix m, TSMatrix* t);
int main(void)
{
    TSMatrix matrix, inverseM, inv;
    Triplet triplet;

    matrix.mu = 6;
    matrix.nu = 7;
    matrix.tu = 8;
    triplet.i = 1;
    triplet.j = 2;
    triplet.e = 12;
    matrix.data[1] = triplet;

    triplet.i = 1;
    triplet.j = 3;
    triplet.e = 9;
    matrix.data[2] = triplet;
    triplet.i = 3;
    triplet.j = 1;
    triplet.e = -3;
    matrix.data[3] = triplet;

    triplet.i = 3;
    triplet.j = 6;
    triplet.e = 14;
    matrix.data[4] = triplet;
    triplet.i = 4;
    triplet.j = 3;
    triplet.e = 24;
    matrix.data[5] = triplet;

    triplet.i = 5;
    triplet.j = 2;
    triplet.e = 18;
    matrix.data[6] = triplet;
    triplet.i = 6;
    triplet.j = 1;
    triplet.e = 15;
    matrix.data[7] = triplet;

    triplet.i = 6;
    triplet.j = 4;
    triplet.e = -7;
    matrix.data[8] = triplet;
    printf("原始矩阵的三元组表示为：\n");
    Display(matrix);

    Transpose(matrix, &inverseM);
    printf("转置矩阵的三元组表示为：\n");
    Display(inverseM);

    FatsTransMatrix(matrix, &inv);
    printf("快速转置矩阵的三元组表示为：\n");
    Display(inv);

    DestroyMatrix(&matrix);
    DestroyMatrix(&inverseM);

    return 0;
} // end main
Status DestroyMatrix(TSMatrix* t) {
    t->mu = 0; t->nu = 0; t->tu = 0;
    return OK;
}
void Display(TSMatrix t) {
    printf("     i     j     v\n");
    for (int i = 1; i <= t.tu; i++)
        printf("%6d%6d%6d\n", t.data[i].i, t.data[i].j, t.data[i].e);
    printf("\n");
}
Status Transpose(TSMatrix m, TSMatrix* t) {
    int col, p, q; q = 1;
    t->mu = m.nu; t->nu = m.mu; t->tu = m.tu;
    if (t->tu == 0)
        return OK;
    for (col = 1; col <= t->nu; col++)
        for (p = 1; p <= t->tu; p++)
            if (m.data[p].j == col) {
                t->data[q].i = m.data[p].j;
                t->data[q].j = m.data[p].i;
                t->data[q].e = m.data[p].e;
                q++;
            }
    return OK;
}
void FatsTransMatrix(TSMatrix m, TSMatrix* t) {//快速转置
    int* num, * copt;//num记录每列非0元素个数，copt记录在t的位置。
    int col, p, q, k;
    num = (int*)malloc((m.nu + 1) * sizeof(int));
    if (num == NULL)
        exit(-1);
    copt = (int*)malloc((m.nu + 1) * sizeof(int));
    if (copt == NULL)
        exit(-1);
    t->mu = m.nu; t->nu = m.mu; t->tu = m.tu;
    if (t->tu == 0)
        printf("The Matrix A = 0\n");
    else {
        for (col = 1; col <= m.nu; col++)//遍历m矩阵每一列，初始化num非0元素个数
            num[col] = 0;//初始化
        for (k = 1; k <= m.tu; k++)
            num[m.data[k].j]++;//记录每一列非0元素个数
        for (copt[1] = 1, col = 2; col <= m.nu; col++)
            copt[col] = copt[col - 1] + num[col - 1];//求每一列第一个非0元素的序号
        for (p = 1; p <= m.tu; p++) {
            col = m.data[p].j;//找列号
            q = copt[col];//新矩阵的位置
            t->data[q].i = m.data[p].j;
            t->data[q].j = m.data[p].i;
            t->data[q].e = m.data[p].e;
            ++copt[col];
        }
        free(num); free(copt);
    }
}