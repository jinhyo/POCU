#include "Vehicle.h"
#include <algorithm>

namespace assignment2
{
	Vehicle::Vehicle()
	{
	}

	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengerNumber(maxPassengersCount)
	{
		mPassengers = new const Person * [mMaxPassengerNumber];
	}

	// �߰� �ڵ�
	Vehicle::Vehicle(const Vehicle& other)
		: mMaxPassengerNumber(other.mMaxPassengerNumber)
		, mPassengerCount(other.mPassengerCount)
	{
		mPassengers = new const Person * [mMaxPassengerNumber];
		for (size_t i = 0; i < mPassengerCount; i++)
		{
			const char* name = other.mPassengers[i]->GetName();
			const unsigned weight = other.mPassengers[i]->GetWeight();
			mPassengers[i] = new Person(name, weight);
		}
	}

	Vehicle::~Vehicle()
	{
		// if�� ���� ���� �Ʒ��� ������ �߻���(��� ���������� �۵� �ؾ���)
		/*if (mPassengers != NULL)
		{*/
			// �̰� �ϸ� Boatplane&& other �������� �� ������ ���� ������ �𸣰���
			for (size_t i = 0; i < mPassengerCount; i++)
			{
				delete mPassengers[i];
			}

			// delete[] & mPassengers; ???
			delete[] mPassengers;
		//}
		
	}
	
	// �߰� �ڵ�
	Vehicle& Vehicle::operator = (const Vehicle& other)
	{
		if (this == &other)
		{
			return *this;
		}

		for (size_t i = 0; i < mPassengerCount; i++)
		{
			delete mPassengers[i];
		}
		delete mPassengers;

		mMaxPassengerNumber = other.GetMaxPassengersCount();
		mPassengerCount = other.GetPassengersCount();
		mPassengers = new const Person * [mMaxPassengerNumber];

		for (size_t i = 0; i < mMaxPassengerNumber; i++)
		{
			const char* name = other.mPassengers[i]->GetName();
			const unsigned weight = other.mPassengers[i]->GetWeight();
			mPassengers[i] = new Person(name, weight);
		}
		
		return *this;
	}


	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mPassengerCount >= mMaxPassengerNumber)
		{
			return false;
		}
		
		// �߰� �ڵ�
		if (person == nullptr)
		{
			return false;
		}

		// �߰� �ڵ�
		for (unsigned i = 0; i < mPassengerCount; i++)
		{
			if (mPassengers[i] == person)
			{
				return false;
			}
		}

		mPassengers[mPassengerCount++] = person;

		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (mPassengerCount <= i)
		{
			return false;
		}
		
		delete mPassengers[i];
		mPassengerCount--;

		// i < mPassengerCount - 1 ���� i < mPassengerCount�� �����ϰ�
		// mPassengerCount--�� for�� �Ʒ����� ���� �ø�
		for (; i < mPassengerCount; i++)
		{
			mPassengers[i] = mPassengers[i + 1];
		}

		// mPassengers[i] = nullptr; // �ٸ������ �ڵ忡���� ������(�� �ʿ�����?)

		return true;
	}

	unsigned int Vehicle::GetDistance() const
	{
		return mDistance;
	}


	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPassengerCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengerNumber;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (mPassengerCount <= i)
		{
			return NULL;
		}

		return mPassengers[i];
	}

	// �߰� �ڵ�(��� ���°ɱ�?: �ٸ� ��ü�� �߰��ϴ� �Լ��ε�)
	/*
	void Vehicle::TransferPassengers(Vehicle& dest)
	{
		for (unsigned i = 0; i < mPassengersCount; i++)
		{
			dest.mPassengers[dest.mPassengersCount] = mPassengers[i];
			++dest.mPassengersCount;

			mPassengers[i] = nullptr;
		}

		mPassengersCount = 0;
	}
	*/
	unsigned int Vehicle::GetMaxPassengersWeight() const
	{
		unsigned int totalWeight = 0;
		for (size_t i = 0; i < mPassengerCount; i++)
		{
			totalWeight += mPassengers[i]->GetWeight();
		}

		return totalWeight;
	}

	unsigned int Vehicle::GetMoveCount() const
	{
		return mMoveCount;
	}

}