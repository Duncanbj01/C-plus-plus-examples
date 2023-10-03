#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
template<class T, class F>
void selectionSort(vector<T>& arg, F comparator) {
	for (int i = 0; i < arg.size() - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < arg.size(); j++) {
			if (comparator(arg.at(minIndex), arg.at(j)) < 0)
				minIndex = j;
		}
		if (i != minIndex)
			std::swap(arg.at(i), arg.at(minIndex));
	}
}
// print, insertionSort, and binarySearch function goes here
// the two comparators also go here
template<class T>
void print(vector<T>& arg)
{
	cout << "["; 
		for (int i = 0; i < arg.size(); i++)
			cout << arg.at(i) << ", "; 
	cout << arg.at(arg.size()-1) << "]";
}

class StringComparator
{
public: 
	int operator()(const string& arg1, const string& arg2) const
	{
		if (arg1 < arg2)
			return -1; 
		else if (arg1 == arg2)
			return 0;
		else
			return 1; 
	}
};

class IntegerComparator
{
public: 
	int operator()(const int& arg1, const int& arg2) const
	{
		if (arg1 < arg2)
			return -1;
		else if (arg1 == arg2)
			return 0;
		else
			return 1;
	}
};

template<typename T, typename F>
static void insertionSort( vector<T> &arg, F comparator)
{
	for (int i = 1; i < arg.size(); i++)
	{
		T key = arg.at(i); 
		int j = i; 
		while (j > 0 && comparator(arg.at(j - 1), key) == 1)
		{
			arg.at(j) = arg.at(j - 1); 
			j--; 
		}
		arg.at(j) = key; 
	}
}

template<typename T, typename F>
int binarySearch(vector<T>& arg, F comparator, T key, int left, int right)
{
	if (left > right)
	{
		return -1; 
	}
	int mid = (left + right) / 2; 
	if (comparator(arg.at(mid),key) == 0)
	{
		return mid;
	}

	else if (comparator(arg.at(mid),key) == -1)
	{
		return binarySearch(arg, comparator, key, mid + 1, right);
	}
	return binarySearch(arg, comparator, key, left, mid -1);
}






int main() {
	string arr_str[] = { "wxcdx", "xyzab", "aac", "abc", "abcdx", "aaa",
	"abcxy", "wxcdx", "aaa", "xyzw" };
	vector<string> vect_str(arr_str,
		arr_str + sizeof(arr_str) / sizeof(string));
	int arr_int[] = { 37, 56, 98, 12, 4, 5, 99, 54, 23, 87, 1, 23, 47, 980, 76 };
	vector<int> vect_int(arr_int, arr_int + sizeof(arr_int) / sizeof(int));
	cout << "Before sorting: ";
	print(vect_str);
	insertionSort(vect_str, StringComparator());
	cout << "\nAfter Sorting:  ";
	print(vect_str);
	cout << endl << endl << "Before sorting: ";
	print(vect_int);
	insertionSort(vect_int, IntegerComparator());
	cout << "\nAfter Sorting:  ";
	print(vect_int);
	string keys_str[] = { "aaa", "a", "abc", "zyz", "abcxy", "xyzz", "xyzw",
	"wxcdx", "aac" };
	printf("\n\n*** Searching Sorted String Vector ***\n");
	for (string& key : keys_str)
		printf("Index of %s is %d\n", key.c_str(),
			binarySearch(vect_str, StringComparator(), key, 0,
				vect_str.size() - 1));
	cout << endl;
	int keys_int[] = { 89, 98, 54, 23, 1, 980, 6, 5, 100, 76 };
	printf("*** Searching Sorted Integer Vector ***\n");
	for (int& key : keys_int)
		printf("Index of %d is %d\n", key,
			binarySearch(vect_int, IntegerComparator(), key, 0,
				vect_int.size() - 1));
}
