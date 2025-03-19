//실습과제 p.75 프로그램 3.1 구조체 선언
#include <stdio.h>

typedef struct studentTag{ //구조체 선언
	char name[10];
	int age;
	double gpa;
} student; // struct studentTag -> student로 변환

int main(void){
	student a = {"kim", 20, 4.3};// 구조체 a, b 선언
	student b = {"park", 21, 4.2};

	// 구조체 출력
	printf("이름 : %s, 나이: %d, 평균평점: %f\n", a.name,a.age, a.gpa);
	printf("이름 : %s, 나이: %d, 평균평점: %f\n", b.name,b.age, b.gpa);
	return 0;
}
