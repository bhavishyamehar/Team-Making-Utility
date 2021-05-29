#include"fileIO.h"


bool f_create_link(int, int);                               // (prototype)to create link in memory for fast operations
bool c_create_link(int, int);                               // (prototype)to create link in memory for fast operations

bool add_user()
{
	fgraph.open("friend_graph.txt", ios::in | ios::ate | ios::out);
	cgraph.open("discordant_graph.txt", ios::in | ios::ate | ios::out);
	infor.open("usrs.dat", ios::binary | ios::in | ios::ate | ios::out);
	user u;
	user_no++;                                                 // incrementing as a new user is added
	int input_uid;
	bool temp;
	usr[user_no].input(user_no);
	cout << "\nenter the uids of users the user is friends with(type -1 to exit) : \n" << "friend's uid => ";
	cin>>input_uid;
	while (input_uid != -1) {
	// here fgraph is the friend graph's fstream object
		if (!save_link(usr[user_no].uid, input_uid, fgraph)) {cout << "Link saving failed"; break; return 0;}
		if (!f_create_link(usr[user_no].uid, input_uid)) {cout << "link creation in memory failed"; break; return 0;}
		cout << "friend's uid => ";
		cin>>input_uid;
	}
	cout << "\nenter the uids of users the user is discordant with(type -1 to exit) : \n" << "discordant's uid => ";
	cin>>input_uid;
	while (input_uid != -1) {
	// here cgraph is the discordant graph's fstream object
		if (!save_link(usr[user_no].uid, input_uid, cgraph)) {cout << "Link saving failed"; break; return 0;}
		if (!c_create_link(usr[user_no].uid, input_uid)) {cout << "link creation in memory failed"; break; return 0;}
		cout << "discordant's uid => ";
		cin>>input_uid;
	}
	fgraph.close(); cgraph.close();
	infor.seekp(0, ios::beg);
	if (infor.good()) {
		infor.seekp(0, ios::end);
		u = usr[user_no];
		infor.write((char *) &u, sizeof(u));
		infor.close();
	}
	else {cout << "File access failed\n"; infor.close(); return 0;}
	return 1;
}
