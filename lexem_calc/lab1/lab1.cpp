// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "expression_calculator.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//char expr[100] = "3+5*(7-8/(16-156*(7+2)))-16-51*3";
    char expr[100] = "34 + (7 - 4-1) * (23 + 5 + 8)";
    //char expr[100] = "3+5*(7-8/(16-156*tg(7+2)))-16-51*3";
	//char expr[100] = "34 + (7 - 4) * (23 + 5)";
	//char expr[100] = "3+10";
    if (argc>1)
    {
        std::cin>>expr;
    }
	
	Queue<char*> inq = initQueue<char*>();
	inq = parseExpression(expr);

	/*while(!isEmpty(inq))
	{
		char* val = 0;
		pop_s(inq,val);
		printf("OBR %s \n",val);
	}*/
	float res = calculate(inq);
	printf("OBR %f \n",res);
	getch();
	return 0;
}

