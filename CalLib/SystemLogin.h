#ifndef SystemLogin_H
#define SystemLogin_H
#include "UiLibraryState.h"
#include "seasonConfig.h"

class SystemLogin : public UiLibraryState{
public:

	int idterminal;

	seasonConfig season;

	SystemLogin(UiLibraryContext* context, seasonConfig season1, int idterminal1);

	bool handleInput(int c);

	void display();
};

#endif