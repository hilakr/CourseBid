#ifndef completetdState_H
#define completetdState_H
#include "UiLibraryState.h"
#include "seasonConfig.h"
#include <string.h>
#include <iostream>
using namespace std;

class combState : public UiLibraryState{

public:
seasonConfig season;
int idobj;
int cur_sel;

combState(UiLibraryContext* context1, seasonConfig season1, int idobj1);

bool handleInput(int c);

void display();

void add(int index, int idobj);

void remove(int index, int idobj);

void returnStudentEnrty();
};

#endif