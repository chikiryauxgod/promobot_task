#include <iostream>
#include <vector>
#include <cmath>

class Figure
{
public:
	virtual double Square() = 0;
	virtual ~Figure() = default;

};

class Circle : public Figure 
{
public:
	Circle(int r) : radius{r} {}

	double Square() override
	{
		return 3.14 * radius * radius;
	}

private:
	int radius;

};

class Triangle : public Figure
{
public:
	Triangle(int a, int b, int c) : sides{a, b, c} {}

	double Square() override
	{
		int p = (sides[0] + sides[1] + sides[2]) / 2;
		double area = sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2]));
		return area;
	}

private:
	std::vector<int> sides;

};

class Rectangle : public Figure
{
public:
	Rectangle(int w, int h) : width{w}, heigth{h} {}
	double Square() override { return width * heigth; }

private:
	int width;
	int heigth;
};


int main()
{
	std::vector<Figure*> figures;

    figures.push_back(new Circle(5));
    figures.push_back(new Triangle(3, 4, 5));
    figures.push_back(new Rectangle(4, 6));


    for (auto* figure : figures){
        std::cout << "Square: " << figure->Square() << std::endl;
    }


    for (auto* figure : figures){
        delete figure;
    }
	
    return 0;

	return 0;
}
