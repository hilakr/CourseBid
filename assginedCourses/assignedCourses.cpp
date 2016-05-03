// CourseBid.cpp : Defines the entry point for the console application.
#include <vector>
#include <string.h>
#include "FileStroage.h"
#include "IdObjectFactory.h"
#include "Terminal.h"
#include "seasonConfig.h"
#include "loginSec.h"
#include <iostream>
#include <lemon/glpk.h>
#include <lemon/lp.h>
#include "myCalLib.h"
#include "Shibetz_Courses.h"
#include "Shibetz_Students.h"
using namespace lemon;
using namespace std;


int main()

{
	
	FileStorage storage("db.txt");
	IdObjectFactory factory(storage);
	calculate cal(storage, factory);
	cal.assignedCoursestoStudents();
	int input;
	seasonConfig season = factory.construct<seasonConfig>(0);
	UiLibraryContext* context = new UiLibraryContext();
	cout << "1 - Display final courses for student" << endl;
	cout << "2 - Display final students for course " << endl;
	cout << "q-Exit" << endl;
	cin >> input;
	try{

		switch (input)
		{
		case 1:
		{
			finalStudents* state = new finalStudents(context, season);
			context->setState(state);
			context->run();
		}
		break;
		case 2:

		{
			finalCourses* state = new finalCourses(context, season);
			context->setState(state);
			context->run();
		}
		break;
		case 'q':
		case 'Q':
			return 0;
		default:
			break;
		};

	}
	catch (exception e){
		cout << e.what() << endl;
	}

	return 0;
}; 