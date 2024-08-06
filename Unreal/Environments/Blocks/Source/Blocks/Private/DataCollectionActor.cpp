// ************************************************************************************************************************
// DEFAULTS
#include "DataCollectionActor.h"
#include <fstream>
#include <string>
#include <iostream>

// Sets default values
ADataCollectionActor::ADataCollectionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADataCollectionActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADataCollectionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// DEFAULTS
// ************************************************************************************************************************
