//#include <stdio.h>
//#include <string.h>
//
//void reverseString(char* str) {
//    int length = strlen(str);
//    int start = 0;
//    int end = length - 1;
//
//    while (start < end) {
//        // �����ַ�
//        char temp = str[start];
//        str[start] = str[end];
//        str[end] = temp;
//
//        // �ƶ�ָ��
//        start++;
//        end--;
//    }
//}
//
//int main() {
//    char str[100];
//
//    printf("������һ���ַ�����");
//    fgets(str, sizeof(str), stdin);
//
//    // �Ƴ����з�
//    if (strlen(str) > 0 && str[strlen(str) - 1] == '\n') {
//        str[strlen(str) - 1] = '\0';
//    }
//
//    // ����������
//    reverseString(str);
//
//    printf("�������к���ַ���Ϊ��%s\n", str);
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