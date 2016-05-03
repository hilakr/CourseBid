#ifndef EditFormulaDisplayState_H
#define EditFormulaDisplayState_H
#include "UiLibraryState.h"
#include "seasonConfig.h"


class EditFormulaDisplayState : public UiLibraryState {
public:
	seasonConfig season;

	EditFormulaDisplayState(UiLibraryContext* context, seasonConfig season1);

	void display();

	bool handleInput(int c);

	void edit();

	void returnState();

};


#endif