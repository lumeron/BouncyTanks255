// SIT255 Group Project Assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Globals.generated.h"

/* -- DOCO/REFLECTION COMMENT --
 * This class is used to handle and adjust AI behavior, as well as to adjust blackboard/behavior tree states
 */

UCLASS()
class BOUNCYTANKS255_API AGlobals : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGlobals();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(Category = "GlobalVariables", EditAnywhere, BlueprintReadWrite)
		int timeInSeconds = 0;
	
	UPROPERTY(Category = "GlobalVariables", EditAnywhere, BlueprintReadWrite)
		bool bulletIsSpawnable = true;

	UPROPERTY(Category = "GlobalVariables", EditAnywhere, BlueprintReadWrite)
		int32 bulletCount = 0;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
