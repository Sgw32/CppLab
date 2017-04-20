#ifndef LEXEM_H
#define LEXEM_H
#include "stdafx.h"

bool isOperand(char* lexem); //1234567890
bool isOperator(char* lexem); //+-*/
bool isFunction(char* lexem); //tg ctg atan atan2 sin cos sqrt ln log
bool isOpeningBracket(char* lexem);	//(
bool isClosingBracket(char* lexem);	//)
bool isVariable(char* lexem); //вся латиница
int getOperatorPriority(char* lexem); //???
bool getSingleSize(char* lexem);

#endif