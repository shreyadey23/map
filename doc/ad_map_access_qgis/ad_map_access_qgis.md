# QGis 3.14-Pi
 
## Table of contents
1. [Introduction](#introduction)
2. [Features of Qgis 3.14](#features)
3. [CARLA ad_map_access toolbar](#toolbar)
4. [How to use the tool](#howtouse)
5. [Layer view ](#Layerview)

### Introduction <a name="introduction"></a>
Visualization of the map data is crucial to be able to inspect the data and work with it. 
Therefore a plugin for the *free QGIS tool (currently Version 3.14)* is available providing insight into the inner data model of the map. 

The following map data is e.g. visualized there:

- road layout with individual lane segments
- the supporting points of the borders (red)
- the nominal driving direction within the lane (yellow arrows inside)
- the type of lane: normal (light blue), intersection (light green)
- lane contact relations like left/right neighbor, successor/predecessor lane
- right-of-way regulation, speed limits and other landmarks

Also basic tools to test the map matching and routing functionality, prediction test(with runtime selection of route creation mode, prediction duration and length) are also provided.


### Features of QGis 3.14 <a name="features"></a>
Version 3.0 brings changes to many underlying dependencies which QGIS is built upon.

#### Python 3.0
QGIS 3.0 introduces a move to Python 3. This version brings many changes to both the Python language and individual Python libraries.  
A good place to start learning about the changes involved, and how to port your code to Python 3, is available in the official Python documentation: [Porting Python 2 Code to Python 3.](https://docs.python.org/3/howto/pyporting.html)

#### Qt5
QGIS 3.0 is based off version 5 of the underlying Qt libraries. Many changes and API breaks were introduced in Qt5. 

#### PyQt 5
Together with the Python and Qt version changes, the PyQt libraries which expose Qt classes to Python have also had their version bumped to PyQt 5.


### CARLA ad_map_access toolbar <a name="toolbar"></a>
The CARLA ad_map_access toolbar looks like this when the plugin is loaded:

| ![QGIS toolbar](images/Qgis_toolbar.png) |
| -- |
| *Screenshot of the QGIS toolbar when the plugin is loaded into the tool* |

The different features provided by the plugin are:
#### Load New Map
 ![Load New Map](images/Load.png) : Selecting this icon will open a File Dialog Box which allows the user to select and load a map for visialization in QGis 3.14. Post the selection of the map, it is loaded and visible in qgis.
#### Unload currently loaded Map
 ![Unload Loaded Map](images/Unload.png) : Selecting this icon will unload the currently loaded map.
#### Set Snap Altitude
 ![Set Snap Altitude](images/Setsnapaltitude.png) : By using this tool, user can hover anywhere over the map and click to set the default altitude for calculations during Snapping Test, Routing Test and Prediction Test.
#### Snapping Test
 ![Unload Loaded Map](images/Snappingtest.png) : User can select this icon to activate the snapping test. Also ENU co-ordinates of the map-snapped listed points is also visible. 
#### Routing Test
 ![Unload Loaded Map](images/Routingtest.png) : Selecting this icon, will provide the options to the user to select a mode for route creation. After selecting the appropriate route creation mode, the start point and the end point of the route is selected on the map, which then generates the route.
#### Routing Restart
 ![Unload Loaded Map](images/Routingrestart.png) : User can select this icon to restart the routing test.
#### Prediction Test
 ![Unload Loaded Map](images/Predictiontest.png) : Provides the Prediction test on the loaded map. On selecting this icon, user will get options to select the route creation mode, length and duration of the prediction test. Post selection of the test specific features, the lane for prediction can be selected on the map.
#### Enable all lane IDs
 ![Unload Loaded Map](images/ID.png) : Generally it is required to select each layer(INTERSECTION, NORMAL, OTHER or UNKNOWN) under Lane Types, and then activate the lane id attribute to visualize the lane ids on the map. Enabling this button helps the user to bypass those steps, and directly visualize the lane ids on the map. Also, disabling the button removes the lane IDs from the map.

### How to use the tool <a name="howtouse"></a>
- The python path is set to the current python bindings and the working folder.  
*$map> export PYTHONPATH=$PYTHONPATH:/localdisk/shreyade/map/install/ad_map_access/lib/python3.6:/localdisk/shreyade/map/install/ad_physics/lib/python3.6:/localdisk/shreyade/map/tools*
- Load qgis from the working folder where the python environment was set.
- The QGIS_PLUGINPATH can be configured optionally as a shell script file to avoid loading the plugin everytime, QGis is opened.
- Once the plugin is loaded, the CARLA ad_map_access toolbar is now available for use.
- The map is loaded using the load map icon on the CARLA ad_map_access toolbar. 
 ![Loading the desired map](images/Load_file.png "Select the map from the file system") 
      *Select the map from the file system* 

- The map after successful loading shows all the layers with the Lane Geometry, Lane types, Lane Contact Types, Landmark, Topology and speed limits.
 ![Loaded Map](images/loaded_map.png) 
      *One of the loaded maps view in Qgis 3.14* 

- To set the snap altitude the icon is selected from the toolbar and the default altitude is set by selecting the point on the map.
 ![Snap Altitude](images/SetSnapAltitude.png) 
      *The Qgs logger shows the snapped altitude after it is set* 

- In order to start the routing test, the routing test is activated, the option for the route creation mode is selected. Next, the start point and the destination point of the route is snapped on the map which generates the route, highlighted on the map in green.
 ![Routing selection](images/mode_creation.png) ![Routing Test](images/routing.png)
      *Select the route creation mode and the generated route is highlighted* 

- In order to view the lane ids of all layers at once, select the option from the toolbar and the lane ids are visible on the map.
 ![Enable All](images/view_all_laneids.png)
      *With the button enabled we can see all lane IDs of loaded layers.*

- To conduct a Prediction Test, the route creation mode, length and duration of the test is selected on enabling the prediction test button from the CARLA ad_map_access toolbar.
![Prediction selection](images/prediction_mode.png) ![Length](images/length.png) ![Duration](images/duration.png)
![Prediction tests](images/prediction_result.png)
      *The Prediction test with all the selected options during run time*

- Different features of the loaded map can also be visualized using the feature identification tool ![](images/feature_tool.png) in the attributes toolbar.
After selecting the layer to be visualized, the feature identification tool on a layer shows the feature of the layers in a separate panel for better visualization of map data.
 ![](images/feature_tool_result.png)
     *The Normal Layer under Lane Types is selected and the features are displayed*

- The in-built python console in Qgis 3.14 ![](images/python.png) can also be used to verify different functionalities of Qgis while reading and understanding any plugin code. ALl the qgis core modules and gui modules are already a part of the environment which makes debugging for the user easier.

- In order to manually enable any attributes of a particular layer, the *Layer Properties* of the layer is accessed any attribute is enabled to be visible. 
  ![](images/Attributes.png)

### Layer view <a name="Layerview"></a>
When a map is loaded in QGis, all the layers of the map are visible in the Layers Panel on the QGis main window as below:

![](images/Layer_view.png) 

Each of the layer group can then be expanded to see the layer contents and further access the attributes of each layer.
![](images/expanded_layers.png)

To make any one group visible, the other groups can be unchecked in the box right next to it. This removes the specific layer group from the map.



