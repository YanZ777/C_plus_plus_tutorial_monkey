#include "classes_with_destructors_and_copy_constructors_and_assignment_operators.hpp"


Monkey exampleFunction(Monkey exampleMonkey) 
{
	std::cout << "Example function called." << std::endl;
	
	return exampleMonkey;
}

int main()
{
	int mrMonkeyBananaHoardSize = 3;
	Monkey mrMonkey = Monkey("Mr. Monkey", 2, mrMonkeyBananaHoardSize);
	mrMonkey.addToBananaHoard(1);
	mrMonkey.addToBananaHoard(5);
	mrMonkey.addToBananaHoard(7);

	int acroBananaHoardSize = 3;
 	Monkey acro = Monkey("Acro", 2, acroBananaHoardSize);
	acro.addToBananaHoard(10);
	acro.addToBananaHoard(3);
	acro.addToBananaHoard(5);

	//Commenting this out to print out less.
	//acro.printMonkeyInformation();

	acro.addToBananaHoard(11);
	
	//Commenting these out to print out less.
 	//mrMonkey.printMonkeyInformation();
	//acro.printMonkeyInformation();
	
	//Commenting these out to print out less.
	//Copy constructor examples
	//Monkey acroCopyOne = acro;
	//Monkey acroCopyTwo(acro);
	//exampleFunction(mrMonkey);
	
	//Assignment operator examples
	//Note that while the assignment operator will be called, nothing will be copied.
	acro = acro;
	//Since we need a currently existing object, we'll copy from mrMonkey to arco,
	//and then we will print out each Monkey's information to see if it really
	//is the same.
	acro = mrMonkey;
	mrMonkey.printMonkeyInformation();
	acro.printMonkeyInformation();
	
	return 0;
}

