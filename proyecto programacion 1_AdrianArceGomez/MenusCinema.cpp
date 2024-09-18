#include "MenusCinema.h"

void Menusaboutme::menuaboutme() {
	int option = 0;

	cout << "Seleccione una opcion" << endl << "1.Acera de " << endl << "2.Volver " << endl << "0.Salir " << endl;
	cin >> option;

	while (option != 0) {

		if (option == 1) {

			cout << name;


		}

		if (option == 2) {


			return;


		} 
		
	}
}


void Menusaboutme::erroroptions(void menuaboutme()) {




}


void Generalmenu::Menu(Menusaboutme Aboutme, int choise){

	

	std::cout << "escoja la opcion a usar" << endl << "1.Archivo" << endl << "2.Mantenimiento" << "3.Reserva" << endl << "4.Venta" << endl << "(1~4)" << endl << "0.Salir" << endl;
	std::cin >> choise;

	while (choise != 0) {

		if (choise == 1) {

			Aboutme.menuaboutme();

		}
		if (choise == 2) {




		}
		if (choise == 3) {




		}
		if (choise == 4) {




		}

	};


}

void Generalmenu::erroroption(void Menu()) {

	if (choise < 1 || choise  > 4) {

		cout << "Esto no es una opcion";





	}







}
