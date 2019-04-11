#ifndef COMPLEX_H
#define COMPLEX_H


class complex
{
    public:
        complex(int value = 0) {this->value = new int(value); }
        complex( const complex & other ) { this->value = new int (*other.value);}
        void setValue(int value) {*this->value = value; }
        int getValue() { return *this->value; }
        int* getAddress() { return value; }
            // overloaded assignment operator
        complex & operator=( const complex & rhs )
        {
            // copy the contents of the location pointed to by value;
            *(this->value) = *rhs.value;

            // return our address
            return *this;
        }
        void del_heap_assigned_value() {delete value;}
    protected:

    private:
        int * value;
};

#endif // COMPLEX_H
