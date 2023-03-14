#include "Vec2D.h"
Vec2D::Vec2D()
{
    x=0; y=0;
}
Vec2D::Vec2D(int i, int j)
{
    x = i;
    y = j;

    return ;
}

Vec2D::Vec2D(const Vec2D &source)
{
    x = source.x;
    y = source.y;
    return ;
}

Vec2D &Vec2D::operator=(const Vec2D &source)
{
    x = source.x;
    y = source.y;
    return *this;
}


Vec2D &Vec2D::operator+=(const Vec2D &c)
{
    x += c.x;
    y += c.y;
    return *this;
}

Vec2D &Vec2D::operator-=(const Vec2D &c)
{
    x -= c.x;
    y -= c.y;
    return *this;
}

Vec2D &Vec2D::operator*=(const Vec2D &c)
{
    double temp = x*c.x -y*c.y;
    y = x*c.y + y*c.x;
    x = temp;
    return *this;
}

Vec2D &Vec2D::operator/=(const Vec2D &c)
{
    double norm = c.x*c.x + c.y*c.y;
    double temp = (x*c.x + y*c.y) / norm;
    y = (-x*c.y + y*c.x) / norm;
    x = temp;
    return *this;
}

bool Vec2D::operator== (Vec2D v1)
{
if (v1.x==x && v1.y==y)
{return true;}
else return false;

}