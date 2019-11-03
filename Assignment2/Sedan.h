#pragma once

#include "IDrivable.h"
#include "Trailer.h"
#include "Vehicle.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		Sedan(const Sedan& other);
		~Sedan();

		Sedan& operator=(const Sedan& other);

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		const Trailer* GetTrailer() const;
		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;
		void Move();

	private:
		unsigned int mTrailerWeight = 0;
		const Trailer* mTrailerPointer = NULL;
	};
}