# include <stdio.h>
# include <malloc.h>

typedef struct Queeue {
	int * pBase;
	int front;
	int rear;
}QUEUE;

void init(QUEUE *);
bool en_queue(QUEUE *, int val);
void traverse_queue(QUEUE *);
bool full_queue(QUEUE *);

int main(void) {
	QUEUE Q;
	return 0;

	init(&Q);
}

void init(QUEUE *pQ) {
	pQ->pBase = (int *)malloc(sizeof(int) * 6);
	pQ->front = 0;
	pQ->rear = 0;
}

bool full_queue(QUEUE * pQ){
	if ((pQ->rear+1)%6==pQ->front)
		return true;
	else 
		return false;
}
bool en_queue(QUEUE* pQ, int val) {
	if (full_queue(pQ)) {
		return false;
	}
	else {
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear+1)%6;
	}
	return true;
}

void traverse_queue(Queeue * pQ) {
	
}