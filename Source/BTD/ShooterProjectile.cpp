// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterProjectile.h"

// Sets default values
AShooterProjectile::AShooterProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProjectileMovementComponent->InitialSpeed = 100;
	ProjectileMovementComponent->MaxSpeed = 100;
	ProjectileMovementComponent->ProjectileGravityScale = 0;
	SkeletalMeshComponent->SetSkeletalMesh(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Sprites/Weapons/ShooterProjectile.ShooterProjectile'")).Object);
	SkeletalMeshComponent->SetWorldScale3D(FVector(0.001, 0.01, 0.001));
	SkeletalMeshComponent->SetWorldRotation(FRotator(0, 90, 0));
}

// Called when the game starts or when spawned
void AShooterProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShooterProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

