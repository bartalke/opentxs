# Copyright (c) 2010-2022 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

add_library(
  proto-verify OBJECT
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/APIArgument.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/AcceptPendingPayment.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/AccountData.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/AccountEvent.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/AddClaim.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/AddContact.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/AsymmetricKey.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Authority.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Bailment.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BailmentReply.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BasketItem.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BasketParams.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Bip47Channel.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Bip47Direction.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BitcoinBlockHeaderFields.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlindedSeriesList.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainAccountData.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainActivity.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainAddress.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainBlockHeader.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainBlockLocalData.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainDeterministicAccountData.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainExternalAddress.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainFilterHeader.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainHDAccountData.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainInputWitness.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainOutputMultisigDetails.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainPeerAddress.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainPreviousOutput.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainTransaction.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainTransactionInput.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainTransactionOutput.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainTransactionProposal.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainTransactionProposedNotification.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainTransactionProposedOutput.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/BlockchainWalletKey.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ChildCredentialParameters.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Ciphertext.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Claim.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ClientContext.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ConnectionInfo.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ConnectionInfoReply.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Contact.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ContactData.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ContactEvent.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ContactItem.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ContactSection.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Context.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/CreateInstrumentDefinition.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/CreateNym.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Credential.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/CurrencyParams.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/DisplayScale.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Envelope.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/EquityParams.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/EthereumBlockHeaderFields.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Faucet.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/GCS.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/GetWorkflow.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/HDAccount.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/HDPath.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/HDSeed.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Identifier.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/InstrumentRevision.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Issuer.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/KeyCredential.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ListenAddress.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/LucreTokenData.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/MasterCredentialParameters.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ModifyAccount.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/MoveFunds.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/NoticeAcknowledgement.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Nym.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/NymIDSource.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/OTXPush.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/OutBailment.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/OutBailmentReply.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/P2PBlockchainChainState.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/P2PBlockchainHello.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/P2PBlockchainSync.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/PairEvent.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/PaymentCode.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/PaymentEvent.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/PaymentWorkflow.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/PeerObject.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/PeerReply.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/PeerRequest.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/PeerRequestHistory.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/PeerRequestWorkflow.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/PendingBailment.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/PendingCommand.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Purse.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/PurseExchange.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/RPCCommand.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/RPCPush.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/RPCResponse.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/RPCStatus.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/RPCTask.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ScaleRatio.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Seed.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/SendMessage.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/SendPayment.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ServerContext.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ServerContract.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ServerReply.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/ServerRequest.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/SessionData.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Signature.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/SourceProof.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/SpentTokenList.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageAccountIndex.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageAccounts.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageBip47AddressIndex.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageBip47ChannelList.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageBip47Contexts.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageBip47NymAddressIndex.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageBlockchainAccountList.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageBlockchainTransactions.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageContactAddressIndex.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageContactNymIndex.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageContacts.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageCredentials.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageIDList.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageIssuers.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageItemHash.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageItems.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageNotary.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageNym.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageNymList.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StoragePaymentWorkflows.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StoragePurse.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageRoot.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageSeeds.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageServers.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageThread.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageThreadItem.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageUnits.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageWorkflowIndex.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StorageWorkflowType.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/StoreSecret.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/SymmetricKey.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/TaggedKey.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/TaskComplete.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Token.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/TransactionData.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/UnitAccountMap.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/UnitDefinition.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/Verification.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerificationGroup.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerificationIdentity.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerificationOffer.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerificationSet.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerifyBlockchain.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerifyCash.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerifyClaim.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerifyConsensus.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerifyContacts.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerifyContracts.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerifyCredentials.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerifyOTX.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerifyP2P.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerifyPeer.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerifyRPC.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerifyStorage.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerifyWorkflows.hpp"
  "${opentxs_SOURCE_DIR}/src/internal/serialization/protobuf/verify/VerifyZMQ.hpp"
  "Check.cpp"
  "Contact.cpp"
  "VerifyBlockchain.cpp"
  "VerifyCash.cpp"
  "VerifyConsensus.cpp"
  "VerifyContacts.cpp"
  "VerifyContracts.cpp"
  "VerifyCredentials.cpp"
  "VerifyOTX.cpp"
  "VerifyP2P.cpp"
  "VerifyPeer.cpp"
  "VerifyRPC.cpp"
  "VerifyStorage.cpp"
  "VerifyWorkflows.cpp"
  "acceptpendingpayment/AcceptPendingPayment_1.cpp"
  "accountdata/AccountData_1.cpp"
  "accountevent/AccountEvent_1.cpp"
  "addclaim/AddClaim_1.cpp"
  "addcontact/AddContact_1.cpp"
  "apiargument/APIArgument_1.cpp"
  "asymmetrickey/AsymmetricKey_1.cpp"
  "authority/Authority_1.cpp"
  "bailment/Bailment_1.cpp"
  "bailmentreply/BailmentReply_1.cpp"
  "basketitem/BasketItem_1.cpp"
  "basketparams/BasketParams_1.cpp"
  "bip47channel/Bip47Channel_1.cpp"
  "bip47direction/Bip47Direction_1.cpp"
  "bitcoinblockheaderfields/BitcoinBlockHeaderFields_1.cpp"
  "blindedserieslist/BlindedSeriesList.cpp"
  "blockchainaccountdata/BlockchainAccountData_1.cpp"
  "blockchainactivity/BlockchainActivity_1.cpp"
  "blockchainaddress/BlockchainAddress_1.cpp"
  "blockchainblockheader/BlockchainBlockHeader_1.cpp"
  "blockchainblocklocaldata/BlockchainBlockLocalData_1.cpp"
  "blockchaindeterministicaccountdata/BlockchainDeterministicAccountData_1.cpp"
  "blockchainexternaladdress/BlockchainExternalAddress_1.cpp"
  "blockchainfilterheader/BlockchainFilterHeader_1.cpp"
  "blockchainhdaccountdata/BlockchainHDAccountData_1.cpp"
  "blockchaininputwitness/BlockchainInputWitness_1.cpp"
  "blockchainoutputmultisigdetails/BlockchainOutputMultisigDetails_1.cpp"
  "blockchainpeeraddress/BlockchainPeerAddress_1.cpp"
  "blockchainpreviousoutput/BlockchainPreviousOutput_1.cpp"
  "blockchaintransaction/BlockchainTransaction_1.cpp"
  "blockchaintransactioninput/BlockchainTransactionInput_1.cpp"
  "blockchaintransactionoutput/BlockchainTransactionOutput_1.cpp"
  "blockchaintransactionproposal/BlockchainTransactionProposal_1.cpp"
  "blockchaintransactionproposednotification/BlockchainTransactionProposedNotification_1.cpp"
  "blockchaintransactionproposedoutput/BlockchainTransactionProposedOutput_1.cpp"
  "blockchainwalletkey/BlockchainWalletKey_1.cpp"
  "childcredentialparameters/ChildCredentialParameters_1.cpp"
  "ciphertext/Ciphertext_1.cpp"
  "claim/Claim_1.cpp"
  "clientcontext/ClientContext_1.cpp"
  "connectioninfo/ConnectionInfo_1.cpp"
  "connectioninforeply/ConnectionInfoReply_1.cpp"
  "contact/Contact_1.cpp"
  "contactdata/ContactData_1.cpp"
  "contactevent/ContactEvent_1.cpp"
  "contactitem/ContactItem_1.cpp"
  "contactsection/ContactSection_1.cpp"
  "context/Context_1.cpp"
  "createinstrumentdefinition/CreateInstrumentDefinition_1.cpp"
  "createnym/CreateNym_1.cpp"
  "credential/Credential_1.cpp"
  "currencyparams/CurrencyParams_1.cpp"
  "displayscale/DisplayScale_1.cpp"
  "envelope/Envelope_1.cpp"
  "equityparams/EquityParams_1.cpp"
  "ethereumblockheaderfields/EthereumBlockHeaderFields_1.cpp"
  "faucet/Faucet_1.cpp"
  "gcs/GCS_1.cpp"
  "getworkflow/GetWorkflow_1.cpp"
  "hdaccount/HDAccount_1.cpp"
  "hdpath/HDPath_1.cpp"
  "hdseed/HDSeed_1.cpp"
  "identifier/Identifier_1.cpp"
  "instrumentrevision/InstrumentRevision_1.cpp"
  "issuer/Issuer_1.cpp"
  "keycredential/KeyCredential_1.cpp"
  "listenaddress/ListenAddress_1.cpp"
  "lucretokendata/LucreTokenData_1.cpp"
  "mastercredentialparameters/MasterCredentialParameters_1.cpp"
  "modifyaccount/ModifyAccount_1.cpp"
  "movefunds/MoveFunds_1.cpp"
  "noticeacknowledgement/NoticeAcknowledgement_1.cpp"
  "nym/Nym_1.cpp"
  "nymidsource/NymIDSource_1.cpp"
  "otxpush/OTXPush_1.cpp"
  "outbailment/OutBailment_1.cpp"
  "outbailmentreply/OutBailmentReply_1.cpp"
  "p2pblockchainchainstate/P2PBlockchainChainState_1.cpp"
  "p2pblockchainhello/P2PBlockchainHello_1.cpp"
  "p2pblockchainsync/P2PBlockchainSync_1.cpp"
  "pairevent/PairEvent_1.cpp"
  "paymentcode/PaymentCode_1.cpp"
  "paymentevent/PaymentEvent_1.cpp"
  "paymentevent/PaymentEvent_2.cpp"
  "paymentevent/PaymentEvent_3.cpp"
  "paymentworkflow/PaymentWorkflow_1.cpp"
  "paymentworkflow/PaymentWorkflow_2.cpp"
  "paymentworkflow/PaymentWorkflow_3.cpp"
  "peerobject/PeerObject_1.cpp"
  "peerobject/PeerObject_2.cpp"
  "peerobject/PeerObject_3.cpp"
  "peerreply/PeerReply_1.cpp"
  "peerreply/PeerReply_2.cpp"
  "peerreply/PeerReply_3.cpp"
  "peerreply/PeerReply_4.cpp"
  "peerrequest/PeerRequest_1.cpp"
  "peerrequest/PeerRequest_2.cpp"
  "peerrequest/PeerRequest_3.cpp"
  "peerrequest/PeerRequest_4.cpp"
  "peerrequesthistory/PeerRequestHistory_1.cpp"
  "peerrequestworkflow/PeerRequestWorkflow_1.cpp"
  "pendingbailment/PendingBailment_1.cpp"
  "pendingcommand/PendingCommand_1.cpp"
  "purse/Purse_1.cpp"
  "purseexchange/PurseExchange_1.cpp"
  "rpccommand/RPCCommand_1.cpp"
  "rpccommand/RPCCommand_2.cpp"
  "rpcpush/RPCPush_1.cpp"
  "rpcresponse/RPCResponse_1.cpp"
  "rpcresponse/RPCResponse_2.cpp"
  "rpcstatus/RPCStatus_1.cpp"
  "rpctask/RPCTask_1.cpp"
  "scaleratio/ScaleRatio_1.cpp"
  "seed/Seed_1.cpp"
  "sendmessage/SendMessage_1.cpp"
  "sendpayment/SendPayment_1.cpp"
  "servercontext/ServerContext_1.cpp"
  "servercontext/ServerContext_2.cpp"
  "servercontract/ServerContract_1.cpp"
  "serverreply/ServerReply_1.cpp"
  "serverrequest/ServerRequest_1.cpp"
  "sessiondata/SessionData_1.cpp"
  "signature/Signature_1.cpp"
  "signature/Signature_2.cpp"
  "signature/Signature_3.cpp"
  "sourceproof/SourceProof_1.cpp"
  "spenttokenlist/SpentTokenList_1.cpp"
  "storageaccountindex/StorageAccountIndex_1.cpp"
  "storageaccounts/StorageAccounts_1.cpp"
  "storagebip47addressindex/StorageBip47AddressIndex_1.cpp"
  "storagebip47channellist/StorageBip47ChannelList_1.cpp"
  "storagebip47contexts/StorageBip47Contexts_1.cpp"
  "storagebip47nymaddressindex/StorageBip47NymAddressIndex_1.cpp"
  "storageblockchainaccountlist/StorageBlockchainAccountList_1.cpp"
  "storageblockchaintransactions/StorageBlockchainTransactions_1.cpp"
  "storagecontactaddressindex/StorageContactAddressIndex_1.cpp"
  "storagecontactnymindex/StorageContactNymIndex_1.cpp"
  "storagecontacts/StorageContacts_1.cpp"
  "storagecontacts/StorageContacts_2.cpp"
  "storagecredentials/StorageCredentials_1.cpp"
  "storageidlist/StorageIDList_1.cpp"
  "storageissuers/StorageIssuers_1.cpp"
  "storageitemhash/StorageItemHash_1.cpp"
  "storageitemhash/StorageItemHash_2.cpp"
  "storageitems/StorageItems_1.cpp"
  "storageitems/StorageItems_2.cpp"
  "storageitems/StorageItems_3.cpp"
  "storageitems/StorageItems_4.cpp"
  "storageitems/StorageItems_5.cpp"
  "storageitems/StorageItems_6.cpp"
  "storagenotary/StorageNotary_1.cpp"
  "storagenym/StorageNym_1.cpp"
  "storagenym/StorageNym_2.cpp"
  "storagenym/StorageNym_3.cpp"
  "storagenym/StorageNym_4.cpp"
  "storagenym/StorageNym_5.cpp"
  "storagenym/StorageNym_6.cpp"
  "storagenym/StorageNym_7.cpp"
  "storagenym/StorageNym_8.cpp"
  "storagenym/StorageNym_9.cpp"
  "storagenymlist/StorageNymList_1.cpp"
  "storagepaymentworkflows/StoragePaymentWorkflows_1.cpp"
  "storagepurse/StoragePurse_1.cpp"
  "storageroot/StorageRoot_1.cpp"
  "storageroot/StorageRoot_2.cpp"
  "storageseeds/StorageSeeds_1.cpp"
  "storageservers/StorageServers_1.cpp"
  "storagethread/StorageThread_1.cpp"
  "storagethreaditem/StorageThreadItem_1.cpp"
  "storageunits/StorageUnits_1.cpp"
  "storageworkflowindex/StorageWorkflowIndex_1.cpp"
  "storageworkflowtype/StorageWorkflowType_1.cpp"
  "storageworkflowtype/StorageWorkflowType_2.cpp"
  "storageworkflowtype/StorageWorkflowType_3.cpp"
  "storesecret/StoreSecret_1.cpp"
  "symmetrickey/SymmetricKey_1.cpp"
  "taggedkey/TaggedKey_1.cpp"
  "taskcomplete/TaskComplete_1.cpp"
  "token/Token_1.cpp"
  "transactiondata/TransactionData_1.cpp"
  "unitaccountmap/UnitAccountMap_1.cpp"
  "unitdefinition/UnitDefinition_1.cpp"
  "unitdefinition/UnitDefinition_2.cpp"
  "verification/Verification_1.cpp"
  "verificationgroup/VerificationGroup_1.cpp"
  "verificationidentity/VerificationIdentity_1.cpp"
  "verificationoffer/VerificationOffer_1.cpp"
  "verificationset/VerificationSet_1.cpp"
  "verifyclaim/VerifyClaim_1.cpp"
)
add_library(
  opentxs::proto-verify
  ALIAS
  proto-verify
)
target_include_directories(
  proto-verify SYSTEM
  PRIVATE "${opentxs_SOURCE_DIR}/deps/robin-hood/src/include"
)
target_link_libraries(
  proto-verify
  PRIVATE
    Boost::headers
    opentxs-common
    protobuf::libprotobuf-lite
)
target_link_libraries(opentxs PUBLIC protobuf::libprotobuf-lite)
set_target_properties(
  proto-verify
  PROPERTIES
    MSVC_RUNTIME_LIBRARY "${MSVC_RUNTIME_DEFAULT}"
    C_INCLUDE_WHAT_YOU_USE ""
    CXX_INCLUDE_WHAT_YOU_USE ""
)

if(NOT MSVC)
  target_compile_options(
    proto-verify
    PRIVATE
      -Wno-extra-semi
      -Wno-suggest-destructor-override
      -Wno-type-limits
      -Wno-unused-parameter
  )
endif()

target_sources(opentxs PRIVATE $<TARGET_OBJECTS:proto-verify>)
add_dependencies(proto-verify generated_code)
