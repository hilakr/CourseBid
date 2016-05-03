#ifndef CourseEditingState_H
#define CourseEditingState_H
#include "EntryDisplayState.h"
#include "seasonConfig.h"
#include <string.h>
#include <iostream>
using namespace std;


class CourseEditingState : public EntryDisplayState {
public:
	Course course;
	seasonConfig season;

	CourseEditingState(UiLibraryContext* context1, seasonConfig season1, Course course1);

	bool Circle(vector<string>&vec);

	int getFieldCount();

	void edit(int i);

	string getCaption(int i);

	string getValue(int i);
	
	void entryReturnState();
};


#endif 
