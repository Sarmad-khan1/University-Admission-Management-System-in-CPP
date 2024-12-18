#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// global variables
string name, password, role;

const int size = 1000;
string student[size];
float rolls[size];
string department[size];
float fsc[size];
float ecat[size];
float merit[size];
string email[size];
int phone[size];
string cnic[size];
bool announce;

int studentCount = 0;

// prototypes
int opt();
void header();
void submenu();
int admininterface();
void signin();
void addstudentMenu();
void studentdata();
void viewStudent();
void aggregate();
void removeStudent();
void generateMeritList();
void ViewMeritList();
int studentinterface();
void studentapplicationdata();
bool announceResult();
void announcement();
void viewApplicationofstudent();

// bool isExitKeyPressed();

// Main function---DRIVER CODE
int main()
{
	while (true)
	{
		system("cls");
		submenu();
		int option = opt();
		if (option == 1)
		{
			while (true)
			{
				signin();
				if (role == "admin")
				{
					header();
					while (true)
					{
						int adminn = admininterface();
						if (adminn == 1)
						{
							addstudentMenu();
							studentdata();
							aggregate();
							generateMeritList();
						}
						else if (adminn == 2)
						{
							viewStudent();
							char x;
							cout << endl;
							cout << "\033[34mPress any key to continue... \033[0m";
							cin >> x;
						}
						else if (adminn == 3)
						{
							removeStudent();
						}
						else if (adminn == 4)
						{
							announcement();
							char z;
							cout << endl;
							cout << "\033[34mPress any key to continue... \033[0m";
							cin >> z;
						}
						else if (adminn == 5)
						{
							announceResult();
						}
						else if (adminn == 6)
						{
							break;
						}
					}
				}
				if (role == "student")
				{

					header();
					while (true)

					{
						int optionstudentInterface = studentinterface();
						if (optionstudentInterface == 1)
						{
							studentapplicationdata();
							aggregate();
						}
						else if (optionstudentInterface == 2)
						{
							// update Information Function call here
						}
						else if (optionstudentInterface == 3)
						{
							viewApplicationofstudent();
							cout << "\033[34mPress any key to continue.. \033[0m";
							char t;
							cin >> t;
						}
						else if (optionstudentInterface == 4)
						{
							announcement();
							char q;
							cout << "\033[34mPress any key to continue... \033[0m";
							cin >> q;
						}

						else if (optionstudentInterface == 5)
						{
							break;
						}
					}
				}
				break;
			}
		}
		if (option == 2)
		{

			break;
		}
	}
}
// bool isExitKeyPressed()
// {
// 	if (GetAsyncKeyState(VK_ESCAPE))
// 	{ // VK_ESCAPE is the code for the Escape key
// 		return true;
// 	}
// 	return false;
// }
void viewApplicationofstudent()
{
	system("cls");
	header();
	cout << endl;
	cout << "\033[34m Student Interface >>\033[0m \033[33m View Application \033[0m" << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;

	// cout<<"No."<<"\t\t\t"<<"Name"<<"\t\t\t"<<"Cnic"<<"\t\t\t"<<"Matric"<<"\t\t\t"<<"Fsc"<<"\t\t\t"<<"ECAT"<<"\t\t\t"<<endl;
	// cout<<endl;
	// cout<<studentCount<<"\t\t\t"<<student[studentCount]<<"\t\t\t"<<cnic[studentCount]<<"\t\t\t"<<rolls[studentCount]<<"\t\t\t"<<fsc[studentCount]<<"\t\t\t"<<ecat[studentCount]<<"\t\t\t"<<endl;

	cout << "\033[33m Enter you CNIC number to track your Application >> \033[0m";
	string cnicNumber;
	cin >> cnicNumber;
	cout << endl;
	int a = -1;
	for (int i = 0; i < studentCount; i++)
	{
		if (cnic[i] == cnicNumber)
		{
			a = i;
			break;
		}
	}
	if (a >= 0)
	{
		cout << "\033[32m  1)  Application No. >  \033[0m" << a << endl; // Display student number (1-indexed)
		cout << endl;
		cout << "\033[32m  2)  Cnic >  \033[0m" << cnic[a] << endl;
		cout << endl;
		cout << "\033[32m  3)  Name >  \033[0m" << student[a] << endl;
		cout << endl;
		cout << "\033[32m  4)  Matric Marks \033[0m>  " << rolls[a] << endl;
		cout << endl;
		cout << "\033[32m  5)  Fsc Marks >  \033[0m" << fsc[a] << endl;
		cout << endl;
		cout << "\033[32m  6)  Ecat Marks >  \033[0m" << ecat[a] << endl;
		cout << endl;
		cout << "\033[32m  7)  Aggregate >  \033[0m" << merit[a] << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "\033[33m No record found!!! \033[0m" << endl;
	}
	cout << endl;
}
bool announceResult()
{
	char result;
	cout << "\033[33m Press 'y' to announce result: \033[0m";
	cin >> result;
	cout << endl;
	if (result == 'y' || result == 'Y')
	{
		announce = true;
	}
	else
	{
		announce = false;
	}
	return announce;
}
void announcement()
{

	system("cls");
	header();
	if (announce)
	{
		cout << "\033[34m Results have been announced! \033[0m" << endl;
		cout << endl;
		generateMeritList();
		ViewMeritList();
	}
	else
	{
		cout << "\033[34m Result not announced!! \033[0m" << endl;
		cout << endl;
	}
}

void studentapplicationdata()
{
	system("cls");
	header();
	cout << "\033[34mStudent Interface >> \033[0m" << "\033[34mApply in a Degree\033[0m" << endl;
	cout << "\033[33m-------------------------------------------------------------\033[0m" << endl;
	cout << endl;
	while (true)
	{
		system("cls");
		header();
		cout << "\033[33mStudent Interface  >> \033[0m \033[33m Apply in a Degree Program \033[0m" << endl;
		cout << endl;
		cout << "\033[32m  Student \033[0m" << studentCount + 1 << "\033[32m Name: \033[0m";
		cin >> student[studentCount];
		cout << "\033[32m  Educational background: \033[0m" << endl;
		cout << endl;
		while (true)
		{
			cout << "\033[32m  Enter cnic (without Dashes): \033[0m";
			cin >> cnic[studentCount];
			cout << endl;
			if (cnic[studentCount].length() != 13)
			{
				cout << "\033[34m Invalid cnic!!! Re-enter Your cnic.. \033[0m" << endl;
				cout << endl;
				continue;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "\033[32m  Matric Marks: \033[0m";
			cin >> rolls[studentCount];
			cout << endl;
			if (rolls[studentCount] > 1100 || rolls[studentCount] < 0)
			{
				cout << "\033[32m Invalid Marks!!!! \033[0m" << endl;
				cout << endl;
				continue;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "\033[32m  Fsc Marks: \033[0m";
			cin >> fsc[studentCount];
			cout << endl;
			if (fsc[studentCount] < 0 || fsc[studentCount] > 1100)
			{
				cout << "\033[32m Invalid Marks!!! \033[0m" << endl;
				cout << endl;
				continue;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "\033[32m  Ecat Marks: \033[0m";
			cin >> ecat[studentCount];
			cout << endl;
			if (ecat[studentCount] < 0 || ecat[studentCount] > 400)
			{
				cout << "\033[32m Invalid Marks!!! \033[0m";
				continue;
			}
			else
			{
				break;
			}
		}
		cout << endl;
		cout << "\033[32m  Do you want to re-write your data? (y or n): \033[0m";
		char choize;
		cin >> choize;
		if (choize == 'y' || choize == 'Y')
		{
			continue;
		}
		else
		{
			studentCount++;
			break;
		}
		aggregate();
	}
}
int studentinterface()
{
	system("cls");
	header();
	cout << "\033[34m Student Interface >>\033[0m" << endl;
	cout << "\033[34m------------------\033[0m" << endl;
	cout << endl;
	cout << "\033[35m Select one of the following: \033[0m" << endl;
	cout << endl;

	cout << "\033[36m  1. Apply in a Degree Program \033[0m" << endl;
	cout << endl;
	cout << "\033[36m  2. Update Information \033[0m" << endl;
	cout << endl;
	cout << "\033[36m  3. View your application \033[0m" << endl;
	cout << endl;
	cout << "\033[36m  4. See results\033[0m \033[35m>> \033[0m" << endl;
	cout << endl;
	cout << "\033[36m  5. Move back to Sign-in Interface\033[0m" << endl;
	cout << endl;
	cout << "\033[30m  Your Option \033[0m";

	int option;
	cin >> option;

	// if (isExitKeyPressed())
	// {
	// 	cout << "Exiting program..." << endl;
	// 	exit(0); // Exit the program
	// }

	return option;
}
void removeStudent()
{
	system("cls");
	header();
	cout << "\033[32m Remove Student >>\033[0m" << endl;
	cout << endl;
	while (true)
	{
		string removeName;
		cout << "\033[32m  Enter Student name to remove >> \033[0m";
		cin >> removeName;
		cout << endl;
		int a = -1; // this is just random value to see if value of a changed or not to see if student found in array or not.
		for (int i = 0; i < studentCount; i++)
		{
			if (student[i] == removeName)
			{
				a = i; // value of a got changed from -1. becoz now a=i and i is the index number of the array where stu name is found.
				break; // Loop will break upon getting condition true.
			}
		}
		if (a == -1) // validaiton to handle case when value of a didn't changed.
		{
			cout << "\033[31m  Student not found \033[0m" << endl;
			cout << endl;
			return;
		}
		for (int i = a; i < studentCount; i++) // drifting index of array from right to left by 1 point.
		{
			student[i] = student[i + 1];
			rolls[i] = rolls[i + 1];
			fsc[i] = fsc[i + 1];
			ecat[i] = ecat[i + 1];
			merit[i] = merit[i + 1];
		}
		cout<<"\033[33m Student Removed Successfully!!! \033[0m"<<endl;
		cout << endl;
		cout << "\033[31m  Do you want to remove another student? ( y or n): \033[0m";
		char s;
		cin >> s;

		if (s == 'y' || s == 'Y')
		{
			continue;
		}
		else
		{
			break;
		}
	}
}
void viewStudent()
{
	system("cls");
	header();
	cout << "\033[32m View All Students >> \033[0m" << endl;
	cout << "\033[33m------------------------------------------------------------------------------------------------------\033[0m" << endl;
	cout << endl;
	cout << "\033[32mName \033[0m" << "\t\t" << "\033[32mMatric Marks \033[0m" << "\t\t" << "\033[32mFsc Marks \033[0m" << "\t\t" << "\033[32mECAT \033[0m" << "\t\t" << "\033[32mAggregate \033[0m" << endl;
	cout << endl;

	for (int i = 0; i < studentCount; i++)
	{
		cout << student[i] << "\t\t" << rolls[i] << "\t\t\t" << fsc[i] << "\t\t\t" << ecat[i] << "\t\t" << merit[i] << endl;
		cout << endl;
	}
}
void studentdata()
{
	system("cls");
	header();
	cout << "\033[33m  Add Students >>\033[0m" << endl;
	cout << endl;
	while (true)
	{
		system("cls");
		header();
		cout << "\033[33m  Student \033[0m" << studentCount + 1 << "\033[33m name: \033[0m";
		cin >> student[studentCount];
		cout << endl;
		while (true)
		{
			cout << "\033[33m  Matric Marks: \033[0m";

			cin >> rolls[studentCount];
			cout << endl;
			if (rolls[studentCount] < 0 || rolls[studentCount] > 1100) // validation
			{
				cout << "\033[34m Invalid marks. Please Enter correct marks! \033[0m" << endl;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "\033[33m  Fsc Marks: \033[0m";
			cin >> fsc[studentCount];
			cout << endl;
			if (fsc[studentCount] < 0 || fsc[studentCount] > 1100) // validation
			{
				cout << "\033[34m Invalid Marks. Please enter Correct marks! \033[0m" << endl;
				cout << endl;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "\033[33m  Ecat Marks: \033[0m";
			cin >> ecat[studentCount];
			cout << endl;
			if (ecat[studentCount] < 0 || ecat[studentCount] > 400) // validation
			{
				cout << "\033[34m Invalid marks. Please Enter correct marks! \033[0m" << endl;
				cout << endl;
			}
			else
			{
				break;
			}
		}
		char choyce;
		cout << endl;
		cout << "\033[34m Do you want to enter another student? (y/n): \033[0m"; // validation to enter the entry
		cin >> choyce;
		cout << endl;
		if (choyce == 'Y' || choyce == 'y')
		{
			studentCount++;
			continue;
		}
		else
		{
			char choice;
			cout << "\033[34m  Re-enter data of current student? (y or n): \033[0m"; // validation to overwrite the data of current entry
			cin >> choice;
			cout << endl;
			if (choice == 'y' || choice == 'Y')
			{
				continue;
			}
			else
			{
				studentCount++;
				break;
			}
			cout << endl;
			aggregate();
		}
	}
}

void aggregate()
{
	for (int i = 0; i < studentCount; i++)
	{
		merit[i] = ((rolls[i] / 1100 * 0.1) + (fsc[i] / 1100 * 0.6) + (ecat[i] / 400 * 0.3)) * 100;
	}
}
void addstudentMenu()
{
	system("cls");
	cout << "\033[33m Admin Interface >> \033[0m \033[35m Add Students >> \033[0m" << endl;
	cout << "\033[32m--------------------------------------------\033[0m" << endl;
	cout << endl;
}
int admininterface()
{
	system("cls");
	header();
	cout << "\033[35m  Welcome to Admin Interface >>\033[0m" << endl;
	cout << endl;

	cout << "\033[34m  Select one of the following.. \033[0m" << endl;
	cout << endl;
	cout << "\033[33m  1. Add Student \033[0m" << endl;
	cout << endl;
	cout << "\033[33m  2. View all Students \033[0m" << endl;
	cout << endl;

	cout << "\033[33m  3. Remove Student \033[0m" << endl;
	cout << endl;
	cout << "\033[33m  4. Generate Merit list \033[0m" << endl;
	cout << endl;
	cout << "\033[33m  5. Announce Result >>\033[0m" << endl;
	cout << endl;
	cout << "\033[33m  6. Move back to login Interface \033[0m" << endl;

	cout << endl;
	int admin;
	cout << "\033[34m       Your Option... \033[0m";
	cin >> admin;
	return admin;
}
void ViewMeritList()
{
	system("cls");
	header();
	cout << "\033[35m  Merit List >>\033[0m" << endl;
	cout << "\033[34m-----------------------------------------------------------------------------\033[0m" << endl;
	cout << endl;
	if (announce == false)
	{
		cout << "\033[33m        Results have not been announced yet.\033[0m" << endl;
		return; // Stop the function if results are not announced.
	}

	cout << endl;
	cout << "\033[35m Rank\033[0m" << "\t\t" << "\033[35m  Name\033[0m" << "\t\t" << "\033[35m Merit Aggregate\033[0m" << "\t\t" << endl;
	for (int i = 0; i < studentCount; i++)
	{

		cout << i + 1 << "\t\t" << student[i] << "\t\t" << merit[i] << "\t\t" << endl;
	}
}
void generateMeritList()
{
	aggregate();
	// sort elements of the array to create a merit list as per highest merit aggregate.
	for (int i = 0; i < studentCount; i++)
	{
		for (int j = i + 1; j < studentCount; j++)
		{
			if (merit[i] < merit[j])
			{
				// swap elements to position the students as per merit criteria in a list.
				float tempMerit = merit[i];
				merit[i] = merit[j];
				merit[j] = tempMerit;

				string tempstudent = student[i];
				student[i] = student[j];
				student[j] = tempstudent;

				float temprolls = rolls[i];
				rolls[i] = rolls[j];
				rolls[j] = temprolls;

				float tempfsc = fsc[i];
				fsc[i] = fsc[j];
				fsc[j] = tempfsc;

				float tempecat = ecat[i];
				ecat[i] = ecat[j];
				ecat[j] = tempecat;
			}
		}
	}
}
void signin()
{
	system("cls");
	header();
	cout << "\033[35m   Login >>  \033[0m" << endl;
	cout << "-----------------" << endl;
	cout << endl;
	cout << "\033[35m Name: \033[0m";
	cin >> name;
	cout << endl;
	cout << "\033[35m Password: \033[0m";
	cin >> password;
	cout << endl;
	cout << "\033[35m Role (admin or student): \033[0m";
	cin >> role;
	cout << endl;
}
void header()
{
	cout << "\033[31m ************************************************************************************** \033[0m" << endl;
	cout << "\033[31m *------------------------University Management System--------------------------------* \033[0m" << endl;
	cout << "\033[31m **************************************************************************************\033[0m" << endl;
	cout << endl;
}
void submenu()
{
	header();
	cout << "\033[32m  Sign-In >> \033[0m " << endl;
	cout << "\033[32m---------------------\033[0m" << endl;
	cout << endl;
	cout << "\033[30m  1. Signin \033[0m" << endl;
	cout << endl;
	cout << "\033[30m  2. Exit the application \033[0m" << endl;
}
int opt()
{
	int options;
	cout << endl;
	cout << "\033[31m    Enter option..\033[0m";
	cin >> options;
	return options;
}