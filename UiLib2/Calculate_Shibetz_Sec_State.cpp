#include "Calculate_Shibetz_Sec_State.h"
#include "CourseListEditingState.h"
#include "StudentListEditingState.h"
#include "loginSec.h"
#include "Shibetz_Students.h"
#include "Shibetz_Courses.h"
#include <iostream>
using namespace std;

Shibetz::Shibetz(UiLibraryContext* context, seasonConfig season1): season(season1){
	this->context = context;
	

}

void Shibetz::display()
{
/*	Calculate cal(season);
	cal.myCalculate();*/
	
	cout << "1-Studnet final courses" << endl;
	cout << "2-Course final students" << endl;
	cout << "3-Return" << endl;
	cout << "q-Exit" << endl;
}


bool Shibetz::handleInput(int c){
	switch (c)
	{
	case '1':
	{
		finalStudents* state1 = new finalStudents(context, season);
		context->setState(state1);
		break;
	}
	case '2':
	{
		finalCourses* state2 = new finalCourses(context, season);
		context->setState(state2);
		break;
	}
	case '3':
	{
		loginSec* state3 = new loginSec(context, season);
		context->setState(state3);
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
