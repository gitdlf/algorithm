/*
 * 装载问题.c
 *
 *  Created on: 2017年6月30日
 *      Author: lfsenior
 */

#include <stdio.h>
#define N 100
void c641() {
	int n, c1, c2, i, j, s, cw, sw, w[N], m[N][N];
	printf(" input c1,c2: ");
	scanf("%d,%d", &c1, &c2);
	printf(" input n: ");
	scanf("%d", &n);
	s = 0;
	printf(" 集装箱的重量: ");
	for (i = 1; i <= n; i++)            //  输入n个集装箱重量整数
			{
		scanf("%d", &w[i]);
		s += w[i];
	}
	if (s > c1 + c2)
		return;         // 确保n个集装箱重量之和不大于c1+c2
	printf("集装箱重量：%d", w[1]);
	for (i = 2; i <= n; i++)
		printf(", %d", w[i]);
	printf("\n n=%d,s=%d ", n, s);
	printf("\n c1=%d, c2=%d \n", c1, c2);
	for (j = 0; j < w[n]; j++)
		m[n][j] = 0; //因为w[n]的重量比j大，所有不装意味着m[n][j]=0;


	for (j = w[n]; j <= c1; j++)
		m[n][j] = w[n];       	//  首先计算m(n,j),因为j比w[n]大所以可以装


	for (i = n - 1; i >= 1; i--)                       	//  逆推计算m(i,j)
		for (j = 0; j <= c1; j++)
			if (j >= w[i] && m[i + 1][j] < m[i + 1][j - w[i]] + w[i])
				m[i][j] = m[i + 1][j - w[i]] + w[i];
			else
				m[i][j] = m[i + 1][j];
	printf("maxc1=%d \n", m[1][c1]);    	// 得最优值m(1,c1)
	if (m[1][c1] >= s - c2)        	        // 判断是否有解
			{
		printf("C1:");
		cw = m[1][c1];
		for (sw = 0, i = 1; i <= n - 1; i++)        //  构造最优解，输出船1的装载
			if (m[i][cw] > m[i + 1][cw]) { //这是有装载的递归条件决定的
				cw -= w[i];
				sw += w[i];
				printf(" %3d", w[i]);
				w[i] = 0;                 	// w(i)装载后赋0,为装船2作准备
			}
		if (m[1][c1] - sw == w[n]) {
			printf(" %3d", w[n]);
			sw += w[n];
			w[n] = 0;
		}
		printf("  (%d)\n", sw);
		printf("C2:");
		for (sw = 0, i = 1; i <= n; i++)       	//  输出船2的装载
			if (w[i] > 0) {
				sw += w[i];
				printf(" %3d", w[i]);
			}
		printf("  (%d)\n", sw);
	} else
		printf("此装载问题无解！"); 	//  输出无解信息
}
