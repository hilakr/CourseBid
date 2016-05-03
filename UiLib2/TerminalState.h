#ifndef TerminalState_H
#define TerminalState_H
#include "ListDisplayState.h"
#include "seasonConfig.h"
#include <iostream>
using namespace std;

class TerminalState : public ListDisplayState{

public:
	seasonConfig season;
	TerminalState(UiLibraryContext* context, seasonConfig season1);
	string get(int index);
	void select(int index);
	void myDelete(int index);
	void add(int index);
	int countList();
	void returnState();

};



#endif
