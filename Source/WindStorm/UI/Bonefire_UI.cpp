


#include "Bonefire_UI.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "WindStorm\Actors\InteractActor.h"
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
	if (Items->GetAllChildren().Num() <= 0)
	{
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = false;
		UWidgetBlueprintLibrary::SetInputMode_GameOnly(UGameplayStatics::GetPlayerController(GetWorld(),0));
		this->RemoveFromParent();
	}
}

void UBonefire_UI::SynchronizeProperties()
{
	Super::SynchronizeProperties();

}

void UBonefire_UI::AddItems(AInteractActor * Actor, TSubclassOf<USitcksInInventory> StickInInvUI)
{
	if (Items && StickInInvUI)
	{
		USitcksInInventory* SitcksInInventoryRef = CreateWidget<USitcksInInventory>(GetWorld(), StickInInvUI);
		if (SitcksInInventoryRef)
		{
			SitcksInInventoryRef->Item = Actor;
			AStick* Stick = Cast<AStick>(Actor);
			if (Stick)
			{
				SitcksInInventoryRef->SetParams(Stick->Name, Stick->BurnTime);
			}
			else
			{
				SitcksInInventoryRef->SetParams(Actor->Name);
			}
			SitcksInInventoryRef->Own = this;

			Items->AddChildToVerticalBox(SitcksInInventoryRef);
		}

	}
}
