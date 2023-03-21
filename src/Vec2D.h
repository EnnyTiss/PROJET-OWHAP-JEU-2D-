#ifndef _VEC2D_H
#define _VEC2D_H

class Vec2D {
    public:
    int x;
    int y;

Vec2D();
Vec2D(int i, int j);

Vec2D(const Vec2D &source);

Vec2D &operator=(const Vec2D &source);



bool operator== (Vec2D v1);
};
#endif