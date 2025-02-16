#include <iostream>

using namespace std;

class LSE{
	private:
		float num,mayor,promedio;
		LSE *ini,*sig;
	public:
		LSE(){
			num=mayor=promedio=0.0;
			ini=sig=NULL;
		}
		void lee(){
			cout<<"\nNumero: ";
			cin>>num;
		}
		void llena_lista(){
			LSE *nodo=new LSE;
			nodo->lee();
			if(ini==NULL)
				ini=nodo;
			else{
				nodo->sig=ini;
				ini=nodo;
			}
			cout<<"\n Nodo insertado";
		}
		void encuentra_mayor(){
			mayor=ini->num;
			for(LSE *a=ini; a!=NULL; a=a->sig){
				if(a->num>mayor){
					mayor=a->num;
				}
			}
		}
		void imprime(){
			for(LSE *i=ini; i!=NULL; i=i->sig){
				cout<<i->num<<endl;
			}
			cout<<"\nNumero mayor"<<mayor<<endl;
		}
		void hacer(){
			char rep;
			do{
				llena_lista();
				cout<<"otro nodo? S\N";
				cin>>rep;
			}while(rep=='s' or rep=='S');
			encuentra_mayor();
			imprime();
			Promedio();
		}
		void Promedio(){
			int contador=0;
			float suma=0;
			for(LSE *p=ini; p!=NULL; p=p->sig){
				contador++;
				suma=suma+p->num;
			}
			promedio=suma/contador;
			cout<<"Promedio : "<<promedio<<endl;
		}
		~LSE(){
			LSE *aux;
			while(ini){
				aux=ini;
				ini=ini->sig;
				delete aux;
			}			
		}
};
int main() {
	LSE L;
	L.hacer();
	return 0;
};
