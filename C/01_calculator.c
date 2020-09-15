#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
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
	default:
		printf("\nInvalid Operator !\n");
		isValid = 0;
        break;
	}
	if (isValid) {
		printf("\n%f %c %f = %f\n", a, op, b, c);
	}
    return 0;
}