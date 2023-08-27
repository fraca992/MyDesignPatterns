#pragma once
#include"Actor.h"

class ICommand
{
public:
	~ICommand() {}

	virtual void Execute(Actor& CommandedActor) const = 0;
	//virtual void Undo() = 0; //if needed, could implement an Undo method
};