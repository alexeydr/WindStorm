

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inventory.generated.h"

/**
 * 
 */
UCLASS()
class WINDSTORM_API UInventory : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* Effect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* Drop;



protected:

	

	virtual void SynchronizeProperties() override;

};
