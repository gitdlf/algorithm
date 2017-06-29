/*
 * 韩信点兵.c
 *
 *  Created on: 2017年6月29日
 *      Author: lfsenior
 */

#include <stdio.h>
void c202()
{ long int x;
  x=65;
  while(1)
    { x=x+66;
      if(x%5==1 && x%7==4)
	         { printf("至少有兵: %ld 个。",x);
           break;
         }
     }
}
