#include<iostream>
#include<cstdio>
#include<string>
#include <stdlib.h>
#include <vector>
#include <math.h> 


using namespace std;

class Animal{
    private:
        string name;
        int pv,x,y;
        string sx;
    public:
        Animal(const string &n,int p, const string &s,int px, int py){
            name = n;
            pv = p;
            sx = s;
            x = px;
            y = py;
        }

        string get_name(){
            return name;
        }

        int* get_pos(){
            static int pos[2] = {y,x};
            return pos;
        }

        bool dead(){
            return pv<=0;
        }
};

int main(){
    Animal a("M",5,"F",1,4);
    int *pos = a.get_pos();
    cout<<pos[0]<<pos[1];
    cout<<a.dead();
    return 0;
}