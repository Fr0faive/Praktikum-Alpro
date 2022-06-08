#include <iostream>
#include <conio.h>
using namespace std;

#define atas 72
#define bawah 80
#define kiri 75
#define kanan 77

struct item {
	string nama;
	int harga;
	int benefit;
};

struct hero {
	string nama;
	string role;
	int hp;
	int mana;
	int dam_basic;
	int att_speed;
	

	
	void attack(hero *heroObject) {
		int hpAwal = heroObject->hp;
		cout << nama << " menyerang " << heroObject->nama << endl;
		heroObject->hp = heroObject->hp - dam_basic;
		cout <<  heroObject->nama << " berkurang hpnya dari " << hpAwal<< " ke " << heroObject->hp << endl;
	}
};

int main() {
	hero myHero1;
	myHero1.nama = "Alucard";
	myHero1.role = "Fighter";
	myHero1.hp = 2621;
	myHero1.mana = 0;
	myHero1.dam_basic = 123;
	myHero1.att_speed = 1.12;
	
	hero myHero2;
	myHero2.nama = "Guinevere";
	myHero2.role = "Fighter";
	myHero2.mana = 0;
	myHero2.hp = 2528;
	myHero2.dam_basic = 126;
	myHero2.att_speed = 1.14;
	
	int tinggi= 30, lebar=30, x=2, y=19, att; 
	cout << "Cara bermain : " << endl
		 << "Tombol panah Atas/Bawah/Kanan/Kiri" << endl
		 << "9 = dinding, 8 = bangunan, 6 = rumput, 7=barrier,\n5 = harta karun, 3 = item loot, 2 = summoning egg, 1= jalan" << endl
		 << "=================================================" << endl
		 << "Jelajahi map dan temukan sesuatu!" << endl;
	cout << "Posisi kamu ada di " << x << " dan " << y << endl;
	// 9 = dinding, 8 = bangunan, 6 = rumput, 7=barrier, 5 = harta karun, 4 = Guinever, 3 = item loot, 2 = summoning egg, 1= jalan
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
		{9,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,9},
		{9,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,8,8,1,1,1,1,1,1,1,6,1,1,9},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,8,1,1,1,1,6,1,1,1,1,1,9},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,6,6,6,1,1,1,1,1,1,6,6,1,1,1,1,9},
		{9,1,1,1,1,1,1,9,9,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,6,1,1,1,1,9},
		{9,1,1,1,1,1,1,9,9,1,1,1,1,1,1,1,6,1,1,1,1,1,1,6,1,1,1,1,1,9},
		{9,1,1,4,1,1,9,9,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9},
		{9,1,1,1,1,5,2,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,9},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9},
		{9,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9},
		{9,1,1,2,1,1,1,1,1,4,1,1,1,1,1,1,1,1,6,6,9,1,1,1,1,1,1,1,1,9},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,6,6,6,1,1,1,1,1,1,1,1,9},
		{9,1,4,9,9,7,1,1,1,1,1,1,1,1,1,1,1,9,9,6,6,1,1,1,1,1,1,1,1,9},
		{9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,4,1,1,1,9},
		{9,1,1,1,1,1,9,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,1,1,9},
		{9,1,8,8,1,1,9,1,1,1,1,1,1,1,1,1,6,2,6,1,1,1,1,1,1,1,1,5,6,9},
		{6,6,8,8,1,1,1,1,1,1,4,1,1,1,1,1,1,6,6,1,1,1,1,1,1,1,1,6,6,9},
		{6,1,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,6,6,9},
		{6,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	};
	
	int panah = 0;

	while (1) {

		cout << "\nArah kemana?";
		panah = getch();
		
		system("cls");
	// atas	
	if(panah == 72 && (map[y-1][x] == 1 || map[y-1][x] == 6 || map[y-1][x] == 2 || map[y-1][x] == 3 || map[y-1][x] == 4 || map[y-1][x] == 5) && y >= 0) {
            if (map[y-1][x] == 2) {
			y =y-1;
			cout << "Selamat kamu mendapatkan summoning egg!\n";
		} else if ( map[y-1][x] == 3) {
			y =y-1;
			cout << "Selamat kamu mendapatkan item loot!\n";
		} else if (map[y-1][x] == 5) {
			y =y-1;
			cout << "Selamat kamu mendapatkan harta karun!\n";
		} else if (map[y-1][x] == 4) {
			while(1) {
				cout << "Kamu berhadapan dengan Guinevere!\nKamu ingin menyerang nya? (1/0) : ";
				cin >> att;
				if (att == 1) {
					myHero1.attack(&myHero2);
					if (myHero2.hp == 0 || myHero2.hp<0) {
						cout << "Musuh sudah kalah!\n";
						break;
					}
				} else {
					break;
				}
			}
			y =y-1;
		} else {
			y =y-1;
		}
        }
	
	// bawah
	if(panah == 80 && (map[y+1][x] == 1 || map[y+1][x] == 6 || map[y+1][x] == 2 || map[y+1][x] == 3 || map[y+1][x] == 4 || map[y+1][x] == 5) && y < tinggi) {
        if (map[y+1][x] == 2) {
			y =y+1;
			cout << "Selamat kamu mendapatkan summoning egg!\n";
		} else if ( map[y+1][x] == 3) {
			y =y+1;
			cout << "Selamat kamu mendapatkan item loot!\n";
		} else if (map[y+1][x] == 4) {
			while(1) {
				cout << "Kamu berhadapan dengan Guinevere!\nKamu ingin menyerang nya? (1/0) : ";
				cin >> att;
				if (att == 1) {
					myHero1.attack(&myHero2);
					if (myHero2.hp == 0 || myHero2.hp<0) {
						cout << "Musuh sudah kalah!\n";
						break;
					}
				} else {
					break;
				}
			}
			y =y+1;
		} else if (map[y+1][x] == 5) {
			y =y+1;
			cout << "Selamat kamu mendapatkan harta karun!\n";
		} else {
			y =y+1;
		} 
    }
	
	// kiri
	if(panah == 75 && (map[y][x-1] == 1 || map[y][x-1] == 6 || map[y][x-1] == 2 || map[y][x-1] == 3 || map[y][x-1] == 4 || map[y][x-1] == 5) && x >= 0) {
		if (map[y][x-1] == 2) {
			x =x-1;
			cout << "Selamat kamu mendapatkan summoning egg!\n";
		} else if ( map[y][x-1] == 3) {
			x =x-1;
			cout << "Selamat kamu mendapatkan item loot!\n";
		} else if (map[y][x-1] == 4) {
			while(1) {
				cout << "Kamu berhadapan dengan Guinevere!\nKamu ingin menyerang nya? (1/0) : ";
				cin >> att;
				if (att == 1) {
					myHero1.attack(&myHero2);
					if (myHero2.hp == 0 || myHero2.hp<0) {
						cout << "Musuh sudah kalah!\n";
						break;
					}
				} else {
					break;
				}
			}
			x =x-1;
		} else if (map[y][x-1] == 5) {
			x =x-1;
			cout << "Selamat kamu mendapatkan harta karun!\n";
		} else {
			x =x-1;
		}   
    }
	
	// kanan
	if(panah == 77 && (map[y][x+1] == 1 || map[y][x+1] == 6 || map[y][x+1] == 2 || map[y][x+1] == 3 || map[y][x+1] == 4 || map[y][x+1] == 5) && x < lebar) {
        if (map[y][x+1] == 2) {
			x =x+1;
			cout << "Selamat kamu mendapatkan summoning egg!\n";
		} else if ( map[y][x+1] == 3) {
			x =x+1;
			cout << "Selamat kamu mendapatkan item loot!\n";
		} else if (map[y][x+1] == 4) {
			while(1) {
				cout << "Kamu berhadapan dengan Guinevere!\nKamu ingin menyerang nya? (1/0) : ";
				cin >> att;
				if (att == 1) {
					myHero1.attack(&myHero2);
					if (myHero2.hp == 0 || myHero2.hp<0) {
						cout << "Musuh sudah kalah!\n";
						break;
					}
				} else {
					break;
				}
			}
			x =x+1;
		} else if (map[y][x+1] == 5) {
			x =x+1;
			cout << "Selamat kamu mendapatkan harta karun!\n";
		} else {
			x =x+1;
		} 
    }
	cout << "Posisi kamu di " << x << "," << y << endl;
	// peta
	for(int i=0; i<tinggi; i++) {
            for(int j=0; j<lebar; j++) {
                
                if(x == j && y == i) {
                    cout << "H" << " ";
                } else {
                    cout << map[i][j] << " ";
                }
            }
            cout << endl;
        }
	}
	return 0;
}
