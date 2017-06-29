/*
 * 摆动数列.c
 *
 *  Created on: 2017年6月29日
 *      Author: lfsenior
 */

#include <stdio.h>
void c331() {
	int i, n, max, a[10000];
	printf("  请确定项数n: ");
	scanf("%d", &n);
	a[1] = 1;
	max = 0;
	for (i = 2; i <= n; i++) {
		if (i % 2 == 0)                // 分情况实施递推
			a[i] = a[i / 2] + 1;
		else
			a[i] = a[(i - 1) / 2] + a[(i + 1) / 2];
		if (a[i] > max)
			max = a[i];    // 比较得最大值
	}
	printf("  a(%d)=%d \n", n, a[n]);
	printf("  摆动数列前%d项中最大项有：", n);
	for (i = 2; i <= n; i++)            // 探索所有的最大项
		if (a[i] == max)
			printf("a(%d)=", i);
	printf("%d \n", max);
}
