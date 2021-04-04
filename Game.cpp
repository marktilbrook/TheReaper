#include "Game.h"

Game::Game()
	: m_Window(sf::VideoMode(640, 480), "SFML Application")
	, m_Player()
{
	
	m_Player.setRadius(40.f);
	m_Player.setPosition(100.f, 100.f);
}

void Game::Run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (m_Window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			ProcessEvents();
			Update(TimePerFrame);
		}

		
		Render();
	}
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			HandlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			HandlePlayerInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			m_Window.close();
			break;
		}
	}
}

void Game::Update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (m_isMovingUp)
		movement.y -= m_playerSpeed;
	if (m_isMovingDown)
		movement.y += m_playerSpeed;
	if (m_isMovingLeft)
		movement.x -= m_playerSpeed;
	if (m_isMovingRight)
		movement.x += m_playerSpeed;

	m_Player.move(movement * deltaTime.asSeconds());
}

void Game::Render()
{
	m_Window.clear();
	m_Window.draw(m_Player);
	m_Window.display();
}

void Game::HandlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		m_isMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		m_isMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		m_isMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		m_isMovingRight = isPressed;
}

