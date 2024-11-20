#include "ExitStrategy.h"

ExitStrategy::ExitStrategy(sf::RenderWindow& window) : window(window) {}

void ExitStrategy::execute() {
	window.close();
}