#include "CourseListEditingState.h"
#include <string>
#include <iostream>
using namespace std;
#include <conio.h>
#include <cstdlib>
#include <exception>
#include "loginSec.h"
#include "CourseEditingState.h"
CourseListEditingState::CourseListEditingState(UiLibraryContext* context, seasonConfig season1) : season(season1) {
	this->context = context;
}

string CourseListEditingState::get(int index)
{
	if (season.courseList.count() == 0)
		throw exception("The list is empty");
	string id = to_string(season.courseList.get(index).id.get());
	string name = season.courseList.get(index).name.get();
	string value = id + "," + name;
	return value;
};

void  CourseListEditingState::select(int index) {
	if (season.courseList.count() == 0)
		throw exception("The list is empty");
	CourseEditingState* state = new CourseEditingState(context, season, season.courseList.get(index));
	context->setState(state);
};


void CourseListEditingState::myDelete(int index) {
	int input, idobj, flag = 0;
	if (season.courseList.count() == 0)
		throw exception("The list is empty");
	idobj = season.courseList.get(index).get_id();
	/*check the course isn't in the completed courses of the students*/
	for (int i = 0; i < season.studentList.count(); i++)
	{
		for (int j = 0; j < season.studentList.get(i).completed.count(); j++){
			if (idobj == season.studentList.get(i).completed.get(j).get_id())
			{
				throw exception("This course couldn't be deleted beacuse it is in the completed list of student");
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0)
	{
		for (int i = 0; i < season.courseList.count(); i++){
			for (int j = 0; j < season.courseList.get(i).pre.count(); j++){
				if (idobj == season.courseList.get(i).pre.get(j).get_id())
				{
					throw exception("This course couldn't be deleted beacuse it appears in the pre course of course");
					flag = 1;
					break;
				}
			}
		}
	}

	if (flag == 1)
		throw exception("Not delete course");
	cout << "Are you sure you want to delete ?" << endl;
	cout << "if yes enter '1' otherwise enter '0'" << endl;
	input = _getch();
	if (input)
		season.courseList.remove(index);
	else
		cout << "Not deleted" << endl;

};


void CourseListEditingState::add(int index) {
	string input, val;
	int  idobj;
	cout << "Please insert the following deatils" << endl;
	Course newCourse = season.courseList.allocateAndAdd();
	season.courseList.add(newCourse);
	CourseEditingState* state = new CourseEditingState(context, season, newCourse);
	context->setState(state);

};

int CourseListEditingState::countList() {
	return season.courseList.count();
}

void CourseListEditingState::returnState(){
	system("CLS");
	loginSec* state = new loginSec(context, season);
	context->setState(state);

}



