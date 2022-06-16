# include <stdio.h>

void Show_Array(int * p, int len) {
	p[0] = -1;	//p[0] == *p
	for(int i = 0; i<len; i++) {
		p[i] = -i;
	}

}

int main(void) {
	int a[5] = {1, 2, 3, 4, 5};

	Show_Array(a, 5);	//a等价于&a[0],&a[0]本身就是int * 类型
	for(int i = 0; i<5; i++){
		printf("%d\n", a[i]);
	}
	return 0;
}