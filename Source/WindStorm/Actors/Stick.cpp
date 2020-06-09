


#include "Stick.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "Kismet\GameplayStatics.h"
#include "WindStorm\HeroCharacter.h"

void AStick::ActionOnInteract()
{
	Super::ActionOnInteract();

	auto Stick = NewObject<AStick>(MainChar, AStick::StaticClass());

	if (Stick)
	{
		Stick->BurnTime = this->BurnTime;
		Stick->Name = this->Name;
		Stick->SetActorScale3D(this->GetActorScale3D());
		Stick->StaticMesh = this->StaticMesh;
		Stick->ClassForSpawn = this->ClassForSpawn;
		Stick->MainChar = this->MainChar;
	}
	MainChar->Inventory.Add(Stick);
	
	this->Destroy();
}

void AStick::SpawnThis(AStick* Stick)
{	
		FActorSpawnParameters Params;

		Params.Owner = MainChar;
		auto Item = GetWorld()->SpawnActor<AStick>(ClassForSpawn, MainChar->GetActorLocation() + FVector(100, 0, 0), FRotator::ZeroRotator, Params);

		if (Item)
		{
			Item->BurnTime = Stick->BurnTime;
			Item->Name = Stick->Name;
			Item->SetActorScale3D(Stick->GetActorScale3D());
			Item->StaticMesh = Stick->StaticMesh;
			Item->ClassForSpawn = Stick->ClassForSpawn;
			Item->MainChar = Stick->MainChar;

		}
	
}