/*
 * 全素组.c
 *
 *  Created on: 2017年6月29日
 *      Author: lfsenior
 */

#include <stdio.h>
#include <math.h>
void c221() {
	int i, j, k, i2, j2, k2, n, s, t, w, z, max, p[9000], q[1500];
	long m;
	printf("  请输入整数n: ");
	scanf("%d", &n);
	/**
	 * 对3-3n进行素组判定
	 */
	for (i = 3; i <= 3 * n; i = i + 2) {
		t = 1;
		z = (int) sqrt(i);
		for (j = 3; j <= z; j = j + 2)
			if (i % j == 0) {
				t = 0;
				break;
			}
		if (t == 1)
			p[i] = 1;     // 奇数i为素数时标记p[i]=1
	}
	w = 0;
	for (i = 3; i <= n; i = i + 2)
		if (p[i] == 1) {
			w++;
			q[w] = i;
		}       // 共w个不大于n的奇素数赋给q数组
	m = 0;
	max = 0;
	for (i = 1; i <= w - 2; i++)     // 设置三重循环枚举所有三个素数组
		for (j = i + 1; j <= w - 1; j++)
			for (k = j + 1; k <= w; k++) {
				s = q[i] + q[j] + q[k];   // 统计3个素数之和s
				if (p[s] == 1) {
					m++;             // 统计全素组个数
					if (s > max)        // 比较并记录最大全素组
							{
						max = s;
						i2 = q[i];
						j2 = q[j];
						k2 = q[k];
					}
				}
			}
	printf("  共有%ld个全素组; \n", m);
	if (m > 0)
		printf("  一个最大全素组为：%d+%d+%d=%ld\n", i2, j2, k2, max);
}
