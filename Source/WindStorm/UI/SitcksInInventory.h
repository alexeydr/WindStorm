

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SitcksInInventory.generated.h"

/**
 * 
 */
UCLASS()
class WINDSTORM_API USitcksInInventory : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* Effect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetOptional))
		class UButton* Add;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetOptional))
		class UButton* Drop;

	UFUNCTION()
		void OnAddClicked();

	UFUNCTION()
		void OnDropClicked();

	float Eff;

public:

	class AStick* StickInInv;

	class UBonefire_UI* Own;

	virtual void SynchronizeProperties() override;

	void SetParams(FString ItemName, float ItemEffect);
	
};
