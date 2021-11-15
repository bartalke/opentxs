// Copyright (c) 2010-2021 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "0_stdafx.hpp"             // IWYU pragma: associated
#include "1_Internal.hpp"           // IWYU pragma: associated
#include "api/Legacy.hpp"           // IWYU pragma: associated
#include "api/context/Context.hpp"  // IWYU pragma: associated
#include "util/Thread.hpp"          // IWYU pragma: associated

extern "C" {
#include <sys/resource.h>
}

namespace opentxs
{
auto SetThisThreadsPriority(ThreadPriority) noexcept -> void
{
    // TODO
}
}  // namespace opentxs

namespace opentxs::api::implementation
{
auto Context::set_desired_files(::rlimit& out) noexcept -> void
{
    out.rlim_cur = OPEN_MAX;
    out.rlim_max = OPEN_MAX;
}

auto Legacy::get_suffix() noexcept -> fs::path
{
    return get_suffix("OpenTransactions");
}

auto Legacy::prepend() noexcept -> std::string
{
#if TARGET_OS_IPHONE  // iOS
    return "Documents/";
#else  // OSX
    return "Library/Application Support/";
#endif
}

auto Legacy::use_dot() noexcept -> bool { return false; }
}  // namespace opentxs::api::implementation
