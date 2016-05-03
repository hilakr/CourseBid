#include "preState.h"
#include "CourseEditingState.h"
#include <string>
#include <exception>
#include <iostream>
using namespace std;

preState::preState(UiLibraryContext* context1, seasonConfig season1, int idobj1) : season(season1), idobj(idobj1), cur_sel(0){
	context = context1;
}

bool preState::handleInput(int c){
	try{
		switch (c)
		{
		case '1':
			add(cur_sel, idobj);
			break;
		case '2':
			remove(cur_sel, idobj);
			break;
		case 'r':
			returnStateCourseEntry();
			break;
		case 72:
			cur_sel--;
			if (cur_sel < 0)
				cur_sel = 0;
			break;
		case 80:
			cur_sel++;
			if (cur_sel > this->season.courseList.count())
				cur_sel = 0;
			break;
		case 'q':
		case 'Q':
			return false;
		default:
			break;

		};
	}
	catch (exception &e){
		cout << e.what() << endl;
	}


	return true;
};

void preState::display(){
	int x = season.courseList.count() - 1;
	if (season.courseList.count() - 1 == 0)
	{
		cout << "No courses" << endl;
	}
	else
	{
		for (int i = 0; i < season.courseList.count() - 1; i++)
		{
			if (i == cur_sel)
				cout << "*" << i << "-> " << season.courseList.get(i).id.get() << endl;

			else
				cout << i << "-> " << season.courseList.get(i).id.get() << endl;

		}
	}
	cout << "Opitions: " << endl;
	cout << "1 -> add" << endl;
	cout << "2 -> remove" << endl;
	cout << "r -> return" << endl;
	cout << "q -> exit" << endl;
}

void preState::add(int index, int idobj){
	if (season.courseList.count() - 1 == 0)
		throw exception("No courses to add");
	Course temp = season.courseList.get(index);
	Course course = season.getFactory().construct<Course>(idobj);
	for (int i = 0; i < season.courseList.get(i).pre.count(); i++)
		if (temp.id.get() == season.courseList.get(i).pre.get(i).id.get())
			cout << "Already in the list " << endl;
		else
			course.pre.add(temp);
	cout << "Added successfully" << endl;


}
void preState::remove(int index, int idobj){

	if (season.courseList.count() == 0)
		throw exception("The list is empty");
	int idcourse = season.courseList.get(index).id.get();
	Course course = season.getFactory().construct<Course>(idobj);
	/*cout << "BEFORE - num of courses " << course.pre.count() << endl;*/
	for (int i = 0; i < course.pre.count(); i++)
	{
		if (course.pre.get(i).id.get() == idcourse)
			course.pre.remove(i);

	}
	/*cout << "Test" << endl;
	cout << "print the courses" << endl;*/
	for (int i = 0; i < course.pre.count(); i++)
	{
		cout << course.pre.get(i).id.get() << ",";

	}
	cout << "Deleted successfully" << endl;

}

void preState::returnStateCourseEntry(){
	CourseEditingState* state = new CourseEditingState(context, season, season.getFactory().construct<Course>(idobj));
	context->setState(state);
}