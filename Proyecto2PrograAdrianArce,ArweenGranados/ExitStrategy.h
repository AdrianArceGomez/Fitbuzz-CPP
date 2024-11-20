#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "ButtonStrategy.h"

class ExitStrategy : public ButtonStrategy {
private:
	sf::RenderWindow& window;

public:
	ExitStrategy(sf::RenderWindow& window);
	void execute() override;

};