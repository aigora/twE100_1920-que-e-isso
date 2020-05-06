//Hundir su flota
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NF
#define NC
char dificultad;
char mapa;
char nombre[20];
FILE *fp;
int x;
int F;
int C;
int i;
int j;
int barco;
int aciertos=0;

main(){
	srand(time(NULL));
	mapa=(rand()%3);
	printf("Elige la dificultad:\n1.-F\240cil\n2.-Medio\n3.-Dif\241cil\n");
    scanf("%c",&dificultad);
    fflush(stdin);

	switch(dificultad)
	{	
		case'1':
			printf("\nModo f\240cil\n");
			barco=10;
				if(mapa==0){
					printf("\nMapa 1\n");
					do{
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						fp=fopen("facil1.txt","r");
						if(fp==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*5+C-1; i++) fscanf(fp,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x>0){
							printf("\nTocado Kayak del retiro\n");
							aciertos++;
							}	
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
					
				else if(mapa==1){
					printf("\nMapa 2\n");
					do{
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						fp=fopen("facil2.txt","r");
						if(fp==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*5+C-1; i++) fscanf(fp,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x>0){
							printf("\nTocado Kayak del retiro\n");
							aciertos++;
							}	
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
					
				else if(mapa==2){
					printf("\nMapa 3\n");
					do{
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						fp=fopen("facil3.txt","r");
						if(fp==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*5+C-1; i++) fscanf(fp,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x>0){
							printf("\nTocado Kayak del retiro\n");
							aciertos++;
							}	
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
					
				else{
					printf("\nError\n");}
		break;		

					
			
		case'2':
				printf("\nModo normal\n");
				barco=14;
				if(mapa==0){
					printf("\nMapa 1\n");
					do{
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						fp=fopen("Medio(1).txt","r");
						if(fp==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*6+C-1; i++) fscanf(fp,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==2){
							printf("\nTocado Kayak del retiro\n");
							aciertos++;
							}
							else if(x==3){
							printf("\nTocado barca del reiro\n");
							aciertos++;
							}	
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
				else if(mapa==1){
					printf("\nMapa 2\n");
					do{
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						fp=fopen("Medio(2).txt","r");
						if(fp==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*6+C-1; i++) fscanf(fp,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==2){
							printf("\nTocado Kayak del retiro\n");
							aciertos++;
							}
							else if(x==3){
							printf("\nTocado barca del reiro\n");
							aciertos++;
							}	
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
				else if(mapa==2){
					printf("\nMapa 3\n");
					do{
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						fp=fopen("Medio(3).txt","r");
						if(fp==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*6+C-1; i++) fscanf(fp,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==2){
							printf("\nTocado Kayak del reiro\n");
							aciertos++;
							}	
							else if(x==3){
							printf("\nTocado barca del reiro\n");
							aciertos++;
							}
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
				else{
					printf("\nError\n");}
		break;				
		
		
		case'3':
				printf("\nModo dif\241cil\n");
				barco=22;
				if(mapa==0){
					printf("\nMapa 1\n");
						do{
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						fp=fopen("Difícil(1).txt","r");
						if(fp==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*7+C-1; i++) fscanf(fp,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==2){
							printf("\nTocado kayak del reiro\n");
							aciertos++;
							}	
							else if(x==3){
							printf("\nTocado barca del reiro\n");
							aciertos++;
							}
							else if(x==4){
							printf("\nTocado Submarino nuclear del retiro\n");
							aciertos++;
							}
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
				else if(mapa==1){
						printf("\nMapa 2\n");
						do{
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						fp=fopen("Difícil(2).txt","r");
						if(fp==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*7+C-1; i++) fscanf(fp,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==2){
							printf("\nTocado kayak del reiro\n");
							aciertos++;
							}	
							else if(x==3){
							printf("\nTocado barca del reiro\n");
							aciertos++;
							}
							else if(x==4){
							printf("\nTocado Submarino nuclear del retiro\n");
							aciertos++;
							}
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
				else if(mapa==2){
						printf("\nMapa 3\n");
						do{
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						fp=fopen("Difícil(3).txt","r");
						if(fp==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*7+C-1; i++) fscanf(fp,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==2){
							printf("\nTocado kayak del reiro\n");
							aciertos++;
							}	
							else if(x==3){
							printf("\nTocado barca del reiro\n");
							aciertos++;
							}
							else if(x==4){
							printf("\nTocado Submarino nuclear del retiro\n");
							aciertos++;
							}
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
				else{
					printf("\nError\n");}
		break;				
		default:
			printf("\nEsta respuesta es err\242nea\n");
	}
}
	





