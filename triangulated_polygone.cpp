#include "triangulated_polygone.h"
#include "polygone.h"
#include "stack.h"
#include "structs.h"
#include "opencv2/opencv.hpp"

using namespace cv;

triangulated_poly::triangulated_poly(point* U_points, point* L_points, int UPPER_count, int LOWER_count) :polygone(U_points, L_points, UPPER_count, LOWER_count) {
	stack_length = UPPER_count + LOWER_count - 2;
	stack=Stack(stack_length);
	left_vertex = UPPER[0];
	right_vertex = UPPER[UPPER_count-1];
	diagonals =new diagonal[stack_length*2];	
	x_vertexes = new flag_vertex[stack_length];
	x_sort();
}

triangulated_poly::~triangulated_poly() {			
		delete[] diagonals;
		delete[] x_vertexes;
}

void triangulated_poly::x_sort() {
	x_vertexes[0] = flag_vertex(left_vertex, true);
	x_vertexes[stack_length-1] = flag_vertex(right_vertex, true);
	int k = 1;
	int i = 1;
	int j = 1;
	while (k < stack_length - 1) {
		if (UPPER[i].x <= LOWER[j].x) {
			x_vertexes[k] = flag_vertex(UPPER[i], true);
			k++;
			i++;
		}
		else {
			x_vertexes[k] = flag_vertex(LOWER[j], false);
			k++;
			j++;
		}				
	}
	/*for (int i = 0; i < stack_length; i++) {
		cout << "(" << x_vertexes[i].a.x << "; " << x_vertexes[i].a.y << "; " << x_vertexes[i].up << ")  " << endl;;
	}
	cout << endl;*/
}

void triangulated_poly::triangulate() {
	stack.push(x_vertexes[0]);
	stack.push(x_vertexes[1]);
	int di_count = 0;
	flag_vertex just_popped;
	for (int i = 2; i < stack_length; i++) {
		if (x_vertexes[i].up == stack.peek().up) {
			diagonals[di_count] = diagonal(x_vertexes[i].a, stack.peek().a);
			just_popped = stack.peek();
			stack.pop();
			if (x_vertexes[i].up == false) {
				while (stack.peek_top() >= 0) {
					if ((stack.peek().a.x - diagonals[di_count].a.x)*(diagonals[di_count].b.y - diagonals[di_count].a.y) - (stack.peek().a.y - diagonals[di_count].a.y)*(diagonals[di_count].b.x - diagonals[di_count].a.x) > 0) {
						di_count++;
						diagonals[di_count] = diagonal(x_vertexes[i].a, stack.peek().a);
						just_popped = stack.peek();
						stack.pop();
					}
					else {
						stack.push(just_popped);
						stack.push(x_vertexes[i]);
						di_count++;
						break;
					}
				}
				stack.push(just_popped);
				stack.push(x_vertexes[i]);
				di_count++;
				
			}
			else {
				while (stack.peek_top() >= 0) {
					if ((stack.peek().a.x - diagonals[di_count].a.x)*(diagonals[di_count].b.y - diagonals[di_count].a.y) - (stack.peek().a.y - diagonals[di_count].a.y)*(diagonals[di_count].b.x - diagonals[di_count].a.x) < 0) {
						di_count++;
						diagonals[di_count] = diagonal(x_vertexes[i].a, stack.peek().a);
						just_popped = stack.peek();
						stack.pop();
					}
					else {
						stack.push(just_popped);
						stack.push(x_vertexes[i]);
						break;
					}
				}
				stack.push(just_popped);
				stack.push(x_vertexes[i]);		
				di_count++;
			}
		}
		else {
			just_popped = stack.peek();
			while (stack.peek_top() >= 0) {
				diagonals[di_count] = diagonal(x_vertexes[i].a, stack.peek().a);
				di_count++;
				stack.pop();
			}
			stack.push(just_popped);
			stack.push(x_vertexes[i]);
		}
	}
	diagonals[di_count] = diagonal(point(NAN, NAN), point(NAN, NAN));
}

void triangulated_poly::show_diagonals() {
	int k = 0;
	while (!isnan(diagonals[k].a.x)) {
		cout << "(" << diagonals[k].a.x << "; " << diagonals[k].a.y << ")  "<< "(" << diagonals[k].b.x << "; " << diagonals[k].b.y << ")  "<<endl;
		k++;
	}
}

void triangulated_poly::draw_polygone(string output) {
	
	int x_diff = right_vertex.x - left_vertex.x;
	int y_min = x_vertexes[0].a.y;
	int y_max = x_vertexes[0].a.y;
	
	for (int i = 1; i < stack_length;i++) {
		if (x_vertexes[i].a.y > y_max) y_max = x_vertexes[i].a.y;
		if (x_vertexes[i].a.y < y_min) y_min = x_vertexes[i].a.y;
	}
	//cout << y_max - y_min << "\ " << x_diff << endl;
	Mat img(800*(y_max-y_min)/x_diff,800, CV_8UC3, Scalar::all(255));
	int scale=800 / (x_diff);	
	Point center = Point(scale*(abs(left_vertex.x)), scale*(abs(y_max)));
	int k = 0;
	while (!isnan(diagonals[k].a.x)) {
		line(img, Point(center.x + scale*diagonals[k].b.x, center.y - scale*diagonals[k].b.y),
			Point(center.x + scale*diagonals[k].a.x, center.y - scale*diagonals[k].a.y),
			Scalar(0, 0, 255), 2);
		k++;
	}
	for (int i = 1; i < UPPER_count; i++) {
		line(img, Point(center.x+scale*UPPER[i-1].x,center.y-scale*UPPER[i-1].y),
			Point(center.x + scale*UPPER[i].x, center.y - scale*UPPER[i].y),
			Scalar(0, 0, 0), 2);
	}
	for (int i = 1; i < LOWER_count; i++) {
		line(img, Point(center.x + scale*LOWER[i - 1].x, center.y - scale*LOWER[i - 1].y),
			Point(center.x + scale*LOWER[i].x, center.y - scale*LOWER[i].y),
			Scalar(0, 0, 0), 2);
	}
	
	
	
	try {
		imwrite(output, img);
	}
	catch (...) {
		cout << "Недопустимое имя изображения" << endl;
		return;
	}		
}
