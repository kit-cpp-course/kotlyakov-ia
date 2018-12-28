#pragma once
#include <string>

namespace cmd {
	class arguments;
}

/*
конфигурация программы
поддерживатся ключи:
/save - путь, куда будет сохранено изображение (результат триангуляции), ключ опционален, имееет значение по умолчанию "polygon.jpg"
/file - текстовый файл, описывающий монотонный многоугольник (верхняя и нижняя монотонные цепочки)
*/
class config {
	friend class cmd::arguments; //добавл¤ем дружественный класс, чтобы он мог измен¤ть дефолтную конфигурацию
	static config m_instance;
	std::string m_input;	//тестовый файл-описание многоугольника
	std::string m_output = "polygon.jpg";	//изображение-результат
	config() {};  // приватный конструктор обеспечивает, что экземпл¤р класса может быть создан только внутри него самого
public:
	const std::string & input() {
		return m_input;
	}

	const std::string & output() {
		return m_output;
	}

	static config & instance() {
		return m_instance;
	}
};

