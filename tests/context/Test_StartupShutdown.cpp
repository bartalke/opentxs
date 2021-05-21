// Copyright (c) 2010-2021 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <memory>

#include "OTLowLevelTestEnvironment.hpp"
#include "opentxs/OT.hpp"

TEST(StartupShutdown, create)
{
    ot::InitContext(OTLowLevelTestEnvironment::Args());
    ot::Cleanup();
}

TEST(StartupShutdown, restart)
{
    ot::InitContext(OTLowLevelTestEnvironment::Args());
    ot::Cleanup();
}
