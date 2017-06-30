/*
 * 回溯n皇后问题.c
 *
 *  Created on: 2017年6月30日
 *      Author: lfsenior
 */

#include <stdio.h>
#include <math.h>
void c913() {
	 int i, g, k, j, n, x, a[20];
	long s;
	printf("  请输入整数n:");
	scanf("%d", &n);
	printf("  %d皇后问题的解:\n", n);
	i = 1;
	s = 0;
	a[1] = 1;
	while (1) {
		g = 1;
		for (k = i - 1; k >= 1; k--) {
			x = abs(a[i] - a[k]);
			if (x == 0 || x == i - k)
				g = 0;     // 相同或同处一对角线上时返回
		}
		if (i == n && g == 1)          	// 满足条件时输出解
				{
			for (j = 1; j <= n; j++)
				printf("%d", a[j]);
			printf("   ");
			s++;
			if (s % 5 == 0)
				printf("\n");
		}
		if (i < n && g == 1) {
			i++;
			a[i] = 1;
			continue;
		}
		while (a[i] == n && i > 1)
			i--;  // 往前回溯
		if (a[i] == n && i == 1)
			break;
		else
			a[i] = a[i] + 1;
	}
	printf("\n 共%ld个解.\n", s);
}
