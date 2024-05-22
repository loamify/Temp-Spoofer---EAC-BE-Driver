#include <ntifs.h>
#include "shared.h"

#include "disks.h"
#include "smbios.h"

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT object, PUNICODE_STRING registry)
{
	UNREFERENCED_PARAMETER(object);
	UNREFERENCED_PARAMETER(registry);

	Disks::DisableSmart();
	Disks::ChangeDiskSerials(); // ctrl + f search "point 19484" to make disk serials more realistic (MAY CAUSE ISSUES WITH NOT SPOOFING ON CERTAIN DISKS)
	Smbios::ChangeSmbiosSerials(); // use "net stop winmgmt" and "net start winmgmt" in command prompt after otherwise bios wont change

	return STATUS_SUCCESS;
}