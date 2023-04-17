#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[]){
	if(argc==1){
		printf("Necesitas ingresar argumentos.\nPrueba [ manitmid --help ]");
	}else if(argc==2){
		if(strcmp(argv[1],"--about")==0||strcmp(argv[1],"-ab")==0){
			printf("\tmanitmid es una recopilacion de distintas herramientas de pentesting, Man In The Middle.\n\tDiseñada, codificada y herramientas recopiladas por PrShaHk.\n");
			printf("\tHerramientas incluidas:\n\t\tDelorean.\n\t\tsslstrip.\n\t\tarpspoof.\n");
			printf("\n\t\t[ Estas herramientas no pertenecen a PrShaHk, dentro de cada directorio vienen licencias y la propiedad del autor. ]");
			printf("\n\t\t[ sslstrip fue modificada para ser compatible con python 2 y 3 ]");
			printf("\n\t\t[ Delorean y sslstrip fueron modificadas para cambiar su idioma ]");
			printf("\n\tCodificada en C\n");
			printf("\n\tLicensia libre, para modificar y mejorar, pero no para apropiarse o adjudicarse.");
			printf("\n\n\t\tPrShaHk 2021\n\t\t\t\t----------");
		}else if(strcmp(argv[1],"--help")==0||strcmp(argv[1],"-h")==0){
			printf("\tmanitmid <opciones> <argumentos>\n");
			printf("\n\t<opciones>");
			printf("\n\t--about \t |\t-ab");
			printf("\n\t > Muestra informacion sobre manitmid.\n");
			printf("\n\t--arpspoof \t |\t-a");
			printf("\n\t > Activa el envio de paquetes para engañar conexion y ser Man in the middle.");
			printf("\n\t<argumentos arpspoof>");
			printf("\n\t\t<interfaz> <ip A> <ip B>");
			printf("\n\t\tSi queremos escuchar trafico que sale de un dispositivo:\n\t\t ip A=Dispositivo y ip B=puerta de enlace");
			printf("\n\t\tSi queremos escuchar trafico que sale de un router a un dispositivo: \n\t\t ip A=puerta de enlace y ip B=Dispositivo");
			printf("\n\t--Delorean \t -d");
			printf("\n\t\tInicia herramienta de MITM Delorean");
			printf("\n\t--flow \t |\t-f");
			printf("\n\t > Permite que los paquetes fluyan a travez de la maquina y no se estanquen.\n");
			printf("\n\t--help \t |\t-h");
			printf("\n\t > Muestra este mensaje de ayuda.\n");
			printf("\n\t--iptables \t | \t-i");
			printf("\n\t > Configura reglas para enrutamiento.");
			printf("\n\t<argumentos iptbles>");
			printf("\n\t\tclean \t | \t c");
			printf("\n\t\t\tBorra todas las reglas de enrutamiento.");
			printf("\n\t\tshow \t | \t s");
			printf("\n\t\t\tMuestra reglas de enrutamiento.");
			printf("\n\t\tshowAll \t | \t sA");
			printf("\n\t\t\tMuestra reglas de nateo.");
			printf("\n\t\tprerouting hsn | p hsn");
			printf("\n\t\t\tCrea reglas para preenrutamiento de http y https al puerto 8080 y acutalizacion de hora puerto 123");
			printf("\n\t\t<prerouting|p> <udp|tcp> <Puerto a escuchar> <Nuevo puerto donde enrutara>");
			printf("\n\t--sslstrip \t | \t -s");
			printf("\n\tInicia herramienta MITM sslstrip");
			printf("\n\t\t----------\n");
		}else if(strcmp(argv[1],"--flow")==0||strcmp(argv[1],"-f")==0){
			system("echo 1 > /proc/sys/net/ipv4/ip_forward");
			system("cat /proc/sys/net/ipv4/ip_forward");
		}else if(strcmp(argv[1],"--sslstrip")==0||strcmp(argv[1],"-s")==0){
                        system("python3 /usr/share/sslstrip/sslstrip.py");
                }else if(strcmp(argv[1],"--Delorean")==0||strcmp(argv[1],"-d")==0){
			system("python3 /usr/share/Delorean/delorean.py");
		}else{
			printf("No se reconoce opcion.\nPrueba [ manitmid --help ]");
		}
	}else if(argc==3){
		if(strcmp(argv[1],"--iptables")==0||strcmp(argv[1],"-i")==0){
			if(strcmp(argv[2],"clean")==0||strcmp(argv[2],"c")==0){
				system("iptables -F");
				system("iptables -t nat -F");
			}else if(strcmp(argv[2],"show")==0||strcmp(argv[2],"s")==0){
				system("iptables -L");
			}else if(strcmp(argv[2],"showAll")==0||strcmp(argv[2],"sA")==0){
				system("iptables -t nat -L");
			}else{
                 	       printf("No se reconoce argumento.\nPrueba [ manitmid --help ]");
                	}
		}else{
                        printf("No se reconoce opcion.\nPrueba [ manitmid --help ]");
                }
	}else if(argc==4){
		if(strcmp(argv[1],"--iptables")==0||strcmp(argv[1],"-i")==0){
			if(strcmp(argv[2],"prerouting")==0||strcmp(argv[2],"p")==0){
				if(strcmp(argv[3],"hsn")==0){
					system("manitmid -i p tcp 80 8080");
					system("manitmid -i p tcp 443 8080");
					system("manitmid -i p udp 123 123");
				}else{
        	        	        printf("No se reconoce argumento.\nPrueba [ manitmid --help ]");
	        	        }

			}else{
                        	printf("No se reconoce argumento.\nPrueba [ manitmid --help ]");
	                }
		}else{
                        printf("No se reconoce opcion.\nPrueba [ manitmid --help ]");
                }
	}else if(argc==5){
		if(strcmp(argv[1],"--arpspoof")==0||strcmp(argv[1],"-a")==0){
			char tmp[100];
                        strcpy(tmp,"arpspoof -i ");
                        strcat(tmp,argv[2]);
			strcat(tmp," -t ");
                        strcat(tmp,argv[3]);
			strcat(tmp," ");
			strcat(tmp,argv[4]);
                        system(tmp);
		}else{
                        printf("No se reconoce opcion.\nPrueba [ manitmid --help ]");
                }
	}else if(argc==6){
		if(strcmp(argv[1],"--iptables")==0||strcmp(argv[1],"-i")==0){
                        if(strcmp(argv[2],"prerouting")==0||strcmp(argv[2],"p")==0){ 
                                char tmp[100];
                                strcpy(tmp,"iptables -t nat -A PREROUTING -p ");
                                strcat(tmp,argv[3]);
                                strcat(tmp," --destination-port ");
                                strcat(tmp,argv[4]);
                                strcat(tmp," -j REDIRECT --to-port ");
                                strcat(tmp,argv[5]);
				system(tmp);
                        }else{
                        	printf("No se reconoce argumento.\nPrueba [ manitmid --help ]");
                	}
                }else{
                        printf("No se reconoce opcion.\nPrueba [ manitmid --help ]");
                }

	}else{
        	printf("No se reconoce opcion.\nPrueba [ manitmid --help ]");
        }
}
