#include "SystemLogin.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "myCalLib.h"
#include "FileStroage.h"
#include "IdObjectFactory.h"
#include "seasonConfig.h"
using namespace std;


SystemLogin::SystemLogin(UiLibraryContext* context, seasonConfig season1, int idterminal1) : idterminal(idterminal1), season(season1){
	this->context = context;
}

bool SystemLogin::handleInput(int c){
	switch (c)
	{
	case '1':{
		/*studentLogin* state = new studentLogin(context, season, idterminal);
		context->setState(state);*/
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

void SystemLogin::display(){
	system("CLS");
	string temp_str, token1, token2,input,line;
	cout << "Enter password" << endl;
	cin >> input;
	string name = "system.txt";
	ifstream file(name);
	while (!file.eof()) {
		file >> temp_str;
		std::istringstream ss(temp_str);
		getline(ss, token1, ':');
		getline(ss, token2, '\n');

	}
	calculate myCal(storage, factory);
	myCal.assignedCoursestoStudents();
	
	if (input == "system")
	{
		cout << "The system checking is starting" << endl;
	}
		

}