#ifndef SystemLogin_H
#define SystemLogin_H
#include "UiLibraryState.h"
#include "FileStroage.h"
#include "IdObjectFactory.h"
class SystemLogin : public UiLibraryState{
public:

	int idterminal;

	FileStorage storage;
	IdObjectFactory factory;

	SystemLogin(FileStorage storage1, IdObjectFactory factory1);

	bool handleInput(int c);

	void display();
};

#endif