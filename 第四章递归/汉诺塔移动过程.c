/*
 * 汉诺塔移动过程.c
 *
 *  Created on: 2017年6月29日
 *      Author: lfsenior
 */

#include <stdio.h>
int k = 0;
void mv(char x, char y)                   // 输出函数
{
	printf(" %c-->%c  ", x, y);
	k++;                                // 统计移动次数
	if (k % 5 == 0)
		printf("\n");
}
void hn(int m, char a, char b, char c)      // 递归函数
{
	if (m == 1)
		mv(a, c);
	else {
		hn(m - 1, a, c, b);
		mv(a, c);
		hn(m - 1, b, a, c);
	}
}
void c432()                     // 主函数
{
	int n;
	printf("\n input n: ");
	scanf("%d", &n);
	hn(n, 'A', 'B', 'C');
	printf("\n k=%d \n", k);     // 输出移动次数
}
