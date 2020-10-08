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

		// The player's tank is found at the start, but this is updated during Tick so is not actually required (not removed to avoid any unforeseen issues).
		PlayerTank = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		// Sets player position in the blackboard
		GetBlackboardComponent()->SetValueAsVector(TEXT("PawnSpawnPosition"),GetPawn()->GetActorLocation());

	
		/* -- DOCO/REFLECTION COMMENT --
		* The randomizer is set up to get a random number between 1 and 3 and then set patrol point based on this.
		* In future implementations I would prefer to add some random patrol point handling, as this runs several risks,
		* including patrol point overlap and stale gameplay, but it currently works at a rudimentary level.
		*/
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

	//if (flaggedForDeletion) {
	//	GetBlackboardComponent()->ClearValue(TEXT("healingLocation"));
	//	UE_LOG(LogTemp, Warning, TEXT("Heal location cleared"));
	//}
//	controllerState = GetPawn()->get     GetComponentsByTag(UStatsComponent::StaticClass(), FName("aistats"))->currentHealth;
			//FindComponentByClass(TSubclassOf<UStatsComponent>("aistats"));
	PlayerTank = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//	GetPawn()->GetComponentByClass(TSubclassOf<UStatsComponent>(TEXT("aistats")) ;
	
	if (!powerupStillAvailable) {
		pendingHeal = true;
	}
	// I struggled a lot to have the ai controller actually look at the stats component for the AI tank... there is no collision event
	// or similar to grab a root object out of and it would be meaningless to simply adjust for healing withoug cause - eventually I used
	// a blueprint reference from enemytankbase to change controllerState here.
	if (controllerState.Equals("healing")) {

		if (pendingHeal) {
			for (TObjectIterator<APowerupActor> It; It; ++It)
			{
				// get the first available powerup actor and then break the loop
				if (It->powerupAvailable) {
					//set up powerupStillAvailable pointer so that AI can dynamically determine if a powerup is used/destroyed
					powerupStillAvailable = &It->powerupAvailable;
					if (nearestHeal != It->GetActorLocation()) {
						
						// set heal location vector
						nearestHeal = It->GetActorLocation();
						
						GetBlackboardComponent()->ClearValue(TEXT("healingLocation"));
						
						// prevent over-looping when target already exists
						pendingHeal = false;
						
						UE_LOG(LogTemp, Warning, TEXT("Heal location set to %f , %f"), nearestHeal.Y, nearestHeal.X);
					}
					break;
				}
				else {
					UE_LOG(LogTemp, Warning, TEXT("Targeted heal is not available"));
					continue;
				}
			}
		}

		GetBlackboardComponent()->SetValueAsBool(TEXT("healing"), true);
		GetBlackboardComponent()->SetValueAsVector(TEXT("healingLocation"), nearestHeal);
	}
	else {
		GetBlackboardComponent()->ClearValue(TEXT("healing"));
		GetBlackboardComponent()->ClearValue(TEXT("healingLocation"));
		pendingHeal = true;

		//handles dynamic settings for blackboard components
		if (LineOfSightTo(PlayerTank) && !controllerState.Equals("healing")) {
			GetBlackboardComponent()->SetValueAsBool(TEXT("pursuit"), true);
			// I didn't mean for this next value to have different case style, I just overlooked it and didn't have time to refactor everywhere in the project
			GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerTankLocation"), PlayerTank->GetActorLocation());
		}
		else {
			GetBlackboardComponent()->ClearValue(TEXT("PlayerTankLocation"));
			GetBlackboardComponent()->ClearValue(TEXT("pursuit"));
		}
	}

	
}


