#include "argumets.h"


std::string cmd::arguments::find(const std::string name, std::string default) const {
	for (size_t i = 1; i < count; i++) {
		if (isKey(i) && !isKey(i + 1) && name == argument[i])
			return argument[i + 1];
	}
	return default;
}

void cmd::arguments::apply(config & cfg) const {
	cfg.m_input = find("/file", cfg.m_input);
	cfg.m_output = find("/save", cfg.m_output);
}