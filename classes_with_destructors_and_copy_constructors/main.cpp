#include "classes_with_destructors_and_copy_constructors.hpp"


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

	acro.printMonkeyInformation();

	acro.addToBananaHoard(11);

 	mrMonkey.printMonkeyInformation();
	acro.printMonkeyInformation();
	
	Monkey acroCopyOne = acro;
	Monkey acroCopyTwo(acro);
	exampleFunction(mrMonkey);

	return 0;
}

