/*
 * 多幂序列.c
 *
 *  Created on: 2017年6月29日
 *      Author: lfsenior
 */

#include <stdio.h>
void c333() {
	int k, m, t, p2, p3, p5;
	double a, b, c, s, f[100];
	printf("  求数列的第m项与前m项和,请输入m: ");
	scanf("%d", &m);
	f[1] = 1;
	p2 = 0;
	p3 = 0;
	p5 = 0;
	a = 2;
	b = 3;
	c = 5;
	s = 1;
	for (k = 2; k <= m; k++) {
		if (a < b && a < c) {
			f[k] = a;
			a = a * 2;          	// 用2的幂给f[k]赋值
			t = 2;
			p2++;              	// t=2表示2的幂，p2为指数
		} else if (b < a && b < c) {
			f[k] = b;
			b = b * 3;          	// 用3的幂给f[k]赋值
			t = 3;
			p3++;              	// t=3表示3的幂，p3为指数
		} else {
			f[k] = c;
			c = c * 5;          	// 用5的幂给f[k]赋值
			t = 3;
			p5++;              	// t=5表示5的幂，p5为指数
		}
		s += f[k];
	}
	printf("  数列的第%d项为: %.0f ", m, f[m]);
	if (t == 2)                       	// 对输出项进行标注
		printf("(2^%d) \n", p2);
	else if (t == 3)
		printf("(3^%d) \n", p3);
	else
		printf("(5^%d) \n", p5);
	printf("  数列的前%d项之和为：%.0f \n", m, s);
}
