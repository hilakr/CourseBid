#include "FileStroage.h"
#include "IdObjectFactory.h"
#include "Terminal.h"
#include "Login.h"
using namespace std;

int main()
{
	cout << "hello" << endl;
	FileStorage storage("db.txt");
	IdObjectFactory factory(storage);
	seasonConfig season(0, factory);
	Terminal terminal = season.getFactory().allocate<Terminal>();
	UiLibraryContext* context = new UiLibraryContext();
	Login* state = new Login(context, season,terminal.get_id());
	context->setState(state);
	context->run();
	return 1;

};