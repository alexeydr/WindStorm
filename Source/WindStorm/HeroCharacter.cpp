


#include "HeroCharacter.h"
#include "Engine\Engine.h"
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

void AHeroCharacter::Interaction()
{
	if (InteractActor)
	{
		InteractActor->ActionOnInteract();
	}
}

void AHeroCharacter::OpenInventory()
{
	for (auto Elem: Inventory)
	{
		UE_LOG(LogTemp, Warning, TEXT("I have: %s"), *Elem->GetName());
	}
}


// Called every frame
void AHeroCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

