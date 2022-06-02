# Wanna-be-game ver. build
Sebuah program permainan sederhana berburu monster

## Changelogs (v0.2)
* Add event
* Add fitur detect arrowkey
* Fix Gerak
* Fix Event

## Bugs
* Event muncul (fix)

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
	
	int tinggi= 30, lebar=30, x=2, y=19; 
	
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
		{9,1,1,1,1,5,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9},
		{9,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9},
		{9,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,6,9,1,1,1,1,1,1,1,1,9},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,6,6,6,1,1,1,1,1,1,1,1,9},
		{9,1,1,9,9,7,1,1,1,1,1,1,1,1,1,1,1,9,9,6,6,1,1,1,1,1,1,1,1,9},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,1,9},
		{9,1,1,1,1,1,9,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,1,1,9},
		{9,1,8,8,1,1,9,1,1,1,1,1,1,1,1,1,6,2,6,1,1,1,1,1,1,1,1,5,6,9},
		{6,6,8,8,1,1,1,1,1,1,1,1,1,1,1,1,1,6,6,1,1,1,1,1,1,1,1,6,6,9},
		{6,1,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,6,6,9},
		{6,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	};
	
	int panah = 0;

	while (1) {

		cout << "\nArah kemana?";
		panah = getch();
		cout << "Panah yang kamu masukkan : " << panah << endl;

	// atas	
	if(panah == 72 && (map[y-1][x] == 1 || map[y-1][x] == 6 || map[y-1][x] == 2 || map[y-1][x] == 3 || map[y-1][x] == 5) && y >= 0) {
            if (map[y-1][x] == 2) {
			y =y-1;
			cout << "Selamat kamu mendapatkan summoning egg!\n";
		} else if ( map[y-1][x] == 3) {
			y =y-1;
			cout << "Selamat kamu mendapatkan item loot!\n";
		} else if (map[y-1][x] == 5) {
			y =y-1;
			cout << "Selamat kamu mendapatkan harta karun!\n";
		} else {
			y =y-1;
		} 
        }
	
	// bawah
	if(panah == 80 && (map[y+1][x] == 1 || map[y+1][x] == 6 || map[y+1][x] == 2 || map[y+1][x] == 3 || map[y+1][x] == 5) && y < tinggi) {
        if (map[y+1][x] == 2) {
			y =y+1;
			cout << "Selamat kamu mendapatkan summoning egg!\n";
		} else if ( map[y+1][x] == 3) {
			y =y+1;
			cout << "Selamat kamu mendapatkan item loot!\n";
		} else if (map[y+1][x] == 5) {
			y =y+1;
			cout << "Selamat kamu mendapatkan harta karun!\n";
		} else {
			y =y+1;
		} 
    }
	
	// kiri
	if(panah == 75 && (map[y][x-1] == 1 || map[y][x-1] == 6 || map[y][x-1] == 2 || map[y][x-1] == 3 || map[y][x-1] == 5) && x >= 0) {
		if (map[y][x-1] == 2) {
			x =x-1;
			cout << "Selamat kamu mendapatkan summoning egg!\n";
		} else if ( map[y][x-1] == 3) {
			x =x-1;
			cout << "Selamat kamu mendapatkan item loot!\n";
		} else if (map[y][x-1] == 5) {
			x =x-1;
			cout << "Selamat kamu mendapatkan harta karun!\n";
		} else {
			x =x-1;
		}   
    }
	
	// kanan
	if(panah == 77 && (map[y][x+1] == 1 || map[y][x+1] == 6 || map[y][x+1] == 2 || map[y][x+1] == 3 || map[y][x+1] == 5) && x < lebar) {
        if (map[y][x+1] == 2) {
			x =x+1;
			cout << "Selamat kamu mendapatkan summoning egg!\n";
		} else if ( map[y][x+1] == 3) {
			x =x+1;
			cout << "Selamat kamu mendapatkan item loot!\n";
		} else if (map[y][x+1] == 5) {
			x =x+1;
			cout << "Selamat kamu mendapatkan harta karun!\n";
		} else {
			x =x+1;
		} 
    }
        
	
	// peta
	for(int i=0; i<tinggi; i++) {
            for(int j=0; j<lebar; j++) {
                
                if(x == j && y == i) {
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
