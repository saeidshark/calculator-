// simple_calculator.cpp
#include <iostream>
#include <cmath>    // pow()
#include <limits>   // clear invalid input

using namespace std;

void clearInput() {
    // clear error state + flush input buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    cout << "=== Simple Calculator (C++) ===\n\n";

    while (true) {
        cout << "Menu:\n";
        cout << "  1) Add (+)\n";
        cout << "  2) Subtract (-)\n";
        cout << "  3) Multiply (*)\n";
        cout << "  4) Divide (/)\n";
        cout << "  5) Power (a^b)\n";
        cout << "  6) Modulus (a % b)\n";
        cout << "  0) Exit\n";
        cout << "Choose (0-6): ";

        int choice;
        if (!(cin >> choice)) {
            cout << "Invalid input! Enter an integer.\n\n";
            clearInput();
            continue;
        }

        if (choice == 0) {
            cout << "bye\n";
            break;
        }

        long double a, b;
        if (choice >= 1 && choice <= 5) {
            cout << "Enter first number: ";
            if (!(cin >> a)) {
                cout << "Invalid number. Back to menu.\n\n";
                clearInput();
                continue;
            }
            cout << "Enter second number: ";
            if (!(cin >> b)) {
                cout << "Invalid number. Back to menu.\n\n";
                clearInput();
                continue;
            }
        } else if (choice == 6) {
            long long ai, bi;
            cout << "Enter first integer: ";
            if (!(cin >> ai)) {
                cout << "Invalid integer. Back to menu.\n\n";
                clearInput();
                continue;
            }
            cout << "Enter second integer: ";
            if (!(cin >> bi)) {
                cout << "Invalid integer. Back to menu.\n\n";
                clearInput();
                continue;
            }
            if (bi == 0) {
                cout << "Error: division by zero.\n\n";
                continue;
            }
            cout << ai << " % " << bi << " = " << (ai % bi) << "\n\n";
            continue;
        } else {
            cout << "Invalid choice! Try again.\n\n";
            continue;
        }

        switch (choice) {
            case 1: // add
                cout << a << " + " << b << " = " << (a + b) << "\n\n";
                break;
            case 2: // subtract
                cout << a << " - " << b << " = " << (a - b) << "\n\n";
                break;
            case 3: // multiply
                cout << a << " * " << b << " = " << (a * b) << "\n\n";
                break;
            case 4: // divide
                if (fabsl(b) < 1e-18L) {
                    cout << "Error: division by zero.\n\n";
                } else {
                    cout << a << " / " << b << " = " << (a / b) << "\n\n";
                }
                break;
            case 5: // power
                cout << a << " ^ " << b << " = " << pow((double)a, (double)b) << "\n\n";
                break;
            default:
                cout << "Unsupported option.\n\n";
        }
    }

    return 0;
}
