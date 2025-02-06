#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <cmath>

class Figure
{
public:
	virtual double Square() const = 0;
	virtual ~Figure() = default;

	bool operator<(const Figure& other) const {
        return this->Square() < other.Square();
    }

};

class Circle final : public Figure 
{
public:
	explicit Circle(double r) : radius{r} {}

	double Square() const override
	{
		return 3.14 * radius * radius;
	}

private:
	double radius;

};

class Triangle final : public Figure
{
public:
	Triangle(double a, double b, double c) : sides{a, b, c} {}

	double Square() const override
	{
		double p = (sides[0] + sides[1] + sides[2]) / 2;
		double area = sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2]));
		return area;
	}

private:
	std::vector<double> sides;
};

class Rectangle final : public Figure
{
public:
	Rectangle(double w, double h) : width{w}, heigth{h} {}
	double Square() const override { return width * heigth; }

private:
	double width;
	double heigth;
};


int main()
{
	std::vector<std::unique_ptr<Figure>> figures;

    figures.push_back(std::make_unique <Circle>(5));
    figures.push_back(std::make_unique <Triangle>(3, 4, 5));
    figures.push_back(std::make_unique <Rectangle>(4, 6));

	std::sort(figures.begin(), figures.end(), [](const std::unique_ptr<Figure>& a, const std::unique_ptr<Figure>& b) -> bool{
		return *a < *b;
	});

    for (const auto& figure : figures){
        std::cout << "Square: " << figure->Square() << std::endl;
    }

	return 0;
}
