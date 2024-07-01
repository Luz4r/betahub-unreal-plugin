#pragma once

#include "CoreMinimal.h"
#include "BH_Frame.h"
#include "BH_FrameBuffer.h"
#include "Containers/Queue.h"
#include "HAL/Runnable.h"
#include "HAL/RunnableThread.h"
#include "Misc/Paths.h"

class BH_VideoEncoder : public FRunnable
{
private:
    FString encodingSettings;
    FString ffmpegPath;
    FString outputFile;
    FString segmentsDir;
    int32 targetFPS;
    int32 screenWidth;
    int32 screenHeight;

    UPROPERTY()
    UBH_FrameBuffer* frameBuffer;

    FEvent* stopEvent;
    FEvent* pauseEvent;

    FRunnableThread* thread;
    bool bIsRecording;
	void* pipeWrite;

    FTimespan RecordingDuration;
    FTimespan MaxSegmentAge;
    FTimespan SegmentCheckInterval;
    FDateTime LastSegmentCheckTime;

    void RunEncoding();
    void RemoveOldSegments();
    int32 GetSegmentCountToKeep();

public:
    BH_VideoEncoder(
        int32 InTargetFPS,
        const FTimespan &InRecordingDuration,
        int32 InScreenWidth, int32 InScreenHeight,  
        UBH_FrameBuffer* InFrameBuffer);
    virtual ~BH_VideoEncoder();

    bool Init() override;
    uint32 Run() override;
    void Stop() override;

    void StartRecording();
    void StopRecording();
    void PauseRecording();
    void ResumeRecording();
    void EncodeFrame(TSharedPtr<FBH_Frame> frame);

    FString MergeSegments(int32 MaxSegments);
};
