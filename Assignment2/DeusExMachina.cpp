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
		
		//delete[]  mMachineList; 다른 코드에서는 이게 없음(스택에 생성되서)
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mDeusMachineCount > 0)
		{
			return mDeusMachine;
		}

		mDeusMachine = new DeusExMachina();
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
		// 추가 코드
		if (vehicle == nullptr)
		{
			return false;
		}
		//

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
			delete mMachineList[i];
			mMachineCount--;
			for (; i < mMachineCount; i++)
			{
				mMachineList[i] = mMachineList[i + 1];
			}

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
		unsigned int maxSpeed = mMachineList[0]->GetDistance();
		for (size_t i = 1; i < mMachineCount; i++)
		{
			if (mMachineList[i]->GetDistance() > maxSpeed)
			{
				maxSpeed = mMachineList[i]->GetDistance();
				index = i;
			}
		}
		return mMachineList[index];
	}

	unsigned int DeusExMachina::mDeusMachineCount = 0;
	DeusExMachina* DeusExMachina::mDeusMachine = NULL;
}