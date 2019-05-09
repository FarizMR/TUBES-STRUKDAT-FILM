#include "tubes.cpp"

int main()
{
    listArtist LA; createListArtist(LA);
    listFilm LF; createListFilm(LF);
    listRelasi LR; createListRelasi(LR);
    adrArtist A; adrFilm F; adrRelasi R;
    char chooser = '1';

    while(chooser != 'a' || chooser != 'b' || chooser != 'c' || chooser != 'd' || chooser != 'e' || chooser != 'f' || chooser != 'g' || chooser != 'h' || chooser != 'v') {
        system("cls");
        cout << "=== DATA PERFILMAN ===" << endl;
        cout << "===      MENU      ===" << endl;
        cout << "a. Tambah artis" << endl;
        cout << "b. Tambah film" << endl;
        cout << "c. Tambah relasi artis - film " << endl;
        cout << "d. Hapus artis" << endl;
        cout << "e. Hapus film" << endl;
        cout << "f. Tampilkan seluruh film" << endl;
        cout << "g. Tampilkan film yang dibintangi artis x" << endl;
        cout << "h. Tampilkan artis yang membintangi film" << endl;
        cout << "i. Tampilkan artis top"  << endl;
        cout << "Pilihan : "; cin >> chooser;
        switch(chooser){
            case 'a' :
                addArtist(LA);
                break;
            case 'b' :
                addFilm(LF);
                break;
            case 'c' :
                addRelasi(LA, LF, LR);
                break;
            case 'd' :
                deleteArtist(A, LA, R, LR);
                break;
            case 'e' :
                deleteFilm(F, LF, R, LR);
                break;
            case 'f' :
                viewAllFIlm(LF, LR);
                break;
            case 'g' :
                viewSpecificArtist(LA, LR);
                break;
            case 'h' :
                viewSpecificFilm(LF, LR);
                break;
            case 'i' :
                topArtist(LA, LR);
                break;
            case 'j' :
                topThreeActrist(LA,LR);
                break;
            case 'v' :
                viewArtist(LA);
                break;
            default :
                break;
        }
    }
}
