#pragma once
#include "config.h"
#include <string>


namespace cmd {

	/*
	Обработка агрументов командной строки и определение на их основе коффигурации программы
	*/
	class arguments {
		size_t count;
		char ** argument;
	protected:
		bool isKey(size_t index) const {
			return argument[index][0] == '/';
		}

		std::string find(const std::string name, std::string default) const;
				

	public:
		arguments(size_t count,  char * arguments[]):count(count), argument(arguments){}
		void apply(config & cfg) const;
	};

}