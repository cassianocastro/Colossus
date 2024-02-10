#ifndef COLOSSUS_H

#define COLOSSUS_H

#include <ctype.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_RESPONSE 200

typedef unsigned int uint;

typedef unsigned short ushort;

typedef unsigned char byte;

/**
 *
 */
typedef struct
{
	uint value;
	byte sex;
	byte type;
} Inputs;

bool isFemale, isCardinalNumber;

char* response = NULL;

/**
 *
 */
void startApp(void);

/**
 *
 */
void print(const char*);

/**
 *
 */
const char* getMenu(void);

/**
 *
 */
Inputs getInputs(void);

/**
 *
 */
bool isValid(uint);

/**
 *
 */
void turnIntoExtensive(uint);

/**
 *
 */
void writeMillions(uint);

/**
 *
 */
void writeThousands(uint);

/**
 *
 */
void writeHundreds(uint);

/**
 *
 */
void numext(uint);

/**
 *
 */
char* switchC(uint, uint, uint);

/**
 *
 */
char* switchD(short, short);

/**
 *
 */
char* switchU(short);

/**
 *
 */
char* switchCase1(short);

/**
 *
 */
bool isOrdinal();

/**
 *
 */
char* appendOrdinalSuffix(char*);

/**
 *
 */
char* appendCardinalSuffix(char*);

/**
 *
 */
char* getCentenaOrdinal(uint);

/**
 *
 */
char* getCentenaCardinal(uint);

/**
 *
 */
char* getDezenaOrdinal(uint);

/**
 *
 */
char* getDezenaOrdinal(uint);

/**
 *
 */
char* centenas(char*, char*, short);

/**
 *
 */
char* dezenas(char*, char*, short);

#endif