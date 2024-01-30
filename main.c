#include "main.h"
#include <stdio.h>
int main(void)
{
	int len;
	int len2;
	len = _printf("Let's try to printf a simple sentence.\n");
	printf("%d\n", len);
	len2 = printf("Let's try to printf a simple sentence.\n");
	printf("%d\n", len2);
return (0);
}
