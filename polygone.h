#pragma once
#include <string>
#include "iostream"
#include "structs.h"

using namespace std;
	
/*
�����, ���������� ���������� �������
point* UPPER ������ ������, ������������� ������� ���������� �������
point* LOWER ������ ������, ������������� ������ ���������� �������
*/
	class polygone {
	protected:
		point* UPPER;
		int UPPER_count;
		point* LOWER;
		int LOWER_count;	

	public:
		polygone();
		polygone(int UPPER_count, int LOWER_count);
		polygone(point* U_points, point* L_points, int UPPER_count, int LOWER_count);
		~polygone();
		polygone(const polygone &source);
		polygone& operator =(const polygone &source);

		/*
		���������, ��������� �� ����� ������� �� �������� (������� ������� �������, ����� ������)
		*/
		void show();
	};
