// File: CS112_A2_T3_S19 S20_20230052_20230123_20230538.cpp
// Authors :
// Esraa Hussien Mohamed Abdullah
// Hassan Abdallah Hassan Mohamed
// Yomn Tarek Fathi Arab
// Section -->> S19 S20
//ID for Esraa : 20230052
//ID for Hassan : 20230123
//ID for Yomn : 20230538

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <sstream>
using namespace std;
long long int X, Y, a, b, c, d;

long long int GCD(long long int a, long long int b) {
    while (b) {
        long long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to perform addition of fractions
void Addition() {
    X = ((a * d) + (c * b));
    Y = (b * d);
    cout << "The result : " << (X / GCD(X, Y)) << "/" << (Y / GCD(X, Y)) << endl;
}

// Function to perform subtraction of fractions
void substraction() {
    X = ((a * d) - (c * b));
    Y = (b * d);
    cout << "The result : " << (X / GCD(X, Y)) << "/" << (Y / GCD(X, Y)) << endl;
}

// Function to perform multiplication of fractions
void multi() {
    X = (a * c);
    Y = (b * d);
    cout << "The result : " << (X / GCD(X, Y)) << "/" << (Y / GCD(X, Y)) << endl;
}

// Function to perform division of fractions
void div() {
    X = a * d;
    Y = b * c;
    cout << "The result : " << (X / GCD(X, Y)) << "/" << (Y / GCD(X, Y)) << endl;
}

// Function to check if a string represents a valid integer
bool Valid_Int(string s)
{
    if (s[0] == '-' || s[0] == '+')
    {
        s.erase(0, 1);
    }
    for (auto& c : s)
    {
        if (c < '0' || c > '9')
        {
            return false;
        }
    }
    return (s.size() > 0);
}

int main() {
    while (true) {
        // Welcome message
        cout << "<< Welcome to my calculator >>\n";
        int choice;
        cout << "1- Enter rational number operations\n" << "2- Exit\n" << "Your choice: ";
        cin >> choice;
        if (cin.fail() || (choice != 1 && choice != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input." << endl;
            continue;
        }
        if (choice == 2) {
            cout << "Thanks for using my calculator.";
            break;
        }
        else if (choice == 1) {
            cout << "Enter the input : ";
            string input = "";
            char op;
            cin.ignore();
            getline(cin, input);

            string num1 = "", num2 = "";
            string operations[] = { " / "," + "," - "," * " };
            bool val = false;
            for (auto& X : operations)
            {
                if (input.find(X) != std::string::npos)
                {
                    num1 = input.substr(0, input.find(X));
                    num2 = input.substr(input.find(X) + 3);
                    op = X[1];
                    val = true;
                }

            }
            if (!val)
            {
                cout << "Invalid Input\n";
                continue;
            }

            // Extracting numerator and denominator of the first fraction
            a = b = c = d = 1;

            if (num1.find("/") != std::string::npos)
            {

                if (Valid_Int(num1.substr(0, num1.find("/"))) && Valid_Int(num1.substr(num1.find("/") + 1)))
                {
                    a = stoi(num1.substr(0, num1.find("/")));
                    b = stoi(num1.substr(num1.find("/") + 1));
                }
                else
                {
                    cout << "Invalid Input\n";
                    continue;
                }
            }
            else
            {
                if (Valid_Int(num1))
                {
                    a = stoi(num1);
                }
                else
                {
                    cout << "Invalid Input\n";
                    continue;
                }
            }

            // Extracting numerator and denominator of the second fraction
            if (num2.find("/") != std::string::npos)
            {
                if (Valid_Int(num2.substr(0, num2.find("/"))) && Valid_Int(num2.substr(num2.find("/") + 1)))
                {
                    c = stoi(num2.substr(0, num2.find("/")));
                    d = stoi(num2.substr(num2.find("/") + 1));
                }
                else
                {
                    cout << "Invalid Input\n";
                    continue;
                }
            }
            else
            {
                if (Valid_Int(num2))
                {
                    c = stoi(num2);
                }
                else
                {
                    cout << "Invalid Input\n";
                    continue;
                }
            }
            if (b == 0 || d == 0) {
                cout << "<< Math error! >>\n";
                continue;
            }

            // Checking and performing the selected operation
            if (op == '+') {
                Addition();
            }
            else if (op == '-') {
                substraction();
            }
            else if (op == '*') {
                multi();
            }
            else if (op == '/') {
                if (c == 0) {
                    cout << "<< Math error! >>\n";
                    continue;
                }
                else
                    div();
            }
            else {
                cout << "<< invalid input! >>\n";
                continue;
            }
        }
    }
    return 0;
}
