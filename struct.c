#include <stdio.h>
#include <stdlib.h>

//declaracion de la estructura del alumno
typedef struct
{

char stnumber[10];
char stname[20];
char numcontrol[13];
char sex;
char carrera[20];
float quizz1;
float quizz2;
float assigment;
float midterm;
float final;
float total;

}student;
//funciones principales
int search(student st[],char id[], int itemcount);
void clean(student st[],int deleteitem);
void displayheading();

//funcion para mostrar el menu
void displaymenu(){
printf("==================================================\n");
printf("                      MENU \n");
printf("==================================================\n");
printf(" 1.ingresar datos del alumno\n");
printf("==================================================\n");
printf(" 2.eliminar datos del alumno\n");
printf("==================================================\n");
printf(" 3.ver todos los registros\n");
printf("==================================================\n");
printf(" 4.buscar alumno por id\n");
printf("==================================================\n");
}
//funcion para agregar un nuevo registro
void add_rec(student st[],int *itemcount){

again:
printf("\ningresa id del alumno:");
scanf("%s",&st[*itemcount].stnumber);
if(search(st,st[*itemcount].stnumber,*itemcount)!=-1)
{
printf("Este id ya existe\n");
goto again;
}

printf("ingresa el nombre del estudiante:");
scanf("%s",&st[*itemcount].stname);
printf("ingresa el numero de control:");
scanf("%s",&st[*itemcount].numcontrol);
printf("ingresa el sexo del estudiante(F o M):");
scanf("%s",&st[*itemcount].sex);
printf("ingresa carrera del alumno:");
scanf("%s",&st[*itemcount].carrera);
printf("ponderacion de la primera unidad:");
scanf("%f",&st[*itemcount].quizz1);
printf("ponderacion de la segunda unidad:");
scanf("%f",&st[*itemcount].quizz2);
printf("ponderacion de la tercera unidad:");
scanf("%f",&st[*itemcount].assigment);
printf("ponderacion de la cuarta unidad:");
scanf("%f",&st[*itemcount].midterm);
printf("ponderacion de la quinta unidad:");
scanf("%f",&st[*itemcount].final);
st[*itemcount].total=(st[*itemcount].quizz1+st[*itemcount].quizz2+
st[*itemcount].assigment+st[*itemcount].midterm+st[*itemcount].final)/5;

++(*itemcount);


}

//funcion de busqueda
int search(student st[], char id[],int itemcount){
int found =-1,i;

for (i = 0; i < itemcount && found==-1; i++)
{

if (strcmp(st[i].stnumber,id)==0) found=i;

else found=-1 ;
}

return found;
}



//funcion para ver todos los registros
void viewall(student st[], int itemcount){
int i=0;
displayheading();
while(i<itemcount)
{
if(st[i].stnumber!="")
{
printf("%-2s",st[i].stnumber);
printf("%-17s",st[i].stname);
printf("%-13s",st[i].numcontrol);
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
printf("ID NOMBRE             No.Control       SEXO     CARRERA           P1   P2    P3    P4   P5   TOTAL \n");
printf("===================================================================================================\n");
}

//funcion para borrar registro
void delete_rec(student st[], int *itemcount)
{
char id[10];
int index,i;
if (*itemcount > 0)
{
printf("ingresa el id del sistema:");
scanf("%s",id);
index = search(st, id,*itemcount);

if ((index!=-1) && (*itemcount != 0))
{
if (index == (*itemcount-1)) //elimina el ultimo registro
{

clean(st, index);
--(*itemcount);

printf("The record was deleted.\n");
}
else //elimina el primer o el registro de en medio de la lista 
{
for (i = index; i < *itemcount-1; i++)
{
st[i] = st[i + 1];
clean(st, *itemcount);
--(*itemcount) ;
}

}

}
else printf("este registro no existe.comprueba el id del alumno.\n");


}
else printf("no hay registro para eliminar\n");
}

//funcion para limpiar el registro del alumno
void clean(student st[],int index)
{
strcpy(st[index].stnumber,"");
strcpy(st[index].stname,"");
strcpy(st[index].numcontrol,"");
st[index].sex =NULL;
strcpy(st[index].carrera,"");
st[index].quizz1 = 0;
st[index].quizz2 = 0;
st[index].assigment = 0;
st[index].midterm = 0;
st[index].final = 0;
st[index].total = 0;

}








//funcion para encontrar registro
void find(student st[], int itemcount)
{
char id[10];
printf("Enter student's ID:");
scanf("%s",&id);

int index=search(st,id,itemcount);
if (index != -1)
{ //desplegar registros encontrados
displayheading();
printf("%-5s",st[index].stnumber);
printf("%-17s",st[index].stname);
printf("%-13s",st[index].numcontrol);
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
else printf("el registro no existe.\n");

}







//funcion principal

int main(int argc, char *argv[])
{


student st[20];
int itemcount=0;

//mostrar menu
displaymenu();
int yourchoice;
char confirm;
do
{
printf("ingresa tu opcion(1-4):");
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
default:printf("invalido\n");
}

printf("presiona y o Y para continuar:");
scanf("%s",&confirm);
}
while(confirm=='y'||confirm=='Y');
system("PAUSE");
return EXIT_SUCCESS;
}
