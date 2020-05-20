//=====================================================================================

#pragma once

#include "Engine/Engine.hpp"

//=====================================================================================

namespace ProtoGenesys
{
	class cHooks
	{
	public:

		cHooks() : _thunkVectoredExceptionHandler(&cHooks::VectoredExceptionHandler, this) {}

		typedef enum
		{
			VEH_INDEX_CONNECTPATHS = 2104,
			VEH_INDEX_MOUSEACCEL = 22152,
			VEH_INDEX_DRAWBIGFPS = 33553,
			VEH_INDEX_MAXCLIENTS = 33558,
			VEH_INDEX_NODELTA = 33833
		} eVehIndex;

		QWORD qwXuidOverride;

		int iFriendCount;
		std::vector<std::pair<QWORD, std::string>> vFriends;

		DWORD dwConnectPaths, dwMouseAccel, dwDrawBigFPS, dwMaxClients, dwNoDelta, dwSysValue, dwShader, dwAddress;
		DWORD_PTR dwSteamUserFunc, dwSteamUserVTable, dwSteamFriendsFunc, dwSteamFriendsVTable;

		LPTOP_LEVEL_EXCEPTION_FILTER pUnhandledExceptionFilter;
		LPVOID pVectoredExceptionHandler;

		LONG VectoredExceptionHandler(_In_ LPEXCEPTION_POINTERS ExceptionInfo);
		typedef LONG(CALLBACK* tVectoredExceptionHandler)(_In_ LPEXCEPTION_POINTERS ExceptionInfo);

		BOOL PageGuardSVFK();
		BOOL PageGuardAddress(DWORD address);
		BOOL PatchAntiCheat();

		void DrawBigFPS();
		void PredictPlayerState();
		void WritePacket();
		void KillSpam(DWORD attacker, DWORD victim);
		void BulletHitEvent(int localnum, int sourcenum, int targetnum, int weapon, Vector3 start, Vector3 position, Vector3 normal, Vector3 alphanormal, int surface, int _event, int param, int contents, char bone);
		void TransitionPlayerState(int localnum, sPlayerState* playerstate, LPVOID transplayerstate);
		void CalcEntityLerpPositions(int localnum, sCEntity* entity);
		void GetWorldTagMatrix(LPVOID pose, LPVOID dobj, WORD tag, Vector3 matrix[], Vector3 origin);
		void GetAddr(bool renew);
		
		int GameTypeSettings(int settings);
		int GetPlayerStatus(int localnum, DWORD xuid1, DWORD xuid2);
		bool SteamIDIsValid(DWORD** _this);

		sSteamID GetSteamID(sSteamID steamid);
		LPCSTR GetPersonaName(LPCSTR name);
		int GetFriendCount(DWORD** _this, void* edx, eFriendFlags friendflags);
		sSteamID GetFriendByIndex(DWORD** _this, void* edx, QWORD* steamid, int _friend, eFriendFlags friendflags);
		ePersonaState GetFriendPersonaState(DWORD** _this, void* edx, sSteamID steamid);
		LPCSTR GetFriendPersonaName(DWORD** _this, void* edx, sSteamID steamid);
		bool GetFriendGamePlayed(sSteamID steamid, int unk1, int unk2, sFriendGameInfo* friendgameinfo);

		int Atoi1(int result);
		int Atoi2(int result);

		std::string Randomize(std::string name);
		void RefreshFriends();

		StdThunk<tVectoredExceptionHandler, cHooks> _thunkVectoredExceptionHandler;
	} extern _hooks;
}

//=====================================================================================