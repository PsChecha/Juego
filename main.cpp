#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

/*funcion gotoxy para registrar las coordenadas*/
void gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon,dwPos);
}

/*esconde el cursor de la consola*/
void HideCursor(){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100; //esto alteraria el tamaño del cursor, pero como lo escondemos no importa
	info.bVisible = FALSE;
	
	SetConsoleCursorInfo(hCon, &info);
}

class NAVE{
	int x,y;
	public:
		NAVE(int _x, int _y): x(_x), y(_y){}
		void dibujar();
		void borrar();
		void mover();
};

void NAVE::dibujar(){
	gotoxy(x,y); printf("  %c",30);
	gotoxy(x,y+1); printf(" %c%c%c",47,207,92);
	gotoxy(x,y+2); printf("%c%c%c%c%c",30,191,193,218,30);
}

void NAVE::borrar(){
	gotoxy(x,y); printf("     ");
	gotoxy(x,y+1); printf("     ");
	gotoxy(x,y+2); printf("     ");
}

void NAVE::mover(){
	if(kbhit()){
			char tecla = getch();
			borrar();
			if(tecla == LEFT){
				x--;
			}
			if (tecla == RIGHT){
				x++;
			}
			if (tecla == UP){
				y--;
			}
			if (tecla == DOWN){
				y++;
			}
			dibujar();
		}
}

int main(){
	HideCursor();
	NAVE spaceship(10,10);
	spaceship.dibujar();
	/*loop para que el juegue continue hasta que pierdas*/
	bool game_over = false;
	while(!game_over){
		spaceship.mover();
		Sleep(30);
	}
	return 0;
}
