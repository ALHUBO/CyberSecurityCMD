/*
Codigo desarrollado por ALHUBO
Con el unico fin de facilitar los comandos
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[]){
	char tmp[100];
	if(argc==1){
		printf("El comando recibe:\n\t1 Argumento:\n\t\tmodmon <Nombre del adaptador>\n\t2 o mas Argumentos:\n\t\tmodmon [opcion] <Argumentos>\nPara mas informacion:\n\tmodmon --help\n");
	}else if(argc==2){
		if(strcmp(argv[1],"-v")==0||strcmp(argv[1],"--version")==0){
            printf("modmon version 1.0\n");
        }else if(strcmp(argv[1],"-h")==0||strcmp(argv[1],"--help")==0){
			printf("--help | -h \n\tMuestra ayuda\n");
			printf("\n--connection | -c\n\tActiva modo monitor sin desconectar de la red\n\tmodmon -c <Adaptador>\n");
			printf("\n--about | -a\n\tMuestra informacion sobre modmon\n");
			printf("\n--version | -v \n\tMuestra la version de modmon\n");
			printf("\n--rename | -r \n\tCambia el nombre temporalmente a una interfaz de red\n\tmodmon -r <Interfaz> <NuevoNombre>\n");
			printf("\n--interface | -i \n\tMuestra las interfaces de red\n");
        }else if(strcmp(argv[1],"-a")==0||strcmp(argv[1],"--about")==0){
			printf("Desarrollado por ALHUBO.\nEste comando fue desarrollado para hacer mas rapido la activacion del modo monitor.\nLenguaje utilizado [ C ]\nComandos Utilizados:\n\tairmon-ng check kill\n\tiw [interfaz] set type monitor\n\trfkill unblock wifi\n\tip l s [interfaz] up\n\tiwconfig | grep Mode:\n\tairmon-ng start [interfaz]\n");
		}else if(strcmp(argv[1],"-i")==0||strcmp(argv[1],"--interfaces")==0){
			printf("Mostrando Interfaces de red...\n");
			sprintf(tmp,"sudo iwconfig");
			printf("\t>$ %s\n",tmp);
			system(tmp);
		}else if(strcmp(argv[1],"-c")!=0&&strcmp(argv[1],"--connection")!=0){
			printf("Matando procesos de red...\n");
			sprintf(tmp,"sudo airmon-ng check kill");
			printf("\t>$ %s\n",tmp);
			system(tmp);

			printf("Activando  modo Monitor en %s...\n",argv[1]);
			sprintf(tmp,"sudo iw %s set type monitor",argv[1]);
			printf("\t>$ %s\n",tmp);
			system(tmp);

			printf("Confirmando que no hay procesos que desactiven...\n");
			sprintf(tmp,"sudo rfkill unblock wifi");
			printf("\t>$ %s\n",tmp);
			system(tmp);

			printf("Activando adaptdor %s...\n",argv[1]);
			sprintf(tmp,"ip l s %s up",argv[1]);
			printf("\t>$ %s\n",tmp);
			system(tmp);

			printf("Verificando resultado:\n");
			sprintf(tmp,"iwconfig | grep Mode:");
			printf("\t>$ %s\n",tmp);
			system(tmp);
		}else{
			printf("Prueba:\n\tmodmon --help\n");
		}
	}else if(argc>=3){
		if(strcmp(argv[1],"-c")==0||strcmp(argv[1],"--connection")==0){
			printf("Activando modo monitor en %s...\n",argv[2]);
			sprintf(tmp,"sudo airmon-ng start %s",argv[2]);
			printf("\t>$ %s\n",tmp);
			system(tmp);
			
		}else if((strcmp(argv[1],"-r")==0||strcmp(argv[1],"--rename")==0)&&argc==4){
			printf("Apagnado interfaz %s...\n",argv[2]);
			sprintf(tmp,"sudo ifconfig %s down",argv[2]);
			printf("\t>$ %s\n",tmp);
			system(tmp);

			printf("Cambiando nombre\n");
			sprintf(tmp,"sudo ip link set %s name %s",argv[2],argv[3]);
			printf("\t>$ %s\n",tmp);
			system(tmp);

			printf("Encendiendo interfaz %s...\n",argv[3]);
			sprintf(tmp,"sudo ifconfig %s up",argv[3]);
			printf("\t>$ %s\n",tmp);
			system(tmp);
		}else{
			printf("Prueba:\n\tmodmon --help\n");
		}
	}
}
