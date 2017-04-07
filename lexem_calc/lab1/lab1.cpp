// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "expression_calculator.h"

int _tmain(int argc, _TCHAR* argv[])
{

	//Тестовые данные.
	//char expr[100] = "3+5*(7-8/(16-156*(7+2)))-16-51*3";
    //char expr[100] = "3! + (7 - 4-1) * (23 + 5 + 8) + ln(2.71)";
    //char expr[100] = "3+5*(7-8/(16-156*tg(7+2)))-16-51*3";
	//char expr[100] = "34 + (7 - 4) * (23 + 5)";
	//char expr[100] = "3+10";


	char expr[100] = "3! + (7 - 4-1) * (x + 5 + 8) + ln(y)";

    if (argc>1)
    {
        std::cin>>expr;
    }
	
	Queue<char*> inq = initQueue<char*>();
	inq = parseExpression(expr);
	Queue<char*> inp = makeInvPN(inq);
	/*while(!isEmpty(inq))
	{
		char* val = 0;
		pop_s(inq,val);
		printf("OBR %s \n",val);
	}*/

	//Сформируем список переменных
	Queue<varPair*> vars = initQueue<varPair*>();
	varPair* a = new varPair();
	a->var='x';
	a->value=24;
	push(vars,a);
	a = new varPair();
	a->var='y';
	a->value=2.71f;
	push(vars,a);


	//float res = calculate2(inp);
	float res=0;
	if (calculate_var(inp,res,vars))
	{
		printf("OBR %f \n",res);
	}
	else
	{
		printf("Error. \n");
	}
	getch();
	return 0;
}

