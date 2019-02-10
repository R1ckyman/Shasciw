#ifndef _Door_H_
#define _Door_H_

class Door{
  private:
    unsigned x;
    unsigned y;
    bool open;
    unsigned time;
  public:
    Door(unsigned x, unsigned y);
    unsigned getX() const { return x; };
    unsigned getY() const { return y; };
    unsigned getTime() const { return time; };
    bool getOpen() const { return open; };
    void setOpen(bool open);
    void setTime();
};

#endif
