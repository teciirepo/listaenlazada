#include <stdio.h>
#include <stdlib.h>

//declaring student structure
typedef struct
{

char stnumber[10];
char stname[20];
char sex;
char carrera[20];
float quizz1;
float quizz2;
float assigment;
float midterm;
float final;
float total;

}student;
//function prototypes
int search(student st[],char id[], int itemcount);
void clean(student st[],int deleteitem);
void displayheading();

//function to display a menu of choices
void displaymenu(){
printf("==================================================\n");
printf("                      MENU \n");
printf("==================================================\n");
printf(" 1.Add student records\n");
printf("==================================================\n");
printf(" 2.Delete student records\n");
printf("==================================================\n");
printf(" 4.View all student records\n");
printf("==================================================\n");
printf(" 8.Find a student by ID\n");
printf("==================================================\n");
}
//function to append a new record
void add_rec(student st[],int *itemcount){

again:
printf("\nEnter student's ID:");
scanf("%s",&st[*itemcount].stnumber);
if(search(st,st[*itemcount].stnumber,*itemcount)!=-1)
{
printf("This ID already exists\n");
goto again;
}

printf("Enter student's Name:");
scanf("%s",&st[*itemcount].stname);
printf("Enter student's Sex(F or M):");
scanf("%s",&st[*itemcount].sex);
printf("ingresa carrera del alumno:");
scanf("%s",&st[*itemcount].carrera);
printf("Enter student's quizz1 score:");
scanf("%f",&st[*itemcount].quizz1);
printf("Enter student's quizz2 score:");
scanf("%f",&st[*itemcount].quizz2);
printf("Enter student's assigment score:");
scanf("%f",&st[*itemcount].assigment);
printf("Enter student's mid term score:");
scanf("%f",&st[*itemcount].midterm);
printf("Enter student's final score:");
scanf("%f",&st[*itemcount].final);
st[*itemcount].total=st[*itemcount].quizz1+st[*itemcount].quizz2+
st[*itemcount].assigment+st[*itemcount].midterm+st[*itemcount].final;

++(*itemcount);


}

//function to find the location of the record
int search(student st[], char id[],int itemcount){
int found =-1,i;

for (i = 0; i < itemcount && found==-1; i++)
{

if (strcmp(st[i].stnumber,id)==0) found=i;

else found=-1 ;
}

return found;
}



//function to view all records
void viewall(student st[], int itemcount){
int i=0;
displayheading();
while(i<itemcount)
{
if(st[i].stnumber!="")
{
printf("%-2s",st[i].stnumber);
printf("%-17s",st[i].stname);
printf("%-5c",st[i].sex);
printf("%-17s",st[i].carrera);
printf("%-6.1f",st[i].quizz1);
printf("%-6.1f",st[i].quizz2);
printf("%-6.1f",st[i].assigment);
printf("%-6.1f",st[i].midterm);
printf("%-7.1f",st[i]. final);
printf("%-4.1f",st[i].total);
printf("\n");
}
i=i+1;

}


}

void displayheading()
{
printf("ID NAME         SEX     CARRERA           Q1   Q2    As    Mi   Fi   TOTAL \n");
printf("==========================================================================\n");
}

//function to delete record
void delete_rec(student st[], int *itemcount)
{
char id[10];
int index,i;
if (*itemcount > 0)
{
printf("Enter student's ID:");
scanf("%s",id);
index = search(st, id,*itemcount);

if ((index!=-1) && (*itemcount != 0))
{
if (index == (*itemcount-1)) //delete the last record
{

clean(st, index);
--(*itemcount);

printf("The record was deleted.\n");
}
else //delete the first or middle record
{
for (i = index; i < *itemcount-1; i++)
{
st[i] = st[i + 1];
clean(st, *itemcount);
--(*itemcount) ;
}

}

}
else printf("The record doesn't exist.Check the ID and try again.\n");


}
else printf("No record to delete\n");
}

//function to clean deleted record
void clean(student st[],int index)
{
strcpy(st[index].stnumber,"");
strcpy(st[index].stname,"");
st[index].sex =NULL;
strcpy(st[index].carrera,"");
st[index].quizz1 = 0;
st[index].quizz2 = 0;
st[index].assigment = 0;
st[index].midterm = 0;
st[index].final = 0;
st[index].total = 0;

}








//function to find record
void find(student st[], int itemcount)
{
char id[10];
printf("Enter student's ID:");
scanf("%s",&id);

int index=search(st,id,itemcount);
if (index != -1)
{ //display the found record
displayheading();
printf("%-5s",st[index].stnumber);
printf("%-17s",st[index].stname);
printf("%-5c",st[index].sex);
printf("%-17s",st[index].carrera);
printf("%-6.1f",st[index].quizz1);
printf("%-6.1f",st[index].quizz2);
printf("%-6.1f",st[index].assigment);
printf("%-6.1f",st[index].midterm);
printf("%-7.1f",st[index]. final);
printf("%-4.1f",st[index].total);
printf("\n");

}
else printf("The record doesn't exits.\n");

}







//the main function

int main(int argc, char *argv[])
{


student st[20];
int itemcount=0;

//show menu
displaymenu();
int yourchoice;
char confirm;
do
{
printf("Enter your choice(1-4):");
scanf("%d",&yourchoice);

switch(yourchoice){
case 1:add_rec(st, &itemcount);
	break;
case 2:delete_rec(st, &itemcount);
	break;
case 3:viewall(st, itemcount);
	break;
case 4:find(st, itemcount);
	break;
default:printf("invalid\n");
}

printf("Press y or Y to continue:");
scanf("%s",&confirm);
}
while(confirm=='y'||confirm=='Y');
system("PAUSE");
return EXIT_SUCCESS;
}
