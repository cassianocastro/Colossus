#ifndef HOUSES_H

#define HOUSES_H

#include "./globals.h"

char* numext(uint value, char* response);

void setHouseOfCentenas(houses house, char* response);

void setHouseOfDezenas(houses house, char* response);

void setHouseOfUnidades(houses house, char* response);

void switchCentena(houses houseOf, char* text);

void switchDezena(houses houseOf, char* text);

void switchUnidade(houses houseOf, char* text);

void switchCase1(int u, char* text);

#endif