/**
 * @file appointment_main.cc
 * @author levi finney (lf484020@ohio.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Appointment.h" 

int main(int argc, char const *argv[])
{

    vector<Appointment> agenda;
    string inputfile = "agenda.txt";
    string outFile = "agenda.txt";

  
    load_Data(inputfile, agenda);
    string argWord;
    argWord = argv[1];

  
    
    
    // Part 2 of hw 7 
    if( argc == 1)
    {
        cout << "No command line argument" << endl; 
        return 0; 
    }
    else if (argc == 2 && argWord == "-ps")
    {
      sort(agenda); 
    }
    else if (argc == 3 && argWord == "-p")
    {
        string argWord1 = argv[2];
        printTime(agenda, argWord1);
    }
    else if (argc == 3 && argWord == "-a")
    {
        string argWord2 = argv[2];
        add_Appointment(agenda, argWord2, outFile);
    }
    else if (argc == 3 && argWord == "-dt")
    {
        string argWord3 = argv[2];
        delete_Appointment(agenda, argWord3, outFile);
    }
    else if(argc == 3 && argWord == "-dm")
    {
        string argWord4 = argv[2];
        delete_Time(agenda, argWord4, outFile);
    }
    else
    {
        cout << "Command line invalid";
    }
    
    return 0;
} // main