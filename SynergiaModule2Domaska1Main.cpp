#include<iostream>
#include<string>
using namespace std;



class Ychitel;
class Stydent;

class Ychitel
{
public:
	void GiveGrades(Stydent &FirstStydent);
};

class Stydent
{

	friend Ychitel;

private:
	int grade;
	static int course;


public:

	Stydent()
	{
		name = "Noname";
		age = 0;
		last_name = "Nolastname";
		course++;
		grade = 0;
	}


	Stydent FirstStydent(string name, int age, string last_name, int grade)
	{
		name = "Noname";
		age = 0;
		last_name = "Nolastname";
		course++;
		grade = 0;
	}


	Stydent(int grade)
	{
		this->grade = grade;
	}

	int age; 
	string name; 
	string last_name; 

	friend void Ychitel::GiveGrades(Stydent &FirstStydent);

	int Getgrade()
	{
		return grade;
	}

	void Setgrade(int valuegrade)
	{
		grade = valuegrade;
	}

	void Print()
	{
		cout << "grade" << &grade << endl;
	}


	static int get_course() 
	{								
		return course;
	}
	
	
	static void new_course() 
	{			  
		course++; 
	}


};

int Stydent::course = 0;


int main()
{
	

	Stydent FirstStydent;
	FirstStydent.age = 18;
	FirstStydent.name = "Ivan";
	FirstStydent.last_name = "Ivanov";
	

	FirstStydent.new_course();
	

	FirstStydent.Setgrade(5);
	int result = FirstStydent.Getgrade();

	cout << "Total course " << Stydent::get_course() << endl;
	cout << result << endl;
	cout << FirstStydent.age << endl;
	cout << FirstStydent.name << endl;
	cout << FirstStydent.last_name << endl;
	

	Ychitel Ychitel;
	
	Ychitel.GiveGrades(FirstStydent);

	return 0;
}

void Ychitel::GiveGrades(Stydent & FirstStydent)
{
	cout << "Give Grades" << FirstStydent.grade << endl;
}

