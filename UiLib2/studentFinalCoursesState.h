#ifndef studentFinalCoursesState_H
#define studentFinalCoursesState_H
#include "UiLibraryState.h"
#include "Student.h"
class studentFinalCoursesState: public UiLibraryState{
public:
	Student student;
	studentFinalCoursesState(UiLibraryContext*context, Student student);
	void display();
	bool handleInput(int c);


};








#endif