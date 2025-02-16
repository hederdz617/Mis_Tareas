#include<iostream>

using namespace std;

class LDE{
	private:
		float num,mayor,contador,s,promedio;
		LDE *ini1,*ini2,*der,*izq;
	public:
		LDE(){
			num=mayor=contador=promedio=s=0.0;
			ini1=ini2=der=izq=NULL;
		}
		void Numero(){
			cout<<"Dame Numero"<<endl;
			cin>>num;
		}
		void Meter_Der(){
			LDE *nodo=new LDE;
			nodo->Numero();
			if(ini1 == NULL)
				ini1=ini2=nodo;
			else{
				nodo->izq=ini2;
				ini2->der=nodo;
				ini2=nodo;
			}
		}
		void Meter_Izq(){
			LDE *nodo=new LDE;
			nodo->Numero();
			if(ini1==NULL)
				ini1=ini2=nodo;
			else{
				ini1->izq=nodo;
				nodo->der=ini1;
				ini1=nodo;
			}
		}
		void Menu(){
			char caso;
			do{
				cout<<"\nMenu de LDE\n"
					<<"\nElige una opcion: "
					<<"\n1.-Inserta por la Der"
					<<"\n2.-Inserta por la Izq"
					<<"\n3.-Imprime"
					<<"\n4.-Salir\n";
				cin>>caso;
				switch(caso){
					case '1':
						Meter_Der();
						break;
					case '2':
						Meter_Izq();
						break;
					case '3':
						Imprimir();
						break;		
				}
			}while(caso !='4');	
		}
		void Mayor(){
			mayor=ini1->num;
			for(LDE *M=ini1; M; M=M->der){
				if(M->num >mayor){
					mayor=M->num;
				}
			}
		}
		void Suma(){
			for(LDE *c=ini1;c;c=c->der){
				contador=contador+c->num;
			}
		}
		void Promedio(){
			LDE *P=ini1;
			do{
				s++;
				P=P->der;
			}while(P);
			promedio=contador/s;
		}
		void Imprimir(){
			cout<<"\n\nLos datos de la LDE son: ";
			for(LDE *a=ini1; a; a=a->der){
				cout<<a->num<<"\t";
			}
			Mayor();
			cout<<"\nEl numero mayor es: "<<mayor<<endl;
			Suma();
			cout<<"\nLa suma de los datos es: "<<contador<<endl;
			Promedio();
			cout<<"\nEl promedio de los datos es: "<<promedio<<endl;
		}
		~LDE(){
			LDE *aux;
			while(ini1){
				aux=ini1;
				ini1=ini1->der;
				delete aux;
			}
		}
};
int main(){
	LDE L;
	L.Menu();
	return 0;
}
