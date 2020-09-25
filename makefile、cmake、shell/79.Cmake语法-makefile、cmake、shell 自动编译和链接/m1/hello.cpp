#include<stdio.h>

int add(int num1,int num2);
int sub(int num1,int num2);
int div(int num1,int num2);

int main(int argc, char* argv[]){
	int a = 20;
	int b = 10;
	printf("%d+%d=%d\n",a,b,add(a,b));
	printf("%d-%d=%d\n",a,b,sub(a,b));
	printf("%d/%d=%d\n",a,b,div(a,b));
	return 0;
}
