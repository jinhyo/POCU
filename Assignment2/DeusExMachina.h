#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		DeusExMachina();
		~DeusExMachina();
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

	private:
		static unsigned int mDeusMachineCount;
		static DeusExMachina* mDeusMachine;
		Vehicle* mMachineList[10];
		unsigned int mMachineCount = 0;
	};
}