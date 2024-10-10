#include <iostream>
using namespace std;

int main() {
    cout << "===========================================================================================================================" << endl;
    cout << "===================================================== Simple Calculator ===================================================" << endl;
    cout << "===========================================================================================================================" << endl;

    char continueCalculation;
    cout << "Press 'c' to calculate or any other key to quit: ";
    cin >> continueCalculation;

    while (continueCalculation == 'c') {
        int firstNumber, secondNumber;
        cout << "Enter first number: "; 
        cin >> firstNumber;
        cout << endl;
        cout << "Enter second number: "; 
        cin >> secondNumber;
        cout << endl;

        string operation; 
        cout << "Enter operator (+, -, *, /): ";
        cin >> operation;

        if (operation == "+") {
            cout << "Result: " << firstNumber + secondNumber << endl;
        } else if (operation == "-") {
            cout << "Result: " << firstNumber - secondNumber << endl;
        } else if (operation == "*") {
            cout << "Result: " << firstNumber * secondNumber << endl;
        } else if (operation == "/") {
            if (secondNumber != 0) {
                cout << "Result: " << float(firstNumber) / float(secondNumber) << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
        } else {
            cout << "Error: Invalid operator. Please enter +, -, *, or /." << endl;
        }

        cout << "Press 'c' to calculate again or any other key to quit: ";
        cin >> continueCalculation;
        cout << "=========================================================================================================================" << endl;
    }

    return 0;
}
