#include <stdio.h>
#include <stdlib.h>

struct List{
	char data;
	struct List *next;
};

typedef struct List node;

node *head, *tail; //연결리스트의 시작 노드 , 끝노드

void initLinkedList(void){//연결리스트를 초기화 하는 함수
	head=(node*)malloc(sizeof(node)); //동적메모리 할당 후 head에 연결
	tail=(node*)malloc(sizeof(node));
	tail->next=NULL;
	head->next=tail;
	printf("연결 리스트가 초기화 되었습니다.\n");
}
void insertNode(char inputData){
	node *newNode=(node*)malloc(sizeof(node));
	node *p;
	p=head;
	while(p->next!=tail){
		p=p->next;
	}
	newNode->data=inputData;
	newNode->next=tail;
	p->next=newNode;
}
void printLinkedList(void){
	node *p;
	printf("Linked List의 출력\n");
	p=head->next;
	while(p!=tail){
		printf("%-3c", p->data);
		p=p->next;
	}
	printf("\n");
}
void deleteHeadNextNode(void){
	node *deleteNode=head->next;
	if(deleteNode==tail){
		printf("삭제할 노드가 없습니다.");
		return;
	}
	head->next=deleteNode->next;
	free(deleteNode);
}

node *searchNode(char searchData){
    node *p= head->next;
    if(p==tail){
       printf("비어있는 연결리스트\n");
       return;
    }
    printf("searchNode('%c')\n", searchData);

    while(p->data!=searchData && p->next!=NULL){
      p=p->next;
    }
    return p;
}

int main(){
	node *resultNode;
	initLinkedList();
	insertNode('A');
	insertNode('B');
	insertNode('C');
	printLinkedList();
	deleteHeadNextNode(); //head의 다음 노드 삭제
	printLinkedList(); // B C
        resultNode=searchNode('B');
        if(resultNode->next!=NULL)
          printf("연결리스트에 노드가 존재합니다.\n");
  	else
	  printf("연결리스트에 노드가 존재하않스빈다");
	return 0;
}

