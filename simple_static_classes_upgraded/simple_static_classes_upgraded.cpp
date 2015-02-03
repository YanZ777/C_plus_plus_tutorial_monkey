#include "simple_static_classes_upgraded.hpp"

/*
We want to make the variables that the constructor takes in const because we
don't want to be able to change the variables that are passed in. Here it
doesn't matter so much since they are pass by value, but if they are passed
by reference then we want to protect the original values by using const.
*/
Monkey::Monkey(const std::string name, const int age, const int bananaHoardArrCap)
	/*
	These are called initializers, and the reason why we use them is to
	prevent the program from using too much memory. When a new string is 
	created, memory is allocated for that string, and then copied over into
	the private member variable. The memory is then deallocated. This goes
	for all the data types of the private member variables. To circumvent
	this step of allocating and deallocating memory (even though we don't 
	see it directly, it's done under the hood), we use initializers.
	This may not matter so much for small programs, but for larger programs, 
	memory is important. Basically, practice now before it comes back to 
	bite you and throw bananas at you.
	
	
	The format for initializers is as such: <destination>(<source>)
	*/
	: name(name), age(age), bananaHoardArrCap(bananaHoardArrCap), 
	bananaHoard(new int[bananaHoardArrCap]),
	bananaHoardSize(0)
{
}

/*
The const at the end of the method means that the method doesn't mutate
anything within the method body.
The reason why we would want to do this is so that it is very clear as to which
methods are making modifications to private member variables and which are not.
As of such, methods that have const should not be modifying private member
variables of the class.
*/
void Monkey::printMonkeyInformation() const
{
	std::cout << "This monkey's name is: " << name << std::endl;
	std::cout << "This monkey is this old: " << age << std::endl;
	std::cout << "This monkey has these bananas in his banana hoard: " << std::endl;

	for (int i = 0; i < bananaHoardSize; i++)
	{
		std::cout << bananaHoard[i] << " ";
	}
	std::cout << std::endl;
}


void Monkey::addToBananaHoard(const int bananasToAdd)
{
	/*
	When it isn't possible to fit any more items in the array, create a new
	array double the size and copy everything from the old array into the
	new array. Delete the old array and reassign the private member variable
	to the new array.
	*/
	if (bananaHoardSize == bananaHoardArrCap)
	{
		int newBananaHoardArrCap = bananaHoardArrCap * 2;
		int* newBananaHoardArr = new int[newBananaHoardArrCap];

		for (int i = 0; i < bananaHoardArrCap; i++)
		{
			newBananaHoardArr[i] = bananaHoard[i];
		}

		// delete the old array first
		// if the old array is deleted afterwards, the new array
		// might accidentally be deleted, and then there would be a
		// memory leak with the old array
		delete[] bananaHoard;
		// make the pointer point to the new array
		bananaHoard = newBananaHoardArr;		
		bananaHoardArrCap = newBananaHoardArrCap;
	}
	bananaHoard[bananaHoardSize] = bananasToAdd;
	bananaHoardSize++;
}
