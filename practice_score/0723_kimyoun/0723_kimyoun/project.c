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

S* tail = NULL; // ?

void input(int count)    // 기준 노드 뒤에 노드를 추가하는 함수
{
    char* name = (char*)malloc(sizeof(char*)); //동적할당 
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

    S* newnode, * head;

    newnode = (S*)malloc(sizeof(S));
    newnode->next = NULL;
    newnode->name = name;
    newnode->kor = kor;
    newnode->eng = eng;
    newnode->mat = mat;
    newnode->sum = sum;
    newnode->avg = avg;
    head = tail;

    if (tail == NULL) {
        tail = newnode;
        return;
    }
    else if (tail->sum < newnode->sum) {
        newnode->next = tail;
        tail = newnode;
        return;
    }
    else
    {
        while (head->next != NULL) {
            if (head->next->sum < newnode->sum) {
                newnode->next = head->next;
                head->next = newnode;
                return;
            }
            head = head->next;
        }
    }
    head->next = newnode;
}

void print() {
    S* head;
    head = tail;
    int rank = 1;

    printf("------------------------------------------------------\n");
    printf("이름\t 국어\t 영어\t 수학\t 총점\t 평균\t 등수\n");
    printf("------------------------------------------------------\n");
    while (head->next != NULL) {
        printf("%s\t %d\t %d\t %d\t %d\t %.2f\t %d등\t \n", head->name, head->kor, head->eng, head->mat, head->sum, head->avg, rank);
        rank++;
        head = head->next;
    }
    printf("%s\t %d\t %d\t %d\t %d\t %.2f\t %d등\n\n", head->name, head->kor, head->eng, head->mat, head->sum, head->avg, rank);

}

void main() {
    int menu = 0;
    int exit = 1;
    int count = 1;
    while (exit) {
        printf("\n[ MENU ]\n1. 성적입력\n 2. 성적확인\n 3. 종료\n");
        printf("----------------------------선택 ( 1 ~ 3 ) : ");
        scanf("%d", &menu);
        switch (menu) {
        case 1:
            input(count);
            count++;
            break;
        case 2:
            print();
            break;
        case 3:
            exit = 0;
            break;
        }
    }
}