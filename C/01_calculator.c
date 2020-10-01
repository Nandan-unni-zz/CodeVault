#include <stdio.h>
#include <math.h>
float permutation(int a, int b);
float combination(int a, int b);
int main()
{
    float a, b;
    long int c;
    char op;
    int isValid = 1;
    printf("Enter the first number : ");
	scanf("%f", &a);
	printf("Enter the operator : ");
	scanf(" %c", &op);
	printf("Enter the first number : ");
	scanf("%f", &b);
	switch (op)
    {
	case '+':
		c = a + b;
        break;
	case '-':
		c = a - b;
        break;
	case '*':
		c = a * b;
        break;
	case '/':
		if (b != 0)
			c = a / b;
		else
        {
			printf("\nDivision by 0 not possible !\n");
			isValid = 0;
		}
        break;
	case '^':
		c = pow(a, b);
        break;
	case '%':
		c = fmod(a, b);
        break;
		case 'P':
			if(b>a)
			{
				printf("\nPermutation not possible !\n");
			isValid=0;
			}
			c=permutation(a,b);
			break;
		case 'C': if(b>a)
		           {
		            printf("\nCombination not possible ! \n");
			    isValid=0;
		           }
			c=combination(a,b);
	default:
		printf("\nInvalid Operator !\n");
		isValid = 0;
        break;
	}
	if (isValid) {
		printf("\n%f %c %f = %ld\n", a, op, b, c);
	}
    return 0;
}
long permutation(int a, int b)
{
    return factorial(a) / factorial(a-b);
}

long combination(int a, int b)
{
    return permutation(a,b) / factorial(b);
}

long factorial(int num)
{
    long  fact = 1;

    while(num > 0)
    {
        fact *= num;
        num--;
    }

    return fact;
}
