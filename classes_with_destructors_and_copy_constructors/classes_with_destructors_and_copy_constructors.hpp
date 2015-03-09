#ifndef CLASSES_WITH_DESTRUCTORS_AND_COPY_CONSTRUCTORS_HPP
#define CLASSES_WITH_DESTRUCTORS_AND_COPY_CONSTRUCTORS_HPP

#include <iostream>


class Monkey
{
	public:
		Monkey(const std::string& name, const int& age, const int& bananaHoardArrCap);
		~Monkey();
		Monkey(const Monkey& srcMonkey);
		void printMonkeyInformation() const;
		void addToBananaHoard(const int& bananasToAdd);
	private:
		std::string name;
		int age;
		int* bananaHoard;
		//How big the array is.
		int bananaHoardArrCap;
		//How full the array is. (How many items are in the array.)
		int bananaHoardSize;
};

#endif //CLASSES_WITH_DESTRUCTORS_AND_COPY_CONSTRUCTORS_HPP
