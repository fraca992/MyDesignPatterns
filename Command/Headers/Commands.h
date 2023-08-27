// list of possible actions.
// they are derived from a common IAction interface.
// A command MAY perform the action directly or
// contain a reference to the Object that will
#pragma once
#include "ICommand.h"
#include "Actor.h"
#include <iostream>

class UpCommand : public ICommand
{
private:
	int _Amount;

public:
	UpCommand(int Amount) : _Amount(Amount) {}

	void Execute(Actor& CommandedActor) const override{
		CommandedActor.GoUp(_Amount);
	}
};

class DownCommand : public ICommand
{
private:
	int _Amount;

public:
	DownCommand(int Amount) : _Amount(Amount) {}

	void Execute(Actor& CommandedActor) const override{
		CommandedActor.GoDown(_Amount);
	}
};

class ShootCommand : public ICommand
{
public:
	void Execute(Actor& CommandedActor) const override {
		CommandedActor.Shoot();
	}
};


// used to avoid having a null command pointer
class NULLCommand : public ICommand
{
public:
	void Execute(Actor& CommandedActor) const{}
};