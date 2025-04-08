/******************************************************************************
 * 코드 추가 1
 ******************************************************************************/
// 1) 메뉴 [File]->[New]->[C/C++ Project] 한 후 새로운 프로젝트 CH5을 만들어라.
// 2) 메뉴 [File]->[New]->[Source Folder] 한 후 폴더 이름으로 src를 지정하여 생성하라.
// 3) 메뉴 [File]->[New]->[Source File]   한 후 폴더 이름으로는 위에서 지정한 CH5/src로
//    설정하고 파일 이름으로 ch5.cpp를 지정하여 소스파일을 만들어라.
// 4) 아래 코드를 소스파일로 복사하라.
//-----------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

/******************************************************************************
 * Person Container
 ******************************************************************************/

class Container {
    string title;  // 컨테이너 타이틀
    int    size;   // 컨테이너에 저장된 정수 배열 arr의 크기
    int    *arr;   // size 개의 원소를 가진 배열 시작 주소
public:
    Container();
    Container(string title);
    Container(string title, int size);
    Container(const Container&);
    ~Container();

    void setTitle(string title);
    string getTitle();
    void printIntArray();
    Container& newIntArray();
    Container& inputIntArray();
    void inputTitle(Container);
};

Container::Container():Container("no-title"){ }

Container::Container(string title):Container(title,0){}

Container::Container(string title, int size) {
    this -> title = title;
	this->size = size;

    if(size>0)
    	arr = new int[size];
    else
    	arr = nullptr;
    for(int i = 0; i<size; i++)
    	arr[i] = 0;
    cout << "Container(): "; printIntArray();
}
Container::Container(const Container& tmp){
	this -> title = tmp.title;
	this -> size = tmp.size;
	this -> arr = new int[size];
	for(int i=0; i<size; i++)
		this->arr[i] = tmp.arr[i];
	cout << "Container(Container& c): "; printIntArray();
}

Container::~Container() {
    cout << "~Container(): "; printIntArray();
    if (arr != nullptr)
        delete [] arr;
}

void Container::setTitle(string title) {
    this->title = title;
}

string Container::getTitle() {
    return title;
}

void Container::printIntArray() {
    cout << title << ": arr[" << size << "]: ";
    for (int i = 0; i < size; ++i)
    	cout << arr[i] << " ";
    cout << endl;
}

Container& Container::newIntArray() {
    if (arr != nullptr)
        delete [] arr;
    cout << "element numbers of int array[]? ";
    cin >> size;
    arr = new int[size];
    return *this;
}

Container& Container::inputIntArray() {
    cout << "input " << size << " integers: ";
    for (int i = 0; i < size; ++i)
        cin >> arr[i];
	return *this;
}

void inputTitle(Container& d){
	string tmp;
	cout << "input title: ";
	getline(cin, tmp);
	d.setTitle(tmp);

}

/******************************************************************************
 * Global functions
 ******************************************************************************/

void skipEnter() {
    string s;
    getline(cin, s); // 메뉴항목 번호 뒤의 [엔터]를 제거함
}

void refParam() {
    Container c("C", 3);
    Container b("B");
    Container a;
    Container d;
	skipEnter();
	inputTitle(d);
}

Container& changeTitle(Container& rc) {
    string s;
    cout << "title to change: ";
    getline(cin, s);
    rc.setTitle(s);
    return rc;       // rc의 원본 객체의 참조를 리턴함
}

void refRet1() {
	skipEnter();
	Container c("C");
	Container& rc = changeTitle(c); // rc는 원본 객체 c의 데이타를 공유하는 참조변수임
	cout << " c.getTitle(): " <<  c.getTitle() << endl;
	cout << "rc.getTitle(): " << rc.getTitle() << endl;
	cout << "---" << endl;
	cout << "appendTitle(c).getTitle(): " << changeTitle(rc).getTitle() << endl;
	cout << "             c.getTitle(): " <<               c.getTitle() << endl;
	cout << "            rc.getTitle(): " <<              rc.getTitle() << endl;
	// changeTitle(rc)에 의해 반환되는 참조 역시 원본 객체 c의 데이타를 공유하는 참조변수임
	// 참조 변수는 생성자 및 소멸자가 없다. 원본 객체의 데이터를 공유하는 또 다른 변수 이름일 뿐이다.
}

void refRet2() {
	Container c("C");
	c.newIntArray().inputIntArray().printIntArray();
}

void explicitCopy() {
    Container c1("c1", 4);
    c1.inputIntArray().printIntArray();
    cout << "---" << endl;
    Container c2(c1);
    c2.setTitle("c2");
    c2.printIntArray();
    cout << "---" << endl;
    c2.inputIntArray().printIntArray();
    c1.printIntArray();
}

void callByValue(Container v) {
    cout << "callByValue" << endl;
    v.setTitle("V");
    v.inputIntArray().printIntArray();
}

Container returnValue(Container& r) {
    cout << "returnValue" << endl;
    return r;  // 자동으로 복사생성자 호출
}

void implicitCopy() {
    Container a("A", 2);
    a.inputIntArray().printIntArray();
    cout << "---" << endl;
    Container b = a; // 자동으로 복사생성자 호출
    b.setTitle("B");
    b.inputIntArray().printIntArray();
    cout << "---" << endl;
    callByValue(a); // 자동으로 복사생성자 호출
    cout << "---" << endl;
    Container c = returnValue(a);
    c.setTitle("C");
	c.inputIntArray().printIntArray();
	cout << "---" << endl;
}

string menuStr =
"****************************** Main Menu ******************************\n"
"* 0.Exit 1.refParam 2.refRet1 3.refRet2 4.explicitCopy 5.implicitCopy *\n"
"***********************************************************************\n";

int main() {
    while (true) {
        int menuItem;
        cout << endl << menuStr << "menu? ";
        cin >> menuItem;
        if (menuItem == 0)
            break;
        switch(menuItem) {
        case 1: refParam();     break;
        case 2: refRet1();      break;
        case 3: refRet2();      break;
        case 4: explicitCopy(); break;
        case 5: implicitCopy(); break;
        }
    }
    cout << "Good bye!!" << endl;
}
