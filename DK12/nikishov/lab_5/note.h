#ifndef NOTE_H
#define NOTE_H

class Note
{
	private:

	char note;
	bool db;
	int octave;

	public:

	Note(char nt, bool d, int oc);
	void change(char nt, bool d, int oc);
	char get_note();
	bool get_db();
	int get_octave();
};

#endif // NOTE_H
