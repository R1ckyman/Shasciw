#ifndef _Door_H_
#define _Door_H_

class Door{
    private:
        unsigned x;
        unsigned y;
        bool closed;
        unsigned time;
    public:
        Door(unsigned x, unsigned y);
        unsigned getX() const { return x; };
        unsigned getY() const { return y; };
        unsigned getTime() const { return time; };
        bool getClosed() const { return closed; };
        void setClosed(bool closed);
        void setTime();
};

#endif
