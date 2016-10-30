// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReadWriteScore.generated.h"

USTRUCT(BlueprintType)
struct FScoreNode {
	GENERATED_USTRUCT_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Struct")
		int32 p_score;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Struct")
		FString p_name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Struct")
		bool fresh = false;
};

UCLASS()
class POINTYSTICK_API UReadWriteScore : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
	public:
	UFUNCTION(BlueprintCallable, Category = "HighScore")
		static FScoreNode readScore();

	UFUNCTION(BlueprintCallable, Category = "HighScore")
		static void writeScore(FScoreNode score);
	
	
};
