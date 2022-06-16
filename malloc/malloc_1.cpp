#include <stdio.h>
#include <malloc.h>
int main(void) {
	int a[5] = {4, 10, 2, 8, 6};

	int len;
	printf("请输入你需要分配的数组长度：len = " );
	scanf("%d", &len);
	int *pArr = (int *)malloc(sizeof(int)* len);
	// *pArr = 4;	//类似于 a[0] = 4;
	// pArr[1] = 10;	//类似于 a[1] = 10;
	// printf("%d %d", *pArr, pArr[1]);
	//可以把pArr当作一个普通数组来使用
	for(int i = 0; i<len; i++) {
		scanf("%d", &pArr[i]);
	}

	for(int i = 0; i<len; i++) {
		printf("%d ", pArr[i]);

	}
	free(pArr);

	return 0;
}