#include "../includes/Colossus.h"

bool isFemale = false, isCardinalNumber = false;

char* response = NULL;

const uint ONE_MILLION = 1000000;
const uint THOUSAND    = 1000;
const ushort HUNDRED   = 100;
const ushort TEN       = 10;

void startApp(void)
{
	print(getMenu());

	Inputs inputs    = getInputs();
	isFemale         = toupper(inputs.sex) == 'F';
    isCardinalNumber = toupper(inputs.type) == 'C';

    turnIntoExtensive(inputs.value);
    print(response);
}

void print(const char* content)
{
    printf("%s\n", content);
}

const char* getMenu(void)
{
	return "Hello..."
	"\n1. Digite um valor entre 0 e 999.999.999: "
	"\n2. Informe o sexo para fins de terminologia."
	"\n3. Escolha o tipo de numeração (Cardinal ou Ordinal)."
	"\n4. Obtenha o resultado :^D\n";
}

Inputs getInputs(void)
{
	Inputs inputs;

	do {
    	printf("Valor..............\? ");
	    scanf("%d", &inputs.value);
	} while ( not isValid(inputs.value) );

    printf("Sexo [M/F].........\? ");
    scanf(" %c", &inputs.sex);

    printf("Numeração [C/O]....\? ");
    scanf(" %c", &inputs.type);

	return inputs;
}

bool isValid(uint value)
{
	const uint MIN_VALUE = 0;
    const uint MAX_VALUE = 999999999;

	return value >= MIN_VALUE and value <= MAX_VALUE;
}

void turnIntoExtensive(uint number)
{
	writeMillions(number);
	writeThousands(number);
    writeHundreds(number);
}

void writeMillions(uint number)
{
    uint casa_milhoes = number / ONE_MILLION;

    if (casa_milhoes == 0) return;

    if (casa_milhoes > 1)
    {
        numext(casa_milhoes);
        strcat(response, (isCardinalNumber) ? "Milhões, " : appendCardinalSuffix("Milhonésim"));
        return;
    }
    strcpy(response, (isCardinalNumber) ? "Um Milhão, " : appendOrdinalSuffix("Milhonésim"));
}

void writeThousands(uint number)
{
    uint casa_milhares = ((number % ONE_MILLION) / THOUSAND);

    if (casa_milhares == 0) return;

    if (casa_milhares > 1)
    {
        numext(casa_milhares);

        if (isCardinalNumber)
            response = strcat(response, "Mil");
        else
            response = strcat(response, (isFemale) ? "Milésimas" : "Milésimos");

        response = strcat(response, ", ");
        return;
    }
    response = strcat(response, "Mil ");
}

void writeHundreds(uint number)
{
    uint hundreds = ((number % ONE_MILLION) % THOUSAND);

    if (hundreds not_eq 0)
    {
        numext(hundreds);
    }
}

void numext(uint number)
{
	uint d   = ((number % HUNDRED) / TEN);
	uint u   = ((number % HUNDRED) % TEN);

    response = strcat(response, switchC(number, d, u));
    response = strcat(response, switchD(d, u));

    if (d not_eq 1)
    {
        response = strcat(response, switchU(u));
    }
}

char* switchC(uint number, uint d, uint u)
{
    short c       = (short) number / HUNDRED;
    char* centena = NULL;

    if (isCardinalNumber)
    {
        centena = getCentenaCardinal(c - 1);
        centena = appendCardinalSuffix(centena);

        if ( d not_eq 0 )
        {
            centena = strcat(centena, "e ");
        }
    }
    else
    {
        centena = getCentenaOrdinal(c - 1);
        centena = appendOrdinalSuffix(centena);
    }
    /*
    switch (c)
	{
	    case 1:
	    	strcpy(centena, (d == 0 and u == 0) ? "Cem" : "Cento e ");

			if (not isCardinalNumber)
			{
				strcpy(centena, "Centésim");
				appendOrdinalSuffix(centena);
			}
    }
    */
    return centena;
}

char* switchD(short d, short u)
{
    if (d == 1)
    {
        return switchCase1(u);
    }

    char* palavra = NULL;

    if (isCardinalNumber)
    {
        palavra = getDezenaCardinal(d);

        if ( u not_eq 0 )
        {
            palavra = strcat(palavra, " e ");
        }
    }
    else
    {
        palavra = getDezenaOrdinal(d);
        palavra = appendOrdinalSuffix(palavra);
    }
    return palavra;
}

char* switchU(short u)
{
	switch (u)
	{
		case 1:
			if (isCardinalNumber)
				return (isFemale) ? "Uma " : "Um ";
			return (isFemale) ? "Primeira" : "Primeiro";
		case 2:
			if (isCardinalNumber)
				return (isFemale) ? "Duas " : "Dois ";
			return (isFemale) ? "Segunda" : "Segundo";
		case 3:
			return (isCardinalNumber) ? "Três "   : appendOrdinalSuffix("Terceir");
		case 4:
			return (isCardinalNumber) ? "Quatro " : appendOrdinalSuffix("Quart");
		case 5:
			return (isCardinalNumber) ? "Cinco "  : appendOrdinalSuffix("Quint");
		case 6:
			return (isCardinalNumber) ? "Seis "   : appendOrdinalSuffix("Sext");
		case 7:
			return (isCardinalNumber) ? "Sete "   : appendOrdinalSuffix("Sétim");
		case 8:
			return (isCardinalNumber) ? "Oito "   : appendOrdinalSuffix("Oitav");
		case 9:
			return (isCardinalNumber) ? "Nove "   : appendOrdinalSuffix("Non");
	}
}

char* switchCase1(short u)
{
	switch (u)
	{
		case 0:
			return (isCardinalNumber) ? "Dez "       : (isFemale) ? "Décima" : "Décimo";
		case 1:
			return (isCardinalNumber) ? "Onze "      : (isFemale) ? "Décima Primeira" : "Décimo Primeiro";
		case 2:
			return (isCardinalNumber) ? "Doze "      : (isFemale) ? "Décima Segunda" : "Décimo Segundo";
		case 3:
			return (isCardinalNumber) ? "Treze "     : (isFemale) ? "Décima Terceira" : "Décimo Terceiro";
		case 4:
			return (isCardinalNumber) ? "Catorze "   : (isFemale) ? "Décima Quarta" : "Décimo Quarto";
		case 5:
			return (isCardinalNumber) ? "Quinze "    : (isFemale) ? "Décima Quinta" : "Décimo Quinto";
		case 6:
			return (isCardinalNumber) ? "Dezesseis " : (isFemale) ? "Décima Sexta" : "Décimo Sexto";
		case 7:
			return (isCardinalNumber) ? "Dezesete "  : (isFemale) ? "Décima Sétima" : "Décimo Sétimo";
		case 8:
			return (isCardinalNumber) ? "Dezoito "   : (isFemale) ? "Décima Oitava" : "Décimo Oitavo";
		case 9:
			return (isCardinalNumber) ? "Dezenove "  : (isFemale) ? "Décima Nona" : "Décimo Nono";
	}
}

char* getCentenaCardinal(uint value)
{
    char representations[9][20] = {
        "Cem"       , "Duzent"  , "Trezent",
        "Quatrocent", "Quinhent", "Seiscent",
        "Setecent"  , "Oitocent",  "Novecent"
    };

    char* word = representations[value];
    return word;
}

char* getCentenaOrdinal(uint value)
{
    char representations[9][20] = {
        "Centésim"      , "Ducentésim"  , "Tricentésim",
        "Quadrigentésim", "Quingentésim", "Seiscentésim",
        "Septigentésim" , "Octigentésim", "Nongentésim"
    };

    char* word = representations[value];
    return word;
}

char* getDezenaCardinal(uint value)
{
    char representations[9][20] = {
        "Vinte"    , "Trinta"  , "Quarenta",
        "Cinquenta", "Sessenta", "Setenta",
        "Oitenta"  , "Noventa"
    };

    char* word = representations[value];
    return word;
}

char* getDezenaOrdinal(uint value)
{
    char representations[9][20] = {
        "Vigésim"     , "Trigésim" , "Quadragésim",
        "Quinquagésim", "Sexagésim", "Septuagésim",
        "Octagésim"   , "Nonagésim"
    };

    char* word = representations[value];
    return word;
}

char* appendCardinalSuffix(char* word)
{
	word = strcat(word, (isFemale) ? "as " : "os ");
    return word;
}

char* appendOrdinalSuffix(char* word)
{
	word = strcat(word, (isFemale) ? "a " : "o ");
    return word;
}