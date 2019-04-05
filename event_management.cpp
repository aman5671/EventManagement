// NAME - SINGHANIYA AMAN
// ROLL NO. - RE1705B50
// REGISTRATION NO. - 11701665
// SECTION - E1705
// GROUP - 2
// MOBILE NO. - 8437510430


#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
class event
{
   public:
       char eventname[100],organization[50],day[20],description[100],sponsor[50],budget[10],achiever[50];
       int q,B,p;
       event()
       {
           strcpy(eventname,"NO Event Name");
           strcpy(organization,"No Organization Name");
           strcpy(day,"No Date");
           strcpy(description,"No description");
           strcpy(achiever,"No Archiever");
           strcpy(budget,"No Budget");
           strcpy(sponsor,"No Sponsor");
           q=1;
           B=0;
       }
          void get();
          void student();
          void pass();
          void admin();
          void password();
          void getdata();
          void show(int);
          void eventlist(int);
          void modify();
          void search(int);
          void der(char[],int,int);
};
void event::getdata()
{
                    int i;
                    fflush(stdin);
                    cout<<"\n\t\tEnter the details :-\n";
                    cout<<"\n\t\tEnter Event's Name : ";
                    cin.getline(eventname,100);
                    for(i=0;eventname[i]!='\0';i++)
                    {
                    if(eventname[i]>='a'&&eventname[i]<='z')
                    
                       eventname[i]-=32;
                    }
                    cout<<"\n\t\tEnter Organization Name : ";
                    cin.getline(organization,50);
                    cout<<"\n\t\tEnter description of Event: ";
                    cin.getline(description,100);
                    cout<<"\n\t\tEnter Date of Event : ";
                    cin.getline(day,20);
                    cout<<"\n\t\tEnter Achiever of Event : ";
                    cin.getline(achiever,50);
					cout<<"\n\t\tEnter Budget of Event : ";
                    cin.getline(budget,10);
					cout<<"\n\t\tEnter Sponsor of Event : ";
                    cin.getline(sponsor,50);
}
void event::show(int i)
{
    cout<<"\n\t\tEvent Name : "<<eventname<<endl;
    cout<<"\n\t\tOrganization's Name : "<<organization<<endl;
    cout<<"\n\t\tEvent's Date : "<<day<<endl;
    cout<<"\n\t\tEvent's description : "<<description<<endl;
    cout<<"\n\t\tEvent's Achiever : "<<achiever<<endl;
if(i==2)
{
cout<<"\n\t\tEvent's Budget : "<<budget<<endl;
cout<<"\n\t\tEvent's Sponsor : "<<sponsor<<endl;
}
}
  void event::eventlist(int i)
  {
                int b,r=0;
                system("cls");
                system("cls");
                ifstream intf("Eventdata.txt",ios::binary);
                if(!intf)
                    cout<<"\n\t\tFile Not Found.";
                else
                {
                    cout<<"\n\t    ************ Event List ************ \n\n";
                    intf.read((char*)this,sizeof(*this));
                while(!intf.eof())
                {
                    if(b==B)
                    {
                        if(q==0 && i==1)
                        {

                        }
                        else
                            {
                                r++;
                                cout<<"\n\t\t********** "<<r<<". ********** \n";
                                show(i);
                            }
                    }
                    intf.read((char*)this,sizeof(*this));
                }
                }
                cout<<"\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                if(i==1)
                    student();
                else
                    admin();
    }
  void event::modify()
  {
    char ch,st1[100];
    int i=0,b,cont=0;
    system("cls");
    cout<<"\n\t\t>>Please Choose one option :-\n";
    cout<<"\n\t\t1.Modification In Current Events\n\n\t\t2.Add New Event\n\n\t\t3.Delete A Event\n\n\t\t4.Go back\n";
    cout<<"\n\n\t\tEnter your choice : ";
    cin>>i;
    if(i==1)
    {
                    system("cls");
                    ifstream intf1("Eventdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tFile Not Found\n";
                        cout<<"\n\t\tPress any key to continue.....";
                        getch();
                        system("cls");
                        admin();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tPlease Choose One Option :-\n";
                        cout<<"\n\t\t1.Search By Event Name\n\n\t\t2.Search By Date\n";
                        cout<<"\n\t\tEnter Your Choice : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tEnter Event Name : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Eventdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&eventname[i]!='\0'&&st1[i]!='\0'&&(st1[i]==eventname[i]||st1[i]==eventname[i]+32);i++);
                                        if(eventname[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                                     intf.read((char*)this,sizeof(*this));
                                    }
                                    intf.close();
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tEnter Date : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Eventdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&day[i]!='\0'&&st1[i]!='\0'&&st1[i]==day[i];i++);
                                        if(day[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                        intf.read((char*)this,sizeof(*this));
                                    }

                                intf.close();
                        }
                        else
                        {
                            cout<<"\n\t\tIncorrect Input.....:(\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tEvent Not Found.\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\tUpdate Successful.\n";


    }
    else if(i==2)
    {
                    system("cls");
                    system("cls");
                    getdata();
                    ofstream outf("Eventdata.txt",ios::app|ios::binary);
                    outf.write((char*)this,sizeof(*this));
                    outf.close();
                    cout<<"\n\t\tEvent added Successfully.\n";
    }
    else if(i==3)
    {
                    system("cls");
                    ifstream intf1("Eventdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tFile Not Found\n";
                        cout<<"\n\t\tPress any key to continue.....";
                        getch();
                        intf1.close();
                        system("cls");
                        admin();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tPlease Choose One Option for deletion:-\n";
                        cout<<"\n\t\t1.By Event Name\n\n\t\t2.By Event Date\n";
                        cout<<"\n\t\tEnter Your Choice : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tEnter Event Name : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Eventdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&eventname[i]!='\0'&&st1[i]!='\0'&&(st1[i]==eventname[i]||st1[i]==eventname[i]+32);i++);
                                        if(eventname[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));

                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }

                    intf.close();
                    outf.close();
                    remove("Eventdata.txt");
                    rename("temp.txt","Eventdata.txt");
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tEnter Event's Date : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Eventdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&day[i]!='\0'&&st1[i]!='\0'&&st1[i]==day[i];i++);
                                        if(day[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));
                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }
                    outf.close();
                    intf.close();
                    remove("Eventdata.txt");
                    rename("temp.txt","Eventdata.txt");
                        }
                        else
                        {
                            cout<<"\n\t\tIncorrect Input.....:(\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tEvent Not Found.\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\tDeletion Successful.\n";

    }
    else if(i==4)
    {
    system("cls");
    admin();
    }
    else
    {
    cout<<"\n\t\tWrong Input.\n";
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    modify();
    }
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    admin();

  }
  void event::search(int x)
  {
      int i,b,cont=0;
      char ch[100];
      system("cls");
      ifstream intf("Eventdata.txt",ios::binary);
        if(!intf)
        {
            cout<<"\n\t\tFile Not Found.\n";
            cout<<"\n\t\t->Press any key to continue.....";
            getch();
            system("cls");
            if(x==1)
            student();
            else
            admin();
        }

      system("cls");
      cout<<"\n\t\tPlease Choose one option :-\n";
      cout<<"\n\t\t1.Search By Name\n\n\t\t2.Search By Date\n";
      cout<<"\n\t\tEnter Your Choice : ";
      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(i==1)
      {
          cout<<"\n\t\tEnter Event's Name : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
            for(i=0;b==B&&q!=0&&eventname[i]!='\0'&&ch[i]!='\0'&&(ch[i]==eventname[i]||ch[i]==eventname[i]+32);i++);
            if(eventname[i]=='\0'&&ch[i]=='\0')
                {
                        cout<<"\n\t\tEvent Found :-\n";
                        show(x);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }
      }
          else if(i==2)
          {
          cout<<"\n\t\tEnter Event's Date : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
              for(i=0;b==B&&q!=0&&day[i]!='\0'&&ch[i]!='\0'&&ch[i]==day[i];i++);
              if(day[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tEvent Found :-\n";
                            show(x);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\n\t\tPlease enter correct option :(";
             getch();
             system("cls");
             search(x);
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tThis Event is not available :( \n";

    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if(x==1)
    student();
    else
    admin();


  }
void event::get()
{
   int i;
    system("Color F4");
        cout<<"\n\t*********** EVENT MANAGEMENT SYSTEM ***********\n"<<"\n\t\tMade By - Singhaniya Aman\n"<<"\n\t\tRegistration No. - 11701665\n";
        cout<<"\n\t\t>>Please Choose Any Option To login \n";
        cout<<"\n\t\t1.Student\n\n\t\t2.Admin\n\n\t\t3.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        if(i==1)
        {
            system("cls");
            student();
        }
        else if(i==2)
            pass();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("CLS");
           get();
        }
}
void event::student()
{
    int i;
        cout<<"\n\t************ WELCOME STUDENT ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View Event List\n\n\t\t2.Search for an Event\n\n\t\t3.Go to main menu\n\n\t\t4.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
            if(i==1)
                eventlist(1);
            else if(i==2)
                search(1);
            else if(i==3)
            {
                system("cls");
                get();
            }
            else if(i==4)
                exit(0);
            else
            {
                cout<<"\n\t\tPlease enter correct option :(";
                getch();
                system("cls");
                student();
            }
}
void event::pass()
{
    int i=0;
    char ch,st[21],ch1[21]={"pass"};
    cout<<"\n\t\tEnter Password : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream inf("password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        admin();
    }
    else
    {
        cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        getch();
        system("cls");
        get();
    }
}
void event::admin()
{
    int i;
        cout<<"\n\t************ WELCOME ADMIN ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View Event List\n\n\t\t2.Search for an Event\n\n\t\t3.Modify/Add Event\n\n\t\t4.Go to main menu\n\n\t\t5.Change Password\n\n\t\t6.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch(i)
        {
            case 1:eventlist(2);
                     break;
            case 2:search(2);
                     break;
            case 3:modify();
                     break;
            case 4:system("cls");
                     get();
                     break;
            case 5:password();
                    break;
            case 6:exit(0);
            default:cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            admin();
        }
}
void event::password()
{
    int i=0,j=0;
    char ch,st[21],ch1[21]={"pass"};
    system("cls");
    cout<<"\n\n\t\tEnter Old Password : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream intf("password.txt");
    intf>>ch1;
    intf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        cout<<"\n\t**The Password Should be less than 20 characters & don't use spaces**\n\n";
        cout<<"\n\t\tEnter New Password : ";
        fflush(stdin);
        i=0;
        while(1)
        {
        j++;
        ch=getch();
        if(ch==13)
        {
            for(i=0;st[i]!=' '&&st[i]!='\0';i++);
            if(j>20 || st[i]==' ')
            {
                cout<<"\n\n\t\tYou did't follow the instruction \n\n\t\tPress any key for try again.....";
                getch();
                system("cls");
                password();
                admin();
            }
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
        cout<<"*f";
        st[i]=ch;
        i++;
        }
        }
        ofstream outf("password.txt");
        outf<<st;
        outf.close();
        cout<<"\n\n\t\tYour Password has been changed Successfully.";
        cout<<"\n\t\tPress any key to continue......";
        getch();
        system("cls");
        admin();
    }
    else
    {
        cout<<"\n\n\t\tPassword is incorrect.....\n";
        cout<<"\n\t\tEnter 1 for retry or 2 for menu";
        cin>>i;
        if(i==1)
        {
        system("cls");
        password();
        }
        else
        {
            system("cls");
            admin();
        }
    }
}
int main()
{
    event obj;
    obj.get();
    getch();
    return 0;
}
