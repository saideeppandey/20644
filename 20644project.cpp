#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
class bank
{
 private:
   int long total;
   string id;
   struct person
   {
     string name;string Id;string address;
     int long contact;int long cash;
     }person[100];
 public:
    bank()
    {
      total=0;
      }
      void choice();
      void perdata();
      void show();
      void update();
      void search();
      void transactions();
      void del();
};
int main()
{
    bank b;
    b.choice();
   return 0;
}
void bank::choice()
{
  char ch;
  while(1)
  {
   cout<<"\n\nPRESS...!!"<<endl;
   cout<<"1. Create new account"<<endl;
   cout<<"2. View customers list"<<endl;
   cout<<"3. Update information of existing account"<<endl;
   cout<<"4. Check the details of the existing account"<<endl;
   cout<<"5. For transactions"<<endl;
   cout<<"6. Remove existing account"<<endl;
   cout<<"7. Exit"<<endl;
   ch=getch();
   system("CLS");
   switch(ch)
   {
     case '1':
       bank::perdata();
       break;
     case '2':
         if(total==0)
         {
             cout<<"No data is entered"<<endl;
         }
         else{
        bank::show();
         }
        break;
     case '3':
         if(total==0)
         {
             cout<<"No data is entered"<<endl;
         }
         else
         {
        bank::update();}
        break;
     case '4':
         if(total==0)
         {
             cout<<"No data is entered"<<endl;
         }else{
        bank::search();}
        break;
     case '5':
         if(total==0)
         {
             cout<<"No data is entered"<<endl;
         }else{
        bank::transactions();}
        break;
     case '6':
         if(total==0)
         {
             cout<<"No data is entered"<<endl;
         }else{
        bank::del();}
        break;
     case '7':

            exit(0);
         break;
    }
  }
}
void bank::perdata()
{
  cout<<"Enter the data of person "<<total+1<<endl;
  cout<<"Enter name: ";
  cin>>person[total].name;
  cout<<"Id: ";
  cin>>person[total].Id;
  cout<<"Address: ";
  cin>>person[total].address;
  cout<<"Contact: ";
  cin>>person[total].contact;
  cout<<"Total Cash: ";
  cin>>person[total].cash;
  total++;

}
void bank::show()
{
    int i;
  for(i=0;i<total;i++)
  {
      cout<<"Data of person "<<i+1<<endl;
      cout<<"Name: "<<person[i].name<<endl;
      cout<<"Id: "<<person[i].Id<<endl;
      cout<<"Address: "<<person[i].address<<endl;
      cout<<"Contact: "<<person[i].contact<<endl;
      cout<<"Cash: "<<person[i].cash<<endl;
  }
}

void bank::update()
{
    int i;
  cout<<"Enter id of student those data you want to update"<<endl;
  cin>>id;
  for(i=0;i<total;i++)
  {
      if(id==person[i].Id)
      {
          cout<<"Previous data"<<endl;
          cout<<"Data of person "<<i+1<<endl;
          cout<<"Name: "<<person[i].name<<endl;
          cout<<"Id: "<<person[i].Id<<endl;
          cout<<"Address: "<<person[i].address<<endl;
          cout<<"Contact: "<<person[i].contact<<endl;
          cout<<"Cash: "<<person[i].cash<<endl;
          cout<<"\nEnter new data"<<endl;
          cout<<"Name: ";
  cin>>person[i].name;
  cout<<"Id: ";
  cin>>person[i].Id;
  cout<<"Address: ";
  cin>>person[i].address;
  cout<<"Contact: ";
  cin>>person[i].contact;
  cout<<"Total Cash: ";
  cin>>person[i].cash;
  break;

      }
      if(i==total-1)
      {
           cout<<"No such record found"<<endl;
      }
  }
}
void bank::search()
{
   int i;
   cout<<"Enter id of student whose data you want to search"<<endl;
   cin>>id;
   for(i =0;i<total;i++)
   {
       if(id==person[i].Id)
       {
           cout<<"Name: "<<person[i].name<<endl;
           cout<<"Id: "<<person[i].Id<<endl;
           cout<<"Address: "<<person[i].address<<endl;
           cout<<"Contact: "<<person[i].contact<<endl;
           cout<<"Cash: "<<person[i].cash<<endl;
           break;
       }
       if(i==total-1)
       {
            cout<<"No such record found"<<endl;
       }
   }
}
void bank::transactions()
{
  int i,cash;char ch;
  cout<<"Enter id of student in which you want to do transaction"<<endl;
  cin>>id;
  for(i=0;i<total;i++)
  {
      if(id==person[i].Id)
      {
          cout<<"Name: "<<person[i].name<<endl;
          cout<<"Address: "<<person[i].address<<endl;
          cout<<"Contact: "<<person[i].contact<<endl;
          cout<<"\nExisting cash "<<person[i].cash<<endl;
          cout<<"Press 1 to deposit"<<endl;
          cout<<"Press 2 to withdraw"<<endl;
          ch=getch();
          switch(ch)
          {
          case '1':
            cout<<"How much cash you want to deposit??"<<endl;
            cin>>cash;
            person[i].cash+=cash;
            cout<<"Your new cash is "<<person[i].cash<<endl;
            break;
          case '2':
            back:
            cout<<"How much cash you want to withdraw??"<<endl;
            cin>>cash;
            if(cash>person[i].cash)
            {
                cout<<"Your existing cash is just "<<person[i].cash<<endl;
                Sleep(4000);
                goto back;
            }
            person[i].cash-=cash;
            cout<<"Your new cash is "<<person[i].cash<<endl;
            break;
          default:
            cout<<"invalid input"<<endl;
            break;
          }
          break;
      }
      if(i==total-1)
      {
          cout<<"No such record found"<<endl;
      }
  }
}
void bank::del()
{
    char ch;int i;
    cout<<"Press 1 to remove specific record"<<endl;
    cout<<"Press 2 to remove full record"<<endl;
    ch=getch();
    switch(ch)
    {
        case '1':
        cout<<"Enter id of student those data you want to del"<<endl;
        cin>>id;
        for(i=0;i<total;i++)
        {
            if(id==person[i].Id)
            {
                for(int j=i;j<total;j++)
                {
                person[j].name=person[j+1].name;
                person[j].Id=person[j+1].Id;
                person[j].address=person[j+1].address;
                person[j].contact=person[j+1].contact;
                person[j].cash=person[j+1].cash;

                }
                total--;
                cout<<"Your required data is deleted"<<endl;
                break;
            }
            if(i==total-1)
            {
                cout<<"No such record found"<<endl;
            }
        }
        break;
        case '2':
            total=0;
            cout<<"All record is deleted"<<endl;
            break;
        default:
            cout<<"invalid input"<<endl;
            break;
    }
}
