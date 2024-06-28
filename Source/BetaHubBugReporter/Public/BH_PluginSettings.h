#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BH_PluginSettings.generated.h"

UCLASS(Config=Game, defaultconfig)
class BETAHUBBUGREPORTER_API UBH_PluginSettings : public UObject
{
    GENERATED_BODY()

public:
	UBH_PluginSettings();

    UPROPERTY(EditAnywhere, Config, Category="Settings", 
        meta=(ToolTip="The API endpoint for submitting bug reports."))
    FString ApiEndpoint;

    UPROPERTY(EditAnywhere, Config, Category="Settings", 
        meta=(ToolTip="The Project ID of your project on BetaHub. You can find this on the project settings page on BetaHub."))
    FString ProjectId;

    UPROPERTY(EditAnywhere, Config, Category="Settings",
        meta=(ToolTip="Enable or disable the shortcut key to open the bug report form."))
    bool bEnableShortcut;

    UPROPERTY(EditAnywhere, Config, Category="Settings", 
        meta=(ToolTip="The shortcut key to open the bug report form."))
    FKey ShortcutKey;

    UPROPERTY(EditAnywhere, Config, Category="Settings", 
        meta=(ToolTip="The maximum number of frames per second (FPS) to record in the bug report video."))
    int32 MaxRecordedFrames;

    UPROPERTY(EditAnywhere, Config, Category="Settings", 
        meta=(ToolTip="The maximum duration of the bug report video."))
    FTimespan MaxRecordingDuration;
};