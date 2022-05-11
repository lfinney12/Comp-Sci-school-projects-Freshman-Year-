/**
 *   @file: card-game.cc
 * @author: Levi Finney
 *   @date: 3/22/22
 *  @brief: This program takes a triangular number  from the command line and plays a card game with it by splitting that number 
 * into a random pile of cards. Once in random piles the game begins. Each round 1 card will be taken from 
 * each pile and that sum creates a new pile of cards. The program reapeats this until the sequence of cards is in 
 * a descending order when the card right next to it subtracts and equals 1. 
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
    // Variable Declaration 
    int numIters; 
    int cards[500];
    int count = 0;
    srand(time(nullptr)); // Seeding randome number generator

    // Function Declaration 
    /**
     * function- isTriangular
     * determines if a number is triangular 
     * 
     * 
     * @param int num - takes an integer as a parameter 
     * @return true - If number is triangular
     * @return false - If number is not triangular
     */
    bool isTriangular(int num);
    /**
     * Function- printArray
     * This function prints an array
     * 
     * 
     * @param int arr- takes an array of integers
     * @param int count- Needs count of elements in array 
     * @return - no return value only prints array 
     */
    
    void printArray(const int arr[], int count);
    /**
     * function - randomNum 
     * generates a random number 
     * 
     * 
     * @param int num - takes an integer as a paramter
     * @return- returns an integer value 
     */
    int randomNum(int num);
    
    /**
     * Function - checkGame 
     * function determines if the game is over by checking if all cards next to one another equals 1
     * 
     * 
     * @param int arr- takes an array of integer elements  
     * @param int count - takes an integer that keeps count of elements in the array 
     * @return true - if condition is met returns true 
     * @return false - if any number next to one another doesn't equal 1
     */
    bool checkGame(int arr[], int count);
    /**
     * Function - sortArray
     * function takes an array of integer elements and arranges them in descending order
     * 
     * 
     * @param int arr - takes an array of integer elements 
     * @param int count - takes an integer used to keep count of all elements in an array
     * @return - doesn't return a value
     */
    void sortArray(int arr[], int count);
    int triNum;
    int cardDeck;
    int counter; 
    int temp; 
    

    // more than two index values in comand line 
    if (argc > 2)
    {
        cout << "Too many arguments" << endl;
        exit(0);
    }
    // if there's not a number in the command line use 45 
   else if( argc == 1) 
   {
      for(int i = 0; i < argc; i++) 
      {
          argv[i] = "45"; 
          
          triNum = atoi(argv[i]); 

      }
   }
   
   // uses number inputted on command line
    for (int i = 0; i < argc; i++)
    {
        
       triNum = atoi(argv[i]);
    }
    if (!isTriangular(triNum))// test to see if number is triangular 

    {
        cout << "Error: The number " << triNum << " is not a triangular Number" << endl;
        exit(0);
    }

    cout << "Number of cards:" << triNum << endl;

    // round 1 (splits deck into first split of piles)
    cardDeck = triNum;
    
    while (cardDeck > 0)
    {
        cards[count] = (rand() % cardDeck + 1);
        cardDeck = cardDeck - cards[count];
        count++;
    }

    sortArray(cards, count);
    printArray(cards, count);
    cout << endl;

    counter = 0;
    numIters = 0; 
    // do-while loop runs rounds until last sequence has met the proper conditions 
    do
    {
        
        for (int i = 0; i < count; i++)
        {
            cards[i]--;// deacreases each number in the array by 1 
            counter = count;
        }

        cards[counter] = count;
        count++; //adds 1 to count so new pile can be added 
        
        sortArray(cards, count);

        temp = count;
        //decreases count by however many zeros there are 
        for (int i = 0; i < temp; i++)
        {
            if (cards[i] == 0)
            {
                count--; 
            }
        }
        // prints each round 
        printArray(cards, count);
        numIters++; // increases rounds by 1 for each print
        cout << endl;
    } while (!checkGame(cards, count)); // check condition 
    cout << "Rounds: " << numIters << endl; // rounds print statement 

    return 0;
} /// main

bool isTriangular(int num) // test to see if a num is triangular
{
    if (num < 0) // base condition
        return false;

    int sum = 0;
    for (int i = 0; i <= num; i++)
    {
        sum = sum + i;
        if (sum == num)
            return true;
    }
    return false;
}

void printArray(const int arr[], int count) // prints elements of an array
{

    for (int i = 0; i < count; i++) // loops through all elements of an array
    {

        cout << arr[i] << '\t';
    }
}

int randomNum(int num) // generates a random number 
{
    int randomNumber = rand();
    randomNumber = randomNumber % num + 1;
    return randomNumber;
}

void sortArray(int arr[], int count) // arranges elements in array in descending order 
{
    int maxIndex;
    int max;
    int originalMax;

    for (int i = 0; i < count; i++)
    {
        // max starts at index 0
        max = arr[i];
        originalMax = arr[i];
        // compares max to new index position
        for (int currentPos = i + 1; currentPos < count; currentPos++)
        {
            if (arr[currentPos] > max)
            {
                max = arr[currentPos];
                maxIndex = currentPos;
            }
        }
        // swaps values index position
        if (max != originalMax)
        {
            swap(arr[i], arr[maxIndex]);
        }
    }
}

bool checkGame(int arr[], int count) // checks to see if triangular sequence is met
{
    for (int i = 0; i < count; i++)
    {
        // if any two values next to each other do not equal 1 when subtracted return false 
        if (arr[i] - arr[i + 1] != 1)
        {
            return false;
        }
    }
    return true;
}

