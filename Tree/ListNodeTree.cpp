# include <stdio.h>
# include <malloc.h>
struct BTNode{
	int data;
	struct BTNode * pLchild;	//p是指针 L是左 chilid是孩子
	struct BTNode * pRchild;
};
struct BTNode * CreateBTree(void);
void PreTraverseBTree(struct BTNode *pT);
void InTraverseBTree(struct BTNode *pT);
void PostTraverseBTree(struct BTNode *pT);
int main() {
	struct BTNode * pT = CreateBTree();
	//PreTraverseBTree(pT);
	//InTraverseBTree(pT);
	 PostTraverseBTree(pT);
	return 0;
}
struct BTNode * CreateBTree(void){
	struct BTNode * pA = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pB = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pC = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pD = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pE = (struct BTNode *)malloc(sizeof(struct BTNode));
	pA -> data = 'A';
	pB -> data = 'B';
	pC -> data = 'C';
	pD -> data = 'D';
	pE -> data = 'E';

	pA -> pLchild = pB;
	pA -> pRchild = pC;
	pB -> pLchild = pB -> pRchild = NULL;
	pC -> pLchild = pD;
	pC -> pRchild = NULL;
	pD -> pLchild = NULL;
	pD -> pRchild = pE;
	pE -> pLchild = pE -> pRchild = NULL;

	return pA;
}

void PreTraverseBTree(struct BTNode *pT){
	if(pT!=NULL) {
		printf("%c\n", pT->data);
		PreTraverseBTree(pT->pLchild);
		PreTraverseBTree(pT->pRchild);
	}
}

void InTraverseBTree(struct BTNode *pT) {
	if(pT!=NULL) {
		InTraverseBTree(pT->pLchild);
		printf("%c\n", pT->data);
		InTraverseBTree(pT->pRchild);
	}
}

void PostTraverseBTree(struct BTNode *pT) {
	if(pT!=NULL) {
		PostTraverseBTree(pT->pLchild);
		PostTraverseBTree(pT->pRchild);
		printf("%c\n", pT->data);
	}
}