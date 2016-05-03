#pragma once
#ifndef UiLibraryContext_H
#define UiLibraryContext_H

class UiLibraryState;

class UiLibraryContext{
public:
	UiLibraryState* state;

	void setState(UiLibraryState* state1);

	void run();

};


#endif