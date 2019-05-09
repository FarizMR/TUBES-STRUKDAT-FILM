#include <iostream>
#include <stdlib.h>
#include <string>
#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#define artistName(A) A->artistName
#define nextArtist(A) A->nextArtist
#define prevArtist(A) A->prevArtist
#define artistRole(A) A-> artistRole
#define filmTitle(F) F->filmTitle
#define nextFilm(F) F->nextFilm
#define nextR(R) R->nextR
#define film(R) R->film
#define artist(R) R->artist
#define firstArtist(L) L.firstArtist
#define firstRelasi(L) L.firstRelasi
#define firstFilm(L) L.firstFilm

using namespace std;

typedef struct relasi* adrRelasi;
typedef struct film* adrFilm;
typedef struct artist* adrArtist;

struct artist { //Parent
    string artistRole;
    string artistName;
    adrArtist nextArtist;
    adrArtist prevArtist;
};

struct relasi {
    adrRelasi nextR;
    adrFilm film;
    adrArtist artist;
};

struct film { //child
    string filmTitle;
    adrFilm nextFilm;
};

struct listArtist { //List Double - insert terurut
    adrArtist firstArtist;
};

struct listFilm { //List circular - insert last
    adrFilm firstFilm;
};

struct listRelasi { //List single - insert first
    adrRelasi firstRelasi;
};

void menu();
adrArtist allocationArtist(string namaArtis, int roleArtist);
adrFilm allocationFilm(string judulFilm);
adrRelasi allocationRelasi(adrFilm alamatFilm, adrArtist alamatArtis);
void createListArtist(listArtist &L);
void createListFilm(listFilm &L);
void createListRelasi(listRelasi &L);
bool hasAlreadyArtist(string nama, listArtist L);
void addArtist(listArtist &L);
bool hasAlreadyFilm(string judul, listFilm L);
void addFilm(listFilm &L);
void addRelasi(listArtist LA, listFilm LF, listRelasi &LR);
void deleteArtist(adrArtist &A, listArtist &L, adrRelasi &R, listRelasi &LR);
void deleteFilm(adrFilm &F, listFilm &L, adrRelasi R, listRelasi &LR);
void viewAllFIlm(listFilm L, listRelasi LR);
void viewSpecificArtist(listArtist L, listRelasi LR);
void viewSpecificFilm(listFilm L, listRelasi LR);
adrArtist getArtist(string nama, listArtist L);
adrFilm getFilm(string judul, listFilm L);
void topArtist(listArtist LA, listRelasi L);
void topThreeActrist(listArtist LA, listRelasi LR);

#endif // TUBES_H_INCLUDED
