#include <stdbool.h>

#ifndef COLOSSUS_H
#define COLOSSUS_H

#define MAX_SIZE_RESPONSE 200

typedef unsigned int uint;

typedef unsigned short ushort;

typedef unsigned char byte;

typedef struct
{
	uint value;
	byte sex;
	byte type;
} Inputs;

bool isFemale, isCardinalNumber;
char* response = NULL;

void startApp(void);

void print(const char* content);

const char* getMenu(void);

Inputs getInputs(void);

bool isValid(uint value);

void turnIntoExtensive(uint number);


void writeMillions(uint number);

void writeThousands(uint number);

void writeHundreds(uint number);

void numext(uint number);


char* switchC(uint number, uint d, uint u);

char* switchD(short d, short u);

char* switchU(short u);

char* switchCase1(short u);


bool isOrdinal();

char* appendOrdinalSuffix(char* word);

char* appendCardinalSuffix(char* word);



char* getCentenaOrdinal(uint value);

char* getCentenaCardinal(uint value);

char* getDezenaOrdinal(uint value);

char* getDezenaOrdinal(uint value);



char* centenas(char* palavra, char* palavra2, short d);

char* dezenas(char* palavra, char* palavra2, short u);

#endif