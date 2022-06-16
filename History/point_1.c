#include <stdio.h>

int main(void) {
	int *p;	//p是个变量名字，int*表示该p变量只能存储int类型变量的地址
	int i = 10;
	int *j;

	p = &i;	//把i的地址存储在p变量中，即以p变量存储了一个地址，这个地址就是i变量对应的地址
	//p指向了i，i = *p
	
	//j = *p; //等价与 j= i;
	printf("%d\n", j);
	printf("i = %d, j = %d, *p = %d\n", i, j, *p);
	return 0;
}
