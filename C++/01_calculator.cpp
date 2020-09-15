#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a, b, c;
    char op;
    bool isValid = true;
    cout << "Enter the first number : ";
    cin >> a;
    cout << "Enter the operator : ";
    cin >> op;
    cout << "Enter the second number : ";
    cin >> b;
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
			cout << "\nDivision by 0 not possible !\n";
			isValid = false;
		}
        break;
	case '^':
		c = pow(a, b);
        break;
	case '%':
		c = fmod(a, b);
        break;
	default:
		cout << "\nInvalid Operator !\n";
		isValid = false;
        break;
	}
	if (isValid)
        cout << "\n" << a << " " << op << " " << b << " = " << c << "\n";
    return 0;
}