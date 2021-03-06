#pragma once
#include "polygone.h"
#include "stack.h"
#include "structs.h"



/*
triangulated_poly - �����, ����������� ��������������� ���������� �������������
*/

class triangulated_poly :public polygone {
	Stack stack;
	int stack_length;
	/*
	point left_vertex - ����� ������� ��������������
	point right_vertex - ������ ������� ��������������
	*/
	point left_vertex;
	point right_vertex;
	diagonal* diagonals;	//���������� � �������������� ���������
	flag_vertex* x_vertexes; //��������������� �� �-���������� ������� ��������������
public:
	triangulated_poly(point* U_points, point* L_points, int UPPER_count, int LOWER_count);
	~triangulated_poly();


	void x_sort();	//���������� ������ �������������� �� �-����������
	void triangulate();	//������������ �������������� (������� ��������������� ���������� ������)
	void show_diagonals();	//���������, ��������� �� ������� ��� ����������, � ���������� ������������ ���������
							//(������������ ������������ ������������� ���������� ������)
	
	void draw_polygone(string output); //�������� ����������� ������������������ �������������� (string output - �������������� ���� � ����������� .jpg)
};