


#include "Inventory.h"
#include "Components\Button.h"


void UInventory::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (Drop)
	{
		//Drop->OnClicked.AddDynamic(this, &UInventory::OnDropClicked);
	}


}
