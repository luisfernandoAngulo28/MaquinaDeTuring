//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//#include<Vcl.Grids.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
using namespace std;
class Instruccion{
	private:
		char mirar;
		char conv;
		char mov;
		int apuntador;
		public:
			   Instruccion();
			   void operacion(int &cabezal,char* &simb,int &i);
			   bool sepuede(int cabezal,char* &simbolo,char valornulo);
			   void set(char mirar1,char conv1,char mov1,int apuntador1);

 };

class Estado{
private:
	Instruccion Ins[100];
	char VInstruccion[100];
	int cantidad;//DeInstrucciones
	int numeroi;
	int cabezal;

public:
	Estado();

	bool Vacia();
	bool Pertenece(char ele);
	void CargarvalEstado(TStringGrid *MatrizDeEstados,char valores);
	void EliminarvalEstado(TStringGrid *MatrizDeEstados,char valores);

	void setnumero(int numero);
	void setInstruccion(char mirar,char conv,char mov,int apuntador);
	void ejecutar(int &cabezal,char* &simbolo, int &i,char valornulo);
	void LlenarUnCombobox(TComboBox *CoBox);

};


#endif
