# Copyright (c) 2010-2022 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

set(cxx-install-headers
    "${opentxs_SOURCE_DIR}/include/opentxs/blockchain/bitcoin/cfilter/FilterType.hpp"
    "${opentxs_SOURCE_DIR}/include/opentxs/blockchain/bitcoin/cfilter/Hash.hpp"
    "${opentxs_SOURCE_DIR}/include/opentxs/blockchain/bitcoin/cfilter/Header.hpp"
    "${opentxs_SOURCE_DIR}/include/opentxs/blockchain/bitcoin/cfilter/Types.hpp"
)

target_sources(
  opentxs-common
  PRIVATE
    "${opentxs_SOURCE_DIR}/src/internal/blockchain/bitcoin/cfilter/GCS.hpp"
    "Hash.cpp"
    "Header.cpp"
)

if(OT_BLOCKCHAIN_EXPORT)
  target_sources(opentxs-common PRIVATE "GCS.cpp" "GCS.hpp")
  target_link_libraries(opentxs-common PRIVATE Boost::headers)
  list(
    APPEND
    cxx-install-headers
    "${opentxs_SOURCE_DIR}/include/opentxs/blockchain/bitcoin/cfilter/GCS.hpp"
  )
endif()

target_sources(opentxs-common PRIVATE ${cxx-install-headers})

if(OPENTXS_STANDALONE)
  install(
    FILES ${cxx-install-headers}
    DESTINATION include/opentxs/blockchain/bitcoin/cfilter
    COMPONENT dev
  )
endif()
