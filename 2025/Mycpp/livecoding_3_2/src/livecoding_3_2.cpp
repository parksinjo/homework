/*
키보드에서 원의 개수를 입력받고, 그 개수만큼 원의 반지름을 입력받아,
다음과 같은 출력결과와 같이 실행되도록  Circle클래스를 완성하고 main()함수를 작성하시오

**************************************************************************
[입출력형식1]
원의 개수 >> 3
원 1의 반지름 >> 10
원 2의 반지름 >> 2
원 3의 반지름 >> 1
면적이 100보다 큰 원은 1개 입니다

[입출력형식2]
원의 개수 >> 5
원 1의 반지름 >> 10
원 2의 반지름 >> 8
원 3의 반지름 >> 4
원 4의 반지름 >> 2
원 5의 반지름 >> 1
면적이 100보다 큰 원은 2개 입니다
***************************************************************************
*/


#include <iostream>
using namespace std;

class Circle {
	int radius; // 원의 반지름 값
public:
	void setRadius(int radius); // 반지름을 설정한다.
	double getArea(); // 면적을 리턴한다.
};
void Circle::setRadius(int radius) {
	this->radius = radius;
}
double Circle::getArea() {
	return radius*radius*3.14;
}
int main() {
	int num,r,count = 0;
	cout << "원의 개수 >> ";
	cin >> num;
	Circle* p = new Circle[num];
	for(int i=0; i<num; i++){
		cout<< "원 "<<i+1<<"의 반지름 >> ";
		cin >> r;
		p[i].setRadius(r);
		if(p[i].getArea()>100) count++;
	}
	cout << "면적이 100보다 큰 원은 "<<count<<"개 입니다";
	delete[] p; // 객체 배열 소멸
}
