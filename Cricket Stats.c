#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

void gotoxy(short x, short y) 
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void mainMenu(void);
void saving(void);
void playerRecord(void);
void teamRecord(void);
void viewing(void);
void printPlayer(void);
void printTeam(void);
void printTP(int cod);
void GoBack(void);
void NewMatch(void);
int MatchType(void);
int PlayMatch(int , int ,int ,int );
void MatchMenu(void);
int Score1(int ,int ,int ,int );
int Score2(int ,int );
void result(int S1, int S2);
void Layout(void);
void Main(void);
void Main1(void);
void Page1(void);
void editing(void);
void editPlayer(void);
void editTeam(void);

int a=0;
int s2=0,w1=0,w2=0;
int t1,t2;

struct player{
	char P_Name[20];
	int P_C;
	int age;
	float str;
	int lts;
}p[3][4];

struct team{
	char T_Name[20];
	int T_C;
	int tst;
	int t20;
	int odi;
}tm[3];


int main()
{
	Layout();
	Page1();
	mainMenu();
}

void mainMenu()
{
	int v;
	system("cls");
	system("color 4E");
	if(a == 0)
	{
		Main();
		a++;
	}
	else
		Main1();
	printf("\t\t\t\t\t*************\n");
	printf("\t\t\t\t\t* MAIN MENU *\n");
	printf("\t\t\t\t\t*************\n");
	

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
	fflush(stdin);
	scanf("%d",&v);
	
	if(v == 1)
	{
		system("color 1F");
		saving();
	}
	
	if(v == 2)
	{
		system("cls");
		system("color 3F");
		editing();
		//printf("This menu is not available right now\n");
		GoBack();
	}
	
	if(v == 3)
	{
		system("color 3e");
		viewing();
	}
	
	if(v == 4)
	{
		system("color 5B");
		NewMatch();
	}
	
	if(v == 5)
	{
		system("cls");
		system("color 5F");
		printf("Do you want to exit (y/n)\t");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='y'||c=='Y')
			exit(0);
		else
			mainMenu();
	}
	
	if(v!=1 && v!=2 && v!=3 && v!=4)
	{
		system("cls");
		fflush(stdin);
		printf("Invalid input press any key to restart\n");
		fflush(stdin);
		getch();
		mainMenu();
	}
}

void saving(void)
{
	system("cls");
	int v;
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\t\t\t\t\tSAVING MENU\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("____________________________________________________________________________________________________\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("Select any of following:\n\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\t1. Create Player\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\t2. Create Team");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n\t3. Back to Main Menu");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n\nEnter Your Selection:\t");
	fflush(stdin);
	scanf("%d",&v);
	if(v==1)
	{
		system("cls");
		printf("\t\t\t\t\tPLAYER PROFILE MENU\n");
		printf("____________________________________________________________________________________________________\n");
		playerRecord();
	}
	if(v==2)
	{
		system("cls");
		printf("\t\t\t\t\tTEAM PROFILE MENU\n");
		printf("____________________________________________________________________________________________________\n");
		teamRecord();
	}
	if(v==3)
	{
		mainMenu();
	}
	else
	{
		system("cls");
		fflush(stdin);
		printf("Invalid input press any key to re-input\n");
		fflush(stdin);
		getch();
		saving();
	}
}

void playerRecord(void)
{
	float a;
	char T[20];
	FILE *g = fopen("cricketTeams.txt","r");
	if (g == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
        fflush(stdin);
        getch();
		exit(0);
    }
	fread(&tm[0],sizeof(tm[0]),1,g);

    fclose(g);
    
    FILE *h = fopen("cricketPlayers.txt","r");
	if (h == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
        fflush(stdin);
        getch();
		exit(0);
    }
    
	fread(&p,sizeof(p),1,h);
	
	if(strlen(tm[0].T_Name) == 0)
		{
			printf("\nNo Team to select\nFirst create a team\n");
			printf("____________________________________________________________________________________________________\n");
			GoBack();
		}
	int i,t;
	
	
	for(t=0;t<3;t++)
	{
		printf("\t\t\t\t\t      TEAM %s\n",tm[t].T_Name);
		printf("____________________________________________________________________________________________________\n");
		for(i=0;i<4;i++)
		{
			printf("\t\t\t\t\t     PLAYER %d\n",i+1);
			printf("____________________________________________________________________________________________________\n");
			
			printf("Player code:\t\t\t\t");
			p[t][i].P_C = i+1;
			printf("%d\n",p[t][i].P_C);
			
			printf("Player Name:\t\t\t\t");
			fflush(stdin);
			gets(p[t][i].P_Name);
			
			printf("Player age:\t\t\t\t");
			fflush(stdin);
			scanf("%d",&p[t][i].age);
			
			printf("Player Strike Rate:\t\t\t");
			fflush(stdin);
			scanf("%f",&p[t][i].str);
			
			printf("Player Life Time score:\t\t\t");
			fflush(stdin);
			scanf("%d",&p[t][i].lts);
			printf("\n____________________________________________________________________________________________________\n");
			
			int c=0;
			while(1)
			{
				if(i>=3)
					break;
				if(i<3)
				{
					char check;
					printf("Do You Want To Input Another Player(y/n)\t");
					fflush(stdin);
					scanf("%c",&check);
						if(check == 'n' ||check =='N')
						{
							printf("____________________________________________________________________________________________________\n");
							c=-1;
							break;
						}
						if(check == 'y' || check == 'Y')
						{
							printf("____________________________________________________________________________________________________\n");
							break;
						}
						else
						{
							printf("\nINVALID INPUT");
							printf("\n");
							continue;
						}
					printf("____________________________________________________________________________________________________\n");
				}
			}
			if(c == -1)
				break;
		}
		
		int c=0;
			while(1)
			{
				if(t>=2)
					break;
				if(t<2)
				{
					char check;
					printf("Do You Want To Input Another Team(y/n)\t");
					fflush(stdin);
					scanf("%c",&check);
					printf("____________________________________________________________________________________________________\n");
						if(check == 'n' ||check =='N')
						{
							c=-1;
							break;
						}
						if(check == 'y' || check == 'Y')
						{
							break;
						}
						else
						{
							printf("\nINVALID INPUT");
							printf("\n");
							continue;
						}
					printf("____________________________________________________________________________________________________\n");
				}
			}
			if(c == -1)
				break;
	}
	FILE *f = fopen("cricketPlayers.txt","w");
	if (f == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
        fflush(stdin);
        getch();
		exit(0);
    }
    
	fwrite(&p,sizeof(p),1,f);
	fclose(f);
	GoBack();
}


void teamRecord(void)
{
	FILE *f = fopen("cricketTeams.txt","w");
	if (f == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
		exit(0);
    }
	
	int i;
	for(i=0;i<3;i++)
	{
		printf("\t\t\t\t\t      TEAM %d\n",i+1);
		printf("____________________________________________________________________________________________________\n");
		
		printf("Team Code:\t\t\t\t");
		tm[i].T_C = i+100;
		printf("%d\n",tm[i].T_C);
		
		printf("Name of team:\t\t\t\t");
		fflush(stdin);
		gets(tm[i].T_Name);
		
		printf("Test played:\t\t\t\t");
		fflush(stdin);
		scanf("%d",&tm[i].tst);
		
		printf("T-20 played:\t\t\t\t");
		fflush(stdin);
		scanf("%d",&tm[i].t20);
		
		printf("ODI played:\t\t\t\t");
		fflush(stdin);
		scanf("%d",&tm[i].odi);
		printf("\n");
		printf("____________________________________________________________________________________________________\n");
		
		int c=0;
			while(1)
			{
				if(i>=2)
					break;
				if(i<2)
				{
					char check;
					printf("Do You Want To Enter Another Team(y/n)\t");
					fflush(stdin);
					scanf("%c",&check);
					printf("____________________________________________________________________________________________________\n");
						if(check == 'n' ||check =='N')
						{
							c=-1;
							break;
						}
						if(check == 'y' || check == 'Y')
						{
							break;
						}
						else
						{
							printf("\n\nINVALID INPUT");
							continue;
						}
					printf("____________________________________________________________________________________________________\n");
				}
			}
			if(c == -1)
				break;
			
	}
	fwrite(&tm,sizeof(tm),1,f);
	fclose(f);
	GoBack();
}


void viewing(void)
{
	int v;
	system("cls");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("____________________________________________________________________________________________________\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\t\t\t\t\t  VIEWING MENU\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("____________________________________________________________________________________________________\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("What do you want to view:\n\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\t1. Players Profile");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n\t2. Teams Profile");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n\t3. Back to Main Menu");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n\nEnter Your Selection:\t");
	scanf("%d",&v);
	
	if(v==1)
	{
		printPlayer();
	}
	if(v==2)
	{
		printTeam();
	}
	if(v==3)
	{
		mainMenu();
	}
	else
	{
		system("cls");
		fflush(stdin);
		printf("Invalid input press any key to re-input\n");
		fflush(stdin);
		getch();
		viewing();
	}
}


void printPlayer(void)
{
	system("cls");
	printf("\t\t\t\t\t   PLAYER DETAILS\n\n");
	printf("____________________________________________________________________________________________________\n");
	
	FILE *f = fopen("cricketPlayers.txt","r");
	if (f == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
		exit(0);
    }
    
	fread(&p,sizeof(p),1,f);
    
	fclose(f);
	
	FILE *g = fopen("cricketTeams.txt","r");
	if (g == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
		exit(0);
    }
    
	fread(&tm,sizeof(tm),1,g);
    
	fclose(g);
	
	int i,j,k;

	for(i=0;i<3;i++)
	{
		printf("\t\t\t\t\t      TEAM %s\n",tm[i].T_Name);
		system("ping 127.0.0.1 -n 1 > nul");
		printf("____________________________________________________________________________________________________\n");
		system("ping 127.0.0.1 -n 1 > nul");
		printf("NAME\t\tID\tAGE\tSTRIKE RATE\tTOTAL SCORE\n");
		system("ping 127.0.0.1 -n 1 > nul");
	
		for(j=0;j<4;j++)
		{
			system("ping 127.0.0.1 -n 1 > nul");
			printf("%s\t",p[i][j].P_Name);
				if(strlen(p[i][j].P_Name)<=7)
				{
					printf("\t");
				}
			
				printf("%d\t",p[i][j].P_C);
				printf("%d\t",p[i][j].age);
				printf("%.2f\t",p[i][j].str);
				printf("\t%d\t",p[i][j].lts);
			
			printf("\n");
			
		}
		if(i<2)
			printf("____________________________________________________________________________________________________\n");
	}
	printf("____________________________________________________________________________________________________\n");
	
	GoBack();
}


void printTeam(void)
{
	FILE *f = fopen("cricketTeams.txt","r");
	if (f == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
		exit(0);
    }
    
	
	int x;
	
	fread(&tm,sizeof(tm),1,f);
    fclose(f);
	
	int a;
	system("cls");
	printf("\t\t\t\t\tTEAM DETAILS\n\n");
	printf("____________________________________________________________________________________________________\n");
	printf("Team NAME\tCODE\tTest Played\tODI Played\tT-20 Played\n");
	int i,j;
	
	for(i=0;i<3;i++)
	{
		system("ping 127.0.0.1 -n 1 > nul");
		printf("%s\t",tm[i].T_Name);
			if(strlen(tm[i].T_Name)<7)
			{
				printf("\t");
			}
		
			printf("%d\t",tm[i].T_C);
			printf("%d\t\t",tm[i].tst);
			printf("%d\t\t",tm[i].odi);
			printf("%d",tm[i].t20);
		
		printf("\n");
	}
	printf("____________________________________________________________________________________________________\n");
	
	
		char check;
		printf("\nEnter \"y\" to view Team details\t");
		fflush(stdin);
		scanf("%c",&check);
	
	if(check == 'y' || check == 'Y')
	{
		while(1)
		{
			printf("\nEnter Team code to view details:\t");
			fflush(stdin);
			scanf("%d",&a);
			if(a == tm[0].T_C)
			{
				printTP(a);
			}
			if(a == tm[1].T_C)
			{
				printTP(a);
			}
			if(a == tm[2].T_C)
			{
				printTP(a);
				
			}
			if(a!=tm[0].T_C && a!=tm[1].T_C && a!=tm[2].T_C)
			{
				printf("\nInvalid code..!!!!");
				continue;
			}
		}
	}
	else
	{
		GoBack();
	}
	
}


void printTP(int cod)
{
	FILE *g = fopen("cricketTeams.txt","r");
	if (g == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
		exit(0);
    }
	FILE *f = fopen("cricketPlayers.txt","r");
	if (f == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
		exit(0);
    }
    
	fread(&tm,sizeof(tm),1,g);
	fread(&p,sizeof(p),1,f);
    
	fclose(f);
	
	int i,j,k;
	
	if(cod == tm[0].T_C)
		i=0;
	if(cod == tm[1].T_C)
		i=1;
	if(cod == tm[2].T_C)
		i=2;
	
	printf("____________________________________________________________________________________________________\n");
	printf("\t\t\t\t\tTEAM\t");
	printf("%s\n",tm[i].T_Name);
	printf("____________________________________________________________________________________________________\n");
	printf("NAME\t\tTEAM\t\tID\tAGE\tSTRIKE RATE\tTOTAL SCORE\n");

	for(j=0;j<4;j++)
	{
		system("ping 127.0.0.1 -n 1 > nul");
		printf("%s\t",p[i][j].P_Name);
			if(strlen(p[i][j].P_Name)<=7)
			{
				printf("\t");
			}
		
		printf("%s\t",tm[i].T_Name);
			if(strlen(tm[i].T_Name)<7)
			{
				printf("\t");
			}
			
			printf("%d\t",p[i][j].P_C);
			printf("%d\t",p[i][j].age);
			printf("%.2f\t",p[i][j].str);
			printf("\t%d\t",p[i][j].lts);
		
		printf("\n");
		
	}
	printf("____________________________________________________________________________________________________\n");
	
	GoBack();
}


void GoBack(void)
{
	printf("\nPress Any Key To Go Back TO Main Menu\t");
	fflush(stdin);
	getch();
	mainMenu();
}


void NewMatch(void)
{
	system("cls");
	
	FILE *f = fopen("cricketTeams.txt","r");
	if (f == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
		exit(0);
    }
	
	fread(&tm,sizeof(tm),1,f);
    fclose(f);
	
	printf("\t\t\t\t\tNew Match Menu\n");
	printf("____________________________________________________________________________________________________\n");
	
	if(strlen(tm[0].T_Name) == 0)
	{
		printf("\nNo Team to select\nFirst create a team\n");
		printf("____________________________________________________________________________________________________\n");
		GoBack();
	}
		
	if((strlen(tm[0].T_Name) == 0 && strlen(tm[1].T_Name) == 0) || (strlen(tm[0].T_Name) == 0 && strlen(tm[2].T_Name) == 0) || (tm[1].T_Name) == 0 && strlen(tm[3].T_Name) == 0)
	{
		printf("\nAtleast two are required for match\n");
		printf("____________________________________________________________________________________________________\n");
		GoBack();
	}
	
	printf("Select any two teams\n");
	
	int j,n1,n2;
		printf("\nTeam Code\t\tTeam Name\n");
		for(j=0;j<3;j++)
		{
			printf("%d\t\t\t",tm[j].T_C);
			printf("%s\n",tm[j].T_Name);
		}
		
	while(1)
	{
		int s1,s2;
		printf("\nEnter code of team 1:\t");
		fflush(stdin);
		scanf("%d",&n1);
		printf("Enter code of team 2:\t");
		fflush(stdin);
		scanf("%d",&n2);
	
		if((n1 == 100 || n1 == 101 || n1 == 102) && (n2 == 100 || n2 == 101 || n2 == 102))
		{
			int a;
			fflush(stdin);
			srand(time(NULL));
			a=1+(rand()%(4+1-1));
				
			if(n1==n2)
			{
				printf("\nEnter code of two different teams");
				continue;
			}
			else
			{
				system("cls");
				
				printf("Loading Match Data\n");
				
				int k;
				
				system("ping 127.0.0.1 -n 2 > nul");
				for(k=0;k<33;k++)
				{
					if(k<32)
					{
					printf("%c%c%c",177,177,177);
					system("ping 127.0.0.1 -n 1 > nul");
					}
					if(k==32)
					{
					printf("%c%c%c%c",177,177,177,177);
					system("ping 127.0.0.1 -n 1 > nul");
					}
				}
				
				system("cls");
				int over = MatchType();
				
				system("cls");
				printf("\nWait a few seconds for toss.....\n");
				system("ping 127.0.0.1 -n 3 > nul");
				system("cls");
				if((n1==100 && n2==102)||(n1==102 && n2==100))
				{
					if(a==1)
					{
						printf("\n%s won the toss and elected to bat first.",tm[0].T_Name);
						t1=0;
						t2=2;
					}
					if(a==2)
					{
						printf("\n%s won the toss and elected to field first.",tm[0].T_Name);
						t1=2;
						t2=0;
					}
					if(a==3)
					{
						printf("\n%s won the toss and elected to bat first.",tm[2].T_Name);
						t1=2;
						t2=0;
					}
					if(a==4)
					{
						printf("\n%s won the toss and elected to field first.",tm[2].T_Name);
						t1=0;
						t2=2;
					}
				}
				if((n1==100 && n2==101)||(n1==101 && n2==100))
				{
					if(a==1)
					{
						printf("\n%s won the toss and elected to bat first.",tm[0].T_Name);
						t1=0;
						t2=2;
					}
						if(a==2)
					{
						printf("\n%s won the toss and elected to field first.",tm[0].T_Name);
						t1=1;
						t2=0;
					}
					if(a==3)
					{
						printf("\n%s won the toss and elected to bat first.",tm[1].T_Name);
						t1=1;
						t2=0;
					}
					if(a==4)
					{
						printf("\n%s won the toss and elected to field first.",tm[1].T_Name);
						t1=0;
						t2=1;
					}
				}
				if((n1==101 && n2==102)||(n1==102 && n2==101))
				{
					if(a==1)
					{
						printf("\n%s won the toss and elected to bat first.",tm[2].T_Name);
						t1=2;
						t2=1;
					}
						if(a==2)
					{
						printf("\n%s won the toss and elected to field first.",tm[2].T_Name);
						t1=1;
						t2=2;
					}
					if(a==3)
					{
						printf("\n%s won the toss and elected to bat first.",tm[1].T_Name);
						t1=1;
						t2=2;
					}
					if(a==4)
					{
						printf("\n%s won the toss and elected to field first.",tm[1].T_Name);
						t1=2;
						t2=1;
					}
				}
				
				system("ping 127.0.0.1 -n 3 > nul");
				
				s1 = PlayMatch(over,n1,n2,a);
				printf("\n\nScore of team :\t%d\n",s1);
				fflush(stdin);
				system("ping 127.0.0.1 -n 3 > nul");
				system("cls");
				s2 = Score2(over,s1);
				printf("\n\nScore of team 2:\t%d\n\n",s2);
				system("ping 127.0.0.1 -n 3 > nul");
				result(s1,s2);
				GoBack();
				
			}
			
		}
		else
		{
			printf("\nNo option is avaliabe for this number\nRe-enter your selection from above list\n");
			continue;
		}
	}
}
void Layout(void)
{
	system("mode con: cols=100 lines=60");
	system("title Final project of BSE(C) TECH-GEEKS (Bilal Khalid (027) and Faizan Haider (108)) ");
}
void Main(void)
{
	int l;
	for(l=0;l<10;l++)
	{
		printf("**********");
		system("ping 127.0.0.1 -n 1 > nul");
	}
	printf("\t\t\t\t\tWELCOME TO CRICKET STATS\n");
	int j;
	for(j=0;j<10;j++)
	{
		printf("**********");
		system("ping 127.0.0.1 -n 1 > nul");
	}
	printf("\n");
}

void Main1(void)
{
	int l;
	for(l=0;l<10;l++)
	{
		printf("**********");
	}
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\t\t\t\t\tWELCOME TO CRICKET STATS\n");
	int j;
	for(j=0;j<10;j++)
	{
		printf("**********");
	}
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n");
}

int MatchType(void)
{
	
	system("color 2F");
	int type=0,over=0;
	int l,j;
	for(l=0;l<10;l++)
	{
		printf("**********");
	}
	printf("\t\t\t\t\t  MATCH TYPE\n");
	for(j=0;j<10;j++)
	{
		printf("**********");
	}
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\nSelect match type:\n\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("1. T-20 match.\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n2. ODI match\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n3. To go back.\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\nEnter your selection:\t");
	fflush(stdin);
	scanf("%d",&type);

	if(type==1)
	{
		over=20;
	}
	if(type==2)
	{
		over=50;
	}
	if(type==3)
	{
		over=0;
		GoBack();
	}
	if(type != 1 && type != 2 && type != 3)
	{
		fflush(stdin);
		printf("Invalid input press any key to restart\n");
		fflush(stdin);
		getch();
		system("cls");
		MatchType();
	}
	
	return over;
}

int PlayMatch(int over,int n1, int n2, int a)
{
	if(over==0)
	{
		MatchMenu();
	}
	else
	{
		system("cls");
		return Score1(over,n1,n2,a);
	}
}

int Score1(int over, int n1, int n2, int a)
{
	system("color F5");
	int z,wicket1=0;
	int s1=0;
	
	if((n1==100 && n2==102)||(n1==102 && n2==100))
	{
		if(a==1)
		{
			printf("\t\t\t\t\tData of team %s\n",tm[0].T_Name);
		}
			if(a==2)
		{
			printf("\t\t\t\t\tData of team %s\n",tm[2].T_Name);
		}
		if(a==3)
		{
			printf("\t\t\t\t\tData of team %s\n",tm[2].T_Name);
		}
		if(a==4)
		{
			printf("\t\t\t\t\tData of team %s\n",tm[0].T_Name);
		}
	}
	if((n1==100 && n2==101)||(n1==101 && n2==100))
	{
		if(a==1)
		{
			printf("\t\t\t\t\tData of team %s\n",tm[0].T_Name);
		}
			if(a==2)
		{
			printf("\t\t\t\t\tData of team %s\n",tm[1].T_Name);
		}
		if(a==3)
		{
			printf("\t\t\t\t\tData of team %s\n",tm[1].T_Name);
		}
		if(a==4)
		{
			printf("\t\t\t\t\tData of team %s\n",tm[0].T_Name);
		}
	}
	if((n1==101 && n2==102)||(n1==102 && n2==101))
	{
		if(a==1)
		{
			printf("\t\t\t\t\tData of team %s\n",tm[2].T_Name);
		}
			if(a==2)
		{
			printf("\t\t\t\t\tData of team %s\n",tm[1].T_Name);
		}
		if(a==3)
		{
			printf("\t\t\t\t\tData of team %s\n",tm[1].T_Name);
		}
		if(a==4)
		{
			printf("\t\t\t\t\tData of team %s\n",tm[2].T_Name);
		}
	}
	
	system("ping 127.0.0.1 -n 2 > nul");
	printf("Match of %d overs\n",over);
	system("ping 127.0.0.1 -n 3 > nul");
	int j,c=0;
	float b=0,d;
	for(j=0;j<over;j++)
	{
		fflush(stdin);
		srand(time(NULL));
		d=(0+(rand()%(35-0+1)))/10.0;
		if(d<3.2)
		{
			wicket1=0;
		}
		else
		{
			wicket1=1;
		}
		
		b=(0+(rand()%(10-0+1)))/10;
		if(b<=.7)
		{
			fflush(stdin);
			srand(time(NULL));
			z=0+(rand()%(10-0+1));
			
			w1+=wicket1;
			s1=s1+z;
			
			gotoxy(0,58);
			printf("Result: %d/%d\t Over: %d/%d",s1,w1,j+1,over);
			gotoxy(0, j+2);
			printf("\nScore of over %.2d:\t%.2d\tWickets:\t%d",j+1,z,wicket1);
			system("ping 127.0.0.1 -n 2 > nul");
			
			if(w1==4)
			{
				c=1;
				break;
			}
		}
		else
		{
			
			z=11+(rand()%(36-11+1));
			
			
			w1+=wicket1;
			s1=s1+z;
			
			gotoxy(0,58);
			printf("Result: %d/%d\t Over: %d/%d",s1,w1,j+1,over);
			gotoxy(0, j+2);
			printf("\nScore of over %.2d:\t%.2d\tWickets:\t%d",j+1,z,wicket1);
			system("ping 127.0.0.1 -n 2 > nul");
			
			if(w1==4)
			{
				c=1;
				break;
			}
		}
		if(c==1)
		{
			break;
		}
	}
	
	FILE* g=fopen("cricketTeams.txt","r");
	if (g == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
        fflush(stdin);
        getch();
		exit(0);
    }
    fread(&tm,sizeof(tm),1,g);
	fclose(g);
	
	if(over == 20)
	{
		tm[t1].t20 +=1;
	}
	if(over == 50)
	{
		tm[t1].odi +=1;
	}
	FILE* f=fopen("cricketTeams.txt","w");
	if (f == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
        fflush(stdin);
        getch();
		exit(0);
    }
    fwrite(&tm,sizeof(tm),1,f);
	fclose(f);
	
	return s1;
}

int Score2(int over,int s1)
{
	int S1;
	int z,wicket2=0;
	s2=0;
	system("color 5C");
	
	
	printf("\t\t\t\t\tData of team %s\n",tm[t2].T_Name);
	system("ping 127.0.0.1 -n 2 > nul");
	printf("Match of %d overs\n",over);
	system("ping 127.0.0.1 -n 3 > nul");
	int j,c=0;
	float b,d;
	for(j=0;j<over;j++)
	{
		fflush(stdin);
		srand(time(NULL));
		d=(0+(rand()%(35-0+1)))/10.0;
		if(d<3.2)
		{
			wicket2=0;
		}
		else
		{
			wicket2=1;
		}
		
		b=(0+(rand()%(10-0+1)))/10.0;
		if(b<=.7)
		{
			fflush(stdin);
			srand(time(NULL));
			z=0+(rand()%(10-0+1));
			
			w2 += wicket2;
			s2=s2+z;
			gotoxy(0,58);
			printf("Result: %d/%d\t Over: %d/%d",s2,w2,j+1,over);
			gotoxy(0, j+2);
			
			printf("\nScore of over %.2d:\t%.2d\tWickets:\t%d",j+1,z,wicket2);
			system("ping 127.0.0.1 -n 2 > nul");
			
			if(s2>s1)
			{
				c=1;
				break;
			}
			if(wicket2==4)
			{
				c=1;
				break;
			}
		}
		else
		{
			z=11+(rand()%(36-11+1));
			
			w2 += wicket2;
			s2=s2+z;
			
			gotoxy(0,58);
			printf("Result: %d/%d\t Over: %d/%d",s2,w2,j+1,over);
			gotoxy(0, j+2);
			
			printf("\nScore of over %.2d:\t%.2d\tWickets:\t%d",j+1,z,wicket2);
			system("ping 127.0.0.1 -n 2 > nul");
			
			if(s2>s1)
			{
				c=1;
				break;
			}
			if(wicket2==4)
			{
				c=1;
				break;
			}
		}
		if(c==1)
			break;
	}
	
	FILE* g=fopen("cricketTeams.txt","r");
	if (g == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
        fflush(stdin);
        getch();
		exit(0);
    }
    fread(&tm,sizeof(tm),1,g);
	fclose(g);
	
	if(over == 20)
	{
		tm[t2].t20 +=1;
	}
	if(over == 50)
	{
		tm[t2].odi +=1;
	}
	FILE* f=fopen("cricketTeams.txt","w");
	if (f == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
        fflush(stdin);
        getch();
		exit(0);
    }
    fwrite(&tm,sizeof(tm),1,f);
	fclose(f);
	
	return s2;
}

void result(int S1, int S2)
{
	
	printf("Press any key to get result");
	getch();
	system("cls");
	system("color CF");
	
	printf("\nScore of %s:\t%d\n",tm[t1].T_Name,S1);
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\nWickets of %s:\t%d\n\n",tm[t1].T_Name,w1);
	system("ping 127.0.0.1 -n 2 > nul");
	printf("\nScore of %s:\t%d\n\n",tm[t2].T_Name,S2);
	system("ping 127.0.0.1 -n 1 > nul");
	printf("Wickets of %s:\t%d\n\n",tm[t2].T_Name,w2);
	
	if(S1>S2)
	{
		printf("\n\nRESULT:\t%s won the match by %d runs...!!\n",tm[t1].T_Name,(S1-S2));
	}
	if(S2>S1)
	{
		printf("\n\nRESULT:\t%s won the match by %d wickets...!!\n",tm[t2].T_Name,(10-w2));
	}
	if(S1==S2)
	{
		printf("The Match was a draw...!!\n");
	}
}

void MatchMenu(void)
{
	system("cls");
	system("color 89");
	int k;
	
	for(k=0;k<32;k++)
	{
		if(k<32);
		printf("***");
		if(k==32)
		printf("****");
	}
}

void Page1(void)
{
	int b=0;
	system("color 4F");
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n                       ");
	system("ping 127.0.0.1 -n 1 > nul");
	int i=0;
	for(i;i<6;i++)
	{
		if(i==5)
		{
		printf("*******");
		system("ping 127.0.0.1 -n 1 > nul");
		}
		else
		{
		printf("*********");
		system("ping 127.0.0.1 -n 1 > nul");
		}
	}
	printf("\n                       *                                                  *");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n                       *     ****************************************     *");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n                       *     *                                      *     *");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n                       *     *    Final project of 1st semester     *     *");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n                       *     *             SP17-BSE-(C)             *     *");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n                       *     *          Group: TECH-GEEKS           *     *");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n                       *     *     Bilal Khalid:  SP17-BSE-027      *     *");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n                       *     *     Faizan Haider: SP17-BSE-108      *     *");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n                       *     *                                      *     *");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n                       *     *         Under supervision of         *     *");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n                       *     *       Prof.: Dr.Aksam Iftikhar       *     *");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n                       *     *                                      *     *");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n                       *     ****************************************     *");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n                       *                                                  *");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n                       ");
	int j=0;
	for(j;j<6;j++)
	{
		if(j==5)
		{
		printf("*******");
		system("ping 127.0.0.1 -n 1 > nul");
		}
		else
		{
		printf("*********");
		system("ping 127.0.0.1 -n 1 > nul");
		}
	}
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nCopyrights are reserved at TECH-GEEK to purchase it in full form please contact to the company...\nContact numbers : 0314-4209047,0331-4230885");
	
	system("ping 127.0.0.1 -n 6 > nul");
	system("cls");
	system("color 1D");
	/*printf("\n1. To view project\n\n2. To exit\n\nEnter your selection:\t");
	scanf("%d",&b);
	if(b==1)
	{
		mainMenu();
	}
	if(b==2)
	{
		system("cls");
		system("color FC");
		printf("Do you want to exit (y/n)\t");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='y'||c=='Y')
			exit(0);
		else
			mainMenu();
	}*/
}

void editing(void)
{
	system("cls");
	int v;
	system("cls");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\t\t\t\t\tEDITING MENU\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("____________________________________________________________________________________________________\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("What do you want to edit:\n\n");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\t1. Players Profile");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n\t2. Teams Profile");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n\t3. Back to Main Menu");
	system("ping 127.0.0.1 -n 1 > nul");
	printf("\n\nEnter Your Selection:\t");
	scanf("%d",&v);
	
	if(v==1)
	{
		editPlayer();
	}
	if(v==2)
	{
		editTeam();
	}
	if(v==3)
	{
		mainMenu();
	}
	else
	{
		system("cls");
		fflush(stdin);
		printf("Invalid input press any key to re-input\n");
		fflush(stdin);
		getch();
		viewing();
	}
	
}

void editPlayer(void)
{
	system("cls");
	printf("\t\t\t\t\tPLAYER EDITING MENU");
	printf("\n____________________________________________________________________________________________________\n");
	
	FILE* g=fopen("cricketTeams.txt","r");
	if (g == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
        fflush(stdin);
        getch();
		exit(0);
    }
    fread(&tm,sizeof(tm),1,g);
	fclose(g);
	
	FILE* f=fopen("cricketPlayers.txt","r");
	if (f == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
        fflush(stdin);
        getch();
		exit(0);
    }
    fread(&p,sizeof(p),1,f);
    fclose(f);
    
    int t,i,j,a,b;
    printf("\nTeam Code\t\tTeam Name\n");
	for(j=0;j<3;j++)
	{
		printf("%d\t\t\t",tm[j].T_C);
		printf("%s\n",tm[j].T_Name);
	}
    
    while(1)
	{
		printf("\nEnter player\'s team code:\t");
		fflush(stdin);
		scanf("%d",&a);
		if(a == tm[0].T_C)
		{
			t=0;
			break;		
		}
		if(a == tm[1].T_C)
		{
			t=1;
			break;
		}
		if(a == tm[2].T_C)
		{
			t=2;
			break;
			
		}
		if(a!=tm[0].T_C && a!=tm[0].T_C && a!=tm[0].T_C)
		{
			printf("\nInvalid code..!!!!");
			continue;
		}
	}
	
	printf("\nPlayer Code\t\tPlayer Name\n");
	for(j=0;j<4;j++)
	{
		printf("%d\t\t\t",p[t][j].P_C);
		printf("%s\n",p[t][j].P_Name);
	}
	
	while(1)
	{
		printf("\nEnter player\'s code:\t");
		fflush(stdin);
		scanf("%d",&b);
		if(b == p[t][0].P_C)
		{
			i=0;
			break;		
		}
		if(b == p[t][1].P_C)
		{
			i=1;
			break;
		}
		if(b == p[t][2].P_C)
		{
			i=2;
			break;
		}
		if(b == p[t][3].P_C)
		{
			i=3;
			break;
		}
		if(b!=p[t][0].P_C && b!=p[t][1].P_C && b!=p[t][2].P_C && b!=p[t][3].P_C)
		{
			printf("\nInvalid code..!!!!");
			continue;
		}
	}
	
	printf("\t\t\t\t\t      TEAM %s\n",tm[t].T_Name);
	printf("____________________________________________________________________________________________________\n");
	
	printf("\t\t\t\t\t     PLAYER %d\n",i+1);
	printf("____________________________________________________________________________________________________\n");
	
	printf("Player code:\t\t\t\t");
	p[t][i].P_C = i+1;
	printf("%d\n",p[t][i].P_C);
	
	printf("Player Name:\t\t\t\t");
	fflush(stdin);
	gets(p[t][i].P_Name);
	
	printf("Player age:\t\t\t\t");
	fflush(stdin);
	scanf("%d",&p[t][i].age);
	
	printf("Player Strike Rate:\t\t\t");
	fflush(stdin);
	scanf("%f",&p[t][i].str);
	
	printf("Player Life Time score:\t\t\t");
	fflush(stdin);
	scanf("%d",&p[t][i].lts);
	printf("\n____________________________________________________________________________________________________\n");

	FILE* h=fopen("cricketPlayers.txt","w");
	if (h == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
        fflush(stdin);
        getch();
		exit(0);
    }
	fwrite(&p,sizeof(p),1,h);
	fclose(h);
    printf("\n\nRECORD EDITED\n\n\n");
    GoBack();
}

void editTeam(void)
{
	system("cls");
	printf("\t\t\t\t\tTEAM EDITING MENU");
	printf("\n____________________________________________________________________________________________________\n");
	
	FILE* g=fopen("cricketTeams.txt","r");
	if (g == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
        fflush(stdin);
        getch();
		exit(0);
    }
    fread(&tm,sizeof(tm),1,g);
	fclose(g);
	
	int i,j,a;
    printf("\nTeam Code\t\tTeam Name\n");
	for(j=0;j<3;j++)
	{
		printf("%d\t\t\t",tm[j].T_C);
		printf("%s\n",tm[j].T_Name);
	}
    
    while(1)
	{
		printf("\nEnter team\'s code:\t");
		fflush(stdin);
		scanf("%d",&a);
		if(a == tm[0].T_C)
		{
			i=0;
			break;		
		}
		if(a == tm[1].T_C)
		{
			i=1;
			break;
		}
		if(a == tm[2].T_C)
		{
			i=2;
			break;
			
		}
		if(a!=tm[0].T_C && a!=tm[0].T_C && a!=tm[0].T_C)
		{
			printf("\nInvalid code..!!!!");
			continue;
		}
	}
	
	printf("\t\t\t\t\t      TEAM %d\n",i+1);
	printf("____________________________________________________________________________________________________\n");
	
	printf("Team Code:\t\t\t\t");
	tm[i].T_C = i+100;
	printf("%d\n",tm[i].T_C);
	
	printf("Name of team:\t\t\t\t");
	fflush(stdin);
	gets(tm[i].T_Name);
	
	printf("Test played:\t\t\t\t");
	fflush(stdin);
	scanf("%d",&tm[i].tst);
	
	printf("T-20 played:\t\t\t\t");
	fflush(stdin);
	scanf("%d",&tm[i].t20);
	
	printf("ODI played:\t\t\t\t");
	fflush(stdin);
	scanf("%d",&tm[i].odi);
	printf("\n");
	printf("____________________________________________________________________________________________________\n");
	
	FILE* f=fopen("cricketTeams.txt","w");
	if (f == NULL)
	{
        printf("Failed to open file\n");
        printf("Press any key to exit\t");
        fflush(stdin);
        getch();
		exit(0);
    }
    fwrite(&tm,sizeof(tm),1,f);
	fclose(f);
	
}
