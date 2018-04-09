/************************************************************
 *
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  EMAIL:
 *  fellowtraveler@opentransactions.org
 *
 *  WEBSITE:
 *  http://www.opentransactions.org/
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This Source Code Form is subject to the terms of the
 *   Mozilla Public License, v. 2.0. If a copy of the MPL
 *   was not distributed with this file, You can obtain one
 *   at http://mozilla.org/MPL/2.0/.
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will
 *   be useful, but WITHOUT ANY WARRANTY; without even the
 *   implied warranty of MERCHANTABILITY or FITNESS FOR A
 *   PARTICULAR PURPOSE.  See the Mozilla Public License
 *   for more details.
 *
 ************************************************************/

#ifndef OPENTXS_STORAGE_TREE_NYMS_HPP
#define OPENTXS_STORAGE_TREE_NYMS_HPP

#include "opentxs/Forward.hpp"

#include "opentxs/api/storage/Storage.hpp"
#include "opentxs/api/Editor.hpp"
#include "opentxs/storage/tree/Node.hpp"
#include "opentxs/Types.hpp"

#include <map>
#include <mutex>
#include <set>
#include <string>
#include <tuple>

namespace opentxs
{
namespace storage
{

class Nym;
class Tree;

class Nyms : public Node
{
private:
    friend class Tree;

    mutable std::map<std::string, std::unique_ptr<class Nym>> nyms_;
    std::set<std::string> local_nyms_{};

    class Nym* nym(const std::string& id) const;
    class Nym* nym(const Lock& lock, const std::string& id) const;
    void save(class Nym* nym, const Lock& lock, const std::string& id);

    void init(const std::string& hash) override;
    bool save(const Lock& lock) const override;
    proto::StorageNymList serialize() const;

    Nyms(const opentxs::api::storage::Driver& storage, const std::string& hash);
    Nyms() = delete;
    Nyms(const Nyms&) = delete;
    Nyms(Nyms&&) = delete;
    Nyms operator=(const Nyms&) = delete;
    Nyms operator=(Nyms&&) = delete;

public:
    bool Exists(const std::string& id) const;
    const std::set<std::string> LocalNyms() const;
    void Map(NymLambda lambda) const;
    bool Migrate(const opentxs::api::storage::Driver& to) const override;
    const class Nym& Nym(const std::string& id) const;

    Editor<class Nym> mutable_Nym(const std::string& id);
    bool RelabelThread(const std::string& threadID, const std::string label);
    void UpgradeLocalnym();

    ~Nyms() = default;
};
}  // namespace storage
}  // namespace opentxs
#endif  // OPENTXS_STORAGE_TREE_NYMS_HPP
