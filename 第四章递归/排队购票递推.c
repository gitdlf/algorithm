/*
 * 排队购票递推.c
 *
 *  Created on: 2017年6月29日
 *      Author: lfsenior
 */

#include<stdio.h>
void c422() {
	int m, n, i, j;
	long f[100][100];
	printf(" input m,n: ");
	scanf("%d,%d", &m, &n);
	for (j = 1; j <= m; j++)
		f[j][0] = 1;
	for (j = 0; j <= m; j++)                   // 确定初始条件
		for (i = j + 1; i <= n; i++)
			f[j][i] = 0;
	for (i = 1; i <= n; i++)
		for (j = i; j <= m; j++)
			f[j][i] = f[j - 1][i] + f[j][i - 1];   //  实施递推
	printf("  f(%d,%d)=%ld.\n", m, n, f[m][n]);
}
