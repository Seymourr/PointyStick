// Fill out your copyright notice in the Description page of Project Settings.

#include "PointyStick.h"
#include "ReadWriteScore.h"

UReadWriteScore::UReadWriteScore(const class FObjectInitializer & PCIP)
	: Super(PCIP)
{

}

FString fd_new = FPaths::GameDir() + "Content/GameLogic/Saved/";
FString fn_new = "TempScore.txt";
FString fp_new = fd_new + fn_new;

FScoreNode UReadWriteScore::readScore() {
	FScoreNode hs; hs.p_name = "null"; hs.p_score = -1;
	FString file = "";
	FFileHelper::LoadFileToString(file, *fp_new);
	TArray<FString> lines;
	file.ParseIntoArray(lines, _T("\n"), true);
	if (lines.Num() > 0) {
		FString line = lines[0];
		if (line.Len() > 0) {
			FString name, tscore, score, status;
			line.Split(" ", &name, &tscore);
			tscore.Split(" ", &score, &status);
			hs.p_name = name; hs.p_score = FCString::Atoi(*score);
			hs.fresh = false;

			if (FCString::Atoi(*status) == 1) {
				hs.fresh = true;
			}
		}
	}
	return hs;
}

void UReadWriteScore::writeScore(FScoreNode n) {
	int32 status = 0;
	if (n.fresh) status = 1;
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (!PlatformFile.DirectoryExists(*fd_new)) {
		//create directory if it not exist
		PlatformFile.CreateDirectory(*fd_new);
	}
	if (PlatformFile.CreateDirectoryTree(*fd_new)) {
		FString res = n.p_name + " " + FString::FromInt(n.p_score) + " " + FString::FromInt(status) + "\n";
		FFileHelper::SaveStringToFile(res, *fp_new);
	}
}


