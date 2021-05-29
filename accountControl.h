#include"makeTeam.h"

void modify_user(int userid)
{
    int choice, choice_f, choice_d,friend_id,discordant_id;
    cout<<"\n1. Add or Remove a friend "<<endl;
    cout<<"2. Add or Remove a discordant "<<endl;
    cout<<"3. edit my skills and password "<<endl;
    cout<<"enter your choice -> ";
    cin>>choice;
    if (choice==1)
    {
		fgraph.open("friend_graph.txt", ios::in | ios::ate | ios::out);
        cout<<"enter user id of friend: ";
        cin>>friend_id;
        cout<<"1. add friend"<<endl;
        cout<<"2. remove friend"<<endl;
        cout<<"enter your choice"<<endl;
        cin>>choice_f;
        if(choice_f==1)
        {
            if(save_link(userid, friend_id, fgraph)) {
                cout<<"friend added successfully"<<endl;
                f_create_link(userid, friend_id);
			}

        }
        else if (choice_f == 2)
        {
            if(delete_link(userid,friend_id, fgraph)) {
                cout<<"friend removed successfully"<<endl;
                f_delete_link(userid, friend_id);
			}    
        }
    }
    else if(choice == 2)
    {
		cgraph.open("discordant_graph.txt", ios::in | ios::ate | ios::out);
        cout<<"enter user id of discordant: "<<endl;
        cin>>discordant_id;
        cout<<"1. add discordant"<<endl;
        cout<<"2. remove discordant:"<<endl;
        cin>>choice_d;
        if(choice_d==1)
        {
            if(save_link(userid, discordant_id, cgraph)) {
                cout<<"discordant added successfully"<<endl;
                c_create_link(userid, discordant_id);
			}
        }
        else
        {
            if(delete_link(userid, discordant_id, cgraph)) {
                cout<<"discordant removed successfully"<<endl;
                c_delete_link(userid, discordant_id);
			}
        }
    }
    else if (choice == 3)
    {
        int user_id;
        user usr;
        fstream file3;
        file3.open("usrs.dat", ios::in | ios::out | ios::ate | ios::binary);
        cout<<"enter your user id"<<endl;
        cin>>user_id;
        while( file3.read((char *)&usr, sizeof(usr)))
        {
            if( usr.return_userid()== user_id)
           {
               usr.input( user_id);
               file3.seekg( -sizeof(usr), ios::cur);
               file3.write( (char *)&usr, sizeof(usr));
           }

       }
    }
    infor.close(); fgraph.close(); cgraph.close();
}

bool delete_user(int user_id)
 {
	 fgraph.open("friend_graph.txt", ios::in | ios::ate | ios::out);
	 cgraph.open("discordant_graph.txt", ios::in | ios::ate | ios::out);
	 char pass[21];
     user usr;
     int input_uid;
     bool temp1;

      //int user_id;
     cout<<"Enter your password => ";
     cin>>pass;
	if (!(::usr[user_id].check_pass(pass))) {cout << "password incorrect\n"; return 0;}
   //  cout<<" Enter the user id the user is friend with(type -1 to exit)"<<endl;
    // cin>>input_uid;

     /*    temp1= delete_link(usr.uid, user_id,fgraph);
         if(temp1 ==1)
         {
             cout<<"link is deleted"<<endl;
             return 0;
         }
         else
            cout<<"user id is not matched, hence link is not deleted"<<endl;

    // cout<<" Enter the user id the user is concordant with(type -1 to exit)"<<endl;
    // cin>>input_uid;

         temp1= delete_link(usr.uid, user_id,cgraph);
         if(temp1 ==1)
         {
             cout<<"link is deleted"<<endl;
             return 0;
         }
         else
            cout<<"user id is not matched, hence link is not deleted"<<endl;*/


     fstream file1;
     fstream file2;
     file1.open("usrs.dat", ios::in |ios::binary);
     file2.open("usrs_temp.dat", ios::out | ios::binary);



     while ( file1.read((char *)&usr, sizeof(usr)))
      {
          if(usr.return_userid()!= user_id)
            file2.write((char *)&usr, sizeof(usr));
      }
      file1.close();
      file2.close();
      remove("usrs.dat");
      rename("usrs_temp.dat","usrs.dat");
		::usr[user_id].deleteo();
		for (int i = 0; i<user_no; i++) {
			if (is_discordant(user_id, i)) {delete_link(user_id, i, cgraph); c_delete_link(user_id, i);}
			if (is_friend(user_id, i)) {delete_link(user_id, i, fgraph); f_delete_link(user_id, i);}
		}
 }
