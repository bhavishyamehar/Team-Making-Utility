#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>


using namespace std;

unsigned int user_no;                                       // stores ("the number of user"-1) as UIDs start from zero
// files for saving the graph to disk
fstream fgraph;
fstream cgraph;
fstream infor;

// classes and member functions start
class fgraph_node {

public:
	int uid;
	fgraph_node *friend_link = nullptr;
};
class cgraph_node {

public:
	int uid;
	cgraph_node *disc_link = nullptr;
};

// enum skill{production, research, marketing, human_resource, accounting_finance};

class user {
	char name[52];
	// skill is abilty to work in other group
	int skill1;
	int skill2;
	int skill3;
	char password[51];

public:
	int uid;
	fgraph_node *friend_link = nullptr;
	cgraph_node *disc_link = nullptr;
	void disp_info() {
	cout << "name = " << name << "\tskill-1 = " << skill1 << "\tskill-2 = " << skill2 << "\tskill-3 = " << skill3 << "\tuser id = " << uid;
	}
	void input(int userid)
	{
		int temp;
		cout << "enter name => ";
		cin>>name;
		cout << "enter a PASSWORD(max 50 words) => "; cin>>password;
		cout << "enter your skill set :(if less than 3 skill then repeatedly fill the last skill)\n";
		cout << "0->production\t1->research\t2->marketing\t3->human_resource\t4->accounting & finance";
		do {
			cout << "\nskill-1 => "; cin>>skill1;
		}while (skill1 != 0 && skill1 != 1 && skill1 != 2 && skill1 != 3 && skill1 != 4);
		do {
			cout << "skill-2 => "; cin>>skill2;
		}while (skill2 != 0 && skill2 != 1 && skill2 != 2 && skill2 != 3 && skill2 != 4);
		do {
			cout << "skill-3 => "; cin>>skill3;
		}while (skill3 != 0 && skill3 != 1 && skill3 != 2 && skill3 != 3 && skill3 != 4);
		uid = userid;
		cout << "your UID is = " << uid;
	}
	void deleteo()
	{
		int temp;
		strcpy(name, "DELETED");
		skill1 = -1;
		skill2 = -1;
		skill3 = -1;
	}
	bool check_pass(char *r)
	{
		if (strcmp(r, password)) {return 0;}
		else {return 1;}
	}
	void operator =(user u)                                    // operator function as otherwise "=" will copy all the data including the pointers variable
	{                                                          // without any memory leading to segmentation fault
		uid = u.uid;
		strcpy(name, u.name);
		skill1 = u.skill1;
		skill2 = u.skill2;
		skill3 = u.skill3;
		strcpy(password, u.password);
	}
	bool check_skill(int skillno)
	{
		if (skill1 == skillno || skill2 == skillno || skill3 == skillno) {return 1;}
		return 0;
	}
	int return_userid()
	{
	    return (uid);
	}
};
user usr[200];                                               // global array for storing the user objects

class gmem {

public:
	int uid;
	int compatiblity = 0;                                      // if this value is high then the user is more likely to be in any group
	void operator =(gmem m)                                    // not really neccessary but helps in keeping track
	{
		uid = m.uid;
		compatiblity = m.compatiblity;
	}
};

// classes and member function declaration end

