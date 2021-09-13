//Author: D'arcy Liu

#include<iostream>
#include "Pila.h"
using namespace std;

int main() {
	int opc;
	int dato;
	Pila p;
	do {
		cout<<"1. Inicializar pila"<<endl;
		cout<<"2. Ingresar dato"<<endl;
		cout<<"3. Eliminar dato"<<endl;
		cout<<"4. Mostrar cima"<<endl;
		cout<<"5. Mostrar datos de la pila"<<endl;
		cout<<"6. Total numeros pares"<<endl;
		cout<<"7. Total numeros impares"<<endl;
		cout<<"8. Suma de todos los valores de la pila"<<endl;
		cout<<"9. Ordenar los valores de la pila (ascendente)"<<endl;
		cout<<"10. Vaciar pila"<<endl;
		cout<<"11. Salir"<<endl;
		cout<<"> ";
		cin>>opc;
		switch(opc) {
			case 1:
				p.Inicializar();
				cout<<"Se ha inicializado correctamente."<<endl;
				break;
			case 2:
				cout<<"Ingrese un numero entero: >";
				cin>>dato;
				if(p.Push(dato) == -1) {
					cout<<"La pila esta llena!"<<endl; //Overflow
				}else {
					cout<<"Dato ingresado correctamente."<<endl;
				}
				break;
			case 3:
				if(p.Pop() == -1) {
					cout<<"La pila esta vacia!"<<endl; //Underflow
				}else {
					cout<<"Se ha eliminado correctamente el dato de la cima"<<endl;
				}
				break;
			case 4:
				if(p.Cima() == -1) {
					cout<<"La pila esta vacia!"<<endl; 
				}else {
					cout<<"El dato que se encuentra en la cima es: "<<p.Cima()<<endl;
				}
				break;
			case 5:
				if(p.Cima() == -1) {
					cout<<"La pila esta vacia!"<<endl;
				}else {
					cout<<"Los datos de la pila son:"<<endl;
					p.MostrarDatos(0);
				}
				break;
			case 6:
				if(p.Cima() == -1) {
					cout<<"La pila esta vacia!"<<endl;
				}else {
					if(p.MostrarPares(0,0) == 0) {
						cout<<"No hay numeros pares!"<<endl;
					}else {
						cout<<"Los numeros pares de la pila son: "<<p.MostrarPares(0,0)<<endl;
					}
				}
				break;
			case 7:
				if(p.Cima() == -1) {
					cout<<"La pila esta vacia!"<<endl;
				}else {
					if(p.MostrarImpares(0,0) == 0) {
						cout<<"No hay numeros impares!"<<endl;
					}else {
						cout<<"Los numeros impares de la pila son: "<<p.MostrarImpares(0,0)<<endl;
					}
				}
				break;
			case 8:
				if(p.Cima() == -1) {
					cout<<"La pila esta vacia!"<<endl;
				}else {
					cout<<"La suma de todos los numeros de la pila es: "<<p.SumaNumeros(0,0)<<endl;
				}
				break;
			case 9:
				if(p.Cima() == -1) {
					cout<<"La pila esta vacia!"<<endl;
				}else {
					p.ordenarNumerosAsc(0,-1,0);
					cout<<"Los valores se han ordenado ascendentemente"<<endl;
				}
				break;
			case 10:
				p.LimpiarPila();
				cout<<"Se ha limpiado la pila"<<endl;
				break;
			case 11:
				cout<<"Terminando programa..."<<endl;
				break;
			default:
				cout<<"Ingrese una de las opciones!"<<endl;
				break;
		}
		system("PAUSE");
		system("CLS");
	}while(opc != 11);
	return 0;
}
