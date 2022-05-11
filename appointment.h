/**
 * @file appointment.h
 * 
 * @author levi Finney (lf484020ohio.edu)
 * @brief program runs takes a inputs of appointment data and stores it into a vector. Using command line arguments 
 * the user can access different functions and manipulate the appointments. The user is capable of deleting appointments 
 * adding appointments, and even organizing appointments from earliest to latest.  
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


using namespace std;
class Appointment
{
public:
    Appointment(); // default constructor
    Appointment(string appData);

    // Mutators
    /**
     * @brief setTitle 
     * initializes the title variable
     * 
     * @param newTitle 
     */
    void setTitle(string newTitle);
    /**
     * setYear 
     * initializes the year variable 
     * 
     * @param newYear 
     */
    void setYear(int newYear);
    /**
     * setMonth 
     * initializes the month variable 
     * 
     * @param newMonth 
     */
    void setMonth(int newMonth);
    /**
     * setDay 
     * initializes the Day variable
     * 
     * @param newDay 
     */
    void setDay(int newDay);
    /**
     * setTime 
     * initializes the time variable
     * 
     * @param newTime 
     */
    void setTime(int newTime);
    /**
     * setDuration 
     * initializes the Duration variable 
     * 
     * @param newDuration 
     */
    void setDuration(int newDuration);
    /**
     * SetDate 
     * takes information of year, month, and day to format them 
     * 
     * @param newYear 
     * @param newMonth 
     * @param newDay 
     */
    void setDate(int newYear, int newMonth, int newDay);

    // Accessors
    /**
     * getTitle 
     * returns title variable
     * 
     * @return string 
     */
    string getTitle();
    /**
     * getYear 
     * returns year variable 
     * 
     * @return int 
     */
    int getYear();
    /**
     * getMonth 
     * returns month variable
     * 
     * @return int 
     */
    int getMonth();
    /**
     * getDay 
     * returns day variable 
     * 
     * @return int 
     */
    int getDay();
    /**
     * getTime 
     * returns the time variable 
     * 
     * @return int 
     */
    int getTime();
    /**
     * getDuration 
     * returns the duration variable 
     * 
     * @return int 
     */
    int getDuration();
    /**
     * getDate
     * returns date variable in year-month-day format 
     * 
     * @return string 
     */
    string getDate();
    /**
     * getStandardTime
     * returns standard time 
     * 
     * @return string 
     */
    string getStandardTime();

    // Helper Functions
    /**
     * output 
     * returns the getters values 
     * doesn't take a param
     */
    void output();
    /**
     * militaryToStandard
     * takes time in military format and converts it to standard format 
     * 
     * @param time 
     * @return string 
     */
    string militaryToStandard(int time);
    /**
     * standardToMilitary 
     * takes time in standard format and returns it in military 
     * 
     * @param time 
     * @return int 
     */
    int standardToMilitary(string time);
    /**
     * time_of_day 
     * determines whether time in is AM or PM 
     * 
     * 
     * @param getStandardTime 
     * @return true - if time if PM 
     * @return false - if time is AM 
     */
    bool time_of_day(string getStandardTime);
    /**
     * friend bool operator == 
     * compared the data of two appointments
     * 
     * @param first 
     * @param second 
     * @return true - if both appointments are the same
     * @return false - if appointments are different in any way 
     */
    friend bool operator==(const Appointment &first, const Appointment &second);
    /**
     * lower_Case 
     * converts a string to all lower case letters
     * 
     * @param title 
     * @return string 
     */
    string lower_Case(string title); 

private:
    // Member Variables
    string title;
    int year;
    int month;
    int day;
    int time; // Military Time
    int duration;
    string string_military_time;
    int int_military_time;
    string year_string;
    string month_string;
    string day_string;
    string time_string;
    string standardTime;
    string trim_string(string appData);
     
}; 

// Functions
/**
 * load_Data 
 * Function takes each appointment from a file and loads it into a vector 
 * 
 * @param string inputfile - takes an input file to read
 * @param vector <Appointment > agenda 
 */
void load_Data(string inputfile, vector<Appointment> &agenda);

/**
 * printTime 
 * Function prints all appointments at a given time
 * 
 * @param vector <Appointment> agenda 
 * @param string argvWord1 - uses string from agrv command line 
 */
void printTime(vector<Appointment> &agenda, string argvWord1);

/**
 * add_Appointment 
 * function takes an appointment in title | year | month | day | duration format and adds it to 
 * the list if appointments. 
 * 
 * @param vector <Appointment> agenda 
 * @param string argvWord - command line argument, argv, used to know what appointment to add
 * @param string outputFile - outputs updated string to original file
 */
void add_Appointment(vector<Appointment> &agenda, string argvWord, string outputFile);

/**
 * delete_Appointment 
 * function that takes a command line argument and deletes every appointment that mathces the title
 * 
 * @param vector <Appointment>  agenda
 * @param string argvWord -  needs command line argument, argv, to compare the title to each appointment 
 * @param string outputFile - outputs updated appointments into new file 
 */
void delete_Appointment(vector<Appointment> &agenda, string argvWord, string outputFile);

/**
 * delete_Time 
 * delets the appointment if time mathces correctly 
 * @param vector <Appointment> agenda 
 * @param string argvWord - command line argument used to compare the time to each appointment 
 * @param string  outputFile - used to output the updated appointment 
 */
void delete_Time(vector<Appointment> &agenda, string argvWord, string outputFile); 

/**
 * sort
 * sorts vector from earliest time to latest time 
 * @param vector <Appointment> agenda 
 */
void sort (vector <Appointment> &agenda); 
