#include "classes_with_destructors_and_copy_constructors.hpp"

/*
We want to make the variables that the constructor takes in const because we
don't want to be able to change the variables that are passed in. Here it
doesn't matter so much since they are pass by value, but if they are passed
by reference then we want to protect the original values by using const.
*/
Monkey::Monkey(const std::string& name, const int& age, const int& bananaHoardArrCap)
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

/*
This is a destructor. It is important to clean up dynamic (heap) memory that 
an object has used, as we should not expect the user (of the Monkey class, 
or any class that uses heap memory) to know how to clean up after after the 
object created from the class.
*/
Monkey::~Monkey()
{
	//This line is here for the purposes of showing that the destructor gets called.
	//You can comment it out if you don't want output showing up.
	std::cout << "Destructor called!" << std::endl;
	delete[] bananaHoard;
}

/*
This is the copy constructor. The copy constructor is important for making sure
that when you create a new object of a class, it gets properly copied.
Note that we are writing the copy constructor from the standpoint of the
copy, NOT from the object that we are copying from.
*/
Monkey::Monkey(const Monkey& srcMonkey) 
{
	std::cout << "Copy Constructor called! Copying from: " << srcMonkey.name << std::endl;
	
	name = srcMonkey.name;
	age = srcMonkey.age;
	bananaHoardArrCap = srcMonkey.bananaHoardArrCap;
	bananaHoardSize = srcMonkey.bananaHoardSize;
	
	bananaHoard = new int(bananaHoardSize);
	
	//Copy everything from the source monkey to the destination monkey.
	for (int i = 0; i < bananaHoardSize; i++)
	{
		bananaHoard[i] = srcMonkey.bananaHoard[i];
	}
}

void Monkey::addToBananaHoard(const int& bananasToAdd)
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
