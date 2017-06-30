/*
 * 两组均分.c
 *
 *  Created on: 2017年6月30日
 *      Author: lfsenior
 */

#define N 50
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void c552() {
	int n, m, a[N], b[2 * N], i, j, t;
	long s1, s = 0;
	printf("把2n个整数分为和相等的两个组,每组n个数.\n");
	t = time(0) % 1000;
	srand(t);         //  随机数发生器初始化
	printf(" input n :");
	scanf("%d", &n);
	for (s = 0, i = 1; i <= 2 * n; i++)         //  产生2n个不同的随机整数
			{
		t = 0;
		b[i] = rand() % (5 * n) + 10;
		for (j = 1; j <= i - 1; j++)
			if (b[i] == b[j]) {
				t = 1;
				break;
			}
		if (t == 1) {
			i--;
			continue;
		}   // 出现相同数时，返回重新产生
		s += b[i];
		printf("%d  ", b[i]);
	}
	if (s % 2 == 0) {
		printf("\n以上%d个整数总和为%d.\n", 2 * n, s);
		s1 = s / 2;
	} else
		printf("\n  和%ld为奇数,无法平分!\n", s);
	a[1] = 1;
	i = 2;
	a[i] = 2;
	m = 0;
	while (1) {
		if (i == n) {
			for (s = 0, j = 1; j <= n; j++)
				s += b[a[j]];
			if (s == s1)                   // 满足均分条件时输出
					{
				m++;
				printf("NO%d:  ", m);
				for (j = 1; j <= n; j++)
					printf("%d  ", b[a[j]]);
				printf("\n");
			}
		} else {
			i++;
			a[i] = a[i - 1] + 1;
			continue;
		}
		while (a[i] == n + i)
			i--;          // 调整或回溯
		if (i > 1)
			a[i]++;
		else
			break;
	}
	if (m > 0)
		printf("共有以上%d种分法。", m);
	else
		printf(" 无法实现二堆均分. ");
}
