#include "iostream"
#include "opencv2/opencv.hpp"		//билиотека функций, необходимая для вывода графического результата работы программы
#include "config.h"
#include "argumets.h"
#include "polygone.h"
#include "triangulated_polygone.h"
#include "structs.h"
#include <fstream>



using namespace std;
using namespace cv;

int main(size_t count, char * args[]) {		//или char ** args (массив строк) count(количество аргументов)
	setlocale(LC_ALL, "Russian");
	config & cfg = config::instance();	
	cmd::arguments arg(count, args);
	arg.apply(cfg);	
	
	ifstream f(cfg.input());
	if (!f.good()) {									//проверка аргументов командной строки на корректность
		cout << "Некорректное имя файла " << endl;
		return 1;
	}
	int n;
	char devider;
	float coord_x, coord_y;
	point* upoints,* lpoints;
	int ulength, llength;
	
		f >> n;
		try {
			upoints = new point[n];
		}
		catch (std::bad_array_new_length e) {
			cout << "Ошибка в формате текстового файла" << endl;	//проверка на корректность содержимого файла, с описанием многоугольника
			system("pause");
			return 1;
		}
		ulength = n;
		for (int i = 0; i < n; i++) {
			f >> devider >> coord_x >> devider >> coord_y >> devider;
			upoints[i] = point(coord_x, coord_y);
		}
		f >> n;
		try {
			lpoints = new point[n];
		}
		catch (std::bad_array_new_length e) {
			cout << "Ошибка в формате текстового файла" << endl;	//проверка на корректность содержимого файла, с описанием многоугольника
			system("pause");
			return 1;
		}		
		llength = n;
		for (int i = 0; i < n; i++) {
			f >> devider >> coord_x >> devider >> coord_y >> devider;
			lpoints[i] = point(coord_x, coord_y);
		}
	
	
	
	triangulated_poly poly(upoints,lpoints, ulength,llength);		//создание триангулируемого объекта по заданным параметрам

	//poly.show();
	poly.triangulate();
	//poly.show_diagonals();	
	
	poly.draw_polygone(cfg.output());
	
	

}