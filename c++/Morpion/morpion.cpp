#include <iostream>

using namespace std;

struct plt{
    char tab[3][3] = {{' ',' ',' '},
                      {' ',' ',' '},
                      {' ',' ',' '}};

    bool Draw(){
        int check = 0;
        for (int i = 0; i < sizeof(tab)/sizeof(tab[0]); i++)
        {
           for (int j = 0; j < sizeof(tab[0]); j++)
           {
            cout<<11<<endl;
           }
           
        }
        return false;
    }
};

struct player{
    char m;
    player(char mark){
        m = mark;
    }
};

int main(){
    player p1('O');
    player p2('X');
    return 0;
}