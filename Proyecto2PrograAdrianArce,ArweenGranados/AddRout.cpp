#include "AddRout.h"

AddRouteStrategy::AddRouteStrategy(DoublyLinkedList<Rout>& routes)
    : routes(routes) {}

void AddRouteStrategy::execute() {
    sf::Font font;
    font.loadFromFile("Stardew Valley Regular.ttf");
    TextInputWindow nameImput(font);
    Rout newRoute(nameImput.open());


    routes.pushBack(newRoute);

    std::cout << "Nueva ruta " << routes.back()->getName() << " annadida.\n";
}