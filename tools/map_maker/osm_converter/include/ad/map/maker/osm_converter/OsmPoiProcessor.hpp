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

#pragma once

#include <memory>
#include <unordered_map>
#include <unordered_set>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/types.hpp>
#pragma GCC diagnostic pop

#include "ad/map/maker/osm_converter/PointOfInterest.hpp"

namespace osmium {
class Node;
} // osmium

namespace ad {
namespace map {
namespace maker {

namespace common {
struct LogChannel;
class LogFactory;
} // namespace common

namespace osm_converter {
class OsmObjectStore;
class PointStore;
class OsmPoiExtractor;

/**
 * @brief Prepare data for POIs
 *
 * This class is obsolete as soon as we as osm_to_road5 is changed to internal map data only
 */
class OsmPoiProcessor
{
public:
  OsmPoiProcessor(common::LogFactory &logFactory);
  virtual ~OsmPoiProcessor() = default;

  void processPois(std::shared_ptr<OsmPoiExtractor> poiExtractor,
                   std::shared_ptr<OsmObjectStore> objectStore,
                   std::shared_ptr<PointStore>);

  bool hasPoisForSegment(::osmium::object_id_type first, ::osmium::object_id_type last) const;

  /* may return an empty set */
  std::unordered_set<::osmium::object_id_type> poisForSegment(::osmium::object_id_type first,
                                                              ::osmium::object_id_type last) const;

  PointOfInterest const &pointMappingForNodeId(::osmium::object_id_type nodeId) const;

private:
  std::unordered_set<PoiType> mPoiTypes; // should we use a vector/list?
  std::unordered_map<PoiType, std::unordered_set<::osmium::object_id_type>> mPois;
  common::LogChannel &mLog;

  // re-think structure, is a map of a map of a set ideal? Will be replaced by other class
  // key of outer map: id of start
  // key of inner map: id at end
  std::unordered_map<::osmium::object_id_type,
                     std::unordered_map<::osmium::object_id_type, std::unordered_set<::osmium::object_id_type>>>
    mSegmentToPoiMap;
  std::unordered_map<::osmium::object_id_type, PointOfInterest> mPoiToSegmentMapping;

  void processPoisForWay(std::shared_ptr<OsmObjectStore> objectStore,
                         std::shared_ptr<PointStore> pointStore,
                         std::unordered_set<::osmium::object_id_type> const &listOfPoi,
                         PoiType typeOfPoi);
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
