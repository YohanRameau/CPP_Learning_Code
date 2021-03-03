#pragma once

#include "Person.h"

class Phone
{
public:
	
	//virtual ~Phone() ;

	//virtual void ring() const { _owner.answer_phone(); }
	virtual void ring() const = 0;

protected:
	Phone(const Person& owner)
		: _owner { owner }
	{}
	const Person& _owner;
};

class HomePhone : public Phone
{
public:

	HomePhone(const Person& owner)
	    : Phone(owner)
	{}

    HomePhone(const Person& owner, int position)
	    : Phone(owner),
		  _position {position}
	{}

	//~HomePhone() override {}

	void ring() const override
	{
		if (_position == _owner.get_position())
		{
			_owner.answer_phone();
			return; 
		}
		std::cout << "This is the voicemail of " << _owner.get_name() << ". Please leave a message." << std::endl;
		
	}

private:
	int _position = 0;
};

class MobilePhone : public Phone
{
public:
	MobilePhone(const Person& owner)
	    : Phone(owner)
	{}
	//~MobilePhone() override {}
	void ring() const override { _owner.answer_phone(); }
private:

};