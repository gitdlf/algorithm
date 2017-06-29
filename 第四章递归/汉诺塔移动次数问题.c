/*
 * 汉诺塔移动次数问题.c
 *
 *  Created on: 2017年6月29日
 *      Author: lfsenior
 */

#include<stdio.h>
void c431() {
	double g(int m);
	int n;
	printf("  请输入盘片数n: ");
	scanf("%d", &n);
	if (n <= 40)
		printf("  %d盘的移动次数为：%.0f\n", n, g(n));
	else
		printf("  %d盘的移动次数为：%.4e\n", n, g(n));
}
// 求移动次数的递归函数
double g(int m) {
	double s;
	if (m == 1)      // 确定初始条件
		s = 1;
	else
		s = 2 * g(m - 1) + 1;
	return s;
}

