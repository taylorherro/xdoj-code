#include<bits/stdc++.h>
typedef struct LinkList {
    int num;
    LinkList* next;
}LinkList;

LinkList* creatList(int cnt) {
    LinkList* head, * s, * r;
    head = (LinkList*)malloc(sizeof(LinkList));		//����ͷ�ڵ�head 
    r = head;	//βָ��ָ��ͷ�ڵ� 
    for (int i = 0; i < cnt; i++) {
        s = (LinkList*)malloc(sizeof(LinkList));		//�����½ڵ�*s 
        scanf("%d", &s->num);
        r->next = s;	//�½ڵ�����β 
        r = s;			//βָ��ָ���±�β 
    }
    r->next = NULL;
    return head;		//���ر�ͷָ�� 
}

void reversal(LinkList* L) {
    LinkList* p = L->next;
    LinkList* r = p->next;
    //ָ����� 
    while (p->next != NULL) {
        p->next = r->next;
        r->next = L->next;
        L->next = r;
        r = p->next;
    }
    //    LinkList *p =  NULL
    //    LinkList *cur = L; 
    //	  while(cur) {
    //		LinkList *r = cur->next;
    //		//��curͷ�嵽������
    //        cur->next = p;
    //        p = cur;
    //        cur = r;
    //	}
}

void print(LinkList* L) {	//����������,������ 
    LinkList* p;
    p = L;
    while (p != NULL) {
        if (p->next) {
            printf("%d ", p->next->num);
        }
        p = p->next;
    }
}

int main()
{
    int i, j;
    int cnt = 0;
    scanf("%d", &j);
    LinkList* L[10];
    for (i = 0; i < j; i++) {		//����ѭ�����д�������
        scanf("%d", &cnt);
        L[i] = creatList(cnt);
        reversal(L[i]); 	//����ԭ������λ�ý��з�ת����洢 
    }
    for (i = 0; i < j; i++)
    {
        print(L[i]);
        if (i != j - 1)
            printf("\n");
    }
    return 0;
}