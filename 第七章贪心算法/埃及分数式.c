/*
 * 埃及分数式.c
 *
 *  Created on: 2017年6月30日
 *      Author: lfsenior
 */

#include <stdio.h>
void c731() {
	int a, b, c, k, j, t, u, f[20];
	printf("  请输入分数的分子、分母: ");
	scanf("%d,%d", &a, &b);
	printf("  %d/%d=", a, b);
	if (a == 1 || b % a == 0) {
		printf("  %d/%d=%d/%d \n", a, b, 1, b / a);
		return;
	}
	k = 0;
	t = 0;
	j = b;	        // 记录给定分数的分母
	while (1) {
		c = b / a + 1;
		if (c > 1000000000 || c < 0)  // 所得分母超过所定上限，则中断
				{
			t = 1;
			break;
		}
		if (c == j)
			c++;	   // 保证埃及分数的分母不与给定分数的分母相同
		k++;
		f[k] = c;        // 得第k个埃及分数的分母
		a = a * c - b;
		b = b * c;             // a,b迭代，为选择下一个分母作准备
		for (u = 2; u <= a; u++)
			while (a % u == 0 && b % u == 0) {
				a = a / u;
				b = b / u;
			}
		if (a == 1 && b != j)  // 化简后的分数为埃及分数,则赋值后退出
				{
			k++;
			f[k] = b;
			break;
		}
	}
	if (t == 0)              // 输出k个埃及分数组成的埃及分数式
			{
		printf("1/%d", f[1]);
		for (j = 2; j <= k; j++)
			printf("+1/%d", f[j]);
		printf("\n");
	} else
		printf("  尚未找到合适的埃及分数式！\n");
}
