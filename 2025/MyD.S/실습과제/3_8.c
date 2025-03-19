//실습과제 p.96 프로그램 3.8 동적 메모리 할당의 예
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SIZE 10

int main()
{
	int *p;

	p = (int *)malloc(SIZE * sizeof(int));
	if (p == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}

	for (int i = 0; i < SIZE; i++)
		p[i] = i;

	for (int i = 0; i < SIZE; i++)
		printf("%d ", p[i]);

	free(p);
	return 0;
}