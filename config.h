#pragma once
#include <string>

namespace cmd {
	class arguments;
}

/*
������������ ���������
������������� �����:
/save - ����, ���� ����� ��������� ����������� (��������� ������������), ���� ����������, ������ �������� �� ��������� "polygon.jpg"
/file - ��������� ����, ����������� ���������� ������������� (������� � ������ ���������� �������)
*/
class config {
	friend class cmd::arguments; //��������� ������������� �����, ����� �� ��� �������� ��������� ������������
	static config m_instance;
	std::string m_input;
	std::string m_output = "polygon.jpg";
	config() {};  // ��������� ����������� ������������, ��� ��������� ������ ����� ���� ������ ������ ������ ���� ������
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