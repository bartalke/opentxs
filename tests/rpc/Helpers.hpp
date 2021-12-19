// Copyright (c) 2010-2021 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

// IWYU pragma: no_include "opentxs/core/UnitType.hpp"
// IWYU pragma: no_include "opentxs/crypto/Language.hpp"
// IWYU pragma: no_include "opentxs/crypto/SeedStyle.hpp"

#pragma once

#include <gtest/gtest.h>
#include <cstddef>
#include <cstdint>
#include <iosfwd>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "opentxs/core/Amount.hpp"
#include "opentxs/core/Types.hpp"
#include "opentxs/util/Bytes.hpp"

namespace opentxs
{
namespace api
{
namespace session
{
class Client;
class Notary;
}  // namespace session

class Context;
class Session;
}  // namespace api

namespace display
{
class Definition;
}  // namespace display

namespace identifier
{
class Nym;
class Server;
}  // namespace identifier

namespace network
{
namespace zeromq
{
class Message;
}  // namespace zeromq
}  // namespace network

class Amount;
class Identifier;
}  // namespace opentxs

namespace ot = opentxs;
namespace zmq = ot::network::zeromq;

namespace ottest
{
struct AccountActivityData;
struct AccountListData;
struct User;

auto check_account_activity_rpc(
    const User& user,
    const ot::Identifier& account,
    const AccountActivityData& expected) noexcept -> bool;
auto check_account_list_rpc(
    const User& user,
    const AccountListData& expected) noexcept -> bool;

class RPCPushCounter
{
public:
    auto at(std::size_t index) const -> const zmq::Message&;
    auto size() const noexcept -> std::size_t;
    auto wait(std::size_t index) const noexcept -> bool;

    auto shutdown() noexcept -> void;

    RPCPushCounter(const ot::api::Context& ot) noexcept;

    ~RPCPushCounter();

private:
    struct Imp;

    std::unique_ptr<Imp> imp_;

    RPCPushCounter(const RPCPushCounter&) = delete;
    RPCPushCounter(RPCPushCounter&&) = delete;
    auto operator=(const RPCPushCounter&) -> RPCPushCounter& = delete;
    auto operator=(RPCPushCounter&&) -> RPCPushCounter& = delete;
};

class RPC_fixture : virtual public ::testing::Test
{
protected:
    using AccountMap = std::map<std::string, std::vector<std::string>>;
    using Amount = ot::Amount;
    using IssuedUnits = std::vector<std::string>;
    using LocalNymMap = std::map<int, std::set<std::string>>;
    using SeedMap = std::map<int, std::set<std::string>>;

    static SeedMap seed_map_;
    static LocalNymMap local_nym_map_;
    static IssuedUnits created_units_;
    static AccountMap registered_accounts_;

    const ot::api::Context& ot_;
    RPCPushCounter& push_;

    auto CreateNym(
        const ot::api::Session& api,
        const std::string& name,
        const std::string& seed,
        int index) const noexcept -> std::string;
    auto DepositCheques(
        const ot::api::session::Client& api,
        const ot::api::session::Notary& server,
        const std::string& nym) const noexcept -> std::size_t;
    auto ImportBip39(const ot::api::Session& api, const std::string& words)
        const noexcept -> std::string;
    auto ImportServerContract(
        const ot::api::session::Notary& from,
        const ot::api::session::Client& to) const noexcept -> bool;
    // TODO modify UIHelpers and put the Counter struct in a non-anonymous
    // namespace so that we can forward declare the type without "declared but
    // not defined" errors
    auto InitAccountActivityCounter(
        const ot::api::session::Client& api,
        const std::string& nym,
        const std::string& account,
        void* counter) const noexcept -> void;
    auto IssueUnit(
        const ot::api::session::Client& api,
        const ot::api::session::Notary& server,
        const std::string& issuer,
        const std::string& shortname,
        const std::string& terms,
        ot::core::UnitType unitOfAccount,
        const ot::display::Definition& displayDefinition) const noexcept
        -> std::string;
    auto RefreshAccount(
        const ot::api::session::Client& api,
        const ot::identifier::Nym& nym,
        const ot::identifier::Server& server) const noexcept -> void;
    auto RefreshAccount(
        const ot::api::session::Client& api,
        const std::vector<std::string> nyms,
        const ot::identifier::Server& server) const noexcept -> void;
    auto RegisterAccount(
        const ot::api::session::Client& api,
        const ot::api::session::Notary& server,
        const std::string& nym,
        const std::string& unit,
        const std::string& label) const noexcept -> std::string;
    auto RegisterNym(
        const ot::api::session::Client& api,
        const ot::api::session::Notary& server,
        const std::string& nym) const noexcept -> bool;
    auto SendCheque(
        const ot::api::session::Client& api,
        const ot::api::session::Notary& server,
        const std::string& nym,
        const std::string& account,
        const std::string& contact,
        const std::string& memo,
        Amount amount) const noexcept -> bool;
    auto SendTransfer(
        const ot::api::session::Client& api,
        const ot::api::session::Notary& server,
        const std::string& sender,
        const std::string& fromAccount,
        const std::string& toAccount,
        const std::string& memo,
        Amount amount) const noexcept -> bool;
    auto SetIntroductionServer(
        const ot::api::session::Client& on,
        const ot::api::session::Notary& to) const noexcept -> bool;
    auto StartClient(int index) const noexcept
        -> const ot::api::session::Client&;
    auto StartNotarySession(int index) const noexcept
        -> const ot::api::session::Notary&;

    virtual auto Cleanup() noexcept -> void;

    RPC_fixture() noexcept;

private:
    auto init_maps(int instance) const noexcept -> void;
};
}  // namespace ottest
