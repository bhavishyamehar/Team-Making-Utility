#include"initialization.h"

void display_links()                                        // to display all the links when in admin mode
{
	fgraph_node *ftemp;
	cgraph_node *ctemp;
	for (int i = 0; i <= user_no; i++) {
		usr[i].disp_info();
		ftemp = usr[i].friend_link;
		cout << "\n\n\tthe user has the following friends :";
		while (ftemp != nullptr) {
			cout<< "\n\t"; usr[ftemp->uid].disp_info();
			ftemp = ftemp->friend_link;
		}
		ctemp = usr[i].disc_link;
		cout << "\n\tthe user has the following discordinators :";
		while (ctemp != nullptr) {
			cout<< "\n\t"; usr[ctemp->uid].disp_info();
			ctemp = ctemp->disc_link;
		}
		cout << "\n\n";
	}
}

void most_links()
{
	fgraph_node *ftemp;
	cgraph_node *ctemp;
	int fmax = 0, cmax = 0, temp1, temp2;
	for (int i = 0; i <= user_no; i++) {
		int fcount = 0, ccount = 0;
		ftemp = usr[i].friend_link;
		while (ftemp != nullptr) {
			fcount++;
			ftemp = ftemp->friend_link;
		}
		ctemp = usr[i].disc_link;
		while (ctemp != nullptr) {
			ccount++;
			ctemp = ctemp->disc_link;
		}
		if (fcount > fmax) {fmax = fcount; temp1 = i;}
		if (ccount > cmax) {cmax = ccount; temp2 = i;}
	}
	cout <<"the following user has the most friends :\n";
	usr[temp1].disp_info();
	cout << "       with " << fmax << " friends\n";
	cout <<"the following user has the most discordants :\n";
	usr[temp2].disp_info();
	cout << "       with " << cmax << " discordants\n";
}

bool is_friend(int uid, int other_uid)
{
	fgraph_node *ftemp;
	ftemp = usr[uid].friend_link;
	while (ftemp != nullptr) {
		if (ftemp->uid == other_uid) {return 1;}
		ftemp = ftemp->friend_link;
	}
	return 0;
}

bool is_discordant(int uid, int other_uid)
{
	cgraph_node *ctemp;
	ctemp = usr[uid].disc_link;
	while (ctemp != nullptr) {
		if (ctemp->uid == other_uid) {return 1;}
		ctemp = ctemp->disc_link;
	}
	return 0;
}
