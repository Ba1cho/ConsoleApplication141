// ConsoleApplication134.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
private:
    double x1, y1; // координаты первой вершины
    double x2, y2; // координаты второй вершины
    double x3, y3; // координаты третьей вершины
public:
    // конструкторы
    Triangle() {
        cout << "Введите первую координату: ";
        cin >> x1 >> y1;
        cout << "Введите вторую координату: ";
        cin >> x2 >> y2;
        cout << "Введите третью координату: ";
        cin >> x3 >> y3;
    }

    Triangle(double x1_, double y1_, double x2_, double y2_, double x3_, double y3_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_), x3(x3_), y3(y3_) {}

    // методы перемещения
    void move(double dx, double dy) {
        x1 += dx;
        y1 += dy;
        x2 += dx;
        y2 += dy;
        x3 += dx;
        y3 += dy;
    }

    // методы поворота
    void rotate(double angle) {
        double rad = angle * 3.14 / 180.0; // перевод градусов в радианы
        double new_x1 = x1 * cos(rad) - y1 * sin(rad);
        double new_y1 = x1 * sin(rad) + y1 * cos(rad);
        double new_x2 = x2 * cos(rad) - y2 * sin(rad);
        double new_y2 = x2 * sin(rad) + y2 * cos(rad);
        double new_x3 = x3 * cos(rad) - y3 * sin(rad);
        double new_y3 = x3 * sin(rad) + y3 * cos(rad);
        x1 = new_x1;
        y1 = new_y1;
        x2 = new_x2;
        y2 = new_y2;
        x3 = new_x3;
        y3 = new_y3;
    }

    // методы определения площади и периметра
    double area() {
        return 0.5 * abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
    }

    double perimeter() {
        double a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        double b = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
        double c = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
        return a + b + c;
    }

    // метод рисования на плоскости (просто выводит информацию о фигуре)
    void draw() {
        cout << "Треугольник с вершинами (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ") and (" << x3 << ", " << y3 << ")" << endl;
    }
};

class Rectangle {
private:
    double x1, y1; // координаты левой верхней вершины
    double x2, y2; // координаты правой нижней вершины
public:
    // конструкторы
    Rectangle() {
        cout << "Введите координаты верхней левой вершины: ";
        cin >> x1 >> y1;
        cout << "Введите координаты верхней правой вершины: ";
        cin >> x2 >> y2;
    }

    Rectangle(double x1_, double y1_, double x2_, double y2_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_) {}

    // методы перемещения
    void move(double dx, double dy) {
        x1 += dx;
        y1 += dy;
        x2 += dx;
        y2 += dy;
    }

    // методы поворота (не имеет смысла для прямоугольника)
    void rotate(double angle) {}

    // методы определения площади и периметра
    double area() {
        return abs((x2 - x1) * (y2 - y1));
    }

    double perimeter() {
        return 2 * (abs(x2 - x1) + abs(y2 - y1));
    }

    // метод рисования на плоскости (просто выводит информацию о фигуре)
    void draw() {
        cout << "Прямоугольник с вершинами (" << x1 << ", " << y1 << ") и (" << x2 << ", " << y2 << ")" << endl;
    }
};
class Rhombus {
private:
    double x, y; // координаты центра ромба
    double side; // длина стороны ромба
public:
    Rhombus() {
        cout << "Введите координаты центра (x, y): ";
        cin >> x >> y;
        cout << "Введите длину стороны: ";
        cin >> side;
    }

    // методы для перемещения
    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }

    // метод для поворота на угол angle (в радианах) относительно точки (x0, y0)
    void rotate(double angle, double x0, double y0) {
        double cosAngle = cos(angle);
        double sinAngle = sin(angle);

        // поворот центра ромба
        double newX = (x - x0) * cosAngle - (y - y0) * sinAngle + x0;
        double newY = (x - x0) * sinAngle + (y - y0) * cosAngle + y0;
        x = newX;
        y = newY;
    }

    // метод для вычисления площади ромба
    double area() {
        return side * side * sin(3.14 / 3.0);
    }

    // метод для вычисления периметра ромба
    double perimeter() {
        return 4 * side;
    }

    // метод для рисования ромба на плоскости
    void draw() {
        cout << "Ромб: (" << x - side / 2.0 << ", " << y << ") ("
            << x << ", " << y + side / 2.0 << ") ("
            << x + side / 2.0 << ", " << y << ") ("
            << x << ", " << y - side / 2.0 << ")" << endl;
    }

    // метод для ввода координат и длины стороны ромба от пользователя

};
class Ellipse {
private:
    double x, y; // координаты центра
    double a, b; // полуоси
public:
    // конструкторы
    Ellipse() {
        cout << "Введите координаты центра: ";
        cin >> x >> y;
        cout << "Введите длину главной оси: ";
        cin >> a;
        cout << "Введите длину малой оси: ";
        cin >> b;
    }

    Ellipse(double x_, double y_, double a_, double b_) : x(x_), y(y_), a(a_), b(b_) {}

    // методы перемещения
    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }

    // методы поворота (не имеет смысла для эллипса)
    void rotate(double angle) {
        double x_new, y_new;
        x_new = x * cos(angle) - y * sin(angle);
        y_new = x * sin(angle) + y * cos(angle);
        x = x_new;
        y = y_new;
    }

    // методы определения площади и периметра
    double area() {
        return 3.14 * a * b;
    }

    double perimeter() {
        return 2 * 3.14 * sqrt((a * a + b * b) / 2);
    }

    // метод рисования на плоскости (просто выводит информацию о фигуре)
    void draw() {
        cout << "Эллипс с центром (" << x << ", " << y << "), главная ось " << a << ", малая ось " << b << endl;
    }
};
class Trapezoid {
private:
    double x1, y1; // координаты первой вершины
    double x2, y2; // координаты второй вершины
    double x3, y3; // координаты третьей вершины
    double x4, y4; // координаты четвертой вершины
public:
    // конструкторы
    Trapezoid() {
        cout << "Введите координаты первой вершины: ";
        cin >> x1 >> y1;
        cout << "Введите координаты второй вершины: ";
        cin >> x2 >> y2;
        cout << "Введите координаты третьей вершины: ";
        cin >> x3 >> y3;
        cout << "Введите координаты четвертой вершины: ";
        cin >> x4 >> y4;
    }

    Trapezoid(double x1_, double y1_, double x2_, double y2_, double x3_, double y3_, double x4_, double y4_)
        : x1(x1_), y1(y1_), x2(x2_), y2(y2_), x3(x3_), y3(y3_), x4(x4_), y4(y4_) {}

    // методы перемещения
    void move(double dx, double dy) {
        x1 += dx;
        y1 += dy;
        x2 += dx;
        y2 += dy;
        x3 += dx;
        y3 += dy;
        x4 += dx;
        y4 += dy;
    }

    // методы поворота
    void rotate(double angle) {
        double cx = (x1 + x2 + x3 + x4) / 4;
        double cy = (y1 + y2 + y3 + y4) / 4;
        double s = sin(angle);
        double c = cos(angle);

        // поворачиваем каждую вершину относительно центра фигуры
        double x1_new = cx + (x1 - cx) * c - (y1 - cy) * s;
        double y1_new = cy + (x1 - cx) * s + (y1 - cy) * c;
        double x2_new = cx + (x2 - cx) * c - (y2 - cy) * s;
        double y2_new = cy + (x2 - cx) * s + (y2 - cy) * c;
        double x3_new = cx + (x3 - cx) * c - (y3 - cy) * s;
        double y3_new = cy + (x3 - cx) * s + (y3 - cy) * c;
        double x4_new = cx + (x4 - cx) * c - (y4 - cy) * s;
        double y4_new = cy + (x4 - cx) * s + (y4 - cy) * c;

        // обновляем координаты вершин
        x1 = x1_new;
        y1 = y1_new;
        x2 = x2_new;
        y2 = y2_new;
        x3 = x3_new;
        y3 = y3_new;
        x4 = x4_new;
        y4 = y4_new;
    }

    // методы определения площади и периметра
    double area() {
        double h = abs(y2 - y1);
        double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        double b = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
        return (a + b) * h / 2;
    }

    double perimeter() {
        double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        double b = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
        double c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        double d = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2));
        return a + b + c + d;
    }

    // метод рисования на плоскости (просто выводит информацию о фигуре)
    void draw() {
        cout << "Трапеция с вершинами (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << "), (" << x4 << ", " << y4 << ")" << endl;
    }
};
void info_opr() {
    cout << "Выберите действие из перечисленых: " << '\n'
        << "1. Вывод информации о новой фигуре" << '\n'
        << "2. Вывод площади" << '\n'
        << "3. Вывод периметра" << '\n'
        << "4. Поворот фигуры" << '\n'
        << "5. Для выбоа другой фигуры введите 0" << '\n'
        << "6 Перемещение фигуры\n";
}
void menu() {
    int n = 9;
    bool flag = true;
    while (n != 0)
    {
        int k = 1;
        cout << "Выберите фигуру" << '\n'
            << "1. Треугольник" << '\n'
            << "2. Прямоугольник" << '\n'
            << "3. Ромб" << '\n'
            << "4. Элипс" << '\n'
            << "5. Трапеция" << '\n'
            << "0. Для завершения программы\n";
        cin >> n;
        system("CLS");
        if (n == 1) {
            Triangle t;
            while (k != 0) {
                if (k == 0) {
                    n = 9;
                    k = 1;
                }
                if (k == 1) {
                    t.draw(); // выводим информацию о фигуре
                }
                else if (k == 2) {
                    cout << "площадь: " << t.area() << endl; // выводим площадь
                }
                else if (k == 3) {
                    cout << "периметр: " << t.perimeter() << endl; // выводим периметр
                }
                else if (k == 4) {
                    t.rotate(90); // поворачиваем на 90 градусов
                    t.draw();
                }
                else if (k == 6) {
                    int x, y;
                    cout << "введите координаты x,y:";
                    cin >> x >> y;
                    t.move(x, y);
                }
                info_opr();
                cin >> k;
            }
        }
        if (n == 2) {
            Rectangle t;
            while (k != 0) {
                if (k == 0) {
                    n = 9;
                    k = 1;
                }
                if (k == 1) {
                    t.draw(); // выводим информацию о фигуре
                }
                else if (k == 2) {
                    cout << "площадь: " << t.area() << endl; // выводим площадь
                }
                else if (k == 3) {
                    cout << "периметр: " << t.perimeter() << endl; // выводим периметр
                }
                else if (k == 4) {
                    t.rotate(90); // поворачиваем на 90 градусов
                    t.draw();
                }
                else if (k == 6) {
                    int x, y;
                    cout << "введите координаты x,y:";
                    cin >> x >> y;
                    t.move(x, y);
                }
                info_opr();
                cin >> k;
            }
        }
        if (n == 3) {
            Rhombus t;
            while (k != 0) {
                if (k == 0) {
                    n = 9;
                    k = 1;
                }
                if (k == 1) {
                    t.draw(); // выводим информацию о фигуре
                }
                else if (k == 2) {
                    cout << "площадь: " << t.area() << endl; // выводим площадь
                }
                else if (k == 3) {
                    cout << "периметр: " << t.perimeter() << endl; // выводим периметр
                }
                else if (k == 4) {
                    t.rotate(90, 0, 0); // поворачиваем на 90 градусов
                    t.draw();
                }
                else if (k == 6) {
                    int x, y;
                    cout << "введите координаты x,y:";
                    cin >> x >> y;
                    t.move(x, y);
                }
                info_opr();
                cin >> k;
            }
        }
        if (n == 4) {
            Ellipse t;
            while (k != 0) {
                if (k == 0) {
                    n = 9;
                    k = 1;
                }
                if (k == 1) {
                    t.draw(); // выводим информацию о фигуре
                }
                else if (k == 2) {
                    cout << "площадь: " << t.area() << endl; // выводим площадь
                }
                else if (k == 3) {
                    cout << "периметр: " << t.perimeter() << endl; // выводим периметр
                }
                else if (k == 4) {
                    t.rotate(90); // поворачиваем на 90 градусов
                    t.draw();
                }
                else if (k == 6) {
                    int x, y;
                    cout << "введите координаты x,y:";
                    cin >> x >> y;
                    t.move(x, y);
                }
                info_opr();
                cin >> k;
            }
        }
        if (n == 5) {
            Trapezoid t;
            while (k != 0) {
                if (k == 0) {
                    n = 9;
                    k = 1;
                }
                if (k == 1) {
                    t.draw(); // выводим информацию о фигуре
                }
                else if (k == 2) {
                    cout << "площадь: " << t.area() << endl; // выводим площадь
                }
                else if (k == 3) {
                    cout << "периметр: " << t.perimeter() << endl; // выводим периметр
                }
                else if (k == 4) {
                    t.rotate(90); // поворачиваем на 90 градусов
                    t.draw();
                }
                else if (k == 6) {
                    int x, y;
                    cout << "введите координаты x,y:";
                    cin >> x >> y;
                    t.move(x, y);
                }
                info_opr();
                cin >> k;
            }
        }
    }

}
int main()
{

    setlocale(LC_ALL, "rus");
    menu();
    /*
    //Треугольник
    Triangle t; // создаем треугольник с запросом на ввод координат
    t.draw(); // выводим информацию о фигуре
    cout << "площадь: " << t.area() << endl; // выводим площадь
    cout << "периметр: " << t.perimeter() << endl; // выводим периметр
    //t.move(1, 2); // перемещаем на (1,2)
    t.rotate(90); // поворачиваем на 90 градусов
    t.draw(); // выводим информацию о новой фигуре


    //Прямоугольник
    Rectangle n; // создаем прямоугольник с запросом на ввод координат
    n.draw(); // выводим информацию о фигуре
    cout << "площадь: " << n.area() << endl; // выводим площадь
    cout << "периметр: " << n.perimeter() << endl; // выводим периметр
    n.move(1, 2); // перемещаем на (1,2)
    n.draw(); // выводим информацию о новой фигуре

    //Ромб
    Rhombus r;

    // перемещаем ромб на (1,1)
    r.move(1, 1);

    // поворачиваем ромб на 45 градусов относительно точки (0,0)
    r.rotate(3.14 / 4.0, 0, 0);

    // вычисляем площадь и периметр ромба
    double area = r.area();
    double perimeter = r.perimeter();

    // выводим информацию о ромбе
    r.draw();
    cout << "площадь: " << area << endl;
    cout << "периметр: " << perimeter << endl;

    //Эллипс
    Ellipse e; // создаем эллипс с запросом на ввод координат
    e.draw(); // выводим информацию о фигуре
    cout << "площадь: " << e.area() << endl; // выводим площадь
    cout << "периметр: " << e.perimeter() << endl; // выводим периметр
    e.move(1, 2); // перемещаем на (1,2)
    e.draw(); // выводим информацию о новой фигуре

    //Трапеция
    Trapezoid m; // создаем трапецию с левой нижней вершиной в (0,0), правой нижней вершиной в (2,0) и высотой 1
    m.draw(); // выводим информацию о фигуре
    cout << "площадь: " << m.area() << endl; // выводим площадь
    cout << "периметр: " << m.perimeter() << endl; // выводим периметр
    m.move(1, 2); // перемещаем на (1,2)
    m.draw(); // выводим информацию о новой фигуре
    m.rotate(3 / 14 / 4); // поворачиваем на 45 градусов
    m.draw(); // выводим информацию о новой фигуре
    */
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
