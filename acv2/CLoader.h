#include "CDirectX.h"
#include "CProcessList.h"
#include "CInjectedLibraries.h"
#include "CDirectoryScanner.h"

class CLoader 
{
public:

	// PURPOSE: Initialize main program.
	// REQUIRES: The current .asi's HMODULE.
	// PROMISE: Program main facilities will be initiated.
	static void Initialize(HMODULE hMod);

	// PURPOSE: Relaunch gta_sa as an elevated process.
	// REQUIRES: NULL
	// PROMISE: The program will be relaunched as an elevated process, and then the current process will exit.
	static void RunElevated();

	static CInjectedLibraries Modules;
	static CProcessList Processes;
	static CDirectoryScanner GtaDirectory;

private:
	// PURPOSE: Check elevation of the program, and elevate if necessary.
	// REQUIRES: NULL
	// PROMISE: An elevated process after it returns.
	static void CheckElevation();

	// PURPOSE: Determine if the process is elevated.
	// REQUIRES: NULL
	static BOOL IsProcessElevated();

};