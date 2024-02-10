#include <locale.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isWoman, isCardinal, flag;

char frase[200];

void helper(char* string, char* ordinal)
{
	if ( flag )
    {
		if ( not isCardinal )
        {
			strcpy(string, ordinal);
            strcat(string, ( isWoman ) ? "a " : "o ");
		}
	}
}

void centenas(char* string, char* cardinal, char* ordinal, int d)
{
	strcpy(string, cardinal);
    strcat(string, ( isWoman ) ? "as " : "os ");

	if ( d != 0 )
    {
		strcat(string, "e ");
    }

	helper(string, ordinal);
}

void dezenas(char* string, char* cardinal, char* ordinal, int u)
{
	strcpy(string, cardinal);

	if ( u != 0 )
    {
		strcat(string, " e ");
    }

	helper(string, ordinal);
}

void casade10(char* string, char* cardinal, char* ordinal)
{
	strcpy(string, cardinal);

	if ( flag )
    {
		if ( not isCardinal )
        {
            strcpy(string, ordinal);
        }
	}
}

void unidades(char* string, char* cardinal, char* ordinal)
{
	strcpy(string, cardinal);

	helper(string, ordinal);
}

void escolheCentena(int c, int d, int u)
{
    char string[20] = "";

    switch ( c )
    {
	    case 1:
	    	strcpy(string, ( d == 0 and u == 0 ) ? "Cem" : "Cento e ");
            helper(string, "Centésim");
	    	break;
	    case 2:
	    	centenas(string, "Duzent", "Ducentésim", d);
			break;
	    case 3:
	    	centenas(string, "Trezent", "Tricentésim", d);
	    	break;
	    case 4:
	    	centenas(string, "Quatrocent", "Quadrigentésim", d);
	    	break;
	    case 5:
	    	centenas(string, "Quinhent", "Quingentésim", d);
	    	break;
	    case 6:
	    	centenas(string, "Seiscent", "Seiscentésim", d);
	    	break;
	    case 7:
	    	centenas(string, "Setecent", "Septigentésim", d);
			break;
	    case 8:
	    	centenas(string, "Oitocent", "Octigentésim", d);
	    	break;
	    case 9:
	    	centenas(string, "Novecent", "Nongentésim", d);
    }

    strcat(frase, string);
}

void escolheCasaDe10(char* string, int u)
{
    char text[15] = "";

    switch ( u )
    {
        case 0:
            strcpy(text, ( isWoman ) ? "Décima" : "Décimo");
            casade10(string, "Dez ", text);
            break;
        case 1:
            strcpy(text, ( isWoman ) ? "Décima Primeira" : "Décimo Primeiro");
            casade10(string, "Onze ", text);
            break;
        case 2:
            strcpy(text, ( isWoman ) ? "Décima Segunda" : "Décimo Segundo");
            casade10(string, "Doze ", text);
            break;
        case 3:
            strcpy(text, ( isWoman ) ? "Décima Terceira" : "Décimo Terceiro");
            casade10(string, "Treze ", text);
            break;
        case 4:
            strcpy(text, ( isWoman ) ? "Décima Quarta" : "Décimo Quarto");
            casade10(string, "Catorze ", text);
            break;
        case 5:
            strcpy(text, ( isWoman ) ? "Décima Quinta" : "Décimo Quinto");
            casade10(string, "Quinze ", text);
            break;
        case 6:
            strcpy(text, ( isWoman ) ? "Décima Sexta" : "Décimo Sexto");
            casade10(string, "Dezesseis ", text);
            break;
        case 7:
            strcpy(text, ( isWoman ) ? "Décima Sétima" : "Décimo Sétimo");
            casade10(string, "Dezesete ", text);
            break;
        case 8:
            strcpy(text, ( isWoman ) ? "Décima Oitava" : "Décimo Oitavo");
            casade10(string, "Dezoito ", text);
            break;
        case 9:
            strcpy(text, ( isWoman ) ? "Décima Nona" : "Décimo Nono");
            casade10(string, "Dezenove ", text);
    }
}

void escolheDezena(int d, int u)
{
    char string[20] = "";

    switch ( d )
    {
        case 1:
            escolheCasaDe10(string, u);
            break;
	    case 2:
	    	dezenas(string, "Vinte", "Vigésim", u);
	    	break;
	    case 3:
	    	dezenas(string, "Trinta", "Trigésim", u);
	    	break;
	    case 4:
	    	dezenas(string, "Quarenta", "Quadragésim", u);
	    	break;
	    case 5:
	    	dezenas(string, "Cinquenta", "Quinquagésim", u);
	    	break;
	    case 6:
	    	dezenas(string, "Sessenta", "Sexagésim", u);
	    	break;
	    case 7:
	    	dezenas(string, "Setenta", "Septuagésim", u);
	    	break;
	    case 8:
	    	dezenas(string, "Oitenta", "Octagésim", u);
	    	break;
	    case 9:
	    	dezenas(string, "Noventa", "Nonagésim", u);
	    	break;
    }

    strcat(frase, string);
}

void escolheUnidade(int u)
{
    char string[20] = "";

    switch ( u )
    {
        case 1:
            if ( isCardinal )
                strcpy(string, ( isWoman ) ? "Uma " : "Um ");
            else
                strcpy(string, ( isWoman ) ? "Primeira" : "Primeiro");
            break;
        case 2:
            if ( isCardinal )
                strcpy(string, ( isWoman ) ? "Duas " : "Dois ");
            else
                strcpy(string, ( isWoman ) ? "Segunda" : "Segundo");
            break;
        case 3:
            unidades(string, "Três ", "Terceir");
            break;
        case 4:
            unidades(string, "Quatro ", "Quart");
            break;
        case 5:
            unidades(string, "Cinco ", "Quint");
            break;
        case 6:
            unidades(string, "Seis ", "Sext");
            break;
        case 7:
            unidades(string, "Sete ", "Sétim");
            break;
        case 8:
            unidades(string, "Oito ", "Oitav");
            break;
        case 9:
            unidades(string, "Nove ", "Non");
    }

    strcat(frase, string);
}

void numext(int number)
{
    int c = (int) number / 100;
    int d = (int) (number % 100) / 10;
    int u = (int) (number % 100) % 10;

    escolheCentena(c, d, u);
    escolheDezena(d, u);

    if ( d != 1 )
    {
        escolheUnidade(u);
    }
}

void calculaMilhoes(int number)
{
    char text[14] = "Milhonésim";

    int milhao = (int) number / 1000000;

    if ( milhao == 0 ) return;

    if ( milhao == 1 )
    {
        strcat(text, ( isWoman ) ? "a " : "o ");
        strcpy(frase, ( isCardinal ) ? "Um Milhão, " : text);

        return;
    }

    numext(milhao);

    strcat(text, ( isWoman ) ? "as " : "os ");
    strcat(frase, ( isCardinal ) ? "Milhões, " : text);
}

void calculaMilhares(int number)
{
    int mil = (int) (number % 1000000) / 1000;

    if ( mil == 0 ) return;

    if ( mil == 1 )
    {
        strcat(frase, "Mil ");

        return;
    }

    numext(mil);

    if ( isCardinal )
        strcat(frase, "Mil");
    else
        strcat(frase, ( isWoman ) ? "Milésimas" : "Milésimos");

    strcat(frase, ", ");
}

void calculaCentena(int number)
{
    int cent = (int) (number % 1000000) % 1000;

	if ( cent == 0 ) return;

    flag = true;
    numext(cent);
}

void numeroextenso(int number)
{
    calculaMilhoes(number);

    calculaMilhares(number);

    calculaCentena(number);
}

unsigned int getValue(void)
{
    unsigned int value = 0u;

	while ( value <= 0u or value > 999999999u )
    {
    	printf("\nDigite um valor entre 0 e 999.999.999\nOpção\? ");
	    scanf("%d", &value);
	}

    return value;
}

char getSex(void)
{
    char sex = '\0';

    printf("\n0. Feminino | 1. Masculino\nOpção\? ");
    scanf(" %c", &sex);

    return sex;
}

char getType(void)
{
    char type = '\0';

    printf("\n0. Ordinal  | 1. Cardinal\nOpção\? ");
    scanf(" %c", &type);

    return type;
}

/**
 *
 */
int main(int argc, const char* argv[])
{
    setlocale(LC_ALL, "");

    unsigned int value = getValue();

    char sex  = getSex();
    char type = getType();

    isWoman    = sex == '0';
    isCardinal = type == '1';

    numeroextenso(value);

    printf("\nValor por extenso:\n%s\n", frase);

    return EXIT_SUCCESS;
}