#pragma once

#include "IceCube.h"
#include "ObjectPool.h"

namespace lab9
{
	class Game final
	{
	public:
		Game(unsigned int seed, unsigned int poolSize);
		Game(const Game& other) = delete;
		~Game();

		Game& operator=(const Game&) = delete;
		void Spawn();
		void Update();
		const std::vector<IceCube*>& GetActiveGameObjects() const;
		ObjectPool<IceCube>& GetObjectPool();

	private:
		enum { MAX_FRAME_COUNT_TO_LIVE = 100 };
		std::vector<IceCube*> mActiveGameObjects;
		ObjectPool<IceCube> mPool;
	};
}