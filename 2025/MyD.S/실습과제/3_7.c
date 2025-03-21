//실습과제 p.93 프로그램 3.7 배열을 함수의 매개변수로 사용하는 프로그램
#include <stdio.h>
#define SIZE 6

void get_integers(int list[])
{
	printf("6개의 정수를 입력하시오: ");
	for (int i = 0; i < SIZE; i++)
		scanf("%d", &list[i]);
}

int cal_sum(int list[])
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
		sum += *(list + i);
	return sum;
}

int main()
{
	int list[SIZE];
	get_integers(list);
	printf("합 = %d\n", cal_sum(list));
	return 0;
}