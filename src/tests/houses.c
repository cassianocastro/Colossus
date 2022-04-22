#include <iso646.h>
#include <string.h>

#include "./includes/houses.h"
#include "./includes/helpers.h"

char* numext(uint value, char* response)
{
    houses house = {
        value / 100,
        (value % 100) / 10,
        (value % 100) % 10
    };

    defineCentena(house, response);
    defineDezena(house, response);
    defineUnidade(house, response);

    return response;
}

void setHouseOfCentenas(houses house, char* response)
{
    char text[40] = "";

    switchCentena(house, text);

	if (house.c not_eq 1 and house.d not_eq 0 and not isOrdinal)
    {
        sufixo_cardinal(text);
        strcat(text, "e ");
    }
    strcat(response, text);
}

void setHouseOfDezenas(houses house, char* response)
{
    char text[40] = "";

    switchDezena(house, text);

	if (house.d not_eq 1 and house.u not_eq 0 and not isOrdinal)
    {
        strcat(text, " e ");
    }
    strcat(response, text);
}

void setHouseOfUnidades(houses house, char* response)
{
    if (house.d == 1) return;

    char text[40] = "";

    switchUnidade(house, text);
    strcat(response, text);
}

void switchCentena(houses houseOf, char* text)
{
    switch (houseOf.c)
    {
	    case 1:
            getRepr(text, (houseOf.d == 0 and houseOf.u == 0) ? "Cem " : "Cento e ", "Centésim");
	    	break;
	    case 2:
            //strcpy(text, getContent("Duzent", "Ducentésim"));
	    	getRepr(text, "Duzent", "Ducentésim");
			break;
	    case 3:
	    	getRepr(text, "Trezent", "Tricentésim");
	    	break;
	    case 4:
	    	getRepr(text, "Quatrocent", "Quadrigentésim");
	    	break;
	    case 5:
	    	getRepr(text, "Quinhent", "Quingentésim");
	    	break;
	    case 6:
	    	getRepr(text, "Seiscent", "Seiscentésim");
	    	break;
	    case 7:
	    	getRepr(text, "Setecent", "Septigentésim");
			break;
	    case 8:
	    	getRepr(text, "Oitocent", "Octigentésim");
	    	break;
	    case 9:
	    	getRepr(text, "Novecent", "Nongentésim");
    }
}

void switchDezena(houses houseOf, char* text)
{
    switch (houseOf.d)
    {
		case 1:
            switchCase1(houseOf.u, text);
			break;
	    case 2:
	    	getRepr(text, "Vinte","Vigésim");
	    	break;
	    case 3:
	    	getRepr(text, "Trinta","Trigésim");
	    	break;
	    case 4:
	    	getRepr(text, "Quarenta","Quadragésim");
	    	break;
	    case 5:
	    	getRepr(text, "Cinquenta","Quinquagésim");
	    	break;
	    case 6:
	    	getRepr(text, "Sessenta","Sexagésim");
	    	break;
	    case 7:
	    	getRepr(text, "Setenta","Septuagésim");
	    	break;
	    case 8:
	    	getRepr(text, "Oitenta","Octagésim");
	    	break;
	    case 9:
	    	getRepr(text, "Noventa","Nonagésim");
    }
}

void switchUnidade(houses houseOf, char* text)
{
    switch (houseOf.u)
    {
        case 1:
            if (isOrdinal)
                strcpy(text, (isMulher) ? "Primeira" : "Primeiro");
            else
                strcpy(text, (isMulher) ? "Uma " : "Um ");
            break;
        case 2:
            if (isOrdinal)
                strcpy(text, (isMulher) ? "Segunda" : "Segundo");
            else
                strcpy(text, (isMulher) ? "Duas " : "Dois ");
            break;
        case 3:
            getRepr(text, "Três ", "Terceir");
            break;
        case 4:
            getRepr(text, "Quatro ", "Quart");
            break;
        case 5:
            getRepr(text, "Cinco ", "Quint");
            break;
        case 6:
            getRepr(text, "Seis ", "Sext");
            break;
        case 7:
            getRepr(text, "Sete ", "Sétim");
            break;
        case 8:
            getRepr(text, "Oito ", "Oitav");
            break;
        case 9:
            getRepr(text, "Nove ", "Non");
    }
}

void switchCase1(int u, char* text)
{
    switch (u)
    {
        case 0:
            getRepr(text, "Dez ", "Décim");
            break;
        case 1:
            getRepr(text, "Onze ", (isMulher) ? "Décima Primeir" : "Décimo Primeir");
            break;
        case 2:
            getRepr(text, "Doze ", (isMulher) ? "Décima Segund" : "Décimo Segund");
            break;
        case 3:
            getRepr(text, "Treze ", (isMulher) ? "Décima Terceir" : "Décimo Terceir");
            break;
        case 4:
            getRepr(text, "Catorze ", (isMulher) ? "Décima Quart" : "Décimo Quart");
            break;
        case 5:
            getRepr(text, "Quinze ", (isMulher) ? "Décima Quint" : "Décimo Quint");
            break;
        case 6:
            getRepr(text, "Dezesseis ", (isMulher) ? "Décima Sext" : "Décimo Sext");
            break;
        case 7:
            getRepr(text, "Dezesete ", (isMulher) ? "Décima Sétim" : "Décimo Sétim");
            break;
        case 8:
            getRepr(text, "Dezoito ", (isMulher) ? "Décima Oitav" : "Décimo Oitav");
            break;
        case 9:
            getRepr(text, "Dezenove ", (isMulher) ? "Décima Non" : "Décimo Non");
    }
}