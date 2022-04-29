#include "stdio.h"

int main()
{
	ElipsArray *createElipsArray(int count)
	{
		ElipsArray *array = (ElipsArray *)malloc(sizeof(ElipsArray));
		if (array != NULL)
		{
			if (count == 0)
			{
				printf("Count must be > 0!			<<}>>				");
				return NULL;
			}
			array->count = abs(count);
			array->storage = (Elips **)malloc(sizeof(Elips *) * array->count);
			bzero(array->storage, sizeof(Elips *) * array->count);
		}
		return array;
	};
}
