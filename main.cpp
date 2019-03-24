#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

void zgaduj(){
    string tab[43][4] = {
        {"Albania", "Tirana", "Durres", "Szkodra"},
        {"Andora", "Andora", "Escaldes-Engordany", "Sant Julia de Loria"},
        {"Austria", "Wieden", "Graz", "Linz"},
        {"Belgia", "Bruksela", "Antwerpia", "Gandawa"},
        {"Bialorus", "Minsk", "Homel", "Mohylew"},
        {"Bosnia i Hercegowina", "Sarajewo", "Banja Luka", "Mostar"},
        {"Bulgaria", "Sofia", "Plowdiw", "Warna"},
        {"Chorwacja", "Zagrzeb", "Split", "Rijeka"},
        {"Czarnogora", "Podgorica", "Niksic", "Pljevlia"},
        {"Czechy", "Praga", "Brno", "Ostrawa"},
        {"Dania", "Kopenhaga", "Arhus", "Odense"},
        {"Estonia", "Tallinn", "Tartu", "Narwa"},
        {"Finlandia", "Helsinki", "Espoo", "Tampere"},
        {"Francja", "Paryz", "Marsylia", "Lyon"},
        {"Grecja", "Ateny", "Saloniki", "Pireus"},
        {"Hiszpania", "Madryt", "Barcelona", "Walencja"},
        {"Holandia", "Amsterdam", "Rotterdam", "Haga"},
        {"Irlandia", "Dublin", "Cork", "Galway"},
        {"Islandia", "Reykjavik", "Kopavogur", "Hafnarfjorour"},
        {"Kazachstan", "Almaty", "Astana", "Szymkent"},
        {"Liechtenstein", "Schaan", "Vaduz", "Triesen"},
        {"Litwa", "Wilno", "Kowno", "Klajpeda"},
        {"Luksemburg", "Luksemburg", "Esch-sur-Alzette", "Differdange"},
        {"Lotwa", "Ryga", "Dyneburg", "Lipawa"},
        {"Macedonia", "Skopje", "Bitola", "Kumanowo"},
        {"Moldawia", "Kiszyniow", "Bielce", "Tyraspol"},
        {"Niemcy", "Berlin", "Hamburg", "Monachium"},
        {"Norwegia", "Oslo", "Bergen", "Stavanger"},
        {"Polska", "Warszawa", "Krakow", "Lodz"},
        {"Portugalia", "Lizbona", "Porto", "Vila Nova de Gaia"},
        {"Rosja", "Moskwa", "Petersburg", "Nowosybirsk"},
        {"Rumunia", "Bukareszt", "Kluz-Napoka", "Timisoara"},
        {"San Marino", "Serravalle", "Borgo Maggiore", "San Marino"},
        {"Serbia", "Belgrad", "Nowy Sad", "Nisz"},
        {"Slowacja", "Bratyslawa", "Koszyce", "Preszow"},
        {"Slowenia", "Lublana", "Maribor", "Celje"},
        {"Szwajcaria", "Zurych", "Genewa", "Bazylea"},
        {"Szwecja", "Sztokholm", "Goteborg", "Malmo"},
        {"Turcja", "Stambul", "Ankara", "Izmir"},
        {"Ukraina", "Kijow", "Charkow", "Odessa"},
        {"Wegry", "Budapeszt", "Debreczyn", "Segedyn"},
        {"Wielka Brytania", "Londyn", "Birmingham", "Leeds"},
        {"Wlochy", "Rzym", "Mediolan", "Neapol"},
    };
    srand(time(NULL));
    int wiersz, kolumna;
    int licznik = 0;
    string odpowiedz, kraj, TAK;

    while(true){
        do{
            wiersz = rand()%43;
            kolumna = rand()%3+1;
        }while(tab[wiersz][kolumna] == "bylo");

        if(licznik != 50){
            cout << endl << "W jakim kraju znajduje sie miasto: " <<tab[wiersz][kolumna] <<"?" << endl;
            cout << "Odpowiedz(bez polskich liter): ";
            cin.sync();
            getline(cin, odpowiedz);
            transform(odpowiedz.begin(), odpowiedz.end(), odpowiedz.begin(), :: tolower);

            kraj = tab[wiersz][0];
            transform(kraj.begin(), kraj.end(), kraj.begin(), :: tolower);
            if(odpowiedz == kraj){
                cout << "Dobrze!" <<endl;
                tab[wiersz][kolumna] = "bylo";
                licznik++;
            }
            else{
                cout << "Zle! ";
                if(licznik == 0)        cout << "Nie zgadles zadnego miasta." << endl;
                else if (licznik ==1)   cout << "Zgadles " << licznik << " miasto" << endl;
                else                    cout << "Zgadles " << licznik << " miast(a)" << endl;
                cout << "Prawidlowa odpowiedz to: " << tab[wiersz][0] << endl;
                cout << "Chcesz sprobowac jeszcze raz?(T/N)" << endl;
                cin >> TAK;
                if (TAK == "T" || TAK == "t")      zgaduj();
                else                               exit(0);
            }
        }else {
            cout << "GRATULACJE! Zgadles 50 miast z rzedu!";
        }
    }
}

int main()
{
    cout << "!!! WITAMY W TESCIE Z MIAST PANSTW EUROPEJSKICH !!!"<<endl;
    cout<<endl<<"======================================================================"<<endl;
    zgaduj();

    getchar(); getchar();
    return 0;
}
