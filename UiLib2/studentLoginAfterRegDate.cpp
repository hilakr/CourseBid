#include "studentLoginAfterRegDate.h"
#include "Terminal.h"
#include "studentFinalCoursesState.h"
#include "Login.h"
#include <string>
#include <iostream>

using namespace std;

studentLoginAfterRegDate::studentLoginAfterRegDate(UiLibraryContext* context, seasonConfig season1, int idTerminal1) :season(season1), idTerminal(idTerminal1){
	this->context = context;
}


void studentLoginAfterRegDate::display(){
	system("CLS");
	cout << "1-Enter password" << endl;
	cout << "q- Exit" << endl;

}

bool studentLoginAfterRegDate::handleInput(int c){
	try{

		switch (c)
		{
		case '1':{
			checkPassword();
			break;
		}
		case 'q':
		case 'Q':
			return false;
		default:
			break;
		};
	}
	catch (exception e){
		cout << e.what() << endl;
	}
	return true;
};

void studentLoginAfterRegDate::checkPassword(){
	int password;
	cout << "password" << endl;
	cin >> password;
	int idobj, check = 0;
	if (wrongPassword < 4)
	{
		for (int i = 0; i < season.studentList.count(); i++)
		{
			string id = season.studentList.get(i).id.get();
			if (password == atoi(id.c_str()))
			{
				idobj = season.studentList.get(i).get_id();
				Student student = season.studentList.get(i);
				/*Enter to bid state*/
				studentFinalCoursesState* state = new studentFinalCoursesState(context, student);
				context->setState(state);
				check = 1;
			}
		}
		if (check == 0)
			cout << "WRONG PASSWORD" << endl;
	}
	wrongPassword++;
	/*lock the terminal*/
	if (wrongPassword == 3)
	{
		cout << "TERMINAL IS LOCKED" << endl;
		season.getFactory().construct<Terminal>(idTerminal).status.set(0);
		exit(0);
	}
}


