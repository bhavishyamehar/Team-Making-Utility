#include"createUser.h"


bool f_create_link(int userid, int friendid)                // to create link in memory for fast operations
{
	fgraph_node *ftemp;
	ftemp = usr[userid].friend_link;
	if (usr[userid].friend_link == nullptr) {
		usr[userid].friend_link = new fgraph_node;
		usr[userid].friend_link->uid = friendid;
	}
	else {
		while (ftemp->friend_link != nullptr) {ftemp = ftemp->friend_link;}
		ftemp->friend_link = new fgraph_node; ftemp->friend_link->uid = friendid;
	}
	return 1;
}

bool f_delete_link(int userid, int friendid)
{
	int place = 0;
	fgraph_node *ftemp, *swap;
	ftemp = usr[userid].friend_link;
	while (ftemp != nullptr) {
		if (ftemp->uid == friendid) {
			break;
		}
		place++;
	}
	if (place == 0) {return 0;}
	ftemp = usr[userid].friend_link;
	while (place > 0) {
		ftemp = ftemp->friend_link;
		place--;
	}
	swap = ftemp->friend_link->friend_link;
	ftemp->friend_link = swap;
	return 1;
}

bool c_delete_link(int userid, int discid)
{
	int place = 0;
	cgraph_node *ctemp, *swap;
	ctemp = usr[userid].disc_link;
	while (ctemp != nullptr) {
		if (ctemp->uid == discid) {
			break;
		}
		place++;
	}
	if (place == 0) {return 0;}
	ctemp = usr[userid].disc_link;
	while (place > 0) {
		ctemp = ctemp->disc_link;
		place--;
	}
	swap = ctemp->disc_link->disc_link;
	ctemp->disc_link = swap;
	return 1;
}

bool c_create_link(int userid, int discid)                  // to create link in memory for fast operations
{
	cgraph_node *ctemp;
	ctemp = usr[userid].disc_link;
	if (usr[userid].disc_link == nullptr) {
		usr[userid].disc_link = new cgraph_node;
		usr[userid].disc_link->uid = discid;
	}
	else {
		while (ctemp->disc_link != nullptr) {ctemp = ctemp->disc_link;}
		ctemp->disc_link = new cgraph_node; ctemp->disc_link->uid = discid;
	}
	return 1;
}
