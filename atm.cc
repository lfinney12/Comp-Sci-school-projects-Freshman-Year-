/**
 *   @file: atm.cc
 * @author: Levi finney
 *   @date: 2/4/22
 *  @brief: This program is an ATM simulation, where the user enters a pin and if the pin is correct that
 * // user can take out out money less than or equal to the current balance.
 * //If the user enters the wrong pin then he/she gets three tries to enter it correctly before the program quits
 */

#include <iostream>
#include <istream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

/// Pin variable is a constant because it will never change
const int PIN = 1234;

int main(int argc, char const *argv[])
{
    cout << fixed << setprecision(2); // gives me two decimal places
    // pin1 represents ths user hitting the number pad at the atm
    int pin1,num1,num2, num; // num variables is how i iterate through the tries
    double withdrawal, Balance;
    Balance = 1000;
    num = 3;
    num1 = 3; 
    num2 = 3; 
    char answer;
    cout << "Welcome to Bobcats Bank Manchine" << endl;
    cout << "Your Current Balance: $" << Balance << endl;

    cout << "Enter 4 digit pin" << endl;
    cin >> pin1;
    // Determines if entered pin is correct
    if (pin1 != PIN)
    {
        // Start of Do-while loop 
        do
        {
            cout << "Wrong Pin, Enter 4 digit pin" << endl;
            cout << num << " Tries left" << endl;
            cout << "Try again ";
            cin >> pin1;
            num = num - 1;
            if (num < 0 ) // Keeps track of how many attempts the user has used
            {
                cout << "Too many tries, Come back later!" << endl;
                exit(0);
            }

        } while (pin1 != PIN); // only stays in the loop if the condition is met
    }
    // This do-while is for when the corrrect pin is used.
    do
    {
        cout << "How much do you want to withdrawal ";
        cin >> withdrawal;
        if (withdrawal > Balance)
        {
            do
            {
                cout << "Not enough Funds, Try again";
                cin >> withdrawal;
            } while (withdrawal > Balance);
        }
        Balance -= withdrawal; // keeps an updated balance
        cout << "Your balance is: $" << Balance << endl;
        cout << "Would you like to Withdrawal again?(y/n) ";
        cin >> answer;
        if (answer == 'y')
        {
            cout << "Enter your 4-digit pin";
            cin >> pin1;
            if (pin1 != PIN)
            {
                do
                {
                    cout << "Wrong Pin, Enter 4 digit pin" << endl;
                    cout << num1 << " Tries left" << endl;
                    cout << "Try again ";
                    cin >> pin1;
                    num1 -= 1;
                    if (num1 < 0) // Keeps track of how many attempts the user has used
                    {
                        cout << "Too many tries, Come back later!" << endl;
                        exit(0);
                    }

                } while (pin1 != PIN); // only stays in the loop if the condition is met
            }

            do
            {

                cout << "How much do you want to withdrawal";
                cin >> withdrawal;
                if (withdrawal > Balance)
                {
                    do
                    {
                        // keeps withdrawl < Balance
                        cout << "Not enough Funds, Try again ";
                        cin >> withdrawal;
                    } while (withdrawal > Balance);
                }
                Balance -= withdrawal;
                cout << "Your balance is: $" << Balance << endl;
                cout << "Would you like to withdrawal? (y/n)";
                cin >> answer;
                if (answer == 'y')
                {
                    cout << "Enter your 4-digit pin";
                    cin >> pin1;
                    if (pin1 != PIN)
                    {
                        do
                        {
                            cout << "Wrong Pin, Enter 4 digit pin" << endl;
                            cout << num2 << " Tries left" << endl;
                            cout << "Try again ";
                            cin >> pin1;
                            num2 -= 1;
                            if (num2 < 0) // Keeps track of how many attempts the user has used
                            {
                                cout << "Too many tries, Come back later!" << endl;
                                exit(0);
                            }

                        } while (pin1 != PIN); // only stays in the loop if the condition is met
                    }
                }

            } while (answer == 'y');
        }
        else if

            (answer == 'n')
            ;
        {
            cout << "Have a nice day" << endl;
            exit(0);
        }

    } while (pin1 == PIN);

    return 0;

} /// main