#ifndef Shibetz_Students_H
#define Shibetz_Students_H
#include "UiLibraryState.h"
#include "seasonConfig.h"
class finalStudents: public UiLibraryState{
public:
	seasonConfig season;
	finalStudents(UiLibraryContext* context, seasonConfig season1);
	void display();
	bool handleInput(int c);
};


#endif