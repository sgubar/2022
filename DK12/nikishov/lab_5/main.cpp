#include <iostream>

#include "note.h"

int main()
{
	Note a('A', 0, 1);
	a.change('B', 1, 4);
	std::cout << "Note:\n" << a.get_note();
	if(a.get_db()) std::cout << "d";
	else std::cout << "b";

	std::cout << "\noctave: " << a.get_octave() << std::endl;
	return 0;
}
