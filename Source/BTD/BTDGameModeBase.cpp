// Copyright Epic Games, Inc. All Rights Reserved.


#include "BTDGameModeBase.h"

void ABTDGameModeBase::Tick(float DeltaTime)
{
	int index = 0;
	while (index < Bloons.Num()) {
		if (Bloons[index]->HP <= 0 || Bloons[index]->Invaded) {
			TArray<AActor*> OverlappedActors;
			TSubclassOf<ADefender> Filter;
			Bloons[index]->GetOverlappingActors(OverlappedActors, Filter);
			for (auto j : OverlappedActors) {
				ADefender* Defender = Cast<ADefender>(j);
				if (Defender) {
					for (int k = 0; k < Defender->EncounteredBloons.Num(); ++k)
						if (Defender->EncounteredBloons[k] == Bloons[index]) {
							Defender->EncounteredBloons.RemoveAt(k);
							break;
						}
				}
			}
			Bloons[index]->Destroy();
			Bloons.RemoveAt(index);
		}
		else
			++index;
	}
	for (auto i : Defenders) {
		i->UpdateBloonOrder();
	}
	if (Bloons.IsEmpty())
		Playing = false;
}

ABTDGameModeBase::ABTDGameModeBase()
{
	bAllowTickBeforeBeginPlay = true;
	PlayerControllerClass = APlayerControllerReal::StaticClass();
	//DefaultPawnClass = AMySpectatorPawn::StaticClass();
	SpectatorClass = AMySpectatorPawn::StaticClass();
	DefaultMaterial = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Script/Engine.Material'/Game/Animations/Material.Material'")).Object;
	EmissiveMaterial = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Script/Engine.Material'/Game/Animations/EmissiveMaterial.EmissiveMaterial'")).Object;
	LevelStages.Init(nullptr, 1);
	LevelStages[0] = ConstructorHelpers::FObjectFinder<UDataTable>(TEXT("/Script/Engine.DataTable'/Game/BloonLevels/DataTableLevel1.DataTableLevel1'")).Object;
}

void ABTDGameModeBase::SpawnBloon(TSubclassOf<ABloon> Bloon)
{
	FActorSpawnParameters SpawnParameters;
	Bloons.Add(GetWorld()->SpawnActor<ABloon>(Bloon, FVector(0, 0, 0.001), FRotator(0, -90, 0), SpawnParameters));
}

bool ABTDGameModeBase::isValidSpawnLocation(FVector Location, float Radius)
{
	AValidSpawnLocationChecker* Checker = SpawnChecker(Location, Radius);
	bool ValidSpawnLocation = Checker->isOverlappingDefenderSpawnRadius(), OnValidTile = Checker->OnValidTile();
	Checker->Destroy();
	return !ValidSpawnLocation && OnValidTile;
}

void ABTDGameModeBase::Play() {
	int RowCount = LevelStages[Level - 1]->GetRowNames().Num();
	for (int i = 0; i < RowCount; ++i) {
		FBloonSpawnRow* BloonSpawnRow = LevelStages[Level - 1]->FindRow<FBloonSpawnRow>(FName(FString::FromInt(i)), FString(""));
		if (BloonSpawnRow) {//what if we use the exact same timerhandle for everything?
			for (int j = 0; j < BloonSpawnRow->SpawnCount; ++j) {
				FTimerHandle TimerHandle; //in future make distinction when there is a different sized bloon, then the spawn location should not be 1, but a bit higher or lower
				GetWorldTimerManager().SetTimer(TimerHandle, [this, BloonSpawnRow]() {SpawnBloon(BloonSpawnRow->BloonType); }, 0.0001, false, BloonSpawnRow->SpawnDelay);
			}
		}
	}
	//set playing to false once all bloons are popped
}

FVector ABTDGameModeBase::ConvertViewportPositionToGameCoordinates(FVector& ViewportPosition)
{
	return FVector((ViewportPosition.X - 34.074) * RATE_OF_CHANGE, (ViewportPosition.Y + 4.712) * RATE_OF_CHANGE, 0.001);
}

AValidSpawnLocationChecker* ABTDGameModeBase::SpawnChecker(FVector& Location, float Radius)
{
	AValidSpawnLocationChecker* Checker = GetWorld()->SpawnActor<AValidSpawnLocationChecker>(AValidSpawnLocationChecker::StaticClass(), FTransform(Location));
	Checker->SphereComponent->SetSphereRadius(Radius);
	return Checker;
}
