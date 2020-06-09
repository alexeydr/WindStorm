


#include "FireActor.h"
#include "Kismet\GameplayStatics.h"
#include "WindStorm\HeroCharacter.h"
#include "WindStorm\Actors\FireActor.h"

void AFireActor::ActionOnInteract()
{
	Super::ActionOnInteract();

	auto Stick = NewObject<AFireActor>(MainChar, AFireActor::StaticClass());

	if (Stick)
	{
		Stick->Name = this->Name;
		Stick->SetActorScale3D(this->GetActorScale3D());
		Stick->StaticMesh = this->StaticMesh;
		Stick->ClassForSpawn = this->ClassForSpawn;
		Stick->MainChar = this->MainChar;
	}
	MainChar->Inventory.Add(Stick);

	this->Destroy();

}

void AFireActor::SpawnThis(AFireActor * Act)
{
	FActorSpawnParameters Params;

	Params.Owner = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	auto Item = GetWorld()->SpawnActor<AFireActor>(ClassForSpawn, UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation() + FVector(100, 0, 0), FRotator::ZeroRotator, Params);
	if (Item)
	{
		Item->Name = Item->Name;
		Item->SetActorScale3D(Item->GetActorScale3D());
		Item->StaticMesh = Item->StaticMesh;
		Item->ClassForSpawn = Item->ClassForSpawn;
		Item->MainChar = Item->MainChar;

	}
}
