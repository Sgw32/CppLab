#ifndef EXPRESSION_CALCULATOR_H
#define EXPRESSION_CALCULATOR_H

#include "stdafx.h"

enum 
{ 
	UNKNOWN,
	BINARY, 
	UNARY
};

Queue<char*> parseExpression(char* exps);
Queue<char*> makeInvPN(Queue<char*> q);
void processLexem(char* str,Queue<char*>& res,Stack<char*>& slaveS);
//Queue<char*> parseExpression2(char* exps);
float calculate(Queue<char*> &q);
float calculate2(Queue<char*> &q);
char* processOperator_c(char* op,float a,float b);
float processOperator(char* op, float a);
float processOperator(char* op, float a, float b);
int getOperatorType(char* op);
#endif