//classe identificativa per ogni casella
#include<iostream>
using namespace std;

enum class Direction { UP, LEFT, DIAG };
ostream& operator<<(ostream& out, const Direction& dir){
    switch (dir)
    {
    case Direction::UP:
        out<<"U";
        break;
    case Direction::LEFT:
        out<<"L";
        break;
    case Direction::DIAG:
        out<<"D";
        break;
    default:
        break;
    }
    return out;
}

class Casella{
    private:
        int value;
        Direction dir;  //può essere UP, LEFT, DIAG

    public:
        Casella():value{0}, dir{Direction::UP}{}
        Casella(int value, Direction dir):value{value}, dir{dir}{}

        int getValue(){return value;}
        Direction getDirection(){return dir;}

        void setDirection(Direction dir)
        {
            this->dir = dir;
        }
        void setValue(int value)
        {
            this->value = value;
        }

};