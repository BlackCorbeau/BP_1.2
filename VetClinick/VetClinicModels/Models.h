#pragma once
#include <iostream>
#include <class.h>
#include <CDate.h>
#include <functions.h>
#include <string.h>
#include <archive.h>
#include <CExperience.h>
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
	int id;
	int Client_id;
	CString Nickname;
	int age;
	int weight;
};

class Ilness
{
	int id;
	CString name;
	int animal_type;
	CString syptomes;
};

class Doktor : human //Doktors.txt
{
	int id;
	CString password;
	CString spetialization;
	TArchive<CTime[4]> T;
	CExperience exp;
	CString university;
	int access_level = 1;
public:
	Doktor();
	void Registrate_Pet();
	void Create_Reception();
	void Close_Reception();

	void writeToFile(const std::string& filename);
	void readFromFile(const std::string& filename);
};

class Client : human
{
	int id;
	TArchive<int> Record_id;
	TArchive<int> Pets_id;
	int access_level = 0;
public:
	void Sign_up_reception();
	void delet_sign_up();
};

class Admin : human
{
	int id;
	int password;

public:
	void Add_Doktor();
	void Check_log();
	void Check_acsess_level();
	void Find_in_file();
	void download_strukts();
};

class Reception
{
	int id;
	enum State {FREE, OCCUPED, CLOSED};
	int Client_id;
	int doctor_id; 
	CDate date;
	CTime time;
	State status;

};

class cart_of_ilnesses
{
	enum State {Il, IN_PROCESS, RECOVERED, IS_NOT_POSSIBLE};
	int pet_id;
	TArchive<int> Ilnesses_id;
	TArchive<CDate> Date_of_ilness;
	TArchive<CString> Indications;
	TArchive<State> status;
};

class Cat : Pet
{
	int type_id = 001;
	int ilness_id;
};

class Dog : Pet
{
	int type_id = 002;
	int ilness_id;
};

class Bird : Pet
{
	int type_id = 003;
	int ilness_id;
};

class Rodent : Pet
{
	int type_id = 004;
	int ilness_id;
};

class Reptile : Pet
{
	int type_id = 005;
	int ilness_id;
};

bool remove_line(const char* filename, size_t index);