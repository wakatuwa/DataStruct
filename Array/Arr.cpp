#include <stdio.h>
#include <malloc.h>	//包含了malloc函数
#include <stdlib.h>	//包含了exit函数
//定义了一个数据类型，该数据类型的名字叫做struct Arr, 该数据类型含有三个成员分别是 *pBase, len, cnt
struct Arr{
	int * pBase;	//存储的是数组第一个元素的地址
	int len;	//数组所能容纳的最大元素的个数
	int cnt;	//当前数组有效元素的个数
};

void init_arr(struct Arr *, int length);	//初始化
bool append_arr(struct Arr *, int val);	//追加
bool insert_arr(struct Arr *, int pos, int val);	//插入	pos的值从1开始
bool delete_arr(struct Arr *, int pos, int *pVal);	//删除
int get();
bool is_empty(struct Arr *pArr);
bool is_full(struct Arr *, int length);
void sort_arr(struct Arr *);	//排序
void show_arr(struct Arr *);
void inversion_arr(struct Arr *);	//倒置

int main(void) {
	struct Arr arr;	//此时已经分配内存，变量还没有初始化，里面都是垃圾数字，
	int val;
	init_arr(&arr, 6);	//&取地址符
	show_arr(&arr);
	append_arr(&arr, 1);
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	append_arr(&arr, -2);
	append_arr(&arr, 234);
	append_arr(&arr, -99);
	
	if(delete_arr(&arr, 1, &val)){
		printf("删除成功！\n");
		printf("删除的元素是: %d\n", val);
	}
	// append_arr(&arr, 2);
	// append_arr(&arr, 3);
	// append_arr(&arr, 4);
	// append_arr(&arr, 5);
	// insert_arr(&arr, 1, 99);
	// if(append_arr(&arr, 8)){
	// 	printf("追加成功！");
	// }else {
	// 	printf("追加失败！");
	// }
	show_arr(&arr);
	printf("\n");
	inversion_arr(&arr);
	show_arr(&arr);
	printf("\n排序之后：\n");
	sort_arr(&arr);
	show_arr(&arr);
	return 0;
}

void init_arr(struct Arr *pArr, int length) {
	//array.len = 99;	//这样传参，不能改变主函数中的变量
	//pArr -> len = 99;	//将主函数中的结构体的地址传过来，就可以通过地址去改变主函数中的变量
	pArr -> pBase = (int *)malloc(sizeof(int) * length);	//把前四个字节的地址赋给pBase,并且开辟了6*(4*int)字节的空间
	if (NULL == pArr->pBase){
		printf("动态内存分配失败！\n");
		exit(-1);	//终止整个程序
	}
	else {
		pArr -> len = length;
		pArr -> cnt = 0;
	}
	return;
}
bool is_empty(struct Arr *pArr) {
	if(pArr->cnt == 0) {
		return true;
	} else {
		return false;
	}
}
void show_arr(struct Arr *pArr) {
	if(is_empty(pArr)) {
		printf("数组为空！\n");
	}
	else{
		for(int i = 0; i<pArr->cnt; ++i) {
			printf("%d ", pArr->pBase[i]);
		}
	}
}

bool is_full(struct Arr *pArr){
	if(pArr->cnt == pArr->len){
		return true;
	} else {
		return false;
	}
}
bool append_arr(struct Arr *pArr, int val){
	//满时返回false
	if(is_full(pArr))
		return false;
	
	//不满时追加
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;
	return true;
}

bool insert_arr(struct Arr *pArr, int pos, int val){
	if(is_full(pArr))
		return false;
	if(pos<1||pos>pArr->cnt+1)
		return false;
	for(int i = pArr->cnt -1; i>=pos-1; i--) {
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1] = val;
	pArr->cnt++;
	return true;
}

bool delete_arr(struct Arr *pArr, int pos, int *pVal){
	if(is_empty(pArr))
		return false;
	if (pos<1 || pos>pArr->cnt)
		return false;

	*pVal = pArr->pBase[pos-1];
	for(int i = pos; i<pArr->cnt; i++) {
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true;
}


void inversion_arr(struct Arr * pArr){
	int i = 0; 
	int j = pArr ->cnt-1;
	int t;
	while(i < j) {
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		i++;
		j--;
	}
}

void sort_arr(struct Arr * pArr){
	int i, j, t;
	for(i = 0; i<pArr->cnt; i++) {
		for(j = i+1; j<pArr->cnt; j++) {
			if(pArr->pBase[i]>pArr->pBase[j]){
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;  
			}
		}
	}
}


