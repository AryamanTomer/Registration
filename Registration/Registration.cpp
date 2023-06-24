// Registration.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class User {
	private:
		string username, password;
	public:
		User(string n, string p) {
			username = n;
			password = p;
		};
		string getUserName() {
			return username;
	    }
		string getPassword() {
			return password;
		}
		void setUserName(string u) {
			username = u;
		}
		void setPassword(string p) {
			password = p;
		}
		
};
class UserManagement {
	private:
		vector<User> users;
	public:
		void Register() {
			string username, password;
			cout << "\t\tEnter Username: ";
			cin >> username;
			cout << "\t\tEnter Password: ";
			cin >> password;
			
			User newUser(username, password);
			users.push_back(newUser);

			cout << "\t\tUser Registered as " + username + "! Welcome!" << endl;
		}
		bool LoginUser(string name, string pass)
		{
			for (int i = 0; i < users.size(); i++) {
				if (users[i].getUserName() == name && users[i].getPassword() == pass) {
					cout << "\t\tLogin Success!!!!" << endl;
					return true;
				}
			}
			cout << "Login Failed!!!";
			return false;
		}
		void userList() {
			cout << "\t\t---Users List---" << endl;
			for (int i = 0; i < users.size(); i++) {
				cout << "\t\t" << users[i].getUserName() << endl;
			}
		}
		void findUser(string username) {
			for (int i = 0; i < users.size(); i++) {
				if (users[i].getUserName() == username) {
					cout << "\t\t User Found" << endl;
				}
			}
		}
		void deleteUser(string username) {
			for (int i = 0; i < users.size(); i++) {
				if (users[i].getUserName() == username) {
					users.erase(users.begin() + i);
					cout << "\t\t User Successfully Removed!" << endl;
				}
			}
		}
};
int main() {
	UserManagement use;
	int o;
	char choice;
	do {
		system("cls");
		cout << "\n\n\t\t1. Register User " << endl;
		cout << "\t\t2. Login " << endl;
		cout << "\t\t3. Show User List " << endl;
		cout << "\t\t4. Search User " << endl;
		cout << "\t\t5. Delete User " << endl;
		cout << "\t\t6. Exit " << endl;
		cout << "\t\tEnter your choice : ";
		string username, password;
		string us;
		string user;
		cin >> o;
		switch (o) {
		case 1:
			use.Register();
			break;
		case 2:
			cout << "\t\tEnter Username: ";
			cin >> username;
			cout << "\t\tEnter Password: ";
			cin >> password;
			use.LoginUser(username, password);
			break;
		case 3:
			use.userList();
			break;
		case 4:
			cout << "\t\tEnter the user you want to find : ";
			cin >> us;
			use.findUser(us);
			break;
		case 5:
			cout << "\t\t Enter the user you want to delete : ";
			cin >> user;
			use.deleteUser(user);
			break;
		case 6:
			exit(1);
		}
		cout << "\t\tDo you Want to Continue [Yes / No] ? : ";
		cin >> choice;

	}
	while (choice == 'y' || choice == 'Y');

}