#pragma once
#include "polygone.h"
#include "stack.h"
#include "structs.h"



/*
triangulated_poly - класс, описывающий триангулируемый монотонный многоугольник
*/

class triangulated_poly :public polygone {
	Stack stack;
	int stack_length;
	/*
	point left_vertex - лева€ вершина многоугольника
	point right_vertex - права€ вершина многоугольника
	*/
	point left_vertex;
	point right_vertex;
	diagonal* diagonals;	//проведЄнные в многоугольнике диагонали
	flag_vertex* x_vertexes; //отсортированные по х-координате вершины многоугольника
public:
	triangulated_poly(point* U_points, point* L_points, int UPPER_count, int LOWER_count);
	~triangulated_poly();


	void x_sort();	//сортировка вершин многоугольника по х-координате
	void triangulate();	//триангул€ци€ многоугольника (требует предварительной сортировки вершин)
	void show_diagonals();	//процедура, вывод€ща€ на консоль все проведЄнные, в результате триангул€ции диагонали
							//(альтернатива графическому представлению результата работы)
	
	void draw_polygone(string output); //создание изображени€ триангулированного многоугольника (string output - результирующий файл с расширением .jpg)
};