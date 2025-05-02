#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

struct Expression //базовая абстрактная структура
{
	virtual ~Expression() { } //виртуальный деструктор
	virtual double evaluate() const = 0; //абстрактный метод «вычислить»
	virtual Expression* transform(Transformer* tr) const = 0; //метод для двойной диспетчеризации
};

struct Number : Expression // стуктура «Число»
{
	Number(double value) : value_(value) {} //конструктор
	double value() const { return value_; } // метод чтения значения числа
	double evaluate() const  override { return value_; } // реализация виртуального метода «вычислить»
	Expression* transform(Transformer* tr) const override {
		return tr->transformNumber(this);
	}
	~Number()  override {}//деструктор, тоже виртуальный
private:
	double value_; // само вещественное число
};

struct BinaryOperation : Expression // «Бинарная операция»
{
	enum { // перечислим константы, которыми зашифруем символы операций
		PLUS = '+',
		MINUS = '-',
		DIV = '/',
		MUL = '*'
	};
	// в конструкторе надо указать 2 операнда — левый и правый, а также сам символ операции
		BinaryOperation(Expression const* left, int op, Expression const* right): left_(left), op_(op), right_(right){
		assert(left_ && right_);
	}
	~BinaryOperation() override//в деструкторе освободим занятую память
	{
		delete left_;
		delete right_;
	}
	Expression const* left() const { return left_; } // чтение левого операнда
	Expression const* right() const { return right_; } // чтение правого операнда
		int operation() const { return op_; } // чтение символа операции
	double evaluate() const override// реализация виртуального метода «вычислить»
	{
		double left = left_->evaluate(); // вычисляем левую часть
		double right = right_->evaluate(); // вычисляем правую часть
		switch (op_) // в зависимости от вида операции, складываем, вычитаем, умножаем
// или делим левую и правую части
		{
		case PLUS: return left + right;
		case MINUS: return left - right;
		case DIV: return left / right;
		case MUL: return left * right;
		}

	}
	Expression* transform(Transformer* tr) const override {
		return tr->transformBinaryOperation(this);
	}
private:
	Expression const* left_; // указатель на левый операнд
	Expression const* right_; // указатель на правый операнд
	int op_; // символ операции
};
struct FunctionCall : Expression // структура «Вызов функции»
{
	// в конструкторе надо учесть имя функции и ее аогумент
	FunctionCall(string const& name, Expression const* arg) : name_(name),
		arg_(arg)
	{
		assert(arg_);
		assert(name_ == "sqrt" || name_ == "abs");
	} // разрешены только вызов
//sqrt и abs
	string const& name() const
	{
		return name_;
	}
	Expression const* arg() const // чтение аргумента функции
	{
		return arg_;
	}
	~FunctionCall() override { delete arg_; } // освобождаем память в деструкторе
	virtual double evaluate() const override { // реализация виртуального метода
		//«вычислить»
		if (name_ == "sqrt")
			return sqrt(arg_->evaluate()); // либо вычисляем корень квадратный
		else return fabs(arg_->evaluate());
	} // либо модуль — остальные функции
//запрещены
	Expression* transform(Transformer* tr) const override {
		return tr->transformFunctionCall(this);
	}
private:
	string const name_; // имя функции
	Expression const* arg_; // указатель на ее аргумент
};
struct Variable : Expression // структура «Переменная»
{
	Variable(string const& name) : name_(name) { } //в конструкторе надо
	//указать ее имя
	string const& name() const { return name_; } // чтение имени переменной
	double evaluate() const override // реализация виртуального метода «вычислить»
	{
		return 0.0;
	}
	Expression* transform(Transformer* tr) const override {
		return tr->transformVariable(this);
	}
private:
	string const name_; // имя переменной
};

// Интерфейс Transformer (паттерн Visitor)
struct Transformer {
	virtual ~Transformer() {}

	virtual Expression* transformNumber(Number const*) = 0;
	virtual Expression* transformBinaryOperation(BinaryOperation const*) = 0;
	virtual Expression* transformFunctionCall(FunctionCall const*) = 0;
	virtual Expression* transformVariable(Variable const*) = 0;
};

struct DoubleTransformer : Transformer {
	Expression* transformNumber(Number const* num) override {
		return new Number(num->value() * 2);
	}

	Expression* transformBinaryOperation(BinaryOperation const* bin) override {
		Expression* newLeft = bin->left()->transform(this);
		Expression* newRight = bin->right()->transform(this);
		return new BinaryOperation(newLeft, bin->operation(), newRight);
	}

	Expression* transformFunctionCall(FunctionCall const* func) override {
		Expression* newArg = func->arg()->transform(this);
		return new FunctionCall(func->name(), newArg);
	}

	Expression* transformVariable(Variable const* var) override {
		return new Variable(var->name()); //переменные не меняем
	}
};

int main() {
	setlocale(LC_ALL, "russian");

	Expression* e = new BinaryOperation(
		new Number(5),
		BinaryOperation::MUL,
		new FunctionCall("sqrt", new Number(16))
	);

	cout << "Original: " << e->evaluate() << endl;

	Transformer* transformer = new DoubleTransformer();
	Expression* transformed = e->transform(transformer);

	cout << "Transformed: " << transformed->evaluate() << endl;

	delete e;
	delete transformed;
	delete transformer;
	return 0;
}