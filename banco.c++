#include <iostream>
using namespace std;

//CONSTANTES
const int NUM_CUENTAS = 10;

//OBJETO
class Cuenta {
	public:
		string titular;
		int numCuenta;
		float saldo;
		
	//CONSTRUCTORES
	Cuenta(): saldo (0){}
	
	Cuenta(string ti, int numC): Cuenta(){
		titular = ti;
		numCuenta = numC;
	}	

	//MÉTODOS DE LA CLASE
	float dameSaldo(){
		return saldo;
	}

	void ingresar(float cantidad){
		saldo += cantidad;
	}

	bool reintegrar(float cantidad){
		if (cantidad > saldo) {
			return false;
		}
		
		saldo -= cantidad;
		return true;
	}

};

//FUNCIONES
void mostrarSaldo(Cuenta & cM){
	cout << "La cuenta " << cM.numCuenta << " de " << cM.titular << " tiene " << cM.dameSaldo() << " euros" << endl;
}

void realizaIngreso(Cuenta & cI) {
	float cant;

	cout << "Introduzca la cantidad a ingresar en la cuenta de " << cI.titular << ": "; 
	cin >> cant;
	
	cout << "Vas a ingresar: " << cant << " euros a la cuenta." << endl;
	
	cI.ingresar(cant);
	
	cout << "Se ha realizado el ingreso correctamente." << endl;
}

void realizarReintegro(Cuenta & cI) {
	float cant;
	
	cout << "Introduzca la cantidad a sacar de la cuenta de " << cI.titular << ": "; 
	cin >> cant;
	
	cout << "Vas a retirar: " << cant << " euros de la cuenta." << endl;
	
	if (cI.reintegrar(cant)){
		cout << "Reintegro realizado correctamente" << endl;
	} else {
		cout << "No se pudo realizar la operación" << endl;
	}
}

//La selección de la centa se hace con un bool para poder garantizar el paso al menú secundario solo si la cuenta existe.
bool selecCuenta(Cuenta cuentas[], Cuenta*& cuentaSelec){
	int num;
	
	cout << "Indique la cuenta en la que desea realizar las operaciones(1-" << NUM_CUENTAS << "): ";
	cin >> num;

	if (num >= 1 && num <= NUM_CUENTAS){
		cuentaSelec = &cuentas[num-1];
		return true;
	} else {
		cout << "Número de cuenta inválido. Vuelva a intentarlo." << endl;
		return false;
	}
}

void menuSecundario(Cuenta* cuentaSelec){
	int opMenuS = 0;
	while (opMenuS != 4){
		cout << "Operaciones: " << endl;
		cout << "1. Ingresar dinero" << endl;
		cout << "2. Retirar dinero" << endl;
		cout << "3. Mostrar saldo" << endl;
		cout << "4. Volver al menú principal" << endl;
		cout << "Ingrese el número de la operación que desea realizar: ";
		cin >> opMenuS;
		
		if(opMenuS == 1){
			realizaIngreso(*cuentaSelec);
		} else if( opMenuS == 2){
			realizarReintegro(*cuentaSelec);			
		} else if( opMenuS == 3){
			mostrarSaldo(*cuentaSelec);			
		} else if( opMenuS == 4){
			cout << "Volviendo al menú principal..." << endl;		
		} else {
			cout << "ERROR! La opción seleccionada no existe. Vuelva a intentarlo" << endl;
		}
	}
}

void menuPrincipal(Cuenta cuentas[]){
	int opMenuP = 0;
	Cuenta* cuentaSelec = &cuentas[0];
	
	while (opMenuP!= 2){
		cout << "BIENVENIDA/O A LA APP DEL BANCO" << endl;
		cout << "----------------------------------" << endl;
		cout << "Menú:" << endl;
		cout << "1. Operar en una cuenta" << endl;
		cout << "2. Salir" << endl;
		cout << "Ingrese el número de la operación que desea realizar: ";
		cin >> opMenuP;
		
		if (opMenuP == 1){
			if (selecCuenta(cuentas, cuentaSelec)) {
        menuSecundario(cuentaSelec);
    	}
		} else if (opMenuP == 2){
			cout << "Hasta la próxima!" << endl;
		} else {
			cout << "ERROR! La opción seleccionada no existe. Vuela a intentarlo" << endl;
		}
	}
}


//CUERPO DEL MAIN
int main(int argc, char*argv[]) {
	
	string nombres[NUM_CUENTAS] = {"Julia", "Mar", "Patricia", "Natalia", "Martina", "Ana", "Lupe", "Malena", "Paz", "Sofia"};
	
	Cuenta cuentas[NUM_CUENTAS];
	
	for (int i = 0; i < 10; i++){
		cuentas[i] = Cuenta(nombres[i], i+1);
	}
	
	menuPrincipal(cuentas);
}
