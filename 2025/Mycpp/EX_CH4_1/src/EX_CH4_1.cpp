#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/******************************************************************************
 * class Container
 ******************************************************************************/

class Container {
    string title;  // 컨테이너 타이틀
    int    size;   // 컨테이너에 저장된 정수 배열 arr의 크기
    int    *arr;   // size 개의 원소를 가진 배열 시작 주소
public:
    Container();
    ~Container();
    void newIntArray();
    void inputIntArray();
    void setTitle(string title);
    string getTitle();
    void newArray();
    void average();
    void rightRotateTitle();
    void findDeleteTitle();
};


Container::Container(): title{""},size{},arr{nullptr}{
	cout << "Container(): arr = nullptr; size = 0;"<< endl;
}
Container::~Container(){
	if(arr==nullptr)
		cout << "~Container(): " << getTitle() << endl;
	else
		cout << "~Container(): " << "arr["<<size<<"] deleted;"<<endl;
}

void Container::setTitle(string title) {
    this->title = title;
}

string Container::getTitle() {
    return title;
}

/******************************************************************************
 * Global functions
 ******************************************************************************/

void constructor() {
    Container c;
    c.setTitle("constructor-title");
    cout << "c.getTitle(): " << c.getTitle() << endl;
}

void intArray() {
    Container c;
    c.newIntArray();
    c.inputIntArray();
    c.average();
}

void Container::newIntArray(){
	cout << "element numbers of int array[]? ";
	cin >> size;
	arr = new int[size];
}

void Container::inputIntArray(){
	cout << "input " << size << " integers: ";
	for(int i=0; i<size; i++){
		cin >> arr[i];
	}
	cout << "arr["<<size<<"]:";
	for(int i=0; i<size; i++)
			cout << " " << arr[i];
	cout << endl;
}

void Container::average(){
	double sum = 0.0;
	for(int i=0; i<size; i++)
		sum += arr[i];
	sum /= size;
	cout << "average: " << sum << endl;
}

Container *newObjectArray(int size) {
    Container *pArr = nullptr; // Container 객체 배열 시작 주소
    pArr = new Container[size];
    cout << "input "<<size<<" words: ";
    string tmp;
    for(int i = 0; i < size; i++){
    	cin >> tmp;
    	pArr[i].setTitle(tmp);
    }
    return pArr;
}

void printTitles(Container *pArr, int size) {
	cout << "words:";
	for(int i=0; i<size; i++)
		cout<<" "<< pArr[i].getTitle();
	cout << endl;
}

void objectArray() {
    Container *pArr; // Container 객체 배열 시작 주소
    int size;        // Container 객체 배열 원소 개수
    cout << "element numbers of Container array[]? ";
    cin >> size;
    pArr = newObjectArray(size);
    printTitles(pArr, size);
    delete[] pArr;
}

void inputTitle(Container* cp) {
    string s;
    cout<<"input title: ";
    getline(cin, s);
    getline(cin, s);
    cp->setTitle(s);
}

void rotateTitle() {
    Container c;
    inputTitle(&c);
    cout << "c.getTitle(): " << c.getTitle() << endl;
    c.rightRotateTitle();
}

void Container::rightRotateTitle(){
	int num = title.length();
	for(int i=1; i<=num; ++i){
		string rotated = title.substr(num - i) + title.substr(0, num - i);
		cout << rotated << endl;
	}
}

void findDelete() {
    Container c;
    inputTitle(&c);      // This AAis aAA AAtest AAtitle.
    c.findDeleteTitle();
}

void Container::findDeleteTitle(){
	string Delete_word;
	cout << "word to delete? ";
	cin >> Delete_word;

	while(1){
		if(title.find(Delete_word) == string::npos)
			break;
		else{
			int index = title.find(Delete_word);
			int del_size = Delete_word.length();
			title.erase(index,del_size);
		}
	}
	cout << title << endl;
}


/******************************************************************************
 * main()
 ******************************************************************************/

string menuStr =
"******************************** Main Menu *********************************\n"
"* 0.Exit 1.constructor 2.intArray 3.objectArray 4.rotateTitle 5.findDelete *\n"
"****************************************************************************\n";

int main() {
    while (true) {
        int menuItem;
        cout << endl << menuStr << "menu? ";
        cin >> menuItem;
        if (menuItem == 0)
            break;
        switch(menuItem) {
        case 1: constructor(); break;
        case 2: intArray();    break;
        case 3: objectArray(); break;
        case 4: rotateTitle(); break;
        case 5: findDelete(); break;
        }
    }
    cout << "Good bye!!" << endl;
}
