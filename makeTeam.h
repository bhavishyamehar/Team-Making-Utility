#include"adminAlgos.h"

void mkgroup(int req1, int req2 = -1, int req3 = -1)        // req is for requirement
{
	int i = 0, strength, j = -1, k;
	gmem gruid[30], temp;
	cout << "\nhow many people do you want in the group => ";
	cin>>strength;
	if (req2 == -1 && req3 == -1) {
		for (i = 0; i <= user_no; i++) {
			if (usr[i].check_skill(req1)) {j++; gruid[j].uid = i;}
		}
	}
	else if (req3 == -1) {
		for (i = 0; i <= user_no; i++) {
			if (usr[i].check_skill(req1) && usr[i].check_skill(req2)) {j++; gruid[j].uid = i;}
		}
	}
	else {
		for (i = 0; i <= user_no; i++) {
			if (usr[i].check_skill(req1) && usr[i].check_skill(req2) && usr[i].check_skill(req3)) {j++; gruid[j].uid = i;}
		}
	}
	if (j == -1) {cout << "no user has the required skill-set\n"; return;}
	for (k = 0; k <= j; k++) {
		for (i = 0; i <= j; i++) {
			if (is_friend(gruid[k].uid, gruid[i].uid)) {gruid[i].compatiblity++;}
			if (is_discordant(gruid[k].uid, gruid[i].uid)) {gruid[i].compatiblity--;}
		}
	}
	while (j > strength-1) {
		gmem min;
		int index_of_min = 0;
		min = gruid[0];
		for (int i = 0; i <= j; i++) {
			if (gruid[i].compatiblity < min.compatiblity) {index_of_min = i; min = gruid[i];}
		}
		gruid[index_of_min] = gruid[j];
		gruid[j] = min;
		j--;
	}
	cout << "\nRecommended group members are as follows :\n";
	for (int i = 0; i <= j; i++) {
// 		cout << gruid[i].uid <<"\t" << i << "\n";                 // just for debugging
		cout << "\t";
		usr[gruid[i].uid].disp_info(); cout << endl;
	}
}

bool admin_algos()
{
	int ans, y[3], t, i;                                           // for user input to menu
// 	infor.seekg(-sizeof(temp1), ios::end);
// 	if (!infor.good()) {cout << "not good";}
// 	infor.read((char *) & temp1, sizeof(temp1));
// 	user_no = temp1.uid;
// 	cout << usr[0].uid;
    do
    {
//      system("clear");
		cout << "\n\t\tTEAM MAKING UTILITY\n\n";
		cout << "1.display all links\n2.most liked and disliked user\n3.suggest groups\n4.Back to main menu\n\n==>"; cin >>ans;
		switch(ans)
		{
			case 1:
				display_links();
				break;
			case 2:
				most_links();
				break;
			case 3:
				cout << "\nenter the required skill-set below:\n";
				cout << "0->production\t1->research\t2->marketing\t3->human_resource\t4->accounting & finance\nenter the following in accordance :";
				for (i = 0; i<3 && y[i-1] != -1; i++) {
					cout << "\nenter 0 or 1 or 2 or 3 or 4 or -1(to stop)........";
					cin>>y[i];
				}
				if(i == 1)
					mkgroup(y[0]);
				else if (i == 2)
					mkgroup(y[0], y[1]);
				else if (i == 3)
					mkgroup(y[0], y[1], y[2]);
				break;
		}
	}while(ans == 1 || ans == 2 || ans == 3);
	return 1;
}
