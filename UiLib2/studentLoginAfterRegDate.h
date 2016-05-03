#ifndef studentLoginAfterRegDate_H
#define studentLoginAfterRegDate_H
#include "UiLibraryState.h"
#include "seasonConfig.h"


class studentLoginAfterRegDate :public UiLibraryState{
public:
	int wrongPassword;
	seasonConfig season;
	int idTerminal;
	studentLoginAfterRegDate(UiLibraryContext* context, seasonConfig season1, int idTerminal1);
	bool handleInput(int c);
	void display();
	void checkPassword();
};



#endif 