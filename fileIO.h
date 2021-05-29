#include"classes.h"


void display()
{
	for (int i = 0; i <= user_no; i++) {
		usr[i].disp_info();
		cout << endl;
	}
}

bool save_link(int to_uid, int input_uid, fstream &file)
{
	file.seekp(0, ios::end);
	if (file.good()) {file << setw(3) << to_uid << " " << setw(3) << input_uid << endl;}
	else {return 0;}
	return 1;
}

bool delete_link(int to_uid, int input_uid, fstream &file)
{
    int u_id, fr_id;
    char d;
    file.seekp(0, ios::beg);
    file.seekg(0, ios::beg);
//     cout<<"enter user id of user who want to remove"<<endl;
//     cin>>u_id;
    while(!file.eof()) {
		file >> u_id >>fr_id;
		if (u_id == to_uid && fr_id == input_uid) {
			file.seekp(file.tellg(), ios::beg); file.seekp(-7, ios::cur);
			file << "       ";
			return 1;
		}
	}
	return 0;
//     while(!file.eof())
//     {
//         if(u_id == to_uid)
//         {
//              file.seekp(-6, ios::cur);
//              file<<"   "<< "\t" <<"   "<<endl;
//              return 1;
//         }
// 
//     }

}

