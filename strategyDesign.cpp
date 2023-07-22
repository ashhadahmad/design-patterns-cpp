#include <iostream>
using namespace std;

class Quacker {
public:
    virtual void quack() = 0;
};

class AQuacker : public Quacker {
public:
    void quack() {
        cout << "A Quack\n";
    }
};

class BQuacker : public Quacker {
public:
    void quack() {
        cout << "B Quack\n";
    }
};

class Flyer {
public:
    virtual void fly() = 0;
};

class PFlyer : public Flyer {
public:
    void fly() {
        cout << "P Fly\n";
    }
};

class QFlyer : public Flyer {
public:
    void fly() {
        cout << "Q Fly\n";
    }
};

class duck {
    public:
    Quacker* quacker;
    Flyer* flyer;
    void setQuacker(Flyer* quacker) {
        this->quacker = quacker;
    }
    void setFlyer(Flyer* flyer) {
        this->flyer = flyer;
    }
    void performQuack() {
        quacker -> quack();
    }
    void performFly() {
        flyer -> fly();
    }
};

class MallardDuck: public duck {
    public:
    MallardDuck() {
        quacker = new AQuacker();
        flyer = new QFlyer();
    }
};

int main() {
    cout << "Hello World\n";
    MallardDuck m;
    m.performQuack();
    m.performFly();

    m.quacker = new BQuacker();
    m.performQuack();
}