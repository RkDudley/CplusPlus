/*Write statements that compute and display the absolute difference of two type

*double variables, x and y

*|x-y|*/

#include <stdio.h>
#include <math.h>

int main()
{
	double x, y, value;

	printf("Enter the value of x\n");
	scanf("%lf", &x);
	printf("Enter the value of y\n");
	scanf("%lf", &y);

	value = fabs(x - y);

	printf(" The absolute difference of x and y is %.2f\n", value);

	getchar();
	return(0);

}