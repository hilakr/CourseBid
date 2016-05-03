#ifndef Login_H
#define Login_H
#include "UiLibraryState.h"
#include "seasonConfig.h"

class Login : public UiLibraryState{
public:

	int idterminal;

	seasonConfig season;

	Login(UiLibraryContext* context, seasonConfig season1, int idterminal1);

	bool handleInput(int c);

	void display();
};

#endif