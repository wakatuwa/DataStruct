# include <stdio.h>
void f();
void g();
void k();

void f() {
	printf("FFFF\n");
	g();
	printf("111111\n");
}

void g() {
	printf("GGGG\n");
	k();
	printf("222222\n");
}

void k() {
	printf("KKKKK\n");	
}

int main(void) {
	f();
	return 0;
}