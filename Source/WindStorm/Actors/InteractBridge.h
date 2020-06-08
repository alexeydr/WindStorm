

#pragma once

#include "CoreMinimal.h"
#include "InteractActor.h"
#include "InteractBridge.generated.h"

/**
 * 
 */
UCLASS()
class WINDSTORM_API AInteractBridge : public AInteractActor
{
	GENERATED_BODY()

public:

	virtual void ActionOnInteract();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Action")
		FRotator Rotation;

	UFUNCTION(BlueprintImplementableEvent, Category = "Action")
		void RotateObj();
	
};
