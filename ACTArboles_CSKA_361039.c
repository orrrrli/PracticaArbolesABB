
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

//*********************************************************************************
//***** Constantes globales*****//


//*********************************************************************************
//***** Estructuras y variables creadas*****//

typedef struct _tarbol{
	int dato;
	struct _tarbol *izq;
    struct _tarbol *der;
    struct _tarbol *padre;
}sTdato;

typedef sTdato *Tarbol;

//*********************************************************************************
//***** Prototipos de funciones *****//
//*********************************************************************************
int validaNint(int ri, int rf, char *msge);
void menu(void);
void servicio(Tarbol temp);

Tarbol addDatos(void);
void addTree(Tarbol *raiz, Tarbol *nuevo);
void preorder(Tarbol raiz);
Tarbol BuscarArbol(Tarbol raiz, int num);


//Funciones de la información del arbol
void hojas(Tarbol raiz,int *);
void conthojas(Tarbol raiz);
void altura(Tarbol raiz, int *nivel,int *act );
void contaltura(Tarbol raiz);

//Funciones para eliminar
void depurarNodo(Tarbol *nodo);
int status(Tarbol nodo);
void BorrarNodo(Tarbol *raiz, int num);
void BorraHoja(Tarbol *nodo);



//*********************************************************************************
//***** Funcion principal *****//
//*********************************************************************************
int main()
{
	//srand(time(NULL));
    char stnam[9][10]={"RAIZ","RhD","RhI","RhIhD","HOJA","PhD","PhI","PhIhD","VACIO"};
    int stNum[9]={0,1,2,3,4,5,6,7,-1};
	menu();
	return 0;
}

//*********************************************************************************
//***** Funciones *****//

//*********************************************************************************
//*****Funcion menu que manda a llamar otras funciones
//*********************************************************************************
void menu(void)
{
   int opc,num, datos=0;
   Tarbol arbol=NULL;
   Tarbol raiz=NULL;
   Tarbol nuevo=NULL;
   Tarbol temp=NULL;
   do{
      system ("cls");
      printf("* M  E   N   U *\n");
	  printf("1.-Agregar al arbol \n");
	  printf("2.-Imprimir metodo INORDEN\n");
      printf("3.-Buscar\n");
      printf("4.-Numero de hojas\n");
      printf("5.-Altura\n");
      printf("6.-Eliminar\n");
	  printf("7.-Exit\n");

	  opc=validaNint(1,7,"Escoge una opcion:");
	  switch(opc)
	    {
            case 1:
            {

            
            	system ("cls");
            	nuevo=addDatos();
                addTree(&arbol,&nuevo);
                system("pause");
            	break;
            }	
            case 2:
            {
                system ("cls");
                preorder(arbol);
			    system("pause");
		    	break;
		
            }
            case 3:
            {
                system ("cls");
                num=validaNint(1,1000,"Ingresa el valor a buscar: ");
                temp=BuscarArbol(arbol,num);
                if(!arbol)
                {
                    printf("El arbol esta vacio\n");
                    system("pause");
                    break;
                }
                 else{
                    if(temp->dato==num)
                    {
                        system ("CLS");
                        printf("Dato encontrado\n");
                        servicio(temp); //aqui se imprime el nodo
                        printf("\n");
                    }
                    else
                    { 
                        printf("\n Dato NO encontrado \n");
                    }
                    
                    system("pause");
                    break;
                }
               
            }
            case 4:
            {
                if (!arbol)
                {
                    printf("El arbol esta vacio\n");
                    system("pause");
                }
                else{
                conthojas(arbol);
                getch();
                }
                break;
            }
            case 5:
            {
                if (!arbol)
                {
                    printf("El arbol esta vacio\n");
                     system("pause");
                }
                else{
                system ("cls");
                contaltura(arbol);
                getch();
                }
             break;   
            } 
            case 6:
            {
                system("cls");
                num=validaNint(1,1000, "Ingrese el numero que desee borrar: ");
        	    BorrarNodo(&arbol, num);
                system("pause");
                break;
            }   
		}
	}while(opc!=7);
	
	
	printf("NULL \n\n\n MEMORIA LIMPIA...\n");
	system("PAUSE");
	
}

//*********************************************************************************
//*****Funcion que crea espacio de memoria para un nuevo dato
//*********************************************************************************
Tarbol addDatos(void)
{
	int numero;
	Tarbol nodo=NULL;
	nodo=(Tarbol)malloc(sizeof(sTdato)); //malloc: Crea espacio de memoria
    nodo->padre=NULL;
    nodo->der=NULL;
    nodo->izq=NULL;
    nodo->dato=validaNint(1,1000,"\nNumero: ");
	return nodo;
}

//*********************************************************************************
//*****Funcion que mete un dato al arbol
//*********************************************************************************
void addTree(Tarbol *raiz, Tarbol *nuevo)
{
    Tarbol scout, gral;
    scout=(*raiz);
    if (!scout)
    {
        *raiz=*nuevo;
    }
    else{
        while(scout)
        {
            gral=scout;
            if ((*nuevo)->dato < gral->dato)
            {
                scout=(scout->izq);
            }
            else{
                scout=(scout->der);
            }
        }
        (*nuevo)->padre=gral;
        if((*nuevo)->dato < gral->dato)
        {
            gral->izq=(*nuevo);
        }
        else
        {
            gral->der=(*nuevo);
        }
    }
}

//*********************************************************************************
//*****Funcion que realiza un servicio al dato del arbol
//*********************************************************************************
void servicio(Tarbol temp)
{
	printf("[ %d ]--> ",temp->dato);
}

//*********************************************************************************
//*****Funcion que elimina un dato del arbol
//*********************************************************************************


//*********************************************************************************
//*****Funcion que valida un numero entero
//*********************************************************************************
int validaNint(int ri, int rf, char *msge)
{
    char numchar[15];
    int numValid;
    do
    {
        puts(msge);
        fflush(stdin);
        gets(numchar);
        numValid=atoi(numchar);
    }while(numValid<ri || numValid>rf);
    return numValid;
}
	  
//*********************************************************************************
//*****Funcion preorder
//*********************************************************************************
void preorder(Tarbol raiz)
{
    if (raiz)
    {
    
        if((raiz)->izq)
        {
            preorder(raiz->izq);
        }
        servicio(raiz);
        if((raiz)->der)
        {
            preorder((raiz)->der);
        }
    }
}

Tarbol BuscarArbol(Tarbol raiz, int num)
{
	Tarbol gral=NULL, scout=NULL;
	scout=raiz;
	
	while(scout)
	{
		gral=scout;
		if(num== gral->dato )
		{
			return gral;
		}
		else
		{
			if(num < (gral->dato))
			{
				scout= scout->izq;
				//printf("izquierda");
			}
			else
			{
				scout= scout->der;
				//printf("derecha");
			}
		}
	}
	return gral;
}


void conthojas(Tarbol raiz)
{
	int num;
	num=0;
	if((raiz->der))
	{

		hojas(raiz,&num);
		printf("total de hojas es %i",num);
		
	}
	else if((raiz->izq))
	{

		hojas(raiz,&num);
		printf("total de hojas es %i",num);
	}
	else
	{

		printf("total de hojas= 0");
	}
}


void hojas(Tarbol raiz, int *num)
{
	if((raiz->izq))
	{
		hojas((raiz->izq),num);	
	}
	if((raiz->der))
	{
		hojas((raiz->der),num);
	}
	if(!raiz->der && !raiz->izq)
	{
		*num=*num+1;
	}
}

void contaltura(Tarbol raiz)
{
	int nivel=0,act=0;
	altura(raiz,&nivel,&act);
	printf("la altura del arbol es de %i",nivel);
}
void altura(Tarbol raiz, int *nivel,int *act )
{
	*act=*act+1;
	if(*act>*nivel)
	{
		*nivel=*act;
	}
	if(raiz->izq)
	{
	altura((raiz->izq),nivel,act);	
		
	}
	if(raiz->der)
	{
		altura((raiz->der),nivel,act);
	}
	*act=*act-1;
}

int status(Tarbol nodo)
{ 
    int val=0;
    if (nodo)
    {
        if(nodo->padre)
        {
            val=val+4;
        }
        if (nodo->izq)
        {
            val=val+2;
        }
        if (nodo->der)
        {
            val=val+1;
        }
        return val;
    }
    return -1;
}



void depurarNodo (Tarbol *nodo) //Se agrego la función de depurar nodo
{
	int stat= status((*nodo));
	Tarbol temp = NULL;
	switch(stat)
	{
		case -1:
			printf("Arbol vacio\n");
		break;
		
		case 0:
			printf("Raiz sin hijos\n");
			nodo=NULL;
		break;
		
		case 1:
			printf("Raiz con hijo derecho\n");
            
		break;
		
		case 2:
			printf("Raiz con hijo izquierdo\n");
		break;
		
		case 3:
			printf("Raiz con hijo izquierdo y derecho\n");
		break;
		
		case 4:
			printf("Hoja\n");
			if ((*nodo)->dato<((*nodo)->padre)->dato)
            {
                ((*nodo)->padre)->izq=NULL;
            }
            else{
                ((*nodo)->padre)->der=NULL;
            }
            (*nodo)->padre=NULL;
		break;
		
		case 5:
			printf("Padre con hijo derecho\n");
            ((*nodo)->padre)->der=((*nodo)->der);
            ((*nodo)->der)->padre=((*nodo)->padre);
            (*nodo)->padre=NULL;
            (*nodo)->der=NULL;
		break;
		
		case 6:
			printf("Padre con hijo izquierdo\n");
            ((*nodo)->padre)->izq=((*nodo)->izq);
            ((*nodo)->izq)->padre=((*nodo)->padre);
            (*nodo)->padre=NULL;
            (*nodo)->izq=NULL;
		break;
		
		case 7:
			printf("Padre con hijo izquierdo y derecho\n");
            temp=(*nodo)->izq; //nos colocamos a la izquierda para sabe el mayor de los menores
            while (temp->der!=NULL)
            {
                temp=temp->der; //recorremos el arbol a la derecha para encontrar el valor más grande
            }
            temp=*nodo;
            servicio(temp);
            if (temp->dato < (temp->padre)->dato)
            {
                (temp->padre)->izq=temp->izq;
                 (temp->izq)->der=temp->der;
                    servicio(temp->izq);
                    servicio(temp->der);

            }
                else{
                    (temp->padre)->der=temp->izq;
                    (temp->izq)->der=temp->der;

                }

		    free(temp);
        break;

	}
}

void BorrarNodo(Tarbol *raiz, int num)
{
	Tarbol temp=NULL;
	int stat;
	temp=BuscarArbol(*raiz, num);
	
	if(temp)
	{
		depurarNodo(&temp);
	}
	else
	{
		printf("No se localizo el nodo a borrar\n");
	}
	printf("Se ha eliminado el nodo exitosamente\n");
}