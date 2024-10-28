#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;


int imagen() {
    sf::RenderWindow window(sf::VideoMode(842, 660), "Stardew Valley Map");


    sf::Texture mapaTexture;
    if (!mapaTexture.loadFromFile("stardewvalleymap.png")) {
        return -1;
    }


    sf::Sprite mapaSprite;
    mapaSprite.setTexture(mapaTexture);

    // Bucle principal del juego
    while (window.isOpen()) {
        // Manejo de eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana con un color de fondo (opcional)
        window.clear(sf::Color::Red);

        // Dibujar el mapa en la ventana
        window.draw(mapaSprite);

        // Mostrar la ventana actualizada
        window.display();
    }



}

void menu() {
    string ruta;
    int opcion;

    do {
        cout << "----- bienvenidos al menu porfavor digite una opcion -----\n";
        cout << "1. Insertar una ruta\n";
        cout << "2. Modificar una ruta\n";
        cout << "3. ver mapa\n";
        cout << "0. Salir\n";

        cin >> opcion;

        if (opcion == 1) {
            cout << "Ingrese la ruta a insertar: \n";
        
        }
        if (opcion == 2) {
            cout << "escoja la ruta a modificar\n";
        }
        if (opcion == 3) {
            imagen();
        }
            
        if (opcion == 0) {
            cout << "Saliendo del programa...\n";
        
   
        }

    } while (opcion != 0);
}


int main() {
    

    menu();

   

    return 0;
}