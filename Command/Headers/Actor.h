// Receiver. This Implements the actual business logic
// of the commands. It doesn't need to know WHEN to perform actions
// only HOW.
#pragma once
#include <string>

class Actor
{
private:
	std::string _Name;

public:
	Actor(std::string Name) : _Name(Name) {}


	void GoUp(int Amount) {
		std::cout << _Name <<
			"is going up by: " << Amount << '\n';
	}

	void GoDown(int Amount) {
		std::cout << _Name <<
			"is going down by: " << Amount << '\n';
	}

	void Shoot() {
		std::cout << _Name <<
			"Shoots! BANG BANG!" << '\n';
	}
};
