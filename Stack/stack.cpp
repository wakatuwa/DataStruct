# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * pNext;
}NODE, * PNODE;

typedef struct Stack {
	PNODE pTop;
	PNODE pBottom;
}STACK, * PSTACK;	//PSTACK等价于 struc STACK *

void init(PSTACK);
void push(PSTACK, int);
bool pop(PSTACK, int*);
void traverse(PSTACK);
void clear(PSTACK); 
int main(void) {
	STACK S; //STACK等价于 struct Stack
	int val = 3;
	init(&S);	//造出一个空栈
	push(&S, 1);	//压栈
	push(&S, 2);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);
	push(&S, 6);
	traverse(&S);
	//pop(&S, &val);		//弹出
	if(pop(&S, &val)) {
		printf("出栈成功，出栈的元素是%d\n", val);
	}
	else {
		printf("出栈失败！\n");
	}
	traverse(&S);	//遍历输出
	clear(&S);
	traverse(&S);
	return 0;
}

void init(PSTACK pS) {
	pS -> pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop) {
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	else {
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;	//pS->pBottom->pNext = NULL;
	}
}

void push(PSTACK pS, int val) {
	PNODE pNew = (PNODE)malloc(sizeof(NODE));	//创建新的节点
	pNew->data = val;	//赋予新节点值
	pNew->pNext = pS->pTop;	//将新节点指向栈顶
	pS->pTop = pNew;	//pTop指向新的节点
	return;
}

void traverse(PSTACK pS) {
	PNODE p = pS->pTop;	//创建新节点，利用这个节点去遍历栈
	while(p!=pS->pBottom) {
		printf("%d ", p->data);
		p= p->pNext;
	}
	printf("\n");

	return;
}
//判断栈是否为空
bool empty(PSTACK pS) {
	if(pS->pTop==pS->pBottom)
		return true;
	else 
		return false;
}
//把pS所指向的栈出栈一次，并把出栈的元素存入pVal形参所指向的变量中，如果出栈失败返回false，否则返回true
bool pop(PSTACK pS, int * pVal){
	if (empty(pS)) {	//pS本身存放的就是S地址
		return false;
	} else {
		PNODE r = pS->pTop;
		*pVal = r->data;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;
		
		return true;
	}
}

//清空栈
void clear(PSTACK pS) {
	if(empty(pS)){
		return;
	}
	else {
		PNODE p = pS->pTop;
		PNODE q = NULL;
		while(p!=pS->pBottom) {
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;
	}
}