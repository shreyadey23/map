// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// INTEL CONFIDENTIAL
//
// Copyright (c) 2017-2019 Intel Corporation
//
// This software and the related documents are Intel copyrighted materials, and
// your use of them is governed by the express license under which they were
// provided to you (License). Unless the License provides otherwise, you may not
// use, modify, copy, publish, distribute, disclose or transmit this software or
// the related documents without Intel's prior written permission.
//
// This software and the related documents are provided as is, with no express or
// implied warranties, other than those that are expressly stated in the License.
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/OsmMultiLaneInterpolation.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

OsmMultiLaneInterpolation::OsmMultiLaneInterpolation(OsmMultiLane const &start, OsmMultiLane const &end)
  : mStart(start)
  , mEnd(end)
  , mNumberOfLanesDifference(mEnd.mWidths.size() - mStart.mWidths.size())
{
  mFrom = mStart;
  mTo = mEnd;

  // if it is really increasing, add a zero to mFrom and adjust the size of mTo
  if (mNumberOfLanesDifference > 0)
  {
    mFrom.mWidths.push_back(0.);
    while (mTo.mWidths.size() > mFrom.mWidths.size())
    {
      mTo.mWidths.pop_back();
    }
  }
  else if (mNumberOfLanesDifference < 0)
  {
    // fill mTo with widths from mStart, e.g. mTo = [E0, E1] --> mTo = [E0, E1, S2, S3]
    // up to the next-to-last
    for (auto index = mEnd.mWidths.size(); index < mStart.mWidths.size(); ++index)
    {
      mTo.mWidths.push_back(mStart.mWidths[index]);
    }
    // and finalize with a zero
    mTo.mWidths.back() = 0.;
  }
  // no else intended here
}

bool OsmMultiLaneInterpolation::hasNext() const
{
  return (mTo.mWidths.size() != mEnd.mWidths.size());
}

void OsmMultiLaneInterpolation::next()
{
  if (!hasNext())
  {
    return;
  }

  // Adding more lanes
  if (mNumberOfLanesDifference > 0)
  {
    mFrom = mTo;
    mFrom.mWidths.push_back(0.);
    auto pos = mTo.mWidths.size();
    mTo.mWidths.push_back(mEnd.mWidths[pos]);
  }
  else if (mNumberOfLanesDifference < 0)
  {
    mTo.mWidths.pop_back();
    mFrom = mTo;
    if (mTo.mWidths.size() != mEnd.mWidths.size())
    {
      mTo.mWidths.back() = 0.;
    }
  }
}

OsmMultiLane OsmMultiLaneInterpolation::from() const
{
  return mFrom;
}

OsmMultiLane OsmMultiLaneInterpolation::to() const
{
  return mTo;
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
