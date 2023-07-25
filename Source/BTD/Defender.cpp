// Fill out your copyright notice in the Description page of Project Settings.


#include "Defender.h"

// Sets default values
ADefender::ADefender()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Component"));
	SetRootComponent(SceneComponent);
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(SceneComponent);
	Sphere->SetGenerateOverlapEvents(true);
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ADefender::OnBeginOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ADefender::OnOverlapEnd);
	SpawnRadius = CreateDefaultSubobject<USphereComponent>(TEXT("Spawn Radius"));
	SpawnRadius->SetupAttachment(SceneComponent);
	SpawnRadius->SetGenerateOverlapEvents(true);
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh Component"));
	SkeletalMeshComponent->SetupAttachment(SceneComponent);
	SkeletalMeshComponent->SetGenerateOverlapEvents(true);
	SkeletalMeshComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
	SkeletalMeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	SkeletalMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

// Called when the game starts or when spawned
void ADefender::BeginPlay()
{
	Super::BeginPlay();

}

void ADefender::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABloon* Bloon = Cast<ABloon>(OtherActor);
	if (Bloon) {
		if (!WasOverlapped) {
			FVector Location = Bloon->GetActorLocation(), Velocity = Bloon->GetVelocity();
			float HalfSize = Bloon->Box->GetUnscaledBoxExtent().X / 2;
			if (Velocity.X < 0)
				OverlapBeginPoint = Location - FVector(HalfSize, 0, 0);
			else if (Velocity.X > 0)
				OverlapBeginPoint = Location + FVector(HalfSize, 0, 0);
			else if (Velocity.Y > 0)
				OverlapBeginPoint = Location + FVector(0, HalfSize, 0);
			else
				OverlapBeginPoint = Location - FVector(0, HalfSize, 0);
		}
		if (OtherComponent == Bloon->SkeletalMeshComponent)
			EncounteredBloons.Add(Bloon);
	}
}

void ADefender::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	if (!EncounteredBloons.IsEmpty()) {//idk if the if statement is necessary
		ABloon* Bloon = Cast<ABloon>(OtherActor);
		if (Bloon)
			if (OtherComponent == Bloon->SkeletalMeshComponent)
				EncounteredBloons.RemoveAt(0);
	}
}

void ADefender::RotateToBloon()
{
	if (!EncounteredBloons.IsEmpty()) {
		FVector Velocity = EncounteredBloons[0]->GetVelocity(), Location = EncounteredBloons[0]->GetActorLocation();
		Location += Velocity * (EncounteredBloons[0]->Speed / 10); //probably should reduce this constant
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Location);
		LookAtRotation.Pitch = 0;
		SetActorRotation(LookAtRotation);
	}
}

void ADefender::UpdateBloonOrder()
{
	if (!EncounteredBloons.IsEmpty())
		EncounteredBloons.Sort([this](ABloon& lhs, ABloon& rhs) {return FVector::Distance(OverlapBeginPoint, lhs.GetActorLocation()) > FVector::Distance(OverlapBeginPoint, rhs.GetActorLocation()); });
}

// Called every frame
void ADefender::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateToBloon();
}

