// 아래에 class alu를 작성해서
// main 함수에서 +, -, * 계산이 가능하게 하라
// 멤버 변수인 r1, r2는 unsigned int, oper은 char이다
// ------------------------------------------------

#include <iostream>
using namespace std;

//여기에 클래스 코드 작성할 것
class alu{
	int r1,r2;
	char oper;

public:
	alu();
	void calc();
	
	alu::alu(): r1{1}, r2{3}, oper{"+"}{
			cout << r1 << oper << r2 << endl;
	}


	int main() {
	    alu machine; //생성자 구현하여 아래 출력 결과 1*3처럼 출력되게 각 멤버를 초기화 시킬 것
	    cin >> machine.r1;
	    cout << machine.r1;
	}
};

