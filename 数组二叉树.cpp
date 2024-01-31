//#include <stdio.h>
//
//#define MAX_SIZE 100
//
//typedef struct {
//    int data[MAX_SIZE];
//    int size;
//} BinaryTree;
//
//void createBinaryTree(BinaryTree* bt, int* arr, int len)
//{
//    bt->size = len;
//    for (int i = 0; i < len; i++) {
//        bt->data[i] = arr[i];
//    }
//}
//
//void preorderTraversal(BinaryTree bt, int index)
//{
//    if (index >= bt.size)
//        return;
//
//    printf("%d ", bt.data[index]); // 访问当前节点
//
//    int leftChildIndex = 2 * index + 1;
//    int rightChildIndex = 2 * index + 2;
//
//    preorderTraversal(bt, leftChildIndex);  // 遍历左子树
//    preorderTraversal(bt, rightChildIndex); // 遍历右子树
//}
//
//int main()
//{
//    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//    int len = sizeof(arr) / sizeof(arr[0]);
//
//    BinaryTree bt;
//    createBinaryTree(&bt, arr, len);
//
//    preorderTraversal(bt, 0); // 从根节点 0 开始前序遍历
//
//    return 0;
//}
#include<bits/stdc++.h>
typedef struct node {
    int data[100];
    int size;
}bitree;
void create(bitree* t, int arr[], int len)
{
    t->size = len;
    for (int i = 0; i < len; i++)
    {
        t->data[i] = arr[i];
    }
}
void print(bitree* t, int index)
{
    if (index >= t->size)
        return;
    printf("%d ", t->data[index]);
    int leftindex = 2 * index + 1;
    int rightindex = 2 * index + 2;
    print(t, leftindex);
    print(t, rightindex);
}
int main()
{
    int arr[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    bitree t;
    create(&t, arr, n);
    print(&t, 0);
}