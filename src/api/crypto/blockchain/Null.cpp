// Copyright (c) 2010-2021 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "0_stdafx.hpp"                          // IWYU pragma: associated
#include "1_Internal.hpp"                        // IWYU pragma: associated
#include "api/crypto/blockchain/Blockchain.hpp"  // IWYU pragma: associated

#include "api/crypto/blockchain/Imp.hpp"

namespace opentxs::api::crypto::imp
{
Blockchain::Blockchain(
    const api::Session& api,
    const api::session::Activity&,
    const api::session::Contacts& contacts,
    const api::Legacy&,
    const std::string&,
    const Options& args) noexcept
    : imp_(std::make_unique<Imp>(api, contacts, *this))
{
    // WARNING: do not access api_.Wallet() during construction
}
}  // namespace opentxs::api::crypto::imp
