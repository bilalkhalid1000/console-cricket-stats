#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
void Layout(void);
void Main(void);
int main ()
{
	Layout();
	Main();
	
	int v;
	//system("cls");
	//Layout();
	//Main1();
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\t\t\t\t\t    MAIN MENU\n");
	int l=0;
	for(l;l<20;l++)
	{
		printf("_____");
		system("ping 127.0.0.1 -n 1 > nul");
	}
	fflush(stdin);
	printf("What do you want to do?\n\n\t");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("1. Save New Records\n\t");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("2. Edit Record\n\t");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("3. View Records\n\t");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("4. New Match\n\t");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("5. Exit\n\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("Enter Your Selection:\t");
	scanf("%d",&v);
	
	getch();
	return 0;
}
void Layout(void)
{
		system("mode con: cols=100 lines=60");
	system("title Final project of BSE(C) TECH-GEEKS (Bilal Khalid (027) and Faizan Haider (108)) ");
}
void Main(void)
{
	for(int l=0;l<20;l++)
	{
		printf("*****");
		system("ping 127.0.0.1 -n 1 > nul");
	}
	printf("\t\t\t\t\tWELCOME TO CRICKET STATS\n");
	for(int j=0;j<20;j++)
	{
		printf("*****");
		system("ping 127.0.0.1 -n 1 > nul");
	}
	printf("\n");
}
/*
int v;
	system("cls");
	Layout();
	Main1();
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\t\t\t\t\t    MAIN MENU\n");
	int l=0;
	for(l;l<20;l++)
	{
		printf("_____");
		system("ping 127.0.0.1 -n 1 > nul");
	}
	fflush(stdin);
	printf("What do you want to do?\n\n\t");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("1. Save New Records\n\t");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("2. Edit Record\n\t");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("3. View Records\n\t");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("4. New Match\n\t");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("5. Exit\n\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("Enter Your Selection:\t");
	scanf("%d",&v);
*/
