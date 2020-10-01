#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a, b, c;
    char op, ch;
    bool isValid = true;
    label:
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
		cout << "\nInvalid Operator ! Try Again!\n";
		goto label;
	}
	if (isValid)
        	cout << "\n" << a << " " << op << " " << b << " = " << c << "\n";
	cout<<"\n Do you want to Continue? (y/n)";
	cin>>ch;
	if(ch == 'y') {
		isValid = true;
		goto label;
	}
    return 0;
}
