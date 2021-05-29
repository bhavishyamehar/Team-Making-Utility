#include"accountControl.h"

// main function

int main()
{
    cout << "PASSWORD of all the accounts in the sample database is same as their NAME and adminstrative PASSWORD is admin\n";
	bool tar = 0;
	infor.open("usrs.dat", ios::binary | ios::in | ios::ate | ios::out);
	infor.close();
	if (!initialize_database()) {cout << "\nInitialization failed"; exit(0);}
	else {cout << "Database initialized successfully\n";}
	user temp1;
	int ans, y, t;                                                   // for user input to menu
	char passwd[20];

    do
    {
//      system("clear");
		cout << "\n\t\tTEAM MAKING UTILITY\n\n";
		cout << "1.Administrator\n2.Add new user\n3.Login\n4.display all users\n5.exit\n\n==>"; cin >>ans;
		switch(ans)
		{
			case 1:
				cout << "enter the administrative password: ";
				cin>>passwd;
				initialize_database();
				if (strcmp(passwd, "admin")) {cout << "password incorrect\n"; break;}
				admin_algos();
				break;

			case 2:
				initialize_database();
				if (add_user()) {
					cout << "new user added successfully\n";
				}
				else {cout << "user could not be added\n";}
				cin.get();
				break;

			case 3:
				initialize_database();
				cout << "enter your user id(UID) => "; cin>>t;
				usr[t].disp_info();
				for (int i = 0; i<3 && tar == 0; i++) {
					cout << "\nenter your user password: ";
					cin>>passwd;
					if (usr[t].check_pass(passwd)) {tar = 1;}
					else {cout << "password incorrect\n";}
				}
				if (tar == 0) {break;}
				tar = 0;
				int ch;
				cout<<"\n1. edit my user profile "<<endl;
				cout<<"2. delete my id "<<endl;
				cout<<"3. display my friends and discordants "<<endl;
				cout<<"Enter your choice(1 or 2 or 3)"<<endl;
				cin>>ch;
				switch(ch)
				{
				    case 1: modify_user(t);
				            break;
                    case 2: delete_user(t);
                            break;
					case 3: 
						cout << "\n your friends are :\n";
						for(int i = 0; i <= user_no; i++) {
							if (is_friend(t, i)) {usr[i].disp_info(); cout << endl;}
						}
						cout << "\n your discordants are :\n";
						for(int i = 0; i <= user_no; i++) {
							if (is_discordant(t, i)) {usr[i].disp_info(); cout << endl;}
						}
				}
				break;

			case 4:
				initialize_database();
				display();
				cin.get();
				break;

		}
	} while(ans == 1 || ans == 2 || ans == 3 || ans == 4);
	infor.close();
}

