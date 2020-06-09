

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Delegates/IDelegateInstance.h"
#include "UObject/UObjectGlobals.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class WINDSTORM_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	
	UMyGameInstance();

	UFUNCTION(BlueprintCallable, Category = "Save/Load")
		void OpenLevel(FName LocName);

	UFUNCTION()
		void ChangeLevel(UWorld* World);

	FDelegateHandle Load_Map_Delegate;


};
