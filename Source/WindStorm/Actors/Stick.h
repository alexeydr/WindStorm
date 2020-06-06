

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

	UPROPERTY(EditAnywhere)
		FString Name;

	UPROPERTY(EditAnywhere)
		float BurnTime = 5.f;

	virtual void ActionOnInteract();
	
};
