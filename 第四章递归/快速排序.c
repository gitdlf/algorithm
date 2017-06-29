/*
 * 快速排序.c
 *
 *  Created on: 2017年6月29日
 *      Author: lfsenior
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int r[20001];
void c451() {
	int i, n, t;
	void qk(int m1, int m2);   // 函数声明
	t = time(0) % 1000;
	srand(t);          //  随机数发生器初始化
	printf("  input n:");
	scanf("%d", &n);
	printf("  参与排序的%d个整数为：\n", n);
	for (i = 1; i <= n; i++) {
		r[i] = rand() % (4 * n) + 10;          // 随机产生并输出n个整数
		printf("%d ", r[i]);
	}
	qk(1, n);
	printf("  \n  以上%d个整数从小到大排序为：\n", n);
	for (i = 1; i <= n; i++)
		printf("%d ", r[i]);            // 输出排序结果
	printf("\n");
}
void qk(int m1, int m2)             // 快速排序递归函数
{
	int i, j;
	if (m1 < m2) {
		i = m1;
		j = m2;
		r[0] = r[i];          // 定义第i个数作为分区基准
		while (i != j) {
			while (r[j] >= r[0] && j > i)   // 从右至左逐个检查是否大于基准
				j = j - 1;
			if (i < j) {
				r[i] = r[j];
				i = i + 1;
			} // 把小于基准的一个数赋给r(i)
			while (r[i] <= r[0] && j > i)   // 从左至右逐个检查是否小于基准
				i = i + 1;
			if (i < j) {
				r[j] = r[i];
				j = j - 1;
			} // 把大于基准的一个数赋给r(j)
		}                            // 通过循环完成分区
		r[i] = r[0];                     // 分区的基准为r(i)
		qk(m1, i - 1);
		qk(i + 1, m2);        // 在两个区中继续分区
	}
	return;
}
