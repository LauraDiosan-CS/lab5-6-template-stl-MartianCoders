#include <iostream>
#include <crtdbg.h>
#include "repository.h"
#include "repositoryF.h"
#include "controler.h"
#include "UI.h"
#include "tests.h"

int main() {
	{test_all();
	RepositoryF<Cookie> storage("data.txt");
	Controler controler(storage);
	UI ui(controler);
	ui.runUI();
	}
	_CrtDumpMemoryLeaks();
}