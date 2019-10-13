#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina::DeusExMachina()
	{
	}

	DeusExMachina::~DeusExMachina()
	{
		for (size_t i = 0; i < mMachineCount; i++)
		{
			delete mMachineList[i];
		}
		
		//delete[]  mMachineList;와 뭐가 다른건지...
		delete[] & mMachineList;
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mDeusMachineCount > 0)
		{
			return mDeusMachine;
		}

		mDeusMachine = new DeusExMachina;
		mDeusMachineCount++;
		return mDeusMachine;
	}

	void DeusExMachina::Travel() const
	{
		for (size_t i = 0; i < mMachineCount; i++)
		{
			mMachineList[i]->Move();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mMachineCount < 10)
		{
			mMachineList[mMachineCount++] = vehicle;
			return true;
		}

		return false;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i < mMachineCount)
		{
			//delete mMachineList[i];
			mMachineList[i] = NULL;
			for (size_t j = i; j < mMachineCount - 1; j++)
			{
				mMachineList[j] = mMachineList[j + 1];
			}
			mMachineCount--;

			return true;
		}
		return false;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mMachineCount == 0)
		{
			return NULL;
		}

		if (mMachineList[0]->GetDistance() == 0)
		{
			return mMachineList[0];
		}

		unsigned int index = 0;
		for (size_t i = 1; i < mMachineCount; i++)
		{
			unsigned int maxSpeed = mMachineList[0]->GetMaxSpeed();
			if (mMachineList[i]->GetMaxSpeed() > maxSpeed)
			{
				index = i;
			}
		}
		return mMachineList[index];
	}

	unsigned int DeusExMachina::mDeusMachineCount = 0;
	DeusExMachina* DeusExMachina::mDeusMachine = NULL;
}