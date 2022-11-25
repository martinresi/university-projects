#include <iostream>
#include <iomanip>
#define maxTam 3 //<-----modificando esto se puede cambiar el tamaño maximo del juego

using namespace std;

void InicializaMatriz(int matriz[maxTam][maxTam]){
	for(int i = 0; i < maxTam; i++){
		for (int j = 0; j < maxTam; j++){
			matriz[i][j]=0;
		}
	}
}
void Espaciador(){
	for (int i = 0; i < maxTam; i++){
		cout << "-------";
	}
	cout << endl;
}
void MuestraMatriz(int matriz[maxTam][maxTam]){
	Espaciador();
	for(int i=0;i<maxTam;i++){
		for (int j = 0 ; j < maxTam; j++){
			if (j > 0){
				cout<<setw(7)<<"["<<matriz[i][j]<<"]";
			}
			else{
				cout<<"["<<matriz[i][j]<<"]";
			}
		}
		cout<<endl;
	}
	Espaciador();
}
void IngresaMatriz(int matriz[maxTam][maxTam]){
	for (int i = 0; i < maxTam; i++){
		cout << endl;
		for (int j = 0; j < maxTam; j++){
			cout << "Ingrese el elemento ["<<i<<"]["<<j<<"]: ";
			cin >> matriz[i][j];
		}
		cout << endl;
		if (i < maxTam-1){
			MuestraMatriz(matriz);
		}
	}
}
bool NumDentroRango(int matriz[maxTam][maxTam]){
	for (int i = 0; i < maxTam; i++){
		for (int j = 0; j < maxTam; j++){
			if (matriz[i][j] > maxTam || matriz[i][j] < 1){
			   return false;
			}
		}
	}
	return true;
}
bool VerificaFilaIgual(int matriz[maxTam][maxTam]){
	for (int fila = 0; fila < maxTam; fila++){
		for(int i = 0; i < maxTam; i++){
	        for(int j = 0; j < maxTam; j++){
	            if(matriz[fila][i] == matriz[fila][j] && i != j){
	                return true;
	            }
	        }
	    }
	}
	return false;
}
bool VerificaColumIgual(int matriz[maxTam][maxTam]){
	for (int fila = 0; fila < maxTam; fila++){
		for(int i = 0; i < maxTam; i++){
	        for(int j = 0; j < maxTam; j++){
	            if(matriz[i][fila] == matriz[j][fila] && i != j){
	                return true;
	            }
	        }
	    }
	}
	return false;
}
bool VerifDiagonIgual(int matriz[maxTam][maxTam]){
	for (int i = 0; i < maxTam-1; i++){
        for(int j = 0; j < maxTam-1; j++){
            if(matriz[i][i] == matriz[i+1][i+1]){
                return true;
            }
        }
    }
	return false;
}
bool ValidaReglas(int matriz[maxTam][maxTam]){
	int repetidos = 0;
	if (NumDentroRango(matriz) == false)
		return false;
	else if (VerificaFilaIgual(matriz) == true)
		return false;
	else if (VerificaColumIgual(matriz) == true)
		return false;
	else if (VerifDiagonIgual(matriz) == true)
		return false;
	else
		return true;
}
void MuestraMensajeFinal(bool mCorrecta){
	if (mCorrecta == true){
		cout << "Ganaste!";
	}
	else{
		cout << "Perdiste";
	}
}
int main(){
	int matriz[maxTam][maxTam];
	bool matrizCorrecta = false;
	InicializaMatriz(matriz);
	MuestraMatriz(matriz);
	IngresaMatriz(matriz);
	MuestraMatriz(matriz);
	matrizCorrecta = ValidaReglas(matriz);
	cout << endl;
	MuestraMensajeFinal(matrizCorrecta);
	return 1;
}





