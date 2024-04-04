#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *next;
	int priority;
	Nodo *siguiente;
	
	
}*ultimo;
void menu();
Nodo *crearNodo (int);
void insertarNodo(Nodo *&,int); 
Nodo *arbol=NULL;
void mostrarArbol(Nodo *,int);
void insert_pila(Nodo *&list,int dato,int priority);
void insert_cola(Nodo *&list,int dato,int priority);
void showList(Nodo *&list);
void detele(Nodo *&list);
void mostrar(Nodo *&lista);


int main(){
	menu();
	
	
	
	getch();
	return 0;
	
}

void menu(){
	
	int dato,opcion,contador=0;int priority;	Nodo *list=NULL;
	
	do{
		cout<<"\t.:Menu:."<<endl;
		cout<<"1. Agregar a pilas"<<endl;
		cout<<"2. Agregar a colas"<<endl;
		cout<<"3. Mostrar Pila"<<endl;
		cout<<"4. Mostrar Cola"<<endl;
		cout<<"5. Mostrar Lista"<<endl;
		cout<<"6. Eliminar"<<endl;
		cout<<"7. Mostrar arbol"<<endl;
		cout<<"8. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		switch(opcion){
			 case 1:{
				cout<<"\tAGREGAR PROCESO"<<endl<<endl;
				cout<<"Valor del proceso: ";cin>>dato;	
				cout<<"Prioridad del proceso: ";cin>>priority;
					insert_pila(list,dato,priority);	
					cout<<"\n";
					system("pause");
					break;
				
				}
				case 2:{
					cout<<"\tAGREGAR PROCESO"<<endl<<endl;
					cout<<"Valor del proceso: ";cin>>dato;	
					cout<<"Prioridad del proceso: ";cin>>priority;
					insert_cola(list,dato,priority);	
					cout<<"\n";
					system("pause");
			
					break;
				}
				case 3:{
					
					showList(list);
				
				    system("pause");
				
					break;
				}
				case 4:{
					
					showList(list);
				
				    system("pause");
				
					break;
				}
				case 5:{
					
					
					mostrar(list);
					system("pause");
					
					
					break;
				}
				case 6:{
					
					detele(list);
					system("pause");
					break;
				}
			
		
			case 7: cout<<"\nMostrando el arbol\n\n";
			mostrarArbol(arbol,contador);
			cout<<"\n";
			system("pause");
			break;
		}
		system("cls");
	}while(opcion !=8);
	
	
}
void insert_pila(Nodo *&list,int dato,int priority){
	
	Nodo *newNodo= new Nodo();
	newNodo->dato=dato;
	newNodo->priority=priority;
	Nodo *aux1=list;
	Nodo *aux2;
	
	while(aux1!=NULL && aux1->priority<priority){
		aux2=aux1;
		aux1=aux1->next;
	}
	
	if(aux1==list){
		list=newNodo;
		
	}
	else{
		aux2->next=newNodo;
	}
	newNodo->next=aux1;
}

void insert_cola(Nodo *&list,int dato,int priority){
	Nodo *newNodo= new Nodo();
	newNodo->dato=dato;
	newNodo->priority=priority;
	Nodo *aux1=list;
	Nodo *aux2;
	
	while(aux1!=NULL && aux1->priority<=priority){
		aux2=aux1;
		aux1=aux1->next;
	}
	
	if(aux1==list){
		list=newNodo;
		
	}
	else{
		aux2->next=newNodo;
	}
	newNodo->next=aux1;	
}
void showList(Nodo *&list){
	
	Nodo *aux=list;
	
	while(aux!=NULL){
		cout<<"[ DATA="<<aux->dato<<", Priority="<<aux->priority<<"] -> ";
		aux=aux->next;
	}
	cout<<"NULL"<<endl;		
}

void detele(Nodo *&list){
	Nodo *aux=list;
	if(list!=NULL){
		list=list->next;
		cout<<"PROCESO DESPACHADO:"<<endl;
		cout<<"[ DATA="<<aux->dato<<", Priority="<<aux->priority<<"]"<<endl;
		delete aux;		
	}
	else{
		cout<<"NO HAY PROCESOS"<<endl;
	}

}

void insertar(int n,Nodo *&list){
	
	Nodo *newNodo=new Nodo();
	newNodo->dato=n;
	Nodo *aux1=list;
	Nodo *aux2;
	
	if(list==NULL){
		ultimo=newNodo;
		ultimo->siguiente=newNodo;
	}
	else{
		newNodo->siguiente=aux1;
		ultimo->siguiente=newNodo;
		
	}
	
	list=newNodo;
	
	
	
}
void mostrar(Nodo *&lista){
	bool entro=false;
	Nodo *buscar = lista;
	bool inicio;
	if(buscar->siguiente!=buscar){
		entro=true;
	}
	cout<<buscar->dato<<" -> ";
	buscar=buscar->siguiente;

	while(buscar!=ultimo){
		
		cout<<buscar->dato<<" -> ";		
		buscar=buscar->siguiente;	
			
	}
	if(entro){
		cout<<buscar->dato<<endl;//mostrando el ultimo
	}

	

}

Nodo *crearNodo(int n){
	
	Nodo *newNodo = new Nodo();
	
	newNodo->dato = n;
	newNodo->der= NULL;
	newNodo->izq= NULL;
	
	return newNodo;
	
}

void insertarNodo(Nodo *&arbol,int n){
	if(arbol == NULL){
		Nodo *newNodo = crearNodo(n);
		arbol = newNodo;
		
		
	}
	else{
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){
			insertarNodo(arbol->izq,n);	
		}
		else{
			insertarNodo(arbol->der,n);
		}
	}
	
	
}

void mostrarArbol(Nodo *arbol,int cont){
	
	
	if(arbol == NULL){
		return;
}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
			
			
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
		
	}	
							
}
