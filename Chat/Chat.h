#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "User.h"
#include "Mess.h"
using namespace std;

class Chat
{
	public:
		bool registerUser(const string& login, const string& password, const string& name); // ������������ ������ ������������. ���������� true, ���� ����������� �������, � false, ���� ����� ��� �����.
		bool loginUser(const string& login, const string& password); // ��������� ���� ������������ � �������.
		void logoutUser(const string& login); // ����� �� �������.
		void SendMess(const string& senderLogin, const string& mess, const string& recip = "") // ���������� ���������. ���� ���������� �� ������, ��������� ��������� ���������, ����� � ������.
		{
			if (!recip.empty())
			{
				if (!users.count(recip))
				{
					cout << "Error: user " << recip << " not found " << endl;
					return;
				}
				privateMessage[senderLogin].emplace_back(senderLogin, mess, recip);
				privateMessage[recip].emplace_back(senderLogin, mess, recip);
				cout << users[senderLogin]._name << " (to: " << recip << ":) " << mess << endl;
			}
			else
			{
				publicMessage.emplace_back(senderLogin, mess);
				cout << users[senderLogin]._name << " (to everyone) " << mess << endl;
			}
		}
		void listUsers(string login, int count) const; // ������� ������ ���� ������������������ �������������, �������� �������� ������������.
		void viewMess(const string& login) const; // ���������� ��� ��������� (��������� � ������) ��� ������� ������������.

	private:
		map<string, User> users; // ������ ������������������ �������������, ���� - �����.
		vector<string> onlineUsers; // ������ ������������� � ����
		vector<Mess> publicMessage; // ��������� ���������, ������������ ����� ��������������
		map<string, vector<Mess>> privateMessage; // ������ ������ ��������� �������������, ���� - �����
};