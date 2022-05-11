/**
 *   @file: invoice.cc
 * @author: Levi Finney
 *   @date: 1/29/22
 *  @brief: //Program asks the user what monitor they would like to purchase and from there it goes down with some more
 * //questions like are you from Ohio and how many monitors would you like to buy.
 * //The program then returns an invoice statement based on the useers previous answer.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/// Constants and function prototypes
// Constants variable declaration
const double SAMSUNG_Price = 190.00;
const double VIEWsonic_Price = 170.00;
const double OHIO_TAX = .07;
const double DISCOUNT = .05;
int main(int argc, char const *argv[])
{
    // decimal precision
    cout << fixed << showpoint;
    cout << setprecision(2);
    // integer, decimal, and string variable declaration
    int quantity;
    double total, total1, total2, subtotal, taxes, Discount, total3;
    char monitor_type, response, response1, answer;
    // Question that determines the whole outcome of program
    cout << "What monitor would you like(samsung or viewsonic) and how many?" << endl;
    cout << "s for samsung and v for viewsonic" << endl;
    cin >> monitor_type >> quantity;
    if (monitor_type == 's')
    {
        total = SAMSUNG_Price * quantity; // total base price
        if (quantity >= 3)
        {
            // Calc for total with discount
            total1 = total * DISCOUNT;
            Discount = total1;
            total2 = total - total1;
        }
        else if (quantity < 3)
        {
            // Calc for total no discount
            total1 = total;
            Discount = 0;

            total2 = total;
        }
        // Tax or no tax?
        cout << "Are you from Ohio?(y/n)" << endl;
        cin >> response1;
        if (response1 == 'y')
        {
            // Calc for taxes and final total given Ohio Resident is true
            taxes = total2 * OHIO_TAX;
            total3 = total2 + taxes;
        }
        else if (response1 == 'n')
        {
            // Calc for taxes and final total given Ohio Resident is false
            taxes = 0;

            total3 = total2 + taxes;
        }
        // Output statement
        cout << "Hard Monitor Invoice" << endl;
        cout << "-------------------------------" << endl;
        cout << "Monitor Brand: Samsung" << endl;
        cout << "Quantity:" << quantity << endl;
        cout << "Price: $ " << SAMSUNG_Price << endl;
        if (response1 == 'y')
        {
            cout << "Ohio Resident: Yes" << endl;
        }
        else if (response1 == 'n')
        {
            cout << "Ohio Resident: No" << endl;
        }
        cout << "Total Price: $ " << total << endl;
        cout << "-------------------------------" << endl;
        cout << "Discount: $ " << Discount << endl;
        cout << "Subtotal: $ " << total << endl;
        cout << "Taxes: $ " << taxes << endl;
        cout << "==============================" << endl;
        cout << "Total: $ " << total3 << endl;
        cout << "Have a nice Day!" << endl;
        exit(0);
    }

    // No comments made on this portion of code b/c it is a copy and paste from above
    // only difference is the name from Samsung to Viewsonic along with their respective prices

    else if (monitor_type == 'v')
    {
        total = VIEWsonic_Price * quantity;
    }
    if (quantity >= 3)
    {
        total1 = total * DISCOUNT;
        Discount = total1;
        total2 = total - total1;
    }
    else if (quantity < 3)
    {
        total1 = total;
        Discount = 0;

        total2 = total;
    }
    cout << "Are you from Ohio?(y/n)" << endl;
    cin >> response1;
    if (response1 == 'y')
    {
        taxes = total2 * OHIO_TAX;
        total3 = total2 + taxes;
    }
    else if (response1 == 'n')
    {
        taxes = 0;

        total3 = total2 + taxes;
    }
    cout << "Hard Monitor Invoice" << endl;
    cout << "-------------------------------" << endl;
    cout << "Monitor Brand: ViewSonic" << endl;
    cout << "Quantity:" << quantity << endl;
    cout << "Price: $ " << VIEWsonic_Price << endl;
    if (response1 == 'y')
    {
        cout << "Ohio Resident: Yes" << endl;
    }
    else if (response1 == 'n')
    {
        cout << "Ohio Resident: No" << endl;
    }
    cout << "Total Price: $ " << total << endl;
    cout << "-------------------------------" << endl;
    cout << "Discount: $ " << Discount << endl;
    cout << "Subtotal: $ " << total << endl;
    cout << "Taxes: $ " << taxes << endl;
    cout << "==============================" << endl;
    cout << "Total: $ " << total3 << endl;
    cout << "Have a nice Day!" << endl;
    exit(0);
    return 0;

} /// main
