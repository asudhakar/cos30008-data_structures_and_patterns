#include <iostream>

using namespace std;

int main(int argc, char*argv[]) {
	for (int i = 1; i < argc; i++)
	{
		cout << string(argv[i]) + " ";
	}
	//cout << "Hello World!" << endl;
	return 0;
}