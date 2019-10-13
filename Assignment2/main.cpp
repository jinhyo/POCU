#include <cassert>
#include <iostream>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"

using namespace assignment2;

int main()
{
	Person* p = new Person("Bob", 85);

	assert(p->GetName() == std::string("Bob"));
	assert(p->GetWeight() == 85);

	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 78);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);

	Airplane a(5);
	a.AddPassenger(p);
	a.AddPassenger(p2);
	a.AddPassenger(p3);

	//
	//Airplane* c = new Airplane(5);
	//c->AddPassenger(p4);
	//c->AddPassenger(p5);
	//c->AddPassenger(p6);
	

	assert(a.GetMaxPassengersCount() == 5);
	assert(a.GetPassengersCount() == 3);
	assert(a.GetPassenger(1) == p2);
	assert(a.GetFlySpeed() == 648);
	assert(a.GetDriveSpeed() == 59);
	assert(a.GetMaxSpeed() == 648);

	//
	//a.RemovePassenger(0);
	//a.RemovePassenger(1);
	//c->RemovePassenger(1);
	//delete c;

	Boat b(5);
	b.AddPassenger(p4);
	b.AddPassenger(p5);
	b.AddPassenger(p6);

	Boatplane bp = a + b;

	assert(bp.GetPassengersCount() == 6);
	assert(bp.GetMaxPassengersCount() == 10);

	assert(a.GetPassengersCount() == 0);
	assert(b.GetPassengersCount() == 0);

	DeusExMachina* deusExMachina1 = DeusExMachina::GetInstance();
	DeusExMachina* deusExMachina2 = DeusExMachina::GetInstance();

	bool bSame = deusExMachina1 == deusExMachina2;
	assert(bSame);

	Airplane* airplane = new Airplane(5);
	Boat* boat = new Boat(5);
	Boatplane* boatplane = new Boatplane(5);
	Motorcycle* motorcycle = new Motorcycle();
	Sedan* sedan = new Sedan();
	Sedan* sedan2 = new Sedan();
	UBoat* uboat = new UBoat();

	bool bAdded = sedan2->AddTrailer(new Trailer(50));
	assert(bAdded);

	bAdded = sedan2->AddTrailer(new Trailer(60));
	assert(!bAdded);

	bAdded = deusExMachina1->AddVehicle(airplane);
	assert(bAdded);

	deusExMachina1->AddVehicle(boat);
	deusExMachina1->AddVehicle(boatplane);
	deusExMachina1->AddVehicle(motorcycle);
	deusExMachina1->AddVehicle(sedan);
	deusExMachina1->AddVehicle(sedan2);
	deusExMachina1->AddVehicle(uboat);
	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Airplane(5));

	bAdded = deusExMachina1->AddVehicle(new Airplane(5));

	assert(!bAdded);

	deusExMachina1->RemoveVehicle(9);
	deusExMachina1->RemoveVehicle(8);
	bool bRemoved = deusExMachina1->RemoveVehicle(7);
	assert(bRemoved);

	bRemoved = deusExMachina1->RemoveVehicle(9);
	assert(!bRemoved);

	/*std::cout << boat->GetMaxSpeed() << std::endl;
	std::cout << uboat->GetMaxSpeed() << std::endl;
	std::cout << a.GetMaxSpeed() << std::endl;*/

	deusExMachina1->Travel(); // ��� ��� ������ �̵� 
	std::cout << "0 airplane: " << airplane->GetDistance() << std::endl;
	std::cout << "1 boat: " << boat->GetDistance() << std::endl;
	std::cout << "2 boatplane: " << boatplane->GetDistance() << std::endl;
	std::cout << "3 motorcycle: " << motorcycle->GetDistance() << std::endl;
	std::cout << "4 sedan: " << sedan->GetDistance() << std::endl;
	std::cout << "5 sedan2: " << sedan2->GetDistance() << std::endl;
	std::cout << "6 uboat: " << uboat->GetDistance() << std::endl;
	std::cout << std::endl;
	deusExMachina1->Travel(); // Boat, Motorcycle, �� Sedan, UBoat�� �̵� 1 4 5 6
	std::cout << "0 airplane: " << airplane->GetDistance() << std::endl;
	std::cout << "1 boat: " << boat->GetDistance() << std::endl;
	std::cout << "2 boatplane: " << boatplane->GetDistance() << std::endl;
	std::cout << "3 motorcycle: " << motorcycle->GetDistance() << std::endl;
	std::cout << "4 sedan: " << sedan->GetDistance() << std::endl;
	std::cout << "5 sedan2: " << sedan2->GetDistance() << std::endl;
	std::cout << "6 uboat: " << uboat->GetDistance() << std::endl;
	std::cout << std::endl;
	deusExMachina1->Travel(); // Motorcycle, �� Sedan�� �̵� 3 4 5
	std::cout << "0 airplane: " << airplane->GetDistance() << std::endl;
	std::cout << "1 boat: " << boat->GetDistance() << std::endl;
	std::cout << "2 boatplane: " << boatplane->GetDistance() << std::endl;
	std::cout << "3 motorcycle: " << motorcycle->GetDistance() << std::endl;
	std::cout << "4 sedan: " << sedan->GetDistance() << std::endl;
	std::cout << "5 sedan2: " << sedan2->GetDistance() << std::endl;
	std::cout << "6 uboat: " << uboat->GetDistance() << std::endl;
	std::cout << std::endl;
	deusExMachina1->Travel(); // Boat, Motorcycle, �� Sedan�� �̵�1 3 4 5
	std::cout << "0 airplane: " << airplane->GetDistance() << std::endl;
	std::cout << "1 boat: " << boat->GetDistance() << std::endl;
	std::cout << "2 boatplane: " << boatplane->GetDistance() << std::endl;
	std::cout << "3 motorcycle: " << motorcycle->GetDistance() << std::endl;
	std::cout << "4 sedan: " << sedan->GetDistance() << std::endl;
	std::cout << "5 sedan2: " << sedan2->GetDistance() << std::endl;
	std::cout << "6 uboat: " << uboat->GetDistance() << std::endl;
	std::cout << std::endl;
	deusExMachina1->Travel(); // UBoat�� ���� ���� �̵� 0 1 2 3 4 5 7 8 9
	std::cout << "0 airplane: " << airplane->GetDistance() << std::endl;
	std::cout << "1 boat: " << boat->GetDistance() << std::endl;
	std::cout << "2 boatplane: " << boatplane->GetDistance() << std::endl;
	std::cout << "3 motorcycle: " << motorcycle->GetDistance() << std::endl;
	std::cout << "4 sedan: " << sedan->GetDistance() << std::endl;
	std::cout << "5 sedan2: " << sedan2->GetDistance() << std::endl;
	std::cout << "6 uboat: " << uboat->GetDistance() << std::endl;
	std::cout << std::endl;
	deusExMachina1->Travel(); // � ��� ���ܵ� �������� ���� zero
	std::cout << "0 airplane: " << airplane->GetDistance() << std::endl;
	std::cout << "1 boat: " << boat->GetDistance() << std::endl;
	std::cout << "2 boatplane: " << boatplane->GetDistance() << std::endl;
	std::cout << "3 motorcycle: " << motorcycle->GetDistance() << std::endl;
	std::cout << "4 sedan: " << sedan->GetDistance() << std::endl;
	std::cout << "5 sedan2: " << sedan2->GetDistance() << std::endl;
	std::cout << "6 uboat: " << uboat->GetDistance() << std::endl;
	std::cout << std::endl;
	deusExMachina1->Travel(); // Boat, Motorcycle, Ʈ���Ϸ� �� �޸� Sedan, UBoat�� �̵� 1 3 5 
	std::cout << "0 airplane: " << airplane->GetDistance() << std::endl;
	std::cout << "1 boat: " << boat->GetDistance() << std::endl;
	std::cout << "2 boatplane: " << boatplane->GetDistance() << std::endl;
	std::cout << "3 motorcycle: " << motorcycle->GetDistance() << std::endl;
	std::cout << "4 sedan: " << sedan->GetDistance() << std::endl;
	std::cout << "5 sedan2: " << sedan2->GetDistance() << std::endl;
	std::cout << "6 uboat: " << uboat->GetDistance() << std::endl;
	std::cout << std::endl;
	deusExMachina1->Travel(); // Boat, Motorcycle, �� Sedan, UBoat�� �̵� 1 3 4 5 6
	std::cout << "0 airplane: " << airplane->GetDistance() << std::endl;
	std::cout << "1 boat: " << boat->GetDistance() << std::endl;
	std::cout << "2 boatplane: " << boatplane->GetDistance() << std::endl;
	std::cout << "3 motorcycle: " << motorcycle->GetDistance() << std::endl;
	std::cout << "4 sedan: " << sedan->GetDistance() << std::endl;
	std::cout << "5 sedan2: " << sedan2->GetDistance() << std::endl;
	std::cout << "6 uboat: " << uboat->GetDistance() << std::endl;
	std::cout << std::endl;
	deusExMachina1->Travel(); // Airplane, Boatplane, Motorcycle, �� Sedan�� �̵� 0 2 3 4 5
	std::cout << "0 airplane: " << airplane->GetDistance() << std::endl;
	std::cout << "1 boat: " << boat->GetDistance() << std::endl;
	std::cout << "2 boatplane: " << boatplane->GetDistance() << std::endl;
	std::cout << "3 motorcycle: " << motorcycle->GetDistance() << std::endl;
	std::cout << "4 sedan: " << sedan->GetDistance() << std::endl;
	std::cout << "5 sedan2: " << sedan2->GetDistance() << std::endl;
	std::cout << "6 uboat: " << uboat->GetDistance() << std::endl;
	std::cout << std::endl;
	deusExMachina1->Travel(); // Boat, Motorcycle, �� Sedan�� �̵� 1 3 4 5
	std::cout << "0 airplane: " << airplane->GetDistance() << std::endl;
	std::cout << "1 boat: " << boat->GetDistance() << std::endl;
	std::cout << "2 boatplane: " << boatplane->GetDistance() << std::endl;
	std::cout << "3 motorcycle: " << motorcycle->GetDistance() << std::endl;
	std::cout << "4 sedan: " << sedan->GetDistance() << std::endl;
	std::cout << "5 sedan2: " << sedan2->GetDistance() << std::endl;
	std::cout << "6 uboat: " << uboat->GetDistance() << std::endl;
	std::cout << std::endl;
	deusExMachina1->Travel(); // Boat, Motorcycle, �� Sedan�� �̵� 1 3 4 5
	std::cout << "0 airplane: " << airplane->GetDistance() << std::endl;
	std::cout << "1 boat: " << boat->GetDistance() << std::endl;
	std::cout << "2 boatplane: " << boatplane->GetDistance() << std::endl;
	std::cout << "3 motorcycle: " << motorcycle->GetDistance() << std::endl;
	std::cout << "4 sedan: " << sedan->GetDistance() << std::endl;
	std::cout << "5 sedan2: " << sedan2->GetDistance() << std::endl;
	std::cout << "6 uboat: " << uboat->GetDistance() << std::endl;
	std::cout << std::endl;
	deusExMachina1->Travel(); // Ʈ���Ϸ� �޸� Sedan�� �̵� 5
	std::cout << "0 airplane: " << airplane->GetDistance() << std::endl;
	std::cout << "1 boat: " << boat->GetDistance() << std::endl;
	std::cout << "2 boatplane: " << boatplane->GetDistance() << std::endl;
	std::cout << "3 motorcycle: " << motorcycle->GetDistance() << std::endl;
	std::cout << "4 sedan: " << sedan->GetDistance() << std::endl;
	std::cout << "5 sedan2: " << sedan2->GetDistance() << std::endl;
	std::cout << "6 uboat: " << uboat->GetDistance() << std::endl;
	std::cout << std::endl;

	std::cout << deusExMachina1->GetFurthestTravelled() << std::endl;
	assert(deusExMachina1->GetFurthestTravelled() == boat);

	system("pause");
	return 0;
}