#include "stack112.h"

void main()
{
	stack112 s(10);
	s.push(5);
	s.push(5);
	s.push(5);
	s.push(5);
	s.top();
	s.top() = 6;
	s.print();
	stack112 s1(s);
	cout << endl;
	s1.print();
}
