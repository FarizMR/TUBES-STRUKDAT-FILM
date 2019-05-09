#include "tubes.h"

adrArtist allocationArtist(string namaArtis, int roleArtist) {
    adrArtist A = new artist;
    artistName(A) = namaArtis;
    if(roleArtist == 1) {
        artistRole(A) = "aktor";
    } else if(roleArtist == 2) {
        artistRole(A) = "aktris";
    }
    nextArtist(A) = NULL;
    prevArtist(A) = NULL;
    return A;
}

adrFilm allocationFilm(string judulFilm) {
    adrFilm F = new film;
    filmTitle(F) = judulFilm;
    nextFilm(F) = NULL;
    return F;
}

adrRelasi allocationRelasi(adrFilm alamatFilm, adrArtist alamatArtis) {
    adrRelasi R = new relasi;
    film(R) = alamatFilm;
    artist(R) = alamatArtis;
    nextR(R) = NULL;
    return R;
}

void createListArtist(listArtist &L) {
    firstArtist(L) = NULL;
}

void createListFilm(listFilm &L) {
    firstFilm(L) = NULL;
}

void createListRelasi(listRelasi &L) {
    firstRelasi(L) = NULL;
}

bool hasAlreadyArtist(string nama, listArtist L) {
    adrArtist A = firstArtist(L);
    bool status = false;
    while(A != NULL) {
        if(artistName(A) == nama) {
            status = true;
        }
        A = nextArtist(A);
    }
    return status;
}

adrArtist getArtist(string nama, listArtist L) {
    adrArtist A = firstArtist(L);
    adrArtist Ar = NULL;;
    while(A != NULL) {
        if(artistName(A) == nama) {
            Ar = A;
        }
        A = nextArtist(A);
    }
    if(Ar == NULL) {
        return NULL;
    } else {
        return Ar;
    }
}

void addArtist(listArtist &L) {
    system("cls");
    cout << "== INPUT NAMA ARTIST ==" << endl;
    adrArtist A;
    string namaArtis;
    do {
        cout << "Nama artis  : ";
        cin >> namaArtis;
        A = getArtist(namaArtis, L);
    } while(A != NULL);
    int role = 9;
    do{
        cout << "* ( 1 ) Aktor  ( 2 ) Aktris\nPeran artis (1/2) : ";
        cin >> role;
    }while(role != 1 && role != 2);
    A = allocationArtist(namaArtis, role);

    if(firstArtist(L) != NULL) {
        if(artistName(A) < artistName(firstArtist(L))) {
            nextArtist(A) = firstArtist(L);
            prevArtist(firstArtist(L)) = A;
            firstArtist(L) = A;
        } else {
            adrArtist P = firstArtist(L);
            while(nextArtist(P) != NULL && artistName(A) > artistName(nextArtist(P)) ) {
                P = nextArtist(P);
            }
            if(nextArtist(P) == NULL) {
                nextArtist(P) = A;
                prevArtist(A) = P;
            } else {
                nextArtist(A) = nextArtist(P);
                nextArtist(P) = A;
            }
        }
    } else {
        adrArtist A = allocationArtist(namaArtis, role);
        firstArtist(L) = A;
    }
    system("pause");

    //BUAT INSERT TERURUT ARTIS BERDASARKAN ABJAD
}

bool hasAlreadyFilm(string judul, listFilm L) {
    adrFilm F = firstFilm(L);
    bool status = false;
    do {
        if(filmTitle(F) == judul) {
            status = true;
        }
        F = nextFilm(F);
    } while(nextFilm(F) != firstFilm(L));
    return status;
}

adrFilm getFilm(string judul, listFilm L) {
    if (firstFilm(L) == NULL) {
        return NULL;
    } else {
        adrFilm F = firstFilm(L);
        while ((nextFilm(F) != firstFilm(L)) && (filmTitle(F) != judul)) {
            F = nextFilm(F);
        }
        if (filmTitle(F) == judul) {
            return F;
        } else {
            return NULL;
        }
    }
}

void addFilm(listFilm &L) {
    system("cls");
    adrFilm F;
    string judulFilm;
    cout << "== INPUT FILM ==" << endl;
    do {
        cout << "Judul film : ";
        cin >> judulFilm;
        F = getFilm(judulFilm, L);
    } while(F != NULL);
    F = allocationFilm(judulFilm);

    if(firstFilm(L) == NULL) {
        firstFilm(L) = F;
        nextFilm(F) = firstFilm(L);
    } else {
        if(nextFilm(firstFilm(L)) == firstFilm(L)) {
            nextFilm(firstFilm(L)) = F;
            nextFilm(F) = firstFilm(L);
        } else {
            adrFilm Prec = firstFilm(L);
            while(nextFilm(Prec) != firstFilm(L)) {
                Prec = nextFilm(Prec);
            }
            nextFilm(Prec) = F;
            nextFilm(F) = firstFilm(L);
        }
    }
}

void addRelasi(listArtist LA, listFilm LF, listRelasi &LR) {
    if(firstArtist(LA) != NULL && firstFilm(LF) != NULL) {
        system("cls"); string namaArtis; string judulFilm;
        cout << "== TAMBAH DATA FILM ==" << endl;
        adrArtist A;
        do {
            cout << "Nama artis : "; cin >> namaArtis;
            A = getArtist(namaArtis, LA);
        } while(A == NULL);
        adrFilm F;
        cout << "Judul film : "; cin >> judulFilm;
        do {
            F = getFilm(judulFilm, LF);
            if (F == NULL) {
                cout<<"Film tidak ada, ulangi"<<endl;
                cout << "Judul film : "; cin >> judulFilm;
            }
        } while (F == NULL);
        adrRelasi R = allocationRelasi(F,A);
        if(firstRelasi(LR) == NULL) {
            firstRelasi(LR) = R;
        } else {
            nextR(R) = firstRelasi(LR);
            firstRelasi(LR) = R;
        }
    } else {
        cout << "List artis atau film masih kosong" << endl;
    }
    system("pause");
}

void deleteArtist(adrArtist &A, listArtist &L, adrRelasi &R, listRelasi &LR) {
    if(firstArtist(L) != NULL) {
        cout << "== HAPUS DATA ARTIST ==" << endl;
        cout << "Nama artis : "; string nama;
        cin >> nama;
        adrArtist A = getArtist(nama, L);
        adrRelasi R ;
        if(A == NULL) {
            cout << nama << " tidak ada" << endl;
        } else {
            R = firstRelasi(LR);
            while(R != NULL) {
                if(artist(R) == A) {
                    adrRelasi Q = R;
                    R = nextR(Q);
                    if(Q == firstRelasi(LR)) {
                        if(nextR(firstRelasi(LR)) == NULL) {
                            firstRelasi(LR) = NULL;
                            nextR(Q) = NULL;
                        } else {
                            firstRelasi(LR) = nextR(Q);
                            nextR(Q) = NULL;
                        }
                        artist(Q) = NULL;
                        film(Q) = NULL;
                        delete Q;
                    } else {
                        adrRelasi Prec = firstRelasi(LR);
                        while(nextR(Prec) != Q) {
                            Prec = nextR(Prec);
                        }
                        R = nextR(Q);
                        artist(Q) = NULL;
                        film(Q) = NULL;
                        nextR(Prec) = nextR(Q);
                        nextR(Q) = NULL;
                        delete Q;

                    }
                } else {
                    R = nextR(R);
                }
            }
            if(A == firstArtist(L)) {
                if(nextArtist(firstArtist(L)) == NULL) {
                    firstArtist(L) = NULL;
                    nextArtist(A) = NULL;
                } else {
                    firstArtist(L) = nextArtist(A);
                    prevArtist(firstArtist(L)) = NULL;
                    nextArtist(A) = NULL;
                }
            } else {
                if(nextArtist(A) == NULL) {
                    nextArtist(prevArtist(A)) = NULL;
                    prevArtist(A) = NULL;
                } else {
                    nextArtist(prevArtist(A)) = nextArtist(A);
                    prevArtist(nextArtist(A)) = prevArtist(A);
                    prevArtist(A) = NULL;
                    nextArtist(A) = NULL;
                }
            }
            delete A;

        }
    }
    system("pause");
}

void deleteFilm(adrFilm &F, listFilm &L, adrRelasi R, listRelasi &LR) {
    if(firstFilm(L) != NULL) {
        cout << "== HAPUS DATA FILM ==" << endl;
        cout << "Judul : "; string judul;
        cin >> judul;
        adrFilm F = getFilm(judul, L);
        adrRelasi R ;
        if(F == NULL) {
            cout << "Film dengan " <<  judul << " tidak ada" << endl;
        } else {
            R = firstRelasi(LR);
            while(R != NULL) {
                if(film(R) == F) {
                    adrRelasi Q = R;
                    R = nextR(Q);
                    if(Q == firstRelasi(LR)) {
                        if(nextR(firstRelasi(LR)) == NULL) {
                            firstRelasi(LR) = NULL;
                            nextR(Q) = NULL;
                        } else {
                            firstRelasi(LR) = nextR(Q);
                            nextR(Q) = NULL;
                        }
                        artist(Q) = NULL;
                        film(Q) = NULL;
                        delete Q;
                    } else {
                        adrRelasi Prec = firstRelasi(LR);
                        while(nextR(Prec) != Q) {
                            Prec = nextR(Prec);
                        }
                        R = nextR(Q);
                        artist(Q) = NULL;
                        film(Q) = NULL;
                        nextR(Prec) = nextR(Q);
                        nextR(Q) = NULL;
                        delete Q;

                    }
                } else {
                    R = nextR(R);
                }
            }
            if(F == firstFilm(L)) {
                if(nextFilm(F) == firstFilm(L)) {
                    firstFilm(L) = NULL;
                    nextFilm(F) = NULL;
                } else if(nextFilm(nextFilm(F)) == firstFilm(L)) {
                    firstFilm(L) = nextFilm(F);
                    nextFilm(firstFilm(L)) = firstFilm(L);
                    nextFilm(F) = NULL;
                } else if(nextFilm(nextFilm(F)) != firstFilm(L)) {
                    adrFilm Prec = firstFilm(L);
                    while(nextFilm(Prec) != firstFilm(L)) {
                        Prec = nextFilm(Prec);
                    }
                    firstFilm(L) = nextFilm(firstFilm(L));
                    nextFilm(Prec) = firstFilm(L);
                    nextFilm(F) = NULL;
                }
            } else {
                adrFilm Prec = firstFilm(L);
                while(nextFilm(Prec) != F) {
                    Prec = nextFilm(Prec);
                }
                nextFilm(Prec) = nextFilm(F);
                nextFilm(F) = NULL;
            }
            delete F;

        }
    }
    system("pause");
}

void viewAllFIlm(listFilm L, listRelasi LR) {
    cout << "\n== LIHAT FILM ==" << endl;
    if(firstFilm(L) != NULL) {
        adrFilm F = firstFilm(L);

        do{
            cout << "JUDUL : " << filmTitle(F);
            adrRelasi R = firstRelasi(LR);
            while(R != NULL) {
                if(film(R) == F) {
                    cout << "\n -> " << artistName(artist(R));
                }
                R = nextR(R);
            }
            cout << endl;
            F = nextFilm(F);
        }while(F != firstFilm(L));
    } else {
        cout << "- List film masih kosong -" << endl;
    }
    system("pause");
}

void viewSpecificArtist(listArtist L, listRelasi LR) {
    if(firstArtist(L) != NULL) {
        system("cls");
        adrArtist A;
        cout << "== LIHAT DATA FILM YANG DIPERANKAN ARTIS X ==" << endl;
        cout << "Nama : "; string nama;
        cin >> nama;
        A = getArtist(nama, L);
        while(A == NULL) {
            cout << "Maaf, nama tersebut tidak ada di list" << endl;
            cout << "Nama : ";
            cin >> nama;
            A = getArtist(nama,L);
        }
        cout << "==============================================" << endl;
        adrRelasi R = firstRelasi(LR);
        cout << "Film yg diperankan oleh " << artistName(A) <<  " : " << endl;
        if(R == NULL) {
            cout << "Tidak ada" << endl;
        } else {
            while(R != NULL) {
                if(artist(R) == A) {
                    cout << " -> " << filmTitle(film(R)) << endl;
                }
                R = nextR(R);
            }
            adrRelasi cekR = firstRelasi(LR);
            while(artist(cekR) != A && cekR != NULL) {
                cekR = nextR(cekR);
            }
            if(cekR == NULL) {
                cout << "Tidak ada" << endl;
            }
        }
    } else {
        cout << "List artis masih kosong" << endl;
    }

    system("pause");
}

void viewSpecificFilm(listFilm L, listRelasi LR) {
    if(firstFilm(L) != NULL) {
        system("cls");
        cout << "== LIHAT DATA ARTIS YANG BERPERAN DI FILM X ==" << endl;
        adrFilm F;
        cout << "Judul : "; string judul;
        cin >> judul;
        F = getFilm(judul, L);
        while(F == NULL) {
            cout << "Maaf, film dengan judul tersebut tidak ada" << endl;
            cout << "Judul : "; string judul;
            cin >> judul;
            F = getFilm(judul, L);
        }
        cout << "===============================================" << endl;
        adrRelasi R = firstRelasi(LR);
        cout << "Film " << filmTitle(F) <<  " diperankan oleh : " << endl;
        if(R == NULL) {
            cout << "Tidak ada" << endl;
        } else {
            while(R != NULL) {
                if(film(R) == F) {
                    cout << " -> " << artistName(artist(R)) << endl;
                }
                R = nextR(R);
            }
            adrRelasi cekR = firstRelasi(LR);
            while(film(cekR) != F && cekR != NULL) {
                cekR = nextR(cekR);
            }
            if(cekR == NULL) {
                cout << "Tidak ada" << endl;
            }
        }
    } else {
        cout << "List film masih kosong" << endl;
    }
    system("pause");
}

void topArtist(listArtist LA, listRelasi L) {
    system("cls");
    if(firstRelasi(L) == NULL) {
        cout << "List relasi masih kosong" << endl;
    } else {
        if(firstArtist(LA) == NULL) {
            cout << "List artist masih kosong" << endl;
        } else {
            adrArtist A = firstArtist(LA);
            int topAo = 0;
            int topAi = 0;
            adrArtist adrTopAo = NULL;
            adrArtist adrTopAi = NULL;
            while(A != NULL) {
                adrRelasi R = firstRelasi(L);
                int tempAo = 0;
                int tempAi = 0;
                if(artistRole(A) == "aktor") {
                    while(R != NULL) {
                        if(artist(R) == A) {
                            if(artistRole(artist(R)) == artistRole(A)) {
                                tempAo = tempAo + 1;
                            }
                        }
                        R = nextR(R);
                    }
                }
                if(artistRole(A) == "aktris") {
                    while(R != NULL) {
                        if(artist(R) == A) {
                            if(artistRole(artist(R)) == artistRole(A)) {
                                tempAi = tempAi + 1;
                            }
                        }
                        R = nextR(R);
                    }
                }
                if(tempAo > topAo) {
                    topAo = tempAo;
                    adrTopAo = A;
                }
                if(tempAi > topAi) {
                    topAi = tempAi;
                    adrTopAi = A;
                }
                A = nextArtist(A);
            }
            if(topAo != 0) {
                cout << "Top aktor : " << artistName(adrTopAo) << " dengan bermain di " << topAo << " film" << endl;
            }
            if(topAi != 0) {
                cout << "Top aktris : " << artistName(adrTopAi) << " dengan bermain di " << topAi << " film" << endl;
            }
        }
    }
    system("pause");
}

void topThreeActrist(listArtist LA, listRelasi LR) {
    adrArtist A = firstArtist(LA);
    adrRelasi R;
    int tempAi = 0;
    adrArtist top1, top2, top3;
    int iTop1 = 0;
    int iTop2 = 0;
    int iTop3 = 0;
    if(firstArtist(LA) != NULL) {
        int countAktris = 0;
        while(countAktris < 3 && A != NULL) {
            if(artistRole(A) == "aktris") {
                countAktris = countAktris + 1;
            }
            A = nextArtist(A);
        }
        if(countAktris >= 3) {
            A = firstArtist(LA);
            R = firstRelasi(LR);
            if(R != NULL) {
                R = firstRelasi(LR);
                while(A != NULL) {
                    while(R != NULL) {
                        if(artist(R) == A) {
                            tempAi = tempAi + 1;
                        }
                        R = nextR(R);
                    }
                    if(tempAi > iTop3) {
                        if(tempAi > iTop2) {
                            if(tempAi > iTop1) {
                                iTop2 = iTop1;
                                iTop3 = iTop2;
                                iTop1 = tempAi;
                                top3 = top2;
                                top2 = top1;
                                top1 = A;
                            } else {
                                iTop3 = iTop2;
                                iTop2 = tempAi;
                                top3 = top2;
                                top2 = A;
                            }
                        } else {
                            iTop3 = tempAi;
                            top3 = A;
                        }
                    }

                    A = nextArtist(A);
                }

                cout << "== TOP AKTRIS ==" << endl;
                cout << "1. " << artistName(top1) << " dengan film " << iTop1;
                cout << "2. " << artistName(top2) << " dengan film " << iTop2;
                cout << "3. " << artistName(top3) << " dengan film " << iTop3;
            } else {
                cout << "List relasi masih kosong" << endl;
            }
        } else {
            cout << "Jumlah aktris < 3" << endl;
        }
    }
    system("pause");
}

void viewArtist(listArtist L) {
    system("cls");
    adrArtist A = firstArtist(L);
    int i = 1;
    if(A != NULL) {
        while(A != NULL) {
            cout << i << " " << artistName(A) << " (" << artistRole(A) << ") "  << endl;
            A = nextArtist(A);
            i++;
        }
    } else {
        cout << "list artis kosong" << endl;
    }
    system("pause");
}
