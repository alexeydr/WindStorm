


#include "HeroCharacter.h"
#include "Engine\Engine.h"
#include "Blueprint/UserWidget.h"
#include "Actors\Stick.h"
#include "Actors\FireActor.h"
#include "Actors\Bonefire.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Actors\InteractActor.h"
#include "Components/InputComponent.h"
#include "TimerManager.h"

// Sets default values
AHeroCharacter::AHeroCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AHeroCharacter::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Interaction", IE_Pressed, this, &AHeroCharacter::Interaction);
	PlayerInputComponent->BindAction("OpenInventory", IE_Pressed, this, &AHeroCharacter::OpenInventory);
	PlayerInputComponent->BindAction("GetFire", IE_Pressed, this, &AHeroCharacter::GetFire);
}

// Called when the game starts or when spawned
void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (NeedTemperature)
	{
		FTimerHandle FuzeTimerHandle;
		GetWorld()->GetTimerManager().SetTimer(FuzeTimerHandle, this, &AHeroCharacter::OnFreeze, 0.5f, true);
	}
}

void AHeroCharacter::Dead()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("U DIE!"));
	}
}

void AHeroCharacter::OnFreeze()
{
	if (!InWarm)
	{
		this->AddTemperature(-1.f);
	}
	if (Freeze)
	{
		this->AddHealth(-4.f);
	}
}

void AHeroCharacter::GetFire()
{
	for (int i = 0; i < Inventory.Num(); i++)
	{
		AFireActor* FA = Cast<AFireActor>(Inventory[i]);
		if (FA && FlipFlop)
		{
			FlipFlop = false;
			this->EffectFire(true);
			Inventory.RemoveAt(i);
			return;
		}

	}
	FlipFlop = true;
	this->EffectFire(false);
}

void AHeroCharacter::Interaction()
{
	if (InteractActor)
	{
		InteractActor->ActionOnInteract();
	}
}

void AHeroCharacter::OpenInventory()
{
	APlayerController* PC = Cast<APlayerController>(this->GetController());
	if (PC && InventoryWidgetClass && StickUIClass)
	{

		WidgetRef = CreateWidget<UBonefire_UI>(GetWorld(), InventoryWidgetClass);

		if (WidgetRef)
			WidgetRef->AddToViewport();
		else
			return;


		for (auto Elem : Inventory)
		{
			WidgetRef->AddItems(Elem, StickUIClass);
		}

		PC->bShowMouseCursor = true;
		UWidgetBlueprintLibrary::SetInputMode_UIOnly(PC, WidgetRef);
	}


}

void AHeroCharacter::SpawnBonefire()
{
	FActorSpawnParameters Params;

	Params.Owner = this;
	auto Item = GetWorld()->SpawnActor<ABonefire>(BonefireClass, this->GetActorLocation(), FRotator::ZeroRotator, Params);

	if (Item)
	{

	}

}


// Called every frame
void AHeroCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

