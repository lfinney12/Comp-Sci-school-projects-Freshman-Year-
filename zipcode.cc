/**
 *   @file: zipcode.cc(files version)
 * @author: Levi Finney
 *   @date: 2/28/22
 *  @brief: This program takes two inputted files, a input and output, from there it will read each line of
 * the input file and determine if teh zipcode is valid. If valid the program will return the zipcode bar code 
 * to the output file and if not valid the output file will return an error message at the line of the zipcode.
 * 
 * 
 * 
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{

    // variable declarations
    char checkCode;
    int sum, checkDigit, num;
    /**
     * function- isValid
     * this function takes a string zipcode and runs through each digit to make sure it's a digit
     *
     * @param string zipcode - function takes a zipcode in the form of a string
     * @return - returns true or false
     * */

    bool isValid(string zipcode);
    /**
     * Function: get_digit_code
     *          returns the code equivalent of a single digit
     *
     * @param char digit - integer in character form
     * @return- the barcode equivalent of a number
     */
    string get_digit_code(char digit);

    /**
     * Function: getCheckDigitValue
     *            returns the check digit for an inputted zipcode
     *
     *
     * @param int sum - takes the sum of a zipcode/range of numbers
     * @return- returns a check digit value
     */

    int getCheckDigitValue(int sum);

    /**
     * Function - digitsum
     *             calculates and returns a sum 5 numbers
     *
     *
     * @param a - integer value
     * @param b - integer value
     * @param c - interger value
     * @param d - interger value
     * @param e - interger value
     * @return- returns the sum of 5 numbers
     */
    int digitSum(int a, int b, int c, int d, int e);
    // More variable Declaration
    string zipcode;
    int digit1, digit2, digit3, digit4, digit5;
    // do-while loop keeps function running an infinite number of times
    
    // intsream and oustream object declaration 
    ifstream instream;
    ofstream outstream;
    string filename, outputFile;
    cout << "Enter the name of input file: ";
    cin >> filename;
    // checks to see if file was opened 
    instream.open(filename);

    if (instream.fail())
    {
        cout << "Error: File doesn't exist: " << filename << endl;
        exit(0);
    }
    cout << "Enter the name of output file: ";
    cin >> outputFile;
    
    // checks to see if output file is was opened correctly 
    outstream.open(outputFile);
    if (outstream.fail())
    {
        cout << "Error: File doesn't exist: " << outputFile << endl;
        exit(0);
    }

    instream >> zipcode;// first zipcode from input file 

    do
    {
       

        if (isValid(zipcode))
        {
            num = stoi(zipcode); // zipcode goes from string to integer

            // Separated each digit 1 by 1 to find the sum
            digit5 = num % 10;
            num = num / 10;
            digit4 = num % 10;
            num = num / 10;
            digit3 = num % 10;
            num = num / 10;
            digit2 = num % 10;
            num = num / 10;
            digit1 = num;

            sum = digitSum(digit1, digit2, digit3, digit4, digit5);

            checkDigit = getCheckDigitValue(sum);

            checkCode = '0' + checkDigit; // converts int to char to be used in getDigitCode function

            // returns each difgit in their code format to be printed
            string ch1 = get_digit_code(zipcode.at(0));
            string ch2 = get_digit_code(zipcode.at(1));
            string ch3 = get_digit_code(zipcode.at(2));
            string ch4 = get_digit_code(zipcode.at(3));
            string ch5 = get_digit_code(zipcode.at(4));
            string check_code = get_digit_code(checkCode);
            outstream << zipcode << ": ";
            outstream << "| " << ch1 << " " << ch2 << " " << ch3 << " " << ch4 << " " << ch5 << " " << check_code << " |" << endl;
        }
        // else if and else block prints an error message if the zipcode isn't valid in the output text file  
        else if (zipcode.length() != 5)
        {
            outstream << zipcode << ":"
                      << "Error: Zipcode must be 5 digits" << endl;
        }
        else
        {
            outstream << zipcode << ":"
                      << "Error: illegal character" << endl;
        }
        instream >> zipcode;// updates to the next line in input file 
    } while (!instream.eof());
    cout << "Done, the files are in " << outputFile << endl;


    // closes instream and outstream 
    instream.close();
    outstream.close();
    return 0;
} /// main

string get_digit_code(char digit) // returns the code conversion of a digit
{
    if (digit == '0')
        return "||:::";
    else if (digit == '1')
        return ":::||";
    else if (digit == '2')
        return "::|:|";
    else if (digit == '3')
        return " ::||:";
    else if (digit == '4')
        return ":|::|";
    else if (digit == '5')
        return ":|:|:";
    else if (digit == '6')
        return ":||::";
    else if (digit == '7')
        return "|:::|";
    else if (digit == '8')
        return "|::|:";
    else
        return "|:|::";

} // Function
int digitSum(int a, int b, int c, int d, int e) // gives the sum 5 digits
{
    int result = a + b + c + d + e;
    return result;
}
int getCheckDigitValue(int sum) // returns check digit value of a sum

{

    int check;
    int num2;
    num2 = sum;
    do
    {
        if (sum % 10 == 0)
        {
            break;
        }
        sum = sum + 1;

    } while (sum % 10 != 0);
    check = sum - num2;

    return check;
}
bool isValid(string zipcode) // returns true if zipcode is valid
{

    if (zipcode.length() != 5) // allows the user to continuously renter the zipcode when wrong
    {
        return false;
    }
    for (int count = 0; count <= 4; count++) // goes through each value to make sure it is a digit
    {
        if (!isdigit(zipcode.at(count)))
        {
            return false;
        }
    }
    return true;
}