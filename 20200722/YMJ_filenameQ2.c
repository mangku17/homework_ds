#include <stdio.h>
#include <stdlib.h>

void main() {
	float* arr;
	int size;
	float sum = 0;
	float avg;
	printf("배열의 크기를 지정하세요 : ");
	scanf("%d", &size);

	arr = (float*)malloc(sizeof(float) * size);
	for (int i = 0; i < size; i++) {
		scanf("%f", &arr[i]);
	}
	for (int i = 0; i < size; i++) {
		sum += arr[i];
		printf("%.2f\t", arr[i]); //소수점 둘째자리
	}
	avg = sum / size;
	printf("\n합 : %.2f 평균 : %.2f", sum, avg);
}


