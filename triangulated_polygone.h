#pragma once
#include "polygone.h"
#include "stack.h"
#include "structs.h"



/*
triangulated_poly - класс, описывающий триангулируемый монотонный многоугольник
*/

class triangulated_poly :public polygone {
	
	int stack_length;	//величина стека
	/*
	point left_vertex - левая вершина многоугольника
	point right_vertex - правая вершина многоугольника
	*/
	point left_vertex;	//левая вершина многоугольника
	point right_vertex;	//правая вершина многоугольника
	diagonal* diagonals;	//проведённые в многоугольнике диагонали
	flag_vertex* x_vertexes; //отсортированные по х-координате вершины многоугольника
public:
	triangulated_poly(point* U_points, point* L_points, int UPPER_count, int LOWER_count);
	~triangulated_poly();
	triangulated_poly(const triangulated_poly &source);
	triangulated_poly& operator =(const triangulated_poly &source);


	void x_sort();	//сортировка вершин многоугольника по х-координате
	void triangulate();	//триангуляция многоугольника (требует предварительной сортировки вершин)
	void show_diagonals();	//процедура, выводящая на консоль все проведённые, в результате триангуляции диагонали
							//(альтернатива графическому представлению результата работы)
	
	void draw_polygone(string output); //создание изображения триангулированного многоугольника (string output - результирующий файл с расширением .jpg)
};
