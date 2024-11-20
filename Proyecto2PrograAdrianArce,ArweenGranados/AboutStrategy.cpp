#include "AboutStrategy.h"
#include <iostream>

AboutStrategy::AboutStrategy(sf::RenderWindow& window) : window(window) {
	if (!font.loadFromFile("Stardew Valley Regular.ttf")) {
		std::cerr << "Error loading font\n";
	}

	setupAboutInfoBox();
}

void AboutStrategy::setupAboutInfoBox() {
	infoText.setFont(font);
	infoText.setString("Informacion del proyecto:\n Info aqui o_o\n/\\_/\\ \n( o.o )\n> ^ <");
	infoText.setCharacterSize(24);
	infoText.setFillColor(sf::Color::Black);
	infoText.setPosition(110.0f, 110.0f);

	infoBox.setSize(sf::Vector2f(400.0f, 200.0f));
	infoBox.setFillColor(sf::Color(200, 200, 200));
	infoBox.setOutlineThickness(2.0f);
	infoBox.setOutlineColor(sf::Color::Black);
	infoBox.setPosition(100.0f, 100.0f);
}
void AboutStrategy::closePalette(sf::RenderWindow& window, sf::Event event) {
	if (event.type == sf::Event::Closed) {
		window.close();
	}
}


void AboutStrategy::execute() {
	sf::RenderWindow helpWindow(sf::VideoMode(600, 400), "Informacion");

	while (helpWindow.isOpen()) {
		sf::Event event;
		while (helpWindow.pollEvent(event)) {
			closePalette(helpWindow, event);
		}

		helpWindow.clear();
		helpWindow.draw(infoBox);
		helpWindow.draw(infoText);
		helpWindow.display();
	}
}