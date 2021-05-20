// Copyright (c) 2010-2021 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <gtest/gtest.h>
#include <iterator>
#include <regex>
#include <string>

#include "OTTestEnvironment.hpp"  // IWYU pragma: keep
#include "opentxs/OT.hpp"
#include "opentxs/api/Context.hpp"
#include "opentxs/api/Factory.hpp"
#include "opentxs/api/Wallet.hpp"
#include "opentxs/api/client/Blockchain.hpp"
#include "opentxs/api/client/Contacts.hpp"
#include "opentxs/api/client/Manager.hpp"
#include "opentxs/api/client/blockchain/BalanceNode.hpp"
#include "opentxs/blockchain/Blockchain.hpp"
#include "opentxs/blockchain/BlockchainType.hpp"
#include "opentxs/blockchain/block/bitcoin/Transaction.hpp"
#include "opentxs/client/OTAPI_Exec.hpp"
#include "opentxs/contact/Contact.hpp"
#include "opentxs/core/Data.hpp"
#include "opentxs/core/PasswordPrompt.hpp"
#include "opentxs/core/crypto/NymParameters.hpp"
#include "opentxs/core/identifier/Nym.hpp"
#include "opentxs/identity/Nym.hpp"

namespace ottest
{
struct Test_BlockchainActivity : public ::testing::Test {
    using Element = ot::api::client::blockchain::BalanceNode::Element;
    using Transaction = ot::blockchain::block::bitcoin::Transaction;

    static const std::string test_transaction_hex_;
    static const std::string btc_account_id_;
    static const std::string btc_unit_id_;
    static const std::string btc_notary_id_;
    static const std::string nym_1_name_;
    static const std::string nym_2_name_;
    static const std::string contact_3_name_;
    static const std::string contact_4_name_;
    static const std::string contact_5_name_;
    static const std::string contact_6_name_;
    static const std::string contact_7_name_;

    const ot::api::client::Manager& api_;
    const ot::OTPasswordPrompt reason_;

    auto account_1_id() const noexcept -> const ot::Identifier&;
    auto account_2_id() const noexcept -> const ot::Identifier&;
    auto contact_1_id() const noexcept -> const ot::Identifier&;
    auto contact_2_id() const noexcept -> const ot::Identifier&;
    auto contact_3_id() const noexcept -> const ot::Identifier&;
    auto contact_4_id() const noexcept -> const ot::Identifier&;
    auto contact_5_id() const noexcept -> const ot::Identifier&;
    auto contact_6_id() const noexcept -> const ot::Identifier&;
    auto contact_7_id() const noexcept -> const ot::Identifier&;
    auto get_test_transaction(
        const Element& first,
        const Element& second,
        const ot::Time& time = ot::Clock::now()) const
        -> std::unique_ptr<const Transaction>;
    auto get_test_transaction(
        const Element& inputKey1,
        const Element& inputKey2,
        const Element& inputKey3,
        const Element& outputKey1,
        const ot::proto::BlockchainTransactionOutput& prevOut1,
        const ot::proto::BlockchainTransactionOutput& prevOut2,
        const ot::proto::BlockchainTransactionOutput& prevOut3,
        const std::string& secondOutput,
        const ot::Time& time = ot::Clock::now()) const
        -> std::unique_ptr<const Transaction>;
    auto monkey_patch(const Element& first, const Element& second)
        const noexcept -> std::string;
    auto monkey_patch(const std::string& first, const std::string& second)
        const noexcept -> std::string;
    auto nym_1_id() const noexcept -> const ot::identifier::Nym&;
    auto nym_2_id() const noexcept -> const ot::identifier::Nym&;
    auto seed() const noexcept -> const std::string&;
    auto words() const noexcept -> const std::string&;

    Test_BlockchainActivity();
};
}  // namespace ottest
