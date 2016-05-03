#ifndef Shibetz_Courses_H
#define Shibetz_Courses_H
#include "UiLibraryState.h"
#include "seasonConfig.h"
class finalCourses : public UiLibraryState{
public:
	seasonConfig season;
	finalCourses(UiLibraryContext* context, seasonConfig season1);
	void display();
	bool handleInput(int c);
};


#endif