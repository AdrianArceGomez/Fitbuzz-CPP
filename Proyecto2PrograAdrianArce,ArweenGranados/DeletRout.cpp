#include "DeletRout.h"

DeleteRouteStrategy::DeleteRouteStrategy(DoublyLinkedList<Rout>& routes, int& routeIndex)
	: routes(routes), routeIndex(routeIndex) {}


void DeleteRouteStrategy::execute() {
	if (routeIndex < 0 || routeIndex >= routes.getSize()) {
		std::cout << "Índice de ruta no válido.\n";
		return;
	}

	routes.remove(routeIndex);

	std::cout << "Ruta en el índice " << routeIndex << " eliminada.\n";
}