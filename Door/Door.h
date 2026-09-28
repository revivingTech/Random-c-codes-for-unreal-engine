// ---------------------------------------CODE STARTS HERE-----------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class MYPROJECT_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

    UPROPERTY(VisibleAnywhere)
        class USceneComponent* Root;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        class UStaticMeshComponent* Door;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FVector Location;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FRotator Rotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float Rate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
    void DoorAction();
    FTimerHandle ActionTimerHandle;
	
	
};
// ---------------------------------------CODE ENDS HERE-----------------------------------------
