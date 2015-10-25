#include<iostream>
#include"Vector.h"

using namespace std;

int main()
{
	Vector<int> ivec(5);
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);
	ivec.push_back(4);
	ivec.push_back(5);
	/*ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);
	ivec.push_back(4);
	ivec.push_back(5);*/
	cout << ivec.size() << endl;
	cout << ivec << endl;
	cout << *ivec.begin() << endl;
	cout << *ivec.end() << endl;
	return 0;
}