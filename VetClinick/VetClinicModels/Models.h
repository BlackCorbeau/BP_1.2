#pragma once
#include <iostream>
#include "..\TimeLib\class.h"
#include "..\TimeLib\CDate.h"
#include "..\TimeLib\functions.h"
#include "..\StringLib\string.h"
#include "..\Archivelib\archive.h"
#include "..\Experience\CExperience.h"
#include <vector>


struct Clients
{
	TArchive<int> user_id;
	int count = user_id.size();
};

struct Doktors
{
	TArchive<int> Doktors_ID;
	int count = Doktors_ID.size();
};

struct Pets
{
	TArchive<int> Pets_id;
	int count = Pets_id.size();
};

struct Receptions
{
	TArchive<int> Receptions_id;
	int count = Receptions_id.size();
};
class human
{
	CString name;
	CString surname;
	CString TelelefonNumber;
	CString Adress;
};

class Pet
{
	Client* client;
	CString Nickname;
	int age;
	int weight;
};

class Ilness
{
	CString name;
};

class Doktor : human //Doktors.txt
{
	int id;
	CString password;
	CString spetialization;
	TArchive<CTime[4]> T;
	CExperience exp;
	CString university;
public:
	Doktor();
	void Registrate_Pet();
	void Create_Reception(CTime start_time, CTime Finish_time);
	void Close_Reception(int Reception_id);
};

class Client : human
{
	int id;
	CString Password;
	TArchive<Reception> Receptions;
	TArchive<Pet> Pets;
public:
	void Sign_up_reception(int Reception_id);
	void Cancel_sign_up(int Reception_id);
};

class Reception
{
	enum State {FREE, OCCUPED, CLOSED};
	Client* client;
	Doktor* doc;
	CDate date;
	CTime time;
	State status;

};

class cart_of_ilnesses
{
	Pet* pet;
	enum State {Il, IN_PROCESS, RECOVERED, IS_NOT_POSSIBLE};
	TArchive<Ilness*> Ilnesses;
	TArchive<CDate> Date_of_ilness;
	TArchive<CString> Indications;
	TArchive<State> status;
};

class Cat : Pet
{
	Ilness* ilness;
};

class Dog : Pet
{
	Ilness* ilness;
};

class Bird : Pet
{
	Ilness* ilness;
};

class Rodent : Pet
{
	Ilness* ilness;
};

class Reptile : Pet
{
	Ilness* ilness;
};

class Fish : Pet
{
	Ilness* ilness;
};

bool remove_line(const char* filename, size_t index);