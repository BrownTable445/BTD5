// Fill out your copyright notice in the Description page of Project Settings.


#include "Grass.h"

// Sets default values
AGrass::AGrass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Component"));
	SetRootComponent(SceneComponent);
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh Component"));
	SkeletalMeshComponent->SetSkeletalMesh(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Sprites/Tiles/BloonTile.BloonTile'")).Object);
	SkeletalMeshComponent->SetMaterial(0, ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Script/Engine.Material'/Game/Sprites/Tiles/GrassMaterial.GrassMaterial'")).Object);
	SkeletalMeshComponent->SetWorldScale3D(FVector(0.02, 0.02, 0.001));
	SkeletalMeshComponent->SetupAttachment(SceneComponent);
	SkeletalMeshComponent->SetGenerateOverlapEvents(true);
	SkeletalMeshComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
	SkeletalMeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	SkeletalMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

// Called when the game starts or when spawned
void AGrass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

