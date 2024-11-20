#include "SideBarr.h"

SideBarMenu::SideBarMenu(sf::Vector2f size, sf::Vector2f position, DoublyLinkedList<Rout>& routes)
	: sideBarMenu(size), routeList(routes, sf::Vector2f(5.0f, position.y + 400), sf::Vector2f(200, position.y + 500)),
	routes(routes),
	buttonRoutes(position.x + 5.0f, position.y + 100.0f, "Rutas"),
	helpButton(position.x + 5.0f, position.y + 200.0f, "Ayuda"),
	exitButton(position.x + 5.0f, position.y + 300.0f, "Salir"),
	addRouteButton(position.x + 5.0f, position.y + 400.0f, "Añadir"),
	editRouteButton(position.x + 5.0f, position.y + 500.0f, "Editar"),
	deleteRouteButton(position.x + 5.0f, position.y + 600.0f, "Eliminar") {
	sideBarMenu.setFillColor(sf::Color(112, 128, 144));
	sideBarMenu.setPosition(position);
	updateButtonPositions();
}

void SideBarMenu::setStrategies(ButtonStrategy* add, ButtonStrategy* edit, ButtonStrategy* del, ButtonStrategy* help, ButtonStrategy* exit, ButtonStrategy* showRoutes) {
	addRouteStrategy = add;
	editRouteStrategy = edit;
	deleteRouteStrategy = del;


	helpStrategy = help;
	exitStrategy = exit;
	showRoutesStrategy = showRoutes;
}

void SideBarMenu::toggleSideBar() {
	menuState = (menuState == MenuState::Hidden) ? MenuState::MainMenuVisible : MenuState::Hidden;
}

void SideBarMenu::toggleRouteMenu() {
	menuState = (menuState == MenuState::MainMenuVisible) ? MenuState::RouteMenuVisible : MenuState::MainMenuVisible;
	updateButtonPositions();
}

void SideBarMenu::updateButtonPositions() {
	float offsetX = sideBarMenu.getPosition().x + 5.0f;
	if (menuState == MenuState::RouteMenuVisible) {
		updateRouteMenuButtonPositions(offsetX);

	}
	else if (menuState == MenuState::MainMenuVisible) {
		updateMainMenuButtonPositions(offsetX);
	}
}

void SideBarMenu::updateMainMenuButtonPositions(float offsetX) {
	buttonRoutes.setButtonPosition(offsetX, 100.0f);
	helpButton.setButtonPosition(offsetX, 200.0f);
	exitButton.setButtonPosition(offsetX, 300.0f);
	addRouteButton.setButtonPosition(-205.0f, 100.0f);
	editRouteButton.setButtonPosition(-205.0f, 200.0f);
	deleteRouteButton.setButtonPosition(-205.0f, 300.0f);
	routeList.updateButtons();
}

void SideBarMenu::updateRouteMenuButtonPositions(float offsetX) {
	addRouteButton.setButtonPosition(offsetX, 100.0f);
	editRouteButton.setButtonPosition(offsetX, 200.0f);
	deleteRouteButton.setButtonPosition(offsetX, 300.0f);
	buttonRoutes.setButtonPosition(-205.0f, 100.0f);
	helpButton.setButtonPosition(-205.0f, 200.0f);
	exitButton.setButtonPosition(-205.0f, 300.0f);
	routeList.updateButtons();
}

void SideBarMenu::moveSideBarMenu() {
	float deltaTime = clock.restart().asSeconds();
	float targetX = (menuState != MenuState::Hidden) ? 0.0f : -220.0f;
	float currentX = sideBarMenu.getPosition().x;
	float step = displacementSpeed * deltaTime;

	if ((menuState != MenuState::Hidden && currentX < targetX) ||
		(menuState == MenuState::Hidden && currentX > targetX)) {
		float direction = (menuState != MenuState::Hidden) ? 1.0f : -1.0f;
		sideBarMenu.move(direction * std::min(step, std::abs(targetX - currentX)), 0);


		if (std::abs(sideBarMenu.getPosition().x - targetX) < step) {
			sideBarMenu.setPosition(targetX, sideBarMenu.getPosition().y);
		}
	}
	updateButtonPositions();
}

void SideBarMenu::draw(sf::RenderWindow& window) {
	routeList.drawPoints(window);
	window.draw(sideBarMenu);
	if (menuState == MenuState::RouteMenuVisible) {
		addRouteButton.drawButton(window);
		editRouteButton.drawButton(window);
		deleteRouteButton.drawButton(window);
		routeList.drawList(window);
	}

	else if (menuState == MenuState::MainMenuVisible) {
		buttonRoutes.drawButton(window);
		helpButton.drawButton(window);
		exitButton.drawButton(window);
	}
}

DisplayList& SideBarMenu::getRouteDisplay()
{
	return routeList;
}

bool SideBarMenu::isEdgeClicked(const sf::Vector2i& mousePos) {
	sf::FloatRect visibleEdge(sideBarMenu.getPosition().x + 220.0f, 0.0f, 30.0f, 939.0f);
	return visibleEdge.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

bool SideBarMenu::handleButtonClick(const sf::Vector2i& mousePos, sf::RenderWindow& window) {


	if (menuState == MenuState::MainMenuVisible) {
		if (buttonRoutes.isClicked(mousePos, window)) {
			toggleRouteMenu();
			return true;
		}
		if (helpButton.isClicked(mousePos, window)) {
			if (helpStrategy) helpStrategy->execute();
			return false;
		}
		if (exitButton.isClicked(mousePos, window)) {
			if (exitStrategy) exitStrategy->execute();
		}

	}
	return false;
}

bool SideBarMenu::handleRouteMenuClick(const sf::Vector2i& mousePos, sf::RenderWindow& window) {

	routeList.handleClick(mousePos, window);


	if (menuState == MenuState::RouteMenuVisible) {
		if (addRouteButton.isClicked(mousePos, window)) {
			if (addRouteStrategy) addRouteStrategy->execute();
			return true;
		}
		if (editRouteButton.isClicked(mousePos, window)) {
			sf::Font font;
			if (!font.loadFromFile("Stardew Valley Regular.ttf")) {
				std::cerr << "Error al cargar la fuente.\n";
				return false;
			}
			TextInputWindow name(font);
			routes.at(routeList.getCurrentRouteIndex())->setName(name.open());
			return true;
		}
		if (deleteRouteButton.isClicked(mousePos, window)) {
			routes.remove(routeList.getCurrentRouteIndex());
			return true;
		}
	}
	return true;
}

void SideBarMenu::updateHover(sf::RenderWindow& window) {
	buttonRoutes.isHovered(window);
	helpButton.isHovered(window);
	exitButton.isHovered(window);
	addRouteButton.isHovered(window);
	editRouteButton.isHovered(window);
	deleteRouteButton.isHovered(window);
}

void SideBarMenu::handleMenuEvents(const sf::Vector2i& mousePos, sf::RenderWindow& window, sf::Event event) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (isEdgeClicked(mousePos)) {
			toggleSideBar();
		}

		if (!handleButtonClick(mousePos, window)) {
			handleRouteMenuClick(mousePos, window);
		}
	}

}