#ifndef COMPLEX_H
#define COMPLEX_H


class complex
{
    public:
        complex(int value = 0) {this->value = new int(value); }
        void setValue(int value) {*this->value = value; }
        int getValue() { return *this->value; }

    protected:

    private:
        int * value;
};

#endif // COMPLEX_H
