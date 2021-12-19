// Copyright (c) 2010-2021 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

// IWYU pragma: no_include "opentxs/core/UnitType.hpp"

#pragma once

#include <cstdint>
#include <locale>
#include <map>
#include <optional>
#include <string>

#include "Proto.hpp"
#include "core/contract/Signable.hpp"
#include "opentxs/Types.hpp"
#include "opentxs/contact/ClaimType.hpp"
#include "opentxs/core/Account.hpp"
#include "opentxs/core/Amount.hpp"
#include "opentxs/core/Data.hpp"
#include "opentxs/core/Identifier.hpp"
#include "opentxs/core/Types.hpp"
#include "opentxs/core/contract/UnitDefinition.hpp"
#include "opentxs/core/contract/UnitType.hpp"
#include "opentxs/core/display/Definition.hpp"
#include "opentxs/util/Bytes.hpp"
#include "opentxs/util/Numbers.hpp"

namespace opentxs
{
namespace api
{
class Session;
}  // namespace api

namespace proto
{
class Signature;
}  // namespace proto

class AccountVisitor;
class Factory;
class PasswordPrompt;
class String;
}  // namespace opentxs

namespace opentxs::contract::implementation
{
class Unit : virtual public contract::Unit,
             public opentxs::contract::implementation::Signable
{
public:
    static const std::map<VersionNumber, VersionNumber>
        unit_of_account_version_map_;

    static auto GetID(const api::Session& api, const SerializedType& contract)
        -> OTIdentifier;

    auto AddAccountRecord(
        const std::string& dataFolder,
        const Account& theAccount) const -> bool override;
    auto DisplayStatistics(String& strContents) const -> bool override;
    auto EraseAccountRecord(
        const std::string& dataFolder,
        const Identifier& theAcctID) const -> bool override;
    auto Name() const -> std::string override { return short_name_; }
    auto Serialize() const -> OTData override;
    auto Serialize(AllocateOutput destination, bool includeNym = false) const
        -> bool override;
    auto Serialize(SerializedType&, bool includeNym = false) const
        -> bool override;
    auto Type() const -> contract::UnitType override = 0;
    auto UnitOfAccount() const -> core::UnitType override
    {
        return unit_of_account_;
    }
    auto VisitAccountRecords(
        const std::string& dataFolder,
        AccountVisitor& visitor,
        const PasswordPrompt& reason) const -> bool override;

    void InitAlias(const std::string& alias) final
    {
        contract::implementation::Signable::SetAlias(alias);
    }
    void SetAlias(const std::string& alias) override;

    ~Unit() override = default;

protected:
    const core::UnitType unit_of_account_;

    virtual auto IDVersion(const Lock& lock) const -> SerializedType;
    virtual auto SigVersion(const Lock& lock) const -> SerializedType;
    auto validate(const Lock& lock) const -> bool override;

    auto update_signature(const Lock& lock, const PasswordPrompt& reason)
        -> bool override;

    Unit(
        const api::Session& api,
        const Nym_p& nym,
        const std::string& shortname,
        const std::string& terms,
        const core::UnitType unitOfAccount,
        const VersionNumber version,
        const display::Definition& displayDefinition,
        const Amount& redemptionIncrement);
    Unit(
        const api::Session& api,
        const Nym_p& nym,
        const SerializedType serialized);
    Unit(const Unit&);

private:
    friend opentxs::Factory;

    struct Locale : std::numpunct<char> {
    };

    static const Locale locale_;

    std::optional<display::Definition> display_definition_;
    const Amount redemption_increment_;
    const std::string short_name_;

    auto contract(const Lock& lock) const -> SerializedType;
    auto GetID(const Lock& lock) const -> OTIdentifier override;
    auto get_displayscales(const SerializedType&) const
        -> std::optional<display::Definition>;
    auto get_unitofaccount(const SerializedType&) const -> core::UnitType;
    auto verify_signature(const Lock& lock, const proto::Signature& signature)
        const -> bool override;

    Unit(Unit&&) = delete;
    auto operator=(const Unit&) -> Unit& = delete;
    auto operator=(Unit&&) -> Unit& = delete;
};
}  // namespace opentxs::contract::implementation
