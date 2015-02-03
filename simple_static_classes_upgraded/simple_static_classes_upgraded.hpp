#ifndef SIMPLE_STATIC_CLASSES_UPGRADED_HPP
#define SIMPLE_STATIC_CLASSES_UPGRADED_HPP

#include <iostream>

class Monkey
{
	public:
		Monkey(const std::string name, const int age, const int bananaHoardArrCap);
		void printMonkeyInformation() const;
		void addToBananaHoard(const int bananasToAdd);
	private:
		std::string name;
		int age;
		int* bananaHoard;
		//How big the array is.
		int bananaHoardArrCap;
		//How full the array is. (How many items are in the array.)
		int bananaHoardSize;
};

#endif //SIMPLE_STATIC_CLASSES_UPGRADED_HPP
