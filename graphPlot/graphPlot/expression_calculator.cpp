#include "expression_calculator.h"

void processLexem(char* subs,Queue<char*>& res,Stack<char*>& slaveS)
{
	//По пунктам с алгоритма на почте. 
	if ((isOperand(subs))||(isVariable(subs)))
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
	return 0;
}

float processFunction(char* lexem, float a)
{
	if (strcmp(lexem,"sin")==0)
		return (float)(sin(a));
	if (strcmp(lexem,"tg")==0)
		return (float)(tan(a));
	if (strcmp(lexem,"ctg")==0)
		return (float)(1/tan(a));
	if (strcmp(lexem,"atan")==0)
		return (float)(atan(a));
	if (strcmp(lexem,"sqrt")==0)
		return (float)(sqrt(a));
	if (strcmp(lexem,"ln")==0)
		return (float)(log(a));
	if (strcmp(lexem,"log")==0)
		return (float)(log10(a));
	if (strcmp(lexem,"cos")==0)
		return (float)(cos(a));
	return 0;
}

float processOperator(char* op, float a)
{
	if (*op == '!')
		return (float)(fac((int)floor(a)));
	return 0;
}

int fac(int x)
{
	static const int table[] = {
		1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600,
	};
	if (x > 12)
		return 0;
	return table[x];
}

int getOperatorType(char* op)
{
	if ((*op=='+')||(*op=='-')||(*op=='*')||(*op=='\\')||(*op=='/'))
		return BINARY;
	if (*op == '!')
		return UNARY;
	return UNKNOWN;
}

float getVariableValue(char str,Queue<varPair*> vars)
{
	Node<varPair*> *var = vars.start;
	while (!isEmpty(vars)) 
	{
		if (var->value->var==str)
			return var->value->value;
		var=var->next;
	}
	return 0;
}

bool calculate_var(Queue<char*> &q, float &res, Queue<varPair*> &vps)
{
	Queue<char*> vars = getVariables(q);
	Node<char*> *var = vars.start;

	while (var!=NULL) 
	{
		Node<char*> *el = q.start;
		bool found=false;
		//Найдём Node переменной node
		while ((el!=NULL)&&(!found))
		{
			if (el->value==var->value) // Нашли
			{
				char* varname;
				var=var->next;
				pop_s(vars,varname);
				float varValue = getVariableValue(*varname,vps); //Выделим значение переменной из vps.
				sprintf(el->value,"%f",varValue);//Заменим в q на то что в vps
				found=true;
				continue;
			}
			el=el->next;
		}
		//Не нашли. 
		if (!found)
			return false;
	}
	if (isEmpty(vars))
	{
		res = calculate2(q);
		return true;
	}
	return false;
}

//Вычислить значение выражения по обратной польской записи. 
float calculate2(Queue<char*> &q)
{
	char* str=0;
	Node<char*>* opstr[3]={NULL,NULL,NULL};
	Stack<float> temp_f_q =  initStack<float>();
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
			
			switch (getOperatorType(str))
			{
			case BINARY:
				pop_s(temp_f_q, a);
				pop_s(temp_f_q, b);
				res = processOperator(str,b,a);
				push(temp_f_q, res);
				break;
			case UNARY:
				pop_s(temp_f_q, a);
				res = processOperator(str, a);
				push(temp_f_q, res);
				break;
			default:
				break;
			}
		}
		if (isFunction(str))
		{
			pop_s(temp_f_q, a);
			res = processFunction(str,a);
			push(temp_f_q, res);
		}
	}
	pop_s(temp_f_q, a);
    return a;
}

Queue<char*> getVariables(Queue<char*> q)
{
	Queue<char*> temp_v_q =  initQueue<char*>();
	Node<char*> *el = q.start;
	while (el)
	{
		if (isVariable(el->value))
		{
			push(temp_v_q,el->value);
		}
		el=el->next;
	}
	return temp_v_q;
}

float calculate(Queue<char*> &q)
{
	char* str = 0;
	Node<char*>* opstr[3] = { NULL, NULL, NULL };

	while (q.end != NULL)
	{
		char* res;
		Node<char*>* opstr[3] = { NULL, NULL, NULL };
		opstr[0] = q.start; //34
		while ((!isOperator(opstr[0]->value) && !isFunction(opstr[0]->value)))//&&(opstr[0]!=q.end))
		{
			opstr[2] = opstr[1];
			opstr[1] = opstr[0];
			opstr[0] = opstr[0]->next;
			if (!opstr[2] && opstr[1] && !opstr[0])
			{
				return (float)atof(opstr[1]->value);  //Выход из функции здесь.
			}
		}
		if (isOperator(opstr[0]->value))
		{
			switch (getOperatorType(opstr[0]->value))
			{
			case BINARY:
				res = processOperator_c(opstr[0]->value, atof(opstr[1]->value), (float)atof(opstr[2]->value));
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