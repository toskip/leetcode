class Foo {
private:
    int state;
public:
    Foo() {
        state =0;
    }

    void first(function<void()> printFirst) {
        while(state!=0);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        state=1;
    }

    void second(function<void()> printSecond) {
        while(state!=1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        state = 2;
    }

    void third(function<void()> printThird) {
        while(state!=2);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        state = 0;
    }
};
