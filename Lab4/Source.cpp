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
	cout << "compFact= " << a << endl;
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

//Q4b------------------------------------------------------------------------------------------------
int choose(int &n, int &r)
{
	int a = n - r;
	return 6 / (2 * 1);
	//return (compFact(n) / (compFact(r) * compFact(a)));
}

void exercise4_b()
{
	int n = 0, r = 0;
	cout << "Enter values for n and r: ";
	cin >> n, r;
	if (r > n)
		cout << "Those values are the wrong way around, but " << r << " choose " << n << "equals: " << choose(r, n) << endl;
	else
		cout << "n choose r equals: " << choose(n, r) << endl;
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
			cout << "Bye Bye.";
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
				cout << "Which sub excersise? (a-c, 0 to go back): ";
				cin >> q4;
				//cout << endl;
				switch (q4)
				{
				case '0':
					cout << "Bye Bye.";
					break;
				case 'a':
					exercise4_a();
					break;
				case 'b':
					exercise4_b();
					break;/*
				case 'c':
					exercise4_c();
					break;*/

				default:
					cout << "That's not a choice." << endl;
				}
			}
			break;
		}
		/*
		case 5:
			exercise5();
			break;
		case 6:
			exercise6();
			break; */

		default:
			cout << "Incorrect choice" << endl;
		}
		cout << endl;
	}
}
