#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

/*dynamic stack ,
pBottom points to the head node(dummy node)
pTop points to the top node
At the beginning , the pBottom and pTop should point to the head node.

*/
#define bool char
#define true 1
#define false 0

typedef struct Node {
	int data;
	struct Node * next;
} Node, *PNode;

typedef struct stack {
	PNode pTop;
	PNode pBottom;
	
}Stack, *PStack;


PNode create_node(int val) {
	PNode p = (PNode)malloc(sizeof(Node));
	if (p == NULL) {
		printf("fail to create a node!");
		exit(-1);
	}
	p->data = val;
	p->next = NULL;

	return p;
}

void initStack(PStack stk){
	PNode head = (PNode)malloc(sizeof(Node));
	if (head == NULL) {
		printf("initiation fail!");
		return;
	}

	head->next = NULL;
	
	stk->pTop = head;
	stk->pBottom = head;
	
	return;
}

void pushStack(PStack stk,int val) {

	PNode element = create_node(val);
	element->next = stk->pTop;
	stk->pTop = element;
	return ;
}

int is_empty(PStack stk) {

	return (stk->pTop == stk->pBottom);

}

bool popStack(PStack stk, int * val) {

	if (is_empty(stk)) {
		printf("no value to pop");
		return false;
	}
	PNode popped = stk->pTop;
	*val = popped->data;
	stk->pTop = popped->next;
	free(popped);
	popped= NULL;

	return true;

}


void traverse(PStack stk) {

	if (is_empty(stk)){
		printf("empty stack");
		return;
	}

	PNode p = stk->pTop;
	while (p!= stk->pBottom) {
		printf("%d", p->data);
		printf("\n");
		p = p->next;
	}
	return;
}

void resetStack(PStack stk) {

	if (is_empty(stk)) {
		return;
	}

	while (stk->pTop != stk->pBottom) {
		
		PNode temp = stk->pTop;
		stk->pTop = stk->pTop->next;
		free(temp);
		temp = NULL;
	}
	return;
}

int main() {

	Stack stk;
	int val;
	initStack(&stk);
	pushStack(&stk, 1);
	pushStack(&stk, 10);
	pushStack(&stk, 5);
	pushStack(&stk, 12);
	traverse(&stk);

	if (popStack(&stk, &val)) {
		printf("poped number is %d", val);
		printf("\n");
	}
	else {
		printf("failed");
	}

	traverse(&stk);
	resetStack(&stk);
	traverse(&stk);

	return 0;
}
