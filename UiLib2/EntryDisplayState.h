#ifndef EntryDisplayState_H
#define EntryDisplayState_H
#include "UiLibraryState.h"
#include <string>
#include <iostream>
using namespace std;


class EntryDisplayState : public UiLibraryState {

public:
	int cur_sel;

	EntryDisplayState();

	bool handleInput(int c);

	void display();

	virtual int getFieldCount() = 0;

	virtual string getCaption(int index) = 0;

	virtual string getValue(int index) = 0;

	virtual void edit(int index) = 0;

	virtual void entryReturnState() = 0;
};


#endif