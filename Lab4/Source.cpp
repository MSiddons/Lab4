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
	if (a[0] <= 40) // if user worked less than or exactly 40 hours
		b = a[0] * a[1]; // calculate hours worked * hourly pay rate and store it in variable 'b'
	else
	{
		b = 40 * a[1]; //if more than 40 hours worked, multiply the hourly pay rate by 40, store that in variable 'b'
		c = (a[0] - 40) * a[2]; //then calculate the overtime by multiplying the overtime rate by the hours past 40 which were worked.
	}
	a.push_back(b); // store b...
	a.push_back(c); // and c in cells in the vector and return to the main function for output.
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
	if (hw > 40) // only ask the user to enter overtime rate if they worked overtime.
	{
		cout << "You did overtime. Enter overtime pay rate (in pounds): ";
		cin >> oRate;
	}
	userIn.push_back(oRate); // either store the overtime rate or '0' in the vector.

	payCalc(userIn); // send income details in the vector to the function which will compute the pay and ammend those payment details to the end of the vector.
	cout << "You will be paid " << userIn[3] << " pounds for "; //standard line not dependant on hours worked.
	if (hw <= 40)
		cout << hw << " hours worked." << endl << endl;
	else
		cout << "40 hours standard pay, and " << userIn[4] << " pounds for " << hw - 40 << " hours of overtime for a total of " << userIn[3] + userIn[4] << " pounds." << endl;
}

//Q6------------------------------------------------------------------------------------------------
void rowCalc(vector<int> &a, vector<int> b, int i) // allow function to edit the current row, reference the row above and know what row we're looking at. 
{
	a.clear(); // remove all values from this vector as they're not needed anymore
	a.push_back(1); // write '1' to the first element in vector row1.
	int f = 1; // target the second element in the row.
	while (f <= i - 1) // fill in the elements from element 1 to the second from last element.
	{
		a.push_back(b[f-1] + b[f]); // fill the next element with the sum of the two elements 'above' it in the triangle.
		f++; // move to the next element.
	}
	a.push_back(1); // put a 1 in the last element on this vector.
}

int PascalCalc(int n, int r) // row is n, position in row is r.
{
	vector<int> row1{ 1,1 };
	vector<int> row2{ 1,1 }; // this stops the program from trying to refer to this row early on and crashing when there's no data there.
	int c;
	if (r <= 1 && n <= 1)// small piece of code to handle any issues that might come up in row 0 and 1.
		return 1;
	for (int i = 1; i <= n; i++) // work out what row you're calculating, starting in row 1 and going up to the value of n.
	{
		if (i % 2 != 0) // if we're computing an odd row, use vector row1.
			rowCalc(row1, row2, i); // we need to send over both vectors to allow row1 to reference data in row2.
		else // use the row2 vector if we're on an even row.
			rowCalc(row2, row1, i); // sending over the last row calculated along with the current one for reference.
	}
	// we need to find the element we'll report back to the user by targeting the correct array.
	if (n % 2 == 0) // if the array is even, we know the last vector written is row2.
		c = row2[r]; // find the 'r'th position in that vector and store the element in c.
	else
		c = row1[r]; // same as above but for odd numbers of 'n'.
	return c; // send the result of n choose r back to the main function.
}

void exercise6()
{
	// this first bit is exactly the same as exercise 4c, if you don't understand this you shouldn't even be here.
	int n = 0, r = 0;
	cout << "Enter value for n: ";
	cin >> n;
	cout << "Enter value for r: ";
	cin >> r;
	if (r > n)
	{
		cout << "Those are round the wrong way, I will calculate " << r << " choose " << n << " instead." << endl;
		cout << r << " choose " << n << " is " << PascalCalc(r, n) << endl;
	}
	else
		cout << n << " choose " << r << " is " << PascalCalc(n, r) << endl;
}
//Q6 Special------------------------------------------------------------------------------------------------
void rowCalc2(vector<int> &a, vector<int> b, int i, int n) // allow function to edit the current row, reference the row above, know what row we're looking at and n. 
{		
	int w;// this block of code sets how many spaces will be in front of the numbers based on the value of 'n'.
	if (n <= 11) w = 3; else w = 4; // it's not really worth setting beyond 11 lines since it quickly loses shape higher than that.

	a.clear(); // remove all values from this vector as they're not needed anymore
	a.push_back(1); // write '1' to the first element in vector row1.
	for (int z = 1; z < n - i+2; z++) // find out how many spaces to draw based on what row we're on
		cout << "  ";
	cout << setw(w) << " 1 "; // draw the first number to the console.
	int f = 1; // target the second element in the row.
	while (f <= i - 1) // fill in the elements from element 1 to the second from last element.
	{
		a.push_back(b[f - 1] + b[f]); // fill the next element with the sum of the two elements 'above' it in the triangle.
		cout.precision(3); // only draw to 3 S.F.    ---NOT CURRENTLY WORKING, attempted fixes.---
		cout << setw(w) << a[f] << " "; // draw the current element to the console
		f++; // move to the next element.
	}
	a.push_back(1); // put a 1 in the last element on this vector.
	cout << setw(w) << " 1" << endl; // stick a 1 on the end of that line on the console.
}

int PascalCalc2(int n, int r) // row is n, position in row is r.
{
	vector<int> row1{ 1,1 };
	vector<int> row2{ 1,1 }; // this stops the program from trying to refer to this row early on and crashing when there's no data there.
	int c;
	if (r <= 1 && n <= 1)// small piece of code to handle any issues that might come up in row 0 and 1.
		return 1;
	for (int i = 1; i < n+2; i++)// before we start, use n to work out how many double spaces to draw,
		cout << "  ";
	cout << " 1" << endl; // then draw the top '1'.
	for (int i = 1; i <= n; i++) // work out what row you're calculating, starting in row 1 and going up to the value of n.
	{
		if (i % 2 != 0) // if we're computing an odd row, use vector row1.
			rowCalc2(row1, row2, i, n); // we need to send over both vectors to allow row1 to reference data in row2.
		else // use the row2 vector if we're on an even row.
			rowCalc2(row2, row1, i, n); // sending over the last row calculated along with the current one for reference.
	}
	// we need to find the element we'll report back to the user by targeting the correct array.
	if (n % 2 == 0) // if the array is even, we know the last vector written is row2.
		c = row2[r]; // find the 'r'th position in that vector and store the element in c.
	else
		c = row1[r]; // same as above but for odd numbers of 'n'.
	return c; // send the result of n choose r back to the main function.
}

void exercise7()
{
	int n = 0, r = 0;
	cout << endl << " --------------------------------" << endl
		 << " |    Welcome to Q6 Special!    |" << endl
		 << " |  This is a graphical display |" << endl
		 << " |     of Pascal's Triangle.    |" << endl
		 << " |                              |" << endl
		 << " |           Enjoy!             |" << endl
		 << " --------------------------------" << endl << endl;
	cout << "Enter value for n: ";
	cin >> n;
	cout << "Enter value for r: ";
	cin >> r;
	if (r > n)
	{
		cout << "Those are round the wrong way, I will calculate " << r << " choose " << n << " instead." << endl << endl;
		cout << endl << r << " choose " << n << " is " << PascalCalc2(r, n) << endl;
	}
	else
		cout << endl << n << " choose " << r << " is " << PascalCalc2(n, r) << endl;
}
//Menu------------------------------------------------------------------------------------------------
int main()
{
	int exercise = -1;
	char q4 = '1';
	while (exercise != 0)
	{
		cout << "Select an exercise number (1-6), 7 for special or 0 to exit: ";
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
			break;
		case 6:
			exercise6();
			break;
		case 7:
			exercise7();
			break;

		default:
			cout << "Incorrect choice" << endl;
		}
	}
}
