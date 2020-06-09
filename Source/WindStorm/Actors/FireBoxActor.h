

#pragma once

#include "CoreMinimal.h"
#include "InteractActor.h"
#include "FireBoxActor.generated.h"

/**
 * 
 */
UCLASS()
class WINDSTORM_API AFireBoxActor : public AInteractActor
{
	GENERATED_BODY()


public:

	virtual void ActionOnInteract();


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int Amount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class AFireActor* Act;
	
};
