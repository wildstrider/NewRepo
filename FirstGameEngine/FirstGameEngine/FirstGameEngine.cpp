#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
using namespace sf;
using namespace std;


void Fill(int** field, Sprite *sprite, Texture &texture, int block);
void Mix(int** field, int x = 4, int y = 4);

int main()
{
    RenderWindow windows(VideoMode(256, 256), "Puzzel");
	/*RectangleShape button;
	button.setSize(Vector2f(50, 80));
	button.setFillColor(Color(0, 255, 0));
	button.setPosition(300, 10);*/
	windows.setFramerateLimit(60);
	Texture texture;
	texture.loadFromFile("D:/projects/FirstGameEngine/image/00150.jpg");

	int block = 64;
	int** field = new int*[6];
	for (int i = 0; i < 6; i++) {
		field[i] = new int[6]{};
	}
	Sprite sprite[17];
	Fill(field, sprite, texture, block);
	//Mix(field, 4, 4);
	
	while (windows.isOpen())
	{
		Event event;
		while (windows.pollEvent(event))
		{
			if (event.type == event.Closed) windows.close();

			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left) {
					Vector2i position = Mouse::getPosition(windows);
					int x = position.x / block + 1;
					int y = position.y / block + 1;

					int Hx = 0;
					int Vy = 0;

					if (field[x + 1][y] == 16) { Hx = 1; Vy = 0; } 
					if (field[x][y + 1] == 16) { Hx = 0; Vy = 1; }
					if (field[x - 1][y] == 16) { Hx = -1; Vy = 0; }
					if (field[x][y - 1] == 16) { Hx = 0, Vy = -1; }


					int temp = field[x][y];
					field[x][y] = 16;
					field[x + Hx][y + Vy] = temp;

					sprite[16].move(-Hx * block, -Vy * block);
					float speed = 6;
					for (int i = 0; i < block; i += speed) {

						sprite[temp].move(speed * Hx, speed * Vy);
						windows.draw(sprite[16]);
						windows.draw(sprite[temp]);
						windows.display();
					}
				}
			}
		}
		windows.clear(Color::White);
		 
		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 4; j++) {

				int  n = field[i + 1][j + 1];
				sprite[n].setPosition(i * block, j * block);
				windows.draw(sprite[n]);
			}
		}
		//windows.draw(button);
		windows.display();
	}
	for (int i = 0; i < 6; i++) {
		delete[] field[i];
	}
	delete[] field;
    return 0;
}

void Fill(int** field, Sprite *sprite,  Texture &texture, int block)
{
	int n = 0;
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			n++;
			sprite[n].setTexture(texture);
			sprite[n].setTextureRect(IntRect(i * block, j * block, block, block));

			field[i + 1][j + 1] = n;
		}
	}
}
void Mix(int** field, int x, int y)
{
	srand(time(0));
	for (int i = 0; i < 500; i++)
	{
		switch (rand() % 4)
		{
		case 0: if (x == 0)break; swap(field[x][y], field[x - 1][y]); x--; break;
		case 1:	if (x == 3)break; swap(field[x][y], field[x + 1][y]); x++; break;
		case 2:	if (y == 0)break; swap(field[x][y], field[x][y - 1]); y--; break;
		case 3:	if (y == 3)break; swap(field[x][y], field[x][y + 1]); y++; break;
		}
	}
}