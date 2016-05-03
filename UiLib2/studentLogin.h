#ifndef studentLogin_H
#define studentLogin_H
#include "seasonConfig.h"
#include "UiLibraryState.h"
#include <iostream>
using namespace std;

class studentLogin : public UiLibraryState{

public:
	int wrongPassword = 0;
	seasonConfig season;
	int idTerminal;

	studentLogin(UiLibraryContext* context, seasonConfig season1, int idTerminal1);
	bool handleInput(int c);
	void display();
	void checkPassword();
};

#endif 