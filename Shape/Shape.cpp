#include <iostream>

using namespace std;

class Shape
{
public:
    int h = 0;  //высота
    int w = 0;  //ширина
    int a = 0;  //дополнительная переменная для определения ширины, где она изначально не задается
    virtual void draw() = 0;
};

class Rectangle :public Shape   //прямоугольник
{
private:
    void check()
    {
        if (h == w)
        {
            for (int i = 0; i < h; i++)
            {
                cout << "\t";
                if (i == 0 || i == h - 1)            
                {
                    for (int j = 0; j < w; j++)
                    {
                        cout << ". ";
                    }
                }
                else                              
                {
                    cout << ".";
                    for (int j = 1; j < w - 1; j++)
                    {
                        if (j == (w / 2))
                        {
                            cout << "   ";
                        }
                        else
                        {
                            cout << "  ";
                        }
                    }
                    cout << ".";
                }
                cout << endl;
            }
            cout << "\nThis is square!" << endl;
        }
        else
        {
            cout << "\nJust a rectangle" << endl;
        }
    }
public:
    void draw()
    {
        cout << "Enter height" << endl;
        cin >> h;
        cout << "Enter width" << endl;
        cin >> w;
        if (h == w)
        {
            check();
        }
        else
        {
            for (int i = 0; i < h; i++)
            {
                cout << "\t";
                if (i == 0 || i == h - 1)             //условие, что если мы затрагиваем верхние границы прямоугольника, то прописывем "." сплошной
                {
                    for (int j = 0; j < w; j++)
                    {
                        cout << ".";
                    }
                }
                else                               //иначе внутреннюю часть прямоугольника оставляем незаполненным, боковые границыуказываем "."
                {
                    cout << ".";
                    for (int j = 1; j < w - 1; j++)
                    {
                        cout << " ";
                    }
                    cout << ".";
                }
                cout << endl;
            }
            check();
        }
    }
};

class Triangle:public Shape           //треугольник
{
public:
    void draw()
    {
        cout << "Enter height" << endl;
        cin >> h;
        for (int i = h; i > 0; i--)
        {
            cout << "\t";
            for (int j = 1; j < i; j++)       //делаем треугольник равнобедренным за счет дополнительного пробела на каждом новом ряду
            {
                cout << " ";
            }
            if (i == 1 || i == h)
            {
                for (int k = 0; k <= a * 2; k++)
                {
                    cout << ".";
                }
            }
            else
            {
                cout << ".";
                for (int l = 1; l < a * 2; l++)
                {
                    cout << " ";
                }
                cout << ".";
            }
            cout << endl;
            a++;
        }
    }
};

class Rhombus :public Shape           //ромб (посторен по принципу треугольника+перевернутый треугольник)
{
public:
    void draw()
    {
        cout << "Enter half-height" << endl;
        cin >> h;
        for (int i = h; i > 0; i--)
        {
            cout << "\t";
            for (int j = 1; j < i; j++)
            {
                cout << " ";
            }
            if (i == h)
            {
                cout << ".";
            }
            else
            {
                cout << ".";
                for (int k = 1; k < a * 2; k++)
                {
                    cout << " ";
                }
                cout << ".";
            }
            cout << endl;
            a++;
        }
        for (int i = 2; i <= h; i++)
        {
            cout << "\t";
            for (int j = 1; j < i; j++)
            {
                cout << " ";
            }
            if (i == h)
            {
                cout << ".";
            }
            else
            {
                cout << ".";
                for (int k = 2; k < a * 2 - 3; k++)
                {
                    cout << " ";
                }
                cout << ".";
            }
            cout << endl;
            a--;
        }
    }
};


class Circle :public Shape     //круг
{
public:
    void draw()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "\t";
            for (int j = 0; j < 10; j++)
            {
                if (i == 0 && j == 4 || i == 0 && j == 5 || 
                    i == 1 && j == 2 || i == 1 && j == 7 || 
                    i == 2 && j == 1 || i == 2 && j == 8 ||
                    i == 4 && j == 0 || i == 4 && j == 9 || 
                    i == 7 && j == 1 || i == 7 && j == 8 || 
                    i == 8 && j == 2 || i == 8 && j == 7 || 
                    i == 9 && j == 4 || i == 9 && j == 5)
                {
                    cout << ". ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
};

class Drawn
{
public:
    void draw(Shape* shape)
    {
        shape->draw();
    }
};


int main()
{
    int n = 0;
    Rectangle rectangel;
    Triangle triangle;
    Rhombus rhombus;
    Circle circle;
    Drawn drawn;

    while (n != 5)
    {
        cout << "What shape?\n" << "1. Rectangle or Square\n" << "2. Triangle\n" << "3. Rhombus\n" << "4. Circle\n" << "5. Exit\n" << "Your choice = ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << endl;
            drawn.draw(&rectangel);
            break;
        case 2:
            cout << endl;
            drawn.draw(&triangle);
            break;
        case 3:
            cout << endl;
            drawn.draw(&rhombus);
            break;
        case 4:
            cout << endl;
            drawn.draw(&circle);
            break;
        case 5:
            return false;
            break;
        }
    }
        return 0;
}







/* (Не получилось)
class Circle :public Shape     //круг
{
public:
    void draw()
    {
        cout << "Enter diameter" << endl;
        cin >> w;
        int b = w;
        int h = 0;
        int l = 0;
        for (int i = w; i > 0; i--)
        {
            cout << "\t";
            if (i == (w / 2))
            {
                cout << ".";
                for (int k = 1; k < a * 2; k++)
                {
                    cout << " ";
                }
                cout << ".";
            }
            else
            {
                for (int j = 0; j <= b; j++)
                {
                    cout << " ";
                }
                if (i == h)
                {
                    cout << ".";
                }
                else
                {
                    cout << ".";
                    for (int k = 1; k < a * 2; k++)
                    {
                        cout << " ";
                    }
                    cout << ".";
                }
            }
            cout << endl;
            b = b - 2;
            a++;
        }
        for (int i = 2; i < w; i++)
        {
            b = 0;
            cout << "\t";
            for (int j = 0; j <= h; j++)
            {
                cout << " ";
            }
            for (int k = 2; k <= l * 2; k++)
            {
                cout << ".";
            }
            cout << endl;
            a = a - 2;
            l = l + 2;
        }
    }
};

*/