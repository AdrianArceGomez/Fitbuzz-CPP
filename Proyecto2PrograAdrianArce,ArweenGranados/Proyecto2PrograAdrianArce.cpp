#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Button.h"
#include "SideBarr.h"
#include "AddRout.h"
#include "EditRout.h"
#include "DeletRout.h"
#include "AboutStrategy.h"
#include "ExitStrategy.h"
#include "PointTurist.h"
#include "DoublyLinkedList.h"
#include "BackgroundMusic.h"
#include "ShowMap.h"
#include "RoutFManager.h"

using namespace sf;
using namespace std;

void closeWindow(Event event, RenderWindow& window) {
	if (event.type == Event::Closed) {
		window.close();
	}
}

int main() {
	DoublyLinkedList<Rout> routes;
	RouteFileManager::loadFromFile(routes, "routes.txt");

	RenderWindow window(VideoMode(842, 660), "Stardew Valley");

	MapViewer mapViewer(window, "stardewvalleymap.png");

	Button::initializeButtonShape(sf::Color(255, 224, 178), Vector2f(200.0f, 50.0f));
	Button::initializeButtonText("Stardew Valley Regular.ttf", 20, Color::Black);

	SideBarMenu sideBarMenu(Vector2f(250.0f, 939.0f), Vector2f(-220.0f, 0.0f), routes);
	int currentRouteIndex = sideBarMenu.getRouteDisplay().getCurrentRouteIndex();


	AddRouteStrategy* addRoute = new AddRouteStrategy(routes);
	EditRouteStrategy* editRoute = new EditRouteStrategy(routes, currentRouteIndex);
	DeleteRouteStrategy* deleteRoute = new DeleteRouteStrategy(routes, currentRouteIndex);
	AboutStrategy* help = new AboutStrategy(window);
	ExitStrategy* exit = new ExitStrategy(window);

	sideBarMenu.setStrategies(addRoute, editRoute, deleteRoute, help, exit, nullptr);

	BackgroundMusic bgMusic("15 Summer (Tropicala).ogg");
	bgMusic.play();

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			Vector2i mousePos = Mouse::getPosition(window);


			sideBarMenu.handleMenuEvents(mousePos, window, event);

			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				sideBarMenu.getRouteDisplay().deletePointCurrentRoute(window, event);
			}
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right) {

				sideBarMenu.getRouteDisplay().addPointToCurrentRoute(window, event);

			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
				sideBarMenu.toggleRouteMenu();
			}

			RouteFileManager::saveToFile(routes, "routes.txt");
			closeWindow(event, window);

		}

		sideBarMenu.updateHover(window);
		sideBarMenu.moveSideBarMenu();

		window.clear(sf::Color::Black);

		mapViewer.drawMap();

		sideBarMenu.draw(window);

		window.display();
	}

	delete addRoute;
	delete editRoute;
	delete deleteRoute;
	delete help;
	delete exit;

	return 0;
}