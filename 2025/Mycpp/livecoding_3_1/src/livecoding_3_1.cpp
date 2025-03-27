/*
이름, 학과, 학번을 멤버변수로 가지는 Student 클래스를 작성하고, 다음 실행예시와 같은 결과가 나오도록 프로그램을 완성하시오

- 멤버변수는 private( s_name, s_dept, s_id)
- 기본생성자, 매개변수를 갖는 생성자, 소멸자 작성
- 멤버변수는 이름 : “김조선”,　전공: “컴퓨터공학과”, 학번: 11111111 으로 초기화
- 멤버함수
  -- 학생정보를 출력하는 showInfo()함수
  -- s_id를 리턴하는 getId()함수
  -- c++,파이썬, 자바점수를 입력받아 평균을 계산하여 리턴하는 calScore()함수

*******************************[ 실행결과 ]**************************************

id: 11111111 학생객체 생성
학과: 컴퓨터공학과, 학번: 11111111, 이름: 김조선
c++, 파이썬, 자바 점수를 입력하시오>> 90 80 70
학번 11111111의 세 과목 평균점수는 80입니다
이름, 학과, 학번을 입력하시오>> 홍길동 정보통신과 22222222
id: 22222222 학생객체 생성
학과: 정보통신과, 학번: 22222222, 이름: 홍길동
c++, 파이썬, 자바 점수를 입력하시오>> 88 99 77
학번 22222222의 세 과목 평균점수는 88입니다
id: 22222222 학생객체 소멸
id: 11111111 학생객체 소멸

**********************************************************************************
*/



#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Student{
private:
	string s_name, s_dept;
	int s_id;

public:
	Student();
	Student(string,string,int);
	~Student();
	void showInfo();
	int getId();
	double calScore();
};

Student::Student():s_name{"김조선"},s_dept{"컴퓨터공학과"},s_id{11111111}{
	cout << "id: " << s_id <<" 학생객체 생성"<<endl;
}
Student::Student(string name,string dept, int id){
	s_name = name;
	s_dept = dept;
	s_id = id;
	cout << "id: " << s_id <<" 학생객체 생성"<<endl;
}
Student::~Student(){
	cout << "id: " << s_id <<" 학생객체 소멸"<<endl;
}
void Student::showInfo(){
		cout << "학과: "<<s_dept<<", 학번: "<<s_id<<", 이름: "<<s_name<<endl;
}
int Student::getId(){
	return s_id;
}
double Student::calScore(){
	int a,b,c,sum;
	cout<< "c++, 파이썬, 자바 점수를 입력하시오>> ";
	cin >> a >> b >> c;
	sum = a+b+c;
	return (double)sum/3.0;
}
// 아래 main부분 수정할수 없음

int main() {
    string name, major;
    int id;
    double score;

    //기본생성자 호출하여 객체 생성
    Student s1;

    s1.showInfo();
    score = s1.calScore();
    cout << "학번 " << s1.getId() << "의 세 과목 평균점수는 " << score << "입니다" << endl;

    //이름,학과, 학번을 입력받아, 매개변수 있는 생성자 호출하여 객체 생성
    cout << "이름, 학과, 학번을 입력하시오>> ";
    cin >> name >> major >> id;
    Student s2(name, major, id);
    s2.showInfo();
    score = s2.calScore();
    cout << "학번 " << s2.getId() << "의 세 과목 평균점수는 " << score << "입니다" << endl;
}
