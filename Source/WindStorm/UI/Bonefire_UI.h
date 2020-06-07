

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WindStorm\UI\SitcksInInventory.h"
#include "Bonefire_UI.generated.h"

/**
 * 
 */
UCLASS()
class WINDSTORM_API UBonefire_UI : public UUserWidget
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UVerticalBox* Items;


public:

	void RemoveChildFromVB(class USitcksInInventory* Elem);

	class ABonefire* Owner;

	virtual void SynchronizeProperties() override;

	void AddItems(class AStick* Stick, TSubclassOf<USitcksInInventory> StickInInvUI);
	
};
