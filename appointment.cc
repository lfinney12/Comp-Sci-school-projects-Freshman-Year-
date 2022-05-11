/**
 * @file appointment.cc
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

Appointment::Appointment() // deafault constructor that initializes member variables
{
    title = "N/A";
    month = 1;
    day = 1;
    year = 1;
    time = 0;
    duration = 1;
}

Appointment ::Appointment(string appData)
{
    string title_holder;
    string time_holder;

    int location = appData.find("|");
    title = appData.substr(0, location);

    title = trim_string(title);
    title = lower_Case(title);

    year = stoi(appData.substr(location + 1, appData.find("|", location + 1) - location - 1));

    location = appData.find("|", location + 1);
    month = stoi(appData.substr(location + 1, appData.find("|", location + 1) - location - 1));

    location = appData.find("|", location + 1);
    day = stoi(appData.substr(location + 1, appData.find("|", location + 1) - location - 1));

    location = appData.find("|", location + 1);
    standardTime = appData.substr(location + 1, appData.find("|", location + 1) - location - 1);
    standardTime = trim_string(standardTime);
    standardTime = lower_Case(standardTime);

    location = appData.find("|", location + 1);
    duration = stoi(appData.substr(location + 1, appData.find("|", location + 1) - location));
}

// Mutator Functions
void Appointment::setTitle(string newTitle) // tests title's deafult condition
{
    if (newTitle != "")
    {
        title = newTitle;
    }
}

void Appointment::setYear(int newYear) // test year's deafult condition
{
    if (newYear >= 0)
    {
        year = newYear;
    }
}

void Appointment::setMonth(int newMonth) // tests month's default condition
{
    if (newMonth >= 0 && newMonth <= 12)
    {
        month = newMonth;
    }
}

void Appointment ::setDay(int newDay) // tests day's default condition
{
    if (newDay >= 0 && newDay <= 31)
    {
        day = newDay;
    }
}

void Appointment ::setTime(int newTime) // tests time's deafult condition
{
    if (newTime >= 0)
    {
        time = newTime;
    }
}

void Appointment ::setDuration(int newDuration) // tests duration's default condition
{
    if (newDuration >= 0)
    {
        duration = newDuration;
    }
}

void Appointment ::setDate(int newYear, int newMonth, int newDay) // sets date
{
    year = newYear;
    month = newMonth;
    day = newDay;
}

// Accessor Functions

string Appointment::getTitle() // returns title of meeting
{
    return title;
}

int Appointment::getYear() // returns year
{
    if (year == 1)
    {
        cin.ignore();
    }
    return abs(year);
}

int Appointment::getMonth() // returns month
{
    return month;
}

int Appointment::getDay() // returns day
{
    return day;
}

int Appointment ::getTime() // returns time in military
{

    return standardToMilitary(standardTime);
}

string Appointment ::getDate() // returns date in year-month-day form
{
    year_string = to_string(abs(year));
    month_string = to_string(month);
    day_string = to_string(day);
    if (month_string.size() == 1)
    {
        month_string = '0' + to_string(month);
    }
    return year_string + '-' + month_string + '-' + day_string;
}

string Appointment ::getStandardTime() // returns standard time
{
    return standardTime;
}

int Appointment ::getDuration()
{
    return duration;
}

// Helper Functions
void Appointment::output() // prints data for testing
{
    cout << title << year << month << day << standardTime << duration;
}

string Appointment ::militaryToStandard(int time) // converts date from military time to standard time
{
    string timeS = to_string(time);
    vector<char> minutes;
    vector<char> hour;
    int size = timeS.size();
    // keeps track of each minute placement
    string mins1;
    string mins2;
    string mins;
    // Keeps track of each hour placement
    string hr1;
    string hr2;
    string hrs;
    int hour_int;

    if (time == 0)
    {
        hrs = "12";
        mins = "00";
        standardTime = hrs + ':' + mins + "AM";
        return standardTime;
    }
    else if (size == 2)
    {
        hrs = "12";
        mins = timeS;
        standardTime = hrs + ':' + mins + "AM";
        return standardTime;
    }

    // gives me the hour
    if (size == 4) // if military time is 4 digits then standard time will be comprised of two digits that represent the hour
    {
        for (int i = 0; i < size; i++)
        {

            hour.push_back(timeS.at(i));
        }
        hr1 = hour.at(0);
        hr2 = hour.at(1);
        mins1 = hour.at(2);
        mins2 = hour.at(3);
        hrs = hr1 + hr2;
        mins = mins1 + mins2;
    }

    else if (size == 3) // only 1 didgit will represent the hour hand
    {
        for (int i = 0; i < size; i++)
        {

            hour.push_back(timeS.at(i));
        }
        hrs = hour.at(0);

        mins1 = hour.at(1);
        mins2 = hour.at(2);
        mins = mins1 + mins2;
    }

    hour_int = stoi(hrs); // converts to int so I can use to comapre the value to 12

    // Test to see if value if less than 12  == AM
    if (hour_int < 12)
    {

        standardTime = hrs + ':' + mins + "AM";
    }
    // Test to see if hours is greater than 12 == PM
    else if (hour_int >= 12)
    {
        if (hour_int == 12)
        {
            hrs = to_string(hour_int);
            standardTime = hrs + ':' + mins + "PM";
        }
        // test to see if hour == 24 if so it changes to AM instead of PM
        else if (hour_int == 24)
        {
            hour_int -= 12;
            hrs = to_string(hour_int);
            standardTime = hrs + ':' + mins + "AM";
        }
        else
        {
            hour_int -= 12; // Subtracts 12 from hours to get standard time in hours
            hrs = to_string(hour_int);
            standardTime = hrs + ':' + mins + "PM";
        }
    }

    return standardTime;
}

int Appointment ::standardToMilitary(string standardTime)
{
    string nums[5];
    int size = 0;
    int hrs_int;

    string twelve = "12";
    string hr1;
    string hr2;
    string min1;
    string min2;
    string hrs;
    string mins;

    for (size_t i = 0; i < standardTime.size(); i++) // loads each hr and min value into an array
    {
        if (isdigit(standardTime.at(i)))
        {
            nums[i] = standardTime.at(i);
            size++;
        }
    }
    hr1 = nums[0];
    hr2 = nums[1];

    min1 = nums[2];

    min2 = nums[3];

    if (standardTime == "12:00 AM" || standardTime == "12:00 aM" || standardTime == "12:00 Am" || standardTime == "12:00 am")
    {
        int_military_time = 0;
        return int_military_time;
    }

    if (size == 3 && !time_of_day(standardTime)) // needs to read AM
    {
        hrs = hr1;
        mins = min1 + min2;
        string_military_time = hrs + mins;
        int_military_time = stoi(string_military_time);
        return int_military_time;
    }
    else if (size == 3 && time_of_day(standardTime)) // needs to read PM
    {
        hrs = hr1;
        mins = min1 + min2;
        hrs_int = stoi(hrs) + 12;
        string_military_time = to_string(hrs_int) + mins;
        int_military_time = stoi(string_military_time);
        return int_military_time;
    }
    else if (size == 4 && !time_of_day(standardTime)) // size must be 4 and AM must be read
    {

        hr1 = nums[0];
        hr2 = nums[1];

        min1 = nums[3];
        min2 = nums[4];
        hrs = hr1 + hr2;

        if (stoi(hrs) == 12) // odd condition since if 12 we must add to proper military time
        {

            mins = min1 + min2;

            string_military_time = mins;
            int_military_time = stoi(string_military_time);
            return int_military_time;
        }
        else
        {
            hrs = hr1 + hr2;
            mins = min1 + min2;
            string_military_time = hrs + mins;
            int_military_time = stoi(string_military_time);
            return int_military_time;
        }
    }
    else
    {
        hr1 = nums[0];
        hr2 = nums[1];

        min1 = nums[3];
        min2 = nums[4];
        hrs = hr1 + hr2;

        if (stoi(hrs) == 12)
        {

            mins = min1 + min2;
            string_military_time = hrs + mins;
            int_military_time = stoi(string_military_time);
            return int_military_time;
        }
        else
        {
            hrs = hr1 + hr2;
            mins = min1 + min2;
            hrs_int = stoi(hrs) + 12;
            string_military_time = to_string(hrs_int) + mins;
            int_military_time = stoi(string_military_time);
            return int_military_time;
        }
    }

    return 0;
}

string Appointment ::trim_string(string appData) // trims leading and trailing spaces from a string
{
    int i = 0;
    int j = appData.length() - 1;

    while (isspace(appData.at(i))) // counts up 1 when a space is read, starting from the front
    {
        i++;
    }
    while (isspace(appData.at(j))) // counts up one when a space is read starting from the back
    {
        j--;
    }

    appData = appData.substr(i, j - i + 1); // pulls characters between first letter and last letter
    return appData;
}

bool Appointment ::time_of_day(string standardTime) // returns false if PM is read
{
    string str1;
    string str2;
    string str3;
    string str4;

    str1 = "PM"; // word I am searching for
    str2 = "pM";
    str3 = "Pm";
    str4 = "pm";

    size_t found = standardTime.find(str1);
    size_t found1 = standardTime.find(str2);
    size_t found2 = standardTime.find(str3);
    size_t found3 = standardTime.find(str4);
    if (found != string::npos || found1 != string::npos || found2 != string::npos || found3 != string::npos)
    {
        return true;
    }
    else
        return false;
}

bool operator==(const Appointment &first, const Appointment &second) // sees if titles match
{

    if (first.title == second.title && first.year == second.year && first.month == second.month &&
        first.day == second.day && first.standardTime == second.standardTime && first.duration == second.duration)
    {
        return true;
    }
    else
        return false;
}

string Appointment ::lower_Case(string title) // converts string to all Lower Case
{
    for (size_t i = 0; i < title.size(); i++)
    {
        title.at(i) = tolower(title.at(i));
    }

    return title;
}

void load_Data(string inputfile, vector<Appointment> &agenda) // loads vector with appointments from file 
{
    ifstream input;
    string line;
    input.open(inputfile);

    if (input.fail())
    {
        cout << "Error: File can't be opened" << endl;
    }

    //int i = 0;
    while (getline(input, line))
    {
        if (line.find("|") != string ::npos) 
        {
            Appointment a(line);
            agenda.push_back(a);
            // cout << agenda.at(i).getTime() << endl;
            //i++;
        }
        else continue; 
    }

    input.close();
}



void printTime(vector<Appointment> &agenda, string argvWord1) // prints the appointments with the same time
{
    Appointment a;

    for (size_t i = 0; i < agenda.size(); i++)
    {
        if (to_string(agenda.at(i).getTime()) == argvWord1)
        {
            cout << agenda.at(i).getTitle() << "|" << agenda.at(i).getYear() << "|" << agenda.at(i).getMonth() << "|" << agenda.at(i).getDay() << "|" << agenda.at(i).getStandardTime() << "|" << agenda.at(i).getDuration() << endl;
        }
    }
}

void add_Appointment(vector<Appointment> &agenda, string argvWord, string outputFile) // ads an appointment from a command line argument
{
    ofstream out;
    out.open(outputFile);

    if (out.fail())
    {
        cout << "Error: File can't be opened" << endl;
    }

    Appointment a(argvWord); // initialization of added appointment
    agenda.push_back(a);

    for (size_t i = 0; i < agenda.size(); i++)
    {
        out << agenda.at(i).getTitle() << "|" << agenda.at(i).getYear()
            << "|" << agenda.at(i).getMonth() << "|"
            << agenda.at(i).getDay() << "|" << agenda.at(i).getStandardTime() << "|"
            << agenda.at(i).getDuration() << endl;
    }

    out.close();
    cout << "Done file is in " << outputFile;
}

void delete_Appointment(vector<Appointment> &agenda, string argvWord, string outputFile)
{
    ofstream out;
    out.open(outputFile);

    if (out.fail())
    {
        cout << "Error: File can't be opened" << endl;
    }

    transform(argvWord.begin(), argvWord.end(), argvWord.begin(), ::tolower); // changes title to lowercase from command line

    // erases all elements that match the title in the command line
    for (size_t i = 0; i < agenda.size(); i++)
    {
        if (agenda.at(i).getTitle() == argvWord)
        {
            agenda.erase(agenda.begin() + i);
        }
    }
    // reprints all new elements that don't match the command line argument
    for (size_t i = 0; i < agenda.size(); i++)
    {
        out << agenda.at(i).getTitle() << "|" << agenda.at(i).getYear()
            << "|" << agenda.at(i).getMonth() << "|"
            << agenda.at(i).getDay() << "|" << agenda.at(i).getStandardTime() << "|"
            << agenda.at(i).getDuration() << endl;
    }

    out.close();
    cout << "Done file is in " << outputFile;
}

void delete_Time(vector<Appointment> &agenda, string argvWord, string outputFile)
{
    ofstream out;
    out.open(outputFile);

    if (out.fail())
    {
        cout << "Error: File can't be opened" << endl;
    }

    for (size_t i = 0; i < agenda.size(); i++)
    {
        // deletes element thats time mathces with command line argument
        if (to_string(agenda.at(i).getTime()) == argvWord)
        {
            agenda.erase(agenda.begin() + i);
        }
        
        

            out << agenda.at(i).getTitle() << "|" << agenda.at(i).getYear()
                << "|" << agenda.at(i).getMonth() << "|"
                << agenda.at(i).getDay() << "|" << agenda.at(i).getStandardTime() << "|"
                << agenda.at(i).getDuration() << endl;
    }

    out.close();
    cout << "Done file is in " << outputFile;
}



void sort (vector <Appointment> &agenda) // sorts time from earliest to lates 
{
    int minindex; 
    int minValue; 

    for (size_t i = 0; i < agenda.size(); i++) // iterates me through the vector 
    {
        minindex = i; 
        minValue = agenda.at(i).getTime(); 
        // j = i + 1 so the next index can be compared to i
        for (size_t j = i + 1; j < agenda.size(); j++ )
        {
            // performs my comparisons
            if (agenda.at( j).getTime() < minValue) 
            {
                minValue = agenda.at(j).getTime(); 
                minindex = j; 
            }
        }

        swap(agenda.at(minindex), agenda.at(i)); 
        

    }

    for (size_t i = 0; i < agenda.size(); i++) // prints out Appointments in order
    {
        cout <<  agenda.at(i).getTitle() << "|" << agenda.at(i).getYear()
                << "|" << agenda.at(i).getMonth() << "|"
                << agenda.at(i).getDay() << "|" << agenda.at(i).getStandardTime() << "|"
                << agenda.at(i).getDuration() << endl;
    }

}
