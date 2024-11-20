#include "DeletRout.h"

DeleteRouteStrategy::DeleteRouteStrategy(DoublyLinkedList<Rout>& routes, int& routeIndex)
	: routes(routes), routeIndex(routeIndex) {}


void DeleteRouteStrategy::execute() {
	if (routeIndex < 0 || routeIndex >= routes.getSize()) {
		std::cout << "�ndice de ruta no v�lido.\n";
		return;
	}

	routes.remove(routeIndex);

	std::cout << "Ruta en el �ndice " << routeIndex << " eliminada.\n";
}