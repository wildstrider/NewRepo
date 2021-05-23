#include <SFML/Graphics.hpp>
using namespace sf;

int main() 
{
	RenderWindow window(VideoMode(800, 800), "Puzle");
	window.setFramerateLimit(60);
	Texture /*texture*/ texture_puzele;
	//texture.loadFromFile("D:/projects/puzel/image_puzel/756221.jpg");
	texture_puzele.loadFromFile("D:/projects/puzel/image_puzel/001515.jpg");

	Sprite sprite, sprite_puzel[17];
	//sprite.setTexture(texture);
	int arr_puzle[4][4];
	int block = 200, n = 0;
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			n++;
			sprite_puzel[n].setTexture(texture_puzele);
			sprite_puzel[n].setTextureRect(IntRect(i * block, j * block, block, block));
			arr_puzle[i + 1][j + 1] = n;

		}
	}

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
		}
		if (event.type == Event::MouseButtonPressed) {
			if (event.key.code == Mouse::Left) {
				Vector2i position = Mouse::getPosition(window);
				int x = position.x / block + 1;
				int y = position.y / block + 1;

				int Hx = 0;
				int Vy = 0;

				if (arr_puzle[x + 1][y] == 16)  Hx = 1; 
				if (arr_puzle[x][y + 1] == 16) Vy = 1; 
				if (arr_puzle[x - 1][y] == 16)  Hx = -1; 
				if (arr_puzle[x][y - 1] == 16) Vy = -1; 

				int temp = arr_puzle[x][y];
				arr_puzle[x][y] = 16;
				arr_puzle[x + Hx][y + Vy] = temp;

				sprite_puzel[16].move(-Hx * block, -Vy * block);
				
				float speed = 10;
				for (int i = 0; i < block; i += speed)
				{
					
					sprite_puzel[temp].move(speed * Hx, speed * Vy);
					
					window.draw(sprite_puzel[16]);
					
					window.draw(sprite_puzel[temp]);
				
					window.display();
				}
			}

		}
		window.clear();
		//window.draw(sprite);
		for (int i = 0/* k = 320*/; i < 4; i++/* k += block*/) {
			
			for (int j = 0; j < 4; j++) {
				
				int n = arr_puzle[i + 1][j + 1];
				sprite_puzel[n].setPosition(i * block, j * block);
				window.draw(sprite_puzel[n]);
			}
		}
		window.display();
	}

	return 0;
}


//void Mix(int field[][4], int rows, int cols, int num, int x, int y)
//{
//	srand(time(0));
//	for (int i = 0; i < 100; i++)
//	{
//		switch (rand() % 4)
//		{
//		case 0: if (x == 0)break; swap(field[x][y], field[x - 1][y]); x--; break;
//		case 1:	if (x == 3)break; swap(field[x][y], field[x + 1][y]); x++; break;
//		case 2:	if (y == 0)break; swap(field[x][y], field[x][y - 1]); y--; break;
//		case 3:	if (y == 3)break; swap(field[x][y], field[x][y + 1]); y++; break;
//		}
//
//	}
//	PrintField(field, rows, cols, x, y, num);
//}