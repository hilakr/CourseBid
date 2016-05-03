#include "SystemState.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "myCalLib.h"
#include "FileStroage.h"
#include "IdObjectFactory.h"
#include "seasonConfig.h"
using namespace std;


SystemState::SystemState(FileStorage storage1, IdObjectFactory factory1) : storage(storage1), factory(factory1){
	this->context = context;
}

bool SystemState::handleInput(int c){
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

void SystemState::display(){
	system("CLS");
	string temp_str, token1, token2, input, line;
	cout << "Enter password" << endl;
	cin >> input;
	string name = "system.txt";
	ifstream file(name);
	file >> temp_str;
	std::istringstream ss(temp_str);
	getline(ss, token1, ':');
	getline(ss, token2, '\n');
	if (input == token2)
	{
		cout << "The system checking is starting..." << endl;
	}
	else
		return ;
	checkSystem();
}


void SystemState::checkSystem(){
	calculate myCal(storage, factory);
	myCal.assignedCoursestoStudents();
	seasonConfig season_input = factory.construct<seasonConfig>(0);
	FileStorage storage_output("db_output.txt");
	IdObjectFactory factory_output(storage_output);
	seasonConfig season_output = factory_output.construct<seasonConfig>(0);
	int equal = 1;
	int check = season_output.studentList.count();
	for (int j = 0; j < season_output.studentList.count(); j++)
	{
		for (int i = 0; i < season_output.studentList.get(j).FinalCourses.count(); i++)
		{
			int in = season_input.studentList.get(j).FinalCourses.get(i).id.get();
			int out = season_output.studentList.get(j).FinalCourses.get(i).id.get();
			if (in != out)
			{
				cout << "This Terminal is not Good" << endl;
				equal = 0;
				break;
			}
		}
	}
	
	if (equal)
		cout << "***The check was completed succssefully***" << endl;



}
