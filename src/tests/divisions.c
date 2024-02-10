#include "./includes/divisions.h"

void numeroextenso(uint value)
{
    char response[300] = "";

    setDivisionOfMilhoes(value, response);
    setDivisionOfMilhares(value, response);
    setDivisionOfCentenas(value, response);

    printf("\n%s\n", response);
}

void setDivisionOfMilhoes(uint value, char* response)
{
    uint milhao = value / 1000000;

    if (milhao == 0) return;

    char text[20] = "Milhonésim";

    if (milhao > 1)
    {
        numext(milhao, response);
        sufixo_cardinal(text);
        strcat(response, (isOrdinal) ? text : "Milhões, ");
        return;
    }
    sufixo_ordinal(text);
    strcpy(response, (isOrdinal) ? text : "Um Milhão, ");
}

void setDivisionOfMilhares(uint value, char* response)
{
    uint mil = (value % 1000000) / 1000;

	if (mil == 0) return;

    if (mil == 1)
    {
        if (isOrdinal)
            strcat(response, (isMulher) ? "Milésima" : "Milésimo");
        else
            strcat(response, "Mil");
        return;
    }

    numext(mil, response);

    if (isOrdinal)
        strcat(response, (isMulher) ? "Milésimas, " : "Milésimos, ");
    else
        strcat(response, "Mil, ");
}

void setDivisionOfCentenas(uint value, char* response)
{
    uint cent = (value % 1000000) % 1000;

    if (cent == 0) return;

    isLastDivision = true;
    numext(cent, response);
}