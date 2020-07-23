#include <stdio.h>
#include <stdlib.h>
struct stuNode
{
	char* name; //char* name[] 안되욥,,,,,,,,,,,, char name[50]도 안되요......
	int kor;
	int eng;
	int mat;
	int sum;
	float avg;
	struct stuNode* next;
}typedef S;

void input(struct stuNode* target, int count)    // 기준 노드 뒤에 노드를 추가하는 함수
{
	struct stuNode* head = malloc(sizeof(struct stuNode)); //head 생성 _ 할당
	head->next = NULL;

	char* name = (char*)malloc(sizeof(char*)); //동적할당 _ 이름 
	int kor = 0;
	int eng = 0;
	int mat = 0;
	int sum = 0;
	int avg = 0;

	printf("%d 번째 학생의 이름 입력 :", count);
	scanf("%s", name); //포인터라서 & 안붙임
	printf("국어 성적 입력 :");
	scanf("%d", &kor);
	printf("수학 성적 입력 :");
	scanf("%d", &mat);
	printf("영어 성적 입력 :");
	scanf("%d", &eng);
	sum = kor + eng + mat;
	avg = sum / 3;

	struct stuNode* newNode = malloc(sizeof(struct stuNode));    // 새 노드 생성
	newNode->next = target->next;    // 새 노드의 다음 노드에 기준 노드의 다음 노드를 지정
	newNode->name = name;
	newNode->kor = kor;
	newNode->eng = eng;
	newNode->mat = mat;           
	newNode->sum = sum;
	newNode->avg = avg; // 데이터 저장

	target->next = newNode;    // 기준 노드의 다음 노드에 새 노드를 지정
}


void print(S* head) {
	struct stuNode* stuprint = head->next;    

	//출력
	printf("-----------------------------------------------\n");
	printf("이름\t 국어\t 영어\t 수학\t 총점\t 평균\t\n");
	printf("-----------------------------------------------\n");
	while (stuprint != NULL)               //반복 조건
	{
		printf("%s\t %d\t %d\t %d\t %d\t %.2f\n", stuprint->name, stuprint->kor, stuprint->eng, stuprint->mat, stuprint->sum, stuprint->avg);
		stuprint = stuprint->next;             // 포인터에 다음 노드의 주소 저장
	}
}



void main() {
	struct stuNode* head = malloc(sizeof(struct stuNode)); //머리노드 생성
	int menu = 0;
	int exit = 1;
	int count = 1;
	while (exit) {
		printf("[ MENU ]\n1. 성적입력\n 2. 성적확인\n 3. 종료\n");
		printf("----------------------------선택 ( 1 ~ 3 )\n");
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