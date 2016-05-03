#ifndef StudentEditingState_H
#define StudentEditingState_H
#include "EntryDisplayState.h"
#include <seasonConfig.h>
#include <string>
#include <iostream>
using namespace std;

class StudentEditingState : public EntryDisplayState {

public:

	Student studnet;

	seasonConfig season;

	StudentEditingState(UiLibraryContext* context1, seasonConfig season1, Student student1);

	int getFieldCount();

	string getCaption(int i);

	string getValue(int i);

	void edit(int i);

	void entryReturnState();
};


#endif 