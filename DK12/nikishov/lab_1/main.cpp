#include <iostream>

#include "lab.h"

using namespace std;

int main()
{
	num a = 0, b = 0, c = 0, fc = 0, res = 0;
	cout << "Enter a, b and c. Separate each value with space." << endl;
	cin >> a >> b >> c;
	if(c == 0 or c < 0) {
		cerr << "Error: c can't be zero or negative." << endl;
		return EXIT_FAILURE;
	}

	for(unsigned d = 0; d <= c; d++) fc += factorial(a + (num)d);

	res = a * (sqroot(b+c) / b ) + fc;

	cout << "result: " << res << endl;

	return EXIT_SUCCESS;
}

