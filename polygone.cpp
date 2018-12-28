#include "polygone.h"
#include "structs.h"

polygone::polygone() {
	UPPER = new point;
	LOWER = new point;
	UPPER_count = 0;
	LOWER_count = 0;
}

polygone::polygone(int UPPER_count, int LOWER_count) :  UPPER_count(UPPER_count), LOWER_count(LOWER_count) {
	UPPER = new point[UPPER_count];
	LOWER = new point[LOWER_count];
}

polygone::polygone(point* U_points, point* L_points, int UPPER_count, int LOWER_count) : UPPER_count(UPPER_count), LOWER_count(LOWER_count) {
	UPPER = new point[UPPER_count];
	LOWER = new point[LOWER_count];
	for (int i = 0; i < UPPER_count; i++) {
		UPPER[i]= U_points[i];
	}
	for (int i = 0; i < LOWER_count; i++) {
		LOWER[i] = L_points[i];
	}
}

polygone::polygone(const polygone &source) {
	UPPER=new point[source.UPPER_count];	
	LOWER=new point[source.LOWER_count];
}

polygone& polygone::operator =(const polygone &source) {
	if (this == &source) return *this;  //  проверка на самоприсваивание	
	
	delete[] UPPER, LOWER;
	UPPER_count = source.UPPER_count;
	LOWER_count = source.LOWER_count;
	UPPER = new point[UPPER_count];
	LOWER = new point[LOWER_count];
	for (int i = 0; i < UPPER_count; i++)
	{
		UPPER[i] = source.UPPER[i];
	}
	for (int i = 0; i < LOWER_count; i++)
	{
		LOWER[i] = source.LOWER[i];
	}

	return *this;
}

polygone::~polygone() {
	delete[] UPPER;
	delete[] LOWER;
}

void polygone::show() {
	for (int i = 0; i < UPPER_count; i++) {
		cout << "("<<UPPER[i].x<<"; "<< UPPER[i].y<<")  ";
	}
	cout << endl;
	for (int i = 0; i < LOWER_count; i++) {
		cout << "(" << LOWER[i].x << "; " << LOWER[i].y << ")  ";
	}
	cout << endl;
}
