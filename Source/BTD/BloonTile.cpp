// Fill out your copyright notice in the Description page of Project Settings.


#include "BloonTile.h"

// Sets default values
ABloonTile::ABloonTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Component"));
	SetRootComponent(SceneComponent);
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh Component"));
	SkeletalMeshComponent->SetupAttachment(SceneComponent);
	SkeletalMeshComponent->SetSkeletalMesh(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Sprites/Tiles/BloonTile.BloonTile'")).Object);
	SkeletalMeshComponent->SetWorldScale3D(FVector(0.02, 0.02, 0.001));
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	SphereComponent->SetupAttachment(SceneComponent);
	SphereComponent->SetSphereRadius(0.1);
	SphereComponent->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ABloonTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABloonTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

