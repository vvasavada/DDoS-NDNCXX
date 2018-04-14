/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2013-2017 Regents of the University of California.
 *
 * This file is part of ndn-cxx library (NDN C++ library with eXperimental eXtensions).
 *
 * ndn-cxx library is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later version.
 *
 * ndn-cxx library is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
 *
 * You should have received copies of the GNU General Public License and GNU Lesser
 * General Public License along with ndn-cxx, e.g., in COPYING.md file.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * See AUTHORS.md for complete list of ndn-cxx authors and contributors.
 *
 * @author Eric Newberry <enewberry@email.arizona.edu>
 */

#ifndef NDN_CXX_LP_NACK_HEADER_HPP
#define NDN_CXX_LP_NACK_HEADER_HPP

#include "../common.hpp"
#include "../name.hpp"
#include "../encoding/encoding-buffer.hpp"
#include "../encoding/block-helpers.hpp"
#include "tlv.hpp"
#include <list>

namespace ndn {
namespace lp {

/**
 * \brief indicates the reason type of a network NACK
 */
enum class NackReason {
  DDOS_HINT_CHANGE_NOTICE = -150,
  DDOS_FAKE_INTEREST = -100,
  DDOS_VALID_INTEREST_OVERLOAD = -50,
  NONE = 0,
  CONGESTION = 50,
  DUPLICATE = 100,
  NO_ROUTE = 150,
};

std::ostream&
operator<<(std::ostream& os, NackReason reason);

/** \brief compare NackReason for severity
 *
 *  lp::NackReason::NONE is treated as most severe
 */
bool
isLessSevere(lp::NackReason x, lp::NackReason y);

/**
 * \brief represents a Network NACK header
 */
class NackHeader
{
public:
  NackHeader();

  explicit
  NackHeader(const Block& block);

  template<encoding::Tag TAG>
  size_t
  wireEncode(EncodingImpl<TAG>& encoder) const;

  const Block&
  wireEncode() const;

  void
  wireDecode(const Block& wire);

public: // reason
  /**
   * \return reason code
   * \retval NackReason::NONE if NackReason element does not exist or has an unknown code
   */
  NackReason
  getReason() const;

  /**
   * \brief set reason code
   * \param reason a reason code; NackReason::NONE clears the reason
   */
  NackHeader&
  setReason(NackReason reason);

  /**
   * \return expected fake interest percentage
   */
  uint64_t getExpFakePerc() const;

  /**
   * \brief set expected fake interest percentage
   * \param percentage
   */
  NackHeader&
  setExpFakePerc(uint64_t expFakePerc);

  /**
   * \return list of fake interest names
   */
  std::list<Name> getFakeInterestNames() const;

  /**
   * \brief set fake interest names
   * \param list of fake interest names
   */
  NackHeader&
  setFakeInterestNames(std::list<Name> fakeInterestNames);

  uint64_t
  getPrefixLen() const;

  /**
   * \brief set prefix length
   * \param the length of the prefix
   *
   * When a router receives a Nack containing the prefix, the router should handle all
   * the PIT entries under the prefix of the Interest
   */
  NackHeader&
  setPrefixLen(uint64_t m_prefixLen);

public:
  NackReason m_reason;

  // specify the prefix
  uint64_t m_prefixLen;

  // used for fake interest attack
  // control the fake interest percentage to be less than m_fakeTolerance
  // e.g. if value is 50, the tolerance is 50 fake interest per second
  uint64_t m_fakeTolerance;

  // used for fake interest attack
  // contains the list of fake interest name THAT ONLY AFTER THE PREFIX
  std::list<Name> m_fakeInterestNames;

  mutable Block m_wire;
};

NDN_CXX_DECLARE_WIRE_ENCODE_INSTANTIATIONS(NackHeader);

} // namespace lp
} // namespace ndn

#endif // NDN_CXX_LP_NACK_HEADER_HPP
