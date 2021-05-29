#include"memoryIO.h"

bool initialize_database()
{
	fgraph.open("friend_graph.txt", ios::in | ios::ate | ios::out);
	cgraph.open("discordant_graph.txt", ios::in | ios::ate | ios::out);
	infor.open("usrs.dat", ios::binary | ios::in | ios::ate | ios::out);
	user u;
	int i = -1, userid, friendid, discid;                     // friendid - friend's id, discid - discordant's id
	fgraph_node *ftemp;
	cgraph_node *ctemp;
	infor.seekg(0, ios::beg);
	while (!infor.eof()) {
		i++;
		infor.read((char *) &u, sizeof(u));
		usr[i] = u;
	}
	i--;
	user_no = i;
	if (i == -1) {cout << "file access failed"; return 0;}
	fgraph.seekg(0, ios::beg);
	while (!fgraph.eof()) {
		fgraph>>userid>>friendid;
		ftemp = usr[userid].friend_link;
		if (usr[userid].friend_link == nullptr) {
			usr[userid].friend_link = new fgraph_node;
			usr[userid].friend_link->uid = friendid;
		}
		else {
			while (ftemp->friend_link != nullptr) {ftemp = ftemp->friend_link;}
			ftemp->friend_link = new fgraph_node; ftemp->friend_link->uid = friendid;
		}
	}
	ftemp->friend_link = nullptr;                              // to erase an extra record at the end
	cgraph.seekg(0, ios::beg);
	while (!cgraph.eof()) {
		cgraph>>userid>>discid;
		ctemp = usr[userid].disc_link;
		if (usr[userid].disc_link == nullptr) {
			usr[userid].disc_link = new cgraph_node;
			usr[userid].disc_link->uid = discid;
		}
		else {
			while (ctemp->disc_link != nullptr) {ctemp = ctemp->disc_link;}
			ctemp->disc_link = new cgraph_node; ctemp->disc_link->uid = discid;
		}
	}
	ctemp->disc_link = nullptr;                                // to erase an extra record at the end
	infor.close(); fgraph.close(); cgraph.close();
	if (ftemp != nullptr) {return 1;}                          // statement to check if the Initialization was successful
	else {return 0;}
}
