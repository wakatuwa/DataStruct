# include <stdio.h>

typedef struct Node {
	int data;	//数据域
	struct Node * pNext;	//指针域 指针指向一个和他本身数据类型一样的节点
}NODE, *PNODE;	//NODE  等价于 struct Node， PNODE 等价于 struct Node *

int main(void) {
	
	return 0;
}