//---------------------------------------------------------------------------

#pragma hdrstop

#include "UMatrizV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

MatrizV::MatrizV() {
	 df = 0;
	 dc = 0;
	 repe = "0";


	nt = 0;
	vf = new int[0];
	vc = new int[0];
   vd = new String[0];
}
MatrizV::MatrizV(int f, int c,String Elemento_Predominante){
	df = f;
	dc = c;
	repe = Elemento_Predominante;

	nt = f*c;
	vf = new int[0];
	vc = new int[0];
	vd = new String[0];
	for (int i = 0; i <= nt; i++) {
		vf[i] = df;
		vc[i] = dc;
		vd[i] = repe;
	}

}

void MatrizV::dimensionar(int f, int c) {
	df = f;
	dc = c;
	vf = new int[df * dc];
	vc = new int[df * dc];
	vd = new String[df * dc];
}

int MatrizV::dimension_fila() {
	return df;
}

int MatrizV::dimension_columna() {
	return dc;
}

int MatrizV::posicion(int f, int c) {
	for (int i = 0; i < nt; i++) {
		if (vf[i] == f && vc[i] == c)
			return i;
	}
	return -1;
}

void MatrizV::poner(int f, int c, String valor) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		int lugar = posicion(f, c);
		if (lugar == -1 && nt < (df * dc)) // nt < MAX_MV
		{ // insertar a lo ultimo
			if (valor != repe) {
				vd[nt] = valor;
				ShowMessage(valor);
				vf[nt] = f;
				vc[nt] = c;
				nt++;
			}
		}
		else {
			vd[lugar] = valor;
			if (valor == repe) {
				for (int i = lugar; i < nt; i++) {
					vf[i] = vf[i + 1];
					vc[i] = vc[i + 1];
					vd[i] = vd[i + 1];
				}
				nt--;
			}
		}
	}
}

String MatrizV::elemento(int f, int c) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		int lugar = posicion(f, c);
		if (lugar >= 0)
			return vd[lugar];
		else
			return repe;
	}
	else{
	  ShowMessage("ERROR FUERA DE RANGO");
		//cout << "ERROR FUERA DE RANGO\n";
	}

}

void MatrizV::definir_valor_repetido(char valor) {
	bool hayRepe = false;
	for (int i = 0; i < nt && hayRepe == false; i++) {
		if (vd[i] == valor)
			hayRepe = true;
	}
	if (nt == 0 || hayRepe == false) {
		repe = valor;
	}
	else {
		String nRep = valor;
		String aRep = repe;
		for (int i = 1; i <= df; i++) {
			for (int j = 1; j <= dc; j++) {
				String e = elemento(i, j);
				if (e == nRep) {
					int lugar = posicion(i, j);
					for (int k = lugar; k < nt; k++) {
						vf[k] = vf[k + 1];
						vc[k] = vc[k + 1];
						vd[k] = vd[k + 1];
					}
					nt--;
				}
				else if (e == aRep) {
					vd[nt] = aRep;
					vf[nt] = i;
					vc[nt] = j;
					nt++;
				}
			}
		}
		repe = valor;
	}
}

/*
 | 3 0 5 |
 | 0 1 0 |
 | 0 0 9 | */
String MatrizV::to_str() {
	String salida ="";
	for (int i = 1; i <= df; i++) {
		salida = salida+ "| ";
		for (int j = 1; j <= dc; j++) {
			String valor = elemento(i, j);
			//r += to_string(e) + "  ";
			  salida=salida+" "+valor+" ";
		}
		salida += "|\n";
	}
	//salida += "NT: " + to_tring(nt) + "\n";
	/*
	 int max = df * dc;
	 r += "vf: ";
	 for (int i = 0; i < max; i++)
	 r += to_string(vf[i]) + ",";
	 r += "\nvc: ";
	 for (int i = 0; i < max; i++)
	 r += to_string(vc[i]) + ",";
	 r += "\nvd: ";
	 for (int i = 0; i < max; i++)
	 r += to_string(vd[i]) + ",";
	 */
	return salida;
}

String MatrizV::MostrarVector() {
	String salida=" 0 ";
	 int max = df * dc;
	 for (int i = 0; i < max; i++){
		if(vd[i]!=repe){
		   salida=vd[i];
		}
	 }

	 return salida;
}
void MatrizV::Imprimir(TStringGrid *MatrizDeEstados){

		 nt++;
		MatrizDeEstados->Cells[nt+1][1] = MostrarVector();
}

int MatrizV::ColCount(){
	return df;
}

int MatrizV::RowCount(){
	return dc;
}

String MatrizV::ValorD(){
	return dc;
}




