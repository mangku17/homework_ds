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
		char* name = (char*)malloc(sizeof(char*)); //동적할당 
		printf("이름 : ");
		scanf("%s", name);
		printf("나이 : ");
		scanf("%d", &age);
		p[i].name = name;
		p[i].age = age;
	}

	while (check) { //버블정렬
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
	printf("[나이가 어린 사람] %s님 %d살\n", p[4].name, p[4].age);
}


