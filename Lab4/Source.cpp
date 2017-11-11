#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <time.h>

using namespace std;

//Q1------------------------------------------------------------------------------------------------
double coord(vector<double> a, double i)
{
	double y;
	y = a[0] * i + a[1];
	return y;
}

void exercise1()
{
	double userIn = 1;
	vector<double> a; //vector stores values in the order of m, c, x-start, x-end, interval.
	cout << "Where y = mx +c, please enter the values for m, c, x-start, x-end and the interval, followed by 0: ";
	while (userIn != 0)
	{
		cin >> userIn;
		a.push_back(userIn);
	}
	a.pop_back();

	cout << " x  y" << endl;
	for (double i = a[2]; i <= a[3]; i = i + a[4]) // 'i' is now equal to x for this set of figures. It will increase by the interval every loop.
	{
		cout << setw(2) << i << " " << coord(a, i) << endl;
	}
}

//Q2------------------------------------------------------------------------------------------------
bool correct(int a, int b)
{
	if (a == b)
		return true;
	else if (a < b)
	{
		cout << "Too high! Guess again" << endl;
		return false;
	}
	else
	{
		cout << "Too low! Guess again" << endl;
		return false;
	}
}

void exercise2()
{
	int n, userIn = -1;
	srand(time(0));
	n = rand() % 100 + 1; // generate a random number between 1 and 100
	while (userIn != n)
	{
		cout << "I'm thinking of a number between 1 and 100, guess what it is: ";
		cin >> userIn;
		if (correct(n, userIn) == true)
			cout << "That is the correct answer, well done!" << endl;
	}
}

//Q3------------------------------------------------------------------------------------------------
void sort3(int &a, int &b, int &c) // Passing reference to a, b and c. Any calculations are modifying actual values in 'void exercise3()'
{
	int d;
	// for the below explanations, a=1, b=2, c=3
	if (a >= b && b >= c) // 2 2 1, 3 2 1, 2 1 1, 1 1 1
		d = c, c = a, a = d;
	else if (a > b && b < c)	// 3 1 2, 2 1 3 and 2 1 2
	{
		if (a > c)
			d = a, a = b, b = c, c = d;
		else
			d = a, a = b, b = d;
	}
	else if (a < b && b > c)	// 2 3 1, 1 3 2 and 1 2 1
	{
		if (a > c)
			d = c, c = b, b = a, a = d;
		else
			d = b, b = c, c = d;
	}
	// rule not required for 1 2 3, 1 1 2, 1 2 2
}

void exercise3()
{
	int a, b, c;
	cout << "Enter number 1: ";
	cin >> a;
	cout << "Enter number 2: ";
	cin >> b;
	cout << "Enter number 3: ";
	cin >> c;
	sort3(a, b, c);
	cout << a << " " << b << " " << c << endl;
}

//Q4a------------------------------------------------------------------------------------------------
int compFact(int &a)
{
	if (a == 0 || a == 1)
		return 1;
	else
		for (int i = a - 1; i > 1; i--)
			a = a * i;
	return a;
}

void exercise4_a()
{
	int userIn;
	cout << "Enter the positive integer value for n!: ";
	cin >> userIn;
	cout << userIn << "! is ";
	cout << compFact(userIn) << endl;
}

//Q4b+c------------------------------------------------------------------------------------------------
int choose(int n, int r)
{
	int a = n - r;
	return (compFact(n) / (compFact(r) * compFact(a)));
}

void exercise4_c()
{
	int n = 0, r = 0;
	cout << "Enter value for n";
	cin >> n;
	cout << "Enter value for r";
	cin >> r;
	if (r > n)
		cout << "Those values are the wrong way around, but " << r << " choose " << n << "equals: " << choose(r, n) << endl;
	else
		cout << "n choose r equals: " << choose(n, r) << endl;
}

//Q5------------------------------------------------------------------------------------------------
void payCalc(vector<double> &a) //unable to return two values so we'll edit the vector the user input is in. Little dirty but works for us.
{
	double b, c = 0;
	if (a[0] <= 40)
		b = a[0] * a[1];
	else
	{
		b = 40 * a[1];
		c = (a[0] - 40) * a[2];
	}
	a.push_back(b);
	a.push_back(c);
}

void exercise5()
{
	double hw, sRate, oRate = 0;
	vector<double> userIn;
	cout << "Enter number of hours worked: ";
	cin >> hw;
	userIn.push_back(hw);
	cout << "Enter hourly pay (in pounds): ";
	cin >> sRate;
	userIn.push_back(sRate);
	if (hw > 40)
	{
		cout << "You did overtime. Enter overtime pay rate (in pounds): ";
		cin >> oRate;
	}
	userIn.push_back(oRate);

	payCalc(userIn);
	cout << "You will be paid " << userIn[3] << " pounds for ";
	if (hw <= 40)
		cout << hw << " hours worked." << endl << endl;
	else
		cout << "40 hours standard pay, and " << userIn[4] << " pounds for " << hw - 40 << " hours of overtime for a total of " << userIn[3] + userIn[4] << " pounds." << endl;
}

//Menu------------------------------------------------------------------------------------------------
int main()
{
	int exercise = -1;
	char q4 = '1';
	while (exercise != 0)
	{
		cout << "Select an exercise number (1-6) or 0 to exit: ";
		cin >> exercise;
		switch (exercise)
		{
		case 0:
			break;
		case 1:
			exercise1();
			break;
		case 2:
			exercise2();
			break;
		case 3:
			exercise3();
			break;
		case 4:
		{
			while (q4 != '0')
			{
				cout << "Which sub excersise? (a or c, 0 to go back): ";
				cin >> q4;
				switch (q4)
				{
				case '0':
					break;
				case 'a':
					exercise4_a();
					break;
				case 'b':
					exercise4_c();
					break;

				default:
					cout << "That's not a choice." << endl;
				}
			}
			break;
		}

		case 5:
			exercise5();
			break;/*
		case 6:
			exercise6();
			break; */

		default:
			cout << "Incorrect choice" << endl;
		}
		//cout << endl;
	}
}
