#include <iostream>
#include <vector>
#include<string>
using namespace std;

class Movie{
    private:
        string Movename;
        float rate;
    public:
    Movie()
    {
        Movename = "";
        rate = 0.0;
    }
    Movie(string n,float a)
    {
        this->Movename = n;
        this->rate = a;
    }
    void Print()
    {
        cout << Movename << " : " << rate << endl;
    }
};

int main()
{
    vector<Movie> objArray;
        Movie a{"titinic",9.9};
        objArray.push_back(a);
        Movie b{"gone with the wind",9.6};
        objArray.push_back(b);
        Movie c{"terminator",9.7};
        objArray.push_back(c);

    for (Movie c : objArray)
    {
        c.Print();
    }
    return 0;
}