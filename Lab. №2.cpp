// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

class track
{
private:
    int track_number;
    int max_people_amount;
    int people_amount;
    int* peoples_ages;
public:
    track()
    {
        track_number = 0;
        max_people_amount = 10;
        people_amount = 0;
        peoples_ages = new int [max_people_amount];
    }
    track(int _track_number, int _max_people_amount, int _people_amount)
    {
        if (_track_number >= 0)
        {
            track_number = _track_number;
        }
        else
        {
            track_number = 0;
        }
        if (_max_people_amount >= 1)
        {
            max_people_amount = _max_people_amount;
        }
        else
        {
            max_people_amount = 10;
        }
        if (_people_amount >= 0 && _people_amount <= max_people_amount)
        {
            people_amount = _people_amount;
        }
        else
        {
            people_amount = 0;
        }
    }
    track(track& object)
    {
        track_number = object.track_number;
        people_amount = object.people_amount;
        max_people_amount = object.max_people_amount;
        peoples_ages = object.peoples_ages;
    }
    ~track()
    {
        delete[]peoples_ages;
    }
    int get_track_number() { return track_number; }
    int get_max_people_amount() { return max_people_amount; }
    int get_people_amount() { return people_amount; }
    int get_peoples_ages() { return *peoples_ages; }
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
    void set_people_amount(int _settable_people_amount)
    {
        if (_settable_people_amount >= 0 && _settable_people_amount <= max_people_amount)
        {
            people_amount = _settable_people_amount;
        }
        else
        {
            people_amount = 0;
            cout << "Невозможно присвоить данное значение количества людей на дорожке. Присвоено значение по умолчанию: " << people_amount << endl;
        }
    }
    void output_track()
    {
        cout << "Дорожка №" << track_number << endl;
        cout << "Количество людей на дорожке: " << people_amount << endl;
        cout << "Максимальное количество людей на дорожке: " << max_people_amount << endl;
    }
    void output_peoples_ages()
    {
        for (int i = 0; i < get_people_amount(); i++)
        {
            cout << i + 1 << ". " << peoples_ages[i] << endl;
        }
    }
    bool add_human_age(int _human_age)
    {
        bool method_result = false;
        if (people_amount < max_people_amount)
        {
            peoples_ages[get_people_amount()] = _human_age;
            set_people_amount(get_people_amount() + 1);
            method_result = true;
        }
        return (method_result);
    }
    bool remove_human_age(int _index_human_age)
    {
        bool method_result = false;
        if ((_index_human_age - 1) >= 0 && _index_human_age < get_people_amount())
        {
            for (int i = _index_human_age; i < get_people_amount() - 1; i++)
            {
                peoples_ages[i] = peoples_ages[i + 1];
            }
            set_people_amount(get_people_amount() - 1);
            method_result = true;
        }
        return (method_result);
    }
    bool remove_all_humans_age()
    {
        bool method_result = false;
        if (get_people_amount() > 0)
        {
            for (int i = 0; i < get_people_amount(); i++)
            {
                peoples_ages[i] = 0;
            }
            set_people_amount(0);
            method_result = true;
        }
        return (method_result);
    }
};

class swimming_pool
{
private:
    int swimming_pool_number;
    int max_tracks_amount;
    int tracks_amount;
    double max_depth;
    double lenght;
    track** tracks;
public:
    swimming_pool()
    {
        swimming_pool_number = 0;
        max_tracks_amount = 5;
        tracks_amount = 5;
        max_depth = 5;
        lenght = 25;
        tracks = new track* [tracks_amount];
        for (int i = 0; i < max_tracks_amount; i++)
        {
            tracks[i] = new track(i + 1, 10, 0);
        }
    }
    swimming_pool(int _swimming_pool_number, int _max_tracks_amount, int _tracks_amount, double _max_depth, double _lenght)
    {
        if (_swimming_pool_number >= 0)
        {
            swimming_pool_number = _swimming_pool_number;
        }
        else
        {
            swimming_pool_number = 0;
        }
        if (_max_tracks_amount >= 1)
        {
            max_tracks_amount = _max_tracks_amount;
        }
        else
        {
            max_tracks_amount = 5;
        }
        if (_tracks_amount >= 1 && _tracks_amount <= max_tracks_amount)
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
        for (int i = 0; i < max_tracks_amount; i++)
        {
            tracks[i] = new track(i + 1, 10, 0);
        }
    }
    swimming_pool(swimming_pool &object)
    {
        swimming_pool_number = object.swimming_pool_number;
        max_tracks_amount = object.max_tracks_amount;
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
    int get_max_tracks_amount() { return max_tracks_amount; }
    int get_tracks_amount() { return tracks_amount; }
    double get_max_depth() { return max_depth; }
    double get_lenght() { return lenght; }
    int get_track_people_amount(int _number_track)
    {
        return (tracks[_number_track]->get_people_amount());
    }
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
    void set_max_tracks_amount(int _settable_max_tracks_amount)
    {
        if (_settable_max_tracks_amount >= 1)
        {
            max_tracks_amount = _settable_max_tracks_amount;
        }
        else
        {
            max_tracks_amount = 5;
        }
    }
    void set_tracks_amount(int _settable_tracks_amount)
    {
        if (_settable_tracks_amount >= 1 && _settable_tracks_amount <= get_max_tracks_amount())
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
    void set_track_number(int _track_number, int _settable_track_number)
    {
        if (_settable_track_number <= 0)
        {
            cout << "Невозможно присвоить данное значение номера дорожки." << endl;
        }
        else
        {
            tracks[_track_number]->set_track_number(_settable_track_number);
        }
    }
    void set_max_people_amount(int _track_number, int _settable_max_people_amount)
    {
        if (_settable_max_people_amount < 1)
        {
            cout << "Невозможно присвоить данное значение максимального количества людей на дорожке." << endl;
        }
        else
        {
            tracks[_track_number]->set_max_people_amount(_settable_max_people_amount);
        }
    }
    void set_people_amount(int _track_number, int _settable_people_amount)
    {
        if (_settable_people_amount >= 0 && _settable_people_amount <= tracks[_track_number]->get_max_people_amount())
        {
            tracks[_track_number]->set_people_amount(_settable_people_amount);
        }
        else
        {
            tracks[_track_number]->set_people_amount(_settable_people_amount);
            cout << "Невозможно присвоить данное значение количества людей на дорожке. Присвоено значение по умолчанию: " << tracks[_track_number]->get_people_amount() << endl;
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
    void output_track(int _track_number)
    {
        for (int i = 0; i < tracks[i]->get_track_number(); i++)
        {
            if (tracks[i]->get_people_amount() == _track_number)
            {
                cout << "Дорожка №" << tracks[i]->get_track_number() << endl;
                cout << "Количество людей на дорожке: " << tracks[i]->get_people_amount() << endl;
                cout << "Максимальное количество людей на дорожке: " << tracks[i]->get_max_people_amount() << endl;
            }
        }
    }
    void output_track_peoples_ages(int _track_number)
    {
        for (int i = 0; i < tracks[i]->get_track_number(); i++)
        {
            if (tracks[i]->get_people_amount() == _track_number)
            {
                cout << "Дорожка №" << tracks[i]->get_track_number() << endl;
                cout << "Количество людей на дорожке: " << tracks[i]->get_people_amount() << endl;
                cout << "Максимальное количество людей на дорожке: " << tracks[i]->get_max_people_amount() << endl;
                tracks[i]->output_peoples_ages();
            }
        }
    }
    bool let_human_on_track(int _track_number, int _human_age)
    {
        bool method_result = false;
        int current_index_track = 0, number_last_track = tracks[get_tracks_amount()]->get_track_number();
        for (int i = 0; i < get_tracks_amount(); i++)
        {
            if (tracks[i]->get_track_number() == _track_number)
            {
                current_index_track = i;
                break;
            }
        }
        if ((_human_age <= 6 || _human_age >= 80) && (tracks[current_index_track]->get_people_amount() < tracks[current_index_track]->get_max_people_amount()) && (_track_number == number_last_track || _track_number == 1))
        {
            tracks[current_index_track]->set_people_amount(tracks[current_index_track]->get_people_amount() + 1);
            tracks[current_index_track]->add_human_age(_human_age);
            method_result = true;
        }
        else if ((_human_age > 6 && _human_age < 80) && tracks[current_index_track]->get_people_amount() < tracks[current_index_track]->get_max_people_amount())
        {
            tracks[current_index_track]->set_people_amount(tracks[current_index_track]->get_people_amount() + 1);
            tracks[current_index_track]->add_human_age(_human_age);
            method_result = true;
        }
        return (method_result);
    }
    bool remove_human_from_track(int _track_number, int _index_human)
    {
        bool method_result = false;
        for (int i = 0; i < get_tracks_amount(); i++)
        {
            if (tracks[i]->get_track_number() == _track_number)
            {
                if (tracks[i]->remove_human_age(_index_human))
                {
                    method_result = true;
                }
                break;
            }
        }
        return (method_result);
    }
    bool remove_all_humans_from_track(int _track_number)
    {
        bool method_result = false;
        for (int i = 0; i < get_tracks_amount(); i++)
        {
            if (tracks[i]->get_track_number() == _track_number)
            {
                for (int j = 0; j < tracks[i]->get_people_amount(); j++)
                {
                    tracks[i]->remove_human_age(j);
                }
                method_result = true;
                break;
            }
        }
        return (method_result);
    }
    bool remove_all_humans_from_swimming_pool()
    {
        bool method_result = false;
        if (get_tracks_amount() > 0)
        {
            for (int i = 0; i < get_tracks_amount(); i++)
            {
                tracks[i]->remove_all_humans_age();
            }
            method_result = true;
        }
        return (method_result);
    }
    bool add_track()
    {
        bool method_result = false;
        if (get_tracks_amount() < get_max_tracks_amount())
        {
            tracks[get_tracks_amount() + 1] = new track();
            set_tracks_amount(get_tracks_amount() + 1);
            method_result = true;
        }
        return (method_result);
    }
    bool remove_track(int _track_number)
    {
        bool method_result = false;
        if (get_tracks_amount() > 1)
        {
            for (int i = 0; i < get_tracks_amount(); i++)
            {
                if (tracks[i]->get_track_number() == _track_number)
                {
                    for (int j = i; j < get_tracks_amount() - 1; j++)
                    {
                        tracks[j] = tracks[j + 1];
                    }
                    set_tracks_amount(get_tracks_amount() - 1);
                    method_result = true;
                }
            }
        }
        return (method_result);
    }
    void copy_constuct_track(int _number_track)
    {
        for (int i = 0; i < get_tracks_amount(); i++)
        {
            if (tracks[i]->get_track_number() == _number_track)
            {
                tracks[get_tracks_amount() + 1] = new track(tracks[_number_track]->get_track_number(), tracks[_number_track]->get_people_amount(), tracks[_number_track]->get_max_people_amount());
                // !
                set_tracks_amount(get_tracks_amount() + 1);
                break;
            }
        }
    }
};

class sport_complex
{
private:
    string name_sport_complex;
    int max_swimming_pools_amount;
    int swimming_pools_amount;
    swimming_pool** swimming_pools;
public:
    sport_complex()
    {
        name_sport_complex = "не определено";
        max_swimming_pools_amount = 5;
        swimming_pools_amount = 5;
        swimming_pools = new swimming_pool* [swimming_pools_amount];
        for (int i = 0; i < max_swimming_pools_amount; i++)
        {
            swimming_pools[i] = new swimming_pool(i + 1, 5, 5, 5, 25);
        }
    }
    sport_complex(string _name_sport_complex, int _max_swimming_pools_amount, int _swimming_pools_amount)
    {
        name_sport_complex = _name_sport_complex;
        if (_max_swimming_pools_amount >= 1)
        {
            max_swimming_pools_amount = _max_swimming_pools_amount;
        }
        else
        {
            max_swimming_pools_amount = 5;
        }
        if (_swimming_pools_amount >= 1 && _swimming_pools_amount <= _max_swimming_pools_amount)
        {
            swimming_pools_amount = _swimming_pools_amount;
        }
        else
        {
            swimming_pools_amount = 1;
        }
        swimming_pools = new swimming_pool* [swimming_pools_amount];
        for (int i = 0; i < max_swimming_pools_amount; i++)
        {
            swimming_pools[i] = new swimming_pool(i + 1, 5, 5, 5, 25);
        }
    }
    sport_complex(sport_complex &object)
    {
        name_sport_complex = object.name_sport_complex;
        max_swimming_pools_amount = object.swimming_pools_amount;
        swimming_pools_amount = object.swimming_pools_amount;
        swimming_pools = new swimming_pool* [swimming_pools_amount];
        for (int i = 0; i < swimming_pools_amount; i++)
        {
            swimming_pools[i] = new swimming_pool(object.swimming_pools[i]->get_swimming_pool_number(), object.swimming_pools[i]->get_max_tracks_amount(), object.swimming_pools[i]->get_tracks_amount(), object.swimming_pools[i]->get_max_depth(), object.swimming_pools[i]->get_lenght()); // ? tracks array
        }
    }
    ~sport_complex()
    {
        for (int i = 0; i < swimming_pools_amount; i++)
        {
            delete swimming_pools[i];
        }
        delete[]swimming_pools;
    }
    string get_name_sport_complex() { return name_sport_complex; }
    int get_max_swimming_pools_amount() { return max_swimming_pools_amount; }
    int get_swimming_pools_amount() { return swimming_pools_amount; }
    int get_track_people_amount(int _swimming_pool_number, int _number_track)
    {
        return (swimming_pools[_swimming_pool_number]->get_track_people_amount(_number_track));
    }
    void set_name_sport_complex(string _settable_name_sport_complex)
    {
        name_sport_complex = _settable_name_sport_complex;
    }
    void set_max_swimming_pools_amount(int _settable_max_swimming_pools_amount)
    {
        if (_settable_max_swimming_pools_amount >= 1)
        {
            max_swimming_pools_amount = _settable_max_swimming_pools_amount;
        }
        else
        {
            max_swimming_pools_amount = 1;
        }
    }
    void set_swimming_pools_amount(int _settable_swimming_pools_amount)
    {
        if (_settable_swimming_pools_amount >= 1 && _settable_swimming_pools_amount <= get_max_swimming_pools_amount())
        {
            swimming_pools_amount = _settable_swimming_pools_amount;
        }
        else
        {
            swimming_pools_amount = 1;
        }
    }
    void set_swimming_pool_number(int _swimming_pool_number, int _settable_swimming_pool_number)
    {
        if (_settable_swimming_pool_number >= 0)
        {
            swimming_pools[_swimming_pool_number]->set_swimming_pool_number(_settable_swimming_pool_number);
        }
        else
        {
            swimming_pools[_swimming_pool_number]->set_swimming_pool_number(0);
        }
    }
    void set_max_tracks_amount(int _swimming_pool_number, int _settable_max_tracks_amount)
    {
        if (_settable_max_tracks_amount >= 1)
        {
            swimming_pools[_swimming_pool_number]->set_max_tracks_amount(_settable_max_tracks_amount);
        }
        else
        {
            swimming_pools[_swimming_pool_number]->set_max_tracks_amount(5);
        }
    }
    void set_tracks_amount(int _swimming_pool_number, int _settable_tracks_amount)
    {
        if (_settable_tracks_amount >= 1 && _settable_tracks_amount <= swimming_pools[_swimming_pool_number]->get_max_tracks_amount())
        {
            swimming_pools[_swimming_pool_number]->set_tracks_amount(_settable_tracks_amount);
        }
        else
        {
            swimming_pools[_swimming_pool_number]->set_tracks_amount(5);
        }
    }
    void set_max_depth(int _swimming_pool_number, int _settable_max_depth)
    {
        if (_settable_max_depth > 0)
        {
            swimming_pools[_swimming_pool_number]->set_max_depth(_settable_max_depth);
        }
        else
        {
            swimming_pools[_swimming_pool_number]->set_max_depth(5);
        }
    }
    void set_lenght(int _swimming_pool_number, int _settable_lenght)
    {
        if (_settable_lenght > 0)
        {
            swimming_pools[_swimming_pool_number]->set_lenght(_settable_lenght);
        }
        else
        {
            swimming_pools[_swimming_pool_number]->set_lenght(25);
        }
    }
    void copy_construct_swimming_pool(int _swimming_pool_number)
    {
        if (get_swimming_pools_amount() < get_max_swimming_pools_amount())
        {
            for (int i = 0; i < get_swimming_pools_amount(); i++)
            {
                if (swimming_pools[i]->get_swimming_pool_number() == _swimming_pool_number)
                {
                    swimming_pools[get_swimming_pools_amount() + 1] = new swimming_pool(swimming_pools[_swimming_pool_number]->get_swimming_pool_number(), swimming_pools[_swimming_pool_number]->get_max_tracks_amount(), swimming_pools[_swimming_pool_number]->get_tracks_amount(), swimming_pools[_swimming_pool_number]->get_max_depth(), swimming_pools[_swimming_pool_number]->get_lenght());
                    // !
                    set_swimming_pools_amount(get_swimming_pools_amount() + 1);
                    break;
                }
            }
        }
    }
    void output_sport_complex()
    {
        cout << "Спортивный комплекс \"" << name_sport_complex << "\"" << endl;
        cout << "Количество бассейнов: " << swimming_pools_amount << endl;
        for (int i = 0; i < swimming_pools_amount; i++)
        {
            swimming_pools[i]->output_swimming_pool();
        }
    }
    void output_swimming_pool(int _number_swimming_pool)
    {
        for (int i = 0; i < get_swimming_pools_amount(); i++)
        {
            if (swimming_pools[i]->get_swimming_pool_number() == _number_swimming_pool)
            {
                cout << "Бассейн №" << swimming_pools[i]->get_swimming_pool_number() << endl;
                cout << "Количество дорожек: " << swimming_pools[i]->get_tracks_amount() << endl;
                cout << "Максимальная глубина: " << swimming_pools[i]->get_max_depth() << endl;
                cout << "Длина: " << swimming_pools[i]->get_lenght() << endl;
                if (swimming_pools[i]->get_tracks_amount() > 0)
                {
                    for (int j = 0; j < swimming_pools[i]->get_tracks_amount(); j++)
                    {
                        swimming_pools[i]->output_track(j);
                    }
                }
                break;
            }
        }
    }
    void set_track_number(int _number_swimming_pool, int _track_number, int _settable_track_number)
    {
        swimming_pools[_track_number]->set_track_number(_track_number, _settable_track_number);
    }
    void set_max_people_amount(int _number_swimming_pool, int _track_number, int _settable_max_people_amount)
    {
        swimming_pools[_track_number]->set_max_people_amount(_track_number, _settable_max_people_amount);
    }
    void set_people_amount(int _number_swimming_pool, int _track_number, int _settable_people_amount)
    {
        swimming_pools[_track_number]->set_people_amount(_track_number, _settable_people_amount);
    }
    void output_track(int _number_swimming_pool, int _number_track)
    {
        for (int i = 0; i < get_swimming_pools_amount(); i++)
        {
            if (swimming_pools[i]->get_swimming_pool_number() == _number_swimming_pool)
            {
                swimming_pools[i]->output_track(_number_track);
                break;
            }
        }
    }
    void output_track_peoples_ages(int _number_swimming_pool, int _number_track)
    {
        for (int i = 0; i < swimming_pools[i]->get_tracks_amount(); i++)
        {
            if (swimming_pools[i]->get_swimming_pool_number() == _number_swimming_pool)
            {
                swimming_pools[i]->output_track_peoples_ages(_number_track);
            }
        }
    }
    bool let_human_on_track(int _number_swimming_pool, int _number_track, int _human_age)
    {
        bool method_result = false;
        for (int i = 0; i < get_swimming_pools_amount(); i++)
        {
            if (swimming_pools[i]->get_swimming_pool_number() == _number_swimming_pool)
            {
                if (swimming_pools[i]->let_human_on_track(_number_track, _human_age))
                {
                    method_result = true;
                }
                break;
            }
        }
        return (method_result);
    }
    bool remove_human_from_track(int _number_swimming_pool, int _number_track, int _index_human)
    {
        bool method_result = false;
        for (int i = 0; i < get_swimming_pools_amount(); i++)
        {
            if (swimming_pools[i]->get_swimming_pool_number() == _number_swimming_pool)
            {
                if (swimming_pools[i]->remove_human_from_track(_number_track, _index_human))
                {
                    method_result = true;
                }
                break;
            }
        }
        return (method_result);
    }
    bool remove_all_humans_from_track(int _number_swimming_pool, int _number_track)
    {
        bool method_result = false;
        for (int i = 0; i < get_swimming_pools_amount(); i++)
        {
            if (swimming_pools[i]->get_swimming_pool_number() == _number_swimming_pool)
            {
                for (int j = 0; j < swimming_pools[i]->get_tracks_amount(); j++)
                {
                    if (swimming_pools[i]->remove_all_humans_from_track(_number_track))
                    {
                        method_result = true;
                    }
                }
                break;
            }
        }
        return (method_result);
    }
    bool remove_all_humans_from_swimming_pool(int _number_swimming_pool)
    {
        bool method_result = false;
        for (int i = 0; i < get_swimming_pools_amount(); i++)
        {
            if (swimming_pools[i]->get_swimming_pool_number() == _number_swimming_pool)
            {
                if (swimming_pools[i]->remove_all_humans_from_swimming_pool())
                {
                    method_result = true;
                }
                break;
            }
        }
        return (method_result);
    }
    bool remove_all_humans_from_sport_complex()
    {
        bool method_result = false;
        if (get_swimming_pools_amount() > 0)
        {
            for (int i = 0; i < get_swimming_pools_amount(); i++)
            {
                if (swimming_pools[i]->remove_all_humans_from_swimming_pool())
                {
                    method_result = true;
                }
            }
        }
        return (method_result);
    }
    bool add_swimming_pool()
    {
        bool method_result = false;
        if (get_swimming_pools_amount() < get_max_swimming_pools_amount())
        {
            swimming_pools[get_swimming_pools_amount() + 1] = new swimming_pool();
            set_swimming_pools_amount(get_swimming_pools_amount() + 1);
            method_result = true;
        }
        return (method_result);
    }
    bool remove_swimming_pool(int _swimming_pool_number)
    {
        bool method_result = false;
        if (get_swimming_pools_amount() > 1)
        {
            for (int i = 0; i < get_swimming_pools_amount(); i++)
            {
                if (swimming_pools[i]->get_swimming_pool_number() == _swimming_pool_number)
                {
                    for (int j = i; j < get_swimming_pools_amount() - 1; j++)
                    {
                        swimming_pools[j] = swimming_pools[j + 1];
                    }
                    set_swimming_pools_amount(get_swimming_pools_amount() - 1);
                    method_result = true;
                }
            }
        }
        return (method_result);
    }
    bool add_track(int _swimming_pool_number)
    {
        bool method_result = false;
        for (int i = 0; i < get_swimming_pools_amount(); i++)
        {
            if (swimming_pools[i]->get_swimming_pool_number() == _swimming_pool_number)
            {
                if (swimming_pools[i]->add_track())
                {
                    method_result = true;
                }
            }
        }
        return (method_result);
    }
    bool remove_track(int _swimming_pool_number, int _track_number)
    {
        bool method_result = false;
        if (get_swimming_pools_amount() > 1)
        {
            for (int i = 0; i < get_swimming_pools_amount(); i++)
            {
                if (swimming_pools[i]->get_swimming_pool_number() == _swimming_pool_number)
                {
                    swimming_pools[i]->remove_track(_track_number);
                    swimming_pools[i]->set_tracks_amount(swimming_pools[i]->get_tracks_amount() - 1);
                    method_result = true;
                }
            }
        }
        return (method_result);
    }
    void copy_construct_track(int _swimming_pool_number, int _number_track)
    {
        for (int i = 0; i < get_swimming_pools_amount(); i++)
        {
            if (swimming_pools[i]->get_swimming_pool_number() == _swimming_pool_number)
            {
                swimming_pools[i]->copy_constuct_track(_number_track);
                break;
            }
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    sport_complex a("Донбасс", 5, 5);
    a.output_sport_complex();
    int cmd = 0, s_cmd = 0;
    do
    {
        cout << "Выберите действие:" << endl;
        cout << "1. Вывести на экран" << endl;
        cout << ">>> 1. Спортивный комплекс" << endl;
        cout << ">>> 2. Бассейн" << endl;
        cout << ">>> 3. Дорожку" << endl;
        cout << "2. Изменить" << endl;
        cout << ">>> 1. Спортивный комплекс" << endl;
        cout << ">>> 2. Бассейн" << endl;
        cout << ">>> 3. Дорожку" << endl;
        cout << "3. Создать" << endl;
        cout << ">>> 1. Бассейн" << endl;
        cout << ">>> 2. Дорожку" << endl;
        cout << "4. Удалить" << endl;
        cout << ">>> 1. Бассейн" << endl;
        cout << ">>> 2. Дорожку" << endl;
        cout << "5. Поместить человека на дорожку" << endl;
        cout << "6. Убрать человека с дорожки" << endl;
        cout << "7. Убрать всех людей" << endl;
        cout << ">>> 1. С дорожки" << endl;
        cout << ">>> 2. С бассейна" << endl;
        cout << ">>> 3. С спортивного комплекса" << endl;
        cout << "0. Завершить работу программы" << endl;
        cout << "Номер действия: " << endl;
        cin >> cmd;
        while (cmd < 0 || cmd > 7)
        {
            cout << "[Ошибка]: введён неверный номер действия. Введите номер действия: " << endl;
            cin >> cmd;
        }
        switch (cmd)
        {
            case 0:
            {
                break;
            }
            case 1:
            {
                cout << "Выбирите действие: вывести на экран:" << endl;
                cout << "1. Спортивный комплекс" << endl;
                cout << "2. Бассейн" << endl;
                cout << "3. Дорожку" << endl;
                cout << "0. Назад" << endl;
                cout << "Номер действия: " << endl;
                cin >> s_cmd;
                while (s_cmd < 0 || cmd > 3)
                {
                    cout << "[Ошибка]: введён неверный номер действия. Введите номер действия: " << endl;
                    cin >> s_cmd;
                }
                switch (s_cmd)
                {
                    case 0:
                    {
                        break;
                    }
                    case 1:
                    {
                        a.output_sport_complex();
                        break;
                    }
                    case 2:
                    {
                        int number_swimming_pool = 0;
                        cout << "Введите номер бассейна: " << endl;
                        cin >> number_swimming_pool;
                        a.output_swimming_pool(number_swimming_pool);
                        break;
                    }
                    case 3:
                    {
                        int number_swimming_pool = 0, number_track = 0;
                        cout << "Введите номер бассейна: " << endl;
                        cin >> number_swimming_pool;
                        cout << "Введите номер дорожки: " << endl;
                        cin >> number_track;
                        a.output_track(number_swimming_pool, number_track);
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                cout << "Выбирите действие: изменить:" << endl;
                cout << "1. Спортивный комплекс" << endl;
                cout << "2. Бассейн" << endl;
                cout << "3. Дорожку" << endl;
                cout << "0. Назад" << endl;
                cout << "Номер действия: " << endl;
                cin >> s_cmd;
                while (s_cmd < 0 || cmd > 3)
                {
                    cout << "[Ошибка]: введён неверный номер действия. Введите номер действия: " << endl;
                    cin >> s_cmd;
                }
                switch (s_cmd)
                {
                    case 0:
                    {
                        break;
                    }
                    case 1:
                    {
                        cout << "1. Изменить название спортивного комплекса" << endl;
                        cout << "2. Изменить максимальное количество бассейнов" << endl;
                        cout << "3. Изменить количество бассейнов" << endl;
                        cout << "0. Назад" << endl;
                        cout << "Номер действия: " << endl;
                        cin >> s_cmd;
                        while (s_cmd < 0 || cmd > 3)
                        {
                            cout << "[Ошибка]: введён неверный номер действия. Введите номер действия: " << endl;
                            cin >> s_cmd;
                        }
                        switch (s_cmd)
                        {
                            case 0:
                            {
                                break;
                            }
                            case 1:
                            {
                                string name_sport_complex = "";
                                cout << "Введите новое название спортивного комплекса" << endl;
                                cin >> name_sport_complex;
                                a.set_name_sport_complex(name_sport_complex);
                                break;
                            }
                            case 2:
                            {
                                int max_swimming_pools_amount = 0;
                                cout << "Введите новое максимальное количество бассейнов спортивного комплекса" << endl;
                                cin >> max_swimming_pools_amount;
                                a.set_max_swimming_pools_amount(max_swimming_pools_amount);
                                break;
                            }
                            case 3:
                            {
                                int swimming_pools_amount = 0;
                                cout << "Введите новое количество бассейнов спортивного комплекса" << endl;
                                cin >> swimming_pools_amount;
                                a.set_swimming_pools_amount(swimming_pools_amount);
                                break;
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "1. Изменить номер бассейна" << endl;
                        cout << "2. Изменить максимальное количество дорожек" << endl;
                        cout << "3. Изменить количество дорожек" << endl;
                        cout << "4. Изменить максимальную глубину" << endl;
                        cout << "5. Изменить длину" << endl;
                        cout << "0. Назад" << endl;
                        cout << "Номер действия: " << endl;
                        cin >> s_cmd;
                        while (s_cmd < 0 || cmd > 5)
                        {
                            cout << "[Ошибка]: введён неверный номер действия. Введите номер действия: " << endl;
                            cin >> s_cmd;
                        }
                        switch (s_cmd)
                        {
                            case 0:
                            {
                                break;
                            }
                            case 1:
                            {
                                int swimming_pool_number = 0, new_swimming_pool_number = 0;
                                cout << "Введите номер бассейна, для которого Вы хотите сменить номер: ";
                                cin >> swimming_pool_number;
                                cout << "Введите новый номер бассейна: ";
                                cin >> new_swimming_pool_number;
                                // !
                                break;
                            }
                            case 2:
                            {
                                int swimming_pool_number = 0, max_tracks_amount = 0;
                                cout << "Введите номер бассейна, для которого Вы хотите сменить максимальное количество дорожек: ";
                                cin >> swimming_pool_number;
                                cout << "Введите новое максимальное количество дорожек: ";
                                cin >> max_tracks_amount;
                                // !
                                break;
                            }
                            case 3:
                            {
                                int swimming_pool_number = 0, tracks_amount = 0;
                                cout << "Введите номер бассейна, для которого Вы хотите сменить количество дорожек: ";
                                cin >> swimming_pool_number;
                                cout << "Введите новое количество дорожек: ";
                                cin >> tracks_amount;
                                // !
                                break;
                            }
                            case 4:
                            {
                                int swimming_pool_number = 0, max_depth= 0;
                                cout << "Введите номер бассейна, для которого Вы хотите сменить максимальную глубину: ";
                                cin >> swimming_pool_number;
                                cout << "Введите новую максимальную глубину: ";
                                cin >> max_depth;
                                // !
                                break;
                            }
                            case 5:
                            {
                                int swimming_pool_number = 0, lenght = 0;
                                cout << "Введите номер бассейна, для которого Вы хотите сменить длину: ";
                                cin >> swimming_pool_number;
                                cout << "Введите новую длину: ";
                                cin >> lenght;
                                // !
                                break;
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        // !
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                cout << "Выбирите действие: создать:" << endl;
                cout << "1. Бассейн" << endl;
                cout << "2. Дорожку" << endl;
                cout << "0. Назад" << endl;
                cout << "Номер действия: " << endl;
                cin >> s_cmd;
                while (s_cmd < 0 || cmd > 2)
                {
                    cout << "[Ошибка]: введён неверный номер действия. Введите номер действия: " << endl;
                    cin >> s_cmd;
                }
                switch (s_cmd)
                {
                    case 0:
                    {
                        break;
                    }
                    case 1:
                    {
                        cout << "Выберите действие: создать: бассейн:" << endl;
                        cout << "1. Конструктор по умолчанию" << endl;
                        cout << "2. Конструктор с параметрами" << endl;
                        cout << "3. Конструктор копии" << endl;
                        cout << "0. Назад" << endl;
                        cin >> s_cmd;
                        while (s_cmd < 0 || cmd > 3)
                        {
                            cout << "[Ошибка]: введён неверный номер действия. Введите номер действия: " << endl;
                            cin >> s_cmd;
                        }
                        switch (s_cmd)
                        {
                            case 0:
                            {
                                break;
                            }
                            case 1:
                            {
                                if (a.add_swimming_pool())
                                {
                                    cout << "Бассейн успешно добавлен конструктором по умолчанию в спортивный комплекс \"" << a.get_name_sport_complex() << "\"" << endl;
                                }
                                else
                                {
                                    cout << "Не удалось добавить бассейн конструктором по умолчанию в спортивный комплекс \"" << a.get_name_sport_complex() << "\"" << endl;
                                }
                                break;
                            }
                            case 2:
                            {
                                if (a.add_swimming_pool())
                                {
                                    int swimming_pool_number = 0, max_tracks_amount = 0, tracks_amount = 0;
                                    double max_depth = 0, lenght = 0;
                                    cout << "Введите номер бассейна: ";
                                    cin >> swimming_pool_number;
                                    a.set_swimming_pool_number(0, swimming_pool_number);
                                    cout << "Введите максимальное количество дорожек: ";
                                    cin >> max_tracks_amount;
                                    a.set_max_tracks_amount(swimming_pool_number, max_tracks_amount);
                                    cout << "Введите максимальную глубину: ";
                                    cin >> max_depth;
                                    a.set_max_depth(swimming_pool_number, max_depth);
                                    cout << "Введите длину: ";
                                    cin >> lenght;
                                    a.set_lenght(swimming_pool_number, lenght);
                                    cout << "Бассейн успешно добавлен конструктором с параметрами в спортивный комплекс \"" << a.get_name_sport_complex() << "\"" << endl;
                                    a.output_swimming_pool(swimming_pool_number);
                                }
                                else
                                {
                                    cout << "Не удалось добавить бассейн конструктором с параметрами в спортивный комплекс \"" << a.get_name_sport_complex() << "\"" << endl;
                                }
                                break;
                            }
                            case 3:
                            {
                                if (a.add_swimming_pool())
                                {
                                    int number_swimming_pool;
                                    cout << "Введите номер бассейна с которого будет сделана копия: ";
                                    cin >> number_swimming_pool;
                                    a.copy_construct_swimming_pool(number_swimming_pool);
                                    cout << "Бассейн успешно добавлен конструктором копии в спортивный комплекс \"" << a.get_name_sport_complex() << "\"" << endl;
                                    a.output_swimming_pool(number_swimming_pool);
                                }
                                else
                                {
                                    cout << "Не удалось добавить бассейн конструктором копии в спортивный комплекс \"" << a.get_name_sport_complex() << "\"" << endl;
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "Выберите действие: создать: дорожка:" << endl;
                        cout << "1. Конструктор по умолчанию" << endl;
                        cout << "2. Конструктор с параметрами" << endl;
                        cout << "3. Конструктор копии" << endl;
                        cout << "0. Назад" << endl;
                        cin >> s_cmd;
                        while (s_cmd < 0 || cmd > 3)
                        {
                            cout << "[Ошибка]: введён неверный номер действия. Введите номер действия: " << endl;
                            cin >> s_cmd;
                        }
                        switch (s_cmd)
                        {
                            case 0:
                            {
                                break;
                            }
                            case 1:
                            {
                                int swimming_pool_number = 0;
                                cout << "Введите номер бассейна, в который нужно добавить дорожку: ";
                                cin >> swimming_pool_number;
                                if (a.add_track(swimming_pool_number))
                                {
                                    cout << "Дорожка успешно добавлена конструктором по умолчанию в бассейн №" << swimming_pool_number << " в спортивном комплексе \"" << a.get_name_sport_complex() << "\"" << endl;
                                }
                                else
                                {
                                    cout << "Не удалось добавить бассейн конструктором по умолчанию в спортивный комплекс \"" << a.get_name_sport_complex() << "\"" << endl;
                                }
                                break;
                            }
                            case 2:
                            {
                                int swimming_pool_number = 0;
                                cout << "Введите номер бассейна, в который нужно добавить дорожку: ";
                                cin >> swimming_pool_number;
                                if (a.add_track(swimming_pool_number))
                                {
                                    int track_number = 0, max_people_amount = 0, people_amount = 0;
                                    cout << "Введите номер дорожки: ";
                                    cin >> track_number;
                                    a.set_track_number(swimming_pool_number, 0, track_number);
                                    cout << "Введите максимальное количество людей на дорожке: ";
                                    cin >> max_people_amount;
                                    a.set_max_people_amount(swimming_pool_number, track_number, max_people_amount);
                                    cout << "Введите количество людей на дорожке: ";
                                    cin >> people_amount;
                                    a.set_people_amount(swimming_pool_number, track_number, people_amount);
                                    if (people_amount > 0)
                                    {
                                        for (int i = 0; i < people_amount; i++)
                                        {
                                            int human_age = 0;
                                            cout << "Введите возраст человека №1: ";
                                            cin >> human_age;
                                            a.set_people_amount(swimming_pool_number, track_number, a.get_track_people_amount(swimming_pool_number, track_number) - 1);
                                            a.let_human_on_track(swimming_pool_number, track_number, human_age);
                                        }
                                    }
                                    cout << "Дорожка успешно добавлена конструктором с параметрами в бассейн №" << swimming_pool_number << " спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                                    a.output_track(swimming_pool_number, track_number);
                                }
                                else
                                {
                                    cout << "Не удалось добавить дорожку конструктором с параметрами в бассейн №" << swimming_pool_number << " спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                                }
                                break;
                            }
                            case 3:
                            {
                                int swimming_pool_number = 0;
                                cout << "Введите номер бассейна, в который нужно добавить дорожку: ";
                                cin >> swimming_pool_number;
                                if (a.add_track(swimming_pool_number))
                                {
                                    int number_track = 0;
                                    cout << "Введите номер дорожки с которой будет сделана копия: ";
                                    cin >> number_track;
                                    a.copy_construct_track(swimming_pool_number, number_track);
                                    cout << "Дорожка успешно добавлена конструктором с параметрами в бассейн №" << swimming_pool_number << " спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                                    a.output_track(swimming_pool_number, number_track);
                                }
                                else
                                {
                                    cout << "Не удалось добавить дорожку конструктором копии в бассейн №" << swimming_pool_number << " спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                                }
                                break;
                            }
                        }
                        break;
                        break;
                    }
                }
            }
            case 4:
            {
                cout << "Выбирите действие: удалить:" << endl;
                cout << "1. Бассейн" << endl;
                cout << "2. Дорожку" << endl;
                cout << "0. Назад" << endl;
                cout << "Номер действия: " << endl;
                cin >> s_cmd;
                while (s_cmd < 0 || cmd > 2)
                {
                    cout << "[Ошибка]: введён неверный номер действия. Введите номер действия: " << endl;
                    cin >> s_cmd;
                }
                switch (s_cmd)
                {
                    case 0:
                    {
                        break;
                    }
                    case 1:
                    {
                        int number_swimming_pool = 0;
                        cout << "Введите номер бассейна: ";
                        cin >> number_swimming_pool;
                        if (a.remove_swimming_pool(number_swimming_pool))
                        {
                            cout << "Бассейн №" << number_swimming_pool << "спортивного комплекса \"" << a.get_name_sport_complex() << "\" успешно удалён" << endl;
                        }
                        else
                        {
                            cout << "Не удалось удалить бассейн №" << number_swimming_pool << "спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        int number_swimming_pool = 0, number_track = 0;
                        cout << "Введите номер бассейна: ";
                        cin >> number_swimming_pool;
                        cout << "Введите номер дорожки: ";
                        cin >> number_track;
                        if (a.remove_track(number_swimming_pool, number_track))
                        {
                            cout << "Дорожка №" << number_track << " бассейна №" << number_swimming_pool << " спортивного комплекса \"" << a.get_name_sport_complex() << "\" успешно удалена" << endl;
                        }
                        else
                        {
                            cout << "Не удалось удалить дорожку №" << number_track << " бассейна №" << number_swimming_pool << " спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                        }
                        break;
                    }
                }
                break;
            }
            case 5:
            {
                int number_swimming_pool = 0, number_track = 0, human_age = 0;
                cout << "Введите номер бассейна: ";
                cin >> number_swimming_pool;
                cout << "Введите номер дорожки: ";
                cin >> number_track;
                cout << "Введите возраст человека: ";
                cin >> human_age;
                if (a.let_human_on_track(number_swimming_pool, number_track, human_age))
                {
                    cout << "Человек с возрастом " << human_age << " успешно помещён на дорожку №" << number_track << " бассейна №" << number_swimming_pool << " спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                }
                else
                {
                    cout << "Не удалось поместить человека с возрастом " << human_age << " на дорожку №" << number_track << " бассейна №" << number_swimming_pool << " спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                }
                break;
            }
            case 6:
            {
                int number_swimming_pool = 0, number_track = 0, index_human = 0;
                cout << "Введите номер бассейна: ";
                cin >> number_swimming_pool;
                cout << "Введите номер дорожки: ";
                cin >> number_track;
                a.output_track_peoples_ages(number_swimming_pool, number_track);
                cout << "Введите порядковый номер человека: ";
                cin >> index_human;
                index_human -= 1;
                if (a.remove_human_from_track(number_swimming_pool, number_track, index_human))
                {
                    cout << "Человек №" << index_human << " успешно убран с дорожки №" << number_track << " бассейна №" << number_swimming_pool << " спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                }
                else
                {
                    cout << "Не удалось убрать человека №" << index_human << " с дорожки №" << number_track << " бассейна №" << number_swimming_pool << " спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                }
                break;
            }
            case 7:
            {
                cout << "Выбирите действие: убрать всех людей:" << endl;
                cout << "1. С дорожки" << endl;
                cout << "2. С бассейна" << endl;
                cout << "3. С спортивного комплекса" << endl;
                cout << "0. Назад" << endl;
                cout << "Номер действия: " << endl;
                cin >> s_cmd;
                while (s_cmd < 0 || cmd > 3)
                {
                    cout << "[Ошибка]: введён неверный номер действия. Введите номер действия: " << endl;
                    cin >> s_cmd;
                }
                switch (s_cmd)
                {
                    case 0:
                    {
                        break;
                    }
                    case 1:
                    {
                        int number_swimming_pool = 0, number_track = 0, human_age = 0;
                        cout << "Введите номер бассейна: ";
                        cin >> number_swimming_pool;
                        cout << "Введите номер дорожки: ";
                        cin >> number_track;
                        if (a.remove_all_humans_from_track(number_swimming_pool, number_track))
                        {
                            cout << "Все люди успешно убраны с дорожки №" << number_track << " бассейна №" << number_swimming_pool << " спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                        }
                        else
                        {
                            cout << "Не удалось убрать всех людей с дорожки №" << number_track << " бассейна №" << number_swimming_pool << " спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        int number_swimming_pool = 0;
                        cout << "Введите номер бассейна: ";
                        cin >> number_swimming_pool;
                        if (a.remove_all_humans_from_swimming_pool(number_swimming_pool))
                        {
                            cout << "Все люди успешно убраны с бассейна №" << number_swimming_pool << " спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                        }
                        else
                        {
                            cout << "Не удалось убрать всех людей с бассейна №" << number_swimming_pool << " спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        if (a.remove_all_humans_from_sport_complex())
                        {
                            cout << "Все люди успешно убраны с спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                        }
                        else
                        {
                            cout << "Не удалось убрать всех людей с спортивного комплекса \"" << a.get_name_sport_complex() << "\"" << endl;
                        }
                        break;
                    }
                }
                break;
            }
        }
    } while (cmd != 0);
    return 0;
}