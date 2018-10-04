// @Author	  : Indrit Kello

#include "stdafx.h"
using namespace std;
int SolveEulerProblem1();
int SolveEulerProblem2();
int SolveEulerProblem3();
int SolveEulerProblem4();
int SolveEulerProblem5();
int SolveEulerProblem6();
int SolveEulerProblem7();
int sumOfEvenFibonacciUntil4Milion(int, int, int);
bool isPrime(long long nr);
bool isPalindrome(string);
long long SquareOfTheSum(long long);
long long SumOfTheSquares(long long);
int converStringToInt(string);
int main() {
	SolveEulerProblem1();
	SolveEulerProblem2();
	SolveEulerProblem3();
	SolveEulerProblem4();
	SolveEulerProblem5();
	SolveEulerProblem6();
	SolveEulerProblem7();
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
	//kontrolli duhet bere per numrat tek sepse vetem ata mund te jene prim
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

#pragma region Problem4
bool isPalindrome(string number) {
	int length = number.size();
	for (int i = 0; i < length / 2; i++) {
		if (number[i] != number[length - 1 - i]) return false;
	}
	return true;
}
int SolveEulerProblem4() {
	cout << "Ju lutem prisni! Problemi 4 po zgjidhet..." << endl;
	int max = 0;
	for (int i = 999; i >= 100; i--) {
		for (int j = 999; j >= 100; j--) {
			int product = i*j;

			//konvertimi nga int ne string (shume i rendesishem!)
			std::string out_string;
			//stringstream perdor nje bufer qe permban nje sekuence karakteresh
			//dhe ne mund te marrim string duke perdorur str() member
			std::stringstream ss;
			ss << product;
			out_string = ss.str();
			
			if (isPalindrome(out_string)) {
				if (product > max) {
					max = product;
				}
			}
		}
	}

	cout << "Palindroma me e madhe e formuar nga prodhimi i dy numrave 3 shifrore eshte: " << max << endl;
	_getch();
	return 0;
}
#pragma endregion

#pragma region Problem5
int SolveEulerProblem5()
{
	for (int i = 2520; true; i+=10) {
		for (int m = 1; m <= 21; m++) {
			if (m == 21) {
				cout << "Numri me i vogel positiv qe ka plotepjesetues numrat nga 1 ne 20 eshte: " << i << endl;
				_getch();
				return 0;
			}
			if (i%m != 0) {
				break;
			}
		}
		
	}
	_getch();
	return 0;
}
#pragma endregion

#pragma region Problem6
long long SquareOfTheSum(long long number) {
	//S=[n*(n+1)]/2 (shuma e n kufizave te progresionit aritmetik me d=1)	
	long long sum = (((number + 1)*(number)) / 2);
	return sum*sum;

}
long long SumOfTheSquares(long long number) {
	if (number == 0) {
		return 0;
	}
	else
	{
		return number*number + SumOfTheSquares(number - 1);
	}
}
int SolveEulerProblem6() {
	long long number = 100;
	long long difference = SquareOfTheSum(number)-SumOfTheSquares(number);
	cout << "Difereneca midis katrorit te shumes dhe shumes se katroreve per 100 numrat e pare natyror eshte: " << difference << endl;
	_getch();
	return 0;
}
#pragma endregion

#pragma region Problem7
int SolveEulerProblem7() {
	cout << "Ju lutem prisni! Problemi 7 po zgjidhet... " << endl;
	int tracker = 5;
	for (long long i = 13; true; i+=2) {
		if (isPrime(i)) {
			tracker++;
			if (tracker == 10001) {
				cout << "Numri i 10001 prim eshte: " << i << endl;
				_getch();
				return 0;
			}
		}
	}
	_getch();
	return 0;
}
#pragma endregion

#pragma region Problem8
int converStringToInt(string s) {
	stringstream stream(s);

	// The object has the value s and stream it to the integer x 
	int x = 0;
	stream >> x;
	return x;
}
#pragma endregion
