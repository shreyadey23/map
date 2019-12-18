/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/**
 * Generated file
 * @file
 *
 * Generator Version : 10.6.1-1904
 */

#pragma once

#include <cmath>
#include <limits>
#include "ad/map/point/ECEFCoordinateValidInputRange.hpp"
#include "ad/map/point/ECEFHeading.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given ECEFHeading is within valid input range
 *
 * \param[in] input the ECEFHeading as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if ECEFHeading is considered to be within the specified input range
 *
 * \note the specified input range is defined by the ranges of all members
 */
inline bool withinValidInputRange(::ad::map::point::ECEFHeading const &input, bool const logErrors = true)
{
  // check for generic member input ranges
  bool inValidInputRange = true;
  inValidInputRange = withinValidInputRange(input.x, logErrors) && withinValidInputRange(input.y, logErrors)
    && withinValidInputRange(input.z, logErrors);
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::map::point::ECEFHeading)>> {} has invalid member",
                  input); // LCOV_EXCL_BR_LINE
  }

  return inValidInputRange;
}
