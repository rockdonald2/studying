/*int main()
{
	int x{ 0 }, y{ 0 };

	std::cout << "Enter a number: ";
	std::cin >> x;

	std::cout << "Enter another number: ";
	std::cin >> y;

	std::cout << x << " + " << y << " = " << x + y << '\n';
	std::cout << x << " - " << y << " = " << x - y << '\n';

	return 0;
}*/

/*int readNumber()
{
	std::cout << "Enter a number: ";
	int x{ 0 };
	std::cin >> x;

	return x;
}

void writeAnswer(int &x, int &y)
{
	std::cout << x << " + " << y << " = " << x + y << '\n';
}

int main()
{
	int x{ 0 }, y{ 0 };

	x = readNumber();
	y = readNumber();

	writeAnswer(x, y);

	return 0;
}*/

/*int readNumber()
{
	std::cout << "Please enter a number: ";
	int x{ 0 };
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The sum is:" << x << '\n';
}

int main()
{
	int x{ readNumber() };
	x = x + readNumber();
	writeAnswer(x);

	return 0;
}*/

/*int readNumber()
{
	std::cout << "Please enter a number:";
	int x{};
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The quotient is:" << x;
}

int main()
{
	int x{ 0 };
	int y{ 0 };
	x = readNumber();
	y = readNumber();
	writeAnswer(x / y);

	return 0;
}*/

/*namespace Constants
{
	constexpr double gravity{ 9.8 }; // m/s^2
}

void writeHeight(double &tH, int &s)
{
	std::cout << "At " << s << " seconds, the ball is at height: " << tH << " meters\n";
}

void calculateHeight(double &tH)
{
	double cH{ tH };
	double dF{ 0 };

	for (int i = 0; i <= 5; ++i)
	{
		dF = Constants::gravity * (i * i) / 2;
		cH = tH - dF;
		if (cH > 0)
			writeHeight(cH, i);
		else
			std::cout << "At " << i << " seconds, the ball is on the ground\n";
	}
}

int main(void)
{
	using namespace std;

	cout << "Enter the height of the tower in meters: ";
	double tH{ 0 };
	cin >> tH;

	calculateHeight(tH);

	return 0;
}*/

/*

1101 = 1x1 + 0x2 + 1x4 + 1x8 = 13
1011 10 = 0x1 + 1x2 + 1x4 + 1x8 + 0x16 + 1x32 = 2 + 4 + 8 + 32 = 46

15 = 1111
	15 / 2 = 7 r 1
	7 / 2 = 3 r 1
	3 / 2 = 1 r 1
	1 / 2 = 0 r 1

53 =  110101
	53 / 2 = 26 r 1
	26 / 2 = 13 r 0
	13 / 2 = 6 r 1
	6 / 2 = 3 r 0
	3 / 2 = 1 r 1
	1 / 2 = 0 r 1

*/

/*#include <string>

enum class Monsters
{
	OGRE,
	DRAGON,
	ORC,
	GIANTSPIDER,
	SLIME
};

struct Monster
{
	Monsters m_type;
	std::string m_name;
	int m_health;
};

std::string convertMonsterToString(Monster &m)
{
	switch (m.m_type)
	{
	case Monsters::OGRE:
		return "Ogre";
	case Monsters::DRAGON:
		return "Dragon";
	case Monsters::GIANTSPIDER:
		return "Giant Spider";
	case Monsters::ORC:
		return "Orc";
	case Monsters::SLIME:
		return "Slime";
	default:
		return "Error";
	}
}

void printMonster(Monster &m)
{
	std::cout << "This " << convertMonsterToString(m) << " is named " << m.m_name << " and has " << m.m_health << " health.\n";
}

int main()
{
	Monster torg = { Monsters::OGRE, "Torg", 145 };
	Monster blurp = { Monsters::SLIME, "Blurp", 23 };

	printMonster(torg);
	printMonster(blurp);

	return 0;
}*/

/*#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);  
	
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

void gameHiLo(int &number)
{
	int guess{ 0 };
	for (int i = 1; i <= 7; ++i)
	{
		std::cout << "Guess #" << i << ":";
		std::cin >> guess;

		if (guess > number)
			std::cout << "Your guess is too high\n";
		else if (guess < number)
			std::cout << "Your guess is too low\n";
		else
			std::cout << "Correct! You win!\n";
	}
}

int main()
{
	bool game{ true };

	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	int number = getRandomNumber(1, 100);

	while (game)
	{
		std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";

		gameHiLo(number);

		std::cout << "Would you like to play again (y/n)?:";
		char ch;
		std::cin >> ch;

		if (ch == 'y')
			game = true;
		if (ch == 'n')
			game = false;
	}

	return 0;
}*/

/*int swapVariables(int &x, int &y)
{
	int temp{ 0 };
	temp = x;
	x = y;
	y = temp;

	return x, y;
}

int main()
{
	int x{ 5 };
	int y{ 7 };

	std::cout << x << " " << y << '\n';

	swapVariables(x, y);

	std::cout << x << " " << y << '\n';

	return 0;
}*/

/*void printCStr(const char* str)
{
	for (int i{ 0 }; i < strlen(str); ++i)
	{
		if (str[i] != '\0')
			std::cout << str[i] << ' ';
	}
}

int main()
{
	const char* str{ "Hello, world!" };

	printCStr(str);

	return 0;
}*/

/*#include <cassert>

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearch1(int *array, int target, int min, int max)
{
	assert(array && "An error occurred with the array at the beginning.\n");

	while (min <= max)
	{
		int midpoint = min + ((max - min) / 2);

		if (array[midpoint] > target)
			max = midpoint - 1;

		if (array[midpoint] < target)
			min = midpoint + 1;
		
		if (array[midpoint] == target)
			return midpoint;
	}

	return -1;
}

int binarySearch(int *array, int target, int min, int max)
{
	assert(array && "An error occurred with the array in the beginning.\n");

	if (min > max)
		return -1;

	int midpoint = min + ((max - min) / 2);

	if (array[midpoint] > target)
		return binarySearch(array, target, min, midpoint - 1);
	
	if (array[midpoint] < target)
		return binarySearch(array, target, midpoint + 1, max);

	else
		return midpoint;
}

int main()
{
	int array[] = { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

	// We're going to test a bunch of values to see if they produce the expected results
	const int numTestValues = 9;
	// Here are the test values
	int testValues[numTestValues] = { 0, 3, 12, 13, 22, 26, 43, 44, 49 };
	// And here are the expected results for each value
	int expectedValues[numTestValues] = { -1, 0, 3, -1, -1, 8, -1, 13, -1 };

	// Loop through all of the test values
	for (int count = 0; count < numTestValues; ++count)
	{
		// See if our test value is in the array
		int index = binarySearch(array, testValues[count], 0, 14);
		// If it matches our expected value, then great!
		if (index == expectedValues[count])
			std::cout << "test value " << testValues[count] << " passed!\n";
		else // otherwise, our binarySearch() function must be broken
			std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
	}

	return 0;
}*/

/*#include <cmath>

class Point2d
{
private:
	double m_x, m_y;

public:
	Point2d(double x = 0.0, double y = 0.0) : m_x(x), m_y(y) {}

	void print()
	{
		std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
	}

	double distanceTo(const Point2d &p)
	{
		double distance{ 0.0 };

		distance = sqrt((m_x - p.m_x)*(m_x - p.m_x) + (m_y - p.m_y)*(m_y - p.m_y));

		return distance;
	}

	double getX() 
	{
		return m_x;
	}

	double getY() 
	{
		return m_y;
	}

	friend double distanceFrom(Point2d &p1, Point2d &p2);
};

double distanceFrom(Point2d &p1, Point2d &p2)
{
	double distance{ 0.0 };

	distance = sqrt((p1.m_x - p2.m_x)*(p1.m_x - p2.m_x) + (p1.m_y - p2.m_y)*(p1.m_y - p2.m_y));

	return distance;
}

int main()
{
	Point2d first;
	Point2d second(3.0, 4.0);
	first.print();
	second.print();

	std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
	std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

	return 0;
}*/

/*class HelloWorld
{
private:
	char *m_data;

public:
	HelloWorld()
	{
		m_data = new char[14];
		const char *init = "Hello, World!";
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}

	~HelloWorld()
	{
		delete[] m_data;

		std::cout << "deleted\n";
	}

	void print() const
	{
		std::cout << m_data;
	}

};

int main()
{
	HelloWorld hello;
	hello.print();

	return 0;
}*/

/*#include <string>
#include <cstdlib>
#include <ctime>

class Monster
{
public:
	enum MonsterType
	{
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPES
	};

private:
	MonsterType m_type;
	std::string m_name;
	std::string m_roar;
	int m_hp;

public:
	Monster(MonsterType type, std::string name, std::string roar, int hp) :
		m_type(type), m_name(name), m_roar(roar), m_hp(hp)
	{}

	std::string getTypeString()
	{
		switch (m_type)
		{
		case MonsterType::DRAGON:
			return "dragon";
		case MonsterType::GOBLIN:
			return "goblin";
		case MonsterType::OGRE:
			return "ogre";
		case MonsterType::ORC:
			return "orc";
		case MonsterType::SKELETON:
			return "skeleton";
		case MonsterType::TROLL:
			return "troll";
		case MonsterType::VAMPIRE:
			return "vampire";
		case MonsterType::ZOMBIE:
			return "zombie";
		default:
			return "error";
		}
	}

	void print()
	{
		std::cout << m_name << " the " << this->getTypeString() << " has " << m_hp 
			<< " hit points and says " << m_roar << '\n';
	}
};

class MonsterGenerator
{
private:
	static std::string s_names[6];
	static std::string s_roars[6];
public:
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	static Monster generateMonster()
	{
		return Monster(static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MonsterType::MAX_MONSTER_TYPES - 1)), 
			"Bones", "*rattle*", getRandomNumber(1, 100));
	}
};

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	Monster m = MonsterGenerator::generateMonster();
	m.print();

	return 0;
}*/

/*class Average
{
private:
	int m_avg;
	int m_num;

public:
	Average() : m_avg(0), m_num(0) {}

	Average(const Average &copy) : m_avg(copy.m_avg), m_num(copy.m_num) {}

	Average& operator+=(int value)
	{
		this->m_avg = this->m_avg + value;
		++this->m_num;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream &out, const Average &a)
	{
		out << (static_cast<double>(a.m_avg)) / static_cast<double>(a.m_num);

		return out;
	}

	Average& operator=(Average &a)
	{
		this->m_avg = a.m_avg;
		this->m_num = a.m_num;

		return *this;
	}
};

int main()
{
	Average avg;

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
}*/

/*#include <cassert>

class IntArray
{
private:
	int *m_data;
	int m_length;

public:
	IntArray(int length) : m_length(length)
	{
		assert(length > 0);

		m_data = new int[length];
	}

	IntArray(const IntArray &a)
	{
		assert(a.m_data);

		m_length = a.m_length;
		m_data = new int[m_length];

		for (int c = 0; c < m_length; ++c)
		{
			m_data[c] = a.m_data[c];
		}
	}

	~IntArray()
	{
		delete[] m_data;
		m_length = 0;
	}

	int& operator[](const int index)
	{
		assert(index >= 0);
		assert(index < m_length);

		return m_data[index];
	}

	friend std::ostream& operator<<(std::ostream &out, const IntArray &a)
	{
		for (int i = 0; i < a.m_length; ++i)
		{
			out << a.m_data[i] << ' ';
		}

		return out;
	}

	IntArray& operator=(IntArray &a)
	{
		if (this == &a)
			return *this;

		delete[] this->m_data;

		this->m_length = a.m_length;
		m_data = new int[m_length];

		assert(a.m_data);

		for (int j = 0; j < this->m_length; ++j)
		{
			this->m_data[j] = a.m_data[j];
		}

		return *this;
	}
};

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}*/

/*#include <cmath>
#include <cstdlib>

class FixedPoint2
{
private:
	int16_t m_num;
	int8_t m_dec;

public:
	FixedPoint2(int16_t num = 0, int8_t dec = 0) : m_num(num), m_dec(dec)
	{
		if (m_num < 0 || m_dec < 0)
		{
			if (m_num > 0)
				m_num = -m_num;
			if (m_dec > 0)
				m_dec = -m_dec;
		}
	}

	FixedPoint2(const double &num)
	{
		m_num = static_cast<int16_t>(num);

		m_dec = static_cast<int8_t>(round((num - m_num) * 100));
	}

	operator double() const
	{
		return m_num + static_cast<double>(m_dec) / 100;
	}

	friend std::ostream& operator<<(std::ostream &out, const FixedPoint2 &f)
	{	
		out << static_cast<double>(f);

		return out;
	}

	bool operator==(const FixedPoint2 &f)
	{
		return (this->m_num == f.m_num && this->m_dec == f.m_dec);
	}

	friend std::istream& operator>>(std::istream &in, FixedPoint2 &f)
	{
		double num{ 0 };
		in >> num;

		f.m_num = static_cast<int16_t>(num);

		f.m_dec = static_cast<int8_t>(round((num - f.m_num) * 100));

		return in;
	}

	FixedPoint2 operator-()
	{
		return FixedPoint2(-m_num, -m_dec);
	}

	friend FixedPoint2 operator+(FixedPoint2 &f1, FixedPoint2 &f2)
	{
		double temp = static_cast<double>(f1) + static_cast<double>(f2);

		return (static_cast<FixedPoint2>(temp));
	}
};

void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
}

int main()
{
	testAddition();

	FixedPoint2 a(-0.48);
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}*/

/*#include <string>

class Fruit
{
protected:
	std::string m_name;
	std::string m_color;

public:
	Fruit (std::string name, std::string color) : m_name(name), m_color(color) {}

	std::string getName()
	{
		return m_name;
	}

	std::string getColor()
	{
		return m_color;
	}
};

class Apple : public Fruit
{
public:
	Apple (std::string color = "red") : Fruit("Apple", color) {}
};

class Banana : public Fruit
{
public:
	Banana (std::string color = "yellow") : Fruit("Banana", color) {}
};

class GrannySmith : public Apple
{
public:
	GrannySmith() : Apple("green") {}

	std::string getName()
	{
		return "Granny smith apple";
	}
};

int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}*/

/*class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;

public:
	Point(int x, int y, int z)
		: m_x(x), m_y(y), m_z(z)
	{

	}

	friend std::ostream& operator<<(std::ostream &out, const Point &p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Shape
{
public:
	virtual std::ostream& print(std::ostream &out) const = 0;

	friend std::ostream& operator<<(std::ostream &out, const Shape &s) 
	{
		return s.print(out);
	}

	virtual ~Shape() {}
};

class Circle : public Shape
{
private:
	Point m_cp;
	int m_r;

public:
	Circle(const Point &cp, int r) : m_cp(cp), m_r(r) {}

	virtual std::ostream& print(std::ostream &out) const
	{
		out << "Circle(" << m_cp << ", radius " << m_r << ")";

		return out;
	}

	int getRadius() const
	{
		return m_r;
	}
};

class Triangle : public Shape
{
private:
	Point m_p1, m_p2, m_p3;

public:
	Triangle(const Point p1, const Point p2, const Point p3) : m_p1(p1), m_p2(p2), m_p3(p3) {}

	virtual std::ostream& print(std::ostream &out) const
	{
		out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";

		return out;
	}
};

#include <vector>
#include <iostream>

int getLargestRadius(std::vector<Shape*> &v)
{
	int largest{ 0 };
	for (int i = 0; i < v.size(); ++i)
	{
		if (dynamic_cast<Circle*>(v[i]))
		{
		if (dynamic_cast<Circle*>(v[i])->getRadius() > largest)
			largest = dynamic_cast<Circle*>(v[i])->getRadius();
		}
	}
	return largest;
}

int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

	for (int j = 0; j < v.size(); ++j)
	{
		std::cout << *(v[j]) << '\n';
	}

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	for (int z = 0; z < v.size(); ++z)
		delete v[z];

	return 0;
}*/

/*template <typename T1>
class Pair1
{
private:
	T1 m_p1, m_p2;

public:
	Pair1(T1 p1, T1 p2) : m_p1(p1), m_p2(p2) {}

	T1 first() { return m_p1; }
	T1 second() { return m_p2; }

	T1 first() const { return m_p1; }
	T1 second() const { return m_p2; }
};

int main()
{
	Pair1<int> p1(5, 8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(2.3, 4.5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}*/

/*#include <string>

template <typename T1, typename T2>
class Pair
{
private:
	T1 m_p1;
	T2 m_p2;

public:
	Pair(T1 p1, T2 p2) : m_p1(p1), m_p2(p2) {}

	T1& first() { return m_p1; }
	T2& second() { return m_p2; }

	const T1& first() const { return m_p1; }
	const T2& second() const { return m_p2; }
};

template <typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(std::string str, T v) : Pair<std::string, T>(str, v) {}
};

int main()
{
	Pair<int, double> p1(5, 6.7);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(2.3, 4);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}*/

/*#include <exception>
#include <stdexcept>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator)
	{
		if (m_denominator == 0)
			throw std::runtime_error("Denominator = 0");
	}

	friend std::ostream& operator<<(std::ostream &out, const Fraction &f)
	{
		out << f.m_numerator << "/" << f.m_denominator;

		return out;
	}
};

int main()
{
	std::cout << "Enter the numerator: ";
	int num{ 0 };
	std::cin >> num;

	std::cout << "Enter the denominator: ";
	int den{ 0 };
	std::cin >> den;

	try
	{
		Fraction f(num, den);
		std::cout << f << '\n';
	}

	catch(std::exception)
	{
		std::cerr << "Denominator cannot be zero\n";
		exit(-1);
	}

	return 0;
}*/

//#include <array>
//#include <ctime> // for time()
//#include <cstdlib> // rand() and srand()
//
//class Card
//{
//public:
//	enum CardSuit
//	{
//		SUIT_CLUB,
//		SUIT_DIAMOND,
//		SUIT_HEART,
//		SUIT_SPADE,
//		MAX_SUITS
//	};
//
//	enum CardRank
//	{
//		RANK_2,
//		RANK_3,
//		RANK_4,
//		RANK_5,
//		RANK_6,
//		RANK_7,
//		RANK_8,
//		RANK_9,
//		RANK_10,
//		RANK_JACK,
//		RANK_QUEEN,
//		RANK_KING,
//		RANK_ACE,
//		MAX_RANKS
//	};
//
//private:
//	CardSuit m_suit;
//	CardRank m_rank;
//
//public:
//	Card(CardRank rank = CardRank::RANK_7, CardSuit suit = CardSuit::SUIT_SPADE) : m_suit(suit), m_rank(rank) {}
//
//	void printCard () const
//	{
//		switch (m_rank)
//		{
//		case RANK_2:
//			std::cout << '2'; break;
//		case RANK_3:
//			std::cout << '3'; break;
//		case RANK_4:
//			std::cout << '4'; break;
//		case RANK_5:
//			std::cout << '5'; break;
//		case RANK_6:
//			std::cout << '6'; break;
//		case RANK_7:
//			std::cout << '7'; break;
//		case RANK_8:
//			std::cout << '8'; break;
//		case RANK_9:
//			std::cout << '9'; break;
//		case RANK_10:
//			std::cout << 'T'; break;
//		case RANK_JACK:		
//			std::cout << 'J'; break;
//		case RANK_QUEEN:	
//			std::cout << 'Q'; break;
//		case RANK_KING:		
//			std::cout << 'K'; break;
//		case RANK_ACE:		
//			std::cout << 'A'; break;
//
//		default:
//			std::cout << "Err"; break;
//		}
//
//		switch (m_suit)
//		{
//		case SUIT_CLUB:
//			std::cout << 'C'; break;
//		case SUIT_DIAMOND:
//			std::cout << 'D'; break;
//		case SUIT_HEART:
//			std::cout << 'H'; break;
//		case SUIT_SPADE:
//			std::cout << 'S'; break;
//
//		default:
//			std::cout << "Err"; break;
//		}
//	}
//
//	const int getCardValue() const
//	{
//		switch (m_rank)
//		{
//		case RANK_2: return 2;
//		case RANK_3: return 3;
//		case RANK_4: return 4;
//		case RANK_5: return 5;
//		case RANK_6: return 6;
//		case RANK_7: return 7;
//		case RANK_8: return 8;
//		case RANK_9: return 9;
//		case RANK_10: return 10;
//		case RANK_JACK: return 10;
//		case RANK_QUEEN: return 10;
//		case RANK_KING: return 10;
//		case RANK_ACE: return 11;
//		
//		default:
//			return -1;
//		}
//	}
//};
//
//class Deck
//{
//private:
//	std::array<Card, 52> m_deck;
//	int m_cardIndex{ 0 };
//
//public:
//	Deck()
//	{
//		for (int card = 0; card < m_deck.size(); )
//		{
//			for (int r = 0; r < Card::MAX_RANKS; ++r)
//			{
//				for (int s = 0; s < Card::MAX_SUITS; ++s)
//				{
//					m_deck[card] = Card(static_cast<Card::CardRank>(r), static_cast<Card::CardSuit>(s));
//					++card;
//				}
//			}
//		}
//	}
//
//	void printDeck()
//	{
//		for (const auto &card : m_deck)
//		{
//			card.printCard();
//			std::cout << ' ';
//		}
//
//		std::cout << '\n';
//	}
//
//private:
//	// Generate a random number between min and max (inclusive)
//	// Assumes srand() has already been called
//	static int getRandomNumber(int min, int max)
//	{
//		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
//		// evenly distribute the random number across our range
//		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
//	}
//
//	static void swapCard(Card &a, Card &b)
//	{
//		Card temp = a;
//		a = b;
//		b = temp;
//	}
//
//public:
//	void shuffleDeck()
//	{
//		// Step through each card in the deck
//		for (int index = 0; index < 52; ++index)
//		{
//			// Pick a random card, any card
//			int swapIndex = getRandomNumber(0, 51);
//			// Swap it with the current card
//			swapCard(m_deck[index], m_deck[swapIndex]);
//		}
//
//		m_cardIndex = 0;
//	}
//
//	const Card& dealCard()
//	{
//		return m_deck[m_cardIndex++];
//	}
//};
//
//char getPlayerChoice()
//{
//	std::cout << "(h) to hit, or (s) to stand: ";
//	char choice;
//	do
//	{
//		std::cin >> choice;
//	} while (choice != 'h' && choice != 's');
//
//	return choice;
//}
//
//bool playBlackjack(Deck &deck)
//{
//	int playerTotal = 0;
//	int dealerTotal = 0;
//
//	// Deal the dealer one card
//	dealerTotal += deck.dealCard().getCardValue();
//	std::cout << "The dealer is showing: " << dealerTotal << '\n';
//
//	// Deal the player two cards
//	playerTotal += deck.dealCard().getCardValue();
//	playerTotal += deck.dealCard().getCardValue();
//
//	// Player goes first
//	while (1)
//	{
//		std::cout << "You have: " << playerTotal << '\n';
//		char choice = getPlayerChoice();
//		if (choice == 's')
//			break;
//
//		playerTotal += deck.dealCard().getCardValue();
//
//		// See if the player busted
//		if (playerTotal > 21)
//			return false;
//	}
//
//	// If player hasn't busted, dealer goes until he has at least 17 points
//	while (dealerTotal < 17)
//	{
//		dealerTotal += deck.dealCard().getCardValue();
//		std::cout << "The dealer now has: " << dealerTotal << '\n';
//	}
//
//	// If dealer busted, player wins
//	if (dealerTotal > 21)
//		return true;
//
//	return (playerTotal > dealerTotal);
//}
//
//int main()
//{
//	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
//	rand(); // If using Visual Studio, discard first random value
//
//	Deck deck;
//	deck.printDeck();
//	deck.shuffleDeck();
//	deck.printDeck();
//
//	/*std::cout << "The first card has value: " << deck.dealCard().getCardValue() << '\n';
//	std::cout << "The second card has value: " << deck.dealCard().getCardValue() << '\n';*/
//
//	if (playBlackjack(deck))
//		std::cout << "You win!\n";
//	else
//		std::cout << "You lose!\n";
//
//	return 0;
//}

// Mátrix program
/*#include <cassert>
#include <cstdlib>
#include <vector>
#include <string>

class Matrix22
{
private:
	int m_matrix[2][2];
	int m_rows = 2;
	int m_columns = 2;

public:
	// default matrix: ( 0 0 0 0 )
	Matrix22()
	{
		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_columns; ++j)
			{
				m_matrix[i][j] = 0;
			}
		}
	}

	// test matrix
	Matrix22(int n1, int n2, int n3, int n4)
	{
		m_matrix[0][0] = n1;
		m_matrix[0][1] = n2;
		m_matrix[1][0] = n3;
		m_matrix[1][1] = n4;
	}

	// overloaded out operator for 2 by 2 Matrix
	friend std::ostream& operator<<(std::ostream &out, const Matrix22 &m)
	{
		for (int i = 0; i < m.m_rows; ++i)
		{
			out << "( ";
			for (int j = 0; j < m.m_columns; ++j)
			{
				out << m.m_matrix[i][j] << ' ';
			}
			out << ")\n";
		}

		return out;
	}

	// overloaded input operator to fill up the 2 by 2 matrix
	friend std::istream& operator>>(std::istream &in, Matrix22 &m)
	{
		std::cout << "Enter the first element: ";
		in >> m.m_matrix[0][0];
		std::cout << "Enter the second element: ";
		in >> m.m_matrix[0][1];
		std::cout << "Enter the third element: ";
		in >> m.m_matrix[1][0];
		std::cout << "Enter the fourth element: ";
		in >> m.m_matrix[1][1];

		return in;
	}

	// matrix addition
	friend Matrix22 operator+(const Matrix22 &m1, const Matrix22 &m2)
	{
		Matrix22 temp;

		temp.m_matrix[0][0] = m1.m_matrix[0][0] + m2.m_matrix[0][0];
		temp.m_matrix[0][1] = m1.m_matrix[0][1] + m2.m_matrix[0][1];
		temp.m_matrix[1][0] = m1.m_matrix[1][0] + m2.m_matrix[1][0];
		temp.m_matrix[1][1] = m1.m_matrix[1][1] + m2.m_matrix[1][1];

		return temp;
	}

	// matrix multiplication by another matrix
	friend Matrix22 operator*(const Matrix22 &m1, const Matrix22 &m2)
	{
		Matrix22 temp;

		temp.m_matrix[0][0] = (m1.m_matrix[0][0] * m2.m_matrix[0][0]) + (m1.m_matrix[0][1] * m2.m_matrix[1][0]);
		temp.m_matrix[0][1] = (m1.m_matrix[0][0] * m2.m_matrix[0][1]) + (m1.m_matrix[0][1] * m2.m_matrix[1][1]);
		temp.m_matrix[1][0] = (m1.m_matrix[1][0] * m2.m_matrix[0][0]) + (m1.m_matrix[1][1] * m2.m_matrix[1][0]);
		temp.m_matrix[1][1] = (m1.m_matrix[1][0] * m2.m_matrix[0][1]) + (m1.m_matrix[1][1] * m2.m_matrix[1][1]);

		return temp;
	}

	// matrix multiplication by int
	friend Matrix22& operator*(int n, Matrix22 &m)
	{
		m.m_matrix[0][0] *= n;
		m.m_matrix[0][1] *= n;
		m.m_matrix[1][0] *= n;
		m.m_matrix[1][1] *= n;

		return m;
	}

	// determinant calculator
	int det()
	{
		int det{ 0 };

		det = (m_matrix[0][0] * m_matrix[1][1]) - (m_matrix[1][0] * m_matrix[0][1]);

		return det;
	}

	// matrix invert
	Matrix22 invert()
	{
		Matrix22 invertMatrix;
		int det = this->det();
		Matrix22 tMatrix;
		Matrix22 adjMatrix;

		if (det == 0)
		{
			std::cout << "The matrix cannot be inverted.\n";
			return invertMatrix;
		}

		tMatrix.m_matrix[0][0] = this->m_matrix[0][0];
		tMatrix.m_matrix[0][1] = this->m_matrix[1][0];
		tMatrix.m_matrix[1][0] = this->m_matrix[0][1];
		tMatrix.m_matrix[1][1] = this->m_matrix[1][1];

		adjMatrix.m_matrix[0][0] = tMatrix.m_matrix[1][1];
		adjMatrix.m_matrix[0][1] = -(tMatrix.m_matrix[1][0]);
		adjMatrix.m_matrix[1][0] = -(tMatrix.m_matrix[0][1]);
		adjMatrix.m_matrix[1][1] = tMatrix.m_matrix[0][0];

		invertMatrix.m_matrix[0][0] = (1 / det) * adjMatrix.m_matrix[0][0];
		invertMatrix.m_matrix[0][1] = (1 / det) * adjMatrix.m_matrix[0][1];
		invertMatrix.m_matrix[1][0] = (1 / det) * adjMatrix.m_matrix[1][0];
		invertMatrix.m_matrix[1][1] = (1 / det) * adjMatrix.m_matrix[1][1];

		return invertMatrix;
	}
};

int main()
{

	return 0;
}*/

/*#include <string>

template <typename T>
class Pair1
{
private:
	T m_v1;
	T m_v2;

public:
	Pair1(T v1, T v2) : m_v1(v1), m_v2(v2) {}

	~Pair1() {}

	T first() { return m_v1; }
	T second() { return m_v2; }

	T first() const { return m_v1; }
	T second() const { return m_v2; }
};

template <typename T1, typename T2>
class Pair
{
private:
	T1 m_v1;
	T2 m_v2;

public:
	Pair(T1 v1, T2 v2) : m_v1(v1), m_v2(v2) {}

	~Pair() {}

	T1 first() { return m_v1; }
	T2 second() { return m_v2; }

	T1 first() const { return m_v1; }
	T2 second() const { return m_v2; }
};

template <typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(std::string str, T v) : Pair<std::string, T>(str, v)
	{}
};

int main()
{
	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}*/

// selection sort

/*#include <utility>

void selectionSort(int array[], int lArray)
{
	for (int startIndex = 0; startIndex < lArray - 1; ++startIndex)
	{
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < lArray; ++currentIndex)
		{
			if (array[currentIndex] < array[smallestIndex])
				smallestIndex = currentIndex;
		}

		std::swap(array[startIndex], array[smallestIndex]);
	}
}

int main()
{
	int array[]{ 0, 23, 12, 8, 5, 99, 21, 82, 84, 11 };
	int lArray = sizeof(array) / sizeof(array[0]);

	for (int i = 0; i < lArray; ++i)
		std::cout << array[i] << ' ';

	std::cout << '\n';
	selectionSort(array, lArray);

	for (int i = 0; i < lArray; ++i)
		std::cout << array[i] << ' ';

	return 0;
}*/

/*template <typename T>
T permutation(T number)
{
	if (number > 1)
		return number * permutation(number - 1);
	if (number <= 1)
		return 1;
	else
		return -1;
}

template <typename T>
T variation(T firstNumber, T secondNumber)
{
	return (permutation(firstNumber) / (permutation(firstNumber - secondNumber)));
}

template <typename T>
T combination(T firstNumber, T secondNumber)
{
	return (permutation(firstNumber) / (permutation(firstNumber - secondNumber) * permutation(secondNumber)));
}

int main()
{
	std::cout << permutation(5) << '\n';
	std::cout << variation(5, 3) << '\n';
	std::cout << combination(5, 3) << '\n';

	return 0;
}*/

/*#include <cstdlib>
#include <fstream>
#include <string>

int countWords(std::istream& file)
{
	int count = 0;
	for (std::string word; file >> word; ++count) {}
	return count;
}

int main()
{
	using namespace std;

	ifstream file("sample.txt");

	if (!file)
	{
		cerr << "File could not be opened for reading\n";
		exit(-1);
 	}

	std::cout << "The number of words in the document: " << countWords(file) << '\n';

	return 0;
}*/

// teljesen működő matrix

//#include <cassert>
//#include <cstdlib>
//#include <string>
//#include <exception>
//
//class Matrix22
//{
//private:
//	int m_matrix[2][2];
//	int m_rows = 2;
//	int m_columns = 2;
//
//public:
//	// default matrix: ( 0 0 0 0 )
//	Matrix22()
//	{
//		for (int i = 0; i < m_rows; ++i)
//		{
//			for (int j = 0; j < m_columns; ++j)
//			{
//				m_matrix[i][j] = 0;
//			}
//		}
//	}
//
//	// test matrix
//	Matrix22(int n1, int n2, int n3, int n4)
//	{
//		m_matrix[0][0] = n1;
//		m_matrix[0][1] = n2;
//		m_matrix[1][0] = n3;
//		m_matrix[1][1] = n4;
//	}
//
//	// overloaded out operator for 2 by 2 Matrix
//	friend std::ostream& operator<<(std::ostream &out, const Matrix22 &m)
//	{
//		for (int i = 0; i < m.m_rows; ++i)
//		{
//			out << "( ";
//			for (int j = 0; j < m.m_columns; ++j)
//			{
//				out << m.m_matrix[i][j] << ' ';
//			}
//			out << ")\n";
//		}
//
//		return out;
//	}
//
//	// overloaded input operator to fill up the 2 by 2 matrix
//	friend std::istream& operator>>(std::istream &in, Matrix22 &m)
//	{
//		std::cout << "Enter the first element: ";
//		in >> m.m_matrix[0][0];
//		std::cout << "Enter the second element: ";
//		in >> m.m_matrix[0][1];
//		std::cout << "Enter the third element: ";
//		in >> m.m_matrix[1][0];
//		std::cout << "Enter the fourth element: ";
//		in >> m.m_matrix[1][1];
//
//		return in;
//	}
//
//	// matrix addition
//	friend Matrix22 operator+(const Matrix22 &m1, const Matrix22 &m2)
//	{
//		Matrix22 temp;
//
//		temp.m_matrix[0][0] = m1.m_matrix[0][0] + m2.m_matrix[0][0];
//		temp.m_matrix[0][1] = m1.m_matrix[0][1] + m2.m_matrix[0][1];
//		temp.m_matrix[1][0] = m1.m_matrix[1][0] + m2.m_matrix[1][0];
//		temp.m_matrix[1][1] = m1.m_matrix[1][1] + m2.m_matrix[1][1];
//
//		return temp;
//	}
//
//	// matrix multiplication by another matrix
//	friend Matrix22 operator*(const Matrix22 &m1, const Matrix22 &m2)
//	{
//		Matrix22 temp;
//
//		temp.m_matrix[0][0] = (m1.m_matrix[0][0] * m2.m_matrix[0][0]) + (m1.m_matrix[0][1] * m2.m_matrix[1][0]);
//		temp.m_matrix[0][1] = (m1.m_matrix[0][0] * m2.m_matrix[0][1]) + (m1.m_matrix[0][1] * m2.m_matrix[1][1]);
//		temp.m_matrix[1][0] = (m1.m_matrix[1][0] * m2.m_matrix[0][0]) + (m1.m_matrix[1][1] * m2.m_matrix[1][0]);
//		temp.m_matrix[1][1] = (m1.m_matrix[1][0] * m2.m_matrix[0][1]) + (m1.m_matrix[1][1] * m2.m_matrix[1][1]);
//
//		return temp;
//	}
//
//	// matrix multiplication by int
//	friend Matrix22& operator*(int n, Matrix22 &m)
//	{
//		m.m_matrix[0][0] *= n;
//		m.m_matrix[0][1] *= n;
//		m.m_matrix[1][0] *= n;
//		m.m_matrix[1][1] *= n;
//
//		return m;
//	}
//
//	// determinant calculator
//	int det()
//	{
//		int det{ 0 };
//
//		det = (m_matrix[0][0] * m_matrix[1][1]) - (m_matrix[1][0] * m_matrix[0][1]);
//
//		return det;
//	}
//
//	// matrix invert
//	Matrix22 invert()
//	{
//		Matrix22 invertMatrix;
//		int det = this->det();
//		Matrix22 tMatrix;
//		Matrix22 adjMatrix;
//
//		if (det == 0)
//		{
//			std::cout << "The matrix cannot be inverted.\n";
//			return invertMatrix;
//		}
//
//		tMatrix.m_matrix[0][0] = this->m_matrix[0][0];
//		tMatrix.m_matrix[0][1] = this->m_matrix[1][0];
//		tMatrix.m_matrix[1][0] = this->m_matrix[0][1];
//		tMatrix.m_matrix[1][1] = this->m_matrix[1][1];
//
//		adjMatrix.m_matrix[0][0] = tMatrix.m_matrix[1][1];
//		adjMatrix.m_matrix[0][1] = -(tMatrix.m_matrix[1][0]);
//		adjMatrix.m_matrix[1][0] = -(tMatrix.m_matrix[0][1]);
//		adjMatrix.m_matrix[1][1] = tMatrix.m_matrix[0][0];
//
//		invertMatrix.m_matrix[0][0] = (1 / det) * adjMatrix.m_matrix[0][0];
//		invertMatrix.m_matrix[0][1] = (1 / det) * adjMatrix.m_matrix[0][1];
//		invertMatrix.m_matrix[1][0] = (1 / det) * adjMatrix.m_matrix[1][0];
//		invertMatrix.m_matrix[1][1] = (1 / det) * adjMatrix.m_matrix[1][1];
//
//		return invertMatrix;
//	}
//};
//
//class Matrix33
//{
//private:
//	int m_matrix[3][3];
//	int m_rows = 3;
//	int m_columns = 3;
//
//public:
//	Matrix33()
//	{
//		for (int i = 0; i < m_rows; ++i)
//		{
//			for (int j = 0; j < m_columns; ++j)
//			{
//				m_matrix[i][j] = 0;
//			}
//		}
//	}
//
//	// overloaded out operator for 3 by 3 Matrix
//	friend std::ostream& operator<<(std::ostream &out, const Matrix33 &m)
//	{
//		for (int i = 0; i < m.m_rows; ++i)
//		{
//			out << "( ";
//			for (int j = 0; j < m.m_columns; ++j)
//			{
//				out << m.m_matrix[i][j] << ' ';
//			}
//			out << ")\n";
//		}
//
//		return out;
//	}
//};
//
class MatrixException : public std::exception
{
private:
	std::string m_error;

public:
	MatrixException(std::string error) : m_error(error)
	{}

	const char* what() const noexcept { return m_error.c_str(); }
};

class Matrix
{
private:
	int m_rows = 3;
	int m_columns = 3;
	double(*m_matrix)[3] = new double[3][3];

	// special case to display accurately determinant
	double Sdeterminant()
	{
		double determinant{ 0 };
		return determinant = ((this->m_matrix[0][0] * this->m_matrix[1][1]) - (this->m_matrix[0][1] * this->m_matrix[1][0]));
	}

public:
	Matrix()
	{
		std::cout << "Enter the number of rows: ";
		std::cin >> m_rows;
		std::cout << "Enter the number of columns: ";
		std::cin >> m_columns;

		int elem = 1;
		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_columns; ++j)
			{
				std::cout << "Enter the " << elem << ". element: ";
				std::cin >> m_matrix[i][j];
				++elem;
			}
		}
	}
	Matrix(int rows, int columns) : m_rows(rows), m_columns(columns)
	{
		assert(m_rows <= 3 && m_columns <= 3);

		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_columns; ++j)
			{
				m_matrix[i][j] = 0;
			}
		}
	}
	Matrix(const Matrix &m) : m_rows(m.m_rows), m_columns(m.m_columns)
	{
		for (int i = 0; i < this->m_rows; ++i)
		{
			for (int j = 0; j < this->m_columns; ++j)
			{
				this->m_matrix[i][j] = m.m_matrix[i][j];
			}
		}
	}
	Matrix(const Matrix *m) : m_rows(m->m_rows), m_columns(m->m_columns)
	{
		for (int i = 0; i < this->m_rows; ++i)
		{
			for (int j = 0; j < this->m_columns; ++j)
			{
				this->m_matrix[i][j] = m->m_matrix[i][j];
			}
		}
	}

	~Matrix() { delete[] m_matrix; }

	bool isNull()
	{
		for (int i = 0; i < this->m_rows; ++i)
		{
			for (int j = 0; j < this->m_columns; ++i)
			{
				if (this->m_matrix[i][j] != 0)
					return false;
			}
		}

		return true;
	}
	void edit()
	{
		std::cout << "Edit serial number syntax: \n";
		int elem{ 1 };
		for (int x = 0; x < this->m_rows; ++x)
		{
			std::cout << "( ";
			for (int y = 0; y < this->m_columns; ++y)
			{
				std::cout << elem++ << ' ';
			}
			std::cout << ")\n";
		}
		
		std::cout << '\n';

		std::cout << "Enter the serial number of the element you want to edit: ";
		int element{ 0 };
		std::cin >> element;

		std::cout << "Enter the new value: ";
		double value{ 0 };
		std::cin >> value;

		int serial = 1;
		for (int i = 0; i < this->m_rows; ++i)
		{
			for (int j = 0; j < this->m_columns; ++j)
			{
				if (serial == element)
				{
					this->m_matrix[i][j] = value;
					return;
				}
				++serial;
			}
		}
	}
	int numberOfElements()
	{
		return this->m_rows*this->m_columns;
	}

	friend std::ostream& operator<<(std::ostream &out, const Matrix &m)
	{
		for (int i = 0; i < m.m_rows; ++i)
		{
			out << "( ";
			for (int j = 0; j < m.m_columns; ++j)
			{
				out << m.m_matrix[i][j] << ' ';
			}
			out << ")\n";
		}

		return out;
	}
	friend std::istream& operator>>(std::istream &in, Matrix &m)
	{
		int elem = 1;
		for (int i = 0; i < m.m_rows; ++i)
		{
			for (int j = 0; j < m.m_columns; ++j)
			{
				std::cout << "Enter the " << elem << ". element: ";
				in >> m.m_matrix[i][j];
				++elem;
			}
		}

		return in;
	}

	friend Matrix operator+(const Matrix &m1, const Matrix &m2)
	{
		if ((m1.m_rows != m2.m_rows) && (m1.m_columns != m2.m_columns))
			throw MatrixException("Invalid addition, different rows and columns");

		Matrix _matrix(m2.m_rows, m2.m_columns);

		for (int i = 0; i < _matrix.m_rows; ++i)
		{
			for (int j = 0; j < _matrix.m_rows; ++j)
				_matrix.m_matrix[i][j] = m1.m_matrix[i][j] + m2.m_matrix[i][j];
		}


		return _matrix;
	}
	friend Matrix operator-(const Matrix &m1, const Matrix &m2)
	{
		/*if ((m1.m_rows != m2.m_rows) && (m1.m_columns != m2.m_columns))
			throw MatrixException("Invalid subtraction, different rows and columns");

		Matrix _matrix(m2.m_rows, m2.m_columns);

		for (int i = 0; i < _matrix.m_rows; ++i)
		{
			for (int j = 0; j < _matrix.m_rows; ++j)
				_matrix.m_matrix[i][j] = m1.m_matrix[i][j] - m2.m_matrix[i][j];
		}


		return _matrix;*/

		// vagy

		return m1 + (-1 * m2);
	}
	friend Matrix operator*(const Matrix &m1, const Matrix &m2)
	{
		Matrix _matrix(m2.m_rows, m2.m_columns);

		for (int i = 0; i < m2.m_rows; ++i)
		{
			for (int j = 0; j < m2.m_columns; ++j)
			{
				if (m2.m_columns <= m1.m_columns)
					for (int u = 0; u < m2.m_rows; ++u)
						_matrix.m_matrix[i][j] += m1.m_matrix[i][u] * m2.m_matrix[u][j];
				if (m1.m_columns != m2.m_rows)
					throw MatrixException("The number of columns in the first matrix should be equal to the number of rows in the second");
			}
		}

		return _matrix;
	}
	friend Matrix operator*(int number, const Matrix &m)
	{
		Matrix _matrix(m.m_rows, m.m_columns);

		for (int i = 0; i < _matrix.m_rows; ++i)
		{
			for (int j = 0; j < _matrix.m_columns; ++j)
			{
				_matrix.m_matrix[i][j] = number * m.m_matrix[i][j];
			}
		}

		return _matrix;
	}
	Matrix operator=(const Matrix &m)
	{
		if (this == &m)
			return *this;

		if ((this->m_rows == m.m_rows) && (this->m_columns == m.m_columns))
		{
			for (int i = 0; i < this->m_rows; ++i)
			{
				for (int j = 0; j < this->m_columns; ++j)
				{
					this->m_matrix[i][j] = m.m_matrix[i][j];
				}
			}
		}
		else
			throw MatrixException("Invalid assignment");

		return *this;
	}
	friend Matrix operator^(Matrix &m, int power)
	{
		if (power == 1)
			return m;

		if (power == 0)
		{
			if (m.m_columns == 1 && m.m_rows == 1)
			{
				Matrix _matrix(1, 1);

				_matrix.m_matrix[0][0] = 1;

				return _matrix;
			}

			if (m.m_columns == 2 || m.m_rows == 2)
			{
				Matrix _matrix(2, 2);

				for (int i = 0; i < _matrix.m_columns; ++i)
				{
					_matrix.m_matrix[i][i] = 1;
				}

				return _matrix;
			}

			if (m.m_columns == 3 || m.m_columns == 3)
			{
				Matrix _matrix(3, 3);

				for (int i = 0; i < _matrix.m_columns; ++i)
				{
					_matrix.m_matrix[i][i] = 1;
				}

				return _matrix;
			}
		}

		if (power >= 2)
		{
			Matrix _matrix(m);
			for (int i = 2; i <= power; ++i)
				m = (m * _matrix);
		}

		return m;
	}

	double determinant()
	{
		if (this->m_rows != this->m_columns)
			throw MatrixException("Cannot take determinant of uneven matrix");

		double determinant{ 0 };
		if (this->m_rows == 2 && this->m_columns == 2)
		{
			for (int i = 0; i < this->m_rows; ++i)
			{
				std::cout << "| ";
				for (int j = 0; j < this->m_columns; ++j)
				{
					std::cout << this->m_matrix[i][j] << ' ';
				}
				if (i < (this->m_rows - 1))
					std::cout << "|\n";
				else
					std::cout << "| = ";
			}

			determinant = ((this->m_matrix[0][0] * this->m_matrix[1][1]) - (this->m_matrix[0][1] * this->m_matrix[1][0]));
		}

		if (this->m_rows == 3 && this->m_columns == 3)
		{
			Matrix submatrix(2, 2);
			for (int x = 0; x < this->m_rows; x++) 
			{
				int subi = 0;
				for (int i = 1; i < this->m_columns; i++) 
				{
					int subj = 0;
					for (int j = 0; j < this->m_columns; j++) 
					{
						if (j == x)
							continue;
						submatrix.m_matrix[subi][subj] = this->m_matrix[i][j];
						subj++;
					}
					subi++;
				}
				determinant = determinant + (pow(-1, x) * this->m_matrix[0][x] * submatrix.Sdeterminant());
			}

				for (int i = 0; i < this->m_rows; ++i)
				{
					std::cout << "| ";
					for (int j = 0; j < this->m_columns; ++j)
					{
						std::cout << this->m_matrix[i][j] << ' ';
					}
					if (i < (this->m_rows - 1))
						std::cout << "|\n";
					else
						std::cout << "| = ";
				}
		}

		return determinant;
	}

	int rank()
	{
		int rank{ 3 };

		// speciális esetek
		if (this->isNull())
			return rank - 3;
		if (this->m_rows == 2 && this->m_columns == 1)
			return rank - 2;
		if (this->m_rows == 3 && this->m_columns == 1)
			return rank - 2;
		if (this->m_rows == 1 && this->m_columns == 2)
			return rank - 2;
		if (this->m_rows == 1 && this->m_columns == 3)
			return rank - 2;
		
		// normál eset
		if (this->determinant() == 0)
		{
			if (this->m_rows == 3 && this->m_columns == 3)
			{
				if (this->isNull())
					return rank - 3;

				Matrix submatrix(2, 2);
				for (int x = 0; submatrix.determinant() == 0; x++)
				{
					int subi = 0;
					for (int i = 1; i < this->m_columns; i++)
					{
						int subj = 0;
						for (int j = 0; j < this->m_columns; j++)
						{
							if (j == x)
								continue;
							submatrix.m_matrix[subi][subj] = this->m_matrix[i][j];
							subj++;
						}
						subi++;
					}
				}

				if (submatrix.determinant() != 0)
					return rank - 1;

				if (submatrix.determinant() == 0)
				{
					if (!(this->isNull()))
						return rank - 2;
					else
						return rank - 3;
				}
			}

			if (this->m_rows == 2 && this->m_columns == 2)
				if (!(this->isNull()))
					return rank - 2;
				else
					return rank - 3;

		}
		else
		{
			if (this->m_rows == 3 && this->m_columns == 3)
				return rank;
			if (this->m_rows == 2 && this->m_columns == 2)
				return rank - 1;
			if (this->m_rows == 1 && this->m_columns == 1)
				return rank - 2;
		}

		throw MatrixException("Problem with rank");
	}

	Matrix transponalt()
	{
		Matrix _matrix(this);

		for (int i = 0; i < this->m_rows; ++i)
		{
			for (int j = 0; j < this->m_columns; ++j)
			{
				_matrix.m_matrix[i][j] = this->m_matrix[j][i];
			}
		}

		return _matrix;
	}
	Matrix coFactor(int p, int q)
	{
		Matrix submatrix(2, 2);

		int i = 0, j = 0;
		for (int row = 0; row < this->m_rows; row++)
		{
			for (int col = 0; col < this->m_columns; col++)
			{
				if (row != p && col != q)
				{
					submatrix.m_matrix[i][j++] = this->transponalt().m_matrix[row][col];

					if (j == this->m_rows - 1)
					{
						j = 0;
						i++;
					}
				}
			}
		}

		return submatrix;
	}
	Matrix adjoint()
	{
		if (this->m_rows != this->m_columns)
			throw MatrixException("Invalid adjungalt: uneven matrix");

		Matrix _matrix(this);


		if (this->m_rows == 2 && this->m_columns == 2)
		{
			int x = 1;
			for (int i = 0; i < this->m_rows; ++i)
			{
				int y = 1;
				for (int j = 0; j < this->m_columns; ++j)
				{
					_matrix.m_matrix[i][j] = pow(-1, i+j) * this->transponalt().m_matrix[x][y];
					--y;
				}
				--x;
			}
		}

		if (this->m_rows == 3 && this->m_columns == 3)
		{
			for (int i = 0; i < this->m_rows; ++i)
			{
				for (int j = 0; j < this->m_columns; ++j)
				{
					_matrix.m_matrix[i][j] = pow(-1, i+j) * (this->coFactor(i, j).determinant());
				}
			}
		}

		return _matrix;
	}
	Matrix invert()
	{
		if (this->determinant() == 0)
			throw MatrixException("Determinant = 0, matrix is not invertible");

		Matrix _matrix(this);

		for (int i = 0; i < this->m_rows; ++i)
		{
			for (int j = 0; j < this->m_columns; ++j)
			{
				_matrix.m_matrix[i][j] = ((1 / this->determinant()) * this->adjoint().m_matrix[i][j]);
			}
		}

		return _matrix;
	}
};

//int main()
//{
//	try 
//	{
//		Matrix matrix;
//
//		std::cout << matrix;
//
//		std::cout << matrix.determinant();
//	}
//
//	catch (std::exception &e)
//	{
//		std::cerr << "Exception caught: " << e.what() << '\n';
//	}
//
//	return 0;
//}

/*#include <vector>
#include <iostream>
#include <string>

using namespace std;
class Students
{
private:
	struct Student
	{
		string s_name;
		double s_grade;
	};

	Student *m_students = new Student[99];
	int m_numberOfStudents;

public:
	Students() : m_numberOfStudents(0)
	{
		std::cout << "You created a new 'Students' block.\n";
	}

	friend istream& operator>>(istream& in, Students& s)
	{
		std::cout << "Enter the name of the student: ";
		string name;
		in >> name;
		std::cout << "Enter the grade of the student: ";
		double grade;
		in >> grade;

		s.m_students[s.m_numberOfStudents].s_name = name;
		s.m_students[s.m_numberOfStudents].s_grade = grade;

		++s.m_numberOfStudents;
		return in;
	}

	friend ostream& operator<<(ostream& out, const Students& s)
	{
		for (int i = 0; i < s.m_numberOfStudents; ++i)
		{
			out << s.m_students[i].s_name << " has got " << s.m_students[i].s_grade << '\n';
		}

		return out;
	}

	double numberOfStudents() const
	{
		return m_numberOfStudents;
	}
};

int main(void)
{
	Students students;

	cin >> students;

	cout << students;

	cout << students.numberOfStudents();

	return 0;
}*/


/*#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <random>
#include <time.h>
#include <cassert>
#include <exception>
#include <fstream>
#include <stdio.h>*/

// kártyajáték
/*class gameException : public std::exception
{
private:
	std::string m_error;

public:
	gameException(std::string error): m_error(error) {}

	const char* what() noexcept { return m_error.c_str(); }
};

class Card
{
protected:
	enum class CardSuit
	{
		SUIT_CLUB,
		SUIT_HEART,
		SUIT_SPADE,
		SUIT_DIAMOND,
		MAX_SUITS,
	};
	enum class CardRank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_J,
		RANK_Q,
		RANK_K,
		RANK_A,
		MAX_RANKS,
	};

private:
	CardRank m_rank;
	CardSuit m_suit;

public:
	Card(CardRank rank = CardRank::RANK_7, CardSuit suit = CardSuit::SUIT_CLUB) : m_rank(rank), m_suit(suit) {}
	~Card() {}

	friend std::ostream& operator<<(std::ostream& out, const Card& c)
	{
		switch (c.m_rank)
		{
		case CardRank::RANK_2:		out << '2'; break;
		case CardRank::RANK_3:		out << '3'; break;
		case CardRank::RANK_4:		out << '4'; break;
		case CardRank::RANK_5:		out << '5'; break;
		case CardRank::RANK_6:		out << '6'; break;
		case CardRank::RANK_7:		out << '7'; break;
		case CardRank::RANK_8:		out << '8'; break;
		case CardRank::RANK_9:		out << '9'; break;
		case CardRank::RANK_10:		out << 'T'; break;
		case CardRank::RANK_J:		out << 'J'; break;
		case CardRank::RANK_Q:		out << 'Q'; break;
		case CardRank::RANK_K:		out << 'K'; break;
		case CardRank::RANK_A:		out << 'A'; break;
		}

		switch (c.m_suit)
		{
		case CardSuit::SUIT_CLUB:		out << 'C'; break;
		case CardSuit::SUIT_DIAMOND:	out << 'D'; break;
		case CardSuit::SUIT_HEART:	out << 'H'; break;
		case CardSuit::SUIT_SPADE:	out << 'S'; break;
		}

		return out;
	}

	int getCardValue() const 
	{
		switch (this->m_rank)
		{
		case CardRank::RANK_2:		return 2;
		case CardRank::RANK_3:		return 3;
		case CardRank::RANK_4:		return 4;
		case CardRank::RANK_5:		return 5;
		case CardRank::RANK_6:		return 6;
		case CardRank::RANK_7:		return 7;
		case CardRank::RANK_8:		return 8;
		case CardRank::RANK_9:		return 9;
		case CardRank::RANK_10:		return 10;
		case CardRank::RANK_J:		return 10;
		case CardRank::RANK_Q:		return 10;
		case CardRank::RANK_K:		return 10;
		case CardRank::RANK_A:		return 11;
		}

		return 0;
	}
};

class Deck : public Card
{
protected:
	std::array<Card, 52> m_deck;
	int m_cardIndex = 0;

	int getRandomNumber (int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
	void swapCard (Card& a, Card& b)
	{
		Card temp;
		temp = a;
		a = b;
		b = temp;
	}

public:
	Deck() : m_cardIndex(0)
	{
		int card = 0;
		for (int suit = 0; suit < static_cast<int>(Card::CardSuit::MAX_SUITS); ++suit)
			for (int rank = 0; rank < static_cast<int>(Card::CardRank::MAX_RANKS); ++rank)
				m_deck[card++] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
	}

	friend std::ostream& operator<<(std::ostream& out, const Deck& d)
	{
		for (int card = 0; card < 52; ++card)
			out << d.m_deck[card];

		return out;
	}

	void shuffleDeck() 
	{
		for (int i = 0; i < 52; ++i)
		{
			int swapIndex = getRandomNumber(0, 51);

			swapCard(m_deck[i], m_deck[swapIndex]);
		}

		this->m_cardIndex = 0;
	}

	const Card& dealCard()
	{
		assert(this->m_cardIndex < 52);
		return this->m_deck[m_cardIndex++];
	}
};

class BlackJack : public Deck
{
protected:
	bool getPlayerChoice()
	{
		bool playerChoice = false;
		char button = 'A';

		while (1)
		{
			std::cout << "Press 'H' to hit, and 'S' to stand.\n";
			std::cin >> button;

			if (button == 'H' || button == 'h')
				return true;
			if (button == 'S' || button == 's')
				return false;
		}
	}
	Deck bDeck;

public:
	BlackJack()
	{
		bDeck.shuffleDeck();
		///std::cout << bDeck; // teszt
	}

	void play()
	{
		int playerPoints{ 0 };
		int dealerPoints{ 0 };

		// először egy kártya az osztónak
		dealerPoints += bDeck.dealCard().getCardValue();
		std::cout << "The dealer is showing: " << dealerPoints << '\n';

		// két kártya a játékosnak
		playerPoints += bDeck.dealCard().getCardValue();
		playerPoints += bDeck.dealCard().getCardValue();
		std::cout << "You have: " << playerPoints << '\n';



		while (getPlayerChoice())
		{
			playerPoints += bDeck.dealCard().getCardValue();
			std::cout << "You have: " << playerPoints << '\n';
			
			if (playerPoints > 21)
			{
				std::cout << "You lost!\n";
				return;
			}
		}

		while (dealerPoints < 17)
		{
			dealerPoints += bDeck.dealCard().getCardValue();
			std::cout << "The dealer is showing: " << dealerPoints << '\n';
		}

		if (playerPoints > dealerPoints)
			std::cout << "You won!\n";
		else if (playerPoints == dealerPoints)
			std::cout << "It's a draw!\n";
		else
			std::cout << "You lost!\n";

		std::cout << "\nYou have " << playerPoints << ".\n" << "The dealer has " << dealerPoints << ".\n";
	}
};

class Poker : public Deck
{
protected:
	bool getPlayerChoice()
	{
		bool playerChoice = false;
		char button = 'A';

		while (1)
		{
			std::cout << "Press 'H' to hit, and 'S' to stand.\n";
			std::cin >> button;

			if (button == 'H' || button == 'h')
				return true;
			if (button == 'S' || button == 's')
				return false;
		}
	}

	Deck pDeck;

public:
	Poker()
	{
		pDeck.shuffleDeck();
		std::cout << pDeck; // teszt
	}

public:
	Poker()
	{
		Deck pDeck;
		pDeck.shuffleDeck();
	}

	void play()
	{

	}
};

int main(void)
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	BlackJack game;

	game.play();

	return 0;
}*/

/*using namespace std;

// Helper function for textual date and time.
// DTTMSZ must allow extra character for the null terminator.

#define DTTMFMT "%Y-%m-%d %H:%M:%S "
#define DTTMSZ 21
static char* getDtTm(char* buff) {
	time_t t = time(0);
	strftime(buff, DTTMSZ, DTTMFMT, localtime(&t));
	return buff;
}

class GameException : public std::exception
{
private:
	std::string m_error;

public:
	GameException(std::string error = "Err") : m_error(error) {}

	const char* what() { return m_error.c_str(); }

	const std::string logMessage() { return m_error; }
};

class GameLog : public GameException
{
private:
	std::ofstream m_logger;
	std::string m_logMessage;
	char m_buff[DTTMSZ];


public:
	GameLog()
	{
		m_logger = std::ofstream("log.txt", std::ios::app);
	}

	~GameLog()
	{
		m_logger.close();
	}

	void writeLog(std::string logMessage)
	{
		m_logMessage = logMessage;
		m_logger << getDtTm(m_buff);
		m_logger << m_logMessage << std::endl;
		m_logger.close();
	}

	void readLog()
	{
		std::ifstream readLog("log.txt");

		while (readLog)
		{
			std::string strInput;
			std::getline(readLog, strInput);
			std::cout << strInput << std::endl;
		}
	}
};

class Card
{
public:
	enum CardRank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_J,
		RANK_Q,
		RANK_K,
		RANK_A,
		MAX_RANKS,
	};
	enum CardSuit
	{
		SUIT_SPADE,
		SUIT_CLUB,
		SUIT_HEART,
		SUIT_DIAMOND,
		MAX_SUITS,
	};

protected:
	CardRank m_rank;
	CardSuit m_suit;

public:
	Card(CardRank rank = RANK_7, CardSuit suit = SUIT_SPADE) : m_rank(rank), m_suit(suit) {}
	
	friend std::ostream& operator<<(std::ostream& out, const Card& c)
	{
		switch (c.m_rank)
		{
		case CardRank::RANK_2:		out << '2'; break;
		case CardRank::RANK_3:		out << '3'; break;
		case CardRank::RANK_4:		out << '4'; break;
		case CardRank::RANK_5:		out << '5'; break;
		case CardRank::RANK_6:		out << '6'; break;
		case CardRank::RANK_7:		out << '7'; break;
		case CardRank::RANK_8:		out << '8'; break;
		case CardRank::RANK_9:		out << '9'; break;
		case CardRank::RANK_10:		out << 'T'; break;
		case CardRank::RANK_J:		out << 'J'; break;
		case CardRank::RANK_Q:		out << 'Q'; break;
		case CardRank::RANK_K:		out << 'K'; break;
		case CardRank::RANK_A:		out << 'A'; break;
		}

		switch (c.m_suit)
		{
		case CardSuit::SUIT_CLUB:		out << 'C'; break;
		case CardSuit::SUIT_DIAMOND:	out << 'D'; break;
		case CardSuit::SUIT_HEART:		out << 'H'; break;
		case CardSuit::SUIT_SPADE:		out << 'S'; break;
		}

		return out;
	}

	int getCardValue() const 
	{
		switch (m_rank)
		{
		case CardRank::RANK_2:		return 2;
		case CardRank::RANK_3:		return 3;
		case CardRank::RANK_4:		return 4;
		case CardRank::RANK_5:		return 5;
		case CardRank::RANK_6:		return 6;
		case CardRank::RANK_7:		return 7;
		case CardRank::RANK_8:		return 8;
		case CardRank::RANK_9:		return 9;
		case CardRank::RANK_10:		return 10;
		case CardRank::RANK_J:		return 10;
		case CardRank::RANK_Q:		return 10;
		case CardRank::RANK_K:		return 10;
		case CardRank::RANK_A:		return 11;
		}

		return 0;
	}
	std::string returnCardStr()
	{
		std::string cardStr{ "7S" };
		switch (m_rank)
		{
		case CardRank::RANK_2:		cardStr.erase(); cardStr.append("2"); break;
		case CardRank::RANK_3:		cardStr.erase(); cardStr.append("3"); break;
		case CardRank::RANK_4:		cardStr.erase(); cardStr.append("4"); break;
		case CardRank::RANK_5:		cardStr.erase(); cardStr.append("5"); break;
		case CardRank::RANK_6:		cardStr.erase(); cardStr.append("6"); break;
		case CardRank::RANK_7:		cardStr.erase(); cardStr.append("7"); break;
		case CardRank::RANK_8:		cardStr.erase(); cardStr.append("8"); break;
		case CardRank::RANK_9:		cardStr.erase(); cardStr.append("9"); break;
		case CardRank::RANK_10:		cardStr.erase(); cardStr.append("10"); break;
		case CardRank::RANK_J:		cardStr.erase(); cardStr.append("J"); break;
		case CardRank::RANK_Q:		cardStr.erase(); cardStr.append("Q"); break;
		case CardRank::RANK_K:		cardStr.erase(); cardStr.append("K"); break;
		case CardRank::RANK_A:		cardStr.erase(); cardStr.append("A"); break;
		}

		switch (m_suit)
		{
		case CardSuit::SUIT_CLUB:		cardStr.append("C"); break;
		case CardSuit::SUIT_DIAMOND:	cardStr.append("D"); break;
		case CardSuit::SUIT_HEART:		cardStr.append("H"); break;
		case CardSuit::SUIT_SPADE:		cardStr.append("S"); break;
		}

		return cardStr;
	}

	Card* operator=(const Card& c) 
	{
		this->m_rank = c.m_rank;
		this->m_suit = c.m_suit;

		return this;
	}
};

class Deck : public Card
{
private:
	int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
	void swapCard(Card & a, Card & b)
	{
		Card temp;
		temp = a;
		a = b;
		b = temp;
	}

protected:
	std::array<Card, 52> m_deck;
	int m_cardIndex = 0;
	int m_cardNumber = 52;

public:
	Deck() : m_cardIndex(0) 
	{
		for (int suit = 0; suit < MAX_SUITS; ++suit)
			for (int rank = 0; rank < MAX_RANKS; ++rank)
			{
				m_deck[m_cardIndex++] = Card(static_cast<CardRank>(rank), static_cast<CardSuit>(suit));
			}

		m_cardIndex = 0;
	}

	friend std::ostream& operator<<(std::ostream& out, const Deck& d)
	{
		int card{ 0 };
		for (int suit = 0; suit < MAX_SUITS; ++suit)
			for (int rank = 0; rank < MAX_RANKS; ++rank)
			{
				out << d.m_deck[card++] << ' ';
			}

		return out;
	}
	void shuffleDeck()
	{
		int swapIndex{ 0 };
		for (int card = 0; card < m_cardNumber; ++card)
		{
			swapIndex = getRandomNumber(0, m_cardNumber - 1);

			swapCard(m_deck[card], m_deck[swapIndex]);
		}
	}

	const Card& dealCard()
	{
		assert(m_cardIndex < 52);
		return m_deck[m_cardIndex++];
	}

	Card& operator[](const int index)
	{
		return m_deck[index];
	}
};

class BlackJack : public Deck
{
private:
	bool getPlayerChoice()
	{
		char button{ 'A' };

		while (true)
		{
			std::cout << "Press H to hit, or S to stand: ";
			std::cin >> button;

			switch (button)
			{
			case 'H':
			case 'h': return true;
			case 'S':
			case 's': return false;
			}
		}
	}

protected:
	Deck bDeck;
	GameLog l_gameLog;

public:
	BlackJack()
	{
		bDeck.shuffleDeck();
		GameLog l_gameLog;
	}

	void play()
	{
		int playerPoints{ 0 };
		Deck playerCards;
		int playerCardID{ 0 };

		int dealerPoints{ 0 };
		Deck dealerCards;
		int dealerCardID{ 0 };

		// egy kártya az osztónak
		for (int cards = 0; cards < 1; ++cards)
		{
			dealerCards[dealerCardID] = bDeck.dealCard();
			dealerPoints += dealerCards[dealerCardID].getCardValue();
			std::cout << dealerCards[dealerCardID].returnCardStr() << ' ';
			++dealerCardID;
		}
		std::cout << "\nThe dealer has " << dealerPoints << '\n' << '\n';

		// két kártya a játékosnak
		for (int cards = 0; cards < 2; ++cards)
		{
			playerCards[playerCardID] = bDeck.dealCard();
			playerPoints += playerCards[playerCardID].getCardValue();
			std::cout << playerCards[playerCardID].returnCardStr() << ' ';
			++playerCardID;
		}

		std::cout << "\nYou have " << playerPoints << '\n' << '\n';


		while (getPlayerChoice())
		{
			playerCards[playerCardID] = bDeck.dealCard();
			if (playerCards[playerCardID].returnCardStr().at(0) == 'A')
			{
				std::cout << "You got " << playerCards[playerCardID] << ", you want to count it as 11 or 1? Answer: ";
				int playerChoice{ 0 };
				std::cin >> playerChoice;

				switch (playerChoice)
				{
				case 11: playerPoints += playerCards[playerCardID].getCardValue();
				case 1: playerPoints += playerCards[playerCardID].getCardValue() - 10;
				}
			}
			else
				playerPoints += playerCards[playerCardID].getCardValue();
			std::cout << playerCards[playerCardID].returnCardStr() << ' ';
			++playerCardID;

			std::cout << "\nYou have: " << playerPoints << '\n';

			if (playerPoints > 21)
			{

				std::cout << "\nYou lost!\n";
				l_gameLog.writeLog("aaa");


				std::cout << "Player's cards: ";
				for (int cards = 0; cards < playerCardID; ++cards)
					std::cout << playerCards[cards] << ' ';
				std::cout << "\nDealer's cards: ";
				for (int cards = 0; cards < dealerCardID; ++cards)
					std::cout << dealerCards[cards] << ' ';

				return;
			}
		}

		while (dealerPoints < 17)
		{
			dealerCards[dealerCardID] = bDeck.dealCard();
			dealerPoints += dealerCards[dealerCardID].getCardValue();
			std::cout << dealerCards[dealerCardID].returnCardStr() << ' ';
			++dealerCardID;

			std::cout << "\nThe dealer is showing: " << dealerPoints << '\n';
		}

		if (playerPoints > dealerPoints)
		{
			std::cout << "\nYou won!\n";
		}
		else if (playerPoints == dealerPoints)
		{
			std::cout << "\nIt's a draw!\n";
		}
		else
		{
			std::cout << "\nYou lost!\n";
		}

		std::cout << "Player's cards: ";
		for (int cards = 0; cards < playerCardID; ++cards)
		{
			std::cout << playerCards[cards] << ' ';
		}
		std::cout << "\nDealer's cards: ";
		for (int cards = 0; cards < dealerCardID; ++cards)
		{
			std::cout << dealerCards[cards] << ' ';
		}

		std::cout << "\nYou have " << playerPoints << ".\n" << "The dealer has " << dealerPoints << ".\n";
	}
};

int main(void)
{
	srand(static_cast<unsigned int>(time(0)));
	rand(); // ignore
	GameLog l_errorLog;

	try
	{
		bool replay{ true };
		while (replay)
		{
			BlackJack game;
			game.play();

			char button;
			std::cout << "\nPress E to exit, or any other buttons to replay the game ";
			std::cin >> button;
			std::cout << '\n';

			switch (button)
			{
			case 'E':
			case 'e': replay = false;
			}

		}
	}

	catch (GameException &e)
	{
		std::cout << e.what();
		l_errorLog.writeLog(e.logMessage());
	}

	return 0;
}*/




///

/*#include <iostream>
#include <cstdlib>

class GamePlay {

private:
	static const int NumTurns = 5; // ez által lekorlátoztuk a változó scopeját csak a classra, és csakis egyetlen másolat készül belőle.
	// ez egy deklaráció, nem egy definició, általában minden amit írunk először igényel egy definíciót, de a class-specifikus const-ok amelyek static-ok is egyben,
	// valamint az integral típusok kivételek.
	// de ha mégis szükség van egy definícióra, pl. ha lekéred a címét, vagy más miatt akkor lenti példa alapján kell létrehozni
	// azonban nem mindig ez a syntax, van amikor létrehozod a definíciót, de akkor adod meg a kezdeti értéket, és a class-ba már nem írod.

	// a következő trükk az "ENUM HACK", azaz egy enum-ba zárjuk a változónkat, így használhatjuk arrayok esetében, amikor a compiler szükségelteti az array méretét
	// pl:
	enum { _NumTurns = 5};
	// ez által a NumTurns egy symbolic name az 5-höz.

	int scores[NumTurns];


	// ...
};

const int GamePlay::NumTurns;


class CTextBlock {
public:
	// ...

	std::size_t length() const;

private:
	char* pText;

	mutable std::size_t textLength;
	mutable bool lengthIsValid;
		// ezek a tagok akármikor változtathatók, még const tag funkcióban is.

	const char& operator[](std::size_t position) const {
		// ..

		return pText[position];
	}

	char& operator[](std::size_t position) {

		return (const_cast<CTextBlock&>(static_cast<const CTextBlock&>(*this))[position]);
		// ebben az esetben, hogy elkerüljük a kóddublikációt, átalakítjuk a non-const objectet consttá a static_cast-al, hogy a const operator[] hívodjon le,
		// majd a const_cast-al kitőrüljük a const-ot a const operator[] return értékéből.
	}
};

std::size_t CTextBlock::length() const
{
	return textLength;
}

int main(void)
{
	// ha egy classon belül azt szeretnénk, hogy egy const tag változóból csak egyetlen darab készüljön --> static, lásd fennebb

	return 0;
}*/

/*************

Átfogó jegyzet - Effective C++

Const
1. Egyszerű constok esetében, használd a const objecteket vagy az enum hack-et #define-ok helyett.
2. Funkcióhoz hasonlító makrókhoz, használd az inline funkciókat a #define helyett
3. Valamit const-ként meghatározva a compiler segít használati hibákat szűrni, a const határozó bármely objecthez használható bármely scopeon, funkció paraméterekhez is, és return
	típusoknál is, de akár egészben tag funkciókhoz is.
4. A compilerek a bitwise constness szabályát biztosítják, de a programjaidat a conceptual constness szerint határozd meg
5. Amikor a const és a non-const tag funkcióknak lényegében megegyező beépítésük van, a kóddublikációt úgy tudod kiszűrni, hogy a non-const változat a const változatot hívja le.

Konstruktőr-Destruktőr-Másoló funkciók
6. Minden beépített adattípust manuálisan inicializálj.
7. Konstruktőrben, használd a member initialization list-et a bodyban végrehajtott assignment helyett. A member initialization list-ben a paraméterek sorrendjen egyezzen meg
	a meghatározásuk sorrendjével.
8. Kerüld el az inicializació sorrend problémákat a 'translation unit'-ok közt, az által, hogy a non-local static objecteket lecseréled local static objectekkel.
9. A compilerek talán maguktól létrehoznak egy alapértelmezett konstruktőrt, egy másolás konstruktőrt és egy másolás hozzárendelési operator=-t, és egy destruktőrt.
10. Hogy letiltsd ezt az automatikus funkcionalítást a compilereknek, deklaráld a megfelelő tag funkciókat private-ban, és ne határozz meg nekik beépítést.
11. Polimorfikus base classok esetében mindig virtuális destruktőröket határozz meg. Ha egy classnak van akár egy virtuális funkciója is, akkor kell tartalmazzon egy virtuális
	destruktőrt is.
12. Classok amelyeket nem úgy terveztek, hogy base classok legyen(nincs virtuális destruktőrük), vagy nincsenek felkészítve a polimorfizmushoz nem szabad, hogy virtuális destruktőrjük
	legyen.
13. Destruktőröknek sosem szabadna kivételt dobniuk, ha egy funkció hívás egy destruktőrben dobhat, akkor a destruktőrnek el kell kapnia a kivételt, és elnyelnie 
	vagy leállítania a programot.
14. Ha a class klienseknek reagálniuk kell egy kivételre egy művelet során, a classnak biztosítania kell egy rendes funkciót ami végrehajtja a műveletet.
15. Sose hívj le virtuális funkciókat konstrukció, vagy destrukció közben, mert az ilyen hívások sosem jutnak annál a származtatási szintnél tovább, mint a jelenleg zajló
	konstruktőr vagy destruktőr.
16. Az operator= mindig visszakellene térítsen egy *this hivatkozást.
17. Gondoskodj arról, hogy az operator= megfelelően viselkedik önhozzárendelés esetén is: megoldási technikák közé tartozik a címek összehasonlítása, az óvatos állításrendezés,
	és akár a copy-and-swap technika.
18. Bizonyosodj meg róla, hogy bármely funkció amely több mint egy objecten dolgozik megfelelően viselkedik ha kettő vagy több object megegyezik.
19. Másoló funkcióknak(konstruktőr, és operator=) egy object minden adat tagját és base class részét másolnia kell.
20. Ne probáld meg beépíteni az egyik másoló funkciót a másik használatával, hanem hozz létre egy közös funkcionalítást egy harmadik funkció hívásban, ami private és 'init'.

Erőforrás-kezelés
21. Hogy megelőzd az erőforrás leakeket használj RAII objecteket amelyek megszerzik az erőforrást a konstruktőrjeikben és felszabadítják a destruktőrjeikben.
22. Két hasznos RAII class a unique_ptr és a shared_ptr, a shared_ptr a leghasznosabb hiszen intuitív módon mükődik a másolása.
23. Egy RAII object másolása maga után vonja az erőforrások másolását is amelyet kezel, szóval az erőforrás másolási viselkedése meghatározza a RAII object másolási viselkedését.
24. Gyakori RAII class másolási viselkedések: a másolás tiltása, a hivatkozások számolásának végrehajtása(shared_ptr), de más viselkedések is vannak, pl. hagyományos másolás,
	vagy unique_ptr alapján való másolás.
25.	Az API-k gyakran elkell érjék a nyers mutatókat, tehát mindegyik RAII classnak tartalmaznia kellene egy lehetőséget, hogy elérjük az erőforrást amit kezel.
26. Ez az elérés lehet explicit vagy implicit átalakítás, általánosságban nézve az explicit biztonságosabb, azonban az implicit kényelmesebb és egyértelműbb a felhasználoknak.
27. Ha használod a []-t egy new kifejezésben, használnod kell [] a hozzátartozó delete kifejezésben is. Ha nem használod, akkor a delete kifejezésben sem kell használnod.
28. New-elt objecteket külön állításokba raktározd smart pointerekbe. Ennek az elhibázása erőforrás leakekhez vezethet amikor kivételek dóbododnak.

Interfész design
29. A jó interfészeket könnyű helyesen használni és nehéz helytelenül. Törekedned kell erre a karakterisztikákra mindegyik interfészedben.
30. A helyes mód ahhoz, hogy megkönnyítsd a helyes használatát az, hogy konzisztenciát épitesz ki az interfészeidben, és viselkedési kompatibilitást a beépített adattípusokkal.
31. Módok arra, hogy megelőzd a hibákat: új típusok létrehozása, műveletek korlátozása a típusokon, korlátozod a object értékeket, és felszabadítod a klienseket az erőforrás kezelés
	felelőssége alól.
32. A shared_ptr támogat testreszabott 'deleter'-et, ez megelőzi a 'Cross-DLL' problémát, és használható arra, hogy automatikusan felnyissa a mutexeket, stb.
33. A class designeolás type designeolás is egyben. Mielőtt meghatározol egy új típust, ellenőrízd le a kérdéseket az 'ITEM 18'-ból. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
34. Preferáld a pass-by-reference-to-const-ot a pass-by-value helyett, általában hatékonyabb és megelőzi a 'slicing' problémát.
35. A fenti szabály nem vonatkozik a beépített típusokra, STL iterátorokra, és funkció object típusokra, számukra a pass-by-value megfelelő.
36. Sose teríts egy mutatót vagy hivatkozást egy helyi stack objectre, egy hivatkozást egy heap-elhelyezett objectre, vagy egy mutatót/hivatkozást egy helyi static objectre, ha több mint
	egy olyan objectre lenne szükség.
37. Az adattagokat private-ként határozd meg, ez által a klienseknek szintaktikailag egyforma elérést ad az adathoz, megfelelő hozzáférési kontrollt enged meg, megőrízhetők a class
	állandók, és biztosít class szerzői beépítési rugalmasságot.
38. A protected nem sokkal jobban 'encapsulated' mint a public.
39. Preferáld a nem-tag nem-friend funkciókat a tag funkciók helyett. Ezzel növeled az 'encapsulation'-t, a 'becsomagolási' rugalmasságot, és a funkciónális kiterjeszthetőséget.
40. A szükséged van típus átalakításra mindegyik paraméterre egy funkcióhoz, a funkciónak muszáj nem-tag-nak lennie.
41. Biztosíts egy swap tag funkciót amikor az std::swap nem eléggé hatékony a saját típusodhoz. Bizonyosodj meg róla, hogy a swap funkciód nem dob kivételt!
42. Ha biztosítasz egy swap tag funkciót, akkor biztosíts egy nem-tag swap funkciót is amely lehívja a tag funkciót. Classoknak(nem templatek) specializáld az std::swap-ot is.
43. Amikor lehívod a swap-ot, alkalmazz egy using deklarációt std::swap-ra, majd hívd a swap-ot bármilyen namespace határozó nélkül.
44. Tökéletesen rendben van az ha std templateket teljesen specializálsz általad meghatározott típusokra, de sose próbálj meg bármit is hozzáadni(újra értendő) az std-hez!

Beépítés(implementálás)
45. Halaszd el a változó definicíót ameddig csak lehet. Növeli a program átláthatóságot, a program hatékonyságát.
46. Kerüld el a cast-okat bármikor amikor lehetséges, főleg a dynamic_cast-okat a teljesítmény-érzékeny kódokban. Ha a designnak szüksége van castra, próbálj meg cast-mentes alternatívát
	létrehozni.
47. Bármikor amikor a cast-olás szükséges, próbáld elrejteni egy funkción belül, aztán a kliensek lehívhatják a funkciót ahelyett, hogy saját cast-ot raknánk a kódjukba.
48. Preferáld a C++-style cast-okat a C-style castok helyett. Könnyebb őket használni, és sokkal több részletet elárulnak arról, hogy mit is csinálnak.
49. Kerüld el, hogy 'handles'-ket téritesz(legyen az hivatkozás, mutató, vagy iterátor) object belső adattagokra. Növeli az 'encapsulation'-t, segít a const tag funkcióknak
	valóban const-ként viselkedniük, és minimalizálja a logó 'handles'-ek létrehozásának lehetőségét.
50. Kivétel-biztonságos funkciók semmilyen erőforrást nem szivárogtatnak, nem teszik lehetővé, hogy adatstrukturák kárósodjanak, még akkor is ha kivételek dóbodnak.
	Ilyen funkciók alapszintű, erős, vagy nothrow garanciát biztosítanak.
51. Az erős garancia gyakran a copy-and-swap technikával van beépítve, de az erős garancia nem minden funkció számára megvalósítható.
52. Egy funkció nem biztosíthat nagyobb garanciát mint a legkisebb garanciát biztosító funkció amit lehív.
53. Limitált a legtöbb inline funkciódat rövid, gyakran használt funkciókra. Ez elősegíti a debuggolást és a bináris fejleszthetőséget, csökkenti a potenciális kódbloat lehetőségét,
	és maximalizálja a nagyobb program sebességet.
54. Ne deklaráld funkció templateket inline-nak csak azért mert header fileban jelennek meg.
55. Az általános ötlet az összeállítási egymástól való függőség mögött az, hogy deklarációkra legyünk függésbe, és ne definíciókra. Két megjelenési formája van: Handle és interface class.
56. A Library header fájlok teljes és csak-deklaráció formában kellene létezzenek. Ez érvényes akkor is ha van template használva.

Származtatás és OOP
57. A publikus származtatás egy 'is-a' kapcsolatot feltételez. Minden ami érvényes a Base classra, az muszáj érvényes legyen a származtatott classokra is, mert minden Derived object
	egy Base object is egyben.
58. A nevek a származtatott classokban elrejtik a Base class neveit. Publikus származtatás esetén, ez sosem kívánatos.
59. Ahhoz, hogy rejtett neveket újra láthatóvá tegyél, használd a using deklarációt, vagy a 'forwarding function' metódust.
60. Az interfész származtatása különbözik a beépítés származtatásától. Publikus származtatás alatt a származtatott classok mindig öröklik a base class interfészeket.
61. Pure virtual funkciók meghatározzák csak a származtatási interfészt.
62. A sima virtual funkciók meghatározzák a származtatási interfészt, plusz egy alapértelmezett implementálását a funkcionalításnak.
63. A nem-virtuális funkciók meghatározzák a származtatási interfészt, plusz a kötelező implementálását a funkcionalításnak.
64. Virtuál funkció alternatívák közé sorolható az NVI idiom használata, és a Strategy design különböző formái.
65. A hátránya annak, hogy tag funkció funkcionalítását mozgatjuk a classon kivül egy nem-tag funkcióba az, hogy az utóbbi funkció nem rendelkezik eléréssel a nem-publikus tagokhoz.
66. a 'function' objectek úgy viselkednek mint általánosított funkció mutatók, ezzek az objectek képesek támogatni bármely lehívható kompatibilis entitást, amely a megadott signature-el
	rendelkezik. (return type és paraméterek, stb.)
67. Sose határozz újra egy származtatott nem-virtuális funkciót!
68. Sose határozz újra egy származtatott alapértelmezett paramétert, mert az alapértelmezett paraméter értékek statikus boundok, míg a virtuális funkciók dinamikus boundok.
69. A kompozíciónak teljesen más értelmei vannak, mint a publikus származtatásnak.
70. Az alkalmazási domainben, a kompozíció 'has-a' kapcsolatot jelent, míg a beépítési domainben egy 'is-implemented-in-terms-of' kapcsolatot.
71. A privát származtatás egy 'is-implemented-in-terms-of' kapcsolatot feltételez, alárendelt változata a kompozíciósnak, és akkor van értelme, ha egy származtatott classnak
	elérésre van szüksége egy base class taghoz, vagy újra kell határozzon egy származtatott virtuális funkciót.
72. Nem úgy mint a kompozíció, a privát származtatás lehetővé teszi az 'empty base optimization'-t(EBO), ez fontos lehet könyvtár fejlesztőknek akik minimalizálni 
	akarják az object méretet.
73. A több classtól történő származtatás sokkal összetetebb az egy classtól történő származtatásnál. Új kétértelműség problémákhoz vezethet és a virtuális származtatás szükségéhez.
74. A virtuális származtatás magával hordoz méretbeli, sebességbeli árakat, valamint komplexebbé teszi az inicializálási és hozzárendelési folyamatokat. Akkor a legpraktikusabb, ha
	a virtuális base class nem tartalmaz semmilyen adatot.
75. A több classtól történő származtatásnak van valódi létjogosultsága. Egyik ilyen, az a helyzet amikor kombinálunk úgy, hogy egyik felől publikusan egy Interface classból,
	majd privátan egy másik classból, amelyik segít a beépítésben.

Template-k, és a generikus programozás
76. Mind a classok, mind a template-k támogatják az interfészt, illetve a polimorfizmust.
77. Classok számára az interfészek explicit jellegűek, és a funkció signature-re vannak központosítva. A polimorfizmus pedig runtime során jelenik meg virtuális funkciókon keresztül.
78. Template paraméterek esetében, az interfészek implicit jellegűek és érvényes kifejezésekre vannak alapozva. A polimorfizmus az összeállítás során jelenik meg, amikor
	példázzuk a template-t, és megoldjuk a funkció overloadolási döntést(overloadolva van-e az operátor vagy sem).
79. Amikor template paramétereket deklarálunk, a class és a typename kulcsszók felcserélhetők.
80. Használd a typename-t, hogy azonosíts 'nested dependent type' neveket, kivéve a base class listában(származtatás), vagy kivéve mint base class azonosító
	member initialization list-ben.
81. Származtatott class template-kben, hivatkozz nevekre a base class template-ből a 'this->' prefix-el, a using deklarációval, vagy egy explicit base class kvalifikációval.
82. A templatek több classot és több funkciót generálnak, tehát bármely kód amely nem függ a template paramétertől bloat-ot okoz.
83. A non-type template paraméterek által okozott bloat-okat kilehet szűrni úgy, hogy lecseréljük a template paramétereket funkció paraméterekkel, vagy class adattagokkal.
84. A template paraméterek által okozott bloat-okat lelehet csökkenteni úgy, hogy megosztjuk a beépítést olyan példáztatási típusok között amelyek azonos binárikus ábrázolással rendelkeznek.
85. Használj template tag funkciókat ahhoz, hogy olyan funkciókat generálj amely bármely kompatibilis típussal műkődnek.
86. Ha tag templateket deklarálsz általánosított copy konstrukcióhoz, vagy hozzárendeléshez, akkor úgyanúgy deklarálnod kell normális változatokat is ezekből.
87. Amikor olyan class template-t írsz amely biztosít egy olyan funkciót amely felhasználja a template-t és támogatja az implicit típus átalakítást, határozd meg ezt
	a funkciót friend formában a class templaten belül.
88. A jellemvonás(traits) classok információt nyújtanak típusokról amelyek elérhetők kompiláció során. Template-k és template specializálás segítségével vannak beépítve.
89. Az overloadolással körülfogva, a traits classok lehetővé teszik, hogy végrehajtsunk compile-time if...else teszteket típusokon.
90. A TMP átválthatja a munkát runtime-ról, compile-time-ra, ez által lehetővé téve, hogy korábban vegyünk észre híbákat, és nagyobb runtime teljesítményt érjünk el.
91. A TMP használható arra, hogy testreszabott kódot hozzunk létre különböző politika választások kombinációjára alapozva, és arra is használható, hogy elkerüljük olyan kód
	létrehozását amely nem megfelelő bizonyos típusokhoz.

A new és delete testreszabása
92. A 'set_new_handler' lehetővé teszi számodra, hogy olyan funkciót határozz meg amely lehívódik, ha a memória allokáció sikertelen.
93. A 'nothrow new' operátor korlátozott hasznosággal bír, mert csak a memória allokációra vonatkozik, az utána következő konstruktőr attól
	még úgyanúgy dobhat kivételt.
94. Számos valid oka van annak, hogy valaki testreszabott változatokat készit a new és deleteből, beleértve a teljesítménynövekedést, a 'heap usage
	error'-ok debuggolása, és 'heap usage' információ gyűjtése.
95. Az operátor 'new'-nak tartalmaznia kell egy végtelen loop-ot amely megpróbálja elhelyezni a memóriát, miközben lehívja a new-handler funkciót
	ha nem tudja teljesíteni a memória kérést, és kezelnie kell a zero byte-ra történő kéréseket. A class-specifikus változatoknak kezelniük kell
	a kéréseket nagyobb blockokra mint amit elvárnak.
96. Az operátor 'delete'-nek nem szabad semmit sem tennie ha a beadott mutató null. A class-specifikus változatok pedig nagyobb blockokat kellene
	kezelniük mint amit elvárnak.
97. Amikor egy helyettesítő(placement) változatot írsz az operátor new-ról, bizonyosodj meg róla, hogy a hozzá illő helyettesítő operátor delete-t is írsz.
	Ha ezt nem teszed meg, a programodba tapasztalhatsz apró, időszakos memória leak-ket.
98. Amikor deklarálod a helyettesítő változatát a new-nak és delete-nek, bizonyosodj meg róla, hogy nem szándékosan de nem-e rejtetted el a normál
	verzióit ezeknek az operátoroknak.

Egyéb
99. Vedd komolyan a compiler által dobott figyelmeztetéseket, és törekedj arra, hogy olyan programokat alkoss amelyek figyelmeztetés nélkül lefutnak, a legnagyobb figyelmeztetési
	szinten is.
100. Ne függj a compiler figyelmeztetéseken, mert különböző compilerek különböző dolgokra figyelmeztetnek. Ha átváltasz egy másik compilerre az eltörölhet olyan figyelmeztetéseket,
	amelyekre korábban hagyatkoztál.




/////////////////////////

	Átfogó jegyzet - Effective STL

Containers
1. 

*************/

// kapcsolódnak a fenti jegyzethez
/*class FontHandle {};

class Font
{
public:
	operator FontHandle() {}
};



#include <fstream>
#include <iostream>
#include <string>

void logCall(const std::string& logMessage)
{
	static std::ofstream log("log.txt", std::ios::app);
	log << logMessage;
}

// TMP factorial
template <unsigned n>
struct Factorial
{
	enum { value = n * Factorial<n-1>::value };
};

template<>
struct Factorial<0>
{
	enum { value = 1 };
};

int main()
{
	std::cout << Factorial<5>::value;

	return 0;
}
*/

/*#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
	RenderWindow window(VideoMode(320, 480), "The game");

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e));
		{
			if (e.type == Event::Closed)
				window.close();
		}

		window.clear(Color::White);
		window.display();
	}



	return 0;
}*/

// comparison type for sets
struct DereferenceLess 
{
	template <typename PtrType>
	bool operator()(PtrType pT1, // parameters are passed by
		PtrType pT2) const // value, because we expect them
	{ // to be (or to act like) pointers
		return *pT1 < *pT2;
	}
};

#include <vector>
#include <memory>
#include <iterator>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	
	ifstream file("sample.txt");

	if (file)
	{
		file.unsetf(ios::skipws);
		string fileData(istream_iterator<char>(file), istream_iterator<char>());

		cout << fileData << '\n';
	}
	else
		cout << "Couldn't be opened for copying\n";

	return 0;
}