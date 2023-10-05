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
        peoples_ages = object.peoples_ages; // ? array
    }
    ~track()
    {
        delete[]peoples_ages;
    }
    int get_track_number() { return track_number; }
    int get_max_people_amount() { return max_people_amount; }
    int get_people_amount() { return people_amount; }
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
                tracks[i] = new track(object.tracks[i]->get_track_number(), object.tracks[i]->get_people_amount(), object.tracks[i]->get_max_people_amount()); // ? ages array
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
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    sport_complex a("Донбасс", 5, 5);
    a.output_sport_complex();
    int cmd = 0, int s_cmd = 0, sp_number = 0, t_number = 0, int_data = 0;
    double double_data = 0;
    string string_data = "";
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
                        cout << "Введите номер бассейна: " << endl;
                        cin >> sp_number;
                        a.output_swimming_pool(sp_number);
                        break;
                    }
                    case 3:
                    {
                        cout << "Введите номер бассейна: " << endl;
                        cin >> sp_number;
                        cout << "Введите номер дорожки: " << endl;
                        cin >> t_number;
                        a.output_track(sp_number, t_number);
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
                                cout << "Введите новое название спортивного комплекса" << endl;
                                cin >> string_data;
                                a.set_name_sport_complex(string_data);
                                break;
                            }
                            case 2:
                            {
                                cout << "Введите новое максимальное количество бассейнов спортивного комплекса" << endl;
                                cin >> int_data;
                                a.set_max_swimming_pools_amount(int_data);
                                break;
                            }
                            case 3:
                            {
                                cout << "Введите новое количество бассейнов спортивного комплекса" << endl;
                                cin >> int_data;
                                a.set_swimming_pools_amount(int_data);
                                break;
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        // !
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
                                    // !
                                }
                                else
                                {
                                    // !
                                }
                                break;
                            }
                            case 2:
                            {
                                if (a.add_swimming_pool())
                                {
                                    // !
                                    
                                    //int swimming_pool_number = 0, max_tracks_amount = 0, tracks_amount = 0;
                                    //double max_depth = 0, lenght = 0;
                                    //cout << "Введите номер бассейна: ";
                                    //cin >> a.
                                    //cout << "Введите максимальное количество дорожек: ";
                                    //cin >> max_tracks_amount;
                                    //cout << "Введите максимальную глубину: ";
                                    //cin >> max_depth;
                                    //cout << "Введите длину: ";
                                    //cin >> lenght;
                                }
                            }
                        }
                    }
                    case 2:
                    {
                        // !
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
                        // !
                        break;
                    }
                    case 2:
                    {
                        // !
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
                    // !
                }
                else
                {
                    // !
                }
                break;
            }
            case 6:
            {
                int number_swimming_pool = 0, number_track = 0, human_age = 0;
                cout << "Введите номер бассейна: ";
                cin >> number_swimming_pool;
                cout << "Введите номер дорожки: ";
                cin >> number_track;
                cout << "Введите возраст человека: ";
                cin >> human_age;
                if (a.remove_human_from_track(number_swimming_pool, number_track, human_age))
                {
                    // !
                }
                else
                {
                    // !
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
                            // !
                        }
                        else
                        {
                            // !
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
                            // !
                        }
                        else
                        {
                            // !
                        }
                        break;
                    }
                    case 3:
                    {
                        if (a.remove_all_humans_from_sport_complex())
                        {
                            // !
                        }
                        else
                        {
                            // !
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