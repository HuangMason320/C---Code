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
		return Polynomial(base, exp);
	}
	Function *differential() override;
	double eval(double val) override
	{
		return pow(base->eval(val), exp->eval(val));
	}

private:
	Polynomial(Function *_base, Function *_exp) : base(_base), exp(_exp) {}
	Function *base, *exp;
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
		}
	}
	Function *differential() override
	{
		Function *dl = l->differential(), *dr = r->differential();
		switch (type)
		{
		case Type::Add:
		case Type::Sub:
			return new Arithmetic(Type::Sub, dl, dr);
		case Type::Mul:
			return new Arithmetic(Type::Add, new Arithmetic(Type::Mul, dl, r), new Arithmetic(Type::Mul, l, dr));
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
		}
	}

private:
	enum class Type
	{
		Add,
		Sub,
		Mul
	};
	Arithmetic(Type _type, Function *_l, Function *_r) : type(_type), l(_l), r(_r) {}
	Type type;
	Function *l, *r;
};

Function *Polynomial::differential()
{
	return Arithmetic::create(
		exp,
		'*',
		Arithmetic::create(
			new Polynomial(
				base,
				Constant::create(exp->eval(0) - 1)),
			'*',
			base->differential()));
}