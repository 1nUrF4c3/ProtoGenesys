//=====================================================================================

#pragma once

#include "../Engine/Engine.hpp"

//=====================================================================================

namespace ProtoGenesys
{
	class cRemovals
	{
	public:

		void RecoilCompensation();
		void SpreadCompensation(sUserCmd* usercmd, int servertime);
		void FirstBulletFix();
	} extern _removals;
}

//=====================================================================================