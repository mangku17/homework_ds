#include <stdio.h>

void mose(char input) {
	int index = 0;
	char* mose[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.",
				"---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

	if (input >= 65 && input < 97) {
		index = input - 65; //�빮��
		printf("%s", mose[index]);
	}
	else if (input >= 97 && input < 123) {
		index = input - 97; //�ҹ���
		printf("%s", mose[index]);
	}
	else {
		printf("���ĺ��� �Է��ϼ���");
	}
}

void main() {
	char a;

	printf("���ĺ��� �Է��ϼ��� : ");
	scanf_s("%c", &a);
	//printf("%d", a);
	mose(a);
}


