

#pragma once

#include "CoreMinimal.h"
#include "UI\SitcksInInventory.h"
#include "UI\Bonefire_UI.h"
#include "GameFramework/Character.h"
#include "HeroCharacter.generated.h"

UCLASS()
class WINDSTORM_API AHeroCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHeroCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		FString CharName;
		
protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		bool NeedTemperature = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		float Health = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		float Temperature = 100.f;
	
	void Dead();

	bool Freeze = false;

	UFUNCTION()
		void OnFreeze();

	UFUNCTION(BlueprintImplementableEvent, Category = "UI")
		void UpdateUI();

	UFUNCTION(BlueprintImplementableEvent, Category = "UI")
		void CreateFreezeUI();

	UFUNCTION(BlueprintImplementableEvent, Category = "UI")
		void RemoveFreezeUI();

	UFUNCTION(BlueprintImplementableEvent, Category = "Fire")
		void EffectFire(bool AttachOrDeattach);

	bool FlipFlop = true;

	UFUNCTION()
		void GetFire();

	UFUNCTION()
		void Interaction();

	UFUNCTION()
		void OpenInventory();

	UFUNCTION()
		void SpawnBonefire();

	UPROPERTY(EditDefaultsOnly, Category = "BonefireClass")
		TSubclassOf<ABonefire> BonefireClass;

	UPROPERTY(EditDefaultsOnly, Category = "WidgetClass")
		TSubclassOf<USitcksInInventory> StickUIClass;

	UPROPERTY(EditDefaultsOnly, Category = "WidgetClass")
	TSubclassOf<UBonefire_UI> InventoryWidgetClass;

	UPROPERTY()
	class UBonefire_UI* WidgetRef;

public:	

	TArray<class AInteractActor*> Inventory;

	class AInteractActor* InteractActor;

	bool InWarm = false;

	FORCEINLINE void AddHealth(float NewHealth) {
		this->Health = FMath::Clamp(this->Health += NewHealth, 0.f, 100.f);
		if (Health == 0)
		{
			this->Dead();
		}
		this->UpdateUI();
	};

	FORCEINLINE void SetHealth(float NewHealth) { this->Health = NewHealth; };

	FORCEINLINE float GetHealth() { return Health; };

	FORCEINLINE void AddTemperature(float NewTemperature) { 
		this->Temperature = FMath::Clamp(this->Temperature += NewTemperature, 0.f, 100.f);
		if (Temperature == 0)
		{
			this->CreateFreezeUI();
			Freeze = true;
		}
		else
		{
			this->RemoveFreezeUI();
			Freeze = false;
		}
		this->UpdateUI();
	};

	FORCEINLINE void SetTemperature(float NewTemperature) { this->Temperature = NewTemperature; };

	FORCEINLINE float GetTemperature() { return Temperature; };

	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
