// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloon2.h"

ABloon2::ABloon2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Size = 2.6;
	Speed = 6;
	HP = 2;
	SkeletalMeshComponent->SetSkeletalMesh(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Sprites/Tiles/BloonTile.BloonTile'")).Object);
	SkeletalMeshComponent->SetMaterial(0, ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Script/Engine.Material'/Game/Sprites/Materials/Material.Material'")).Object);
	SkeletalMeshComponent->SetWorldScale3D(FVector(0.01, 0.01, 0.01));
}

// Called when the game starts or when spawned
void ABloon2::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABloon2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ABloon::Tick(DeltaTime);

}