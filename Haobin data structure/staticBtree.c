#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

/*static binary tree*/
#define bool char
#define true 1
#define false 0

typedef struct BTNode {

	char data;
	struct BTNode * Lchild;
	struct BTNode * Rchild;
} BTNode;


BTNode * CreateBTree(void );
void PreTraverseBTree(BTNode *);
void InTraverseBTree(BTNode *);
void PostTraverseBTree(BTNode *);

int main() {

	BTNode * pT = CreateBTree();

	PreTraverseBTree(pT);
	printf("\n");
	InTraverseBTree(pT);
	printf("\n");
	PostTraverseBTree(pT);
	return 0;
}

BTNode * CreateBTree( void ) {

	BTNode * pA = (BTNode *) malloc(sizeof(BTNode));
	BTNode * pB = (BTNode *)malloc(sizeof(BTNode));
	BTNode * pC = (BTNode *)malloc(sizeof(BTNode));
	BTNode * pD = (BTNode *)malloc(sizeof(BTNode));
	BTNode * pE = (BTNode *)malloc(sizeof(BTNode));
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';

	pA->Lchild = pB;
	pA->Rchild = pC;

	pB->Lchild = NULL;
	pB->Rchild = NULL;

	pC->Lchild = pD;
	pC->Rchild = NULL;

	pD->Lchild = NULL;
	pD->Rchild = pE;

	pE->Lchild = NULL;
	pE->Rchild = NULL;
		
	return pA;
}

void PreTraverseBTree(BTNode *pT) {
	if (pT != NULL) {
		printf("%c", pT->data);
		if (pT->Lchild != NULL) {
			PreTraverseBTree(pT->Lchild);
		}
		if (pT->Rchild != NULL) {
			PreTraverseBTree(pT->Rchild);
		}
	}
}

void InTraverseBTree(BTNode *pT) {
	if (pT != NULL) {
		if (pT->Lchild != NULL) {
			InTraverseBTree(pT->Lchild);
		}
		printf("%c", pT->data);
		if (pT->Rchild != NULL) {
			InTraverseBTree(pT->Rchild);
		}
	}
}

void PostTraverseBTree(BTNode *pT) {
	if (pT != NULL) {
		if (pT->Lchild != NULL) {
			PostTraverseBTree(pT->Lchild);
		}
		if (pT->Rchild != NULL) {
			PostTraverseBTree(pT->Rchild);
		}
		printf("%c", pT->data);
	}
}
