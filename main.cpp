//
//  main.cpp
//  inheritance
//
//  Created by Rattikarn Dudley on 8/22/17.
//  Copyright © 2017 Rattikarn Dudley. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 2.0 * asin(1.0);

//class declaration section
class Circle
{
protected:
    double radius;
public:
    Circle(double = 1.0); // constructor
    double calcval();
};

//class implementation section for circle
Circle::Circle(double r) // constructor
{
    radius = r;
}
// calculate the area of a Circle
double Circle::calcval()
{
    return (PI * radius * radius);
}
// class declaration section where Cylinder is derived from circle
class Cylinder : public Circle
{
protected:
    double length; // add one data member
public:
    Cylinder(double r = 1.0, double l = 1.0): Circle(r), length(l){}
    double calcval();
};
//class implemetation section for Cylinder
double Cylinder::calcval()
{
    return (length * Circle::calcval()); // note the base function call
}
// class implementation section where Sphere from base Circle class
class Sphere: public Circle
{
public:
    Sphere(double r = 1.0): Circle(r){}; // constructor
    double calcval();
};

// class implementation
double Sphere::calcval()
{
    return radius * (4/3) * Circle::calcval();
}

int main()
{
    Circle circle_1, circle_2(2);
    Cylinder cyl_1(3,4);
    Sphere sp_1(7);
    
    cout << "circle 1 is " << circle_1.calcval() << endl;
    cout << "circle 2 is " << circle_2.calcval() << endl;
    cout << "Cylinder 1 is " << cyl_1.calcval() << endl;
    cout << "Sphere 1 is " << sp_1.calcval() << endl;
    
    circle_1 = cyl_1;
    cout << "Cylider 1 is " << circle_1.calcval() << endl;
    
    return 0;
}
