#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

using namespace std;

class book  {
	private:
		char *author, *title, *publisher;
		float *price, *retailprice, *edition;
		int *stock;
		public:
			book() {
				author= new char[20];
				title= new char[20];
				publisher= new char[20];
				price= new float;
				retailprice= new float;
				edition= new float;
				stock= new int;
			}
			void feeddata();
			void editdata();
			void showdata();
			int search(char[],char[]);
			void buybook();
			
};

void book::feeddata() {
	cin.ignore();
	cout<<"\nEnter Title Of The Book: ";    
	cin.getline(title,20);
	cout<<"\nEnter Author Name: ";   
	cin.getline(author,20);
	cout<<"\nEnter Publisher Name: ";   
	cin.getline(publisher,20);
	cout<<"\nEnter Price: ";    
	cin>>*price;
	cout<<"\nEnter Retail Price: ";    
	cin>>*retailprice;
	cout<<"\nEnter Edition: ";   
	cin>>*edition;
	cout<<"\nEnter Stock Position: ";   
	cin>>*stock;
	
}

void book::editdata() {
	cin.ignore();
	cout<<"\nEnter Author Name: ";   
	cin.getline(author,20);
	cout<<"\Enter Title Name: ";    
	cin.getline(title,20);
	cout<<"\Enter Publisher Name: ";   
	cin.getline(publisher,20);
	cout<<"\Enter Price: ";    
	cin>>*price;
	cout<<"\Enter Retail Price: ";    
	cin>>*retailprice;
	cout<<"\Enter Edition: ";   
	cin>>*edition;
	cout<<"\Enter Stock Position: ";   
	cin>>*stock;
	
}

void book::showdata() {
	cout<<"\nAuthor Name: "<<author;
	cout<<"\nTitle Name: "<<title;
	cout<<"\nPublisher Name: "<<publisher;
	cout<<"\nPrice: "<<*price;
	cout<<"\nRetail Price: "<<*retailprice;
	cout<<"\nEdition of Book "<<*edition;
	cout<<"\nStock Position: "<<*stock;
	
}

int book::search(char tbuy[20],char abuy[20]) {
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
	return 1;
	else return 0;
		
}

void book::buybook() {
	int count;
	cout<<"\nEnter Number Of Books to Buy: ";
	cin>>count;
	if(count=*stock) {
		*stock=*stock-count;
		cout<<"\nBooks Bought Sucessfully";
		cout<<"\nAmount: Rs. "<<(*price)*count;
	}
	else
	cout<<"\nRequired Copies not in Stock";
}

int main() {
	book *B[20];
	int i=0,r,t,choice;
	char titlebuy[20],authorbuy[20];
	
	while(1) {
		system("color 0A");
		cout<<"   \n \t\t\t\t\t\t\t\t\t\t\t Simple Book Store"
		<<"\n\n \t\t\t\t\tMenu"
		<<"\n\t\t\t\t\t1. Entry of New Book"
		<<"\n\t\t\t\t\t2. Buy Book"
		<<"\n\t\t\t\t\t3. Search For Book"
		<<"\n\t\t\t\t\t4. Edit Details of Book"
		<<"\n\t\t\t\t\t5. Exit"
		<<"\n\n\t\t\t\t\tEnter Your Choice: ";
		cin>>choice;
		
		switch(choice) {
			case 1:
				B[i]=new book;
				B[i]->feeddata();
				i++;   break;
			
			case 2:
				cin.ignore();
				cout<<"Enter Title Of Book: ";  cin.getline(titlebuy,20);
				cout<<"\nEnter Author Of Book: ";  cin.getline(authorbuy,20);
				
				for(t=0;t<i;t++)  {
					if(B[t]->search(titlebuy,authorbuy))  {
						B[t]->buybook();
						break;
						}
					}
				if(t==1)
				cout<<"\nThis Book is Not in Stock"; break;
				
		    case 3:
				cin.ignore();
		    	cout<<"\nEnter Title Of Book: ";   cin.getline(titlebuy,20);
		    	cout<<"\nEnter Author Of Book: ";   cin.getline(authorbuy,20);
		    	for(t=0;t<i;t++)  {
		    		if(B[t]->search(titlebuy,authorbuy))  {
		    			cout<<"\nBook Found Successfully";
		    			system("color 9F");
		    			B[t]->showdata();
		    			break;
						}
					}
				if(t==i)
				cout<<"\nThis Book is Not in Stock"; break;
			
			case 4:
				cin.ignore();
				cout<<"\nEnter Title Of Book: ";  cin.getline(titlebuy,20);
				cout<<"\nEnter Author Of Book: ";  cin.getline(authorbuy,20);
				for(t=0;t<i;t++)  {
					if(B[t]->search(titlebuy,authorbuy))  {
						cout<<"\nBook Found Successfully";
						B[t]->editdata();
						break;
						}
					}
				if(t==i)
				cout<<"\nThis Book is Not in Stock"; break;
			
			case 5:
				exit(0);
			default: cout<<"\n\t\t\t\t\tInvalid Choice Entered\n\n\t\t\t\t\tPlease Select From The Above Options\n\n";
		}
	}
	return 0;
}
