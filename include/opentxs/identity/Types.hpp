// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include "opentxs/Version.hpp"  // IWYU pragma: associated

#include <cstddef>
#include <cstdint>
#include <memory>
#include <string_view>

// NOLINTBEGIN(modernize-concat-nested-namespaces)
namespace opentxs  // NOLINT
{
// inline namespace v1
// {
namespace identity
{
class Nym;
}  // namespace identity
// }  // namespace v1
}  // namespace opentxs
// NOLINTEND(modernize-concat-nested-namespaces)

namespace opentxs::identity
{
enum class CredentialRole : std::uint32_t;
enum class CredentialType : std::uint32_t;
enum class Type : std::uint32_t;
enum class SourceProofType : std::uint32_t;
enum class SourceType : std::uint32_t;
enum class NymCapability : std::uint8_t {
    SIGN_MESSAGE = 0,
    ENCRYPT_MESSAGE = 1,
    AUTHENTICATE_CONNECTION = 2,
    SIGN_CHILDCRED = 3,
};
}  // namespace opentxs::identity

namespace opentxs
{
using Nym_p = std::shared_ptr<const identity::Nym>;

OPENTXS_EXPORT auto print(identity::CredentialRole value) noexcept
    -> std::string_view;
OPENTXS_EXPORT auto print(identity::CredentialType value) noexcept
    -> std::string_view;
OPENTXS_EXPORT auto print(identity::Type value) noexcept -> std::string_view;
OPENTXS_EXPORT auto print(identity::SourceProofType value) noexcept
    -> std::string_view;
OPENTXS_EXPORT auto print(identity::SourceType value) noexcept
    -> std::string_view;
}  // namespace opentxs
