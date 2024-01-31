#include<stdio.h>
#include<math.h> 
#include<stdlib.h>
#include<string.h>
#ifndef TREE__STACK_H_INCLUDED
#define TREE__STACK_H_INCLUDED
#endif // TREE__STACK_H_INCLUDED

typedef struct BiTNode{
    char data;  //���ֵ
    int value;  //����ֵ
    struct BiTNode *lchild,*rchild; //���Һ��ӽ��ָ��
}*BiTree;

typedef struct {
    BiTree *top;
    BiTree *base;
}BiTStack;

int InitStack(BiTStack &S){
    //����ջ��Ŷ������ڵ�
    S.base=(BiTree*)malloc(sizeof(BiTNode));
    S.top=S.base;
    return 0;
}

int Push(BiTStack &S, BiTree &B){
    //�������ڵ���ջ
    *S.top=B;
    S.top++;
    return 0;
}

int Pop(BiTStack &S,BiTree &B){
    //�������ڵ��ջ
    S.top--;
    B=*S.top;
    return 0;
}

BiTree Gettop(BiTStack S){  //����ջ��Ԫ��
    return *(S.top-1);
}

int CorrectNot(char a[]){
    //���ر��ʽ�Ƿ�Ϸ�
    int i = 0;
    int flag = 0;
    int cnt1=0;
    int cnt2=0;
    while(a[i]!='\0'){
        if(a[i]=='(') cnt1++;
        if(a[i]==')') cnt2++;
        if(!(a[i]==' ' ||
             a[i]=='~' ||
             a[i]=='|' ||
             a[i]=='&' ||
             a[i]=='(' ||
             a[i]== ')'||
             (a[i]>='A' && a[i]<='Z')||(a[i]>='0' && a[i]<='1'))) {flag = 1; break;}  //�����������������
        if(cnt2 > cnt1) {flag = 1; break;}  //���Ų�ƥ��
        if(a[i]!=' ' && i !=0){
            int l,r;
            l = i-1;
            r = i+1;
            while(a[l]==' '){l--;}
            while(a[r]==' '){r++;}
            if(a[i]=='~' || a[i]=='|' || a[i]=='&'){
                if(!(a[r]=='~' || a[r]=='(' || (a[r]>='A' && a[r]<='Z')||(a[r]>='0' && a[r]<='1'))) {flag = 1;break;}  
//�������������߲������źͷ�
                if(a[i]!='~'){
                    if(!(a[l]==')'|| (a[l]>='A' && a[l]<='Z')||(a[l]>='0' && a[l]<='1'))) {flag = 1;break;}  
//����ǰ�治�������Ż���������
                }
                if(a[i]=='~'){
                    if((a[l]==')'|| (a[l]>='A' && a[l]<='Z')||(a[l]>='0' && a[l]<='1'))) {flag = 1;break;}  
//�����Ÿ��ǻ�������������
                }
            }
            if((a[i]>='A' && a[i]<='Z')||(a[i]>='0' && a[i]<='1')){
                if((a[r]>='A' && a[r]<='Z')|| (a[l]>='A' && a[l]<='Z')||(a[r]>='0' && a[r]<='1')||(a[l]>='0' && a[l]<='1')){flag=1; break;} //��������������
            }
        }
        i++;
    }
    if(cnt1 != cnt2) flag = 1; //���Ų�ƥ��
    return flag;
}

int In(char c){
    //�ж��ַ��Ƿ�Ϊ�����
    char OP[7] = {'|','&','~','(',')','#','\0'};
    int flag = 0;
    int i = 0;
    while(OP[i] != '\0'){
        if(OP[i] == c) flag=1;
        i++;
    }
    return flag;
}

char Precede(char c1, char c2){
    //�ж��߼�����������ȼ�
    char OP[7] = {'|','&','~','(',')','#','\0'};
    unsigned char Prior[7][7] =
    {'x','|','&','~','(',')','#',
     '|','>','<','<','<','>','>',
     '&','>','<','<','<','>','>',
     '~','>','>','>','<','>','>',
     '(','<','<','<','<','=',' ',
     ')','>','>','>','>','>','>',
     '#','<','<','<','<',' ','='
    };
    int i = 0; int j = 0;
    while(c1 != OP[i]) i++;
    while(c2 != OP[j]) j++;
    return Prior[i+1][j+1];
}

int CreatBiTree(BiTree &B, char *a){
    //���ݱ��ʽa���������
    char *expr;
    char End[] = {'#','\0'};
    expr = strcat(a,End);
    BiTStack OPTR, OPND;
    InitStack(OPTR); //�����ջ
    InitStack(OPND);//������ջ
    BiTree b1,b,x,y,theta;
    b1 = (BiTree)malloc(sizeof(BiTNode));
    b1->data = '#';
    b1->value = 0;
    b1->lchild = NULL;
    b1->rchild = NULL;
    Push(OPTR, b1);
    while(*expr !='#'||Gettop(OPTR)->data!='#'){
        if(*expr ==' '){
            expr++;
            continue;
        }
        b = (BiTree)malloc(sizeof(BiTNode));
        b->data = *expr;
        b->value = 0;
        b->lchild = NULL;
        b->rchild = NULL;
        if(!In(*expr)){
            Push(OPND, b);
            expr++;
            continue;
        }else {
            switch(Precede(Gettop(OPTR)->data, *expr)){
                case '<':
                    Push(OPTR,b);
                    expr++;
                    break;
                case '=':
                    Pop(OPTR, b);
                    expr++;
                    break;
                case '>':
                    Pop(OPTR, theta);
                    Pop(OPND, x);
                    theta->rchild = x;
                    if(theta->data != '~'){
                        Pop(OPND, y);
                        theta->lchild = y;
                    }
                    Push(OPND,theta);
            }
        }
    }
    B=Gettop(OPND);
    return 1;
}

int Getvar(char *a,char *ch){
    //���ر��ʽ�в�ͬ�ı��������ͱ���ch
    int i=0,k=0,flag=1;
    while(a[i]){
        if(a[i]>='A' && a[i]<='Z'){
            int j=0;
            while(ch[j]!='\0'){
                if(ch[j]==a[i]){flag=0; break;}
                j++;
            }
            if(flag){ch[k]=a[i]; k++;}
        }
        i++;
        flag=1;
    }
    return k;
}

int AssignValue(BiTree B,char c,int value){
    // ���������������ΪdataΪc��0��1�Ľڵ㸳ֵvalue��0��1��
    if(B){
        if(B->data==c) B->value=value;
        if(B->data=='1') B->value=1;
        if(B->data=='0') B->value=0;
        AssignValue(B->lchild, c, value);
        AssignValue(B->rchild, c, value);
    }
    return 1;
}

int Calculate(BiTree B){
    // ���������������������ʽ��ֵ
    if(B){
        Calculate(B->lchild);
        Calculate(B->rchild);
        switch(B->data){
            case '|':
                B->value = B->lchild->value||B->rchild->value;
                break;
            case '&':
                B->value = B->lchild->value&&B->rchild->value;
                break;
            case '~':
                B->value = !B->rchild->value;
                break;
        }
    }
    return 1;
}

int Num2Bin(int *b,int x,int len){
    // ����b��������x�Ķ����Ʊ�ʾ
    while(x!=0){
        b[len]=(x%2);
        x=x/2;
        len--;
    }
    return 1;
}

int Evaluate(BiTree B, int blmun, char *c, int *res){
    //�������������ֵ
    int comb[20];
    int i,j,k;
    int num;
    num = pow(2,double(blmun));
    for(k=0; k<num; k++){
        for(i=0; i<blmun; i++){
            comb[i] = 0;
        }
        Num2Bin(comb, k, blmun-1);
        for(j=0; j<blmun; j++){
            AssignValue(B, c[j], comb[j]);
        }
        Calculate(B);
        res[k] = B->value;
    }
    return 1;
}

char Judge(int *res){
    //������ֵ���жϱ��ʽΪ����ʽ��ì��ʽ�������ʽ
    int i=0,flag1=0,flag2=0;
    while(res[i] != -1){
        if(res[i] == 0) flag1=1;
        if(res[i] == 1) flag2=1;
        if(flag1 && flag2) return 'S';
        i++;
    }
    if(flag1) return 'F';
    if(flag2) return 'T';
}

void showoff(char x){
    //��ʾ�жϽ��
    switch(x){
            case 'T':
                printf("�ñ��ʽ������ʽ\n");
                break;
            case 'F':
                printf("�ñ��ʽ��ì��ʽ\n");
                break;
            case 'S':
                printf("�ñ��ʽ�ǿ�����ʽ\n");
                break;
        }
}

