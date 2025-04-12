#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[100];
}element;

typedef struct {
	element data;
	struct ListNode* link;
}ListNode;

void error(char* message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value){
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head){
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL \n");
}

int main(){
	printf("//Lab1 단어들을 저장하는 연결리스트 결과값\n");
	ListNode* head = NULL;
	element data;

	strcpy_s(data.name, sizeof(data.name), "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy_s(data.name, sizeof(data.name), "KIWI");
	head = insert_first(head, data);
	print_list(head);

	strcpy_s(data.name, sizeof(data.name), "BANANA");
	head = insert_first(head, data);
	print_list(head);
	return 0;
}