#include "TerminalEntryState.h"
#include "TerminalState.h"
#include <string>
#include <iostream>
using namespace std;

TerminalEntryState::TerminalEntryState(UiLibraryContext* context, seasonConfig season1, Terminal terminal1) : season(season), terminal(terminal1){
	this->context = context;
}

int  TerminalEntryState::getFieldCount(){
	return 3;
};

string TerminalEntryState::getCaption(int index){
	if (index == 0)
		return "id";
	if (index == 1)
		return "password";
	if (index == 2)
		return "status";

}

string TerminalEntryState::getValue(int index){
	if (index == 0)
		return terminal.id.get();
	if (index == 1)
		return terminal.password.get();
	if (index == 2)
		return to_string(terminal.status.get());
};

void TerminalEntryState::edit(int index){
	string value;
	if (index == 0)
	{
		cout << "Enter new id " << endl;
		cin >> value;
		terminal.id.set(value);
	}
	if (index == 1)
	{
		cout << "Enter new password " << endl;
		cin >> value;
		terminal.id.set(value);
	}
	if (index == 0)
	{
		cout << "Enter new status " << endl;
		cin >> value;
		terminal.id.set(value);
	}
}

void TerminalEntryState::entryReturnState(){
	TerminalState* state = new TerminalState(context, season);
	context->setState(state);
}