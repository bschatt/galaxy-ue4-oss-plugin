#pragma once

#include "Types/IListenerGOG.h"

#include "OnlineSessionSettings.h"

class FRequestLobbyListListener
	: public IListenerGOG
	, public galaxy::api::ILobbyListListener
	, public galaxy::api::ILobbyDataRetrieveListener
{
public:

	FRequestLobbyListListener(class FOnlineSessionGOG& InSessionInterface, TSharedRef<FOnlineSessionSearch> InOutSearchSettings);

private:

	void TriggerOnFindSessionsCompleteDelegates(bool InIsSuccessful) const;

	void OnLobbyList(uint32_t InlobbyCount, bool InIOFailure) override;

	bool RequestLobbiesData(uint32_t InLobbyCount);

	void OnLobbyDataRetrieveSuccess(const galaxy::api::GalaxyID& InLobbyID) override;

	void OnLobbyDataRetrieveFailure(const galaxy::api::GalaxyID& InLobbyID, galaxy::api::ILobbyDataRetrieveListener::FailureReason InFailureReason) override;

	class FOnlineSessionGOG& sessionInterface;
	TArray<galaxy::api::GalaxyID> pendingLobbyList;
	TSharedRef<FOnlineSessionSearch> searchSettings;
};
