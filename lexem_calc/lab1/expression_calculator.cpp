#include "expression_calculator.h"

void processLexem(char* subs,Queue<char*>& res,Stack<char*>& slaveS)
{
	//По пунктам с алгоритма на почте. 
	if (isOperand(subs))
	{
		push(res,subs);
		printf("OP %s \n",subs);
	}
	else if (isFunction(subs))
	{
		push(slaveS,subs);
	}
	else if (isOperator(subs))
	{
		Node<char*>* st = slaveS.top;
		if ((st)&&(getOperatorPriority(subs)<=getOperatorPriority(st->value))&&
			(!isOpeningBracket(st->value)))
		{
			while((!isEmpty(slaveS))&&((getOperatorPriority(subs)<=getOperatorPriority(st->value))||(!isOpeningBracket(st->value))))
			{
				char* str=0;
				push(res,st->value);
				printf("OP %s \n",st->value);
				pop_s(slaveS,str);
				st = slaveS.top;
			}
			push(slaveS,subs);
		}
		else
		{
			push(slaveS,subs);
		}
	}
	else if (isOpeningBracket(subs))
	{
		push(slaveS,subs);
	}
	else if (isClosingBracket(subs))
	{
		char* str=0;
		//Node<char*>* st = slaveS.top;
        pop_s(slaveS,str);
        //str = st->value;
		while((!isEmpty(slaveS))&&(!isOpeningBracket(str)))
		{
			push(res,str);
			printf("OP %s \n",str);
			pop_s(slaveS,str);
		}
		if ((!isEmpty(slaveS))&&(isFunction(str)))
		{
			push(res,str);
			printf("OP %s \n",str);
            pop_s(slaveS,str);
		}
	}
}

Queue<char*> parseExpression(char* exps)
{
	int i,curi;
	i=curi=0;
	Queue<char*> res = initQueue<char*>();
	//Stack<char*> slaveS = initStack<char*>();


	while (curi!=strlen(exps))
	{
		if (exps[curi]==' ')
		{
			curi++;
			continue;
		}
		for (i=strlen(exps);i!=curi;i--)
		{
			char* subs = new char[50];
			memcpy(subs,&exps[curi],i-curi);
			subs[i-curi]='\0';
			if (isOperand(subs)||isOperator(subs)||isFunction(subs)
				||isOpeningBracket(subs)||isClosingBracket(subs)||isVariable(subs))
			{
				push(res,subs);
				printf("printf %s \n",subs);
				//Формирование обратной польской записи
				//processLexem(subs,res,slaveS);
				curi=i;
				break;
			}
			else 
			{
				if ((i-curi)==1)
				{
					break;
				}
			}
		}
	}
	/*while (!isEmpty(slaveS))
	{
		char* str = 0;
		Node<char*>* st = slaveS.top;
		push(res, st->value);
		printf("OP %s \n", st->value);
		pop_s(slaveS, str);
	}*/
	return res;
}

Queue<char*> makeInvPN(Queue<char*> q)
{
	Queue<char*> res = initQueue<char*>();
	Stack<char*> slaveS = initStack<char*>();

	while (!isEmpty(q))
	{
		char* str = new char[50];
		pop_s(q, str);
		processLexem(str, res, slaveS);
	}

	//Формирование обратной польской записи. Перенос стека.
	while (!isEmpty(slaveS))
	{
		char* str = 0;
		Node<char*>* st = slaveS.top;
		push(res, st->value);
		printf("OP %s \n", st->value);
		pop_s(slaveS, str);
	}
	return res;
}

char* processOperator_c(char* op,float a,float b)
{
	char* ans = new char[20];
	if (*op=='+')
		sprintf(ans, "%f", (float)(a+b));
	if (*op=='-')
		sprintf(ans, "%f", (float)(b-a));
	if (*op=='*')
		sprintf(ans, "%f", (float)(a*b));
	if ((*op=='/')||(*op=='\\'))
		sprintf(ans, "%f", (float)(b/a));
	if (*op=='^')
		sprintf(ans, "%f", (float)(pow(b,a)));
    return ans;
}

float processOperator(char* op, float a, float b)
{
	float ans;
	if (*op == '+')
		return (float)(a + b);
	if (*op == '-')
		return (float)(a - b);
	if (*op == '*')
		return (float)(a*b);
	if ((*op == '/') || (*op == '\\'))
		return (float)(b / a);
	if (*op == '^')
		return (float)(pow(b, a));
	return ans;
}

float processOperator(char* op, float a)
{
	return 0;
}


int getOperatorType(char* op)
{
	if ((*op=='+')||(*op=='-')||(*op=='*')||(*op=='\\')||(*op=='/'))
		return BINARY;
	//if (op=="+")
	//	return BINARY;
	return UNKNOWN;
}

//Вычислить значение выражения по обратной польской записи. 
float calculate2(Queue<char*> &q)
{
	char* str=0;
	Node<char*>* opstr[3]={NULL,NULL,NULL};
	Queue<float> temp_f_q;
	float res, a, b;

	while(!isEmpty(q))
	{
		char* str = new char[50];
		pop_s(q, str);
		if (isOperand(str))
		{
			push(temp_f_q, (float)atof(str));
		}
		if (isOperator(str))
		{
			pop_s(temp_f_q, a);
			pop_s(temp_f_q, b);
			switch (getOperatorType(str))
			{
			case BINARY:
				res = processOperator(str,a,b);
				push(temp_f_q, res);
				break;
			case UNARY:
				res = processOperator(str, a);
				push(temp_f_q, res);
				// Какие есть примеры унарных операторов?
				break;
			default:
				break;
			}
		}
		if (isFunction(str))
		{

		}
	}
	pop_s(temp_f_q, a);
    return a;
}

float calculate(Queue<char*> &q)
{
	char* str = 0;
	Node<char*>* opstr[3] = { NULL, NULL, NULL };

	while (q.end != NULL)
	{
		char* res;
		char* temp;
		Node<char*>* opstr[3] = { NULL, NULL, NULL };
		opstr[0] = q.start; //34
		while ((!isOperator(opstr[0]->value) && !isFunction(opstr[0]->value)))//&&(opstr[0]!=q.end))
		{
			opstr[2] = opstr[1];
			opstr[1] = opstr[0];
			opstr[0] = opstr[0]->next;
			if (!opstr[2] && opstr[1] && !opstr[0])
			{
				return atof(opstr[1]->value);  //Выход из функции здесь.
			}
		}
		if (isOperator(opstr[0]->value))
		{
			switch (getOperatorType(opstr[0]->value))
			{
			case BINARY:
				res = processOperator_c(opstr[0]->value, atof(opstr[1]->value), atof(opstr[2]->value));
				opstr[2]->value = res;
				opstr[2]->next = opstr[0]->next;
				opstr[1]->next = NULL;
				opstr[0]->next = NULL;
				delete opstr[1];
				delete opstr[0];
				break;
			case UNARY:
				// Какие есть примеры унарных операторов?
				break;
			default:
				break;
			}
		}
		else if (isFunction(opstr[0]->value))
		{
			//Пока что нет обработки функций.
		}
	}
	return 0;
}