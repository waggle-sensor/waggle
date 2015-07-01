module Waggle.View.Util where

import Color
import Date
import Dict
import Graphics.Element exposing 
    ( Element, empty 
    , midRight, midLeft 
    , midBottom, middle, midTop
    , widthOf, heightOf
    , leftAligned
    , container, color, flow, down, right
    , beside, above, bottomLeft, link )
import String
import Text exposing (fromString, style)

import Util
import Waggle.Config as Config exposing 
    ( sensor, value
    , primaryStyle, h1Style 
    , h2Style, sensorBackgroundColor )
import Waggle.Sensor exposing 
    ( Value, SensorId
    , PhysicalQuantity, ValueHistory )
import QueueBuffer

{-| Tag indicating the side of the image corresponding to each sensor. -}
type Side = Left | Right

{-| Generates the visual container for a sensor. -}
sensorContainer : String -> Element -> Element
sensorContainer sensorName = above (primaryText sensorName |> leftAligned)
    >> link ("./assets/SensorDataSheets/" ++ sensorName ++ ".pdf")

{-| Generates the visual container for a single value (i.e. measurement). -}
valueContainer : Element -> Element
valueContainer el = container value.width (heightOf el) bottomLeft el

{- Helpers -}
primaryText : String -> Text.Text
primaryText = fromString >> style primaryStyle

h1 = fromString >> style h1Style >> leftAligned >> marginY 10
h2 = fromString >> style h2Style >> leftAligned >> marginY 10

{-| Give an element (the appearance of) top and bottom margins. -}
marginX : Int -> Element -> Element
marginX margin el = container (widthOf el + 2 * margin) (heightOf el) middle el

marginY : Int -> Element -> Element
marginY m el = container (widthOf el) (heightOf el + 2 * m) midBottom el

padding : Int -> Element -> Element
padding p el = container (widthOf el + 2 * p) (heightOf el + 2 * p) middle el

hline : Int -> Element
hline width = container width (6 + 1) middle
    <| color Color.lightGrey 
    <| container width 1 middle empty 
