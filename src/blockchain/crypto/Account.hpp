// Copyright (c) 2010-2021 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

// IWYU pragma: no_include "opentxs/blockchain/crypto/HDProtocol.hpp"

#pragma once

#include <algorithm>
#include <cstddef>
#include <iosfwd>
#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "internal/api/Api.hpp"
#include "internal/blockchain/crypto/Crypto.hpp"
#include "opentxs/Types.hpp"
#include "opentxs/blockchain/Blockchain.hpp"
#include "opentxs/blockchain/BlockchainType.hpp"
#include "opentxs/blockchain/Types.hpp"
#include "opentxs/blockchain/crypto/Account.hpp"
#include "opentxs/blockchain/crypto/AddressStyle.hpp"
#include "opentxs/blockchain/crypto/Subaccount.hpp"
#include "opentxs/blockchain/crypto/Subchain.hpp"
#include "opentxs/blockchain/crypto/Types.hpp"
#include "opentxs/blockchain/crypto/Wallet.hpp"
#include "opentxs/core/Identifier.hpp"
#include "opentxs/core/Log.hpp"
#include "opentxs/core/LogSource.hpp"
#include "opentxs/core/crypto/PaymentCode.hpp"
#include "opentxs/core/identifier/Nym.hpp"
#include "opentxs/network/zeromq/socket/Push.hpp"

namespace opentxs
{
namespace api
{
namespace client
{
namespace internal
{
class BalanceTreeIndex;
}  // namespace internal
}  // namespace client

namespace internal
{
struct Core;
}  // namespace internal
}  // namespace api

namespace blockchain
{
namespace crypto
{
class Element;
}  // namespace crypto
}  // namespace blockchain

namespace proto
{
class HDPath;
}  // namespace proto

class PasswordPrompt;
class PaymentCode;
}  // namespace opentxs

namespace opentxs::blockchain::crypto::implementation
{
class Account final : public internal::Account
{
public:
    using Accounts = std::set<OTIdentifier>;

    auto AccountID() const noexcept -> const Identifier& final
    {
        return account_id_;
    }
    auto AssociateTransaction(
        const std::vector<Activity>& unspent,
        const std::vector<Activity>& spent,
        std::set<OTIdentifier>& contacts,
        const PasswordPrompt& reason) const noexcept -> bool final;
    auto Chain() const noexcept -> opentxs::blockchain::Type final
    {
        return chain_;
    }
    auto ClaimAccountID(const std::string& id, internal::Subaccount* node)
        const noexcept -> void final;
    auto FindNym(const identifier::Nym& id) const noexcept -> void final;
    auto GetDepositAddress(
        const blockchain::crypto::AddressStyle style,
        const PasswordPrompt& reason,
        const std::string& memo) const noexcept -> std::string final;
    auto GetDepositAddress(
        const blockchain::crypto::AddressStyle style,
        const Identifier& contact,
        const PasswordPrompt& reason,
        const std::string& memo) const noexcept -> std::string final;
    auto GetHD() const noexcept -> const HDAccounts& final { return hd_; }
    auto GetImported() const noexcept -> const ImportedAccounts& final
    {
        return imported_;
    }
    auto GetNextChangeKey(const PasswordPrompt& reason) const noexcept(false)
        -> const Element& final;
    auto GetNextDepositKey(const PasswordPrompt& reason) const noexcept(false)
        -> const Element& final;
    auto GetPaymentCode() const noexcept -> const PaymentCodeAccounts& final
    {
        return payment_code_;
    }
    auto HDChain(const Identifier& account) const noexcept(false)
        -> const internal::HD& final
    {
        return hd_.at(account);
    }
    auto LookupUTXO(const Coin& coin) const noexcept
        -> std::optional<std::pair<Key, Amount>> final;
    auto Node(const Identifier& id) const noexcept(false)
        -> internal::Subaccount& final;
    auto NymID() const noexcept -> const identifier::Nym& final
    {
        return nym_id_;
    }
    auto PaymentCode(const Identifier& account) const noexcept(false)
        -> const internal::PaymentCode& final
    {
        return payment_code_.at(account);
    }
    auto Parent() const noexcept -> const crypto::Wallet& final
    {
        return parent_;
    }
    auto ParentInternal() const noexcept -> const internal::Wallet& final
    {
        return parent_;
    }

    auto AddHDNode(
        const proto::HDPath& path,
        const crypto::HDProtocol standard,
        const PasswordPrompt& reason,
        Identifier& id) noexcept -> bool final
    {
        return hd_.Construct(id, path, standard, reason);
    }
    auto AddUpdatePaymentCode(
        const opentxs::PaymentCode& local,
        const opentxs::PaymentCode& remote,
        const proto::HDPath& path,
        const PasswordPrompt& reason,
        Identifier& out) noexcept -> bool final
    {
        return payment_code_.Construct(out, local, remote, path, reason);
    }
    auto AddUpdatePaymentCode(
        const opentxs::PaymentCode& local,
        const opentxs::PaymentCode& remote,
        const proto::HDPath& path,
        const opentxs::blockchain::block::Txid& txid,
        const PasswordPrompt& reason,
        Identifier& out) noexcept -> bool final
    {
        return payment_code_.Construct(out, local, remote, path, txid, reason);
    }
    auto HDChain(const Identifier& account) noexcept(false)
        -> internal::HD& final
    {
        return hd_.at(account);
    }
    auto PaymentCode(const Identifier& account) noexcept(false)
        -> internal::PaymentCode& final
    {
        return payment_code_.at(account);
    }

    Account(
        const api::internal::Core& api,
        const internal::Wallet& parent,
        const api::client::internal::BalanceTreeIndex& index,
        const identifier::Nym& nym,
        const Accounts& hd,
        const Accounts& imported,
        const Accounts& paymentCode) noexcept;

    ~Account() final = default;

private:
    template <typename InterfaceType, typename PayloadType>
    class NodeGroup final : virtual public InterfaceType
    {
    public:
        using const_iterator = typename InterfaceType::const_iterator;
        using value_type = typename InterfaceType::value_type;

        auto at(const std::size_t position) const -> const value_type& final
        {
            Lock lock(lock_);

            return *nodes_.at(position);
        }
        auto at(const Identifier& id) const -> const PayloadType& final
        {
            Lock lock(lock_);

            return *nodes_.at(index_.at(id));
        }
        auto begin() const noexcept -> const_iterator final
        {
            return const_iterator(this, 0);
        }
        auto cbegin() const noexcept -> const_iterator final
        {
            return const_iterator(this, 0);
        }
        auto cend() const noexcept -> const_iterator final
        {
            return const_iterator(this, nodes_.size());
        }
        auto end() const noexcept -> const_iterator final
        {
            return const_iterator(this, nodes_.size());
        }
        auto size() const noexcept -> std::size_t final
        {
            return nodes_.size();
        }

        auto at(const std::size_t position) -> value_type&
        {
            Lock lock(lock_);

            return *nodes_.at(position);
        }
        auto at(const Identifier& id) -> PayloadType&
        {
            Lock lock(lock_);

            return *nodes_.at(index_.at(id));
        }
        template <typename... Args>
        auto Construct(Identifier& out, const Args&... args) noexcept -> bool
        {
            Lock lock(lock_);

            return construct(lock, out, args...);
        }

        NodeGroup(const api::internal::Core& api, Account& parent) noexcept
            : api_(api)
            , parent_(parent)
            , lock_()
            , nodes_()
            , index_()
        {
        }

    private:
        const api::internal::Core& api_;
        Account& parent_;
        mutable std::mutex lock_;
        std::vector<std::unique_ptr<PayloadType>> nodes_;
        std::map<OTIdentifier, std::size_t> index_;

        auto add(
            const Lock& lock,
            const Identifier& id,
            std::unique_ptr<PayloadType> node) noexcept -> bool;
        template <typename... Args>
        auto construct(
            const Lock& lock,
            Identifier& id,
            const Args&... args) noexcept -> bool
        {
            auto node{
                Factory<PayloadType, Args...>::get(api_, parent_, id, args...)};

            if (false == bool(node)) { return false; }

            if (0 < index_.count(id)) {
                LogOutput("Blockchain account ")(id)(" already exists").Flush();

                return false;
            }

            return add(lock, id, std::move(node));
        }
    };

    template <typename ReturnType, typename... Args>
    struct Factory {
        static auto get(
            const api::internal::Core& api,
            const Account& parent,
            Identifier& id,
            const Args&... args) noexcept -> std::unique_ptr<ReturnType>;
    };

    struct NodeIndex {
        auto Find(const std::string& id) const noexcept
            -> internal::Subaccount*;

        void Add(const std::string& id, internal::Subaccount* node) noexcept;

        NodeIndex() noexcept
            : lock_()
            , index_()
        {
        }

    private:
        mutable std::mutex lock_;
        std::map<std::string, internal::Subaccount*> index_;
    };

    using HDNodes = NodeGroup<HDAccounts, internal::HD>;
    using ImportedNodes = NodeGroup<ImportedAccounts, internal::Imported>;
    using PaymentCodeNodes =
        NodeGroup<PaymentCodeAccounts, internal::PaymentCode>;

    const api::internal::Core& api_;
    const internal::Wallet& parent_;
    const api::client::internal::BalanceTreeIndex& account_index_;
    const opentxs::blockchain::Type chain_;
    const OTNymID nym_id_;
    const OTIdentifier account_id_;
    HDNodes hd_;
    ImportedNodes imported_;
    PaymentCodeNodes payment_code_;
    mutable NodeIndex node_index_;
    mutable std::mutex lock_;
    mutable internal::ActivityMap unspent_;
    mutable internal::ActivityMap spent_;
    OTZMQPushSocket find_nym_;

    void init_hd(const Accounts& HDAccounts) noexcept;
    void init_payment_code(const Accounts& HDAccounts) noexcept;

    auto find_next_element(
        Subchain subchain,
        const Identifier& contact,
        const std::string& label,
        const PasswordPrompt& reason) const noexcept(false) -> const Element&;

    Account() = delete;
    Account(const Account&) = delete;
    Account(Account&&) = delete;
    auto operator=(const Account&) -> Account& = delete;
    auto operator=(Account&&) -> Account& = delete;
};
}  // namespace opentxs::blockchain::crypto::implementation
