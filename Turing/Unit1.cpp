//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Estado::Estado(){
   cantidad=0;
   numeroi=0;
   cabezal=-1;

}
bool Estado::Vacia(){
	return(cabezal==-1);
}

bool Estado::Pertenece(char ele){
	int i=0;
	while((i<=cabezal)&&(VInstruccion[i]!=ele)){
		i++;
	}
	return(i<=cabezal);
}

void Estado::CargarvalEstado(TStringGrid *MatrizDeEstados,char valor){

	if (!Pertenece(valor)) {
		 cabezal++;
		VInstruccion[cabezal]=valor;
		MatrizDeEstados->Cells[0][cabezal+1] = valor;

	}

}

void Estado::EliminarvalEstado(TStringGrid *MatrizDeEstados,char valores){
	if ((!Vacia())&&(Pertenece(valores))) {
		int i=0;
		while (VInstruccion[i]!=valores){
			i++;
		}
		for (int j = i; j < cabezal; j++) {
			VInstruccion[j]=VInstruccion[j+1];
			MatrizDeEstados->Cells[0][cabezal+1]=VInstruccion[j];
		}
		cabezal--;

	}
}
void Estado::setnumero(int numero){
	int numeroi=numero;
}
void Estado::setInstruccion(char mirar,char conv,char mov,int apuntador){
	Ins[cantidad].set(mirar,conv,mov,apuntador);
	cantidad++;
}
void Estado::ejecutar(int &cabezal,char* &simbolo, int &i,char valornulo){
	int i1; bool b;
	while(i==numeroi){
		i1=0; b=false;
		while((i1<cantidad)&&(i==numeroi)&&(b==false)){
			if(Ins[i1].sepuede(cabezal,simbolo,valornulo)){
				Ins[i1].operacion(cabezal,simbolo,i);
				b=true;
			}else{
			 i1++;
			}
		}
	}
}
void Estado::LlenarUnCombobox(TComboBox *CoBox){
	for (int j = 0; j <=cabezal; j++) {
		char Simbolo=VInstruccion[j];
		String s(&Simbolo, 1);
		CoBox->Items->Add(s);
	}
}
//-------------------------------------------------------------
 Instruccion::Instruccion(){

 }
 void Instruccion::operacion(int &cabezal,char* &simb,int &i){
   simb[cabezal]=conv;
   i=apuntador;
   if(mov=='D'){
	cabezal=cabezal+1;
   }else{
	  if(mov=='I'){
		cabezal=cabezal-1;

	  }else{
	   i=-1;
	  }
   }
 }
 bool Instruccion::sepuede(int cabezal,char* &simbolo,char valornulo){
 bool b=false;
	if(simbolo[cabezal]!= '\0'){
		if(simbolo[cabezal]==mirar){
			b=true;
		}
		if(mirar==valornulo){
			b=true;
		}
	}
	 return b;
 }
 void Instruccion::set(char mirar1,char conv1,char mov1,int apuntador1){
  mirar=mirar1;
  conv=conv1;
  mov=mov1;
  apuntador=apuntador1;
 }


