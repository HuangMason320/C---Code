class Constant : public Function
{
public:
    static Constant *create(double);
    Function *differential() override;
    double eval(double) override;
};

class Variable : public Function
{
public:
    static Variable *create(string);
    Function *differential() override;
    double eval(double) override;
};

class Polynomial : public Function
{
public:
    static Polynomial *create(Function *, Function *);
    Function *differential() override;
    double eval(double) override;
};

class Arithmetic : public Function
{
public:
    static Arithmetic *create(Function *, char, Function *);
    Function *differential() override;
    double eval(double) override;
};

class Sin : public Function
{
public:
    static Sin *create(Function *);
    Function *differential() override;
    double eval(double) override;
};

class Cos : public Function
{
public:
    static Cos *create(Function *);
    Function *differential() override;
    double eval(double) override;
};
