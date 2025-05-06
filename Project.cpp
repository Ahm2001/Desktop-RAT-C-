#include <Windows.h>

BOOL was_dllmain_called = FALSE;
DWORD dll_param;

extern "C" __declspec(dllexport) void FUNENTRY()
{

	char dll_path[MAX_PATH];
	DWORD ret = GetModuleFileNameA((HINSTANCE)dll_param, dll_path, MAX_PATH);
	char test[1024];
	wsprintfA(test, , "%s", dll_path);
	MessageBoxA(0, test, "", 0);
	// inject dll inside remote process

}


BOOL APIENTRY DllMain(HMODULE Base, DWORD Callback, LPVOID Param)
{
	
	dll_param = (DWORD)Base;
	was_dllmain_called = TRUE;

	switch (Callback)
	{
	case DLL_PROCESS_ATTACH:
		
	break;

	case DLL_PROCESS_DETACH:

	break;

	

	}
	return TRUE;



}




extern "C" __declspec(dllexport) void MAINENTRY()
{
	if (was_dllmain_called)
	{
		char exe[MAX_PATH + 1];
		GetModuleFileNameA(0, exe, sizeof(exe));
		MessageBoxA(0, exe, "FOMA.dll, I am inside", 0);

	}

	else
	{

	}


}
