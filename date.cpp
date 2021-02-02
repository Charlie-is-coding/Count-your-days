#include <iostream>
#include <time.h>
#include <math.h>
#include "person.h"


using namespace std;

int main ()
{
    Person osoba;

    //simple menu
    int choice;

    while (choice != 5)
    {
        cout<<"Choose option:"
        "\n1. Change name."
        "\n2. Show days from the day of birth."
        "\n3. Count days to death."
        "\n4. Change date of birth."
        "\n5. Exit."<<endl;
        cin>>choice;

        switch (choice)
        {
            case 1:
            {
                osoba.change_name();
            break;
            }

            case 2:
            {
                osoba.show_days();
            break;
            }

            case 3:
            {
                osoba.count_days();
            break;
            }
            case 4:
            {
                osoba.change_day_of_birth();
            break;
            }
            case 5:
                cout<<"Exit"<<endl;
        }
    }
  return 0;
}
