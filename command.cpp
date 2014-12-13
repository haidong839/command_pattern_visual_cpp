// command.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
using namespace System;

ref class Light
{
private:
	bool on;

public:
	void switchOn()
	{
		on = true;
		Console::WriteLine("Light is ON");
	}
	void switchOff()
	{
		on = false;
		Console::WriteLine("Light is OFF");
	}
};

ref class Command abstract {
public:
	virtual void execute() = 0;
};

ref class LightOnCommand : Command {
public:
	Light^ light;
	LightOnCommand(Light^ light)
	{
		this->light = light;
	}

	virtual void execute() override 
	{
		light->switchOn();
	}
};

ref class LightOffCommand : Command {
public:
	Light^ light;
	LightOffCommand(Light^ light)
	{
		this->light = light;
	}

	virtual void execute() override 
	{
		light->switchOff();
	}
};

ref class RemoteControl{

private:
	Command^ command;

public:
	void setCommand(Command^ command)
	{
		this->command = command;
	}

	void pressButton()
	{
		command->execute();
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	RemoteControl^ control = gcnew RemoteControl();

	Light^ light = gcnew Light();

	Command^ lightsOn = gcnew LightOnCommand(light);
	Command^ lightsOff = gcnew LightOffCommand(light);

	control->setCommand(lightsOn);
	control->pressButton();

	control->setCommand(lightsOff);
	control->pressButton();

	Console::ReadLine();
	return 0;
}

