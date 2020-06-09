


#include "SitcksInInventory.h"
#include "WindStorm\Actors\FireActor.h"
#include "WindStorm\Actors\Stick.h"
#include "WindStorm\UI\Bonefire_UI.h"
#include "WindStorm\Actors\Bonefire.h"
#include "Components\TextBlock.h"
#include "Components\Button.h"

void USitcksInInventory::OnAddClicked()
{
	if (Own->Owner)
	{
		Own->RemoveChildFromVB(this);
		Own->Owner->OnAddStick(Eff);
	}
}

void USitcksInInventory::OnDropClicked()
{
	if (Item)
	{
		AStick* Stick = Cast<AStick>(Item);
		if (Stick)
		{
			Stick->SpawnThis(Stick);
		}
		AFireActor* FireActor = Cast<AFireActor>(Item);
		if(FireActor)
		{

			FireActor->SpawnThis(FireActor);
		}

		Own->RemoveChildFromVB(this);
	}

}

void USitcksInInventory::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (Add)
	{
		Add->OnClicked.AddDynamic(this, &USitcksInInventory::OnAddClicked);
	}

	if (Drop)
	{
		Drop->OnClicked.AddDynamic(this, &USitcksInInventory::OnDropClicked);
	}
}

void USitcksInInventory::SetParams(FString ItemName, float ItemEffect)
{
	if (Name && Effect)
	{
		Name->SetText(FText::FromString(ItemName));
		if (ItemEffect != 0)
		{
			Effect->SetText(FText::FromString(FString::FromInt((int)ItemEffect)));
			Eff = ItemEffect;
		}
	}
}
