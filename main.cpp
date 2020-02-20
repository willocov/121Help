#include <iostream>
#include <fstream>
#include <string>
using namespace std;    //Remove this if you cant use the standard namespace, if removed add std:: where needed
int main()
{
    std::string input;

    std::cout << "Welcome to Tuffy Scheduler!" << std::endl;
    std::cout << "Please enter the file name containing the list of classes: ";
    std::cin >> input;

    //Checks for valid file input
    if (input != "sched.txt")
    {
        std::cout << "Invalid File." << std::endl;
        std::cout << "Thank you for using Tuffy Scheduler." << std::endl;
        return 1;
    }
    else
    {
        std::cout << "Valid File." << std::endl;
    }

    //WC - This is your original code
    //not sure what to do with this
    /*
    std::ofstream output_file;
    output_file.open("sched.txt");
    output_file << "Hello World.\n";
    output_file.close();
    */

    //WC - Here is my added code
    std::ifstream file;
    string className, location, days, startTime, endTime, validDays[] = { "M", "T", "W", "H", "F", "MW", "MF", "TH" };
    file.open(input);
    if (file.fail()) {
        cout << "Error: File Does Not Exist\n";
    }
    else {
        while (std::getline(file, className)) {  //This getline call sets line to the first line of the file (cpsc 131)
            getline(file, location);
            //Add location validation here...
            getline(file, days);
            //Add day validation here.
            //check if value of days exists in validDays

            getline(file, startTime);
            getline(file, endTime);
            //Add time validation here
            //I suggest converting times from string to time_t and comparing.
            //Check stack overflow for examples and help
            /*
            From StackOverflow
            You can use strptime(3) to parse the time, and then mktime(3) to convert it to a time_t:
            eg:
                const char *time_details = "16:35:12";
                struct tm tm;
                strptime(time_details, "%H:%M:%S", &tm);
                time_t t = mktime(&tm);  // t is now your desired time_t
            */

            //Loop has ended for this class.
            //When loop begins again, className will be overwritten with next class.
            //If any validations fail, cout error message and break out of loop
        }
    }
    file.close();


    std::cout << "Thank you for using Tuffy Scheduler." << std::endl;
}