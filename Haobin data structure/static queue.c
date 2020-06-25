#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


#define bool char
#define true 1
#define false 0
#define LEN 6


typedef struct Queue {
	int * pBase;
	int front;
	int rear;

}Queue;


void initQueue(Queue * q);

bool is_full(Queue * q){ 
	
	if ((q->rear + 1) % LEN == q->front) {
		return true;
	}
	
	else {
		return false;
	}
}

bool is_empty(Queue * q){ 

	if (q->front == q->rear) {
		return true;
	}
	else {
		return false;
	}
}

bool en_queue(Queue * q, int val);

bool de_queue(Queue * q, int* pVal);

void traverse_queue(Queue * q);


int main() {

	Queue Q;
	initQueue(&Q);
	/*en_queue(&Q, 6);
	en_queue(&Q, 5);
	en_queue(&Q, 4);
	en_queue(&Q, 3);
	en_queue(&Q, 2);
	en_queue(&Q, 1);*/
	traverse_queue(&Q);
	int val;
	de_queue(&Q, &val);
	printf("dequeed is %d ", val);
	printf("\n");
	traverse_queue(&Q);

	return 0;
}

void initQueue(Queue * q) {
	q->pBase = (int *)malloc(sizeof(int)* LEN);
	q->front = 0;
	q->rear = 0;
	return;
}


bool en_queue(Queue *q, int val) {

	if (is_full(q)) {
		printf("the queue is full!\n");
		return false;
	}

	else {
		q->pBase[q->rear] = val;
		q->rear = ((q->rear) + 1) % LEN;
		return true;
	}
}

bool de_queue(Queue *q, int* pVal) {
	
	if (is_empty(q)) {

		printf("the queue is empty!\n");
		return false;
	}
	else {
		*pVal = q->pBase[q->front];
		q->front = ((q->front) + 1) % LEN;
		return true;
	}
}


void traverse_queue(Queue *q) {
	
	int temp = q->front; // 必须要用一个临时变量。
	while (temp!= q->rear) {

		printf("%d ", q->pBase[temp]);
		temp = (temp + 1) % LEN;
	}  
	return;

	/* 错误方法！会移动队列本身的front，导致traverse完毕，front指针指向rear。
	while (is_empty(q)) {

		printf("%d ", q->pBase[q->front]);
		q->front = (q->front + 1) % LEN;
	}
	return;*/

	
}
