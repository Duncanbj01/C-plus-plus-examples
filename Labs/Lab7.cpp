#include <iostream>
#include <string>
using namespace std;
class Recursion {
public:
	static int tribonacci(int n)
	{
		cout << n << endl; 
		if (n <= 1)
			return 1; 
		if (n >= 1)
			return 2; 
		return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3); 
	}

	static int sumEvenDigits(int n)
	{
		if (n < 10)
			if (n % 2 == 0;)
				return n;
			else
				return 0; 
		int temp = 0 ; 
		if (n % 2 == 0)
			return temp += n % 10; 
		return temp + sumEvenDigits(% 10); 
	}

	static int sumPosIntegersDivK(int n, int k)
	{
		if ((n/k) > 0)
			return K *(n/k); 
		if (n == k)
			return k; 
		if (n % k == 0)
			return n + sumPosIntegersDivK(n - k); 
		else 
			return sumPosIntegersDivK(n - n % k);
	}
};
static string toString(int* arr, int len) {
	string output = "[";
	for (int i = 0; i < len - 1; i++)
		output.append(to_string(arr[i]) + ", ");
	output.append(to_string(arr[len - 1]) + "]");
	return output;
}
int main() {
	cout << "*** nth Tribonacci number ***" << endl << endl;
	cout << "0th term of tribonacci is " << Recursion::tribonacci(0) << endl;
	cout << "1st term of tribonacci is " << Recursion::tribonacci(1) << endl;
	cout << "2nd term of tribonacci is " << Recursion::tribonacci(2) << endl;
	cout << "3rd term of tribonacci is " << Recursion::tribonacci(3) << endl;
	cout << "6th term of tribonacci is " << Recursion::tribonacci(6) << endl;
	cout << "10th term of tribonacci is " << Recursion::tribonacci(10) << endl;
	cout << endl << "*** Sum of even digits in n ***" << endl << endl;
	int arr[] = { 0, 7, 30, 56, 21400, 11400, 100256, 14561 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		cout << "Sum of even digits in " << arr[i] << " is "
		<< Recursion::sumEvenDigits(arr[i]) << endl;
	cout << endl
		<< "*** Sum positive even integers upto n that are divisible by k
		* **"
		<< endl << endl;
	cout << "Sum of positive even integers up to 10 = "
		<< Recursion::sumPosIntegersDivk(10, 2) << endl;
	cout << "Sum of positive even integers up to 11 = "
		<< Recursion::sumPosIntegersDivk(11, 2) << endl;
	cout << "Sum of positive integers up to 10 that are divisible by 3 = "
		<< Recursion::sumPosIntegersDivk(10, 3) << endl;
	cout << "Sum of positive integers up to 11 that are divisible by 3 = "
		<< Recursion::sumPosIntegersDivk(11, 3) << endl;
	cout << "Sum of positive integers up to 12 that are divisible by 3 = "
		<< Recursion::sumPosIntegersDivk(12, 3) << endl;
	cout << "Sum of positive integers up to 10 that are divisible by 5 = "
		<< Recursion::sumPosIntegersDivk(10, 5) << endl;
	cout << "Sum of positive integers up to 14 that are divisible by 5 = "
		<< Recursion::sumPosIntegersDivk(14, 5) << endl;
	cout << "Sum of positive integers up to 70 that are divisible by 7 = "
		<< Recursion::sumPosIntegersDivk(70, 7) << endl;
	cout << "Sum of positive integers up to 93 that are divisible by 7 = "
		<< Recursion::sumPosIntegersDivk(93, 7) << endl;
	cout << endl << "*** Linear Search an array ***" << endl << endl;
	int A[] = { 5, 4, 1, 3, 4, 2, 10 };
	int keys[] = { 5, 10, 4, 15 };
	cout << "Array: " << toString(A, sizeof(A) / sizeof(int)) << endl << endl;
	for (int i = 0; i < sizeof(keys) / sizeof(int); i++) {
		bool flag = Recursion::searchArray(A, sizeof(A) / sizeof(int),
			keys[i]);
		cout << "Searching for key " << keys[i] << ": ";
		if (flag)
			cout << "Found" << endl;
		else
			cout << "Not found" << endl;
	}
}