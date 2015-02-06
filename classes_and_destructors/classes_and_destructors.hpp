#ifndef CLASSES_AND_DESTRUCTORS_HPP
#define CLASSES_AND_DESTRUCTORS	_HPP

#include <iostream>


class Monkey
{
	public:
		Monkey(const std::string name, const int age, const int bananaHoardArrCap);
		~Monkey();
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

#endif //CLASSES_UPGRADED_AND_DESTRUCTORS_HPP
