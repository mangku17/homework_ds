#include <stdio.h>
#include <stdlib.h>

void main() {
	float* arr;
	int size;
	float sum = 0;
	float avg;
	printf("�迭�� ũ�⸦ �����ϼ��� : ");
	scanf("%d", &size);

	arr = (float*)malloc(sizeof(float) * size);
	for (int i = 0; i < size; i++) {
		scanf("%f", &arr[i]);
	}
	for (int i = 0; i < size; i++) {
		sum += arr[i];
		printf("%.2f\t", arr[i]); //�Ҽ��� ��°�ڸ�
	}
	avg = sum / size;
	printf("\n�� : %.2f ��� : %.2f", sum, avg);
}


