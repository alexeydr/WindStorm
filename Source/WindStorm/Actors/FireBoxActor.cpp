


#include "FireBoxActor.h"
#include "FireActor.h"
#include "WindStorm\HeroCharacter.h"

void AFireBoxActor::ActionOnInteract()
{
	Super::ActionOnInteract();

	if (Amount > 0 && MainChar->Inventory.Num() < 6)
	{
		auto Stick = NewObject<AFireActor>(MainChar, AFireActor::StaticClass());

		if (Stick && Act)
		{
			Stick->Name = Act->Name;
			Stick->SetActorScale3D(Act->GetActorScale3D());
			Stick->StaticMesh = Act->StaticMesh;
			Stick->ClassForSpawn = Act->ClassForSpawn;
			Stick->MainChar = Act->MainChar;

			MainChar->Inventory.Add(Stick);

			Amount--;
		}
	}

}