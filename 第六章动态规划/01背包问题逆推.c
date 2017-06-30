/*
 * 01背包问题逆推.c
 *
 *  Created on: 2017年6月30日
 *      Author: lfsenior
 */

#include <stdio.h>
#define N 50
void c651() {
	int i, j, c, cw, n, sw, sp, p[N], w[N], m[N][10 * N];
	printf(" input n:");
	scanf("%d", &n);  	//  输入已知条件
	printf(" input c:");
	scanf("%d", &c);
	for (i = 1; i <= n; i++) {
		printf("input w%d,p%d:", i, i);
		scanf("%d,%d", &w[i], &p[i]);
	}
	for (j = 0; j <= c; j++)
		if (j >= w[n])
			m[n][j] = p[n];               		    //  首先计算m(n,j)
		else
			m[n][j] = 0;
	for (i = n - 1; i >= 1; i--)            		//  逆推计算m(i,j)
		for (j = 0; j <= c; j++)
			if (j >= w[i] && m[i + 1][j] < m[i + 1][j - w[i]] + p[i])
				m[i][j] = m[i + 1][j - w[i]] + p[i];
			else
				m[i][j] = m[i + 1][j];
	cw = c;
	printf("c=%d \n", c);
	printf("背包所装物品：\n");
	printf(" i     w(i)    p(i)\n");
	for (sp = 0, sw = 0, i = 1; i <= n - 1; i++)     		// 以表格形式输出结果
		if (m[i][cw] > m[i + 1][cw]) {
			cw -= w[i];
			sw += w[i];
			sp += p[i];
			printf("%2d     %3d     %3d \n", i, w[i], p[i]);
		}
	if (m[1][c] - sp == p[n]) {
		sw += w[i];
		sp += p[i];
		printf("%2d     %3d     %3d \n ", n, w[n], p[n]);
	}
	printf("w=%d,  pmax=%d \n", sw, sp);
}
