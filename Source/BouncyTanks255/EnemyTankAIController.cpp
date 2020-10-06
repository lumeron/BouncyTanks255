// SIT255 Group Project Assignment


#include "EnemyTankAIController.h"
AEnemyTankAIController::AEnemyTankAIController() 
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyTankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehaviorEnemyTank != nullptr) {
		RunBehaviorTree(AIBehaviorEnemyTank);

		PlayerTank = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		//Get player position - this will probably be removed and only fetched when player is seen
		GetBlackboardComponent()->SetValueAsVector(TEXT("PawnSpawnPosition"),GetPawn()->GetActorLocation());
		//Get pawn spawn position - this could be adjusted for a "return to" location
//		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerTankLocation"),PlayerTank->GetActorLocation());

		FRandomStream randomizer = FRandomStream();
		randomizer.GenerateNewSeed();
		int randomPatrol = randomizer.RandRange(1, 3);

		switch (randomPatrol) {
			case 1:
				GetBlackboardComponent()->SetValueAsVector(TEXT("Patrol1A"), FVector(1907.0f, -609.0f, 20.0f));
				GetBlackboardComponent()->SetValueAsVector(TEXT("Patrol1B"), FVector(1907.0f, 1386.0f, 20.0f));
				break;
			case 2:
				GetBlackboardComponent()->SetValueAsVector(TEXT("Patrol1A"), FVector(2082.0f, -609.0f, 20.0f));
				GetBlackboardComponent()->SetValueAsVector(TEXT("Patrol1B"), FVector(4249.0f, 1386.0f, 20.0f));
				break;
			case 3:
				GetBlackboardComponent()->SetValueAsVector(TEXT("Patrol1A"), FVector(3017.0f, 1982.0f, 20.0f));
				GetBlackboardComponent()->SetValueAsVector(TEXT("Patrol1B"), FVector(3017.0f, 5236.0f, 20.0f));
				break;
			default:
				UE_LOG(LogTemp, Warning, TEXT("Seed failed"));
				break;
		}


	}


}

// Called every frame
void AEnemyTankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	controllerState = GetPawn()->currentState;
	PlayerTank = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//	GetPawn()->GetComponentByClass(TSubclassOf<UStatsComponent>(TEXT("aistats")) ;

	if (controllerState.Equals("healing")) {
		GetBlackboardComponent()->SetValueAsBool(TEXT("healing"), true);
		for (TObjectIterator<APowerupActor> It; It; ++It)
		{
			// get the first available powerup actor and then break the loop
			if (!It->IsHidden()) {
				GetBlackboardComponent()->SetValueAsVector(TEXT("healingLocation"), It->GetActorLocation());
				break;
			}
		}
	}
	else {
		GetBlackboardComponent()->ClearValue(TEXT("healing"));
		GetBlackboardComponent()->ClearValue(TEXT("healingLocation"));

		//handles dynamic settings for blackboard components
		if (LineOfSightTo(PlayerTank) && !controllerState.Equals("healing")) {
			GetBlackboardComponent()->SetValueAsBool(TEXT("pursuit"), true);
			GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerTankLocation"), PlayerTank->GetActorLocation());
		}
		else {
			GetBlackboardComponent()->ClearValue(TEXT("PlayerTankLocation"));
			GetBlackboardComponent()->ClearValue(TEXT("pursuit"));
		}
	}

	
}


