#include <cstddef>
#include<iostream>
using namespace std;

class Pila {
	private:
		//Declarar el tipo de arreglo de datos (int,float,varchar,bool)
		int cima;
		int fondo = -1;
		int tope;
		int array[5];
		
		bool PilaLlena() {
			if(cima <= tope) {
				return false;
			}else {
				return true; //Si la pila esta llena regresa true, si no, regresa false
			}
		}
		
		bool PilaVacia() {
			if(cima-1 == fondo) {
				return true; //Si la pila esta vacía regresa true, si no, regresa false
			}else {
				return false;
			}
		}
		
	public:
		void Inicializar() { //Sirve para inicializar los contadores y topes
			cima = 0;
			tope = (SizePila()) - 1;
			return;
		}
		
		int Push(int dato) {
			if(!PilaLlena()) {
				array[cima] = dato; 
				++cima;
				return 0; //Se insertó el elemento
			}else {
				return -1; //Indica que la pila está llena
			}
		}
		
		int Pop() {
			if(!PilaVacia()) {
				array[cima] = NULL;
				--cima;
				return 0; //Elemento eliminado correctamente
			}else {
				return -1; //Indica que la pila está vacía
			}
		}
		
		int Cima() {
			if(!PilaVacia()) {
				return array[cima-1]; //Valor de la cima
			}else {
				return -1; //Pila vacía
			}
		}
		
		void LimpiarPila() {
			if(PilaVacia()) {
				Inicializar();
				return;
			}else {
				Pop();
				LimpiarPila();
			}
			//Eliminar todos los elementos de la pila
		}
		
		int SizePila() {
			return sizeof(array)/sizeof(*array); //Devolverá el tamaño de la pila declarada
		}
		
		void MostrarDatos(int i) {
			//Recorre todos los elementos de la pila por medio de i (recursividad)
			if(i == cima) {
				return;
			}else {
				cout<<array[i]<<endl;
				++i;
				MostrarDatos(i);
			}
		}
		
		int MostrarPares(int i, int cont) {
			//Recorre los elementos de la pila y si el residuo de su división entre 2 es 0 aumenta 1 a cont
			if(i == cima) {
				return cont;
			}else {
				if(array[i]%2 == 0) {
					++cont;
				}
				++i;
				MostrarPares(i,cont);
			}
		}
		
		int MostrarImpares(int i, int cont) {
			//Recorre los elementos de la pila y si el residuo de su división entre 2 es distinto de 0 aumenta 1 a cont
			if(i == cima) {
				return cont;
			}else {
				if(array[i]%2 != 0) {
					++cont;
				}
				++i;
				MostrarImpares(i,cont);
			}
		}
		
		int SumaNumeros(int i, int cont) {
			//Recorre todo el array con i (recursividad) y suma los valores almacenados en cont
			if(i == cima) {
				return cont;
			}else {
				cont+=array[i];
				++i;
				SumaNumeros(i,cont);
			}
		}
		
		void ordenarNumerosAsc(int num, int cont, int pos) {
			if(pos == cima) {
				return;
			}else {
				if(cont==-1) {
					cont = cima-1;
				}
				if(array[pos] < array[cont]) {
					ordenarNumerosAsc(num, cont-1, pos);
				}
				if(array[pos] > array[cont]) {
					num = array[pos];
					array[pos] = array[cont];
					array[cont] = num;
					ordenarNumerosAsc(num, cont-1, pos);
				}
				if(array[pos] == array[cont]) {
					ordenarNumerosAsc(num, cima-1, pos+1);
				}
			}
		}
};
