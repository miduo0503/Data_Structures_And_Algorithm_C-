#pragma warning(disable : 4996)
// test array stack

#include <iostream>
#include <string>
#include "arrayStack.h"
#include "myExceptions.h"

using namespace std;

int str2int(char s)
{
	int num = 0;
	stringstream ss(s);
	ss >> num;
	return num;
}

int main()
{
	//�������
	/*string str = "{[(a+b)*c]/g+(e+f)}";
	int len = str.length();
	arrayStack<char> s;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == '{' || str[i] == '[' || str[i] == '(')
			s.push(str[i]);
		switch (str[i])
		{
		case ')':
			cout << "�����ķ��ţ� " << s.top() << str[i] << endl;
			s.pop();
			break;
		case ']':
			cout << "�����ķ��ţ� " << s.top() << str[i] << endl;
			s.pop();
			break;
		case '}':
			cout << "�����ķ��ţ� " << s.top() << str[i] << endl;
			s.pop();
			break;

		default:
			break;
		}
	}*/

	//��׺���ʽ

	/*string str = "6523+8*+3+*";
	int len = str.length();
	arrayStack<int> s;
	int val1 = 0;
	int val2 = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] > '0' && str[i] < '9')
			s.push(str[i] - 48);
		if (str[i] < '0' || str[i] > '9')
		{
			val1 = s.top();
			s.pop();
			val2 = s.top();
			s.pop();
		}
		switch (str[i])
		{
		case '+':
			s.push(val1 + val2);
			break;
		case '-':
			s.push(val1 - val2);
			break;
		case '*':
			s.push(val1 * val2);
			break;
		case '/':
			s.push(val1 / val2);
			break;
		default:
			break;
		}
	}
	cout << s.top() << endl;*/

	//��׺���ʽת��׺���ʽ

	string str = "a-b-c";
	int len = str.length();
	arrayStack<char> s;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] >= 97 && str[i] <= 122)
			cout << str[i] << " ";
		switch (str[i])
		{
		case '+':
			if (!s.empty())
			{
				while (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-')
				{
					cout << s.top() << " ";
					s.pop();
					if (s.empty())
						break;
				}
			}
			s.push(str[i]);
			break;
		case '-':
			if (!s.empty())
			{
				while (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-')
				{
					cout << s.top() << " ";
					s.pop();
					if (s.empty())
						break;
				}
			}
			s.push(str[i]);
			break;
		case '*':
			if (!s.empty())
			{
				if (s.top() == '*' || s.top() == '/' )
				{
					cout << s.top() << " ";
					s.pop();
				}
			}
			s.push(str[i]);
			break;
		case '/':
			if (!s.empty())
			{
				if (s.top() == '*' || s.top() == '/')
				{
					cout << s.top() << " ";
					s.pop();
				}
			}
			s.push(str[i]);
			break;
		case '(':
			s.push(str[i]);
			break;
		case ')':
			while (s.top() != '(')
			{
				cout << s.top() << " ";
				s.pop();
			}
			break;
		default:
			break;
		}
	}
	while (!s.empty())
	{
		if (s.top() == '(')
			s.pop();
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}
