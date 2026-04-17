#include <iostream>

using namespace std;


class Line {
public:
    int x1, y1, x2, y2;
    void display() {
        printf("Line (родитель) x1: %d; y1: %d; x2: %d; y2: %d \n", x1, y2, x2, y2);
    }
    Line() {
        printf("---Конструктор Line без операторов\n");
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;
    }
    Line(int x1, int y1, int x2, int y2) {
        printf("---Конструктор Line с операторами\n");
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    Line(const Line& l) {
        printf("---Конструктор Line копирования\n");
        this->x1 = l.x1 + 1;
        this->y1 = l.y1;
        this->x2 = l.x2;
        this->y2 = l.y2;
    }
    virtual ~Line() {
        display();
        printf("~~~Деструктор Line\n\n");
    }
    void move(int dx1, int dy1, int dx2, int dy2);
};

void Line::move(int dx1, int dy1, int dx2, int dy2) {
    this->x1 += dx1;
    this->y1 += dy1;
    this->x2 += dx2;
    this->y2 += dy2;
};



int main() {
    setlocale(LC_ALL, "ru");
    {
        printf("\n=== 1) Статическое создание Line ===\n");
        printf("[Создание] Объекты создаются в порядке объявления.\n");
        Line l1;
        Line l2(1, 2, 3, 4);
        Line l3(l2);
    }

    {
        printf("\n=== 2) Динамическое создание Line ===\n");
        printf("[Создание] Объекты создаются через new.\n");
        Line* l1 = new Line();
        Line* l2 = new Line(1, 2, 3, 4);
        Line* l3 = new Line(*l2);

        delete l1;
        delete l2;
        delete l3;
    }

    
}
