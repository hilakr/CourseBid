#pragma once
#ifndef UiLibraryState_H
#define UiLibraryState_H
#include "UiLibraryContext.h"
class UiLibraryState{

public:

	UiLibraryContext* context;
	
	virtual bool handleInput(int c) = 0;
	
	virtual void display() = 0;

};


#endif