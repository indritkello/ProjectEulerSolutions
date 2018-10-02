// @Author	  : Indrit Kello

#include "stdafx.h"
using namespace std;
int SolveEulerProblem1();
int SolveEulerProblem2();
int SolveEulerProblem3();
int sumOfEvenFibonacciUntil4Milion(int, int, int);
bool isPrime(long long nr);
int main() {
	SolveEulerProblem1();
	SolveEulerProblem2();
	SolveEulerProblem3();
}
#pragma region  Problem1

int SolveEulerProblem1()
{
	int sum = 0;
	int sumOf3Multipliers = 0;
	int sumOf5Multipliers = 0;

	//gjejme fillimisht shumen e shumefishave te treshit 
	for (int i = 3; i <= 1000; i += 3)
	{
		if (i <= 1000)
		{
			sumOf3Multipliers += i;
		}
	}
	//me pas gjejme shumen e shumefishave te peses 
	for (int i = 5; i <= 1000; i += 5)
	{
		if (i % 3 != 0 && i <= 1000) //duhen hequr shumefishat e perbashket
		{
			sumOf5Multipliers += i;
		}
	}
	//bejme shumen total
	sum = sumOf3Multipliers + sumOf5Multipliers;

	cout << "Shuma e te gjithe shumefishave te 3 dhe 5 poshte numrit 1000 eshte: " << sum << endl;
	_getch();
	return 0;
}
#pragma endregion

#pragma region Problem2

int SolveEulerProblem2()
{
	cout << "Shuma e numra cift ne vargun e Fibonacit (deri ne 4 milion) eshte: " << sumOfEvenFibonacciUntil4Milion(1, 2, 0) << endl;
	_getch();
	return 0;
}

int sumOfEvenFibonacciUntil4Milion(int prevlast, int last, int sum) {
	if (last > 4000000) {
		return sum;
	}
	else {
		if (last % 2 == 0) sum += last;

		return sumOfEvenFibonacciUntil4Milion(last, prevlast + last, sum);
	}

}

#pragma endregion

#pragma region Problem3


int SolveEulerProblem3()
{
	vector<int> factors;
	long long numberToBeFactored = 600851475143;
	int sqrtNum = (int)sqrt(numberToBeFactored);
	//odd number
	for (long long i = 3; i <= sqrtNum; i += 2) {
		if ((numberToBeFactored)%i == 0 && isPrime(i)) {
			factors.push_back(i);
			numberToBeFactored = (numberToBeFactored / i);
			sqrtNum = (int)sqrt(numberToBeFactored);
			
			i = 1;
			if (isPrime(numberToBeFactored)) 
			{
				cout << "Faktori me i madh prim i numrit 600851475143 eshte: " << numberToBeFactored << endl;
				break;
			}
		}
	}
	
	_getch();
	return 0;
}
bool isPrime(long long nr)
{
	if (nr == 0) return false;
	for (long long i = 2; i <= sqrt(nr); i++) {
		if (nr % i == 0) {
			return false;
		}
	}
	return true;
}
#pragma endregion