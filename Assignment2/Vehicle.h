#pragma once

#include "Person.h"

# define M_E (2.7182818284590452354)

namespace assignment2
{
	class Vehicle
	{
	public:
		friend class Airplane;
		friend class Boat; 
		friend class Boatplane; 
		
		Vehicle();
		Vehicle(unsigned int maxPassengersCount);
		~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;
		virtual void Move() = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetMaxPassengersWeight() const;

	private:
		unsigned int mBreakCount = 0;
		unsigned int mDistance = 0;
		unsigned int mMaxPassengerNumber;
		unsigned int mMoveCount = 0;
		unsigned int mPassengerCount= 0;
		const Person** mPassengers;
	};
}