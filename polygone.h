#pragma once
#include <string>
#include "iostream"
#include "structs.h"

using namespace std;
	
/*
Класс, описыващий монотонный полигон
point* UPPER массив вершин, принадлежащих верхней монотонной цепочке
point* LOWER массив вершин, принадлежащих нижней монотонной цепочке
*/
	class polygone {
	protected:
		point* UPPER;
		int UPPER_count;
		point* LOWER;
		int LOWER_count;	

	public:

		polygone(int UPPER_count, int LOWER_count);
		polygone(point* U_points, point* L_points, int UPPER_count, int LOWER_count);
		~polygone();
		
		/*
		Процедура, выводящая на экран вершины по цепочкам (сначала верхняя цепочка, потом нижняя)
		*/
		void show();
	};
