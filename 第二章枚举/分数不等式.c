/*
 * 分数不等式.c
 *
 *  Created on: 2017年6月29日
 *      Author: lfsenior
 */

#include <stdio.h>
#include<math.h>
void c241() {
	long c, d, i, m1, m2;
	double s;
	printf("  请输入正整数m1,m2(m1<m2): ");
	scanf("%ld,%ld", &m1, &m2);
	i = 0;
	s = 0;
	/**
	 * 获取n的最小值
	 */
	while (s <= m1) {
		i = i + 1;
		s = s + sqrt(i) / (i + 1);
	}
	c = i;
	/**
	 * 获取n的最大值
	 */
	do {
		i = i + 1;
		s = s + sqrt(i) / (i + 1);
	} while (s <= m2);
	d = i - 1;
	printf("  满足不等式的正整数n为: %ld≤n≤%ld \n", c, d);
}
