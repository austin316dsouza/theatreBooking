#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<fstream.h>

class theatre
{
	int A[100][200],rown,coln;
	int RC,GC,SC,MC;
	double Apin;
	int total;
	int bill;

	public:

	char mname[20];

	theatre()
	{
		RC=GC=SC=MC=0;
	}

	void initialize()
	{

		for(int i=1;i<10;i++)
		{
			for(int j=1;j<15;j++)
				A[i][j]=0;
		}
	 }

	void displayseats()
	{
		clrscr();
		int B=1;
		char C=1;
		theatre T;
		T.initialize();
		cout<<"\n\t\t\t\tWELCOME TO SLOWMAPPZ CINEMAS";
		cout<<endl<<"Row 1,2,3 - Royale (Rs.250) \nRow 4,5,6 - Gold(Rs.200) \nRow 7,8,9 - Silver (Rs.150)";
		cout<<endl<<"\nName of the Movie - ";
		puts(mname);
		cout<<endl<<"\nNote- [1] - Booked seats";
		cout<<"\n________________________COLUMN_________________________";
		cout<<"\n___1__2__3__4__5__6__7__8__9_10__11_12_13_14___";
		for(int i=1;i<10;i++)
		{
			cout<<endl<<B++<<C<<":";

			for(int j=1;j<15;j++)
			{
				cout<<A[i][j]<<"  ";
			}
		}
		cout<<"\n_____________________SCREEN_IS_HERE____________________";

	}

	void bookit()
	{
		cout<<"\nEnter the row no. & column no.(Row_SPACE_column):-";
		cin>>rown>>coln;
		clrscr();
		if((rown<1||rown>9)||(coln<1||coln>14))
		{
			cout<<"\nINVALId INPUT... Please check your input";
			return;
		}

		if(A[rown][coln]==1)
		{
			cout<<"\n\nSeat is already taken dude!";
			return;
		}

		if(rown==1||rown==2||rown==3)
			RC++;

		else if(rown==4||rown==5||rown==6)
			GC++;

		else if(rown==7||rown==8||rown==9)
			SC++;

		if(A[rown][coln]==0)
		{
			A[rown][coln]=1;
			cout<<"\n\nseat successfully Booked bhai!! ";
			cout<<"\n========================\nBill:-\nMovie Name - "<<mname;
			cout<<"\nNo. of tickets - 1";
			cout<<"\nSeat no- row "<<rown<<" column "<<coln;

			if(rown==1||rown==2||rown==3)
			       bill=250;

			else if(rown==4||rown==5||rown==6)
				bill=200;

			else if(rown==7||rown==8||rown==9)
				bill=150;
			cout<<"\nTotal = Rs."<<bill<<"\n========================";
		}

	}

	void megabook()
	{
		int start,end;

		cout<<"\n\nEnter the row number of tickets to be booked:";
		cin>>rown;

		if(rown<1||rown>9)
		{
			clrscr();
			cout<<"\nINVALId INPUT... Please check your input";

		}
		cout<<"\nEnter the start column and End column:";
		cin>>start>>end;

		if((start<1||start>14)||(end<1||end>14))
		{
			clrscr();
			cout<<"\nINVALId INPUT... Please check your input";

		}

		for(int j=start;j<=end;j++)
		{
			if(A[rown][j]==1)
			{
				clrscr();
				cout<<"\nPlease check the input! Some seats might be already Booked!";
			}
		}

		for(j=start;j<=end;j++)
		{
			MC++;
			A[rown][j]=1;
		}

		if(rown==1||rown==2||rown==3)
		{
			RC+=MC;
			total+=250*MC;
		}

		else if(rown==4||rown==5||rown==6)
		{
			GC+=MC;
			total+=200*MC;
		}

		else if(rown==7||rown==8||rown==9)
		{
			SC+=MC;
			total+=150*MC;
		}

		clrscr();
		cout<<"\nMega-Book Succesfully !!\n\nNo. of Tickets Booked for you are:"<<MC;

		cout<<"\n========================\nBill:-\nMovie Name - "<<mname;
			cout<<"\nNo. of tickets - "<<MC;
			cout<<"\nSeat nos- row "<<rown<<" column "<<start<<"-"<<end;

			if(rown==1||rown==2||rown==3)
			       bill=MC*250;

			else if(rown==4||rown==5||rown==6)
				bill=MC*200;

			else if(rown==7||rown==8||rown==9)
				bill=MC*150;

			cout<<"\nTotal = Rs."<<bill<<" \n========================";

	}

	void sales()
	{
		clrscr();

		total=RC*250+GC*200+SC*150;
		cout<<"Enter Admin PIN:-";
		cin>>Apin;

		if(Apin==12345)
		{
			clrscr();
			cout<<"\nShowing sales for Movie - ";
			puts(mname);
			cout<<"\n\n\nNO. of tickets sold is:-";
			cout<<"\nROYALE SEATS :"<<RC;
			cout<<"\nGOLD SEATS :"<<GC;
			cout<<"\nSILVER SEATS :"<<SC;
			cout<<"\ntotal cash earned:-Rs."<<total;
		}

		else
			cout<<"\nIncorrect pin! please try again";
	}

	void cancelseat()
	{
		clrscr();
		 int B=1;
		 char C=1;

		cout<<"\n________________________COLUMN_________________________";
		cout<<"\n___1__2__3__4__5__6__7__8__9_10__11_12_13_14___";

		for(int i=1;i<10;i++)
		{
			cout<<endl<<B++<<C<<":";

			for(int j=1;j<15;j++)
			{
				cout<<A[i][j]<<"  ";
			}
		}
		cout<<"\n_____________________SCREEN_IS_HERE____________________";


		cout<<"\nWe serve free cancelations!!";
		cout<<"\n\nEnter seat to be cancelled(Row_SPACE_column):";
		cin>>rown>>coln;
		clrscr();

		if(A[rown][coln]==1)
		{
			A[rown][coln]=0;
			cout<<"\nSeat cancelled sucessfully!";

			if(rown==1|rown==2|rown==3)
			{
				RC--;
				cout<<"\nCashback : Rs.250";
			}

			else if(rown==4|rown==5|rown==6)
			{
				GC--;

				cout<<"\nCashback : Rs.200";
			}
			else if(rown==7|rown==8|rown==9)
			{	SC--;

				cout<<"\nCashback : Rs.150";
			}
		 }
		 else
			cout<<"\nOnly Booked seats can be cancelled!";
	}

};


void main()
{
	clrscr();
	theatre a;
	int n;
	cout<<"\n[ This program is coded by Austin and Raish ] #All rights reserved#";
	cout<<"\n\nEnter the Movie name:-";
	gets(a.mname);

	do
	{
		cout<<"\n\n\n1.Book my seat\n2.Ticket Cancelation\n3.Check total sales\n4.Mega-Book\n5.Exit\n\n\nEnter your choice-";
		cin>>n;
		switch(n)
		{ 	case 1: a.displayseats();
				a.bookit();
				break;
			case 2: a.cancelseat();
				break;
			case 3: a.sales();
				break;
			case 4: a.displayseats();
				a.megabook();
				break;
			case 5:
				break;
			default:cout<<"\nINVALID INPUT";
	  }

	}while(n!=5);

	getch();

}
/*
sample outputs:
Output 1:Welcome Screen


[ This program is coded by Austin and Raish ] #All rights reserved#

Enter the Movie name:-Robot 2.0



1.Book my seat
2.Ticket Cancelation
3.Check total sales
4.Mega-Book
5.Exit


Enter your choice-5

Output 2:Bill Output for single ticket booking


seat successfully Booked bhai!!
========================
Bill:-
Movie Name - Robot 2.0
No. of tickets - 1
Seat no- row 3 column 4
Total = Rs.250
========================


1.Book my seat
2.Ticket Cancelation
3.Check total sales
4.Mega-Book
5.Exit


Enter your choice-5

Output 3:Output for seat cancelation

Seat cancelled sucessfully!
Cashback : Rs.250


1.Book my seat
2.Ticket Cancelation
3.Check total sales
4.Mega-Book
5.Exit


Enter your choice-5

Output 4:Bill Output for Mega-Book


Mega-Book Succesfully !!

No. of Tickets Booked for you are:6
========================
Bill:-
Movie Name - Robot 2.0
No. of tickets - 6
Seat nos- row 1 column 3-8
Total = Rs.1500
========================


1.Book my seat
2.Ticket Cancelation
3.Check total sales
4.Mega-Book
5.Exit


Enter your choice-5

Output 5:Output for Total sales


Showing sales for Movie - Robot 2.0



NO. of tickets sold is:-
ROYALE SEATS :1
GOLD SEATS :2
SILVER SEATS :1
total cash earned:-Rs.800


1.Book my seat
2.Ticket Cancelation
3.Check total sales
4.Mega-Book
5.Exit


Enter your choice-5
*/


