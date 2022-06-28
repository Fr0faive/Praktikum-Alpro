#include <iostream>
#include <conio.h>
#include "warna/warna.hpp"
using namespace std;

#define tombolAtas 72
#define tombolBawah 80
#define tombolKiri 75
#define tombolKanan 77
#define tombolEnd 79
#define tombolDelete 83

struct user {
    string nickName;
	string nama;
	string type;
	int hp;
	int dmg;

    void attack(int *objHp) {
        *objHp = *objHp - dmg;
        cout << "Kamu menyerangnya, sisa darah Oblig " << *objHp << endl;
    }

};

struct oblig {
    string nama;
    string type;
    int hp;
    int dmg;

    void attack(string *objNama,int *objHp) {
        *objHp = *objHp - dmg;
        cout << dye::red(*objNama) << " menyerang kamu! Sisa darah kamu " << *objHp << endl;
    }

};

int main() {
    int tombol,attack, kali=13, pil;
    int posisix = 10;
    int posisiy = 11;

    //Isi Peta
    //1 = Jalan, 2 = rumput, 3 = ItemLoot, 4 = HealingSpot
    int peta[kali][kali] = {
        {8,8,8,8,8,8,8,8,8,8,8,8,8},
        {8,4,1,1,7,2,8,1,5,8,1,4,8},
        {8,1,3,7,2,5,1,1,8,1,1,1,8},
        {8,1,7,7,1,2,1,1,1,1,8,1,8},
        {8,1,2,7,1,1,1,2,2,2,1,1,8},
        {8,1,1,1,1,1,8,2,2,1,1,1,8},
        {7,7,7,7,1,1,8,1,1,1,1,1,8},
        {7,7,1,1,1,1,8,1,1,8,1,5,8},
        {7,1,1,1,1,1,8,1,1,1,1,8,8},
        {8,1,8,1,8,1,8,3,1,8,1,1,8},
        {8,1,8,1,1,1,8,1,1,1,1,1,8},
        {8,1,1,1,8,1,8,8,1,1,1,1,8},
        {8,8,8,8,1,1,8,8,1,1,1,1,8},
    };


    user pemain;
    oblig curio;

    pemain.nama = "Myaillse";
    pemain.hp = 11250;
    pemain.type = "Swordman";
    pemain.dmg = 254;

    menu :
    system("cls");
    cout << hue::blue << "======================" << endl
         << "=== Selamat Datang ===" << endl
         << "=====      di    =====" << endl
         << "===  Wanna be Game ===" << endl
         << "======================" << hue::reset << endl << endl;

    cout << hue::bright_white << "1. Start Game\n2. Keluar\nPilihan : " << hue::reset;
    cin >> pil;
    switch (pil) {
    case 1 :
        system("cls");
        cout << hue::green << "===   SELAMAT BERMAIN, PLAYER!   ===\n"<<hue::reset;
        cout << "Masukkan nickname : "; cin >> pemain.nickName;
    while (true) {
    //Render Map
    system("cls");
    for (int y=0; y<kali;y++) {
        for(int x=0; x<kali;x++) {
            if (posisix == x && posisiy == y) {
                cout << dye::blue("U") << " ";
            } else {
                if (peta[y][x]==1) {
                    cout << dye::vanilla(peta[y][x]) << " ";
                } else if (peta[y][x]==2) {
                    cout << dye::green(peta[y][x]) << " ";
                } else if (peta[y][x]==3) {
                    cout << dye::yellow_on_white(peta[y][x]) << " ";
                } else if (peta[y][x]==4) {
                    cout << dye::green_on_green(peta[y][x]) << " ";
                } else if (peta[y][x]==5) {
                    cout << dye::red_on_white(peta[y][x]) << " ";
                } else if (peta[y][x]==7) {
                    cout << dye::aqua_on_aqua(peta[y][x]) << " ";
                } else if (peta[y][x]==8) {
                    cout << dye::green_on_light_green(peta[y][x]) << " ";
                } else {
                    cout << peta[y][x] << " ";
                }
            }
        }
        cout << endl;
     }
    // Legenda
    cout << dye::blue("\nU") << " : Kamu" << endl
         << dye::bright_white_on_black("1") << " : Jalan"<<endl
         << dye::green("2") << " : Rumput" << endl
         << dye::aqua_on_aqua("7") << " : Sungai" << endl
         << dye::green_on_grey("8") << " : Pohon" << endl;

    // Posisi
    cout << "Posisi Kamu (U) : " << posisix << " " << posisiy << endl;
     // Petunjuk
     cout << "\n\nNote : \n1. Gunakan arrow key untuk menggerakkan player\n2. Tekan tombol End untuk Detail Karakter\n3. Tekan Delete untuk kembali kemu\n";
     cout << "Masukkan : ";
     tombol = getch();

    // Gerakan
    if (tombol == tombolAtas && posisiy >= 0) {
        if (peta[posisiy-1][posisix] == 8 || peta[posisiy-1][posisix] == 7) {
            cout << "Tidak bisa lewat!\n";
        } else {
            posisiy = posisiy - 1;
        }
    } else if (tombol == tombolBawah && posisiy < kali) {
        if (peta[posisiy+1][posisix] == 8 || peta[posisiy+1][posisix] == 7) {
            cout << "Tidak bisa lewat!\n";
        } else {
            posisiy = posisiy + 1;
        }
    } else if (tombol == tombolKiri && posisix >= 0) {
        if (peta[posisiy][posisix-1] == 8 || peta[posisiy][posisix-1] == 7) {
            cout << "Tidak bisa lewat!\n";
        } else {
            posisix = posisix - 1;
        }
    } else if (tombol == tombolKanan && posisix < kali) {
        if (peta[posisiy][posisix+1] == 8 || peta[posisiy][posisix+1] == 7) {
            cout << "Tidak bisa lewat!\n";
        } else {
            posisix = posisix + 1;
        }
    } else if (tombol == tombolEnd) {
        system("cls");
        cout << dye::aqua("\n=== Detail Karakter ===\n")
         << dye::green("Nickname     : ")<< pemain.nickName << endl
         << "Nama Pejuang : " << pemain.nama << endl
         << "Type         : " << pemain.type << endl
         << "HP           : " << pemain.hp << endl
         << "Damage       : " << pemain.dmg << endl;
         getch();
    } else if (tombol == tombolDelete) {
        system("cls");
        cout << dye::yellow("Sedang kembali ke menu") <<endl;
        getch();
        goto menu;
    }

    //Bertemu musuh
    if (peta[posisiy][posisix] == 5) {
            curio.nama = "Roloo Oblig";
            curio.type = "Easy Oblig";
            curio.hp = 5340;
            curio.dmg = 110;
        while(true) {
            system("cls");
            int attMnstr = rand() % 2;
            cout << dye::red("Kamu bertemu Oblig!") << endl
                 << "Nama Oblig : " << curio.nama << endl
                 << "Type       : " << curio.type << endl
                 << "HP         : " << curio.hp << endl
                 << "Damage     : " << curio.dmg << endl << endl;
            cout << dye::blue("Darah kamu : ") << pemain.hp << endl <<dye::red("Damage kamu : ") << pemain.dmg << endl;
            cout << "Kamu ingin menyerangnya?\ntekan 1 untuk menyerang, 0 untuk menghindar! ";
            cin >> attack;
            if (attack==1) {
                system("cls");
                pemain.attack(&curio.hp);
                if (curio.hp <= 0) {
                    cout << "Kamu sudah mengalahkan " << dye::red(curio.nama) << "!"<<endl;
                    getch();
                    break;
                }
                if (attMnstr == 1) {
                curio.attack(&curio.nama, &pemain.hp);
                } else {
                    cout << dye::red(curio.nama) << " tidak berhasil menyerangmu!" << endl;
                }
                getch();
            } else {
                break;
            }

        }
    }

    //Item Spot & Healing spot
    if (peta[posisiy][posisix] == 3) {
        if (pemain.dmg <= 496) {
            pemain.dmg = pemain.dmg + (rand()%43);
            system("cls");
            cout << "Damage kamu bertambah menjadi " << pemain.dmg << endl;
            getch();
        } else {
            system("cls");
            cout << "Damage kamu sudah maksimal!\n";
            getch();
        }
    } else if (peta[posisiy][posisix] == 4 && pemain.hp <= 11250) {
        if (pemain.hp<=11250) {
            for (int h=0;h<3;h++) {
                pemain.hp += (rand()%79);
            }
            system("cls");
            cout << "Darah kamu menjadi : " << pemain.hp << endl;
            getch();
        } else {
            system("cls");
            cout << "Darah kamu sudah maksimal!\n";
            getch();
        }
    }


    }
    break;
    case 2 :
        getch();
    break;
    default :
        cout << "Tidak ada pilihan itu!\n";
    break;
    }
    return 0;
   }

