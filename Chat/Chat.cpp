#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "User.h"
#include "Mess.h"
#include "Chat.h"
using namespace std;

bool Chat::registerUser(const string& login, const string& password, const string& name)
{
	if (users.count(login))
	{
		cout << "login is already taken" << endl;
		return false;
	}
	users[login] = User(login, password, name);
	cout << "User " << name << " sucsessfuly registered" << endl;
	return true;
}

bool Chat::loginUser(const string& login, const string& password)
{
	if (!users.count(login) || users[login]._pass != password)
	{
		cout << "Error: incorrect login or password" << endl;
		return false;
	}
	onlineUsers.push_back(login); //помещаем пользователя в конец вектора пользователей, которые в сети.
	cout << "User " << login << " logged in" << endl;
	return true;
}

void Chat::logoutUser(const string& login)
{
	onlineUsers.erase(remove(onlineUsers.begin(), onlineUsers.end(), login), onlineUsers.end());
	cout << "User " << login << " logged out" << endl;
}


void Chat::listUsers(string login, int count) const
{
	if (count > 1)
	{
		cout << "Registered users:" << endl;
		for (const auto& pair : users)
		{
			if (pair.first != login)
			{
				cout << "- " << pair.second._name << " (login : " << pair.first << ")" << endl;
			}
		}
	}
}

void Chat::viewMess(const string& login) const
{
	cout << "Chat messages for " << users.at(login)._name << ":" << endl;
	for (const auto& msg : publicMessage)
	{
		cout << msg._sender << " (to everyone): " << msg._content << endl;
	}
	if (privateMessage.count(login))
	{
		for (const auto& msg : privateMessage.at(login))
		{
			cout << msg._sender << " (to " << msg._recip <<" : " << msg._content << endl;
		}
	}
}