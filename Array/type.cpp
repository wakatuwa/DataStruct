#include <stdio.h>
typedef int ZHANGSAN;	//为int重新多取一个名字，ZHANGSAN = int
typedef struct Student{
	int sid;
	char name[100];
	char sex;
}* PST;	//PST 等价于 struct Student *
int main(void) {
	// int i = 10;	//等价于ZHANGSAN i = 10;
	// ZHANGSAN j = 20;
	// printf("%d\n", j);
	// struct Student st;	//等价于 ST st;
	// struct Student *ps = &st;	//等价于 ST * ps;

	// ST st2;
	// st2.sid = 200;
	// printf("%d\n", st2.sid);

	struct Student st;
	PST ps = &st;
	ps -> sid = 99;
	printf("%d\n", ps->sid);
	return 0;
}