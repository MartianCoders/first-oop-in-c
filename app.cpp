#include <iostream>
#include <crtdbg.h>
#include "repository.h"
#include "repositoryF.h"
#include "controler.h"
#include "UI.h"
#include "tests.h"

int main() {
	test_all();
	{
		string file = "data.txt";
		RepositoryF<Cookie> storage(file);
		Controler controler(&storage);
		UI ui(controler);
		ui.runUI();
	}
	_CrtDumpMemoryLeaks();
}