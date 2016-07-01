//============================================================================
// Author      : pep
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "select.h"

int main() {
	Select s;
	int a[]={0,4,2,6,8,1,7};
	s.heap_sort(a,6);
	s.print(a,7);
	return 0;
}
