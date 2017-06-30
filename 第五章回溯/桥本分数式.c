/*
 * 桥本分数式.c
 *
 *  Created on: 2017年6月30日
 *      Author: lfsenior
 */

#include <stdio.h>
void c521() {
	int g, i, k, s, a[10];
	long m1, m2, m3;
	i = 1;
	a[1] = 1;
	s = 0;
	while (1) {
		g = 1;
		for (k = i - 1; k >= 1; k--)
			if (a[i] == a[k]) {
				g = 0;
				break;
			}            // 两数相同,标记g=0
		if (i == 9 && g == 1 && a[1] < a[4]) {
			m1 = a[2] * 10 + a[3];
			m2 = a[5] * 10 + a[6];
			m3 = a[8] * 10 + a[9];
			if (a[1] * m2 * m3 + a[4] * m1 * m3 == a[7] * m1 * m2)  // 判断等式
					{
				s++;
				printf("(%2d) ", s);
				printf("%d/%ld+%d/", a[1], m1, a[4]);
				printf("%ld=%d/%ld   ", m2, a[7], m3);
				if (s % 2 == 0)
					printf("\n");
			}
		}
		if (i < 9 && g == 1) {
			i++;
			a[i] = 1;
			continue;
		}      // 不到9个数,往后继续
		while (a[i] == 9 && i > 1)
			i--;    // 往前回溯
		if (a[i] == 9 && i == 1)
			break;
		else
			a[i]++;                  // 至第1个数为9结束
	}
	printf("  共以上%d个解。\n", s);
}
