#pragma once
#include <iostream>
#include <string>
using namespace std;

class User
{
	public:
		string _log;
		string _pass;
		string _name;

		User(); // ������������ �� ���������: �������������� ������ ��������
		User(string log, string pass, string name); // ������������� � ��������� ������� ������� � ������
		void SendMess(const string& mess, const string& recip = "") const // �������� ��������� � ��� ����� �� �����
		{
			if (recip.empty())
			{
				cout << _name << " (to everyone): " << mess << endl;
			}
			else
			{
				cout << _name << " (to " << recip << "): " << mess << endl;
			}
		}
};
