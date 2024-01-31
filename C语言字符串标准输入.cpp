#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char a[100];
    while (fgets(a, sizeof(a), stdin))
    {
        if (strcmp(a, "0000\n") != 0)  // 使用strcmp函数来比较字符串是否相等
            puts(a);
        else
            break;
    }

    return 0;
}