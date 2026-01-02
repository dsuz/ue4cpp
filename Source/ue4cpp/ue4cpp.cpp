// Copyright Epic Games, Inc. All Rights Reserved.

#include "ue4cpp.h"

#include "MessageLog/Public/MessageLogModule.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, ue4cpp, "ue4cpp" );
DEFINE_LOG_CATEGORY( LogCh11 );

FName LoggerName("MessageLogTest");

void CreateLog(FName LogName)
{
	FMessageLogModule& MessageLogModule = FModuleManager::LoadModuleChecked<FMessageLogModule>("MessageLog");
	FMessageLogInitializationOptions InitOptions;
	InitOptions.bShowPages = true;
	InitOptions.bShowFilters = true;
	FText LogListingName = FTEXT("My Log Listing");
	MessageLogModule.RegisterLogListing(LogName, LogListingName, InitOptions);
}