

#pragma once

#include "CoreMinimal.h"
#include "InteractActor.h"
#include "FireActor.generated.h"

/**
 * 
 */
UCLASS()
class WINDSTORM_API AFireActor : public AInteractActor
{
	GENERATED_BODY()
	

public:

	void SpawnActor();

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AFireActor> ClassForSpawn;

	virtual void ActionOnInteract();

	void SpawnThis(AFireActor* Act);

};
