#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "map.h"


using namespace N;
using namespace std;

class Animal
{
private:
    string name, sx;
    int pv, max_pv;
    pair<int, int> pos;

public:
    Animal(const string &n, int p, const string &s, int px, int py)
    {
        name = n;
        max_pv = p;
        pv = max_pv;
        sx = s;
        pos = {px, py};
    }

    string get_name()
    {
        return name;
    }

    string getSx()
    {
        return sx;
    }

    pair<int, int> &get_pos()
    {
        return pos;
    }

    bool dead()
    {
        return pv <= 0;
    }

    bool sameAnimal(Animal animal)
    {
        return animal.name == name;
    }

    bool sameSx(Animal animal)
    {
        return animal.sx == sx;
    }

    void move(Map map){
        int rand_move = rand() % 5;
        int x = pos.first;
        int y = pos.second;
        switch (rand_move)
        {
        case 0:
            break;
        case 1:
            if(map.estVide(y-1,x)){
                y = y -1;
            }
            break;
        case 2:
            if(map.estVide(y,x+1)){
                x = x + 1;
            }
            break;
        case 3:
            if(map.estVide(y+1,x)){
                y = y + 1;
            }
            break;
        case 4:
            if(map.estVide(y,x-1)){
                x = x - 1;
            }
            break;
        
        default:
            break;
        }

        pos = {x,y};
        map.placement(y,x,name+sx);

    }

    ~Animal() {}
};

class Loup : public Animal
{

public:
    Loup(string s, int px, int py) : Animal("L", 15, s, px, py){}
    ~Loup(){}
};

class Mouton : public Animal
{
public:
    Mouton(string s, int px, int py) : Animal("M", 20, s, px, py){}
    ~Mouton(){}
};

int main()
{
    srand(time(NULL));
    Mouton a("F", 1, 4);
    Loup b("M", 1, 5);
    vector<Animal> animals;
    animals.push_back(a);
    Map map;
    cout << a.sameSx(b) << endl;
    for (int i = 0; i < 10; i++)
    {
        animals[0].move(map);
        pair<int, int> pos = animals[0].get_pos();
        int x = pos.first;
        int y = pos.second;
        cout << x << y << endl;
        map.affiche();
    }
    // map.affiche();
    return 0;
}