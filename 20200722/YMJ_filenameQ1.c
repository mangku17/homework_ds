#include <stdio.h>
#include <stdlib.h>

struct people{
	char* name;
	int age;
};


void main() {
	struct people p[5];
	int age = 0;
	int check = 1;

	for (int i = 0; i < 5; i++) {		
		char* name = (char*)malloc(sizeof(char*)); //�����Ҵ� 
		printf("�̸� : ");
		scanf("%s", name);
		printf("���� : ");
		scanf("%d", &age);
		p[i].name = name;
		p[i].age = age;
	}

	while (check) { //��������
		check = 0;
		for (int i = 0; i < 4; i++) {
			if (p[i].age < p[i + 1].age) {
				struct people temp = p[i + 1];
				p[i + 1] = p[i];
				p[i] = temp;
				check = 1;
			}
		}
	}
	printf("[���̰� � ���] %s�� %d��\n", p[4].name, p[4].age);
}


