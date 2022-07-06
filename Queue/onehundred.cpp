# include <stdio.h>
int f(int n){
	if(n == 1) {
		return 1;
	} 
	else 
		return f(n-1)+n;
}

int main(void) {
	int result = f(100);
	printf("%d\n", result);
	return 0;
}