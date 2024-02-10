#include "./includes/view.h"

//extern bool isMulher, isOrdinal;

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