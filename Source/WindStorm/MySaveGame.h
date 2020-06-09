

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class WINDSTORM_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	FVector MainCharLocation;
	
	UPROPERTY(VisibleAnywhere)
	FVector AllyLocation;

	UPROPERTY(VisibleAnywhere)
		float MainCharHealth;

	UPROPERTY(VisibleAnywhere)
		float AllyHealth;

	UPROPERTY(VisibleAnywhere)
		float MainCharTemp;

	UPROPERTY(VisibleAnywhere)
		float AllyTemp;


	UPROPERTY(VisibleAnywhere)
	uint32 UserIndex;
};
