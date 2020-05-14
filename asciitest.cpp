#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char a;

	for (a = 0; a < 255; ++a)
	{
		cout << int(a) << ": " << a << endl;
	}
	
	return 0;
}
