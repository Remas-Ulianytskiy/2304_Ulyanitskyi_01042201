#include <iostream>
#include <string>

using namespace std;

class Floating_Point_Number {
private:
    double value;

public:
    Floating_Point_Number() : value(0.0) {}
    Floating_Point_Number(double value) : value(value) {}

    double getValue() const { return value; }

    double add(double other) const {
        return value + other;
    }

    double subtract(double other) const {
        return value - other;
    }

    double multiply(double other) const {
        return value * other;
    }

    double divide(double other) const {
        if (other == 0.0) {
            cerr << "Error: Division by zero." << endl;
            return 0.0;
        }
        return value / other;
    }

    void input(string msg) {
        string inputStr;
        cout << "Enter " << msg << " floating-point number: ";
        cin >> inputStr;

        for (char& c : inputStr) 
        {
            if (c == ',')
                c = '.';
        }

        value = stod(inputStr);
    }

    friend ostream& operator<<(ostream& os, const Floating_Point_Number& number) {
        os << number.value;
        return os;
    }
};

void display_result(Floating_Point_Number result) {
    cout << "Result: " << result;
}

int main() {
    short operation = -1;

    Floating_Point_Number first_number;
    Floating_Point_Number second_number;
    Floating_Point_Number result_number;

    while (true) {
        cout << "1 - for add\n";
        cout << "2 - for subtract\n";
        cout << "3 - for multiply\n";
        cout << "4 - for divide\n";
        cout << "0 - for exit\n";
        cout << "Select operation: ";
        cin >> operation;

        if (operation == 0) {
            cout << "Exit";
            break;
        }
        if (operation > 0 && operation <= 4) {
            first_number.input("first");
            second_number.input("second");

            switch (operation) {
            case 1:
                result_number = first_number.add(second_number.getValue());
                break;
            case 2:
                result_number = first_number.subtract(second_number.getValue());
                break;
            case 3:
                result_number = first_number.multiply(second_number.getValue());
                break;
            case 4:
                result_number = first_number.divide(second_number.getValue());
                break;
            default:
                cout << "Error!\n";
                break;
            }

            cout << "Result: " << result_number.getValue() << endl;
        }
        else {
            cout << "Error: Invalid operation!\n";
        }

        cout << endl;
    }

    return 0;
}
