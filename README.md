# Wanna-be-game ver. build
Sebuah program permainan sederhana berburu monster

## Changelogs
* Bug Gerak
* Add fitur detect arrowkey

## Source Code

```
#include <iostream>
#include <conio.h>
using namespace std;

#define atas 72
#define bawah 80
#define kiri 75
#define kanan 77

int main() {
	
	int tinggi= 20, lebar=30, x=2, y=19; 
	
	cout << "Posisi kamu ada di " << x << " dan " << y << endl;
	// 9 = dinding, 8 = bangunan, 6 = rumput, 7=barrier, 5 = harta karun, 3 = item loot, 2 = summoning egg, 1= jalan
	int map[tinggi][lebar] = {
		{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
		{9,6,6,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9},
		{9,6,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,8,8,1,9},
		{9,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,1,1,8,8,1,9},
		{9,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,9},
		{9,1,1,1,3,1,1,1,1,6,6,9,1,1,1,1,1,1,1,1,1,1,1,7,1,1,1,1,1,9},
		{9,1,1,1,1,1,1,1,1,6,2,9,1,1,1,1,1,1,1,1,1,1,1,1,1,9,9,1,1,9},
		{9,1,1,1,1,1,5,1,1,1,8,8,1,1,1,1,1,1,1,8,8,1,1,1,1,1,1,1,1,9},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,8,8,8,1,1,1,1,2,1,2,6,6},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,1,1,1,1,1,1,1,1,6,6,6,6},
		{9,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,6,9},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,9},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,8,1,1,1,1,1,1,1,6,1,1,9},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,8,1,1,1,1,6,1,1,1,1,1,9},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,6,6,6,1,1,1,1,1,1,6,6,1,1,1,1,9},
		{9,1,1,1,1,1,1,9,9,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,6,1,1,1,1,9},
		{9,1,1,1,1,1,1,9,9,1,1,1,1,1,1,1,6,1,1,1,1,1,1,6,1,1,1,1,1,9},
		{9,1,1,1,1,1,9,9,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9},
	};
	
	int panah = 0;

	while (1) {

		cout << "\nArah kemana?";
		panah = getch();
		cout << "Panah yang kamu masukkan : " << panah << endl;
	// atas	
	if (panah == 72 && (map[tinggi-1][lebar] == 1 || map[tinggi-1][lebar] == 6) && y >= 0) {
		y =-1;
	}
	
	// bawah
	if (panah == 80 && (map[tinggi+1][lebar] == 1 || map[tinggi+1][lebar] == 6) && y < tinggi) {
		y = y + 1;
	}
	
	// kanan
	if (panah == 75 && (map[tinggi][lebar-1] == 1 || map[tinggi][lebar-1] == 6) && x >= 0) {
		x =-1;
	}
	
	// kiri
	if (panah == 77 && (map[tinggi][lebar+1] == 1 || map[tinggi][lebar+1] == 6) && x < lebar) {
		x =+1;
	}
	
	// event
	if (map[tinggi][lebar+1] == 2) {
			cout << "Selamat kamu mendapatkan summoning egg!\n";
		} else if ( map[tinggi][lebar+1] == 3) {
			cout << "Selamat kamu mendapatkan item loot!\n";
		} else if (map[tinggi][lebar+1] == 5) {
			cout << "Selamat kamu mendapatkan harta karun!\n";
	}
	
	// peta
	for (int i=0; i < lebar; i++) {
		for (int j=0; j<tinggi; j++) {
			if (x == j && y == i) {
				cout << 0 << " ";
			} else {
				cout << map[i][j] << " ";
			}
		}
		cout << endl;
		}
	}
	return 0;
}
```
