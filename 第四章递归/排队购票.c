/*
 * 排队购票.c
 *
 *  Created on: 2017年6月29日
 *      Author: lfsenior
 */

long f(int j, int i) {
	long y;
	if (i == 0)
		y = 1;
	else if (j < i)
		y = 0;     // 确定初始条件
	else
		y = f(j - 1, i) + f(j, i - 1);   //  实施递归
	return (y);
}
#include<stdio.h>
void c421() {
	int m, n;
	printf(" input m,n: ");
	scanf("%d,%d", &m, &n);
	printf("  f(%d,%d)=%ld.\n", m, n, f(m, n));
}
