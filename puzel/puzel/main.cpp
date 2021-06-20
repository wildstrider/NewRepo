#include <SFML/Graphics.hpp>
#include <ctime>

using namespace std;
using namespace sf;


void Mix(int** arr_pulze, int s, int x = 4, int y = 4);
bool Check(int** arr_puzzle, int s, Text text);

int main() 
{
	RenderWindow window(VideoMode(800, 800), "Puzle");
	window.setFramerateLimit(60);
	Texture /*texture*/ texture_puzele;
	//texture.loadFromFile("D:/projects/puzel/image_puzel/756221.jpg");
	texture_puzele.loadFromFile("D:/projects/puzel/image_puzel/00151515.jpg");
	Font font;
	font.loadFromFile("D:/projects/puzel/Text/CyrilicOld.ttf");
	Text text("", font, 70);
	text.setFillColor(Color::Blue);
	


	Sprite sprite, sprite_puzel[17];
	//sprite.setTexture(texture);
	int s = 6;
	int** arr_puzle = new int* [s];
	for (int i = 0; i < s; arr_puzle[i] = new int[s] {}, i++);
	int block = 100, n = 0;
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			n++;
			sprite_puzel[n].setTexture(texture_puzele);
			sprite_puzel[n].setTextureRect(IntRect(i * block, j * block, block, block));
			arr_puzle[i + 1][j + 1] = n;

		}
	}
	//Mix(arr_puzle, s);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
		}
		Check(arr_puzle, s, text);
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
				/*arr_puzle[x][y] = 16;
				arr_puzle[x + Hx][y + Vy] = temp;*/
				swap(arr_puzle[x][y], arr_puzle[x + Hx][y + Vy]);

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
		window.clear(Color::Green);

		text.setString("Вы\n выйграли!");
		int x = 350;
		int y = 400;
		text.setPosition(x, y);
		
		//window.draw(sprite);
		for (int i = 0/* k = 320*/; i < 4; i++/* k += block*/) {
			
			for (int j = 0; j < 4; j++) {
				
				int n = arr_puzle[i + 1][j + 1];
				sprite_puzel[n].setPosition(i * block, j * block);
				window.draw(sprite_puzel[n]);
			}
		}

		if(Check(arr_puzle, s, text)) window.draw(text);
		window.display();
	}
	for (int i = 0; i < s; delete[] arr_puzle[i], i++);
	delete[] arr_puzle;
	return 0;
}


 void Mix(int** arr_puzle, int s, int x, int y)
 {
	 srand(time(0));
	 for (int i = 0; i < 1000; i++)
	 {
		 switch (1 + rand() % 5)
		 {
		 case 1: if (x == 1)break; swap(arr_puzle[x][y], arr_puzle[x - 1][y]); x--; break;
		 case 2: if (x == 4)break; swap(arr_puzle[x][y], arr_puzle[x + 1][y]); x++; break;
		 case 3: if (y == 1)break; swap(arr_puzle[x][y], arr_puzle[x][y - 1]); y--; break;
		 case 4: if (y == 4)break; swap(arr_puzle[x][y], arr_puzle[x][y + 1]); y++; break;
		 }
	 }
 }
 bool Check(int** arr_puzzle, int s, Text text)
 {
	 bool check = true;
	 for (int i = 1; i < 5; i++) {
		 for (int j = 1; j < 5 - 1; j++) {
			 if (arr_puzzle[i][j] > arr_puzzle[i][j + 1]) check = false;
		 }
	 }
	 if (check) 
	 {
		 text.setString("Вы выйграли!");
		 int x = 350;
		 int y = 400;
		 text.setPosition(x, y);
		 return check;
	 }
	 return check;
 }