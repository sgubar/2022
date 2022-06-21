#include "note.h"

Note::Note(char nt = 'A', bool d = 0, int oc = 1)
{
	note = nt;
	db = d;
	octave = oc;
}

void Note::change(char nt, bool d, int oc)
{
	note = nt;
	db = d;
	octave = oc;
}

char Note::get_note(void)
{
	return note;
}

bool Note::get_db(void)
{
	return db;
}

int Note::get_octave()
{
	return octave;
}
