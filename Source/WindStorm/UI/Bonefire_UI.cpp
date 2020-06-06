


#include "Bonefire_UI.h"
#include "WindStorm\Actors\Stick.h"
#include "WindStorm\HeroCharacter.h"
#include "Kismet\GameplayStatics.h"
#include "Components\VerticalBox.h"

void UBonefire_UI::RemoveChildFromVB(USitcksInInventory * Elem)
{
	if (Items)
	{
		for (int i = 0; i < Items->GetAllChildren().Num(); i++)
		{
			if (Elem == Items->GetAllChildren()[i])
			{
				Items->RemoveChildAt(i);
				AHeroCharacter* Char = Cast<AHeroCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
				if (Char)
				{
					Char->Inventory.RemoveAt(i);
				}
			}
		} 

	}
}

void UBonefire_UI::SynchronizeProperties()
{
	Super::SynchronizeProperties();

}

void UBonefire_UI::AddItems(AStick * Stick)
{
	if (Items && StickInInvUI)
	{
		USitcksInInventory* SitcksInInventoryRef = CreateWidget<USitcksInInventory>(GetWorld(), StickInInvUI);
		if (SitcksInInventoryRef)
		{
			SitcksInInventoryRef->SetParams(Stick->Name,Stick->BurnTime);
			SitcksInInventoryRef->Own = this;

			Items->AddChildToVerticalBox(SitcksInInventoryRef);
		}


	}
}
