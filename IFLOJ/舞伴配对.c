#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int id;
	int gender;
	struct _node *next;
}*Node;

typedef struct _Que {
	struct _node *head;
	struct _node *tail;
	int count;
}*Que;

void initQue(Que *q) {
	*q = (Que)malloc(sizeof(struct _Que));
	(*q)->head = (*q)->tail = NULL;
	(*q)->count = 0;
}

void enque(Que const q, Node const p) {
	if(q->tail == NULL) {
		q->tail = q->head = p;
		q->count++;
	}else {
		q->tail->next = p;
		q->tail = p;
		q->count++;
	}
}

void deque(Que q, Node *out) {
	if(q->count <= 0) 
		return;

	*out = q->head;

	if(q->head == q->tail)
		q->head = q->tail = NULL;
	else 
		q->head = q->head->next;
	
	q->count--;
}

int main() {
	int a, b;
	Que q;
	Node tmp;

	initQue(&q);
	while(1) {
		scanf("%d", &a);
		if(a == 0) {
			break;
		}
		scanf("%d", &b);
		if(q->head != NULL && q->head->gender ^ b) {
			deque(q, &tmp);
			free(tmp);
			continue;
		}
		Node p = (Node)malloc(sizeof(struct _node));
		p->id = a;
		p->gender = b;
		enque(q, p);
	}

	printf("%d\n", q->head->id);

	return 0;
}
