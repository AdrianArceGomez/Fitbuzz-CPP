#include "RoutManager.h"
#include <iostream>

RouteManager::RouteManager(DoublyLinkedList<Rout>& routes) : routes(routes) {}

void RouteManager::addPointToRoute(int routeIndex, const TouristPoint& point) {
    if (routeIndex >= 0 && routeIndex < routes.getSize()) {
        routes.at(routeIndex)->addPoint(point);
    }
    else {
        std::cerr << "Índice de ruta inválido\n";
    }
}
