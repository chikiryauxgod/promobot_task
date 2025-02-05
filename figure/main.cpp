#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

class Figure
{
public:
	virtual double Square() const = 0;
	virtual ~Figure() = default;

	bool operator<(const Figure& other) const {
        return this->Square() < other.Square();
    }

};

class Circle : public Figure 
{
public:
	Circle(int r) : radius{r} {}

	double Square() const override
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

	double Square() const override
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
	double Square() const override { return width * heigth; }

private:
	int width;
	int heigth;
};


int main()
{
	std::vector<std::unique_ptr<Figure>> figures;

    figures.push_back(std::make_unique <Circle>(5));
    figures.push_back(std::make_unique <Triangle>(3, 4, 5));
    figures.push_back(std::make_unique <Rectangle>(4, 6));

	// std::sort(figures.begin(), figures.end())
    for (const auto& figure : figures){
        std::cout << "Square: " << figure->Square() << std::endl;
    }

    return 0;

	return 0;
}
