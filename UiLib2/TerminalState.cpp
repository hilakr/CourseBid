#include "TerminalState.h"
#include "TerminalEntryState.h"
#include <string>
#include <iostream>
using namespace std;
#include <conio.h>
#include <cstdlib>
#include <exception>
#include "loginSec.h"
TerminalState::TerminalState(UiLibraryContext* context, seasonConfig season1) : season(season1){
	this->context = context;
}

int TerminalState::countList(){
	return season.terminalList.count();
}

string TerminalState::get(int index){
	if (season.terminalList.count() == 0)
		throw exception("The list is empty");
	string value;
	value = season.terminalList.get(index).id.get() + "," + to_string(season.terminalList.get(index).status.get());
	return value;
}


void TerminalState::select(int index){
	if (season.terminalList.count() == 0)
		throw exception("The list is empty");
	TerminalEntryState* state = new TerminalEntryState(context, season, season.terminalList.get(index));
	context->setState(state);
}

void TerminalState::myDelete(int index)
{

	if (season.terminalList.count() == 0)
		throw exception("The list is empty");
	int input;
	cout << "Are you sure you want to delete ?" << endl;
	cout << "if yes enter '1' otherwise enter '0'" << endl;
	input = _getch();
	if (input)
		season.terminalList.remove(index);
	else
		cout << "Not deleted" << endl;

}

void TerminalState::add(int index){
	string input, val;
	cout << "Please insert the following deatils" << endl;
	Terminal newTerminal = season.terminalList.allocateAndAdd();
	season.terminalList.add(newTerminal);
	TerminalEntryState* state = new TerminalEntryState(context, season, newTerminal);
	context->setState(state);


}

void TerminalState::returnState(){
	loginSec* state = new loginSec(context, season);
	context->setState(state);

}