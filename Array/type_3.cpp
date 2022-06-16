# include <stdio.h>

typedef struct Student {
	int sid;
	char name[100];
	char sex;
}* PSTU, STU;	//等价于STU代表了struct Student, PSTU代表了struct Student *

int main(void) {
	STU st;	//struct Student st
	PSTU ps = &st;	//struct Student *ps = &st
	ps->sid = 99;
	printf("%d\n", ps->sid);
	return 0;
}