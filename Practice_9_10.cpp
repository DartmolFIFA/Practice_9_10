// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Практика 9
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int SIZE = 20;
enum style { rock, pop_rock, alt_rock, indie_rock, EDM, blues_rock };
struct song {
    char song_name[50];
    float duration;
};

struct album {
    char name[45];
    char band[30];
    style genre;
    int year;
    float lenght;
    float price;
    song songs[15];
    int songCount;
    float listened; //в миллионах (прослушивания в Spotify)
};
typedef album arr_a[SIZE];

album* init() {
    album* albums = new album[SIZE];
    albums[0] = { "True", "Avicii", EDM, 2013, 46.56, 2167.30, { {"Wake Me Up", 4.07}, {"Hey Brother", 4.15}, {"Addicted To You", 2.28},
        {"You Make Me", 3.53}, {"Dear Boy", 7.59} }, 10, 5557.29};
    albums[1] = { "AM", "Arctic Monkeys", indie_rock, 2013, 41.38, 1606.0, { {"Do I Wanna Know?", 4.32}, {"R U Mine?", 3.21},
        {"Why'd You Only Call Me When You're High?", 2.41}, {"I Wanna Be Yours", 3.03}, {"Snap Out Of It", 3.13} }, 12, 14162.268};
    albums[2] = { "Leisureplex", "Olympic Ayres", EDM, 2014, 25.18, 1352.5, { {"Control", 3.45}, {"Take Flight", 3.21},
        {"We Can't Get Away", 5.15}, {"Sunshine", 4.06}, {"We Can Learn", 4.09} }, 6, 12.32};
    albums[3] = { "El Camino", "The Black Keys", blues_rock, 2011, 38.18, 5978.34, { {"Lonely Boy", 3.13}, {"Gold on the Ceiling", 3.44},
        {"Little Black Submarines", 4.11}, {"Sister", 3.25}, {"Dead and Gone", 3.41} }, 11, 1456.18};
    albums[4] = { "A Rush of Blood to the Head", "Coldplay", alt_rock, 2002, 54.08, 3490.0, { {"Amsterdam", 5.19}, {"The Scientist", 5.09},
        {"Clocks", 5.07}, {"In My Place", 3.46}, {"Politik", 5.18} }, 11, 5575.05};
    albums[5] = { "The Amazons", "The Amazons", alt_rock, 2017, 44.44, 1540.80, { {"In My Mind", 3.50}, {"Black Magic", 4.31},
        {"Stay With Me", 3.14}, {"Junk Food Forever", 3.46}, {"Ultraviolet", 3.38} }, 11, 82.53};
    albums[6] = { "Rubber Soul", "The Beatles", rock, 1965, 35.50, 2000.0, { {"Drive My Car", 2.28}, {"Norwegian Wood", 2.04},
        {"Nowhere Man", 2.43}, {"Michelle", 2.42}, {"In My Life", 2.26} }, 14, 1752.65};
    albums[7] = { "A/B", "KALEO", blues_rock, 2016, 42.17, 2819.0, { {"Broken Bones", 4.05}, {"Way down We Go", 3.33},
        {"All the Pretty Girls", 4.29}, {"No Good", 3.54}, {"I Can't Go on Without You", 6.17} }, 10, 2747.54};
    albums[8] = { "Viva la Vida or Death and All His Friends", "Coldplay", alt_rock, 2008, 45.49, 2829.0, { {"Strawberry Swing", 4.09}, {"Viva La Vida", 4.02},
        {"Violet Hill", 3.42}, {"Lost!", 3.56}, {"Death and All His Friends", 6.18} }, 10, 4018.47};
    albums[9] = { "Evolve", "Imagine Dragons", indie_rock, 2017, 39.12, 3790.0, { {"Believer", 3.24}, {"Thunder", 3.07},
        {"Whatever It Takes", 3.21}, {"Next To Me", 3.50}, {"Walking The Wire", 3.52} }, 12, 10134.9};
    albums[10] = { "An Awesome Wave", "Alt-J", indie_rock, 2012, 48.42, 4200.0, { {"Breezeblocks", 3.47}, {"Tessellate", 3.01},
        {"Something Good", 3.37}, {"Matilda", 3.48}, {"Fitzpleasure", 3.39} }, 14, 2493.40};
    albums[11] = { "Hozier", "Hozier", indie_rock, 2014, 53.26, 4900.0, { {"Take Me to Church", 4.01}, {"Someone New", 3.42},
        {"Work Song", 3.49}, {"Like Real People Do", 3.18}, {"From Eden", 4.43} }, 13, 8118.06};
    albums[12] = { "What Went Down", "Foals", indie_rock, 2015, 48.21, 1100.0, { {"London Thunder", 4.14}, {"Mountain at My Gates", 4.04},
        {"Birch Tree", 4.21}, {"Give It All", 4.47}, {"What Went Down", 5.00} }, 10, 572.01};
    albums[13] = { "Coming Up for Air", "Kodaline", alt_rock, 2015, 64.21, 4200.0, { {"The One", 3.52}, {"Everything Works Out in the End", 3.37},
        {"Moving On", 4.25}, {"Ready", 3.53}, {"Love Will Set You Free", 4.20} }, 16, 442.287};
    albums[14] = { "Rumours", "Fleetwood Mac", pop_rock, 1977, 38.55, 3500.0, { {"The Chain", 4.29}, {"Dreams", 4.17},
        {"Go Your Own Way", 3.43}, {"Never Going Back Again", 2.14}, {"Don't Stop", 3.13} }, 11, 7713.998};
    albums[15] = { "Strange Days", "The Doors", rock, 1967, 34.49, 2520.0, { {"When the Music's Over", 10.59}, {"People Are Strange", 2.10},
        {"Love Me Two Times", 3.15}, {"Strange Days", 3.06}, {"Moonlight Drive", 3.01} }, 10, 852.41};
    albums[16] = { "Tourist History", "Two Door Cinema Club", indie_rock, 2010, 32.32, 4900.0, { {"What You Know", 3.11}, {"Undercover Martyn", 2.47},
        {"Something Good Can Work", 2.44}, {"I Can Talk", 2.57}, {"This Is the Life", 3.30} }, 10, 2297.19};
    albums[17] = { "Californication", "Red Hot Chili Peppers", alt_rock, 1999, 56.24, 2600.0, { {"Scar Tissue", 3.35}, {"Otherside", 4.15},
        {"Californication", 5.29}, {"Road Trippin'", 3.24}, {"Around the World", 3.59} }, 15, 6097.88};
    albums[18] = { "Evil Friends", "Portugal. The Man", indie_rock, 2013, 48.35, 5700.0, { {"Modern Jesus", 3.14}, {"Purple Yellow Red and Blue", 4.09},
        {"Atomic Man", 3.47}, {"Plastic Soldiers", 5.04}, {"Evil Friends", 3.37} }, 12, 325.58};
    albums[19] = { "One", "C418", EDM, 2012, 99.34, 880.0, { {"Cliffside Hinson", 3.46}, {"Preliminary Art Form", 3.07},
        {"The Weirdest Year of Your Life", 3.58}, {"Post Success Depression", 3.12}, {"Tsuki No Koibumi", 5.07} }, 31, 21.95};
    return albums;
}
void AlbumInfo(const album& alb) {
    cout << "Название: " << alb.name << endl;
    cout << "Исполнитель: " << alb.band << endl;
    cout << "Стиль: " << alb.genre << endl;
    cout << "Год выпуска: " << alb.year << endl;
    cout << "Длительность: " << alb.lenght << " мин" << endl;
    cout << "Количество прослушиваний: " << alb.listened << " млн" << endl;
    cout << "Стоимость: " << alb.price << " руб" << endl;
    cout << "Количество композиций: " << alb.songCount << endl;
    cout << "Популярные композиции:" << endl;

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << alb.songs[i].song_name << " (" << alb.songs[i].duration << " мин)" << endl;
    }
}
void SortedArr(album albums[], int count, const char* title) {
    cout << endl;
    cout << " " << title << " (Найдено: " << count << ")" << endl;
    cout << endl;
    if (count == 0) {
        cout << "Нет данных для отображения" << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        AlbumInfo(albums[i]);
        cout << endl;
    }
}
//1. Фильтрация по стилю (рок или инди-рок)
int FilterByStyle(album StartArr[], int StartArrCount, album FinalArr[]) {
    int FinalArrCount = 0;
    for (int i = 0; i < StartArrCount; i++) {
        if (StartArr[i].genre == rock || StartArr[i].genre == indie_rock) {
            FinalArr[FinalArrCount] = StartArr[i];
            FinalArrCount++;
        }
    }
    return FinalArrCount;
}
//2. Сортировка пузырьком по исполнителю
void SortByArtist(album albums[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(albums[j].band, albums[j + 1].band) > 0) {
                album TempArr = albums[j];
                albums[j] = albums[j + 1];
                albums[j + 1] = TempArr;
            }
        }
    }
}
//3. Поиск конкретного альбома
void FindAnAlbum(album albums[], int count, const char* AlbumName) {
    for (int i = 0; i < count; i++) {
        if (strcmp(albums[i].name, AlbumName) == 0) {
            cout << "\nПоиск конкретного альбома:" << endl;
            cout << "\nНайден альбом: " << AlbumName << endl;
            AlbumInfo(albums[i]);
            return;
        }
    }
    cout << "\nАльбом " << AlbumName << " не найден!" << endl;
}
//4. Топ-5 популярных (по прослушиваниям)
void Top5Albums(album albums[], int count) {
    album TempArr[SIZE];
    for (int i = 0; i < count; i++) TempArr[i] = albums[i];

    // Сортировка пузырьком по убыванию прослушиваний
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (TempArr[j].listened < TempArr[j + 1].listened) {
                album t = TempArr[j];
                TempArr[j] = TempArr[j + 1];
                TempArr[j + 1] = t;
            }
        }
    }

    cout << "\nТоп-5 самых популярных альбомов (по прослушиваниям):" << endl;
    cout << "" << endl;
    for (int i = 0; i < min(5, count); i++) {
        cout << i + 1 << ". " << TempArr[i].name << " - " << TempArr[i].band << " - " << TempArr[i].listened << " млн" << endl;
    }
}
//5. Изменение альбома
/*void ModifyAlbum(album& alb) {
    cout << "\nРедактирование альбома: " << alb.name << endl;

    cout << "Новое количество прослушиваний (было: " << alb.listened << "): ";
    cin >> alb.listened;

    cout << "Новый исполнитель (был: " << alb .band << "): ";
    cin.getline(alb.band, 30);

    cout << "Новая стоимость (была: " << alb.price << "): ";
    cin >> alb.price;

    cout << "Альбом изменен!" << endl;
}*/
//6. Фильтрация по трекам (>7 композиций)
int FilterBySongCount(album StartArr[], int StartArrCount, album FinalArr[]) {
    int FinalArrCount = 0;
    for (int i = 0; i < StartArrCount; i++) {
        if (StartArr[i].songCount > 7) {
            FinalArr[FinalArrCount] = StartArr[i];
            FinalArrCount++;
        }
    }
    return FinalArrCount;
}
int main()
{
    setlocale(LC_ALL, "RU");
    cout << "-----------------------\n";
    cout << "      Практика 9\n";
    cout << "-----------------------\n";
    cout << "Стиль 0 - Рок" << endl;
    cout << "Стиль 1 - Поп-рок" << endl;
    cout << "Стиль 2 - Альт-рок" << endl;
    cout << "Стиль 3 - Инди-рок" << endl;
    cout << "Стиль 4 - EDM" << endl;
    cout << "Стиль 5 - Блюз-рок" << endl;
    album* Arr_n;
    Arr_n = init();
    //1. Фильтрация по стилю (рок или инди-рок)
    album RockAlbums[SIZE];
    int RockCount = FilterByStyle(Arr_n, SIZE, RockAlbums);
    SortedArr(RockAlbums, RockCount, "Альбомы в стиле Рок или Инди-рок");
    //2. Сортировка по исполнителю
    SortByArtist(RockAlbums, RockCount);
    SortedArr(RockAlbums, RockCount, "Отсортировано по исполнителю (A-Z)");
    //3. Поиск конкретного альбома
    FindAnAlbum(Arr_n, SIZE, "Leisureplex");
    FindAnAlbum(Arr_n, SIZE, "One");
    //4. Топ-5 популярных
    Top5Albums(Arr_n, SIZE);
    //5. Изменение альбома
    /*ModifyAlbum(Arr_n[6]);  // Rubber Soul
    cout << "\nПосле изменения:" << endl;
    AlbumInfo(Arr_n[6]);*/
    //6. Альбомы с >7 композициями
    album ManySongs[SIZE];
    int ManyCount = FilterBySongCount(Arr_n, SIZE, ManySongs);
    SortedArr(ManySongs, ManyCount, "Альбомы, в которых более чем 7 композиций");

    //Практика 10
    //Чтение из текстового файла
    ifstream fin;
    //string str;
    cout << "-----------------------\n";
    cout << "      Практика 10\n";
    cout << "-----------------------\n";
    cout << "Задание 1:\n";
    cout << "Рок и Инди-рок альбомы по 1500, остальные - по 2000:" << endl;
    fin.open("price.txt"); // файл долженбыть в ANSI _кодировке, чтобы выводились русские буквы
    if (fin.is_open()) {
        int i = 0;
        while (!fin.eof())
        {
            fin >> Arr_n[i].price;
            cout << Arr_n[i].name << " " << Arr_n[i].price << endl;
            i++;
        }
        fin.close();
    }
    else {
        cout << "File's not found\n";
    }
    cout << endl;
    cout << "Задание 2:\n";
    //Запись структуры Album в двоичный файл структуры
    fstream out("albums.bin", ios::binary | ios::out);
    out.write((char*)Arr_n, sizeof(album) * SIZE);
    out.close();
    cout << "Записано " << SIZE << " альбомов в albums.bin" << endl;

    //Чтение из двоичного файла структуры
    album* LoadedAlbums = new album[SIZE];
    fstream in("albums.bin", ios::binary | ios::in);
    in.read((char*)LoadedAlbums, sizeof(album) * SIZE);
    in.close();
    cout << "Прочитано из albums.bin" << endl;

    //Проверка
    cout << "Альбомы из бинарного файла:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << LoadedAlbums[i].name << endl;
    }

    delete[] Arr_n;
    delete[] LoadedAlbums;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
