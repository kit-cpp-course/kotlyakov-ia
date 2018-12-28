#include "stack.h"
#include "triangulated_polygone.h"
#include "structs.h"

using namespace std;

Stack::Stack(int size)
{
	top = -1;
	length = size;
	p = new flag_vertex[length];
}

Stack::Stack() 
{
	top = -1;
	length = 1;
	p = new flag_vertex[1];
}


void Stack::push(flag_vertex elem)
{	
		top++;
		p[top] = elem;	
}
flag_vertex Stack::pop()
{
	if (top == -1)
	{
		cout << "Stack empty!";
		return flag_vertex(point(NAN,NAN),false);
	}
	flag_vertex ret = p[top];
	top--;
	return ret;
}

flag_vertex Stack::peek()
{
	return p[top];
}

int Stack::peek_top() {
	return top;
}
