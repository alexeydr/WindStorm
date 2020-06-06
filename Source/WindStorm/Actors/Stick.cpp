


#include "Stick.h"
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
		Stick->MainChar = this->MainChar;
	}
	MainChar->Inventory.Add(Stick);
	
	this->Destroy();
}