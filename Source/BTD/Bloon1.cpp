// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloon1.h"

// Sets default values
ABloon1::ABloon1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Size = 2.6;
	Speed = 5;
	HP = 1;
	SkeletalMeshComponent->SetSkeletalMesh(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Sprites/Tiles/BloonTile.BloonTile'")).Object);
	SkeletalMeshComponent->SetWorldScale3D(FVector(0.01, 0.01, 0.01));
}

// Called when the game starts or when spawned
void ABloon1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABloon1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ABloon::Tick(DeltaTime);

}

