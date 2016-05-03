#include "loginSec.h"
#include "CourseListEditingState.h"
#include "StudentListEditingState.h"
#include "EditFormulaDisplayState.h"
#include "TerminalState.h"
#include "Calculate_Shibetz_Sec_State.h"
#include <iostream>
#include <string>
using namespace std;


loginSec::loginSec(UiLibraryContext* context, seasonConfig season1) : season(season1){
	this->context = context;
}


void loginSec::display(){
	cout << "1-Courses" << endl;
	cout << "2-Students" << endl;
	cout << "3-Formula" << endl;
	cout << "4-Terminals" << endl;
	cout << "5- Calculate shibetz" << endl;
	cout << "q- Exit" << endl;

}

bool loginSec::handleInput(int c){
	switch (c)
	{
	case '1':
	{
		CourseListEditingState* state1 = new CourseListEditingState(context, season);
		context->setState(state1);
		break;
	}
	case '2':
	{
		StudentListEditingState* state2 = new StudentListEditingState(context, season);
		context->setState(state2);
		break;
	}
	case '3':
	{
		EditFormulaDisplayState* state3 = new EditFormulaDisplayState(context, season);
		context->setState(state3);
		break;
	}
	case '4':
	{
		TerminalState* state3 = new TerminalState(context, season);
		context->setState(state3);
		break;
	}
	case '5':
	{
		Shibetz* state4 = new Shibetz(context, season);
		context->setState(state4);
		break;
	}
	case 'q':
	case 'Q':
		return false;
	default:
		break;

	};
	return true;

};