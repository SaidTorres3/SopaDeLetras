#include <iostream>
#include <conio.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main(){

	//Programa que resuelve una sopa de letras.
	//Incio de creacion de tabla (Lee el archivo sopa.txt)
	
	int verticales, horizontales;
	string test, line;
	
	cout<<"Ingrese la cantidad de elementos verticales [Lineas] que tiene la sopa: "; cin>>verticales;
	cout<<"Ingrese la cantidad de elementos horizontales [Columnas] que contiene cada fila: "; cin>>horizontales;
	string sopa[verticales+1];
	char conversor[verticales+1][horizontales+2];
	
	ifstream archivo;
	archivo.open("sopa.txt",ios::in);

	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
	}
	
	int i=-1; //Guarda la sopa de letras en sopa[]
	while(!archivo.eof()){
		i=i+1;
		getline(archivo, sopa[i], '-');
	}
	
	archivo.close();
	
	//Generador de matriz ("conversor" es la matriz)
	int j = 0-horizontales;
	int booler;
	for(int i=0; i<verticales; i++){
		j = j + horizontales;
		line=sopa[i].substr(1,horizontales);
		if (i==0){
			line=sopa[i].substr(0,horizontales);
		}
		strcpy(conversor[i],line.c_str());
		cout<<endl<<conversor[i];
	}
	
	cout<<endl<<endl;
	
	//Pedir la palabra
	string comparador,tomador;
	char palabra[25];
	int contpalabra=0;

	cout<<"Ingrese la palabra que desea buscar: ";
	cin>>palabra;

	strupr(palabra);
	contpalabra = strlen(palabra);

	cout<<endl<<endl;
	
	//Zona de logica - Detectificador de palabras	
	for(int i=0;i<verticales;i++){
		for(int j=0;j<horizontales;j++){
			comparador="";
			//Hacia la derecha (1)
			for(int p=0;p<contpalabra;p++){
					tomador=conversor[i][j+p];
					comparador+=tomador;
					if(comparador==palabra){
						cout<<"(Direccion derecha) La palabra "<<palabra<<" se encuentra en las coordenadas: ("<<i+1<<","<<j+1<<")."<<endl;
					}
				}
			//cout<<endl<<"Comparador: "<<comparador<<endl;
			//cout<<endl<<"i = "<<i<<" y j = "<<j;
			comparador="";
			//Hacia derecha-abajo (2)
			for(int p=0;p<contpalabra;p++){
					tomador=conversor[i+p][j+p];
					comparador+=tomador;
					if(comparador==palabra){
						cout<<"(Direccion derecha-abajo) La palabra "<<palabra<<" se encuentra en las coordenadas: ("<<i+1<<","<<j+1<<")."<<endl;
					}
				}
			comparador="";
			//Hacia abajo (3)
			for(int p=0;p<contpalabra;p++){
					tomador=conversor[i+p][j];
					comparador+=tomador;
					if(comparador==palabra){
						cout<<"(Direccion abajo) La palabra "<<palabra<<" se encuentra en las coordenadas: ("<<i+1<<","<<j+1<<")."<<endl;
					}
				}
			comparador="";
			//Hacia izquierda-abajo (4)
			for(int p=0;p<contpalabra;p++){
					tomador=conversor[i+p][j-p];
					comparador+=tomador;
					if(comparador==palabra){
						cout<<"(Direccion izquierda-abajo) La palabra "<<palabra<<" se encuentra en las coordenadas: ("<<i+1<<","<<j+1<<")."<<endl;
					}
				}
			comparador="";
			//Hacia izquierda (5)
			for(int p=0;p<contpalabra;p++){
					tomador=conversor[i][j-p];
					comparador+=tomador;
					if(comparador==palabra){
						cout<<"(Direccion izquierda) La palabra "<<palabra<<" se encuentra en las coordenadas: ("<<i+1<<","<<j+1<<")."<<endl;
					}
				}
			comparador="";
			//Hacia izquierda-arriba (6)
			for(int p=0;p<contpalabra;p++){
					tomador=conversor[i-p][j-p];
					comparador+=tomador;
					if(comparador==palabra){
						cout<<"(Direccion izquierda-arriba) La palabra "<<palabra<<" se encuentra en las coordenadas: ("<<i+1<<","<<j+1<<")."<<endl;
					}
				}
			comparador="";
			//Hacia arriba (7)
			for(int p=0;p<contpalabra;p++){
					tomador=conversor[i-p][j];
					comparador+=tomador;
					if(comparador==palabra){
						cout<<"(Direccion arriba) La palabra "<<palabra<<" se encuentra en las coordenadas: ("<<i+1<<","<<j+1<<")."<<endl;
					}
				}
			comparador="";
			//Hacia derecha-arriba (8)
			for(int p=0;p<contpalabra;p++){
					tomador=conversor[i-p][j+p];
					comparador+=tomador;
					if(comparador==palabra){
						cout<<"(Direccion derecha-arriba) La palabra "<<palabra<<" se encuentra en las coordenadas: ("<<i+1<<","<<j+1<<")."<<endl;
					}
				}
			comparador="";
		}
	}
	
	cout<<endl<<endl<<"[Las coordenadas inician desde la parte superior izquierda.]"<<endl;
	cout<<"[El primer valor indica el numero de linea y el segundo el numero de columna.]";
	
	getch();
	return 0;
	
}
