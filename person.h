#include <iostream>

using namespace std;

class Person
{
	public:
	string name = "";
    	string dateOfBirth = "";

    	Person()
    	{
        change_name();
        change_day_of_birth();
    	}
	
	void show_name();
	void change_name();
	void change_day_of_birth();
	void show_days();
	void count_days();
};

