
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define Patient struct pat

void add(FILE * fp); //to add to list
FILE * del(FILE * fp);//to delete from list
void modify(FILE * fp);//to modify a record
void displayList(FILE * fp);//display whole list
void BrowseRecord(FILE *fp);//find a particular record
void printChar(char ch,int n);//printing a character ch n times
void frmDelhi(FILE * fp); // to check list of patients from Delhi
void frmors(FILE * fp);// to check list of patients from outside Delhi
void printHead();


// Username= USER
// Password= SDF


struct pat
{
    int id;
    char name[100];
    char bldgrp[10];
    float age;
    char jdate[8];
    char gender[10];
    char Doctor[50];
    char tempadr[200];
    char permadr[200];
    char phone[15];
    char mail[20];
    char condition[50];
};


int main()
{
 FILE * fp;
 Patient p;
int option;
char another;

if((fp=fopen("PatientInfo.txt","rb+"))==NULL) //
{
    if((fp=fopen("PatientInfo.txt","wb+"))==NULL)
       {
           printf("can't open file");
           return 0;
       }
}
char username[10],password[10]; //
printHead();
welcome();
printHead();
printf("\n\t\t Login Screen");
printf("\n\t\t Enter Your Credential");
printf("\n\n\n\t\t Username: ");
scanf("%s",username);
printf("\n\t\tPassword: ");
int i;
i=0;
	do
	{
		password[i] = getch();
		if(password[i] == 13 )//
		{
			break;
		}
		else if(password[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;
		}
		else
		{
			printf("*");
			i++;
		}
	}while(password[i]!=13);
	password[i] = '\0';

if(((strcasecmp(username,"USER"))==0)&&((strcasecmp(password,"SDF")==0)))
{
    while(1)
{
    printHead();
    printf("\n\t\t\t\tMain Menu");
    printf("\n\n\n");//


    printf("\n\n\t\t 1. Add Patient");
    printf("\n\n\t\t 2. Delete Patient");
    printf("\n\n\t\t 3. Modify Patient");
    printf("\n\n\t\t 4. Display Patient List");
    printf("\n\n\t\t 5. Browse Record");
    printf("\n\n\t\t 6. Display Patient Info");
    printf("\n\n\t\t 7. Display Patient Contact Info");
    printf("\n\n\t\t 8. List of Male Patients");
    printf("\n\n\t\t 9. List of Female Patients");
    printf("\n\n\t\t 10. List of Patients From Delhi");
    printf("\n\n\t\t 11. List of Patients From Outside Delhi");
    printf("\n\n\t\t 0. exit");

    printf("\n\n\tEnter Your Option :--> ");
    scanf("%d",&option);
//
    switch(option)
    {
        case 0: return 1;
                break;
        case 1: add(fp);
                break;
        case 2: fp=del(fp);
                break;
        case 3: modify(fp);
                break;
        case 4: displayList(fp);
                break;
        case 5: BrowseRecord(fp);
                break;
        case 6: displaybasic(fp);
                break;
        case 7: basiccontact(fp);
                break;
        case 8: malepat(fp);
                break;
        case 9: femalepat(fp);
                break;
        case 10: frmDelhi(fp);
                break;
        case 11: frmors(fp);
                break;

    default: printf("\n\t\tInvalid entry! Please Try Again.");
                  printf("\n\t\tProgram terminated");
                  getch();
                  exit(0);

    }
}
}
else {
    printf("\n\t\tLogin Failed");
}


return 1;

}

//Welcome Screen

void welcome()
{
    printf("\n\n\t\t\t\t\t  ||| Welcome ||| \n\n\t\t");
    system("pause");
}


//Printing character ch at n times

void printChar(char ch,int n)
{
    while(n--)//
    {
        putchar(ch);
    }
}

//Printing Head Line of the program

void printHead()
  {
      system("cls");
      printf("\t");
      printf("\n\n\t\t");
      printChar('~',16);
      printf("Patient Information System");
      printChar('~',16);
      printf("\n\n\t");

}
// Setting 1)

//ADDING NEW RECORD

void add(FILE * fp)
{
printHead();

printf("\n\t\t\tAdd Patient");
char another='y';
Patient p;

fseek(fp,0,SEEK_END);
while(another=='y'||another=='Y')
{
    printf("\n\n\t\tEnter ID number: ");
    scanf("%d",&p.id);
//
    printf("\n\n\t\tEnter Full Name of Patient: ");
    fflush(stdin);
    fgets(p.name,100,stdin);
    //fgets takes an extra \n character as input
    p.name[strlen(p.name)-1]='\0';


    printf("\n\n\t\tEnter BLOOD GROUP: ");
    fflush(stdin);
    fgets(p.bldgrp,10,stdin);
    //fgets takes an extra \n character as input
    p.bldgrp[strlen(p.bldgrp)-1]='\0';


    printf("\n\n\t\tEnter Gender (M/F): ");
    fflush(stdin);
    fgets(p.gender,10,stdin);
    //fgets takes an extra \n character as input
    p.gender[strlen(p.gender)-1]='\0';

    printf("\n\n\t\tEnter Doctor: ");
    fflush(stdin);
    fgets(p.Doctor,50,stdin);
    p.Doctor[strlen(p.Doctor)-1]='\0';


    printf("\n\n\t\tEnter AGE: ");
    scanf("%f",&p.age);

    printf("\n\n\t\tEnter Present Address: ");
    fflush(stdin);
    fgets(p.tempadr,200,stdin);
    p.tempadr[strlen(p.tempadr)-1]='\0';

    printf("\n\n\t\tEnter Permanent Address: ");
    fflush(stdin);//
    fgets(p.permadr,200,stdin);
    p.permadr[strlen(p.permadr)-1]='\0';

    printf("\n\n\t\tEnter Phone: ");
    fflush(stdin);
    fgets(p.phone,50,stdin);
    p.phone[strlen(p.phone)-1]='\0';

    printf("\n\n\t\tEnter e-mail: ");
    fflush(stdin);
    fgets(p.mail,20,stdin);
    p.mail[strlen(p.mail)-1]='\0';

    printf("\n\n\t\tEnter condition: ");
    fflush(stdin);
    fgets(p.condition,50,stdin);
    p.condition[strlen(p.condition)-1]='\0';

    fwrite(&p,sizeof(p),1,fp);

    printf("\n\n\t\tWant to Enter another Patient info (Y/N)\t");
    fflush(stdin);
    another=getchar();
}
}

// Setting (2)
//DELETING A RECORD FROM LIST

FILE * del(FILE * fp)
{
 printHead();
printf("\n\t\t\t\Delete Patient Record");
Patient p;
int flag=0,tpatid,siz=sizeof(p);
FILE *ft;

if((ft=fopen("tpat.txt","wb+"))==NULL)//
{
    printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
    system("pause");
     return fp;
}

printf("\n\n\tPlease Enter Patient ID to Proceed");
printf("\n\n\t\t\tID No. : ");
scanf("%d",&tpatid);

rewind(fp);


while((fread(&p,siz,1,fp))==1)
{

    if(p.id==tpatid)
    { flag=1;
    printf("\n\tRecord Deleted for");
    printf("\n\n\t\t%s\n\n\t\tPatient of %s\n\n\t\tFor ID No. %d\n\t",p.name,p.Doctor,p.id);
    continue;
    }

    fwrite(&p,siz,1,ft);
}


fclose(fp);
fclose(ft);

remove("PatientInfo.txt");
rename("tpat.txt","PatientInfo.txt");

if((fp=fopen("PatientInfo.txt","rb+"))==NULL)//
{
    printf("ERROR");
    return  NULL;
}

if(flag==0) printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");

printChar('-',65);
printf("\n\t");
system("pause");
return fp;
}

// setting 3)

//MODIFY A RECORD

void modify(FILE * fp)
{
printHead();
printf("\n\t\t\t\Modify Patient Record");
Patient p;
int i,flag=0,tpatid,siz=sizeof(p);
float age;

printf("\n\n\tEnter ID Number of Patient to proceed : ");
scanf("%d",&tpatid);

rewind(fp);

while((fread(&p,siz,1,fp))==1)
{
    if(p.id==tpatid)
        {flag=1;//
        break;
        }
}

if(flag==1)
    {
    fseek(fp,-siz,SEEK_CUR);
    printf("\n\n\t\tRecord Found");
    printf("\n\n\t\tEnter New Data for the Record");

     printf("\n\n\t\tEnter ID number: ");
    scanf("%d",&p.id);

    printf("\n\n\t\tEnter Full Name of Patient: ");
    fflush(stdin);
    fgets(p.name,100,stdin);
    //fgets takes an extra \n character as input
    p.name[strlen(p.name)-1]='\0';//


    printf("\n\n\t\tEnter Blood Group: ");
    fflush(stdin);
    fgets(p.bldgrp,10,stdin);
    //fgets takes an extra \n character as input
    p.bldgrp[strlen(p.bldgrp)-1]='\0';


    printf("\n\n\t\tEnter Gender (M/F): ");
    fflush(stdin);
    fgets(p.gender,10,stdin);
     //fgets takes an extra \n character as input
    p.gender[strlen(p.gender)-1]='\0';

    printf("\n\n\t\tEnter Doctor: ");
    fflush(stdin);
    fgets(p.Doctor,50,stdin);
    p.Doctor[strlen(p.Doctor)-1]='\0';


    printf("\n\n\t\tEnter Age: ");
    scanf("%f",&p.age);

    printf("\n\n\t\tEnter Present Address: ");
    fflush(stdin);
    fgets(p.tempadr,200,stdin);
    p.tempadr[strlen(p.tempadr)-1]='\0';

    printf("\n\n\t\tEnter Permanent Address: ");
    fflush(stdin);
    fgets(p.permadr,200,stdin);//
    p.permadr[strlen(p.permadr)-1]='\0';

    printf("\n\n\t\tEnter Phone: ");
    fflush(stdin);
    fgets(p.phone,50,stdin);
    p.phone[strlen(p.phone)-1]='\0';

    printf("\n\n\t\tEnter e-mail: ");
    fflush(stdin);
    fgets(p.mail,20,stdin);
    p.mail[strlen(p.mail)-1]='\0';

    printf("\n\n\t\tEnter condition: ");
    fflush(stdin);
    fgets(p.condition,20,stdin);
    p.condition[strlen(p.condition)-1]='\0';


    fwrite(&p,sizeof(p),1,fp);//
}

else printf("\n\n\tERROR! RECORD NOT FOUND.");

printf("\n\n\t");
system("pause");

}

//setting 4)
//DISPLAY THE LIST

void displayList(FILE * fp)
{   printHead();
printf("\n\t\t\t\List of Patients");
    Patient p;
    int i,siz=sizeof(p);

    rewind(fp);

    while((fread(&p,siz,1,fp))==1)
    {
        printf("\n\n\t\tPATIENT ID : %d",p.id);//
        printf("\n\n\t\tPATIENT NAME : %s",p.name);
        printf("\n\n\t\tBLOOD GROUP : %s",p.bldgrp);
        printf("\n\n\t\tGENDER : %s",p.gender);
        printf("\n\n\t\tDOCTOR : %s",p.Doctor);
        printf("\n\n\t\tAGE : %.2f",p.age);
        printf("\n\n\t\tPRESENT ADDRESS : %s",p.tempadr);
        printf("\n\n\t\tPERMANANT ADDRESS : %s",p.permadr);
        printf("\n\n\t\tPHONE : %s",p.phone);
        printf("\n\n\t\tE-MAIL : %s",p.mail);
        printf("\n\n\t\tCONDITION:%s\n\n",p.condition);
        printChar('=',65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

// Setting 5)
//Browse Patient

void BrowseRecord(FILE *fp)//
{printHead();
printf("\n\t\t\t\Browse Patient");
int tpatid,flag,siz,i;
Patient p;
char another='y';

siz=sizeof(p);

while(another=='y'||another=='Y')
{
printf("\n\n\tEnter ID Number of Patient to Browse the record : ");
scanf("%d",&tpatid);

rewind(fp);//

while((fread(&p,siz,1,fp))==1)
{
    if(p.id==tpatid)
        {flag=1;
        break;
        }
}

if(flag==1)
    {
        printf("\n\t\tNAME : %s",p.name);
        printf("\n\n\t\tID : %d",p.id);
        printf("\n\n\t\tBLOOD GROUP : %s",p.bldgrp);
        printf("\n\n\t\tDoctor : %s",p.Doctor);
        printf("\n\n\t\tAGE: %.2f",p.age);
        printf("\n\n\t\tPRESENT ADDRESS : %s",p.tempadr);
        printf("\n\n\t\tPERMANANT ADDRESS : %s",p.permadr);
        printf("\n\n\t\tPHONE : %s",p.phone);
        printf("\n\n\t\tE-MAIL : %s",p.mail);
        printf("\n\n\t\tCONDITION : %s\n",p.condition);

        printChar('=',65);

}
else printf("\n\n\t\t ERROR RECORD NOT FOUND!");


printf("\n\n\t\t Browse Another Record(Y/N)");
fflush(stdin);//
another=getchar();
}
}

// setting 6)
//LIST OF MALE PATIENT

void malepat(FILE * fp)
{
    printHead();
    printf("\n\t\t\t\List of Male Patients");
    Patient p;
    int i,siz=sizeof(p);

    rewind(fp);//

    while((fread(&p,siz,1,fp))==1)
    {
        if((strcmp(p.gender,"M")==0)||(strcmp(p.gender,"m")==0))
        {
//
        printf("\n\n\t\tID : %d",p.id);
        printf("\n\n\t\tNAME : %s",p.name);
        printf("\n\n\t\tBLOOD GROUP : %s",p.bldgrp);
        printf("\n\n\t\tPHONE : %s",p.phone);
        printf("\n\n\t\tCONDITION : %s\n",p.condition);

        printChar('-',65);
        }
    }
    printf("\n\n\n\t");
     printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

// setting 7)
//LIST OF FEMALE PATIENT

void femalepat(FILE * fp)
{
    printHead();
     printf("\n\t\t\t\List of Female Patients");
    Patient p;
    int i,siz=sizeof(p);

    rewind(fp);

    while((fread(&p,siz,1,fp))==1)
    {
        if((strcmp(p.gender,"F")==0)||(strcmp(p.gender,"f")==0))
        {
        printf("\n\n\t\tID : %d",p.id);
        printf("\n\n\t\tNAME : %s",p.name);
        printf("\n\n\t\tBLOOD GROUP : %s",p.bldgrp);
        printf("\n\n\t\tPHONE : %s",p.phone);
        printf("\n\n\t\tCONDITION : %s\n",p.condition);

        printChar('-',65);//
        }
    }
    printf("\n\n\n\t");
     printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

// Setting 8)
//LIST OF PATIENTS FROM DELHI

void frmDelhi(FILE * fp)
{
    printHead();
     printf("\n\t\t\t\List of Patients From Delhi");//
    Patient p;
    int i,siz=sizeof(p);

    rewind(fp);

    while((fread(&p,siz,1,fp))==1)
    {
        if((strcmp(p.permadr,"Delhi")==0)||(strcmp(p.permadr,"delhi")==0)||(strcmp(p.permadr,"DELHI")==0))
        {
        printf("\n\n\t\tID : %d",p.id);
        printf("\n\n\t\tNAME : %s",p.name);
        printf("\n\n\t\tBLOOD GROUP : %s",p.bldgrp);
        printf("\n\n\t\tPHONE : %s",p.phone);
        printf("\n\n\t\tE-MAIL : %s",p.mail);
        printf("\n\n\t\tCONDITION : %s\n",p.condition);

        printChar('=',65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

// Setting 9)
//LIST OF PATIENTS FROM OUTSIDE DELHI

void frmors(FILE * fp)
{
    printHead();
    printf("\n\t\t\t\List of Patient From Outside Delhi");
    Patient p;
    int i,siz=sizeof(p);

    rewind(fp);

    while((fread(&p,siz,1,fp))==1)
    {
        if((strcmp(p.permadr,"Delhi")!=0)&&(strcmp(p.permadr,"delhi")!=0)&&strcmp(p.permadr,"DELHI")!=0)
        {
        printf("\n\n\t\tID : %d",p.id);
        printf("\n\n\t\tNAME : %s",p.name);
        printf("\n\n\t\tBLOOD GROUP : %s",p.bldgrp);
        printf("\n\n\t\tPHONE : %s",p.phone);
        printf("\n\n\t\tE-MAIL : %s",p.mail);
        printf("\n\n\t\tCONDITION : %s\n",p.condition);

        printChar('=',65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

// setting 10)
//DISPLAY BASIC INFO LIST

void displaybasic(FILE * fp)
{   printHead();//
printf("\n\t\t\t\Display Basic Information");
    Patient p;
    int i,siz=sizeof(p);

    rewind(fp);

    while((fread(&p,siz,1,fp))==1)
    {
        printf("\n\n\t\tID : %d",p.id);
        printf("\n\n\t\tNAME : %s",p.name);
        printf("\n\n\t\tBLOOD GROUP : %s",p.bldgrp);
        printf("\n\n\t\tGENDER : %s",p.gender);
        printf("\n\n\t\tDoctor : %s",p.Doctor);
        printf("\n\n\t\tPHONE : %s",p.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t",p.mail);
        printf("\n\n\t\tCONDITION : %s\n\n\t",p.condition);

        printChar('=',65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

// setting 11)
//BASIC CONTACT INFO LIST

void basiccontact(FILE * fp)
{   printHead();
printf("\n\t\t\t\Basic Contact Information");
    Patient p;
    int i,siz=sizeof(p);

    rewind(fp);

    while((fread(&p,siz,1,fp))==1)
    {
        printf("\n\n\t\tID : %d",p.id);
        printf("\n\n\t\tNAME : %s",p.name);
        printf("\n\n\t\tBLOOD GROUP : %s",p.bldgrp);
        printf("\n\n\t\tPHONE : %s",p.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t",p.mail);
        printChar('=',65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

 
 
 
 

 
 
 



