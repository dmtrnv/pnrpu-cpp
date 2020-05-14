#include <iostream>
#include <vector>
#include <queue>
#include "Error.h"
#include "Time.h"
#include "Vector.h"


int main()
{
	setlocale(LC_ALL, "rus");

	try
	{
		Vector<Time> vec(5);
		vec.print();

		vec.addElementWithKey(135);
		std::cout << "Произведено добавление элемента 2:15.\n";
		vec.print();

		vec.removeElement(147);
		std::cout << "Удален элемент 2:27.\n";
		vec.print();

		Time val = vec.findDifference();
		vec.reduceElements(val);
		std::cout << "Из каждого элемента вычтена разница между максимальным и минимальным элементами контейнера.\n";
		vec.print();
	}
	catch(Error &e)
	{
		e.what();
	}

	system("pause");
	return 0;
}