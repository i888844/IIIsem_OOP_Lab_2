#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

class track
{
private:
    int track_number;
    int people_amount;
    int max_people_amount;
public:
    track()
    {
        track_number = 0;
        people_amount = 0;
        max_people_amount = 1;
    }
    track(int _track_number, int _people_amount, int _max_people_amount)
    {
        if (track_number >= 0)
        {
            track_number = _track_number;
        }
        else
        {
            track_number = 0;
        }
        if (_people_amount >= 0)
        {
            people_amount = _people_amount;
        }
        else
        {
            people_amount = 0;
        }
        if (_max_people_amount >= 1)
        {
            max_people_amount = _max_people_amount;
        }
        else
        {
            max_people_amount = 1;
        }
    }
    track(track& object)
    {
        track_number = object.track_number;
        people_amount = object.people_amount;
        max_people_amount = object.max_people_amount;
    }
    ~track() {}
    int get_track_number() { return track_number; }
    int get_people_amount() { return people_amount; }
    int get_max_people_amount() { return max_people_amount; }
    void set_track_number(int _settable_track_number)
    {
        if (_settable_track_number <= 0)
        {
            cout << "Невозможно присвоить данное значение номера дорожки." << endl;
        }
        else
        {
            track_number = _settable_track_number;
        }
    }
    void set_people_amount(int _settable_people_amount)
    {
        if (_settable_people_amount < 0)
        {
            cout << "Невозможно присвоить данное значение количества людей на дорожке." << endl;
        }
        else
        {
            people_amount = _settable_people_amount;
        }
    }
    void set_max_people_amount(int _settable_max_people_amount)
    {
        if (_settable_max_people_amount < 1)
        {
            cout << "Невозможно присвоить данное значение максимального количества людей на дорожке." << endl;
        }
        else
        {
            max_people_amount = _settable_max_people_amount;
        }
    }
    void output_track()
    {
        cout << "Дорожка №" << track_number << endl;
        cout << "Количество людей на дорожке: " << people_amount << endl;
        cout << "Максимальное количество людей на дорожке: " << max_people_amount << endl;
    }
    void let_human(int age)
    {
        if (age <= 0)
        {
            cout << "Поместить человека на дорожку нельзя." << endl;
        }
        else if ((age >= 6 && age <= 80) && (get_people_amount() < get_max_people_amount()) /* && номер дорожки первый или последний*/)
        {
            set_people_amount(get_people_amount() + 1);
            cout << "Человек возраста " << age << " помещён на дорожку №" << get_track_number() << endl;
        }
        else if ((get_people_amount() < get_max_people_amount()) /* && номер дорожки первый или последний*/)
        {
            set_people_amount(get_people_amount() + 1);
            cout << "Человек возраста " << age << " помещён на дорожку " << get_track_number() << endl;
        }
    }
};

class swimming_pool
{
private:
    int swimming_pool_number;
    int tracks_amount;
    double max_depth;
    double lenght;
    track** tracks;
public:
    swimming_pool()
    {
        swimming_pool_number = 0;
        tracks_amount = 5;
        max_depth = 5;
        lenght = 25;
        tracks = new track* [tracks_amount];
    }
    swimming_pool(int _swimming_pool_number, int _tracks_amount, double _max_depth, double _lenght)
    {
        if (_swimming_pool_number >= 0)
        {
            swimming_pool_number = _swimming_pool_number;
        }
        else
        {
            swimming_pool_number = 0;
        }
        if (_tracks_amount >= 1)
        {
            tracks_amount = _tracks_amount;
        }
        else
        {
            tracks_amount = 5;
        }
        if (_max_depth > 0)
        {
            max_depth = _max_depth;
        }
        else
        {
            max_depth = 5;
        }
        if (_lenght > 0)
        {
            lenght = _lenght;
        }
        else
        {
            lenght = 25;
        }
        tracks = new track* [tracks_amount];
    }
    swimming_pool(swimming_pool &object)
    {
        swimming_pool_number = object.swimming_pool_number;
        tracks_amount = object.tracks_amount;
        max_depth = object.max_depth;
        lenght = object.lenght;
        tracks = new track* [tracks_amount];
        if (tracks_amount > 0)
        {
            for (int i = 0; i < tracks_amount; i++)
            {
                tracks[i] = new track(object.tracks[i]->get_track_number(), object.tracks[i]->get_people_amount(), object.tracks[i]->get_max_people_amount());
            }
        }
    }
    ~swimming_pool()
    {
        if (tracks_amount > 0)
        {
            for (int i = 0; i < tracks_amount; i++)
            {
                delete tracks[i];
            }
        }
        delete[]tracks;
    }
    int get_swimming_pool_number() { return swimming_pool_number; }
    int get_tracks_amount() { return tracks_amount; }
    double get_max_depht() { return max_depth; }
    double get_lenght() { return lenght; }
    void set_swimming_pool_number(int _settable_swimming_pool_number)
    {
        if (_settable_swimming_pool_number >= 0)
        {
            swimming_pool_number = _settable_swimming_pool_number;
        }
        else
        {
            swimming_pool_number = 0;
        }
    }
    void set_tracks_amount(int _settable_tracks_amount)
    {
        if (_settable_tracks_amount >= 1)
        {
            tracks_amount = _settable_tracks_amount;
        }
        else
        {
            tracks_amount = 5;
        }
    }
    void set_max_depth(int _settable_max_depth)
    {
        if (_settable_max_depth > 0)
        {
            max_depth = _settable_max_depth;
        }
        else
        {
            max_depth = 5;
        }
    }
    void set_lenght(int _settable_lenght)
    {
        if (_settable_lenght > 0)
        {
            lenght = _settable_lenght;
        }
        else
        {
            lenght = 25;
        }
    }
    void output_swimming_pool()
    {
        cout << "Бассейн №" << swimming_pool_number << endl;
        cout << "Количество дорожек: " << tracks_amount << endl;
        cout << "Максимальная глубина: " << max_depth << endl;
        cout << "Длина: " << lenght << endl;
        if (tracks_amount > 0)
        {
            for (int i = 0; i < tracks_amount; i++)
            {
                tracks[i]->output_track();
            }
        }
    }
};

class sport_complex
{
private:
    string name_sport_complex;
    int swimmings_amount;
    swimming_pool** swimming_pools;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);



    return 0;
}