// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "0_stdafx.hpp"                 // IWYU pragma: associated
#include "1_Internal.hpp"               // IWYU pragma: associated
#include "otx/client/ServerAction.hpp"  // IWYU pragma: associated

#include "internal/api/session/Wallet.hpp"
#include "internal/otx/client/Factory.hpp"
#include "internal/otx/client/ServerAction.hpp"
#include "internal/otx/common/Account.hpp"
#include "internal/util/Shared.hpp"
#include "opentxs/api/session/Client.hpp"
#include "opentxs/api/session/Wallet.hpp"
#include "opentxs/core/identifier/Notary.hpp"
#include "opentxs/core/identifier/Nym.hpp"
#include "opentxs/util/Pimpl.hpp"
#include "otx/client/obsolete/OTAPI_Func.hpp"

namespace opentxs::factory
{
auto ServerAction(
    const api::session::Client& api,
    const ContextLockCallback& lockCallback) -> otx::client::ServerAction*
{
    return new otx::client::implementation::ServerAction(api, lockCallback);
}
}  // namespace opentxs::factory

namespace opentxs::otx::client::implementation
{
ServerAction::ServerAction(
    const api::session::Client& api,
    const ContextLockCallback& lockCallback)
    : api_(api)
    , lock_callback_(lockCallback)
{
    // WARNING: do not access api_.Wallet() during construction
}

auto ServerAction::ActivateSmartContract(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID,
    const Identifier& accountID,
    const UnallocatedCString& agentName,
    std::unique_ptr<OTSmartContract>& contract) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(reason,
        ACTIVATE_SMART_CONTRACT,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID/*,
        accountID,
        agentName,
        contract*/));
}

auto ServerAction::AdjustUsageCredits(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID,
    const identifier::Nym& targetNymID,
    const Amount& adjustment) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(reason,
        ADJUST_USAGE_CREDITS,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID/*,
        targetNymID,
        adjustment*/));
}

auto ServerAction::CancelPaymentPlan(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID,
    std::unique_ptr<OTPaymentPlan>& plan) const -> ServerAction::Action
{
    // NOTE: Normally the SENDER (PAYER) is the one who deposits a payment plan.
    // But in this case, the RECIPIENT (PAYEE) deposits it -- which means
    // "Please cancel this plan." It SHOULD fail, since it's only been signed
    // by the recipient, and not the sender. And that failure is what burns
    // the transaction number on the plan, so that it can no longer be used.
    //
    // So how do we know the difference between an ACTUAL "failure" versus a
    // purposeful "failure" ? Because if the failure comes from cancelling the
    // plan, the server reply transaction will have IsCancelled() set to true.
    return Action(new OTAPI_Func(reason,
        DEPOSIT_PAYMENT_PLAN,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID/*,
        plan->GetRecipientAcctID(),
        plan*/));
}

auto ServerAction::CreateMarketOffer(
    const PasswordPrompt& reason,
    const Identifier& assetAccountID,
    const Identifier& currencyAccountID,
    const Amount& scale,
    const Amount& increment,
    const std::int64_t quantity,
    const Amount& price,
    const bool selling,
    const std::chrono::seconds lifetime,
    const UnallocatedCString& stopSign,
    const Amount activationPrice) const -> ServerAction::Action
{
    auto notaryID = identifier::Notary::Factory();
    auto nymID = identifier::Nym::Factory();
    const auto assetAccount = api_.Wallet().Internal().Account(assetAccountID);

    if (assetAccount) {
        nymID = assetAccount.get().GetNymID();
        notaryID = assetAccount.get().GetPurportedNotaryID();
    }

    return Action(new OTAPI_Func(reason,
        CREATE_MARKET_OFFER,
        lock_callback_({nymID->str(), notaryID->str()}),
        api_,
        nymID,
        notaryID/*,
        assetAccountID,
        currencyAccountID,
        scale,
        increment,
        quantity,
        price,
        selling,
        lifetime.count(),
        activationPrice,
        stopSign*/));
}

auto ServerAction::DepositPaymentPlan(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID,
    std::unique_ptr<OTPaymentPlan>& plan) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(reason,
        DEPOSIT_PAYMENT_PLAN,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID/*,
        plan->GetSenderAcctID(),
        plan*/));
}

auto ServerAction::DownloadMarketList(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(
        reason,
        GET_MARKET_LIST,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID));
}

auto ServerAction::DownloadMarketOffers(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID,
    const Identifier& marketID,
    const Amount depth) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(reason,
        GET_MARKET_OFFERS,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID/*,
        marketID,
        depth*/));
}

auto ServerAction::DownloadMarketRecentTrades(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID,
    const Identifier& marketID) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(reason,
        GET_MARKET_RECENT_TRADES,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID/*,
        marketID*/));
}

auto ServerAction::DownloadNymMarketOffers(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(
        reason,
        GET_NYM_MARKET_OFFERS,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID));
}

auto ServerAction::ExchangeBasketCurrency(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID,
    const identifier::UnitDefinition& instrumentDefinitionID,
    const Identifier& accountID,
    const Identifier& basketID,
    const bool direction) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(reason,
        EXCHANGE_BASKET,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID/*,
        instrumentDefinitionID,
        basketID,
        accountID,
        direction,
        api_.InternalClient().OTAPI().GetBasketMemberCount(basketID)*/));
}

auto ServerAction::IssueBasketCurrency(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID,
    const proto::UnitDefinition& basket,
    const UnallocatedCString& label) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(reason,
        ISSUE_BASKET,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID/*,
        basket,
        label*/));
}

auto ServerAction::KillMarketOffer(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID,
    const Identifier& accountID,
    const TransactionNumber number) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(reason,
        KILL_MARKET_OFFER,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID/*,
        accountID,
        number*/));
}

auto ServerAction::KillPaymentPlan(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID,
    const Identifier& accountID,
    const TransactionNumber number) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(reason,
        KILL_PAYMENT_PLAN,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID/*,
        accountID,
        number*/));
}

auto ServerAction::PayDividend(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID,
    const identifier::UnitDefinition& instrumentDefinitionID,
    const Identifier& accountID,
    const UnallocatedCString& memo,
    const Amount amountPerShare) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(reason,
        PAY_DIVIDEND,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID/*,
        accountID,
        instrumentDefinitionID,
        amountPerShare,
        memo*/));
}

auto ServerAction::TriggerClause(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID,
    const TransactionNumber transactionNumber,
    const UnallocatedCString& clause,
    const UnallocatedCString& parameter) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(reason,
        TRIGGER_CLAUSE,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID/*,
        transactionNumber,
        clause,
        parameter*/));
}

auto ServerAction::UnregisterAccount(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID,
    const Identifier& accountID) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(reason,
        DELETE_ASSET_ACCT,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID/*,
        accountID*/));
}

auto ServerAction::UnregisterNym(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(
        reason,
        DELETE_NYM,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID));
}

auto ServerAction::WithdrawVoucher(
    const PasswordPrompt& reason,
    const identifier::Nym& localNymID,
    const identifier::Notary& serverID,
    const Identifier& accountID,
    const identifier::Nym& recipientNymID,
    const Amount amount,
    const UnallocatedCString& memo) const -> ServerAction::Action
{
    return Action(new OTAPI_Func(reason,
        WITHDRAW_VOUCHER,
        lock_callback_({localNymID.str(), serverID.str()}),
        api_,
        localNymID,
        serverID/*,
        accountID,
        recipientNymID,
        amount,
        memo*/));
}
}  // namespace opentxs::otx::client::implementation
