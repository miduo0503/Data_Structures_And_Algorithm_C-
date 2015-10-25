#ifndef changeLength1D_
#define changeLength1D_

#include"myExceptions.h"
#include<algorithm>
using namespace std;
template<class T>
void changeLength1D(T* &a, int oldLength, int newLength)
{
	if (newLength < 0)
		throw illegalParameterValue("newLength must be > 0");
	T* temp = new T[newLength];
	int num = min(oldLength, newLength);
	copy(a, a + num, temp);
	delete [] a;
	a = temp;
}

#endif 