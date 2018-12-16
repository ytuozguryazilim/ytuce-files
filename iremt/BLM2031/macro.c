#define MUL_BY_TWO(a) ((a)+(a))
#define FIND_MIN(a,b) ((a)<(b)?a:b)
#define FIND_MINOFALL(a,b,c) ((a)<(b)?     ((a)<(c)?a:c)   :    ((c)<(b)?c:b)     )

#define FIND_MIN_V2(x, y)                                  \
({                                                         \
    if ((x) < (y))                              		   \
        printf("%d\n",x);                                  \
    else                                                   \
        printf("%d\n",y);                                  \
})

#include <stdio.h>
int main()
{
	int y;
	float z;
	y=MUL_BY_TWO(2.4);
	z=MUL_BY_TWO(2.4);
	printf("%d %f\n",y,z);
	printf("FIND_MIN:%d\n",FIND_MIN(3,5));
	printf("FIND_MINOFALL:%d\n",FIND_MINOFALL(1,11,2));
	FIND_MIN_V2(2,4);
}
