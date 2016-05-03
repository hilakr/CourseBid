#include "EntryDisplayState.h"
#include <iostream>
#include <string>
using namespace std;

EntryDisplayState::EntryDisplayState() : cur_sel(0) {}

bool EntryDisplayState::handleInput(int c){
	switch (c)
	{
	case '1':
		cout << this->getValue(cur_sel) << endl;

		break;
	case '2':
		edit(cur_sel);
		break;
	case 72:
		cur_sel--;
		if (cur_sel < 0)
			cur_sel = 0;
		break;
	case 80:
		cur_sel++;
		if (cur_sel > this->getFieldCount())
			cur_sel = 0;
		break;
	case 'r':
		entryReturnState();
		break;
	case 'q':
	case 'Q':
		return false;
	default:
		break;

	};
	return true;
};

void EntryDisplayState::display(){
	/*system("CLS");*/
	cout << "Opitions: " << endl;
	cout << "1 -> show details" << endl;
	cout << "2 -> edit" << endl;
	cout << "r -> return" << endl;
	cout << "Fields:" << endl;
	int count = this->getFieldCount();
	for (int i = 0; i < count; i++)
	{
		if (i == cur_sel)
			cout << "*" << i << "-> " << this->getCaption(i) << endl;

		else
			cout << i << "-> " << this->getCaption(i) << endl;

	}

};