/*
 * 逐位整除数.c
 *
 *  Created on: 2017年6月30日
 *      Author: lfsenior
 */

#include<stdio.h>
void c541() {
	int i, j, n, r, t, s, a[100];
	printf("  逐位整除数n位，请确定n：");
	scanf("%d", &n);
	printf("  所求%d位逐位整除数：\n", n);
	for (j = 1; j <= 100; j++)
		a[j] = 0;
	t = 0;
	s = 0;
	i = 1;
	a[1] = 1;
	while (a[1] <= 9) {
		if (t == 0 && i < n)
			i++;
		for (r = 0, j = 1; j <= i; j++)    // 检测i时是否整除i
				{
			r = r * 10 + a[j];
			r = r % i;//这里进行了一个很高明的处理，因为该算法对除法进行了处理
					  //除法也是从高位开始运算的，所有取余的值必然是下一次运算分高位
					  //如果最后r=0说明能够整除
		}
		if (r != 0) {
			a[i] = a[i] + 1;
			t = 1;     // 余数r!=0时，a[i]增1,t=1
			while (a[i] > 9 && i > 1) {
				a[i] = 0;
				i--;            // 回溯
				a[i] = a[i] + 1;
			}
		} else
			t = 0;               // 余数r=0时,t=0
		if (t == 0 && i == n) {
			s++;
			printf("  %d: ", s);
			for (j = 1; j <= n; j++)
				printf("%d", a[j]);
			printf("\n");
			a[i] = a[i] + 1;
		}
	}
	if (s == 0)
		printf("  没有找到！\n");
	else
		printf("  共以上%d个解。\n", s);
}
