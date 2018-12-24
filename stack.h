#pragma once
#include "iostream"
#include "structs.h"


/*
Реализация стека.
В нём будут храниться вершины, к которым потенциально 
можно провести диагональ из текущей вершины.
*/

class Stack
{
private:
	flag_vertex* p;
	int top, length;

public:
	Stack(int size);
	Stack();
	void push(flag_vertex elem);
	flag_vertex pop();
	flag_vertex peek();
	int peek_top();
};