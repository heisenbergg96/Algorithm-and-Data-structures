#include<stdio.h>
#include<math.h>

int main()
{
	float a,b,rem;
	printf("Enter two floating point numbers:");
	scanf("%f%f",&a,&b);

	//rem = a%b; invalid operands to binary % (have ‘float’ and ‘float’)
	
	rem = fmod(a,b);
	printf("fmod(%f,%f) = %f",a,b,rem);

	return 0;
}
