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
	flag_vertex* p;		//массив вершин многоугольника
	int top, length;	//top-указатель на вершину стека, length-максимальный размер стека

public:
	Stack(int size);
	Stack();
	~Stack();
	Stack(const Stack &source);
	Stack& operator =(const Stack &source);
	void push(flag_vertex elem);	//положить элемент в стек
	flag_vertex pop();		//убрать верхний элемент стека
	flag_vertex peek();		//вернуть верхний элемент стека, но не доставать его
	int peek_top();			//вернуь указатель стека
};
