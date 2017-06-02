#include <stdio.h>
#include <stdlib.h>

//declaracion de la estructura del alumno
typedef struct
{

char esnum[10];
char esnombre[20];
char numcontrol[13];
char sexo;
char carrera[20];
float exam1;
float exam2;
float exam3;
float exam4;
float exam5;
float total;

}estudiante;
//funciones principales
int buscar(estudiante st[],char id[], int contadordeelement);
void limpiar(estudiante st[],int eliminarelem);
void formaimprimir();

//funcion para mostrar el menu
void mostrarmenu(){
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
void agre_regis(estudiante st[],int *contadordeelement){

again:
printf("\ningresa id del alumno:");
scanf("%s",&st[*contadordeelement].esnum);
if(buscar(st,st[*contadordeelement].esnum,*contadordeelement)!=-1)
{
printf("Este id ya existe\n");
goto again;
}

printf("ingresa el nombre del estudiante:");
scanf("%s",&st[*contadordeelement].esnombre);
printf("ingresa el numero de control:");
scanf("%s",&st[*contadordeelement].numcontrol);
printf("ingresa el sexo del estudiante(F o M):");
scanf("%s",&st[*contadordeelement].sexo);
printf("ingresa carrera del alumno:");
scanf("%s",&st[*contadordeelement].carrera);
printf("ponderacion de la primera unidad:");
scanf("%f",&st[*contadordeelement].exam1);
printf("ponderacion de la segunda unidad:");
scanf("%f",&st[*contadordeelement].exam2);
printf("ponderacion de la tercera unidad:");
scanf("%f",&st[*contadordeelement].exam3);
printf("ponderacion de la cuarta unidad:");
scanf("%f",&st[*contadordeelement].exam4);
printf("ponderacion de la quinta unidad:");
scanf("%f",&st[*contadordeelement].exam5);
st[*contadordeelement].total=(st[*contadordeelement].exam1+st[*contadordeelement].exam2+
st[*contadordeelement].exam3+st[*contadordeelement].exam4+st[*contadordeelement].exam5)/5;

++(*contadordeelement);


}

//funcion de busqueda
int buscar(estudiante st[], char id[],int contadordeelement){
int encontrar =-1,i;

for (i = 0; i < contadordeelement && encontrar==-1; i++)
{

if (strcmp(st[i].esnum,id)==0) encontrar=i;

else encontrar=-1 ;
}

return encontrar;
}



//funcion para ver todos los registros
void vertodoreg(estudiante st[], int contadordeelement){
int i=0;
formaimprimir();
while(i<contadordeelement)
{
if(st[i].esnum!="")
{
printf("%-2s",st[i].esnum);
printf("%-17s",st[i].esnombre);
printf("%-13s",st[i].numcontrol);
printf("%-5c",st[i].sexo);
printf("%-17s",st[i].carrera);
printf("%-6.1f",st[i].exam1);
printf("%-6.1f",st[i].exam2);
printf("%-6.1f",st[i].exam3);
printf("%-6.1f",st[i].exam4);
printf("%-7.1f",st[i]. exam5);
printf("%-4.1f",st[i].total);
printf("\n");
}
i=i+1;

}


}

void formaimprimir()
{
printf("ID NOMBRE        No.Control       SEXO     CARRERA           P1   P2    P3    P4   P5   TOTAL \n");
printf("===================================================================================================\n");
}

//funcion para borrar registro
void eliminar_regis(estudiante st[], int *contadordeelement)
{
char id[10];
int index,i;
if (*contadordeelement > 0)
{
printf("ingresa el id del sistema:");
scanf("%s",id);
index = buscar(st, id,*contadordeelement);

if ((index!=-1) && (*contadordeelement != 0))
{
if (index == (*contadordeelement-1)) //elimina el ultimo registro
{

limpiar(st, index);
--(*contadordeelement);

printf("The record was deleted.\n");
}
else //elimina el primer o el registro de en medio de la lista
{
for (i = index; i < *contadordeelement-1; i++)
{
st[i] = st[i + 1];
limpiar(st, *contadordeelement);
--(*contadordeelement) ;
}

}

}
else printf("este registro no existe.comprueba el id del alumno.\n");


}
else printf("no hay registro para eliminar\n");
}

//funcion para limpiar el registro del alumno
void limpiar(estudiante st[],int index)
{
strcpy(st[index].esnum,"");
strcpy(st[index].esnombre,"");
strcpy(st[index].numcontrol,"");
st[index].sexo =NULL;
strcpy(st[index].carrera,"");
st[index].exam1 = 0;
st[index].exam2 = 0;
st[index].exam3 = 0;
st[index].exam4 = 0;
st[index].exam5 = 0;
st[index].total = 0;

}








//funcion para encontrar registro
void encontrar(estudiante st[], int contadordeelement)
{
char id[10];
printf("ingresa id del estudiante:");
scanf("%s",&id);

int index=buscar(st,id,contadordeelement);
if (index != -1)
{ //desplegar registros encontrados
formaimprimir();
printf("%-5s",st[index].esnum);
printf("%-17s",st[index].esnombre);
printf("%-13s",st[index].numcontrol);
printf("%-5c",st[index].sexo);
printf("%-17s",st[index].carrera);
printf("%-6.1f",st[index].exam1);
printf("%-6.1f",st[index].exam2);
printf("%-6.1f",st[index].exam3);
printf("%-6.1f",st[index].exam4);
printf("%-7.1f",st[index]. exam5);
printf("%-4.1f",st[index].total);
printf("\n");

}
else printf("el registro no existe.\n");

}







//funcion principal

int main(int argc, char *argv[])
{


estudiante st[20];
int contadordeelement=0;

//mostrar menu
mostrarmenu();
int eleccion;
char confirm;
do
{
printf("ingresa tu opcion(1-4):");
scanf("%d",&eleccion);

switch(eleccion){
case 1:agre_regis(st, &contadordeelement);
	break;
case 2:eliminar_regis(st, &contadordeelement);
	break;
case 3:vertodoreg(st, contadordeelement);
	break;
case 4:encontrar(st, contadordeelement);
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
