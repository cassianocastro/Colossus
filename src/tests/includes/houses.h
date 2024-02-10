#ifndef HOUSES_H

#define HOUSES_H

#include "./globals.h"

/**
 *
 */
char* numext(uint, char*);

/**
 *
 */
void setHouseOfCentenas(houses, char*);

/**
 *
 */
void setHouseOfDezenas(houses, char*);

/**
 *
 */
void setHouseOfUnidades(houses, char*);

/**
 *
 */
void switchCentena(houses, char*);

/**
 *
 */
void switchDezena(houses, char*);

/**
 *
 */
void switchUnidade(houses, char*);

/**
 *
 */
void switchCase1(int, char*);

#endif