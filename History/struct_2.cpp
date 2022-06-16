#include <stdio.h>
#include <string.h>
struct Student{
	int sid;
	char name[200];
	int age;
};	//分号不能省

int main(void ) {
	struct Student st = {1000, "zhangsan", 20};
	//st.sid = 99;	//第一种方式

	struct Student * pst;
	pst = &st;
	pst -> sid = 99;	//pst->sid 等价于 (*pst).sid 等价于st.sid;
	printf("%d %s %d\n", st.sid, st.name, st.age);
	return 0;
}