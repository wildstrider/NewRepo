#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
using namespace sf;

void menu(RenderWindow& window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("D:/projects/FirstGameEngine/image/111.png");
	//menuTexture2.loadFromFile("D:/projects/FirstGameEngine/image/222.png");
	menuTexture3.loadFromFile("D:/projects/FirstGameEngine/image/333.png");
	aboutTexture.loadFromFile("D:/projects/FirstGameEngine/image/about.png");
	//menuBackground.loadFromFile("D:/projects/FirstGameEngine/image/Penguins.jpg");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	//int menuNum = 0;
	menu1.setPosition(50, 50);
	//menu2.setPosition(30, 90);
	menu3.setPosition(70, 110);
//	menuBg.setPosition(345, 0);

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		//menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		int menuNum = 0;
		window.clear(Color(0, 0, 0));

		if (IntRect(50, 50, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		//if (IntRect(50, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(50, 110, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			//if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		//window.draw(menuBg);
		window.draw(menu1);
		//window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
	////////////////////////////////////////////////////
}