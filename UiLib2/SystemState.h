#ifndef SystemState_H
#define SystemState_H
#include "UiLibraryState.h"
#include "FileStroage.h"
#include "IdObjectFactory.h"
class SystemState : public UiLibraryState{
public:

	int idterminal;

	FileStorage storage;
	IdObjectFactory factory;

	SystemState(FileStorage storage1, IdObjectFactory factory1);

	bool handleInput(int c);
	void checkSystem();

	void display();
};

#endif