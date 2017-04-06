#ifndef EXPRESSION_CALCULATOR_H
#define EXPRESSION_CALCULATOR_H

#include "stdafx.h"

enum 
{ 
	UNKNOWN,
	BINARY, 
	UNARY
};

struct varPair
{
	char var;
	float value;
};

Queue<char*> parseExpression(char* exps);
Queue<char*> makeInvPN(Queue<char*> q);
void processLexem(char* str,Queue<char*>& res,Stack<char*>& slaveS);
//Queue<char*> parseExpression2(char* exps);
float calculate(Queue<char*> &q);
float calculate2(Queue<char*> &q);
bool calculate_var(Queue<char*> &q, float &res, Queue<varPair> &vars);
char* processOperator_c(char* op,float a,float b);
float processOperator(char* op, float a);
float processOperator(char* op, float a, float b);
int getOperatorType(char* op);

//int32_t
int fac(int x);
#endif