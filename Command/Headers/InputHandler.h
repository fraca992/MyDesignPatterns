// Invoker.
// This class invokes Commands for the Receiver to perform.
// OR (like in this case) just return any given Command to the
// Dispatcher or Actor.
// This doesn't need to know HOW to perform commands, only WHEN
#pragma once
#include "../Headers/Commands.h"
#include <cctype>

class InputHandler
{
public:
	InputHandler(
		ICommand* ButtonW,
		ICommand* ButtonS,
		ICommand* ButtonSpace);


	ICommand* HandleInput(char Input);

private:
	ICommand* _ButtonW;
	ICommand* _ButtonS;
	ICommand* _ButtonSpace;
	NULLCommand NlCmd;
};

InputHandler::InputHandler(
	ICommand* ButtonW,
	ICommand* ButtonS,
	ICommand* ButtonSpace)
{
	this->_ButtonW = ButtonW;
	this->_ButtonS = ButtonS;
	this->_ButtonSpace = ButtonSpace;
}

ICommand* InputHandler::HandleInput(char Input)
{
	Input = std::tolower(Input);

	switch (Input)
	{
	case 'w':
		return _ButtonW;

	case 's':
		return _ButtonS;

	case ' ':
		return _ButtonSpace;

	default:
		return &NlCmd;
	}
}
