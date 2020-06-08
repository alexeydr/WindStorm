

#pragma once

#include "CoreMinimal.h"
#include "InteractActor.h"
#include "CableComponent.h"
#include "InteractCord.generated.h"

/**
 * 
 */
UCLASS()
class WINDSTORM_API AInteractCord : public AInteractActor
{
	GENERATED_BODY()

public:

	virtual void ActionOnInteract();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Action")
		bool StartCable;

	UFUNCTION(BlueprintImplementableEvent, Category = "Action")
		void ActionWithCable();

	
	
};
