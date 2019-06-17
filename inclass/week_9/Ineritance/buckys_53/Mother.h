#ifndef MOTHER_H
#define MOTHER_H

//base class

class Mother
{
    public:
        Mother();
        void sayName();
        int publicv;
        void get_protectedv();
        void set_protectedv(int tempint);
    protected:
        int protectedv;

    private:
        int privatev;



};

#endif // MOTHER_H
