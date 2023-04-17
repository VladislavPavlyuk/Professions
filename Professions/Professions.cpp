/*Спроектируйте систему профессий для RPG игры.Профессия в игре - это аналог игровых уровней.После получения каждой следующей профессии персонаж пользователя приобретает(усовершенствует) 
свои характеристики.
Например:
Человек воин имеет скорость перемещения 30 единиц, но после получения профессии «лучник» на его скорость влияет модификатор + 20. Если бы он стал не лучником, а меченосцем, 
то его модификатор скорости был бы меньше на 10 единиц по сравнению с человеком воином.

Описания всех профессий

Необходимо спроектировать архитектуру этого приложения, используя паттерн «Decorator».В этом случае при перемещении персонажа будут вызываться методы Move из всех внутренних 
объектов и к «0» будет применяться модификатор скорости.
*/

#include <iostream>
#include <string>

using namespace std;

// Component (Human) - компонент определяет интерфейс для объектов, на которые могут быть динамически возложены дополнительные обязанности
class Human abstract
{
protected:

	string name;

	short attack, speed, health, defence;

public:
	Human(string n, short a, short s, short h, short d)
	{
		name = n;
		attack = a;
		speed = s;
		health = h;
		defence = d;
	}
	virtual string GetName() abstract;

	virtual short GetAttack() abstract;

	virtual short GetSpeed() abstract;

	virtual short GetHealth() abstract;

	virtual short GetDefence() abstract;

};

// ConcreteComponent (WarriorComponent) - конкретный компонент определяет объект, на который возлагаются дополнительные обязанности
class WarriorComponent : public Human
{
public:
	WarriorComponent() : Human(" Warrior ", attack, speed, health, defence) {}

	string GetName() override
	{
		return name;
	}
	short GetAttack() override
	{
		return attack;
	}
	short GetSpeed() override
	{
		return speed;
	}
	short GetHealth() override
	{
		return health;
	}
	short GetDefence() override
	{
		return defence;
	}
};

// ConcreteComponent (Swordtail) - конкретный компонент определяет объект, на который возлагаются дополнительные обязанности
/*class _Swordtail : public Warrior
{
public:
	Swordtail(Human* h) : Warrior(h->GetAttack(), GetSpeed(), GetSpeed(), GetDefence())
	{ }
	short GetAttack()
	{
		return attack;
	}
	short GetSpeed()
	{
		return speed;
	}
	short GetHealth()
	{
		return health;
	}
	short GetDefence()
	{
		return defence;
	}
	//virtual int GetCost()abstract;
};*/

// Decorator (HumanDecorator) хранит ссылку на объект Component и определяет интерфейс, соответствующий интерфейсу Component
class HumanDecorator  abstract : public Human
{
protected:

	Human* human;

public:

	HumanDecorator( Human* human) : Human(" Human ",  20,  20,  150,  0){}
	
	string GetName() override
	{
		return name;;
	}
	short GetAttack() override
	{
		return attack;
	}
	short GetSpeed() override
	{
		return speed;
	}
	short GetHealth() override
	{
		return health;
	}
	short GetDefence() override
	{
		return defence;
	}
};

// ConcreteDecorator (WarriorDecorator) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class WarriorDecorator : public HumanDecorator
{
public:
	class WarriorDecorator(Human* human) :  HumanDecorator(human) {}
	
	string GetName() override
	{
		return name = " Warrior ";
	}

	short GetAttack() override
	{
		return human->GetAttack() + 10;
	}
	short GetSpeed() override
	{
		return human->GetSpeed() + 10;
	}
	short GetHealth() override
	{
		return human->GetHealth() + 50;
	}
	short GetDefence() override
	{
		return human->GetDefence() + 20;
	}
};

// ConcreteDecorator (SwordTailDecorator) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class SwordTailDecorator : public WarriorDecorator
{
public:
	SwordTailDecorator(Human *human) : WarriorDecorator(human) {}

	string GetName() override
	{
		return name = " Swordtail ";
	}
	
	short GetAttack() override
	{
		return human->GetAttack() + 40;
	}
	short GetSpeed() override
	{
		return human->GetSpeed() - 10;
	}
	short GetHealth() override
	{
		return human->GetHealth() + 50;
	}
	short GetDefence() override
	{
		return human->GetDefence() + 40;
	}
};

// ConcreteDecorator (ArcherDecorator) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class ArcherDecorator : public WarriorDecorator
{
public:
	ArcherDecorator(Human* human) : WarriorDecorator(human) {}

	string GetName() override
	{
		return name = " Archer ";
	}

	short GetAttack() override
	{
		return human->GetAttack() + 20;
	}
	short GetSpeed() override
	{
		return human->GetSpeed() + 20;
	}
	short GetHealth() override
	{
		return human->GetHealth() + 50;
	}
	short GetDefence() override
	{
		return human->GetDefence() + 10;
	}
};

void move(Human* human)
{
	char s[100];
	sprintf_s(s, "Name: %s\tAttack: %d\tSpeed: %d\tHealth: %d\tDefence: %d\n", human->GetName().c_str(), human->GetAttack(), human->GetSpeed(), human->GetHealth(), human->GetDefence());
	cout << s << endl;
}

int main()
{
	Human *human = new WarriorComponent();
	//human = new HumanDecorator(human);
	//move(human);

	Human *warrior = new WarriorDecorator(human);
	move(warrior);


	Human *swordtail = new SwordTailDecorator(human);
	move(swordtail);
	delete human;


	Human* archer = new ArcherDecorator(warrior);
	move(archer);

	delete human;
	delete warrior;
	delete archer;

	/*human = new Swordtail();
	p = new TomatoPizza(p);
	p = new CheesePizza(p);// болгарская пицца с томатами и сыром
	client(p);
	delete p;*/

	system("pause");
}