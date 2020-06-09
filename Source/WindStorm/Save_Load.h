

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Save_Load.generated.h"

/**
 * 
 */
UCLASS()
class WINDSTORM_API USave_Load : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Save/Load")
		static void SaveGame(UObject * WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Save/Load")
		static void LoadGame(UObject * WorldContextObject);

};
