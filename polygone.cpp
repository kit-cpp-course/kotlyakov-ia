#include "polygone.h"
#include "structs.h"


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
	for (int i = 0; i < UPPER_count; i++) {
		LOWER[i] = L_points[i];
	}
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
