// Copyright (c) 2010-2021 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "0_stdafx.hpp"                // IWYU pragma: associated
#include "1_Internal.hpp"              // IWYU pragma: associated
#include "ui/profile/ProfileItem.hpp"  // IWYU pragma: associated

#include <memory>
#include <set>
#include <tuple>
#include <utility>

#include "internal/contact/Contact.hpp"
#include "internal/ui/UI.hpp"
#include "internal/util/LogMacros.hpp"
#include "opentxs/api/session/Client.hpp"
#include "opentxs/api/session/Factory.hpp"
#include "opentxs/api/session/Wallet.hpp"
#include "opentxs/contact/Attribute.hpp"
#include "opentxs/contact/ContactItem.hpp"
#include "opentxs/util/NymEditor.hpp"
#include "ui/base/Widget.hpp"

namespace opentxs::factory
{
auto ProfileItemWidget(
    const ui::implementation::ProfileSubsectionInternalInterface& parent,
    const api::session::Client& api,
    const ui::implementation::ProfileSubsectionRowID& rowID,
    const ui::implementation::ProfileSubsectionSortKey& sortKey,
    ui::implementation::CustomData& custom) noexcept
    -> std::shared_ptr<ui::implementation::ProfileSubsectionRowInternal>
{
    using ReturnType = ui::implementation::ProfileItem;

    return std::make_shared<ReturnType>(parent, api, rowID, sortKey, custom);
}
}  // namespace opentxs::factory

namespace opentxs::ui::implementation
{
ProfileItem::ProfileItem(
    const ProfileSubsectionInternalInterface& parent,
    const api::session::Client& api,
    const ProfileSubsectionRowID& rowID,
    const ProfileSubsectionSortKey& sortKey,
    CustomData& custom) noexcept
    : ProfileItemRow(parent, api, rowID, true)
    , item_{new contact::ContactItem(
          extract_custom<contact::ContactItem>(custom))}
{
}

auto ProfileItem::add_claim(const Claim& claim) const noexcept -> bool
{
    auto reason = api_.Factory().PasswordPrompt(__func__);

    auto nym = api_.Wallet().mutable_Nym(parent_.NymID(), reason);

    return nym.AddClaim(claim, reason);
}

auto ProfileItem::as_claim() const noexcept -> Claim
{
    sLock lock(shared_lock_);
    Claim output{};
    auto& [id, section, type, value, start, end, attributes] = output;
    id = "";
    section = translate(parent_.Section());
    type = translate(parent_.Type());
    value = item_->Value();
    start = item_->Start();
    end = item_->End();

    if (item_->isPrimary()) {
        attributes.emplace(translate(contact::Attribute::Primary));
    }

    if (item_->isPrimary() || item_->isActive()) {
        attributes.emplace(translate(contact::Attribute::Active));
    }

    return output;
}

auto ProfileItem::Delete() const noexcept -> bool
{
    auto reason = api_.Factory().PasswordPrompt(__func__);

    auto nym = api_.Wallet().mutable_Nym(parent_.NymID(), reason);

    return nym.DeleteClaim(row_id_, reason);
}

auto ProfileItem::reindex(
    const ProfileSubsectionSortKey&,
    CustomData& custom) noexcept -> bool
{
    eLock lock(shared_lock_);
    item_ = std::make_unique<contact::ContactItem>(
        extract_custom<contact::ContactItem>(custom));

    OT_ASSERT(item_);

    return true;
}

auto ProfileItem::SetActive(const bool& active) const noexcept -> bool
{
    Claim claim{};
    auto& attributes = std::get<6>(claim);

    if (active) {
        attributes.emplace(translate(contact::Attribute::Active));
    } else {
        attributes.erase(translate(contact::Attribute::Active));
        attributes.erase(translate(contact::Attribute::Primary));
    }

    return add_claim(claim);
}

auto ProfileItem::SetPrimary(const bool& primary) const noexcept -> bool
{
    Claim claim{};
    auto& attributes = std::get<6>(claim);

    if (primary) {
        attributes.emplace(translate(contact::Attribute::Primary));
        attributes.emplace(translate(contact::Attribute::Active));
    } else {
        attributes.erase(translate(contact::Attribute::Primary));
    }

    return add_claim(claim);
}

auto ProfileItem::SetValue(const std::string& newValue) const noexcept -> bool
{
    Claim claim{};
    std::get<3>(claim) = newValue;

    return add_claim(claim);
}
}  // namespace opentxs::ui::implementation
