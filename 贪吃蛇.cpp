#include<bits/stdc++.h>
void welcome();  //��ӭ���� 
void border();  //�����߽� 
void Pos(int x, int y);  //�ı����̨���λ�� 
void getRandomPos(int* x, int* y);  //��ȡ�������
void initSnake();  //�ߵĳ�ʼ��
void createFood();  //����ʳ��
int inSnake(int x, int y);  //�ж�(x, y)�Ƿ������ϣ�1��ʾ�ڣ�0��ʾ���� 
void snakeMove();  //�ߵ��ƶ� 
int getDirection();  //��ȡ�ƶ�����0��1��2��3�ֱ�����ϡ��¡����� 

typedef struct Node {
	int x;
	int y;
	Node* next;
}node;

//ȫ�ֱ���
node* head;  //��ͷ
node food;  //ʳ�� 
int reCreateFood;  //�ж�ʳ���Ƿ񱻳Ե�
int fail;  //�����ͷ���������߽���ʧ�� 
int score, add = 10;  //���������ÿ��ʳ��ķ��� 
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };  //(dx[0], dy[0])Ϊ(0, 1)���������ϡ�
int d = -1;  //��ʾ��ǰ���ķ�������һ�ж�Ӧ��0Ϊ�ϣ�1Ϊ�£�2Ϊ��3Ϊ��
//����ʱ��ʼ��Ϊ-1����ʾ��δ������� 

int main() {
	welcome();  //��ӭ���� 
	border();  //�����߽� 
	initSnake();  //�ߵĳ�ʼ�� 
	createFood();  //����ʳ�� 

	//fail ��= 0��һֱ���� 
	while (1) {
		if (fail) break;
		//ʳ�ﱻ�Ե���Ҫ�������� 
		if (reCreateFood) {
			createFood();
			reCreateFood = 0;
		}
		snakeMove();  //�ߵ��ƶ� 
		Sleep(500);  //������ͣ500���룬ע�͵�����һ�¾Ͷ���
		//��ȡ�µķ��� 
		d = getDirection();
	}

	//���Ҳ��ע�͵��Ա�һ�¾Ͷ��� 
	Pos(0, 24);
	printf("\n");

	return 0;
}

void welcome() {
	system("mode con cols=100 lines=30");
	system("cls");

	Pos(38, 6);
	printf("welcome come to SnakeGame\n");
	Pos(38, 8);
	printf("��������control direction\n");
	Pos(45, 10);
	printf("ESC For Exit\n");
	Pos(42, 12);
	printf("Enter For Begin\n");
	getchar();
	system("cls");
}

void border() {  //������(0, 0), (59�� 25)Ϊ����ľ��α߽�
	for (int i = 0; i < 60; i++) {
		Pos(i, 0);  //���� 
		printf("�~");
		Pos(i, 25);  //���� 
		printf("�~");
	}

	for (int i = 1; i < 25; i++) {
		Pos(0, i);  //���� 
		printf("�~");
		Pos(59, i);  //���� 
		printf("�~");
	}
}

void Pos(int x, int y) {
	COORD pos;  //λ������ 
	pos.X = x;
	pos.Y = y;

	HANDLE handleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  //��ȡ������ 
	SetConsoleCursorPosition(handleOutput, pos);   //��λ 
}

void getRandomPos(int* x, int* y) {
	srand((unsigned int)time(NULL));
	*x = rand() % 58 + 1;
	*y = rand() % 24 + 1;
}

void initSnake() {
	head = (node*)malloc(sizeof(node));
	//��֤�ڱ߽���
	head->x = rand() % 58 + 1;
	head->y = rand() % 24 + 1;
	head->next = NULL;

	Pos(head->x, head->y);
	printf("*");
}

void createFood() {
	int x, y;
	getRandomPos(&x, &y);
	if (inSnake(x, y)) createFood();  //��������
	food.x = x;
	food.y = y;
	Pos(x, y);
	printf("$");
}

int inSnake(int x, int y) {
	node* p = head->next;
	while (p) {  //��ͷ�������� 
		if (x == p->x && y == p->y)
			return 1;
		p = p->next;
	}
	return 0;
}

void snakeMove() {
	//�տ���δ������������ 
	if (d == -1)
		while (d == -1) d = getDirection();

	node* newHead = (node*)malloc(sizeof(node));
	newHead->x = head->x + dx[d];
	newHead->y = head->y + dy[d];
	newHead->next = head;
	head = newHead;

	node* p = head;
	if (inSnake(p->x, p->y) || (p->x == 0 || p->x == 59 || p->y == 0 || p->y == 25))
		fail = 1;
	else if (p->x != food.x || p->y != food.y) {
		Pos(p->x, p->y);
		printf("*");

		while (p->next->next) p = p->next;
		Pos(p->next->x, p->next->y);
		printf(" ");
		p->next = NULL;
	}
	else {
		reCreateFood = 1;
		score += add;
		Pos(p->x, p->y);
		printf("*");
	}
	Pos(61, 25);
	printf("���ĵ÷�Ϊ��%d", score);
}

int getDirection() {
	//�������������� 
	if ((GetAsyncKeyState(VK_UP) & 0x8000) && d != 1) d = 0;
	else if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && d != 0) d = 1;
	else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && d != 3) d = 2;
	else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && d != 2) d = 3;
	return d;
}
