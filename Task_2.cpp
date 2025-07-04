#include <iostream>
using namespace std;

// Function for each operation
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b == 0) {
        cout << "❌ Division by zero is not allowed.\n";
        return 0;
    }
    return a / b;
}
int main() {
    double num1, num2;
    char op;

    cout << "🧮 Basic Calculator\n";
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    double result;

    // Use switch to choose operation
    switch (op) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            cout << "⚠️ Invalid operator!" << endl;
            return 1;
    }
    cout << "🧾 Result: " << result << endl;
    return 0;
}
