// Fill out your copyright notice in the Description page of Project Settings.


#include "DataTransmitter.h"

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
	
}

// Called every frame
void ADataTransmitter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

