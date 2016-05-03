#include "EditFormulaDisplayState.h"
#include "Lexer.h"
#include "loginSec.h"
#include <string>
#include <iostream>
#include "Terminal.h"
#include "Login.h"
using namespace std;

EditFormulaDisplayState::EditFormulaDisplayState(UiLibraryContext* context, seasonConfig season1) : season(season1) {
	this->context = context;
}
void EditFormulaDisplayState::display(){
	cout << "Formula -> " << season.formula.get() << endl;
	cout << "Optioins: " << endl;
	cout << "1- Edit" << endl;
	cout << "2- Return " << endl;


}

bool EditFormulaDisplayState::handleInput(int c){
	switch (c)
	{
	case '1':
		edit();
		break;
	case 'r':
		returnState();
		break;
	case 'q':
	case 'Q':
		return false;
	default:
		break;

	};
	return true;

}


void EditFormulaDisplayState::edit(){
	Lexer lexer;
	string experssion;
	cout << "Please enter experssion that include the following:" << endl;
	cout << "Negative and Positive numbers" << endl;
	cout << "Operators:+,-,*,/" << endl;
	cout << "Example: 100+2*@" << endl;
	cin >> experssion;
	lexer.setExpr(experssion);
	lexer.tokenize();
	season.formula.set(experssion);
};

void EditFormulaDisplayState::returnState(){
	loginSec* state = new loginSec(context, season);
	context->setState(state);

}