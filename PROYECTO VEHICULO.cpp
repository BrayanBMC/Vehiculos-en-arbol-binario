#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cstdlib>
#include <cstdlib>


using namespace std;

class Vehiculo;
class Pila;

class Pila{
	Vehiculo *dato;
	Pila *sig;
	public:
		void iniciarPila(Pila *&cab){
			cab=new Pila;
			cab->dato=NULL;
			cab->sig=NULL;
		}
		bool pilaVacia(Pila *cab){
			if(!cab->sig)
				return true;
			else
				return false;
		}
		void agregarPila(Pila *&cab, Vehiculo *dato){
			Pila *aux=cab;
			while(aux->sig)
		    	aux=aux->sig;
			aux->sig=new Pila;
			aux->sig->sig=NULL;
			aux->sig->dato=dato;
		}
		Vehiculo *retirarPila(Pila *&cab){
			Pila *aux=cab,*aux1;
			Vehiculo *dir_dato;
			aux1=aux;
			if(!pilaVacia(aux)){
			while(aux->sig){
				aux1=aux;
				aux=aux->sig;
			}
			aux1->sig=NULL;
			dir_dato=aux->dato;
			delete aux;
			return dir_dato;
			}
			else
				cout<<"  Pila vacia ...."<<endl;
		}
};

class Vehiculo{
	public: 
	char placa[7];
	char marca[25];
	char color[25];
	int potencia;
	bool tipo;
	Vehiculo *izq;
	Vehiculo *der;
	Vehiculo *padre;
	
	
	void crearRaiz(Vehiculo *&raiz, char placa[], char marca[], char color[],int potencia, bool tipo, Vehiculo *padre){
		raiz=new Vehiculo;
		strcpy(raiz->placa,placa);
		strcpy(raiz->marca,marca);
		strcpy(raiz->color,color);
		raiz->potencia=potencia;
		raiz->tipo=tipo;
		raiz->izq=NULL;
		raiz->der=NULL;
		raiz->padre=padre;
		/*cout<<"  PLACA = "<<raiz->placa<<endl;
	    cout<<"  MARCA = "<<raiz->marca<<endl;
		cout<<"  COLOR = "<<raiz->color<<endl;
	    cout<<"  POTENCIA = "<<raiz->potencia<<endl;
		cout<<" "<<endl;*/
	}
	
	void agregarIzq(Vehiculo *&temp, char placa[], char marca[], char color[],int potencia, bool tipo,Vehiculo *padre){
		Vehiculo *nuevo;
		nuevo=new Vehiculo;
		strcpy(nuevo->placa, placa);
		strcpy(nuevo->marca,marca);
		strcpy(nuevo->color,color);
		nuevo->potencia=potencia;
		nuevo->tipo=tipo;
		nuevo->izq=NULL;
		nuevo->der=NULL;
		nuevo->padre=padre;
		temp->izq=nuevo;
		/*cout<<"  PLACA = "<<temp->placa<<endl;
	    cout<<"  MARCA = "<<temp->marca<<endl;
		cout<<"  COLOR = "<<temp->color<<endl;
	    cout<<"  POTENCIA = "<<temp->potencia<<endl;*/
	}
	
	void agregarDer(Vehiculo *&temp, char placa[], char marca[], char color[],int potencia, bool tipo,Vehiculo *padre){
		Vehiculo *nuevo;
		nuevo=new Vehiculo;
		strcpy(nuevo->placa, placa);
		strcpy(nuevo->marca,marca);
		strcpy(nuevo->color,color);
		nuevo->potencia=potencia;
		nuevo->tipo=tipo;
		nuevo->izq=NULL;
		nuevo->der=NULL;
		temp->der=nuevo;
		/*cout<<"  PLACA = "<<temp->placa<<endl;
	    cout<<"  MARCA = "<<temp->marca<<endl;
		cout<<"  COLOR = "<<temp->color<<endl;
	    cout<<"  POTENCIA = "<<temp->potencia<<endl;*/
	}
	
	
	/*void crearArbol(Vehiculo *&raiz){
		Vehiculo *temp1,*temp2;
		char placa[7];
	    char marca[25];
	    char color[25];
	    int potencia;
	    int tipo;
		
		while(placa[0]!='<'){
			fflush(stdin);
			cout<<"  DIGITE LA PLACA: ";
			cin.getline(placa,7,'\n');
			for (int i=0; placa[i] !='\0'; ++i){
				placa[i]=toupper(placa[i]);
			}
			if(!raiz){
				if(placa[0]!='<'){
					fflush(stdin);
					cout<<"  DIGITE LA MARCA: ";
					cin.getline(marca,26,'\n');
					fflush(stdin);
					cout<<"  DIGITE EL COLOR: ";
					cin.getline(color,26,'\n');
					fflush(stdin);
					cout<<"  DIGITE LA POTENCIA: ";
					cin>>potencia;
					int t,c,p; 	
			    	cout<<"  ELIJA EL TIPO 1=CARGA 2=PASAJEROS: ";
			    	cin>>t;
			    	
			    	if(t==1){
			    		cout<<"  VEHICULO DE CARGA"<<endl;
			    		tipo=1;
					}else{
						cout<<"  VEHICULO DE PASAJEROS"<<endl;
						tipo=2;
					}
					crearRaiz(raiz,placa,marca,color,potencia,tipo);
					cout<<"  VEHICULO INGRESADO CON EXITO COMO RAIZ"<<endl;
					cout<<" "<<endl;
				}//fin raiz
			}else{//si raiz ya existe
				if(placa[0]!='<'){
					temp1=temp2=raiz;
					while(temp2&&strcmp(placa,temp1->placa)!=0){
						temp1=temp2;
						if(strcmp(placa,temp1->placa)<0){
							temp2=temp2->izq;		
						}else{
							temp2=temp2->der;
						}
					}
					
					if(strcmp(placa,temp1->placa)==0){
						cout<<" PLACA REPETIDA INTENTE DE NUEVO"<<endl;
					}
					
					if(strcmp(placa,temp1->placa)<0){
						fflush(stdin);
						cout<<"  DIGITE LA MARCA: ";
						cin.getline(marca,26,'\n');
						fflush(stdin);
						cout<<"  DIGITE EL COLOR: ";
						cin.getline(color,26,'\n');
						fflush(stdin);
						cout<<"  DIGITE LA POTENCIA: ";
						cin>>potencia;
							
						int t,c,p; 	
					    cout<<"  ELIJA EL TIPO 1=CARGA 2=PASAJEROS: ";
					    cin>>t;
					    	
					    if(t==1){
					    	cout<<"  VEHICULO DE CARGA"<<endl;
					    	tipo=1;
						}else{
							cout<<"  VEHICULO DE PASAJEROS"<<endl;
							tipo=2;
						}
						agregarIzq(temp1,placa,marca,color,potencia,tipo);
						cout<<"  VEHICULO INGRESADO CON EXITO POR LA IZQUIERDA"<<endl;
						cout<<" "<<endl;					
					}else{
						
						if(strcmp(placa,temp1->placa)>0){
							fflush(stdin);
							cout<<"  DIGITE LA MARCA: ";
							cin.getline(marca,26,'\n');
							fflush(stdin);
							cout<<"  DIGITE EL COLOR: ";
							cin.getline(color,26,'\n');
							fflush(stdin);
							cout<<"  DIGITE LA POTENCIA: ";
							cin>>potencia;
									
							int t,c,p; 	
							cout<<"  ELIJA EL TIPO 1=CARGA 2=PASAJEROS: ";
							cin>>t;
							    	
							if(t==1){
							    cout<<"  VEHICULO DE CARGA"<<endl;
							    tipo=1;
							}else{
								cout<<"  VEHICULO DE PASAJEROS"<<endl;
								tipo=2;
							}
							agregarDer(temp1,placa,marca,color,potencia,tipo);
						    cout<<"  VEHICULO INGRESADO CON EXITO POR LA DERECHA"<<endl;
					        cout<<" "<<endl;	
						}	
					}
				}
			}
		}	
	}*/
	
	//funcion para crear el arbol
	void crearArbol(Vehiculo *&raiz, Vehiculo *padre){
		Vehiculo *temp1,*temp2;
		char placa[7];
	    char marca[25];
	    char color[25];
	    int potencia;
	    int tipo;
	    
	    while(placa[0]!='!'){
	    	fflush(stdin);
	    	cout<<"  PARA TERMINAR DE INGRESAR PLACAS PULSE !"<<endl;
			cout<<"  DIGITE LA PLACA: ";
			cin.getline(placa,7,'\n');
			for (int i=0; placa[i] !='\0'; ++i){
				placa[i]=toupper(placa[i]);
			}
			if(placa[0]!='!'){
				if(!raiz){
					
					fflush(stdin);
					cout<<"  DIGITE LA MARCA: ";
					cin.getline(marca,25,'\n');
					fflush(stdin);
					cout<<"  DIGITE EL COLOR: ";
					cin.getline(color,25,'\n');
					fflush(stdin);
					cout<<"  DIGITE LA POTENCIA: ";
					cin>>potencia;
					int t,c,p; 	
			    	cout<<"  ELIJA EL TIPO 1=CARGA 2=PASAJEROS: ";
			    	cin>>t;
			    	
			    	if(t==1){
			    		cout<<"  VEHICULO DE CARGA"<<endl;
			    		tipo=false;
					}else{
						cout<<"  VEHICULO DE PASAJEROS"<<endl;
						tipo=true;
					}
					crearRaiz(raiz,placa,marca,color,potencia,tipo,NULL);
					cout<<"  VEHICULO INGRESADO CON EXITO COMO RAIZ"<<endl;
					cout<<" "<<endl;
					
				}else{
					temp1=temp2=raiz;
					while(temp2 && strcmp(placa,temp1->placa)!=0){
						temp1=temp2;
						if(strcmp(placa,temp1->placa)<0){
							temp2=temp2->izq;		
						}else{
							temp2=temp2->der;
						}
					}
					
					if(strcmp(placa,temp1->placa)==0){
						cout<<"  PLACA REPETIDA INTENTE DE NUEVO"<<endl;
					}else{
						if(strcmp(placa,temp1->placa)<0){
							
							fflush(stdin);
							cout<<"  DIGITE LA MARCA: ";
							cin.getline(marca,25,'\n');
							fflush(stdin);
							cout<<"  DIGITE EL COLOR: ";
							cin.getline(color,25,'\n');
							fflush(stdin);
							cout<<"  DIGITE LA POTENCIA: ";
							cin>>potencia;
								
							int t,c,p; 	
						    cout<<"  ELIJA EL TIPO 1=CARGA 2=PASAJEROS: ";
						    cin>>t;
						    	
						    if(t==1){
						    	cout<<"  VEHICULO DE CARGA"<<endl;
						    	tipo=false;
							}else{
								cout<<"  VEHICULO DE PASAJEROS"<<endl;
								tipo=true;
							}
							agregarIzq(temp1,placa,marca,color,potencia,tipo,raiz);
							cout<<"  VEHICULO INGRESADO CON EXITO POR LA IZQUIERDA"<<endl;
							cout<<" "<<endl;
							
						}else{
							
							fflush(stdin);
							cout<<"  DIGITE LA MARCA: ";
							cin.getline(marca,25,'\n');
							fflush(stdin);
							cout<<"  DIGITE EL COLOR: ";
							cin.getline(color,25,'\n');
							fflush(stdin);
							cout<<"  DIGITE LA POTENCIA: ";
							cin>>potencia;
									
							int t,c,p; 	
							cout<<"  ELIJA EL TIPO 1=CARGA 2=PASAJEROS: ";
							cin>>t;
							    	
							if(t==1){
							    cout<<"  VEHICULO DE CARGA"<<endl;
							    tipo=false;
							}else{
								cout<<"  VEHICULO DE PASAJEROS"<<endl;
								tipo=true;
							}
							agregarDer(temp1,placa,marca,color,potencia,tipo,raiz);
						    cout<<"  VEHICULO INGRESADO CON EXITO POR LA DERECHA"<<endl;
					        cout<<" "<<endl;					
						}
					}
				}
			}
		}
	}
	
	//Funcion que muestra los datos
	void mostrar(Vehiculo *raiz){
		cout<<" "<<endl;
		cout<<"  PLACA = "<<raiz->placa<<endl;
		cout<<"  MARCA = "<<raiz->marca<<endl;
		cout<<"  COLOR = "<<raiz->color<<endl;
		cout<<"  POTENCIA = "<<raiz->potencia<<endl;
		//cout<<"  TIPO = "<<raiz->tipo<<" (0=PASAJEROS---1=CARGA )"<<endl;

	}
	
	//Funcion inorden
	void inorden(Vehiculo *raiz){
			Pila *aux,obj_pila;
			Vehiculo *temp=raiz;
			cout<<"  LISTA DE VEHICULOS INGRESADOS VEHICULOS"<<endl;
			obj_pila.iniciarPila(aux);
			while(temp){
				obj_pila.agregarPila(aux,temp);
				temp=temp->izq;
			}
			while(!obj_pila.pilaVacia(aux)){
				temp=obj_pila.retirarPila(aux);
				mostrar(temp);
				temp=temp->der;	
				while(temp){
					obj_pila.agregarPila(aux,temp);
					temp=temp->izq;
				}					
			}
		}
		
		/*void inOrden(Vehiculo *raiz){
			if(raiz==NULL){
				return;
			}
			else{
				inOrden(raiz->izq);
				mostrar(raiz);
				inOrden(raiz->der);
			}
		}*/
		
		//funcion que mustra vehiculos de carga a base de la funcion inorden
		void mostrarCarga(Vehiculo *raiz){
			Pila *aux,obj_pila;
			Vehiculo *temp=raiz;
			cout<<"  VEHICULOS DE CARGA"<<endl;
			obj_pila.iniciarPila(aux);
			while(temp){
				obj_pila.agregarPila(aux,temp);
				temp=temp->izq;
			}
			while(!obj_pila.pilaVacia(aux)){
				temp=obj_pila.retirarPila(aux);
				
				if(temp->tipo==false){
					mostrar(temp);
				}
				temp=temp->der;	
				while(temp){
					obj_pila.agregarPila(aux,temp);
					temp=temp->izq;
				}					
			}
		}
		
		//funcion que mustra vehiculos de pasajeros a base de la funcion inorden
		void mostrarPasajeros(Vehiculo *raiz){
			Pila *aux,obj_pila;
			Vehiculo *temp=raiz;
			cout<<"  VEHICULOS DE PASAJEROS"<<endl;
			obj_pila.iniciarPila(aux);
			while(temp){
				obj_pila.agregarPila(aux,temp);
				temp=temp->izq;
			}
			while(!obj_pila.pilaVacia(aux)){
				temp=obj_pila.retirarPila(aux);
				
				if(temp->tipo==true){
					mostrar(temp);
				}
				temp=temp->der;	
				while(temp){
					obj_pila.agregarPila(aux,temp);
					temp=temp->izq;
				}					
			}
		}
		
		/*bool buscar(Vehiculo *raiz, char placa[]){
			Vehiculo *temp=raiz;
			if(!temp){
				return false;
			}else{
				if(strcmp(placa,temp->placa)==0){
					return true;
				}else{
					if(strcmp(placa,temp->placa)<0){
						return buscar(temp->izq,placa);
					}else{
						if(strcmp(placa,temp->placa)>0){
							return buscar(temp->der,placa);
						}
					}
				}
			}
		}
		
		bool buscarInt(Vehiculo *raiz, int potencia){
			Vehiculo *temp=raiz;
			if(!temp){
				return false;
			}else{
				if(temp->potencia==potencia){
					return true;
				}else{
					if(potencia<temp->potencia){
						return buscarInt(temp->izq,potencia);
					}else{
						if(potencia>temp->potencia){
							return buscarInt(temp->der,potencia);
						}
					}
				}
			}
		}*/
		
		
		//funcion que busca la placa dentro del arbol dntro del inorden
		void buscarArbol(Vehiculo *raiz){
			Pila *aux,obj_pila;
			Vehiculo *temp=raiz;
			cout<<"  VEHICULOS POR PLACA"<<endl;
			obj_pila.iniciarPila(aux);
			while(temp){
				obj_pila.agregarPila(aux,temp);
				temp=temp->izq;
			}
			cout<<"  INGRESE LA PLACA A BUSCAR: ";
		    fflush(stdin);
		    cin.getline(placa,7,'\n');
		    for (int i=0; placa[i] !='\0'; ++i){
				placa[i]=toupper(placa[i]);
			}
			while(!obj_pila.pilaVacia(aux)){
				temp=obj_pila.retirarPila(aux);
				
				if(strcmp(placa,temp->placa)==0){
					mostrar(temp);
				}

				temp=temp->der;	
				while(temp){
					obj_pila.agregarPila(aux,temp);
					temp=temp->izq;
				}					
			}
		}
		
		/*bool buscarCol(Vehiculo *raiz, char color[]){
			Vehiculo *temp=raiz;
			if(!temp){
				return false;
			}else{
				if(strcmp(color,temp->color)==0){
					return true;
				}else{
					if(strcmp(color,temp->color)<0){
						return buscar(temp->izq,color);
					}else{
						if(strcmp(color,temp->color)>0){
							return buscar(temp->der,color);
						}
					}
				}
			}
		}*/
		
		//funcion buscar vehiculo por color dentro de inorden
		void buscarColor(Vehiculo *raiz){
			Pila *aux,obj_pila;
			Vehiculo *temp=raiz;
			cout<<"  VEHICULOS POR COLOR"<<endl;
			obj_pila.iniciarPila(aux);
			while(temp){
				obj_pila.agregarPila(aux,temp);
				temp=temp->izq;
			}
			cout<<"  INGRESE EL COLOR A BUSCAR: ";
		    fflush(stdin);
		    cin.getline(color,25,'\n');
			while(!obj_pila.pilaVacia(aux)){
				temp=obj_pila.retirarPila(aux);
				
				if(strcmp(color,temp->color)==0){
					mostrar(temp);
				}

				temp=temp->der;	
				while(temp){
					obj_pila.agregarPila(aux,temp);
					temp=temp->izq;
				}					
			}
		}
		
		/*bool buscarPO(Vehiculo *raiz, int potencia){
			Vehiculo *temp=raiz;
			if(!temp){
				return false;
			}else{
				if(temp->potencia==potencia){
					return true;
				}else{
					if(potencia<temp->potencia){
						return buscarPO(temp->izq,potencia);
					}else{
						if(potencia>temp->potencia){
							return buscarPO(temp->der,potencia);
						}
					}
				}
			}
		}*/
		
		//funcion buscar vehiculo por potencia dentro del inorden
		void buscarPotencia(Vehiculo *raiz){
			Pila *aux,obj_pila;
			Vehiculo *temp=raiz;
			cout<<"  VEHICULOS POR POTENCIA"<<endl;
			obj_pila.iniciarPila(aux);
			while(temp){
				obj_pila.agregarPila(aux,temp);
				temp=temp->izq;
			}
			cout<<"  INGRESE LA POTENCIA A BUSCAR: ";
		    cin>>potencia;
			while(!obj_pila.pilaVacia(aux)){
				temp=obj_pila.retirarPila(aux);
				
				if(temp->potencia==potencia){
					mostrar(temp);
				}
				temp=temp->der;	
				while(temp){
					obj_pila.agregarPila(aux,temp);
					temp=temp->izq;
				}					
			}
		}
		
		
	/*void eliminar(Vehiculo *&raiz, char placa[]){
		if(raiz=NULL){
			return;
		}else{
			if(strcmp(placa,raiz->placa)<0){
				eliminar(raiz->izq,placa);
			}else{
				if(strcmp(placa,raiz->placa)>0){
					eliminar(raiz->der,placa);
				}else{
					eliminarNodo(raiz);
				}
			}
		}
	}	
	
	Vehiculo *minimo(Vehiculo *raiz){
		if(raiz==NULL){
			return NULL;
		}
		if(raiz->izq){
			return minimo(raiz->izq);
		}else{
			return raiz;
		}
	}
	
	void reemplazar(Vehiculo *raiz, Vehiculo *nuevoNodo){
		if(raiz->padre){
			if(raiz->placa==raiz->padre->izq->placa){//strcmp(raiz->placa,raiz->padre->izq->placa)==0
				raiz->padre->izq=nuevoNodo;
				
			}else{
				if(raiz->placa==raiz->padre->der->placa){
					raiz->padre->der=nuevoNodo;
				}
			}
		}
		if(nuevoNodo){
			nuevoNodo->padre=raiz->padre;	
		}
	}
	
	void eliminarNodo(Vehiculo *nodoEliminar){
		if(nodoEliminar->izq && nodoEliminar->der){
			Vehiculo *menor=minimo(nodoEliminar->der);
			//nodoEliminar->placa=menor->placa;
			strcpy(nodoEliminar->placa,menor->placa);
			eliminarNodo(menor);
		}else{
			if(nodoEliminar->izq){
				reemplazar(nodoEliminar,nodoEliminar->izq);
				destruirNodo(nodoEliminar);
			}else{
				if(nodoEliminar->der){
					reemplazar(nodoEliminar,nodoEliminar->der);
					destruirNodo(nodoEliminar);
				}else{
					reemplazar(nodoEliminar,NULL);
					destruirNodo(nodoEliminar);
				}
			}
		}	
	}
*/
	
	void destruirNodo(Vehiculo *temp){
		temp->izq=NULL;
		temp->der=NULL;
		
		delete temp;
	}
	
	void eliminar(Vehiculo *raiz){
			Pila *aux,obj_pila;
			Vehiculo *temp=raiz;
			cout<<"  VEHICULOS POR PLACA"<<endl;
			obj_pila.iniciarPila(aux);
			while(temp){
				obj_pila.agregarPila(aux,temp);
				temp=temp->izq;
			}
			cout<<"  INGRESE LA PLACA A BUSCAR: ";
		    fflush(stdin);
		    cin.getline(placa,7,'\n');
		    for (int i=0; placa[i] !='\0'; ++i){
				placa[i]=toupper(placa[i]);
			}
			while(!obj_pila.pilaVacia(aux)){
				temp=obj_pila.retirarPila(aux);
				
				if(strcmp(placa,temp->placa)==0){
					if(temp->izq==NULL||temp->der==NULL){
				        mostrar(temp);
				        destruirNodo(temp);
				        cout<<"  EL REGISTRO FUE ELIMINADO ";
				    }else{
				    	if(temp->izq!=NULL||temp->der!=NULL){
				    		
						}
					}
				}

				temp=temp->der;	
				while(temp){
					obj_pila.agregarPila(aux,temp);
					temp=temp->izq;
				}					
			}
		}
	
	
	void menu(Vehiculo *&raiz){
		Vehiculo *temp1,*temp2;
		int opcion,tipe;
		char placa[7];
	    char marca[25];
	    char color[25];
	    int potencia;
	    bool tipo;	
			
		do{
			system("cls");
			cout<<endl;
			cout<<"  > REGISTRO DE VEHICULOS <"<<endl;
			cout<<endl;
			cout<<"  [1]: AGREGAR VEHICULO"<<endl;
			cout<<"  [2]: BUSCAR POR PLACA"<<endl;
			cout<<"  [3]: MOSTRAR VEHICULOS"<<endl;
			cout<<"  [4]: MOSTRAR VEHICULOS DE CARGA"<<endl;
			cout<<"  [5]: MOSTRAR VEHICULOS DE PASAJEROS"<<endl;
			cout<<"  [6]: REPORTES DE VEHICULOS POR COLOR"<<endl;
			cout<<"  [7]: REPORTES DE VEHICULOS POR POTENCIA"<<endl;
			cout<<"  [8]: ELIMINAR VEHICULO"<<endl;
			cout<<"  [9]: SALIR"<<endl;
			cout<<endl;
			cout<<"  DIGITE OPCION: ";
			cin>>opcion;
				
			if(opcion==1){
				system("cls");
				crearArbol(raiz,NULL);	
			}
				
			if(opcion==2){
				system("cls");
				buscarArbol(raiz);
			}
			if(opcion==3){
				system("cls");
				inorden(raiz);	
			}
			if(opcion==4){
				system("cls");
				mostrarCarga(raiz);	
			}
			if(opcion==5){
				system("cls");
				mostrarPasajeros(raiz);	
			}
			if(opcion==6){
				system("cls");
				buscarColor(raiz);	
		    }
		    if(opcion==7){
				system("cls");
				buscarPotencia(raiz);	
		    }
		    if(opcion==8){
				system("cls");	
				eliminar(raiz);
		    }
				
			cout<<endl<<endl<<"  ";
			system("pause");
			}while(opcion!=9);
		}

};
		
		

int main(){
	Vehiculo *raiz=NULL,*temp, obj_arbol;
	obj_arbol.menu(raiz);
		
	return 0;
}
