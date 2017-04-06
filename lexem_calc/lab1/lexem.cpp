#include "lexem.h"

bool isFunction(char* lexem)
{
	//char lexem[200];
	//strcpy (lexem,lexe);
	//bool res = ((lexem==(char*)"sin")||(lexem==(char*)"cos")||(lexem==(char*)"tg")||(lexem==(char*)"ctg")||(lexem==(char*)"atan")||
	//	(lexem==(char*)"atan2")||(lexem==(char*)"sqrt")||(lexem==(char*)"atan2")||(lexem==(char*)"ln")||(lexem==(char*)"log"));
	bool res = (strcmp(lexem,"sin")==0)||
		(strcmp(lexem,"sin")==0)||
		(strcmp(lexem,"tg")==0)||
		(strcmp(lexem,"ctg")==0)||
		(strcmp(lexem,"atan")==0)||
		(strcmp(lexem,"atan2")==0)||
		(strcmp(lexem,"sqrt")==0)||
		(strcmp(lexem,"ln")==0)||
		(strcmp(lexem,"log")==0)||
		(strcmp(lexem,"cos")==0);
	return res;
}

int getOperatorPriority(char* lexem)
{
	if (*lexem == '!')
		return 6;
	if (*lexem=='^')
		return 5;
	if (*lexem=='*')
		return 4;
	if ((*lexem=='\\')||(*lexem=='/'))
		return 3;
	if (*lexem=='+')
		return 2;
	if (*lexem=='-')
		return 1;
	return 0;
}

bool isOpeningBracket(char* lexem)
{
	bool res = (*lexem=='(')&&(getSingleSize(lexem));
	return res;
}

bool isClosingBracket(char* lexem)
{
	bool res = (*lexem==')')&&(getSingleSize(lexem));
	return res;
}

bool getSingleSize(char* lexem)
{
	if (lexem[1]!='\0')
		return false;
	return true;
}

bool isVariable(char* lexem)
{
	if (!getSingleSize(lexem))
		return false;
	//return (lexem[0]>='a')&&(lexem[0]<='z');
	return (lexem[0]>='x')&&(lexem[0]<='z');
}

bool isOperand(char* lexem)
{
	do
	{
		   if (!(isdigit(*lexem)||(*lexem=='.')))
		   {
			   return false;
		   }
		   lexem++;
	}
	while(*lexem);
	return true;
}

bool isOperator(char* lexem)
{
	bool res = ((*lexem == '!') || (*lexem == '-') || (*lexem == '+') || (*lexem == '*') || (*lexem == '^') || (*lexem == '\\') || (*lexem == '/')) && (getSingleSize(lexem));
	return res;
}