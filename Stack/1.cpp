# include <stdio.h>
# include <malloc.h>
void f() {
	double * q = (double *)malloc(200);
}

int main(void) {
	int i = 10;
	int *p = (int *)malloc(100);

	return 0;
}