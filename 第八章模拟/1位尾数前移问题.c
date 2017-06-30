/*
 * 1位尾数前移问题.c
 *
 *  Created on: 2017年6月30日
 *      Author: lfsenior
 */

#include<stdio.h>
void c831() {
	int a, b, c, p, q;
	printf("请输入整数n的指定尾数q:");
	scanf("%d", &q);                   	// 输入处理数据q,p
	printf("请输入前移后为n的倍数p:");
	scanf("%d", &p);
	b = q / p;
	c = q % p;                      	// 确定初始条件
	printf("n(%d,%d)=%d", q, p, b);      	// 输出n的首位b
	while (c != 0 || b != q)              	// 试商循环处理
	{
		a = c * 10 + b;
		b = a / p;
		c = a % p;                 	// 模拟整数除竖式计算
		printf("%d", b);
	}
	printf("\n");
}
