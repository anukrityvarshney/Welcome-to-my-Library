			      //*book store*//

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<fstream.h>
	      //class for object//
class customer{
public:
char name[30];         //variables
char address[30];
float price;
char bookname[30];
char authorname[30];
void input(){	      //for inputting details of book and customer
cout<<"\t\t\tenter customer name.";
gets(name);
cout<<"\t\t\tenter address.";
gets(address);
cout<<"\t\t\tenter book name.";
gets(bookname);
cout<<"\t\t\tenter author name.";
gets(authorname);
cout<<"\t\t\tenter price of book.";
cin>>price;
}
void output(){
cout<<"\n*****************************************************************************";
cout<<"\n\t\t\t\tdetails\n ";
cout<<"*****************************************************************************";                  //for printing details of book and customer
cout<<"\n\tcustomer name :"<<name;
cout<<"\n\tcustomer address :"<<address;
cout<<"\n\tbook name :"<<bookname;
cout<<"\n\tauthor name :"<<authorname;
cout<<"\n\tbook price :"<<price;
}
}cust;                        //object of class customer

void create(){                         //option 2
	clrscr();
	char ans;
	ofstream file;
	file.open("bookstore.dat",ios::binary);
	do{
		clrscr();
		cust. Input();
		file.write((char*)&cust,sizeof(cust));
		cout<<"want more (y/n)";
		cin>>ans;
	} while(ans=='y'||ans=='Y');
	file.close();
	getch();
}

void display(){                    //option3
	clrscr();
	ifstream file;
	file.open("bookstore.dat",ios::binary);
	while(file.read((char*)&cust,sizeof(cust)))
		cust.output();

	file.close();
	getch();
}

void search(){                 //option5
	clrscr();
	char custoname[30];
	ifstream file;
	cout<<"\nenter customer name whose detail is to be searched.";
	gets(custoname);
	file.open("bookstore.dat",ios::binary);
	while(file.read((char*)&cust,sizeof(cust))){
		if(strcmp((cust.name),(custoname))==0){
			cust.output();
		}
	}
	file.close();
	getch();
}

void append(){                          //option4
	clrscr();
	char ans;
	ofstream file;
	file.open("bookstore.dat",ios::app|ios::binary);
	do{
		cust.input();
		file.write((char*)&cust,sizeof(cust));
		cout<<"more?:(y/n)";
		cin>>ans;
	} while(ans=='Y'||ans=='y');
	file.close();
	getch();
}

void modify(){                 //option6
	clrscr();
	char custname[3],newname[30],newauthor[30];
	float newprice;
	fstream file;
	file.open("bookstore.dat",ios::binary|ios::in|ios::out);
		cout<<"\nenter the customer name you want to edit\n";
	gets(custname);
	cout<<"\nenter new book name"  ;
	gets(newname);
	cout<<"\nenter author.";
	gets(newauthor);
	cout<<"enter price";
	cin>>newprice;
	while(file.read((char*)&cust,sizeof(cust))){
		if(strcmp(cust.name,custname)==0){
		 cout<<"found";
		 strcpy(cust.bookname,newname);
		 strcpy(cust.authorname,newauthor);
		 cust.price=newprice;
	      int pos=file.tellg();
	      file.seekp(pos-sizeof(cust));
	       file.write((char*)&cust,sizeof(cust));
		}
	}
	file.close();
	getch();
}

void del(){
	clrscr();
	ifstream file;
	ofstream file1;
	char name[30];
	file.open("bookstore.dat",ios::binary);
	file1.open("books.dat",ios::binary);
	cout<<"enter customer name :";
	gets(name);
	file.seekg(0,ios::beg);
	while(file.read((char*)&cust,sizeof(cust))){
		if(strcmp(cust.name,name)!=0)
		 file1.write((char*)&cust,sizeof(cust));
		 else
		 cout<<"record deleted";
	}

	file.close();
	file1.close();
	 remove("bookstore.dat");
	rename("books.dat","bookstore.dat");
	getch();
}


void main(){
clrscr();
	int choice;
	do{
	clrscr();
	cout<<"********************************************************************************";
	cout<<"\t\t\twelcome to the bookstore\n";
	cout<<"********************************************************************************";
	cout<<"\n\n1.exit";
	cout<<"\n2.creation";
	cout<<"\n3.display";
	cout<<"\n4.append";
	cout<<"\n5.search";
	cout<<"\n6.modify";
	cout<<"\n7.deletion\n";
	cin>>choice;
	switch(choice){
		case 1:exit(0);
		case 2: create();break;
		case 3:display();break;
		case 4:append();break;
		case 5:search();break;
		case 6:modify();break;
		case 7:del();break;
	}
	}while(choice!=8);
	getch();
}














