/*
 * 整数因数比.c
 *
 *  Created on: 2017年6月29日
 *      Author: lfsenior
 */

#include <stdio.h>
#include <math.h>
void c252() {
	double a, s, a1, s1, b, k, t, x, y, max = 0;
	printf("  求区间[x,y]中整数的因数比最大值.");
	printf("  请输入整数x,y:");
	scanf("%lf,%lf", &x, &y);
	for (a = x; a <= y; a++)            // 枚举区间内的所有整数a
			{
		s = 1;
		b = sqrt(a);
		for (k = 2; k <= b; k++)         // 试商寻求a的因数k
			if (fmod(a, k) == 0)
				s = s + k + a / k;           // k与a/k是a的因数，求和
		if (a == b * b)
			s = s - b;                 // 如果a=b^2,去掉重复因数b
		t = s / a;
		if (max < t) {

			max = t;
			a1 = a;
			s1 = s;
		}
	}
	printf("    整数%.0f的因数比最大：%.4f \n", a1, max);
	printf("    %.0f的因数和为：\n", a1);
	printf("    %.0f=1", s1);     // 输出其因数和式
	for (k = 2; k <= a1 / 2; k++)
		if (fmod(a1, k) == 0)
			printf("+%.0f", k);
}
