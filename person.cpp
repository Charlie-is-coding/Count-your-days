#include <iostream>
#include <time.h>
#include <math.h>
#include "person.h"

using namespace std;

void Person::show_name()
    {
        cout<< name <<endl;
    }

void Person::change_name()
    {
        cout<<"Type your name: "<<endl;
        cin>>name;
        cout<<"Name changed to:" <<name<<endl;
    }

void Person::change_day_of_birth()
    {
        cout<<"Type your date of birth: [dd.mm.yyyy]"<<endl;
        cin>>dateOfBirth;

        int length = dateOfBirth.length();
        while ((dateOfBirth[2] != 46) && (dateOfBirth[5] !=46) || (length != 10))
        {
            cout<<"Wrong format, please try again:"<<endl;
            cin>>dateOfBirth;
            length = dateOfBirth.length();
            cout<<length;
        }

        cout<<"Date of birth set to: " << dateOfBirth<<endl;
    }

void Person::show_days()
    {
        time_t now;
        struct tm date;
        double seconds;
        string dateString = dateOfBirth;

        time(&now);

        int lengthOfDatestring = dateString.length();
        cout<<"\n"<<endl;

        int day = +(dateString[0] - '0')*10 + +(dateString[1] - '0');
//        cout<<"Day: "<< day<<endl;

        int month = +(dateString[3] - '0')*10 + +(dateString[4] - '0')-1;
//        cout<<"Month: "<<month+1<<endl;

        int year = +(dateString[6] - '0')*1000 + +(dateString[7] - '0')*100 + +(dateString[8] - '0')*10 + +(dateString[9] - '0');
//        cout<<"Year: "<<year<<endl;

        date = *localtime(&now);

        date.tm_hour = 0; date.tm_min = 0; date.tm_sec = 0;
        date.tm_year=year-1900; date.tm_mon = month;  date.tm_mday = day;

        time_t x =mktime(&date);
        char* dateToPrint = ctime(&x);
        cout<<"Counting days from: "<<dateToPrint<<endl;

        seconds = difftime(now,mktime(&date));
        cout<< floor(seconds/86400) <<" days passed since the given date...\n"<<endl;
        }

void Person::count_days()
    {
            time_t now;
            struct tm date;
            double seconds;
            string dateString = dateOfBirth;

            time(&now);

            date = *localtime(&now);
            time_t x =mktime(&date);

            int year = +(dateString[6] - '0')*1000 + +(dateString[7] - '0')*100 + +(dateString[8] - '0')*10 + +(dateString[9] - '0');
            cout<<"You were born in: "<< year<<endl;
            cout<<"You live: "<< date.tm_year - year + 1900<<endl;

            cout<<"\nHow many years do you want to live?"<<endl;
            int yearsToLive;
            cin>>yearsToLive;
            cout<<"You have " << (yearsToLive - (date.tm_year - year + 1900))<<" years left."<<endl;

            char* dateToPrint = ctime(&x);
            cout<<"Counting from today: "<<dateToPrint<<endl;

            date.tm_year += yearsToLive - (date.tm_year - year + 1900);

            time_t y =mktime(&date);
            char* dateOfDeath = ctime(&y);
            cout<<"You will die: "<<dateOfDeath<<endl;
            seconds = difftime(now,mktime(&date));
            cout<< abs(floor(seconds/86400)) <<" days left. Your days are counted.\n"<<endl;
        }
