#include <bits/stdc++.h>
using namespace std;

class Constant : public Function
{
public:
    static Constant *create(const double &val)
    {
        return new Constant(val);
    }
    Function *differential() override
    {
        // (c)' = 0
        return new Constant(0);
    }
    double eval(double _val) override
    {
        return val;
    }

private:
    Constant(const double &_val) : val(_val) {}
    double val;
};

class Variable : public Function
{
public:
    static Variable *create(const string &var)
    {
        return new Variable(var);
    }
    Function *differential() override
    {
        //(x)' = 1
        return Constant::create(1);
    }
    double eval(double val) override
    {
        return val;
    }

private:
    Variable(const string &_var) : var(_var) {}
    string var;
};

class Polynomial : public Function
{
public:
    static Polynomial *create(Function *base, Function *exp)
    {
        return new Polynomial(base, exp);
    }
    Function *differential() override;
    double eval(double val) override
    {
        return pow(base->eval(val), exp->eval(val));
    }

private:
    Polynomial(Function *_base, Function *_exp) : base(_base), exp(_exp) {}
    Function *base;
    Function *exp;
};

class Arithmetic : public Function
{
public:
    static Arithmetic *create(Function *l, char op, Function *r)
    {
        switch (op)
        {
        case '+':
            return new Arithmetic(Type::Add, l, r);
        case '-':
            return new Arithmetic(Type::Sub, l, r);
        case '*':
            return new Arithmetic(Type::Mul, l, r);
        case '/':
            return new Arithmetic(Type::Div, l, r);
        /*default:
            // op not listed above, throw exception
            throw invalid_argument(string("Unknown Arithmetic operator: ") + op);*/
        }
    }
    Function *differential() override
    {
        Function *dl = l->differential(), *dr = r->differential();
        switch (type)
        {
        // (A+B)' = A' + B', (A-B)' = A' - B'
        case Type::Add:
        case Type::Sub:
            return new Arithmetic(type, dl, dr);
        // (AB)' = (AB') + (A'B)
        case Type::Mul:
            return new Arithmetic(
                Type::Add,
                new Arithmetic(Type::Mul, l, dr),
                new Arithmetic(Type::Mul, dl, r));
        case Type::Div:
            // (A / B)' = (A'B - B'A) / (B^2)
            return new Arithmetic(
                Type::Div,
                new Arithmetic(
                    Type::Sub,
                    new Arithmetic(Type::Mul, r, dl),
                    new Arithmetic(Type::Mul, l, dr)),
                Polynomial::create(r, Constant::create(2)));
        }
    }
    double eval(double val) override
    {
        switch (type)
        {
        case Type::Add:
            return l->eval(val) + r->eval(val);
        case Type::Sub:
            return l->eval(val) - r->eval(val);
        case Type::Mul:
            return l->eval(val) * r->eval(val);
        case Type::Div:
            return l->eval(val) / r->eval(val);
        }
    }

private:
    enum class Type
    {
        Add,
        Sub,
        Mul,
        Div
    };
    Arithmetic(Type _type, Function *_l, Function *_r) : type(_type), l(_l), r(_r) {}
    Type type;
    Function *l, *r;
};

class Sin : public Function
{
public:
    static Sin *create(Function *base)
    {
        return new Sin(base);
    }
    Function *differential() override;
    double eval(double val) override
    {
        return sin(base->eval(val));
    }

private:
    Sin(Function *_base) : base(_base) {}
    Function *base;
};

class Cos : public Function
{
public:
    static Cos *create(Function *base)
    {
        return new Cos(base);
    }
    Function *differential() override
    {
        // cos(A)' = -sin(A) * A'
        return Arithmetic::create(
            Constant::create(0),
            '-',
            Arithmetic::create(
                Sin::create(base),
                '*',
                base->differential()));
    }
    double eval(double val) override
    {
        return cos(base->eval(val));
    }

private:
    Cos(Function *_base) : base(_base) {}
    Function *base;
};

Function *Polynomial::differential()
{
    // (A^b)' = b * (A^(b-1)) * A'
    return Arithmetic::create(
        exp,
        '*',
        Arithmetic::create(
            new Polynomial(
                base,
                Constant::create(exp->eval(0) - 1) // problem statement guaranteed that no variable in exp
                ),
            '*',
            base->differential()));
}

Function *Sin::differential()
{
    // sin(A)' = cos(A) * A'
    return Arithmetic::create(
        Cos::create(base),
        '*',
        base->differential());
}