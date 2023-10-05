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
            for (int i = 0; i < get_people_amount() - 1; i++)
            {
                peoples_ages[i] = peoples_ages[i + 1];
            }
            set_people_amount(get_people_amount() - 1);
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
    bool let_human_on_track(int _track_number, int _human_age)
    {
        bool method_result = false;
        int i = 0, current_index_track = 0, number_last_track = tracks[get_tracks_amount()]->get_track_number();
        for (i = 0; i < get_tracks_amount(); i++)
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
            // добавить возраст человека в массив возрастов
            method_result = true;
        }
        else if ((_human_age > 6 && _human_age < 80) && tracks[current_index_track]->get_people_amount() < tracks[current_index_track]->get_max_people_amount())
        {
            tracks[current_index_track]->set_people_amount(tracks[current_index_track]->get_people_amount() + 1);
            // добавить возраст человека в массив возрастов
            method_result = true;
        }
        return (method_result);
    }
    //bool add_track() { }
    //bool remove_track() { }
    //bool remove_human_from_track(int age) { }
    //bool remove_all_humans_from_track() { }
    //bool remove_all_humans_from_swimming_pool() { }
    //bool increment_tracks_amount() { }
    //bool decrement_tracks_amount() { }
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
    //bool add_swimming_pool() { }
    //bool remove_swimming_pool() { }
    //bool let_human_on_track() { }
    //bool remove_human_from_track() { }
    //bool remove_all_humans_from_track() { }
    //bool remove_all_humans_from_swimming_pool() { }
    //bool remove_all_humans_from_sport_complex() { }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int i = 0, cmd = 0;
    do
    {
        cout << "Выберите действие:" << endl;
        cout << "1. Вывести на экран" << endl;
        cout << ">>> 1. Спортивный комплекс" << endl;
        cout << ">>> 2. Бассейн" << endl;
        cout << ">>> 3. Дорожку" << endl;
        cout << "2. Создать" << endl;
        cout << ">>> 1. Спортивный комплекс" << endl;
        cout << ">>> 2. Бассейн" << endl;
        cout << ">>> 3. Дорожку" << endl;
        cout << "3. Поместить человека на дорожку" << endl;
        cout << "4. Убрать человека с дорожки" << endl;
        cout << "0. Завершить работу программы" << endl;
        cout << "Номер действия: " << endl;
        cin >> cmd;
        while (cmd < 0 || cmd > 4)
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
                cout << "Вывести на экран:" << endl;
                cout << "1. Спортивный комплекс" << endl;
                cout << "2. Бассейн" << endl;
                cout << "3. Дорожку" << endl;
                cout << "0. Вернуться назад" << endl;
                cout << "Номер действия: " << endl;
                cin >> cmd;
                while (cmd < 0 || cmd > 3)
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
                        break;
                    }
                    case 2:
                    {
                        break;
                    }
                    case 3:
                    {
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                cout << "Создать:" << endl;
                cout << "1. Спортивный комплекс" << endl;
                cout << "2. Бассейн" << endl;
                cout << "3. Дорожку" << endl;
                cout << "0. Вернуться назад" << endl;
                cout << "Номер действия: " << endl;
                cin >> cmd;
                while (cmd < 0 || cmd > 3)
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
                        cout << "Спортивный комплекс:" << endl;
                        cout << "1. Конструктор по умолчанию" << endl;
                        cout << "2. Конструктор с параметрами" << endl;
                        cout << "3. Конструктор копии" << endl;
                        cout << "0. Вернуться назад" << endl;
                        cout << "Номер действия: " << endl;
                        cin >> cmd;
                        while (cmd < 0 || cmd > 3)
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
                                break;
                            }
                            case 2:
                            {
                                break;
                            }
                            case 3:
                            {
                                break;
                            }
                            case 4:
                            {
                                break;
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "Бассейн:" << endl;
                        cout << "1. Конструктор по умолчанию" << endl;
                        cout << "2. Конструктор с параметрами" << endl;
                        cout << "3. Конструктор копии" << endl;
                        cout << "0. Вернуться назад" << endl;
                        cout << "Номер действия: " << endl;
                        cin >> cmd;
                        while (cmd < 0 || cmd > 3)
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
                                break;
                            }
                            case 2:
                            {
                                break;
                            }
                            case 3:
                            {
                                break;
                            }
                            case 4:
                            {
                                break;
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        cout << "Дорожка:" << endl;
                        cout << "1. Конструктор по умолчанию" << endl;
                        cout << "2. Конструктор с параметрами" << endl;
                        cout << "3. Конструктор копии" << endl;
                        cout << "0. Вернуться назад" << endl;
                        cout << "Номер действия: " << endl;
                        cin >> cmd;
                        while (cmd < 0 || cmd > 3)
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
                                break;
                            }
                            case 2:
                            {
                                break;
                            }
                            case 3:
                            {
                                break;
                            }
                            case 4:
                            {
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
        }
    } while (cmd != 0);

    return 0;
}