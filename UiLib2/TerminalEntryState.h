#ifndef TerminalEntryState_H
#define TerminalEntryState_H
#include "EntryDisplayState.h"
#include "seasonConfig.h"
#include <string.h>
#include <iostream>
using namespace std;

class TerminalEntryState : public EntryDisplayState {
public:
	int cur_sel;
	seasonConfig season;
	Terminal terminal;
	TerminalEntryState(UiLibraryContext* context, seasonConfig season1, Terminal terminal1);
	int getFieldCount();
	string getCaption(int index);
	string getValue(int index);
	void edit(int index);
	void entryReturnState();

};

#endif

