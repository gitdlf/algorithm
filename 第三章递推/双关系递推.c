/*
 * 双关系递推.c
 *
 *  Created on: 2017年6月29日
 *      Author: lfsenior
 */

#include <stdio.h>
void c332() {
	int n, p2, p3, i;
	long s, m[3000];
	m[1] = 1;
	s = 1;
	p2 = 1;
	p3 = 1;       // 排头p2,p3赋初值
	printf("  请输入n: ");
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
		if (2 * m[p2] < 3 * m[p3]) {
			m[i] = 2 * m[p2] + 1;
			s += m[i];
			p2++;
		} else {
			m[i] = 3 * m[p3] + 1;
			s += m[i];
			if (2 * m[p2] == 3 * m[p3])
				p2++;  // 为避免重复项，P2须增1
			p3++;
		}
	printf("  m(%d)=%ld\n", n, m[n]);
	printf("  s=%ld\n", s);
}
