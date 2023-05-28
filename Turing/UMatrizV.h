//---------------------------------------------------------------------------

#ifndef UMatrizVH
#define UMatrizVH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>

using namespace std;


const 	String repe="0";

class MatrizV {
private:
	int* vf;
	int* vc;
	//char* vd;
	String* vd;
	int df, dc;
	//char repe;
	String repe;
	int nt;

	int posicion(int f, int c);

public:
	MatrizV();
	MatrizV(int f, int c,String valor);
	void dimensionar(int f, int c);
	int dimension_fila();
	int dimension_columna();
	void poner(int f, int c, String valor);
	String elemento(int f, int c);
	void definir_valor_repetido(char valor);
	String to_str();
    String MostrarVector();
	//---------------------------------
	void Imprimir(TStringGrid *MatrizDeEstados);
	int ColCount();
	int RowCount();

	int VerificarRow(int f);
	int VerificarCol(int c);
	String ValorD();
};
#endif

