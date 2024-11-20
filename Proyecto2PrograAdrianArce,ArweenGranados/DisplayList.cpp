#include "DisplayList.h"


void DisplayList::drawList(sf::RenderWindow& window) {
	window.draw(listBox);
	for (int i = 0; i < buttons.getSize(); ++i) {
		buttons.at(i)->drawButton(window);
	}
}

void DisplayList::drawPoints(sf::RenderWindow& window) {
	if (currentRout >= 0 && currentRout < routes.getSize()) {
		routes.at(currentRout)->drawConnectedCurve(window);
		routes.at(currentRout)->drawRout(window);
		routes.at(currentRout);
	}
}

sf::Vector2f DisplayList::getPosition()
{
	return listBox.getPosition();
}

int& DisplayList::getCurrentRouteIndex()
{
	return currentRout;
}



DisplayList::DisplayList(DoublyLinkedList<Rout>& routes, sf::Vector2f positionList, sf::Vector2f size)
	: routes(routes), positionList(positionList), listBox(size), currentRout(0) {
	listBox.setPosition(positionList);
	listBox.setFillColor(sf::Color(35, 60, 80));
	updateButtons();
}


int DisplayList::handleClick(const sf::Vector2i& mousePos, sf::RenderWindow& window) {

	for (int i = 0; i < buttons.getSize(); ++i) {
		if (buttons.at(i)->isClicked(mousePos, window)) {
			std::cout << "Botón " << i << " clickeado.\n";
			currentRout = i;
			return i;
		}
	}


	return -1;
}



void DisplayList::updateButtons() {
	buttons.clear();

	float offsetY = positionList.y;
	const float buttonHeight = 40.0f;
	const float buttonSpacing = 15.0f;

	for (int i = 0; i < routes.getSize(); ++i) {
		string routeName = routes.at(i)->getName();

		Button newButton(positionList.x, offsetY, routeName);

		buttons.pushBack(newButton);

		offsetY += buttonHeight + buttonSpacing;
	}
}

void DisplayList::addPointToCurrentRoute(sf::RenderWindow& window, sf::Event& event) {
	sf::Vector2f pointPosition = MousePositionProvider::getMousePosition(window);

	RouteManager routeManager(routes);

	sf::Font font;
	if (!font.loadFromFile("Stardew Valley Regular.ttf")) {
		std::cerr << "Error al cargar la fuente.\n";
		return;
	}

	TextInputWindow nameInput(font);
	std::string pointName = nameInput.open();

	ColorPalette colorInput;
	if (!colorInput.openPalette()) {
		std::cerr << "No se seleccionó ningún color.\n";
		return;
	}
	sf::Color pointColor = colorInput.getSelectedColor();

	TouristPoint newTouristPoint(pointName, pointPosition, pointColor, 10);
	routeManager.addPointToRoute(currentRout, newTouristPoint);

	std::cout << "Punto agregado en (" << pointPosition.x << ", " << pointPosition.y << ") con nombre: " << pointName << "\n";
}

void DisplayList::deletePointCurrentRoute(sf::RenderWindow& window, sf::Event& event) {
	if (routes.empty()) {
		std::cerr << "Error: La lista de rutas está vacía." << std::endl;
		return;
	}

	if (currentRout < 0 || currentRout >= routes.getSize()) {
		std::cerr << "Error: currentRoute está fuera de rango. Valor actual: " << currentRout << std::endl;
		return;
	}

	Rout* currentRoutPtr = routes.at(currentRout);
	if (!currentRoutPtr) {
		std::cerr << "Error: currentRoute apunta a nullptr." << std::endl;
		return;
	}

	DoublyLinkedList<TouristPoint>& points = currentRoutPtr->getPoints();

	if (points.empty()) {
		std::cerr << "Advertencia: No hay puntos en la ruta actual." << std::endl;
		return;
	}

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	for (int i = 0; i < points.getSize(); i++) {
		TouristPoint* point = points.at(i);
		if (!point) {
			std::cerr << "Error: Puntero nulo en el punto " << i << std::endl;
			continue;
		}

		if (point->isClicked(mousePos, window)) {
			currentRoutPtr->removePoint(i);
			std::cout << "Punto eliminado en índice: " << i << std::endl;
			break;
		}
	}
}