#pragma once
#include <string>

namespace cmd {
	class arguments;
}

/*
 онфигураци€ программы
поддерживатс€ ключи:
/save - путь, куда будет сохранено изображение (результат триангул€ции), ключ опционален, имееет значение по умолчанию "polygon.jpg"
/file - текстовый файл, описывающий монотонный многоугольник (верхн€€ и нижн€€ монотонные цепочки)
*/
class config {
	friend class cmd::arguments; //добавл€ем дружественный класс, чтобы он мог измен€ть дефолтную конфигурацию
	static config m_instance;
	std::string m_input;
	std::string m_output = "polygon.jpg";
	config() {};  // приватный конструктор обеспечивает, что экземпл€р класса может быть создан только внутри него самого
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