#ifndef _Object_H_
#define _Object_H_

class Object {
private:
	unsigned id;
	unsigned x;
	unsigned y;
public:
	Object(unsigned x, unsigned y, unsigned id);
	unsigned getId() const { return id; };
	unsigned getX() const { return x; };
	unsigned getY() const { return y; };
};

#endif
