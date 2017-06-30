/*
 * 竖式除模拟-积为若干个1构成.c
 *
 *  Created on: 2017年6月30日
 *      Author: lfsenior
 */

#include<stdio.h>
void c821() {
	int a, b, c, p, n;
	printf("  请输入整数p: ");
	scanf("%d", &p);
	if (p % 2 == 0 || p % 10 == 5) {
		printf("  使乘积p*q为若干个1的乘数q不存在。");
		return;
	}
	printf("  寻求的乘数q为：");
	n = 3;
	c = 111;                         	// 确定初始值
	while (c != 0) {
		a = c * 10 + 1;
		c = a % p;
		b = a / p;
		n++;               	// 实施除乘竖式计算模拟
		printf("%d", b);
	}                 	// 输出整数q的一位数
	printf("\n  乘积p*q为%d个1.\n", n);
}
