//Abuso naval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>




main(){
//Dclaramos las variables.
	char dificultad;
	int mapa;
	FILE *tablero;
	FILE *save;
	FILE *tayvol;
	int x;
	int F;
	int C;
	int i;
	int j;
	int w;
	int a;
	int t;
	int r;
	int s;
	int barco;
	int tamano;
	int aciertos;
	int aciertos2;
	int lg;
	int T;
	int Q;
	char est;
	int nmapa;
	srand(time(NULL));
	mapa=(rand()%3);
//Instrucciones.
	printf("Usted va a jugar a Abuso Naval, un juego similar al Hundir la Flota pero solo hay un atacante y un defensor.\nLa partida se guarda autom\240ticamente al cerrar la ventana de comandos.\nSe recomienda ampliar la ventana de comandos usando la tecla Ctrl+rueda del rat\242n.\n");
printf("La longitud de los barcos es la siguiente: Kayak (2), Barca (3), Submarino (4)\n");
//Selección de la dificultad.
	printf("Elige la dificultad:\n1.-F\240cil\n2.-Medio\n3.-Dif\241cil\n4.-Cargar partida\n");
    scanf("%c",&dificultad);
    fflush(stdin);
    system("cls");
	switch(dificultad)
{	
		case'1':
//Guardamos el número de mapa en el archivo "nmapa.txt".
			tayvol=fopen("nmapa.txt","w+");
			if(tayvol==NULL){
				printf("\nNo se ha encontrado el archivo\n");}
			fseek(tayvol,0,SEEK_SET);
			fprintf(tayvol,"%i",mapa);
			fclose(tayvol);
			aciertos=0;
			printf("\nModo f\240cil\n");
			barco=10;
				if(mapa==0){
//Se copia el mapa original en el archivo "save.txt".
							printf("\nMapa 1\n");
					tablero=fopen("facil1.txt","a+");
						if(tablero==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					save=fopen("save.txt","w+");
						if(save==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					while(feof(tablero)==0){
						est=fgetc(tablero);
						fputc(est,save);}
						fclose(tablero);
						fclose(save);
		
					do{
						do{
//Pedimos coordenadas del barco.
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						system("cls");
						if(F>5||C>5)printf("\nCoordenadas exceden los limites del tablero 5x5.\n");
						}while(F>5||C>5);
						save=fopen("save.txt","r+");
						if(save==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
//Leemos la casilla indicada en el archivo "save.txt".
							for (i = 0; i <= (F-1)*5+C-1; i++) fscanf(save,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==1){
							printf("\nTocado Kayak del retiro\n");
							aciertos++;}
							else if(x==9){
							printf("\nCasilla repetida.\n");}
//Guardamos automaticamente la partida y el número de aciertos.
							tamano=(((F-1)*5+C-1)*2)+(F-1);
							fseek(save,tamano,SEEK_SET);
							fputs("9",save);
							aciertos2=aciertos+10;
							fseek(save,55,SEEK_SET);
							fprintf(save,"%i",aciertos2);
							fclose(save);
							
//Dibujamos tablero en la ventana de comandos.
							tablero=fopen("facil1.txt","r+");
							save=fopen("save.txt","r+");
							fseek(tablero,0,SEEK_SET);
							fseek(save,0,SEEK_SET);
							printf("\n");
							for(w=0;w<5;w++){
								printf("\t");
								for(a=0;a<5;a++){
									fscanf(tablero,"%d",&t);
									fscanf(save,"%d",&s);
									r=s+t;
									if(r<9){printf("\333");}
									if(r==9){printf("\260");}
									if(r>9){printf("\312");}
									}
									printf("\n");
									}
	
					}while(aciertos<barco);
					printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
//Se repite este proceso para el resto de mapas y dificultades, variando el número dde varcos que hay en cada mapa.					
				else if(mapa==1){
					printf("\nMapa 2\n");
					tablero=fopen("facil2.txt","a+");
						if(tablero==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					save=fopen("save.txt","w+");
						if(save==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					while(feof(tablero)==0){
						est=fgetc(tablero);
						fputc(est,save);}
						fclose(tablero);
						fclose(save);
					do{
						do{
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						system("cls");
						if(F>5||C>5)printf("\nCoordenadas exceden los limites del tablero 5x5.\n");
						}while(F>5||C>5);
						save=fopen("save.txt","r+");
						if(save==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*5+C-1; i++) fscanf(save,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==1){
							printf("\nTocado Kayak del retiro\n");
							aciertos++;}
							else if(x==9){
							printf("\nCasilla repetida.\n");}
							
							tamano=(((F-1)*5+C-1)*2)+(F-1);
							fseek(save,tamano,SEEK_SET);
							fputs("9",save);
							aciertos2=aciertos+10;
							fseek(save,55,SEEK_SET);
							fprintf(save,"%i",aciertos2);
							fclose(save);
							
							
							tablero=fopen("facil2.txt","r+");
							save=fopen("save.txt","r+");
							fseek(tablero,0,SEEK_SET);
							fseek(save,0,SEEK_SET);
							printf("\n");
							for(w=0;w<5;w++){
								printf("\t");
								for(a=0;a<5;a++){
									fscanf(tablero,"%d",&t);
									fscanf(save,"%d",&s);
									r=s+t;
									if(r<9){printf("\333");}
									if(r==9){printf("\260");}
									if(r>9){printf("\312");}
									}
									printf("\n");
									}
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
					
				else if(mapa==2){
					printf("\nMapa 3\n");
					tablero=fopen("facil3.txt","a+");
						if(tablero==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					save=fopen("save.txt","w+");
						if(save==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					while(feof(tablero)==0){
						est=fgetc(tablero);
						fputc(est,save);}
						fclose(tablero);
						fclose(save);
					do{
						do{
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						system("cls");
						if(F>5||C>5)printf("\nCoordenadas exceden los limites del tablero 5x5.\n");
						}while(F>5||C>5);
						save=fopen("save.txt","r+");
						if(save==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*5+C-1; i++) fscanf(save,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==1){
							printf("\nTocado Kayak del retiro\n");
							aciertos++;}
							else if(x==9){
							printf("\nCasilla repetida.\n");}
							
							tamano=(((F-1)*5+C-1)*2)+(F-1);
							fseek(save,tamano,SEEK_SET);
							fputs("9",save);
							aciertos2=aciertos+10;
							fseek(save,55,SEEK_SET);
							fprintf(save,"%i",aciertos2);
							fclose(save);
							
							
							tablero=fopen("facil3.txt","r+");
							save=fopen("save.txt","r+");
							fseek(tablero,0,SEEK_SET);
							fseek(save,0,SEEK_SET);
							printf("\n");
							for(w=0;w<5;w++){
								printf("\t");
								for(a=0;a<5;a++){
									fscanf(tablero,"%d",&t);
									fscanf(save,"%d",&s);
									r=s+t;
									if(r<9){printf("\333");}
									if(r==9){printf("\260");}
									if(r>9){printf("\312");}
									}
									printf("\n");
									}
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
					
				else{
					printf("\nError\n");}
		break;		

					
//Dificultad media.			
		case'2':
			tayvol=fopen("nmapa.txt","w+");
			if(tayvol==NULL){
				printf("\nNo se ha encontrado el archivo\n");}
			fseek(tayvol,0,SEEK_SET);
			fprintf(tayvol,"%i",mapa);
			fclose(tayvol);
				printf("\nModo normal\n");
				barco=14;
				aciertos=0;
				if(mapa==0){
					printf("\nMapa 1\n");
					tablero=fopen("Medio(1).txt","a+");
						if(tablero==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					save=fopen("save.txt","w+");
						if(save==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					while(feof(tablero)==0){
						est=fgetc(tablero);
						fputc(est,save);}
						fclose(tablero);
						fclose(save);
					do{
						do{
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						system("cls");
						if(F>6||C>6)printf("\nCoordenadas exceden los limites del tablero 6x6.\n");
						}while(F>6||C>6);
						save=fopen("save.txt","r+");
						if(save==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*6+C-1; i++) fscanf(save,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==2){
							printf("\nTocado Kayak del retiro\n");
							aciertos++;
							}
							else if(x==3){
							printf("\nTocado barca del retiro\n");
							aciertos++;
							}
							else if(x==9){
							printf("\nCasilla repetida.\n");
							}
							tamano=(((F-1)*6+C-1)*2)+(F-1);
							fseek(save,tamano,SEEK_SET);
							fputs("9",save);
							aciertos2=aciertos+10;
							fseek(save,78,SEEK_SET);
							fprintf(save,"%i",aciertos2);
							fclose(save);
							
							
							tablero=fopen("Medio(1).txt","r+");
							save=fopen("save.txt","r+");
							fseek(tablero,0,SEEK_SET);
							fseek(save,0,SEEK_SET);
							printf("\n");
							for(w=0;w<6;w++){
								printf("\t");
								for(a=0;a<6;a++){
									fscanf(tablero,"%d",&t);
									fscanf(save,"%d",&s);
									r=s+t;
									if(r<9){printf("\333");}
									if(r==9){printf("\260");}
									if(r>9){printf("\312");}
									}
									printf("\n");
									}
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
				else if(mapa==1){
					printf("\nMapa 2\n");
					tablero=fopen("Medio(2).txt","a+");
						if(tablero==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					save=fopen("save.txt","w+");
						if(save==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					while(feof(tablero)==0){
						est=fgetc(tablero);
						fputc(est,save);}
						fclose(tablero);
						fclose(save);
					do{
						do{
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						system("cls");
						if(F>6||C>6)printf("\nCoordenadas exceden los limites del tablero 6x6.\n");
						}while(F>6||C>6);
						save=fopen("save.txt","r+");
						if(save==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*6+C-1; i++) fscanf(save,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==2){
							printf("\nTocado Kayak del retiro\n");
							aciertos++;
							}
							else if(x==3){
							printf("\nTocado barca del retiro\n");
							aciertos++;
							}
							else if(x==9){
							printf("\nCasilla repetida.\n");
							}
							tamano=(((F-1)*6+C-1)*2)+(F-1);
							fseek(save,tamano,SEEK_SET);
							fputs("9",save);
							aciertos2=aciertos+10;
							fseek(save,78,SEEK_SET);
							fprintf(save,"%i",aciertos2);
							fclose(save);
							
							
							tablero=fopen("Medio(2).txt","r+");
							save=fopen("save.txt","r+");
							fseek(tablero,0,SEEK_SET);
							fseek(save,0,SEEK_SET);
							printf("\n");
							for(w=0;w<6;w++){
								printf("\t");
								for(a=0;a<6;a++){
									fscanf(tablero,"%d",&t);
									fscanf(save,"%d",&s);
									r=s+t;
									if(r<9){printf("\333");}
									if(r==9){printf("\260");}
									if(r>9){printf("\312");}
									}
									printf("\n");
									}
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
				else if(mapa==2){
					printf("\nMapa 3\n");
					tablero=fopen("Medio(3).txt","a+");
						if(tablero==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					save=fopen("save.txt","w+");
						if(save==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					while(feof(tablero)==0){
						est=fgetc(tablero);
						fputc(est,save);}
						fclose(tablero);
						fclose(save);
					do{
						do{
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						system("cls");
						if(F>6||C>6)printf("\nCoordenadas exceden los limites del tablero 6x6.\n");
						}while(F>6||C>6);
						save=fopen("save.txt","r+");
						if(save==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*6+C-1; i++) fscanf(save,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==2){
							printf("\nTocado Kayak del retiro\n");
							aciertos++;
							}	
							else if(x==3){
							printf("\nTocado barca del retiro\n");
							aciertos++;
							}
							else if(x==9){
							printf("\nCasilla repetida.\n");
							}
							tamano=(((F-1)*6+C-1)*2)+(F-1);
							fseek(save,tamano,SEEK_SET);
							fputs("9",save);
							aciertos2=aciertos+10;
							fseek(save,78,SEEK_SET);
							fprintf(save,"%i",aciertos2);
							fclose(save);
							
							
							tablero=fopen("Medio(3).txt","r+");
							save=fopen("save.txt","r+");
							fseek(tablero,0,SEEK_SET);
							fseek(save,0,SEEK_SET);
							printf("\n");
							for(w=0;w<6;w++){
								printf("\t");
								for(a=0;a<6;a++){
									fscanf(tablero,"%d",&t);
									fscanf(save,"%d",&s);
									r=s+t;
									if(r<9){printf("\333");}
									if(r==9){printf("\260");}
									if(r>9){printf("\312");}
									}
									printf("\n");
									}
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
				else{
					printf("\nError\n");}
		break;				
		
		
//Dificultad difícil.		
		case'3':
			tayvol=fopen("nmapa.txt","w+");
			if(tayvol==NULL){
				printf("\nNo se ha encontrado el archivo\n");}
			fseek(tayvol,0,SEEK_SET);
			fprintf(tayvol,"%i",mapa);
			fclose(tayvol);
				printf("\nModo dif\241cil\n");
				barco=22;
				aciertos=0;
				if(mapa==0){
					printf("\nMapa 1\n");
					tablero=fopen("Difícil(1).txt","a+");
						if(tablero==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					save=fopen("save.txt","w+");
						if(save==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					while(feof(tablero)==0){
						est=fgetc(tablero);
						fputc(est,save);}
						fclose(tablero);
						fclose(save);
						do{
							do{
								printf("\nIntroduzca coordenadas(Fila Columna):\n");
								printf("\nTocados %d de %d\n", aciertos, barco);
								scanf("%d%d",&F,&C);
								fflush(stdin);
								system("cls");
								if(F>7||C>7)printf("\nCoordenadas exceden los limites del tablero 7x7.\n");
							}while(F>7||C>7);
						save=fopen("save.txt","r+");
						if(save==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*7+C-1; i++) fscanf(save,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==2){
							printf("\nTocado kayak del retiro\n");
							aciertos++;
							}	
							else if(x==3){
							printf("\nTocado barca del retiro\n");
							aciertos++;
							}
							else if(x==4){
							printf("\nTocado Submarino nuclear del retiro\n");
							aciertos++;
							}
							else if(x==9){
							printf("\nCasilla repetida.\n");
							}
							tamano=(((F-1)*7+C-1)*2)+(F-1);
							fseek(save,tamano,SEEK_SET);
							fputs("9",save);
							aciertos2=aciertos+10;
							fseek(save,105,SEEK_SET);
							fprintf(save,"%i",aciertos2);
							fclose(save);
							
							
							tablero=fopen("Difícil(1).txt","r+");
							save=fopen("save.txt","r+");
							fseek(tablero,0,SEEK_SET);
							fseek(save,0,SEEK_SET);
							printf("\n");
							for(w=0;w<7;w++){
								printf("\t");
								for(a=0;a<7;a++){
									fscanf(tablero,"%d",&t);
									fscanf(save,"%d",&s);
									r=s+t;
									if(r<9){printf("\333");}
									if(r==9){printf("\260");}
									if(r>9){printf("\312");}
									}
									printf("\n");
									}
							
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
				else if(mapa==1){
						printf("\nMapa 2\n");
						tablero=fopen("Difícil(2).txt","a+");
						if(tablero==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					save=fopen("save.txt","w+");
						if(save==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					while(feof(tablero)==0){
						est=fgetc(tablero);
						fputc(est,save);}
						fclose(tablero);
						fclose(save);
						do{
							do{
								printf("\nIntroduzca coordenadas(Fila Columna):\n");
								printf("\nTocados %d de %d\n", aciertos, barco);
								scanf("%d%d",&F,&C);
								fflush(stdin);
								system("cls");
								if(F>7||C>7)printf("\nCoordenadas exceden los limites del tablero 7x7.\n");
							}while(F>7||C>7);
						save=fopen("save.txt","r+");
						if(save==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*7+C-1; i++) fscanf(save,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==2){
							printf("\nTocado kayak del retiro\n");
							aciertos++;
							}	
							else if(x==3){
							printf("\nTocado barca del retiro\n");
							aciertos++;
							}
							else if(x==4){
							printf("\nTocado Submarino nuclear del retiro\n");
							aciertos++;
							}
							else if(x==9){
							printf("\nCasilla repetida.\n");
							}
							tamano=(((F-1)*7+C-1)*2)+(F-1);
							fseek(save,tamano,SEEK_SET);
							fputs("9",save);
							aciertos2=aciertos+10;
							fseek(save,105,SEEK_SET);
							fprintf(save,"%i",aciertos2);
							fclose(save);
							
							
							tablero=fopen("Difícil(2).txt","r+");
							save=fopen("save.txt","r+");
							fseek(tablero,0,SEEK_SET);
							fseek(save,0,SEEK_SET);
							printf("\n");
							for(w=0;w<7;w++){
								printf("\t");
								for(a=0;a<7;a++){
									fscanf(tablero,"%d",&t);
									fscanf(save,"%d",&s);
									r=s+t;
									if(r<9){printf("\333");}
									if(r==9){printf("\260");}
									if(r>9){printf("\312");}
									}
									printf("\n");
									}
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
				else if(mapa==2){
						printf("\nMapa 3\n");
						tablero=fopen("Difícil(3).txt","a+");
						if(tablero==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					save=fopen("save.txt","w+");
						if(save==NULL){
							printf("\nNo se ha encontrado el archivo\n");}
					while(feof(tablero)==0){
						est=fgetc(tablero);
						fputc(est,save);}
						fclose(tablero);
						fclose(save);
						do{
							do{
								printf("\nIntroduzca coordenadas(Fila Columna):\n");
								printf("\nTocados %d de %d\n", aciertos, barco);
								scanf("%d%d",&F,&C);
								fflush(stdin);
								system("cls");
								if(F>7||C>7)printf("\nCoordenadas exceden los limites del tablero 7x7.\n");
							}while(F>7||C>7);
						save=fopen("save.txt","r+");
						if(save==NULL)
							printf("\nError abriendo el mapa.\n");
						else{
							for (i = 0; i <= (F-1)*7+C-1; i++) fscanf(save,"%d",&x);
							}	
							if(x==0){
							printf("\nAgua\n");
								}
							else if(x==2){
							printf("\nTocado kayak del retiro\n");
							aciertos++;
							}	
							else if(x==3){
							printf("\nTocado barca del retiro\n");
							aciertos++;
							}
							else if(x==4){
							printf("\nTocado Submarino nuclear del retiro\n");
							aciertos++;
							}
							else if(x==9){
							printf("\nCasilla repetida.\n");
							}
							tamano=(((F-1)*7+C-1)*2)+(F-1);
							fseek(save,tamano,SEEK_SET);
							fputs("9",save);
							aciertos2=aciertos+10;
							fseek(save,105,SEEK_SET);
							fprintf(save,"%i",aciertos2);
							fclose(save);
							
							
							tablero=fopen("Difícil(3).txt","r+");
							save=fopen("save.txt","r+");
							fseek(tablero,0,SEEK_SET);
							fseek(save,0,SEEK_SET);
							printf("\n");
							for(w=0;w<7;w++){
								printf("\t");
								for(a=0;a<7;a++){
									fscanf(tablero,"%d",&t);
									fscanf(save,"%d",&s);
									r=s+t;
									if(r<9){printf("\333");}
									if(r==9){printf("\260");}
									if(r>9){printf("\312");}
									}
									printf("\n");
									}
						}while(aciertos<barco);
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");}
				else{
					printf("\nError\n");}
		break;
//Cargar partida
		case '4':
	//Leemos el número de acirtos del archivo de guardado.
				save=fopen("save.txt","r+");
				if(save==NULL){
					printf("\nNo se ha encontrado la partida guardada.\n");}
				fseek(save,-2,SEEK_END);
				fscanf(save,"%i",&aciertos2);
				aciertos=aciertos2-10;
	//Medimos la longitud del archivo para saber a qué dificultad pertenece este mapa.
				fseek(save,0,SEEK_END);
				lg=ftell(save);
				fclose(save);
	//En funcion de la dificultad se ajustan las variables pertinentes.
				if(lg==57){barco=10;T=5;Q=55;}
				if(lg==80){barco=14;T=6;Q=78;}
				if(lg==107){barco=22;T=7;Q=105;}
	//En funcion del número de mapa guardado en "nmapa.txt" y la dificultad, decidimos qué archivo abrir.			
				tayvol=fopen("nmapa.txt","r+");
				fseek(tayvol,0,SEEK_SET);
				fscanf(tayvol,"%i",&nmapa);
				if(nmapa==0){
					if(lg==57){tablero=fopen("facil1.txt","r+");}
					else if(lg==80){tablero=fopen("Medio(1).txt","r+");}
					else if(lg==107){tablero=fopen("Difícil(1).txt","r+");}}
				if(nmapa==1){
					if(lg==57){tablero=fopen("facil2.txt","r+");}
					else if(lg==80){tablero=fopen("Medio(2).txt","r+");}
					else if(lg==107){tablero=fopen("Difícil(2).txt","r+");}}
				if(nmapa==2){
					if(lg==57){tablero=fopen("facil3.txt","r+");}
					else if(lg==80){tablero=fopen("Medio(3).txt","r+");}
					else if(lg==107){tablero=fopen("Difícil(3).txt","r+");}}
				
				do{
					do{
	//Se usa el proceso de los casos anteriores para continuar con la partida.
						save=fopen("save.txt","r+");
							fseek(tablero,0,SEEK_SET);
							fseek(save,0,SEEK_SET);
							printf("\n");
							for(w=0;w<T;w++){
								printf("\t");
							for(a=0;a<T;a++){
								fscanf(tablero,"%d",&t);
								fscanf(save,"%d",&s);
								r=s+t;
								if(r<9){printf("\333");}
								if(r==9){printf("\260");}
								if(r>9){printf("\312");}
								}
								printf("\n");
								}
								
						printf("\nIntroduzca coordenadas(Fila Columna):\n");
						printf("\nTocados %d de %d\n", aciertos, barco);
						scanf("%d%d",&F,&C);
						fflush(stdin);
						system("cls");
						if(F>T||C>T)printf("\nCoordenadas exceden los limites del tablero %dx%d.\n",T,T);
						}while(F>T||C>T);
					save=fopen("save.txt","r+");
					if(save==NULL)
						printf("\nError abriendo el mapa.\n");
					else{for (i = 0; i <= (F-1)*T+C-1; i++) fscanf(save,"%d",&x);}		
						if(x==0){
							printf("\nAgua\n");}
						else if(x==2){
							printf("\nTocado kayak del retiro\n");
							aciertos++;
							}	
						else if(x==3){
							printf("\nTocado barca del retiro\n");
							aciertos++;
							}
						else if(x==4){
							printf("\nTocado Submarino nuclear del retiro\n");
							aciertos++;
							}
						else if(x==9){
							printf("\nCasilla repetida.\n");
							}
							tamano=(((F-1)*T+C-1)*2)+(F-1);
							fseek(save,tamano,SEEK_SET);
							fputs("9",save);
							aciertos2=aciertos+10;
							fseek(save,Q,SEEK_SET);
							fprintf(save,"%i",aciertos2);
							fclose(save);
									
						}while(aciertos<barco);;
						printf("\nHas servido con honor a tu gran patria y has conseguido defendernos de la flota enemiga.\nFelicidades marine.\n");
		break;	
			
		default:
			printf("\nEsta respuesta es err\242nea\n");
	}
	}
