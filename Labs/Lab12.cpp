#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

template<typename T> 
class GenericQueue 
{
	vector<T> queue; 

public: 

	void enqueue(T arg)
	{
		queue.push_back(arg); 
	}

	T peek()
	{
		return queue.front(); 
	}

	T dequeue(T val)
	{
		val = peek(); 
		queue.erase(queue.begin()); 
		return val; 
	}

	int size()
	{
		return queue.size(); 
	}
};

int main()
{
	GenericQueue<int> integers; 
	GenericQueue<string> letters; 

	cout << "Size: " << integers.size() << endl;

	cout << endl; 

	integers.enqueue(5); 
	integers.enqueue(10);
	integers.enqueue(15);
	integers.enqueue(20);
	integers.enqueue(25);
	cout << "Size: " << integers.size() << endl;
	cout << integers.peek() << endl; 
	cout << integers.dequeue(5) << endl; 
	cout << integers.dequeue(10) << endl;
	cout << integers.dequeue(15) << endl;
	cout << integers.dequeue(20) << endl;
	cout << integers.dequeue(25) << endl;
	cout << "Size: " << integers.size() << endl;

	cout << endl; 

	cout << "Size: " << letters.size() << endl;

	cout << endl; 
	letters.enqueue("five"); 
	letters.enqueue("ten"); 
	letters.enqueue("fifteen"); 
	letters.enqueue("twenty"); 
	letters.enqueue("twenty-five"); 
	cout << "Size: " << letters.size() << endl;
	cout << endl;

	cout << letters.peek() << endl;
	cout << letters.dequeue("five") << endl; 
	cout << letters.dequeue("ten") << endl;
	cout << letters.dequeue("fifteen") << endl;
	cout << letters.dequeue("twenty") << endl;
	cout << letters.dequeue("twenty-five") << endl;

	cout << endl;
	cout << "Size: " << letters.size() << endl;
}