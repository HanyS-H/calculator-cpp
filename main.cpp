#include <iostream>
#include <cmath>
#include <limits>
#include <string>
using namespace std;

// Reads a valid number from the user (keeps asking until it's valid)
double readNumber(const string& message) {
    double value;
    while (true) {
        cout << message;
        if (cin >> value) {
            return value;
        }
        cout << "Invalid input, please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void printMenu() {
    cout << "\n===== Simple Calculator =====\n";
    cout << "1) Add (+)\n";
    cout << "2) Subtract (-)\n";
    cout << "3) Multiply (*)\n";
    cout << "4) Divide (/)\n";
    cout << "5) Power (^)\n";
    cout << "6) Square root\n";
    cout << "0) Exit\n";
    cout << "Choose: ";
}

int main() {
    int option = -1;

    while (option != 0) {
        printMenu();

        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number from the menu.\n";
            option = -1;
            continue;
        }

        if (option == 0) break;

        if (option < 0 || option > 6) {
            cout << "Invalid option, try again.\n";
            continue;
        }

        if (option == 6) {
            double x = readNumber("Enter a number: ");
            if (x < 0) {
                cout << "Error: can't take the square root of a negative number.\n";
            } else {
                cout << "Result: " << sqrt(x) << "\n";
            }
            continue;
        }

        double a = readNumber("First number: ");
        double b = readNumber("Second number: ");

        switch (option) {
            case 1:
                cout << "Result: " << a + b << "\n";
                break;
            case 2:
                cout << "Result: " << a - b << "\n";
                break;
            case 3:
                cout << "Result: " << a * b << "\n";
                break;
            case 4:
                if (b == 0) {
                    cout << "Error: can't divide by zero.\n";
                } else {
                    cout << "Result: " << a / b << "\n";
                }
                break;
            case 5:
                cout << "Result: " << pow(a, b) << "\n";
                break;
        }
    }

    cout << "Goodbye!\n";
    return 0;
}