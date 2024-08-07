// Fill out your copyright notice in the Description page of Project Settings.


#include "AirSim.h"
#include "DataTransmitter.h"
#include "../../../../../../RFRL-Toolkit/rfrl.hpp"

// Sets default values
ADataTransmitter::ADataTransmitter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADataTransmitter::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADataTransmitter::writeData, 0.5f, true); // Call the WriteData function ever 1/2 second
}

// Called every frame
void ADataTransmitter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Collect Positional data every half second
void ADataTransmitter::writeData() {

	if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hello World"));
    }
}

