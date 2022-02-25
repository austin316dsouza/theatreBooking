#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
const int M=10;
const int N=15;
void megabook();
void sales();
void displayseats();
void bookit();
void fsave(int A[M][N])
{	int i,j,B=1;
	FILE *fp;
	fp=fopen("theatre.txt","w");
			for(i=1;i<M;i++)
		{
			//fscanf(fp,"\n\t  \t%d: ",B++);

			for(j=1;j<N;j++)
			{
				A[i][j]=0;
			}
		}
		for(i=1;i<M;i++)
		{	fprintf(fp,"\n");
			//fprintf(fp,"\n\t  \t%d: ",B++);

			for(j=1;j<N;j++)
			{
				fprintf(fp,"%d  ",A[i][j]);
			}
		}
	fclose(fp);	
}
void ffetch(int A[M][N])
{	FILE *fp;
	int i,j,B=1;
	fp=fopen("theatre.txt","r");
		for(i=1;i<M;i++)
		{
			//fscanf(fp,"\n\t  \t%d: ",B++);

			for(j=1;j<N;j++)
			{
				fscanf(fp,"%d  ",&A[i][j]);
			}
		}
	fclose(fp);	
		for(i=1;i<M;i++)
		{
			printf("\n%d: ",B++);

			for(j=1;j<N;j++)
			{
				printf("%d  ",A[i][j]);
				
			}
		}
}
int total;
int RC=0,GC=0,SC=0,A[100][100];
char mname[50];

void cancelseat()
	{		int rown,coln;
		system("cls");
		//	clrscr();
		 int B=1,i,j;

		printf("\n\nName of the Movie - ");
		puts(mname);
		printf("\n\nNote- [1] - Booked seats\n");
		printf("\n________________________COLUMN_________________________");
		printf("\n___1__2__3__4__5__6__7__8__9_10__11_12_13_14___");

		ffetch(A);
		printf("\n_____________________SCREEN_IS_HERE____________________");
		FILE *fp;
		fp=fopen("theatre.txt","r");
		for(i=1;i<M;i++)
		{
			//fscanf(fp,"\n\t  \t%d: ",B++);

			for(j=1;j<N;j++)
			{
				fscanf(fp,"%d  ",&A[i][j]);
			}
		}
		fclose(fp);	
		puts("\n\nWe serve free cancelations!!");
		puts("\n\nEnter seat to be cancelled(Row_SPACE_column):-");
		scanf("%d%d",&rown,&coln);
		system("cls");

		if(A[rown][coln]==1)
		{
			A[rown][coln]=0;
			puts("\nSeat cancelled sucessfully!");

			if(rown==1|rown==2|rown==3)
			{
				RC--;
				total-=250;
				puts("\nCashback : Rs.250");
			}

			else if(rown==4|rown==5|rown==6)
			{
				GC--;
				total-=200;
				puts("\nCashback : Rs.200");
			}
			else if(rown==7|rown==8|rown==9)
			{	SC--;
				total-=150;
				puts("\nCashback : Rs.150");
			}
		 }
		 else
			puts("\nOnly Booked seats can be cancelled!");
		fp=fopen("theatre.txt","w");
		for(i=1;i<M;i++)
		{	fprintf(fp,"\n");
			//fscanf(fp,"\n\t  \t%d: ",B++);

			for(j=1;j<N;j++)
			{
				fprintf(fp,"%d  ",A[i][j]);
			}
		}
		fclose(fp);	
	}

void main()
{	int n;
	//fsave(A);
	printf("\t\t\t\t\tCoded by - Austin D'souza\n\nEnter Movie Name :- ");
	gets(mname);
	if(strcmp(strupr(mname),"ROBOT")==0)
	{
	do
	{	
		printf("\n\n\n1.Book my seat\n2.Ticket Cancelation\n3.Check total sales\n4.Mega-Book\n5.RESET Theatre\n6.Exit\n\n\nEnter your choice-");
		scanf("%d",&n);
		switch(n)
		{ 	case 1: 
					system("cls");
					displayseats();
					bookit();
									
				break;
			case 2: cancelseat();
				break;
			case 3: sales();
				break;
			case 4: system("cls");
					displayseats();
					megabook();
				break;
			case 5: fsave(A);
					system("cls");
					printf("\nTheatre Has been Reset :-");
					break;	
			case 6:
					break;
			default:printf("\nINVALID INPUT");
	  }

	}while(n!=6);
	}else
		printf("\n\n Currently only 'ROBOT' movie is available!!");
	

	
}
void displayseats()
{
		int i,j,B=1;
		printf("\n\t\t\t\tWELCOME TO SLOWMAPPZ CINEMAS");
		printf("\nRow 1,2,3 - Royale (Rs.250) \nRow 4,5,6 - Gold(Rs.200) \nRow 7,8,9 - Silver (Rs.150)");
		printf("\n\nName of the Movie - ");
		puts(mname);
		printf("\n\nNote- [1] - Booked seats");
		printf("\n________________________COLUMN_________________________");
		printf("\n___1__2__3__4__5__6__7__8__9_10__11_12_13_14___");
		ffetch(A);		
	
		printf("\n___________________SCREEN_IS_HERE______________________");


}
void bookit()
{	int rown,coln,bill,i,j;
	FILE *fp;
	fp=fopen("theatre.txt","r");
		for(i=1;i<M;i++)
		{
			//fscanf(fp,"\n\t  \t%d: ",B++);

			for(j=1;j<N;j++)
			{
				fscanf(fp,"%d  ",&A[i][j]);
			}
		}
	fclose(fp);	
	printf("\nEnter the row no. & column no.(Row_SPACE_column):-");
	scanf("%d%d",&rown,&coln);
	system("cls");
	//	clrscr();
		if((rown<1||rown>9)||(coln<1||coln>14))
		{
			puts("\nINVALId INPUT... Please check your input");
			return;
		}

		if(A[rown][coln]==1)
		{
			puts("\n\nSeat is already Booked!");
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
			puts("\n\nseat successfully Booked !! ");
			printf("\n========================\nBill:-\nMovie Name - %s",mname);
			puts("\nNo. of tickets - 1");
			printf("\nSeat no- row %d column %d",rown,coln);

			if(rown==1||rown==2||rown==3)
			       bill=250;

			else if(rown==4||rown==5||rown==6)
				bill=200;

			else if(rown==7||rown==8||rown==9)
				bill=150;
			printf("\nTotal = Rs.%d \n========================",bill);
		}
		fp=fopen("theatre.txt","w");
		for(i=1;i<M;i++)
		{	fprintf(fp,"\n");
			//fscanf(fp,"\n\t  \t%d: ",B++);

			for(j=1;j<N;j++)
			{
				fprintf(fp,"%d  ",A[i][j]);
			}
		}
	fclose(fp);
//	fsave(A);	
		
		
}
void megabook()
	{
		int i,j,MC=0,bill,rown,coln,start,end,chk=0;
		FILE *fp;
		fp=fopen("theatre.txt","r");
		for(i=1;i<M;i++)
		{
			//fscanf(fp,"\n\t  \t%d: ",B++);

			for(j=1;j<N;j++)
			{
				fscanf(fp,"%d  ",&A[i][j]);
			}
		}
		fclose(fp);	

		printf("\n\nEnter the row number of tickets to be booked:");
		scanf("%d",&rown);

		if(rown<1||rown>9)
		{
			system("cls");
			puts("\nINVALId INPUT... Please check your input");

		}
		else
		{
		
		puts("\nEnter the start column and End column:");
		scanf("%d%d",&start,&end);

		if((start<1||start>14)||(end<start||end>14))
		{
			system("cls");
			puts("\nINVALId INPUT... Please check your input");

		}

		for(j=start;j<=end;j++)
		{
			if(A[rown][j]==1)
			{	chk=1;
				system("cls");
				puts("\nPlease check the input! Some seats might be already Booked!");
			}
		}
		if(chk==0)
		{	
			
			for(j=start;j<=end;j++)
			{
	
				MC++;
				A[rown][j]=1;
			}
		

			if(rown==1||rown==2||rown==3)
			{
				RC+=MC;
				total+=250*MC;
			}else if(rown==4||rown==5||rown==6)
			{
				GC+=MC;
				total+=200*MC;
			}else if(rown==7||rown==8||rown==9)
			{
				SC+=MC;
				total+=150*MC;
			}

			system("cls");
			printf("\nMega-Book Successful !!\n\nNo. of Tickets Booked for you are:%d",MC);

			printf("\n========================\nBill:-\nMovie Name - %s",mname);
			printf("\nNo. of tickets - %d",MC);
			printf("\nSeat nos- row %d column %d - %d",rown,start,end);

			if(rown==1||rown==2||rown==3)
			       bill=MC*250;

			else if(rown==4||rown==5||rown==6)
				bill=MC*200;

			else if(rown==7||rown==8||rown==9)
				bill=MC*150;

			printf("\nTotal = Rs.%d \n========================",bill);
		}
	}
		fp=fopen("theatre.txt","w");
		for(i=1;i<M;i++)
		{	fprintf(fp,"\n");
			//fscanf(fp,"\n\t  \t%d: ",B++);

			for(j=1;j<N;j++)
			{
				fprintf(fp,"%d  ",A[i][j]);
			}
		}
	fclose(fp);
}
	void sales()
	{	 time_t t;  
   		 time(&t);
		FILE *f1;
		f1=fopen("sales.txt","a");
		system("cls");
		int Apin;
		total=RC*250+GC*200+SC*150;
		puts("Enter Admin PIN:-");
		scanf("%d",&Apin);

		if(Apin==12345)
		{
			system("cls");
			puts("\nShowing sales for Movie - ");
			puts(mname);
			puts("\n\n\nNO. of tickets sold is:-");
			printf("\nROYALE SEATS :%d",RC);
			printf("\nGOLD SEATS :%d",GC);
			printf("\nSILVER SEATS :%d",SC);
			printf("\ntotal cash earned:-Rs.%d",total);
			fprintf(f1,"\n\nRecords for :- %s",ctime(&t));
			fprintf(f1,"\nROYALE SEATS :%d",RC);
			fprintf(f1,"\nGOLD SEATS :%d",GC);
			fprintf(f1,"\nSILVER SEATS :%d",SC);
			fprintf(f1,"\ntotal cash earned:-Rs.%d",total);
			fclose(f1);
		}
		
		else
			printf("\nIncorrect pin! please try again");
	}

	

