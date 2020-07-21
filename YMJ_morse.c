#include <stdio.h>

void mose(char input) {
	int index = 0;
	char* mose[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.",
				"---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

	if (input >= 65 && input < 97) {
		index = input - 65; //대문자
		printf("%s", mose[index]);
	}
	else if (input >= 97 && input < 123) {
		index = input - 97; //소문자
		printf("%s", mose[index]);
	}
	else {
		printf("알파벳을 입력하세요");
	}
}

void main() {
	char a;

	printf("알파벳을 입력하세요 : ");
	scanf_s("%c", &a);
	//printf("%d", a);
	mose(a);
}


