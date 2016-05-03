#include "Login.h"
#include "studentLogin.h"
#include <iostream>
#include <string>
using namespace std;


Login::Login(UiLibraryContext* context, seasonConfig season1, int idterminal1) : idterminal(idterminal1), season(season1){
	this->context = context;
}

bool Login::handleInput(int c){
	switch (c)
	{
	case '1':{
		studentLogin* state = new studentLogin(context, season, idterminal);
		context->setState(state);
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

void Login::display(){
	system("CLS");
	cout << "1 - Studnet" << endl;
	cout << "2 - System" << endl;
	cout << "q- Exit" << endl;

}