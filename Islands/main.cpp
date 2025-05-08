#include "Presenter.h"
#include "View.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	// initialize srand for different results each program start
	std::srand(std::time(nullptr));
	
	QApplication a(argc, argv);

	View view;
	view.show();

	Presenter presenter(view);
	
	return a.exec();
}
