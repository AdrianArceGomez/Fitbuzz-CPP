#include "EditRout.h"
#include "Colors.h"

EditRouteStrategy::EditRouteStrategy(DoublyLinkedList<Rout>& routes, int& routeIndex)
    : routes(routes), routeIndex(routeIndex) {}

void EditRouteStrategy::execute() {
    if (routeIndex < 0 || routeIndex >= routes.getSize()) {
        std::cout << "�ndice de ruta no v�lido.\n";
        return;
    }

    sf::Font font;
    font.loadFromFile("Stardew Valley Regular.ttf");
    TextInputWindow nameImput(font);

    routes.at(routeIndex)->setName((nameImput.open()));
}