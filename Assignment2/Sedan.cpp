#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
	{
	}

	// �߰� �ڵ�
	Sedan::Sedan(const Sedan& other)
		: Vehicle(other)
	{
		if (mTrailerPointer != nullptr)
		{
			mTrailerPointer = new Trailer(other.GetTrailer()->GetWeight());
		}
	}

	Sedan::~Sedan()
	{
		RemoveTrailer();
	}

	// �߰��ڵ�
	Sedan& Sedan::operator=(const Sedan& other)
	{
		if (this == &other)
		{
			return *this;
		}

		RemoveTrailer();
		mTrailerPointer = nullptr;
		if (other.GetTrailer() != nullptr)
		{
			mTrailerPointer = new Trailer(other.GetTrailer()->GetWeight());
		}

		Vehicle::operator=(other);
		return *this;
	}

	

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		// Ʈ���Ϸ��� �߰��Ѵٴ� �� ���Ը� �߰��ϸ� �Ǵ°ɱ�? 
		// �׳� �����͸� �߰��ϰ� ���Դ� �ʿ��� �� �������� �� ��
		/*if (mTrailerPointer != nullptr)
		{
			return false;
		}*/
		//�Ʒ� �ڵ� ��� ���� �ڵ带 ����ص� ��

		if (mTrailerWeight > 0)
		{
			return false;
		}

		mTrailerPointer = trailer;
		mTrailerWeight = trailer->GetWeight();

		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailerWeight == 0)
		{
			return false;
		}

		mTrailerWeight = 0;
		delete mTrailerPointer;
		return true;
	}

	const Trailer* Sedan::GetTrailer() const
	{
		return mTrailerPointer;
	}


	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int x = GetMaxPassengersWeight() + mTrailerWeight;

		if (x <= 80)
		{
			return 480;
		}

		if (x <= 160)
		{
			return 458;
		}

		if (x <= 260)
		{
			return 400;
		}

		if (x <= 350)
		{
			return 380;
		}

		if (x > 350)
		{
			return 300;
		}
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	void Sedan::Move()
	{
		if (mMoveCount < 5)
		{
			mMoveCount++;
			mDistance += GetMaxSpeed();
			return;
		}

		if (mMoveCount == 5)
		{
			mBreakCount++;
		}

		else if (mTrailerWeight == 0)
		{
			if (mBreakCount == 1)
			{
				mMoveCount = 0;
			}
		}

		else if (mTrailerWeight != 0)
		{
			if (mBreakCount == 2)
			{
				mMoveCount = 0;
				mBreakCount = 0;
			}
		}
	}

	/* �̷� ��ĵ� ����
	unsigned Sedan::GetTravelledDistance() const
	{
		unsigned distance = 0;
		for (unsigned i = 1; i <= mTravelCount; i++)
		{
			if (mTrailer == nullptr)
			{
				if (i % 6 != 0)
				{
					distance += GetMaxSpeed();
				}
			}

			else
			{
				if (i % 7 != 0 && i % 7 != 6)
				{
					distance += GetMaxSpeed();
				}
			}
		}

		return distance;
	}
	*/
}