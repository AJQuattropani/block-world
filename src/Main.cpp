#include "Application.hpp"

//#ifndef DIST
int main(int argc, char* argv[]) {
	int runtime_success = 1;
	{
		Application application;	
		runtime_success = application.run();
	}
	glfwTerminate();
	return runtime_success;
}
//#else

//#include "Windows.h"
//int WinMain(HINSTANCE hInstances, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
//
//	Application application;
//	return application.run();
//}


//#endif