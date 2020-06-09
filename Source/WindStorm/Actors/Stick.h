

#pragma once

#include "CoreMinimal.h"
#include "InteractActor.h"
#include "Stick.generated.h"

/**
 * 
 */
UCLASS()
class WINDSTORM_API AStick : public AInteractActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AStick> ClassForSpawn;

	void SpawnThis(AStick* Stick);


	UPROPERTY(EditAnywhere)
		float BurnTime = 5.f;

	virtual void ActionOnInteract();
	
};
