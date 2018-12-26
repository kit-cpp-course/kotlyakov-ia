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

		std::string find(const std::string name,std::string default ) const {			
			for (size_t i = 1; i < count; i++) {
				if (isKey(i) && !isKey(i + 1) && name==argument[i])
					return argument[i + 1];
			}
			return default;
		}
				

	public:
		arguments(size_t count,  char * arguments[]):count(count), argument(arguments){}
		void apply(config & cfg) const {
			cfg.m_input = find("/file", cfg.m_input);
			cfg.m_output = find("/save", cfg.m_output);
		}
	};

}
