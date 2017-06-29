/*
 * 双幂序列.c
 *
 *  Created on: 2017年6月29日
 *      Author: lfsenior
 */

#include <stdio.h>
void c341() {
	int k, n, t, p2, p3;
	double a, b, s, f[100];
	printf("  求数列的第n项与前n项和,请输入n: ");
	scanf("%d", &n);
	f[1] = 1;
	p2 = 0;
	p3 = 0;
	a = 2;
	b = 3;
	s = 1;
	for (k = 2; k <= n; k++) {
		if (a < b) {
			f[k] = a;
			a = a * 2;          	// 用2的幂给f[k]赋值
			t = 2;
			p2++;              	// t=2表示2的幂，p2为指数
		} else {
			f[k] = b;
			b = b * 3;          	// 用3的幂给f[k]赋值
			t = 3;
			p3++;              	// t=3表示3的幂，p3为指数
		}
		s += f[k];
	}
	printf("  数列的第%d项为: %.0f ", n, f[n]);
	if (t == 2)                       	// 对输出项进行标注
		printf("(2^%d) \n", p2);
	else
		printf("(3^%d) \n", p3);
	printf("  数列的前%d项之和为：%.0f \n", n, s);
}
