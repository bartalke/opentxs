// Copyright (c) 2010-2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs/protobuf/verify/VerifyBlockchain.hpp"  // IWYU pragma: associated

namespace opentxs::proto
{
auto Bip47ChainAllowedBip47Channel() noexcept -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto Bip47ChannelAllowedBip47Direction() noexcept -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto Bip47ContextAllowedBip47Chain() noexcept -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto Bip47DirectionAllowedBip47Address() noexcept -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto BlockchainAddressAllowedAsymmetricKey() noexcept -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {2, 2}},
    };

    return output;
}
auto BlockchainBlockHeaderAllowedBitcoinBlockHeaderFields() noexcept
    -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto BlockchainBlockHeaderAllowedBlockchainBlockLocalData() noexcept
    -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto BlockchainBlockHeaderAllowedEthereumBlockHeaderFields() noexcept
    -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto BlockchainP2PHelloAllowedBlockchainP2PChainState() noexcept
    -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto BlockchainTransactionAllowedInput() noexcept -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto BlockchainTransactionAllowedOutput() noexcept -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto BlockchainTransactionInputAllowedBlockchainInputWitness() noexcept
    -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto BlockchainTransactionInputAllowedBlockchainPreviousOutput() noexcept
    -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto BlockchainTransactionInputAllowedBlockchainTransactionOutput() noexcept
    -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto BlockchainTransactionInputAllowedBlockchainWalletKey() noexcept
    -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto BlockchainTransactionOutputAllowedBlockchainWalletKey() noexcept
    -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto BlockchainTransactionProposalAllowedBlockchainTransaction() noexcept
    -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto BlockchainTransactionProposalAllowedBlockchainTransactionProposedOutput() noexcept
    -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto BlockchainTransactionProposedOutputAllowedBlockchainOutputMultisigDetails() noexcept
    -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto HDAccountAllowedBlockchainActivity() noexcept -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto HDAccountAllowedBlockchainAddress() noexcept -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
auto HDAccountAllowedHDPath() noexcept -> const VersionMap&
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
}  // namespace opentxs::proto
