
#include <SFML/Graphics.hpp>
using namespace std;

int main() {
    
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

    return 0;
}