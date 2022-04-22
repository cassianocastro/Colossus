#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

bool isMulher, isOrdinal, isLastDivision;

typedef unsigned int uint;
typedef unsigned char byte;

typedef struct
{
    uint value;
    byte sex;
    byte type;
} inputs;

typedef struct
{
    int c;
    int d;
    int u;
} houses;

// char* getContent(char* cardinal, char* ordinal)
// {
// 	return (isLastDivision and isOrdinal) ? ordinal : cardinal;
// }

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

void defineCentena(houses house, char* response)
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

void defineDezena(houses house, char* response)
{
    char text[40] = "";

    switchDezena(house, text);

	if (house.d not_eq 1 and house.u not_eq 0 and not isOrdinal)
    {
        strcat(text, " e ");
    }
    strcat(response, text);
}

void defineUnidade(houses house, char* response)
{
    if (house.d == 1) return;

    char text[40] = "";

    switchUnidade(house, text);
    strcat(response, text);
}

char* numext(int number, char* response)
{
    houses house = {
        number / 100,
        (number % 100) / 10,
        (number % 100) % 10
    };

    defineCentena(house, response);
    defineDezena(house, response);
    defineUnidade(house, response);

    return response;
}

void getMilhao(int value, char* response)
{
    int milhao = value / 1000000;

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

void getMil(uint value, char* response)
{
    int mil = (value % 1000000) / 1000;

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

void getCentenas(uint value, char* response)
{
    uint cent = (value % 1000000) % 1000;

    if (cent == 0) return;

    isLastDivision = true;
    numext(cent, response);
}

void numeroextenso(uint value)
{
    char response[300] = "";

    getMilhao(value, response);
    getMil(value, response);
    getCentenas(value, response);

    printf("\n%s\n", response);
}

bool isInvalid(uint value)
{
    const uint MIN_VALUE = 0;
    const uint MAX_VALUE = 999999999;

    return value <= MIN_VALUE or value > MAX_VALUE;
}

inputs getUserInputs(void)
{
    inputs input = { 0, '\0', '\0' };

	do
    {
    	printf("\nDigite um valor entre 0 e 999.999.999: ");
	    scanf("%d", &input.value);
	} while ( isInvalid(input.value) );

    printf("\nEscolha 1 para feminino ou 0 para masculino. Opção\? ");
    scanf(" %c", &input.sex);

    printf("\n1 para cardinal ou 0 para ordinal: ");
    scanf(" %c", &input.type);

    return input;
}

void startApp(void)
{
    inputs i  = getUserInputs();
    isMulher  = i.sex  == '1';
    isOrdinal = i.type == '0';

    numeroextenso(i.value);
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");

    startApp();

    return EXIT_SUCCESS;
}