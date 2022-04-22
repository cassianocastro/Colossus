#include <iso646.h>
#include "./includes/globals.h"
#include "./includes/helpers.h"

char* getContent(char* cardinal, char* ordinal)
{
	return (isLastDivision and isOrdinal) ? ordinal : cardinal;
}

void sufixo_ordinal(char* text)
{
	strcat(text, (isMulher) ? "a " : "o ");
}

void sufixo_cardinal(char* text)
{
	strcat(text, (isMulher) ? "as " : "os ");
}

void getRepr(char* text, char* cardinal, char* ordinal)
{
    if (isLastDivision and isOrdinal)
    {
        strcpy(text, ordinal);
        sufixo_ordinal(text);
		return;
    }
	strcpy(text, cardinal);
}