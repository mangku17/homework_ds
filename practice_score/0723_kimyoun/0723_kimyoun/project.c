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

S* tail = NULL; // ?

void input(int count)    // ���� ��� �ڿ� ��带 �߰��ϴ� �Լ�
{
    char* name = (char*)malloc(sizeof(char*)); //�����Ҵ� 
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
    printf("�̸�\t ����\t ����\t ����\t ����\t ���\t ���\n");
    printf("------------------------------------------------------\n");
    while (head->next != NULL) {
        printf("%s\t %d\t %d\t %d\t %d\t %.2f\t %d��\t \n", head->name, head->kor, head->eng, head->mat, head->sum, head->avg, rank);
        rank++;
        head = head->next;
    }
    printf("%s\t %d\t %d\t %d\t %d\t %.2f\t %d��\n\n", head->name, head->kor, head->eng, head->mat, head->sum, head->avg, rank);

}

void main() {
    int menu = 0;
    int exit = 1;
    int count = 1;
    while (exit) {
        printf("\n[ MENU ]\n1. �����Է�\n 2. ����Ȯ��\n 3. ����\n");
        printf("----------------------------���� ( 1 ~ 3 ) : ");
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