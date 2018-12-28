#pragma once
#include <string>

namespace cmd {
	class arguments;
}

/*
Конфигурация программы
поддерживатся ключи:
/save - путь, куда будет сохранено изображение (результат триангуляции), ключ опционален, имееет значение по умолчанию "polygon.jpg"
/file - текстовый файл, описывающий монотонный многоугольник (верхняя и нижняя монотонные цепочки)
*/
class config {
	friend class cmd::arguments; //добавляем дружественный класс, чтобы он мог изменять дефолтную конфигурацию
	static config m_instance;
	std::string m_input;
	std::string m_output = "polygon.jpg";
	config() {};  // приватный конструктор обеспечивает, что экземпляр класса может быть создан только внутри него самого
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

config config::m_instance = config();
