/*
 * 递归n皇后问题.c
 *
 *  Created on: 2017年6月30日
 *      Author: lfsenior
 */


#include <stdio.h>
int n,a[30]; long s=0;
void c914()
{ int put(int k);
printf(" 求解n 皇后问题，请确定n: ");scanf("%d",&n);
    put(1);                  // 从第1行开始放皇后
if(s>0)
       printf("\n %d皇后问题共有以上%ld个解。\n",n,s);
	    else
       printf(" %d皇后问题无解。\n",n);
}
// n皇后问题递归函数
#include <math.h>
int put(int k)
{ int i,j,u;
  if(k<=n)
    { for(i=1;i<=n;i++)      // 探索第k行从第1格开始放皇后
      { a[k]=i;
        for(u=0,j=1;j<=k-1;j++)
		     if(a[k]==a[j] || abs(a[k]-a[j])==k-j )
u=1;             // 若第k行第i格放不下,则置u=1
if(u==0)            // 若第k行第i格可放,则检测是否满n行
           { if(k==n)        // 若已放满到n行时，则打印出一个解
	              { s++; printf(" ");
                for(j=1;j<=n;j++)
                   printf("%d",a[j]);
		           if(s%5==0) printf("\n");
	              }
            else  put(k+1); // 若没放满n行,则放下一行 put(k+1)
          }
     }
}
return s;
}
