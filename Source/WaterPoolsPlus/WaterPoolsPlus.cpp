#include "WaterPoolsPlus.h"

#include "Hologram/FGWaterPumpHologram.h"
#include "Patching/NativeHookManager.h"

void FWaterPoolsPlusModule::StartupModule() {
	if (!WITH_EDITOR)
	{
		SUBSCRIBE_METHOD(AFGWaterPumpHologram::CheckMinimumDepth, [](auto& Scope, AFGWaterPumpHologram* Self)
		{
			Scope.Cancel();
		});
	}
}

IMPLEMENT_GAME_MODULE(FWaterPoolsPlusModule, WaterPoolsPlus);