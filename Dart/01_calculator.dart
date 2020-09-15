import 'dart:io';
import 'dart:math';

void main() {
  stdout.write("Enter the first number : ");
  double a = double.parse(stdin.readLineSync());
  stdout.write("Enter the operator : ");
  String op = stdin.readLineSync();
  stdout.write("Enter the second number : ");
  double b = double.parse(stdin.readLineSync());
  double c;
  bool isValid = true;
  switch (op) {
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
      {
        if (b == 0) {
          stdout.write("\ndivision by 0 is not possible !\n");
          isValid = false;
        }
        c = a / b;
      }
      break;
    case '^':
      c = pow(a, b);
      break;
    case '%':
      c = a % b;
      break;
    default:
      {
        stdout.write("\nInvalid operator !\n");
        isValid = false;
      }
      break;
  }
  if (isValid) stdout.write("\n${a} ${op} ${b} = ${c}\n");
}
