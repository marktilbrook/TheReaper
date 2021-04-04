#pragma once

#include <SFML/Graphics.hpp>

class Game
{

public:
	Game();
	void Run();

private:
	void ProcessEvents();
	void Update(sf::Time deltaTime);
	void Render();

	void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	sf::RenderWindow m_Window;
	sf::CircleShape m_Player;

	bool m_isMovingUp;
	bool m_isMovingDown;
	bool m_isMovingLeft;
	bool m_isMovingRight;

	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

	const float m_playerSpeed = 30.f;


};

int main()
{
	Game game;
	game.Run();

}




