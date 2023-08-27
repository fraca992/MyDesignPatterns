/*
		this pattern is used for decoupling the handler/invoker from the business logic
		by making commands objects that completely represent actions.
		allowing for swapping actions easily and for logging,undo,queue of actions
*/
#include <iostream>
#include "Headers/InputHandler.h"
#include "Headers/Actor.h"

int main()
{
	UpCommand uc(3);
	DownCommand dc(3);
	ShootCommand sc;
	InputHandler Invoker(&uc, &dc, &sc);

	Actor Player1("Jonathan");
	Actor Player2("Marlongo");

	while (true)
	{
		std::cout << "enter input (w,s,space or q to quit): ";
		char Input = std::getchar();
		if (std::tolower(Input) == 'q') break;

		// This here acts as Dispatcher.
		// Receives command from the Invoker (AI)
		// and Executes the command on the desired Actor
		ICommand* Command = Invoker.HandleInput(Input);
		Command->Execute(Player1);
		Command->Execute(Player2);
		// If decoupling of command and actor is not necessary
		// the Invoker may directly call Execute in HandleInput

		// If a command has to be tightly coupled to an Actor
		// it is better to put it in the constructor
		// and create a new instance of a Command anytime a new actor is
		// to be commanded
		// remember garbage collect!



		while (getchar() != '\n'); // to flush the \n from input stream
	}
	



}