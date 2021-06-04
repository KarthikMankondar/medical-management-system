#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>

using namespace std;
int num;

class records
{
	char medicine[30];
	int stock;
	int bnumber;
	int mfg,exp;
	float price;
	
	public:

		
		records()
		{
			stock=0;
			price=0;
			mfg=0;
			exp=0;
			bnumber=0;
		}
	
		void setdata()
		{
			system("cls");
			fflush(stdin);
			cout<<endl<<"ENTER THE NAME OF THE MEDICINE"<<ends;
			gets(medicine);
			cout<<endl<<"Enter the batch number"<<ends;
			cin>>bnumber;
			cout<<endl<<"Enter the price"<<ends;
			cin>>price;
			cout<<endl<<"Enter the Manufacturing Date"<<ends;
			cin>>mfg;
			cout<<endl<<"Enter the Expiry Date"<<ends;
			cin>>exp;
			cout<<endl<<"Enter the total stock"<<ends;
			cin>>stock;
			cout<<endl<<endl;
		}
		
		void showdata()
		{
//			system("cls");
			cout<<"Medicine Name=";
			puts(medicine);
			cout<<ends<<"Price="<<price<<ends<<"MFg="<<mfg<<ends<<"EXP="<<exp<<ends<<"Stock="<<stock<<ends<<"Batch Number="<<bnumber;
			cout<<endl<<endl<<"-------------------------------------------------------";
			cout<<endl<<endl<<"Press any key to Continue......"<<endl;
		}
		
		

int menu();		
void readfunc();
void writefunc();
void updatefunc();
void searchfunc();
void deletefunc();

}entry;


void records::readfunc()
{
	system("cls");	
	fstream ifs;
	
	ifs.open("records.txt",ios::in|ios::binary);
		
while(ifs.read((char*)&entry,sizeof(entry)))
  {
	entry.showdata();
  }
  
}

void records::writefunc()
{
	system("cls");
	fstream ofs;
	
	ofs.open("records.txt",ios::out|ios::binary);
	
	cout<<endl<<"Enter the total number of Entries"<<ends;
	cin>>num;

	for(int i=0;i<num;i++)
	{
		entry.setdata();
		ofs.write((char*)&entry,sizeof(entry));
	}
  	
	ofs.close();
	
}

void records::updatefunc()
{
	system("cls");
 int choice,loc,status=0;

 fstream fs;

 cout<<"\nEnter the batch number to be searched\n";
 cin>>choice;

 fs.open("records.txt",ios::in|ios::out|ios::binary);

 while(	fs.read((char*)&entry,sizeof(entry)))
 {

	if(entry.bnumber==choice)
		{
			status=1;
			loc=sizeof(entry);
			fs.seekp(-loc,ios::cur);
			entry.setdata();
			fs.write((char*)&entry,sizeof(entry));
		}
 }

 fs.close();
 
	if(status==1)
	{
		cout<<endl<<"Records Updated"<<endl;
	}
	if(status==0)
 	cout<<"\nRecord not found\n";
 
}

void records::searchfunc()
{
	system("cls");
	int choice;
	int status=0;
	
	cout<<"Enter the Batch number of the Medicine to be Searched ";
	cin>>choice;
	
	ifstream ifs;
	
	ifs.open("records.txt",ios::in|ios::binary);
	
	while(ifs.read((char*)&entry,sizeof(entry)))
	{
		if(entry.bnumber==choice)
		{
			status=1;
			entry.showdata();	
		}
	}
	
	ifs.close();
	
	if(status==0)
	cout<<endl<<"Record Not Found"<<endl;
}

void records::deletefunc()
{
	system("cls");
	int choice,status=0;
	
	fstream fs1,fs2;
	
	cout<<"Enter the Batch Number ";
	cin>>choice;
	
	fs1.open("records.txt",ios::in|ios::binary);
	fs2.open("records2.txt",ios::out|ios::binary);
	
	while(fs1.read((char*)&entry,sizeof(entry)))
	{
		if(entry.bnumber!=choice)
		{
			status=1;
			fs2.write((char*)&entry,sizeof(entry));
		}
	}
	
	fs1.close();
	fs2.close();
	
	remove("records.txt");
	rename("records2.txt","records.txt");
	
	if(status==1)
	{
		cout<<endl<<"Record Deleted"<<endl;
	}
	else if(status==0)
	cout<<endl<<"Records Not Found"<<endl;
}


int records::menu()
{
	int opt;
while(1)
{	
	system("cls");
	
	cout<<"1:ALL DATA"<<"\t\t\t\t2:ENTER DATA"<<endl<<"3:UPDATE"<<"\t\t\t\t4:SEARCH"<<endl<<"5:DELETE"<<"\t\t\t\t6:EXIT"<<endl<<endl;
	cin>>opt;
		
	switch(opt)
	{
		case 1:readfunc();
		getch();
		system("cls");
		break;
		
		case 2:writefunc();
		getch();
		system("cls");
		break;
		
		case 3:updatefunc();
		getch();
		system("cls");
		break;
		
		case 4:searchfunc();
		getch();
		system("cls");
		break;
		
		case 5:deletefunc();
		getch();
		system("cls");
		break;
		
		case 6:exit(0);
		break;
		
		default :cout<<endl<<"Wrong option selected"<<endl<<endl<<endl<<"Press any key to continue......."<<endl;
		getch();
		break;
	}
}
}

int main()
{	
	system("color F3");
	entry.menu();
}
