#include <stdio.h>
void f(int **);
int main(void) {
	int i = 9;
	int * p = &i;

	printf("%p\n",p);
	f(&p);
	printf("%p\n",p);
	return 0;
}
void f(int ** q) {
	*q =(int *) 0xFFFFFFFF;
}