#include <iostream>
#include <deque>
#include <iomanip>
#include "Error.h"


typedef std::deque<double> deque;


deque make(const int &size);
void print(const deque &deq);
deque::iterator find(deque &deq, const double &key);
void addElementToPosition(deque &deq, const double &key, const int &pos);
void removeElement(deque &deq, const double &key);
double findDifference(const deque &deq);
void reduceElements(deque &deq, const double &val);


int main()
{
	setlocale(LC_ALL, "rus");

	try
	{
		deque deq = {3.33, 5.55, 7.77, 9.99, 11.11, 13.13, 15.15};
		print(deq);

		addElementToPosition(deq, 5.55, 6);
		std::cout << "Произведено добавление элемента 5.55 на 6 позицию.\n";
		print(deq);

		removeElement(deq, 15.15);
		std::cout << "Удален элемент 15.15.\n";
		print(deq);

		double val = findDifference(deq);
		reduceElements(deq, val);
		std::cout << "Из каждого элемента вычтена разница между максимальным и минимальным элементами контейнера.\n";
		print(deq);
	}
	catch(Error &e)
	{
		e.what();
	}

	system("pause");
	return 0;
}




deque make(const int &size)
{
	if(size < 0)
		throw Error("Error: deque size must be 0 or higher");

	deque deq;
	double num = 0;
	for(int i = 0; i < size; i++)
	{
		num = std::rand() % 100 / 11.43;
		deq.push_back(num);
	}

	return deq;
}

void print(const deque &deq)
{
	if(deq.size() == 0)
	{
		std::cerr << "Error: deque is empty.\n";
		return;
	}

	std::cout << "Очередь содержит:\n";
	for(int i = 0; i < deq.size(); i++)
		std::cout << std::fixed << std::setprecision(2) << deq[i] << "  ";
	std::cout << std::endl;
}

deque::iterator find(deque &deq, const double &key)
{
	if(deq.size() == 0)
		throw Error("Error: element not found.\n"); 

	deque::iterator iter;

	if(deq.front() == key)
	{
		iter = deq.begin();
		return iter;
	}
	else if(deq.back() == key)
	{
		iter = deq.end() - 1;
		return iter;
	}
	
	for(iter = deq.begin() + 1; iter != deq.end(); iter++)
		if(*iter == key)
			return iter;

	//генерируется исключение, т.к. итератор не может указывать на нулл
	throw Error("Error: element not found.\n"); 
}

void addElementToPosition(deque &deq, const double &key, const int &pos)
{
	if(pos < 0 || pos > deq.size() + 1)
	{
		std::cerr << "Error: invalid position value. It must be in the range 0-" << deq.size() + 1 << ".\n";
		return;
	}

	deque::iterator iterKey = find(deq, key);
	deque::iterator iterPos = deq.begin() + (pos - 1);

	deq.insert(iterPos, *iterKey);
}

void removeElement(deque &deq, const double &key)
{
	if(deq.size() == 0)
	{
		std::cerr << "Error: deque is empty.\n";
		return;
	}

	deque::iterator iter = find(deq, key);

	deq.erase(iter);
}

double findDifference(const deque &deq)
{
	if(deq.size() == 0)
	{
		std::cerr << "Error: deque is empty.\n";
		return 0;
	}

	double min = deq[0], max = deq[0];

	for(int i = 1; i < deq.size(); i++)
	{
		if(deq[i] > max)
			max = deq[i];

		else if(deq[i] < min)
			min = deq[i];
	}

	return abs(max - min);
}

void reduceElements(deque &deq, const double &val)
{
	if(val == 0)
		return;

	else if(deq.size() == 0)
	{
		std::cerr << "Error: deque is empty.\n";
		return;
	}
	
	for(int i = 0; i < deq.size(); i++)
		deq[i] = deq[i] - val;
}	