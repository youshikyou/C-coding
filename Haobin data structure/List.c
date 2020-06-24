#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


#define bool char
#define true 1
#define false 0


typedef struct Node {
	int data;
	struct Node * next;
}NODE, *PNODE; //NODE is struct Node , PNODE is  struct Node*

PNODE create_list(void);

void traverse_list(PNODE phead);

bool is_empty(PNODE phead) {
	if (phead->next == NULL) {
		return true;
	}
	return false;
}

int length_list(PNODE phead) {

	PNODE p = phead->next;

	int len = 0;
	while (p != NULL) {
		len++;
		p = p->next;
	}

	return len;
}

bool insert_list(PNODE phead, int d, int position);

bool delete_list(PNODE phead, int position,int * pval);

void sort_list(PNODE);

int main() {

	int val;
	PNODE phead = NULL;
	phead = create_list(); 
	//sort_list(phead);
	traverse_list(phead);
	if (delete_list(phead, 4, &val)) {
		printf("delete OK! The deleted node value is %d", val);
	}
	printf("\n");
	traverse_list(phead);

	return 0;
}

PNODE create_list(void) {

	int len;
	int i = 0;
	int val;
	printf("input the list length: ");
	scanf_s("%d", &len);
	PNODE phead = (PNODE)malloc(sizeof(NODE));
	
	if (phead == NULL) {
		printf("no memory");
		exit(-1);
	}

	PNODE ptail = phead;
	ptail->next = NULL;

	for (; i < len; i++) {		
		
		printf("input the data of the node: ");
		scanf_s("%d", &val);

		PNODE pNew = (PNODE) malloc(sizeof(NODE));
		
		if (pNew == NULL) {
			printf("no memory");
			exit(-1);
		}
		 
		pNew->data = val;
		pNew->next = NULL;  // create a new node

		ptail->next = pNew;  
		ptail = pNew;  // ptail record the previous node address.
		
	}
	return phead;
}

void traverse_list(PNODE phead) {

	PNODE p = phead->next;

	while (p != NULL) {

		printf("%d ", p->data);
		p = p->next;
	
	}
	return;
}



void sort_list(PNODE phead) {
	int len = length_list(phead);
	int temp, i, j;

	PNODE p = phead->next;
	for (i = 0; i < len - 1; i++) {
		PNODE p1 = p->next;
		for (j = i + 1; j < len; j++) {
			if ( p->data > p1->data) {
				temp = p->data;
				p->data = p1->data;
				p1->data = temp; 
			}
			p1 = p1->next;
		}
		p = p->next;
	}

	return;
}




bool insert_list(PNODE phead, int position, int val) {
	
	/*position is in the correct range of the list*/
	int len = length_list(phead);

	if (position<0 || position>len+1) {
		printf("Illegal position!");
		return false;
	}

	/*
	allocate the node
	*/
	PNODE pInsert = (PNODE)malloc(sizeof(NODE));
	if (pInsert == NULL) {
		
		printf("Insert fail, no memory allocate!");
		return  false;
	}
	pInsert->data = val;
	pInsert->next = NULL;


	PNODE p =phead;
	for (int i = 0; i < position - 1; i++) {
		/*
		advance the pointer to the position.
		*/
		p = p->next;
	} 
	pInsert->next = p->next;
	p->next = pInsert;

	return true;
}

bool delete_list(PNODE phead, int position, int * pval) {

	/*position is in the correct range of the list*/
	int len = length_list(phead);

	if (position<0 || position>len) {
		printf("Illegal position!");
		return false;
	}

	PNODE p = phead;
	
	for (int i = 0; i < position-1; i++) {
		
		p = p->next;
	} //advance to the node prior to the deleted node


	PNODE node = p->next; // record deleted node address;
	*pval = node->data;
	p->next = node->next;
	free(node);
	node = NULL;
	return true;
}
