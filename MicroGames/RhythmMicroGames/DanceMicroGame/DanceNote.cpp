// Copyright Brigham Young University. All Rights Reserved.


#include "DanceNote.h"

// Sets default values
ADanceNote::ADanceNote()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADanceNote::SwapMesh(int32 Index)
{
	if (MaterialList.IsValidIndex(Index))
	{
		//NoteMesh->SetStaticMesh(NoteList[Index]);
		PlaneMesh->SetMaterial(0, MaterialList[Index]);
		NoteValue = Index;
	}
}