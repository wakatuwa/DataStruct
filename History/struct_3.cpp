#include <stdio.h>
#include <string.h>
struct Student{
	int sid;
	char name[200];
	int age;
};	//分号不能省

void f(struct Student *pst);
void g(struct Student pst);
void g2(struct Student *pst);
int main(void ) {
	struct Student st;
	
	f(&st);
	g(st);	
	g2(&st);
	//printf("%d %s %d\n", st.sid, st.name, st.age);
	return 0;
}

void f(struct Student *pst) {
	(*pst).sid = 99;
	strcpy((*pst).name,"zhangsan");
	(*pst).age = 20;
}

//这种方式耗内存，耗时间，不推荐
void g(struct Student pst) {
	printf("%d %s %d\n", pst.sid, pst.name, pst.age);
}

//只消耗了4个字节的内存
void g2(struct Student *pst) {
	printf("%d %s %d\n", pst->sid, pst->name, pst->age);
}