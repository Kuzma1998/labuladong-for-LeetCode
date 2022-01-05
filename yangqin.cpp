/*
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-11-10 09:13:53
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-11-10 09:42:29
 */

#include<stdio.h>

struct A {
	int nouse1;
	int nouse2;
	int n;
};

int main()
{
	A a[10];
	printf("%d\n",*a); // 
	// 数组名a是一个地址，打印这个地址
	printf("%d\n",a);
	for(int i=0;i<10;i++){
		a[i].n=i+1;
	}
	//地址转换成int *，赋给b，b也是个地址
    int * b=(int *)a; 
	printf("%d\n",b);
	printf("%d\n",a);

	//打印地址b指向的数,a[0].nouse1
	printf("%d\n",*b);
	printf("%d\n",*a);
	printf("%d",&a[0].nouse1);


}