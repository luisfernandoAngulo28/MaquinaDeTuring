//---------------------------------------------------------------------------

#ifndef UCintaH
#define UCintaH
//#include<Vcl.Grids.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
using namespace std;
const int max=100;
const char VALOR_NULO='0';
  class Cinta{
	private:
		char simbolos[max]; //100
		char VSimbolo[max];
		int cabezal;
		char valornulo;
        int cant;
	public:
		Cinta();
		Cinta(char valornulo);
		bool Vacia();
		bool Pertenece(char ele);
		void CargarvalSimbolos(TStringGrid *M,char valores);
		void EliminarvalSimbolos(TStringGrid *M,char valores);
		void CargarvalCinta(TStringGrid *M,char valores);
		void crear(TStringGrid *M,String entrada,char valornulo);
		void moverDerecha(TStringGrid *M);
		void moverIzquierda(TStringGrid *M);
		void imprimir(TStringGrid *M);
		int  obtenerCabezal();
		char* obtenerSimbolo();
		void setcabezal();
		char obtenerValorNulo();
		void LlenarUnCombobox(TComboBox *CoBox);


  };
  #endif
