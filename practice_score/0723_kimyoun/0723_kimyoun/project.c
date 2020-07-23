#include <stdio.h>
#include <stdlib.h>
struct stuNode
{
	char* name; //char* name[] �ȵǿ�,,,,,,,,,,,, char name[50]�� �ȵǿ�......
	int kor;
	int eng;
	int mat;
	int sum;
	float avg;
	struct stuNode* next;
}typedef S;

void input(struct stuNode* target, int count)    // ���� ��� �ڿ� ��带 �߰��ϴ� �Լ�
{
	struct stuNode* head = malloc(sizeof(struct stuNode)); //head ���� _ �Ҵ�
	head->next = NULL;

	char* name = (char*)malloc(sizeof(char*)); //�����Ҵ� _ �̸� 
	int kor = 0;
	int eng = 0;
	int mat = 0;
	int sum = 0;
	int avg = 0;

	printf("%d ��° �л��� �̸� �Է� :", count);
	scanf("%s", name); //�����Ͷ� & �Ⱥ���
	printf("���� ���� �Է� :");
	scanf("%d", &kor);
	printf("���� ���� �Է� :");
	scanf("%d", &mat);
	printf("���� ���� �Է� :");
	scanf("%d", &eng);
	sum = kor + eng + mat;
	avg = sum / 3;

	struct stuNode* newNode = malloc(sizeof(struct stuNode));    // �� ��� ����
	newNode->next = target->next;    // �� ����� ���� ��忡 ���� ����� ���� ��带 ����
	newNode->name = name;
	newNode->kor = kor;
	newNode->eng = eng;
	newNode->mat = mat;           
	newNode->sum = sum;
	newNode->avg = avg; // ������ ����

	target->next = newNode;    // ���� ����� ���� ��忡 �� ��带 ����
}


void print(S* head) {
	struct stuNode* stuprint = head->next;    

	//���
	printf("-----------------------------------------------\n");
	printf("�̸�\t ����\t ����\t ����\t ����\t ���\t\n");
	printf("-----------------------------------------------\n");
	while (stuprint != NULL)               //�ݺ� ����
	{
		printf("%s\t %d\t %d\t %d\t %d\t %.2f\n", stuprint->name, stuprint->kor, stuprint->eng, stuprint->mat, stuprint->sum, stuprint->avg);
		stuprint = stuprint->next;             // �����Ϳ� ���� ����� �ּ� ����
	}
}



void main() {
	struct stuNode* head = malloc(sizeof(struct stuNode)); //�Ӹ���� ����
	int menu = 0;
	int exit = 1;
	int count = 1;
	while (exit) {
		printf("[ MENU ]\n1. �����Է�\n 2. ����Ȯ��\n 3. ����\n");
		printf("----------------------------���� ( 1 ~ 3 )\n");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			input(head, count);
			count++;
			break;
		case 2:
			print(head);
			break;
		case 3:
			exit = 0;
			break;
		}
	}
}