//#include <stdio.h>
//#include <string.h>
//
//void reverseString(char* str) {
//    int length = strlen(str);
//    int start = 0;
//    int end = length - 1;
//
//    while (start < end) {
//        // ½»»»×Ö·û
//        char temp = str[start];
//        str[start] = str[end];
//        str[end] = temp;
//
//        // ÒÆ¶¯Ö¸Õë
//        start++;
//        end--;
//    }
//}
//
//int main() {
//    char str[100];
//
//    printf("ÇëÊäÈëÒ»´®×Ö·û´®£º");
//    fgets(str, sizeof(str), stdin);
//
//    // ÒÆ³ı»»ĞĞ·û
//    if (strlen(str) > 0 && str[strlen(str) - 1] == '\n') {
//        str[strlen(str) - 1] = '\0';
//    }
//
//    // µ÷ÓÃÄæĞòº¯Êı
//    reverseString(str);
//
//    printf("ÄæĞòÅÅÁĞºóµÄ×Ö·û´®Îª£º%s\n", str);
//
//    return 0;
//}
#include<bits/stdc++.h>
void reverse(char arr[])
{
	int start = 0;
	int end = strlen(arr) - 1;
	while (start < end)
	{
		char temp;
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
int main()
{
	char arr[100];
	fgets(arr, sizeof(arr), stdin);
	if (strlen(arr) > 0 && arr[strlen(arr) - 1] == '\n')
		arr[strlen(arr) - 1] = '\0';
	reverse(arr);
	printf("%s", arr);
}