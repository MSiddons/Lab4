#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <time.h>

using namespace std;

/* Q1
double coord(vector<double> a, double i);

int main()
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
	return 0;
}

double coord(vector<double> a, double i)
{
	double y;
	y = a[0] * i + a[1];
	return y;
}
*/

/* Q2
bool correct(int a, int b);

int main()
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
	return 0;
}

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
*/

/* Q3*/
int main()
{

	return 0;
}