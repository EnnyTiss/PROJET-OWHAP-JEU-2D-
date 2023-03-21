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



bool Vec2D::operator== (Vec2D v1)
{
if (v1.x==x && v1.y==y)
{return true;}
else return false;

}