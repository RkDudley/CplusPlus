//
//  main.cpp
//  inherritance project
//
//  Created by Rattikarn Dudley on 8/24/17.
//  Copyright © 2017 Rattikarn Dudley. All rights reserved.
//

#include <iostream>

//class declaration section
class Rectangle
{
protected:
    double length;
    double width;
public:
    Rectangle(double = 1.0, double = 1.0);
    double area();
};
// class implementation for rectriangle
Rectangle::Rectangle(double ll, double ww)
{
    length = ll;
    width = ww;
}
double Rectangle::area()
{
    return length * width;
}

//class declaration section where box is derived from rectangle class
class Box: public Rectangle
{
protected:
    double depth;
public:
    //use a base/member initialization list that call Rectangle constructor
    Box(double d =1.0, double r = 1.0): Rectangle(r), depth(d){};
    double volume();
    double area();
};

//class implementation for rectriangle
double Box:: volume()
{
    return depth * Rectangle::area();
}
double Box::area()
{
    return (2 * Rectangle::area()) + (2 * (depth * length)) + (2 * (depth * width));
}

int main() {
    
    Rectangle a_1, a_2(3,5);
    Box b_1, b_2(6,7);
    
    std::cout << "The area of Rec a 1 is " << a_1.area() << std::endl;
    std::cout << "The area of Rec a 2 is " << a_2.area() << std::endl;
    std::cout << "The area of Box b 1 is " << b_1.area() << std::endl;
    std::cout << "The area of Box b 2 is " << b_2.area() << std::endl;
    
    a_1 = b_2;
    
    std::cout << "The area of Rec a 1 is " << a_1.area() << std::endl;
    
    
    return 0;
}
