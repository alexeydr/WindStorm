

#pragma once

#include "CoreMinimal.h"
#include "InteractActor.h"
#include "WindStorm\UI\SitcksInInventory.h"
#include "WindStorm\UI\Bonefire_UI.h"
#include "Bonefire.generated.h"

/**
 * 
 */
UCLASS()
class WINDSTORM_API ABonefire : public AInteractActor
{
	GENERATED_BODY()

protected:
	
	virtual void BeginPlay() override;

	void OnBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;
	 
	void OnEndOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex) override;

	float Lifetime = 10.f;

	UFUNCTION(BlueprintImplementableEvent, Category = "UI")
		void ShowTime();
	
	UFUNCTION()
	void OnWarm();

	UFUNCTION()
		void OnLifetimeComplete();


	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<USitcksInInventory> StickInInvUI;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UBonefire_UI> UI_Class;

	UPROPERTY()
	TArray<class AHeroCharacter*> Chars;

	UPROPERTY(BlueprintReadOnly)
	FTimerHandle BurnHandle;

	class UBonefire_UI* WidgetRef;

public:

	void OnAddStick(float Time);

	virtual void ActionOnInteract();


	
};
